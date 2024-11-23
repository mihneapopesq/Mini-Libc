// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	mode_t mode = 0;
    int result;
    if (flags) {
        va_list args;
        va_start(args, flags);
        mode = va_arg(args, mode_t);
        va_end(args);
        result = syscall(__NR_open, filename, flags, mode);
    } else {
        result = syscall(__NR_open, filename, flags);
    }
    if (result < 0) {
        errno = -result;
        return -1;
    }
    return result;
}
