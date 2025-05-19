// SPDX-License-Identifier: BSD-3-Clause

#include <stddef.h>

#include "pointers.h"

int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2) s1++, s2++;
	return (*s1 - *s2);
}

void *my_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *) dest;
	const unsigned char *s = (const unsigned char *) src;

	if (s < d && d < s + n) {
		s += n;
		d += n;

		while (n--)
			*(--d) = *(--s);
	} else {
		while (n--)
			*d++ = *s++;
	}

	return dest;
}

char *my_strcpy(char *dest, const char *src)
{
	char *old_dest = dest;

	while (*src) *dest++ = *src++;
	*dest = *src;

	return old_dest;
}
