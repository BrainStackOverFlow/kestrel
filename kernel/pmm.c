#include "pmm.h"

#include "utility/macro.h"

void pmm_init(pmm_t* pmm, struct limine_memmap_response* limine_memmap)
{
    pmm_node_t* current = NULL;

    for (size_t i = 0; i < limine_memmap->entry_count; i++) {
        struct limine_memmap_entry* entry = limine_memmap->entries[i];
        if (LIMINE_MEMMAP_USABLE == entry->type) {
            pmm_node_t node = { .next = NULL,
                                .prev = current,
                                .base = (void*)(entry->base + PAGE_SIZE),
                                .no_pages = (entry->length / PAGE_SIZE) - 1,
                                .kind = PMM_NOT_ALLOCATED };
            pmm_node_t* node_ptr = (void*)entry->base;
            *node_ptr = node;

            if (NULL == current) {
                pmm->first_node = node_ptr;
            } else {
                current->next = node_ptr;
            }
            current = node_ptr;
        }
    }
}

void* pmm_alloc_pages(pmm_t* pmm, size_t no_pages)
{
    pmm_node_t* current = pmm->first_node;

    while (NULL != current) {
        if ((PMM_NOT_ALLOCATED == current->kind)
            && (current->no_pages >= no_pages)) {
            break;
        }

        current = current->next;
    }

    if (NULL == current) {
        return NULL;
    }

    size_t leftover_pages = current->no_pages - no_pages;
    if (0 == leftover_pages) {
        current->kind = PMM_ALLOCATED;
        return current->base;
    }

    pmm_node_t* new_node = // may has bug
        add_pointer(pmm_node_t*, current->base, no_pages * PAGE_SIZE);

    new_node->next = current->next;
    new_node->prev = current;
    new_node->base = add_pointer(void*, new_node->base, PAGE_SIZE);
    new_node->no_pages = leftover_pages - 1;
    new_node->kind = PMM_NOT_ALLOCATED;

    current->next = new_node;
    current->no_pages = no_pages;
    current->kind = PMM_ALLOCATED;

    return current->base;
}
