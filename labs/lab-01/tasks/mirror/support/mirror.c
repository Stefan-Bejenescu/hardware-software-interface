// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mirror.h"

int my_strlen(const char *str) {
	int res;

	for (res = 0; *str; str++)
		++res;

	return res;
}

void mirror(char *s)
{
	int n = my_strlen(s);
	int l = 0, r = n-1;

	while (l < r) {
		char aux = *(s + l);
		*(s + l) = *(s + r);
		*(s + r) = aux;

		l++;
		r--;
	}
}
