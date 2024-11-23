#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int var;
    var = syscall(__NR_nanosleep, req, rem);
    if (var < 0) {
		errno = -var;
		return -1;
	}
	return var;
}
