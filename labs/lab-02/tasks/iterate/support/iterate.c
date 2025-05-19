// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>

#include "iterate.h"
#include "array.h"

void print_chars(void)
{
	int n = sizeof(v);
	unsigned char *c = (unsigned char *) &v;

	while (n--) {
		printf("%p -> 0x%x\n", c, *c);
		c++;
	}

	printf("-------------------------------\n");
}

void print_shorts(void)
{
	int n = sizeof(v);
	unsigned short *s = (unsigned short *) &v;

	while (n) {
		printf("%p -> 0x%x\n", s, *s);
		s++;
		n -= 2;
	}

	printf("-------------------------------\n");
}

void print_ints(void)
{
	int n = sizeof(v);
	unsigned int *i = (unsigned int *) &v;

	while (n) {
		printf("%p -> 0x%x\n", i, *i);
		i++;
		n -= 4;
	}

	printf("-------------------------------\n");
}
