// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "len_xor.h"

int my_strlen(const char *str)
{
	char* p = str;

	int len = 0;
	while (*p) {
		len++;
		p++;
	}

	return len;
}

void equality_check(const char *str)
{
	int n = my_strlen(str);
	printf("length = %d\n", n);

	for (int i = 0; i < n; i++) {
		if (!(*(str + i) ^ *(str + ((i + (1 << i)) % n)))) {
			printf("Address of %c: %p\n", *(str + i), str + i);
		}
	}
}
