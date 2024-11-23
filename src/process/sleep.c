#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    while (1) {
        if (nanosleep(&req, &rem) == 0) {
            break;
        } else if (errno == EINTR) {
            req = rem;
        } else {
            break;
        }
    }
    return 0;
}
