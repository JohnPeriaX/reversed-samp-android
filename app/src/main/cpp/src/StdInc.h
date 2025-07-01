//
// Created by SyXhOwN on 19/01/2025.
//

#pragma once

#define __LIBRARY_NAME__ "libSAMP.so"
#define __GAME_LIB_NAME__ "libGTASA.so"

#if defined(__aarch64__)
#include "address_table_x64.h"
#define __ABI_NAME__ "arm64-v8a"
#else
#include "address_table_x32.h"
	#define __ABI_NAME__ "armeabi-v7a"
#endif

// API & SDK INCLUDES
#include <cstring>
#include <cstdlib>
#include <cstdarg>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <cassert>

#include <errno.h>
#include <malloc.h>
#include <limits.h>
#include <unistd.h>
#include <signal.h>
#include <sys/uio.h>
#include <sys/mman.h>

#include <jni.h>
#include <android/log.h>

#include "Code/Log/Log.h"

// ReversibleHooks
#include "ReversibleHooks/hook.h"
#include "ReversibleHooks/memutils.h"

void SetFPS(unsigned char game_fps = 200);

extern uintptr_t g_ptrGTASA;
extern Hook* g_pHookSA;