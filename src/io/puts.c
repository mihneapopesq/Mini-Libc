#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int puts(const char* str)
{
	const char *p = str;
    while (*p != '\0') {
        p++;
    }
    int len = p - str;
    int var = syscall(__NR_write, 1, str, len);
    if (var < 0) {
		errno = -var;
		return -1;
	}
    char c = '\n';
    var = syscall(__NR_write, 1, &c, 1);
    if (var < 0) {
		errno = -var;
		return -1;
	}
	return var;
}
