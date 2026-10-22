#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

#include "common.hpp"

struct sbiret
{
    long error;
    long value;
};

// Prototypes used across Kuro
extern "C" struct sbiret sbi_call(long arg0, long arg1, long arg2, long arg3,
                                  long arg4, long arg5, long fid, long eid);
extern "C" void putchar(char ch);