// SPDX-License-Identifier: BSD-3-Clause

#include <stddef.h>
#include <math.h>

#include "pointers.h"

int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2) {
		if (*s1 == '\0') {
			return 0;
		}

		s1++;
		s2++;
	}

	return *(const unsigned char *) s1 - *(const unsigned char *) s2;
}

void *my_memcpy(void *dest, const void *src, size_t n)
{
	char* it1 = (unsigned char *) dest;
	const char* it2 = (const unsigned char *) src;

	if (src < dest && dest < src + n) {
		it1 += n;
		it2 += n;

		while (n--) {
			*(--it1) = *(--it2);
		}
	} else {
		while (n--) {
			*it1++ = *it2++;
		}
	}
	return dest;
}

char *my_strcpy(char *dest, const char *src)
{
	char *d = dest;

	*dest = *src;
	while (*dest != 0) {
		*(++dest) = *(++src);
	}

	return dest;
}
