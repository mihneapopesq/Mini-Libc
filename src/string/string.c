// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *destptr = destination;
	while(*source != '\0') {
		*destptr = *source;
		source++;
		destptr++;
	}
	*destptr = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *destptr = destination;
	size_t i = 0;
	for(i = 0; i < len && *source !='\0'; i++) {
		*destptr = *source;
		source++;
		destptr++;
	}
	for(; i < len; i++) {
		*destptr = '\0';
		destptr++;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *destptr = destination;
	while(*destptr != '\0') {
		destptr++;
	}
	while(*source != '\0') {
		*destptr = *source;
		source++;
		destptr++;
	}
	*destptr = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *destptr = destination;
	while(*destptr != '\0') {
		destptr++;
	}
	size_t i = 0;
	for(i = 0; i < len && *source !='\0'; i++) {
		*destptr = *source;
		source++;
		destptr++;
	}
	*destptr = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	const char *str1ptr = str1;
	const char *str2ptr = str2;
	size_t len1, len2;
	len1 = 0;
	len2 = 0;
	while(*str1ptr != '\0') {
		str1ptr++;
		len1++;
	}
	while(*str2ptr != '\0') {
		str2ptr++;
		len2++;
	}
	if(len1 < len2)
		return -1;
	if(len1 > len2)
		return 1;
	const char *str1_ptr = str1;
	const char *str2_ptr = str2;
	for(size_t i = 0; i < len1; i++, *str1_ptr++, *str2_ptr++) {
		int a = *str1_ptr;
		int b = *str2_ptr;
		if(a < b)
			return -1;
		if(a > b)
			return 1;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	const char *str1ptr = str1;
	const char *str2ptr = str2;
	size_t len1, len2;
	len1 = 0;
	len2 = 0;
	while(*str1ptr != '\0') {
		str1ptr++;
		len1++;
	}
	while(*str2ptr != '\0') {
		str2ptr++;
		len2++;
	}
	size_t my_length;
	if (len1 < len2)
		my_length = len1;
	else
		my_length = len2;
	if(my_length > len)
		my_length = len;
	const char *str1_ptr = str1;
	const char *str2_ptr = str2;
	for(size_t i = 0; i < my_length; i++, *str1_ptr++, *str2_ptr++) {
		int a = *str1_ptr;
		int b = *str2_ptr;
		if(a < b)
			return -1;
		if(a > b)
			return 1;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	const char *ptr = str;
	while(*ptr != '\0') {
		if(*ptr == (char)c)
			return (char *)ptr;
		ptr++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	const char *ptr = str;
	char *res = NULL;
	while(*ptr != '\0') {
		if(*ptr == (char)c)
			res = (char *)ptr;
		ptr++;
	}
	return res;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	const char *haystack_ptr = haystack;
	const char *needle_ptr = needle;
	const char *res = NULL;
	while (*haystack_ptr != '\0') {
		const char *tmp_ptr = haystack_ptr;
		needle_ptr = needle;
		while(*tmp_ptr != '\0' && *needle_ptr != '\0') {
			if(*tmp_ptr != *needle_ptr)
				break;
			tmp_ptr++;
			needle_ptr++;
		}
		if (*needle_ptr == '\0') {
			res = haystack_ptr;
			break;
		}
		haystack_ptr++;
	}
	return (char *)res;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	const char *haystack_ptr = haystack;
	const char *needle_ptr = needle;
	const char *res = NULL;
	while (*haystack_ptr != '\0') {
		const char *tmp_ptr = haystack_ptr;
		needle_ptr = needle;
		while(*tmp_ptr != '\0' && *needle_ptr != '\0') {
			if(*tmp_ptr != *needle_ptr)
				break;
			tmp_ptr++;
			needle_ptr++;
		}
		if (*needle_ptr == '\0') {
			res = haystack_ptr;
		}
		haystack_ptr++;
	}
	return (char *)res;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest_ptr = (char *)destination; //take byte by byte
	char *source_ptr = (char *)source;
	for(size_t i = 0; i < num; i++) {
		*dest_ptr = *source_ptr;
		dest_ptr++;
		source_ptr++;
	}
	return dest_ptr;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest_ptr = (char *)destination;
	char *source_ptr = (char *)source;
	if(dest_ptr < source_ptr || dest_ptr >= source_ptr + num) { //no overlap
		size_t i = 0;
		while(i < num) {
			*dest_ptr = *source_ptr;
			dest_ptr++;
			source_ptr++;
			i++;
		}
		return destination;
	}
	// overlap
	dest_ptr += num;
	source_ptr += num;
	size_t i = 0;
	dest_ptr--;
	source_ptr--;
	while(i < num) {
		*(dest_ptr) = *(source_ptr);
		dest_ptr--;
		source_ptr--;
		i++;
	}
	return dest_ptr;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *p1 = (char *)ptr1;
	char *p2 = (char *)ptr2;
	size_t i = 0;
	while(i < num) {
		if(*p1 - *p2 != 0) {
			return *p1 - *p2;
		}
		p1++;
		p2++;
		i++;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *source_ptr = (char *)source;
	size_t i = 0;
	while(i < num) {
		*source_ptr = value;
		i++;
		source_ptr++;
	}
	return source_ptr;
}
