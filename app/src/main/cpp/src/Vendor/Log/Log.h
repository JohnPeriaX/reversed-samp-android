//
// Created by SyXhOwN on 17/01/2025.
//

#pragma once

#include "../../StdInc.h"

#define NDEBUG  false
#define USE_FILE_LOG    false
#define LOG_TAG "AXL"

void Log(const char *fmt, ...);
void CrashLog(const char* fmt, ...);

void print(const char* tag, const char* format, ...);
void print(const char* format, ...);

#ifdef NDEBUG
#define DLOG(...)
#else
#define DLOG(...) __android_log_print(ANDROID_LOG_DEBUG, "DEBUG", __VA_ARGS__)
#endif