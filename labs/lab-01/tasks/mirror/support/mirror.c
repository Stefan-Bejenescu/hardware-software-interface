// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mirror.h"

int my_strlen(const char* str) {
	int len = 0;
	char *p = str;

	while (*p) {
		len++;
		p++;
	}

	return len;
}

void mirror(char *s)
{
	int n = my_strlen(s);

	int i = 0, j = n - 1;
	while (i < j) {
		char aux = *(s + i);
		*(s + i) = *(s + j);
		*(s + j) = aux;

		i++;
		j--;
	}
}
