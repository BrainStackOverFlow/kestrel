"""
This file defines image-related rules.
"""

def image_implementation(ctx):
    """
    Implement the image rule.

    Args:
        ctx: Context

    Returns:
        Image directory information
    """

    # Collect inputs

    image_targets = []

    for src in ctx.attr.srcs:
        image_targets.append(src)

    cd_target = ctx.attr.cd
    if cd_target not in image_targets:
        image_targets.append(cd_target)

    efi_target = ctx.attr.efi
    if efi_target not in image_targets:
        image_targets.append(efi_target)

    # Collect files

    image_files = []
    for image_input in image_targets:
        image_files.extend(image_input.files.to_list())

    cd_file = cd_target.files.to_list()[0]
    efi_file = efi_target.files.to_list()[0]

    # Create root directory

    root_directory = ctx.actions.declare_directory("root_directory")

    copy_arguments = ctx.actions.args()
    copy_arguments.add("--dereference")
    copy_arguments.add("-r")
    copy_arguments.add("-t", root_directory.path)
    for image_file in image_files:
        copy_arguments.add(image_file.path)

    ctx.actions.run(
        inputs = image_files,
        outputs = [root_directory],
        executable = "cp",
        arguments = [copy_arguments],
    )

    # Create image

    image = ctx.actions.declare_file(ctx.label.name)

    create_image_arguments = ctx.actions.args()
    create_image_arguments.add("-as", "mkisofs")
    create_image_arguments.add("-b", cd_file.basename)
    create_image_arguments.add("-no-emul-boot")
    create_image_arguments.add("-boot-load-size", 4)
    create_image_arguments.add("-boot-info-table")
    create_image_arguments.add("--efi-boot", efi_file.basename)
    create_image_arguments.add("-efi-boot-part")
    create_image_arguments.add("--efi-boot-image")
    create_image_arguments.add("--protective-msdos-label")
    create_image_arguments.add("-o", image.path)
    create_image_arguments.add(root_directory.path)

    ctx.actions.run(
        inputs = [root_directory],
        outputs = [image],
        executable = "xorriso",
        arguments = [create_image_arguments],
        execution_requirements = {"no-sandbox": "1"},
    )

    return DefaultInfo(files = depset([image]))

image = rule(
    attrs = {
        "srcs": attr.label_list(
            doc = "List of files that should be included in the image",
            allow_files = True,
        ),
        "cd": attr.label(
            doc = "The boot CD image",
            allow_files = True,
        ),
        "efi": attr.label(
            doc = "The EFI image",
            allow_files = True,
        ),
    },
    implementation = image_implementation,
)
