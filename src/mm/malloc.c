// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *var = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (var == MAP_FAILED || mem_list_add(var, size) == -1) {
        munmap(var, size);
        return NULL;
    }
	return var;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;
	void *var = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (var == MAP_FAILED || mem_list_add(var, total_size) == -1) {
        munmap(var, total_size);
        return NULL;
    }
	memset(var, 0, total_size);
	return var;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if(!ptr)
		return;
	struct mem_list *var = mem_list_find(ptr);
	if(var) {
		munmap(var->start, var->len);
		mem_list_del(var->start);
		//remove var from mem list and unmap
	}
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (!ptr) {
		return malloc(size);
	}
	struct mem_list *block_info = mem_list_find(ptr);
    if (!block_info) {
		return NULL;
	}
	size_t needed_size = size + sizeof(struct mem_list);
    if (needed_size <= block_info->len + sizeof(struct mem_list)) {
		return ptr;
	}
    void *new_memory = malloc(size);
    if (new_memory) {
        memcpy(new_memory, ptr, block_info->len);
        free(ptr);
    }
    return new_memory;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	if(nmemb == 0 || size == 0) {
		free(ptr);
		return NULL;
	}
	size_t total_size = nmemb * size;
    void *new_ptr = realloc(ptr, total_size);
    return new_ptr;
}
