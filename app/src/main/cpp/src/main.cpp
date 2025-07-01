//
// Created by SyXhOwN on 17/01/2025.
//

// main
#include "StdInc.h"

// JavaWrapper
#include "Vendor/Javawrapper/JavaWrapper.h"

// ReversibleHooks
#include "ReversibleHooks/hook.h"
#include "ReversibleHooks/memutils.h"

// Log
#include "Code/Log/Log.h"

// Trace
#include "Vendor/Trace/StackTrace.h"

// Code
#include "Code/ThreadOptimizer/ThreadOptimizer.h"

void InstallGlobalHooks();
void InstallHooks();

uintptr_t g_ptrGTASA = (uintptr_t)NULL;
Hook* g_pHookSA = (Hook*)nullptr;
JavaVM *javaVM = nullptr;

jint JNI_OnLoad(JavaVM * vm, void *reserved)
{
    print("Library: %s is loaded! Build time/date: %s %s | ABI: %s",
               __LIBRARY_NAME__,
               __TIME__,
               __DATE__,
               __ABI_NAME__
    );

    srand(time(NULL));

    print("Initializing libraries and hook system..");
    g_ptrGTASA = static_cast<uintptr_t>(MemUtils::getModuleAddress(__GAME_LIB_NAME__));

    if(!g_ptrGTASA) {
        print("Error! %s not found!", __GAME_LIB_NAME__);
        return JNI_ERR;
    }

    print("%s address: 0x%X", __GAME_LIB_NAME__, g_ptrGTASA);

    g_pHookSA = new Hook(g_ptrGTASA + START_LIB, 0x2000, 0x4096);
    if(!g_pHookSA) {
        print("Error! hook system not initialized!");
        return JNI_ERR;
    }

    SetFPS(200);

    InstallGlobalHooks();
    InstallHooks();

    javaVM = vm;
    return JNI_VERSION_1_6;
}

void SetFPS(unsigned char game_fps)
{
    print("%s: %d", __FUNCTION__, game_fps);

    std::vector<uintptr_t> vecFPSAddrs;
    vecFPSAddrs.clear();

    vecFPSAddrs.push_back(FPS_ADDRESS_1);
    vecFPSAddrs.push_back(FPS_ADDRESS_2);
    vecFPSAddrs.push_back(FPS_ADDRESS_3);
    vecFPSAddrs.push_back(FPS_ADDRESS_4);

    for(uintptr_t fps_address : vecFPSAddrs) {
        MemUtils::write(g_ptrGTASA + fps_address, (uintptr_t)&game_fps, 1);
    }
}