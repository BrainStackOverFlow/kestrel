#include <limine.h>
#include <stddef.h>

#define PAGE_SIZE ((size_t)0x1000)

typedef enum {
    PMM_NOT_ALLOCATED,
    PMM_ALLOCATED,
} pmm_node_kind_t;

typedef struct pmm_node_t {
    struct pmm_node_t* next;
    struct pmm_node_t* prev;
    void* base;
    size_t no_pages;
    pmm_node_kind_t kind;
} pmm_node_t;

typedef struct {
    pmm_node_t* first_node;
} pmm_t;

void pmm_init(pmm_t* pmm, struct limine_memmap_response* limine_memmap);
void* pmm_alloc_pages(pmm_t* pmm, size_t no_pages);
