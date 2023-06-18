#include "logging.h"


void logging_set_level(enum log_level new_level) {
    __log_level = new_level;
}


void logging_increase_verbosity(void) {
    // Decrease __log_level becomes more verbosity
    if (__log_level > LOG_NOT_SET + 1) {
         __log_level--;
    }
}

void log_generic(enum log_level level, const char* __restrict fmt, ...) {
    va_list ap;
    // Initializing ap list to store all value after fmt
    va_start(ap, fmt);
    log_generic_v(level, fmt, ap);
    va_end(ap);
}

void log_generic_v(enum log_level level, const char* __restrict fmt, va_list ap) {
    int save_errno = errno;
    const char* filename = NULL;
    uint64 lineno = 0;
    va_list ap2;
    char* buf;
    
    // Do nothing if level too low
    if (level < __log_level) {
        return;
    }

    // Flush before output to stderr, to ensure sync even when stdout is buffered
    fflush(stdout);

    
}
