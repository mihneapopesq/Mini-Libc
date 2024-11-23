// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	void *var = (void *)syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if ((long) var < 0) {
		 errno = -((long)var);
		return MAP_FAILED;
	}
	return var;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	void *var = (void *)syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if ((long) var < 0) {
		 errno = -((long)var);
		return MAP_FAILED;
	}
	return var;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int var = syscall(__NR_munmap, addr, length);
	if(var < 0) {
		errno = -var;
		return -1;
	}
	return var;
}
