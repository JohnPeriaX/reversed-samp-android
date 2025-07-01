//
// Created by JohnPeriaX on 1/7/2025.
//

#ifndef REGTA_MEMUTILS_H
#define REGTA_MEMUTILS_H

#pragma once

#include <sys/uio.h>
#include <sys/mman.h>
#include <cstddef>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <dlfcn.h>
#include <vector>

#include "hook.h"

#define PAGE_SIZE 0x4096
#define HOOK_PROC "\x01\xB4\x01\xB4\x01\x48\x01\x90\x01\xBD\x00\xBF\x00\x00\x00\x00"

namespace MemUtils
{
    uintptr_t getModuleAddress(const char*);
    uintptr_t getModuleLen(const char*);
    uintptr_t getSymbolAddress(uintptr_t, const char*);

    bool unprotect(uintptr_t ptr, size_t size = 100);
    void cacheClear(uintptr_t, size_t);
    void makeNOP(uintptr_t, size_t);
    void read(uintptr_t, uintptr_t, size_t);
    void write(uintptr_t, uintptr_t, size_t);
    void jump(uintptr_t, uintptr_t);
    void bxlr(uintptr_t);
    void makeRET(uintptr_t address, bool onlyTwoBytes = false);
};


#endif //REGTA_MEMUTILS_H
