# kuro

attempt at making a small operating system that can run doom and has its own kernel space tcp/ip stack , written in C++

## directory structure

current(will change most probabbly) :-

```text
kuro/
├── disk/         - File system contents
├── common.cpp    - Kernel/user shared library: printf, memset, memcpy
├── common.hpp    - Shared types, constants, inline utilities
├── kernel.cpp    - Kernel entry point, syscall dispatcher, process scheduler
├── kernel.hpp    - Kernel structs,page table definitions,process control blocks
├── kernel.ld     - Kernel linker script (memory layout)
├── shell.cpp     - Userland command-line shell
├── user.cpp      - Userland syscall wrappers (inline assembly)
├── user.hpp      - Userland definitions & system call numbers
├── user.ld       - Userland linker script
└── run.sh        - Build script (clang++/g++, llvm-objcopy, QEMU runner)

```

## Phase 1 features  (currently building through phase 1)

1. Multitasking: Switch between processes to allow multiple applications to share the CPU.
2. Exception handler: Handle events requiring OS intervention.
3. Paging: Provide an isolated memory address space for each application.
4. System calls: Allow applications to call kernel features.
5. Device drivers: Abstract hardware functionalities, such as disk read/write.
6. File system: Manage files on disk.
7. Command-line shell: User interface for humans.
8. Memory management : Physical -> BitMap Frame Allocator | Heap -> Arena Allocator | Slab Allocator For Other Features 

## Phase 2 features

1. Interrupt handling
2. Timer processing
3. Inter-process communication
4. Multi-processor support

## Phase 3 features

* not sure exactly what but all shit that allows to play single player doom

## Phase 4 features

* not sure exactly what but all shit that allows to play multi-player doom
* kernel space tcp/ip stack to allow some network shit

---

> **Note:** if you try to test this shit with whatever it is done then the run.sh expects the OpenSBI firmware , will add proper running and setup instructions later after all of phase 1 is done atleast