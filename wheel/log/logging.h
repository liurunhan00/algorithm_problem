#pragma once
#include "c.h"

enum log_level {
    LOG_NOT_SET = 0,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_OFF
};

extern enum log_level __log_level;

void logging_init(const char* argv);

void logging_set_level(enum log_level new_level);

void logging_increase_verbosity(void);

void log_generic(enum log_level level, const char* __restrict fmt, ...);

void log_generic_v(enum log_level level, const char* __restrict fmt, va_list ap); 