# Kestrel

Kestrel is a kernel.

## Setup the Environment

There are several installation requirements for the project.

### Bazel & Java

The project uses the `Bazel` build system, which requires a `JDK`.

- Install any `JDK` (version 8 or above)
- [`Bazel` installation guide](https://bazel.build/install)

### xorriso

The project uses `xorriso` to create bootable images.

- Install `xorriso` via `apt`

### qemu

The project uses the `qemu` emulator.

- Install `qemu-system-x86` via `apt`

## Run the Project

- Run without debugging:
    - `bazel run //image:emulator --config kestrel`
- Run and debug:
    - `bazel run //image:debuggee --config kestrel`
    - `bazel run //image:debugger --config kestrel`
