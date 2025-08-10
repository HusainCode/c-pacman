#pragma once 

#include <stdio.h>     // For printf, fprintf
#include <stdarg.h>    // For va_list, va_start, va_arg, va_end
#include <time.h>      // For time, localtime_r

// Macros for different log levels
#define LOG_INFO(fmt, ...)  log_message("INFO",  __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...) log_message("WARN", __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) log_message("ERROR", __FILE__,__LINE__, fmt, ##__VA_ARGS__)

// Core logging function
void log_message(const char *level, const char *file, int line, const char *fmt, ...);

 