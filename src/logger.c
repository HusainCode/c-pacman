vvvv#include "../include/logger.h"


// Central log function
void log_message(const char *level, const char *file, int line, const char *fmt, ...) {
    // Get current time
    time_t t = time(NULL);
    struct tm tm;
    localtime_r(&t, &tm);  // Thread-safe version of localtime()

    // Print timestamp + level + file + line number
    fprintf(stderr, "%02d:%02d:%02d [%s] %s:%d: ",
            tm.tm_hour, tm.tm_min, tm.tm_sec,
            level, file, line);

    // Handle variable arguments (va_list lets us forward  arguments)
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);  // Print the actual log message
    va_end(args);

    // End with a newline
    fprintf(stderr, "\n");
}
