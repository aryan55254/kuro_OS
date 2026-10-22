#!/bin/bash
set -xue

# QEMU file path
QEMU=qemu-system-riscv32

# Path to clng and compiler flags
CXX=clang++
CXXFLAGS="-std=c++20 -O2 -g3 -Wall -Wextra --target=riscv32-unknown-elf -fuse-ld=lld -fno-stack-protector -ffreestanding -nostdlib -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics"

# Build the kernel
$CXX $CXXFLAGS -Wl,-Tkernel.ld -Wl,-Map=kernel.map -o kernel.elf \
    kernel.cpp common.cpp

# Start QEMU
$QEMU -machine virt -bios default -nographic -serial mon:stdio --no-reboot \
    -kernel kernel.elf