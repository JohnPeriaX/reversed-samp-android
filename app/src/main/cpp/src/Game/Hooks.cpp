//
// Created by SyXhOwN on 17/01/2025.
//

#include "../StdInc.h"
#include "../Code/ThreadOptimizer/ThreadOptimizer.h"

// TODO: In the future this will be moved
int GetInputType() {
    return 0;
}

ThreadOptimizer m_ThreadOpt;
void* (*NVThreadSpawnProc)(void* arg);
void* HOOK_NVThreadSpawnProc(void* arg)
{
    m_ThreadOpt.PushThread(gettid());
    return NVThreadSpawnProc(arg);
}

void InstallHooks()
{
    // Fix mouse/keyboard bad
    //ReversibleHooks::Redirect("_ZN4CHID12GetInputTypeEv", &GetInputType);
}

void InstallGlobalHooks() {
    g_pHookSA->install(g_ptrGTASA + ADDR_NVThreadSpawnProc, (uintptr_t)HOOK_NVThreadSpawnProc, (uintptr_t*)&NVThreadSpawnProc);
}