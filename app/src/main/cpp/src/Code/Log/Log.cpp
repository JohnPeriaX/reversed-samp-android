//
// Created by SyXhOwN on 17/01/2025.
//

#include "Log.h"

void Log(const char *fmt, ...)
{
    static char buffer[512] {};

    memset(buffer, 0, sizeof(buffer));

    va_list arg;
    va_start(arg, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, arg);
    va_end(arg);

    __android_log_write(ANDROID_LOG_INFO, "LOG", buffer);

#if USE_FILE_LOG
	static FILE* flLog = nullptr;

	if(flLog == nullptr && g_pszStorage != nullptr)
	{
		sprintf(buffer, "%ssamp/log.txt", g_pszStorage);
		flLog = fopen(buffer, "ab");
	}

	if(flLog == nullptr) return;
	fprintf(flLog, "%s\n", buffer);
	fflush(flLog);
#endif
}

void CrashLog(const char* fmt, ...)
{
    static char buffer[512] {};
    memset(buffer, 0, sizeof(buffer));

    va_list arg;
    va_start(arg, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, arg);
    va_end(arg);

    __android_log_write(ANDROID_LOG_FATAL, "CRASH", buffer);

#if USE_FILE_LOG
    static FILE* flLog = nullptr;

	if (flLog == nullptr && g_pszStorage != nullptr)
	{
		sprintf(buffer, "%ssamp/crash_log.txt", g_pszStorage);
		flLog = fopen(buffer, "ab");
	}

	if (flLog == nullptr) return;
	fprintf(flLog, "%s\n", buffer);
	fflush(flLog);
#endif
}

void print(const char* tag, const char* format, ...)
{
    std::string result;
    va_list args, args_copy;

    va_start(args, format);
    va_copy(args_copy, args);

    int len = vsnprintf(nullptr, 0, format, args);
    if (len < 0) {
        va_end(args_copy);
        va_end(args);
        return;
    }

    if (len > 0) {
        result.resize(len);
        vsnprintf(&result[0], len+1, format, args_copy);
    }

    va_end(args_copy);
    va_end(args);

    __android_log_write(ANDROID_LOG_INFO, tag, result.c_str());
}

void print(const char* format, ...)
{
    std::string result;
    va_list args, args_copy;

    va_start(args, format);
    va_copy(args_copy, args);

    int len = vsnprintf(nullptr, 0, format, args);
    if (len < 0) {
        va_end(args_copy);
        va_end(args);
        return;
    }

    if (len > 0) {
        result.resize(len);
        vsnprintf(&result[0], len+1, format, args_copy);
    }

    va_end(args_copy);
    va_end(args);

    __android_log_write(ANDROID_LOG_INFO, LOG_TAG, result.c_str());
}