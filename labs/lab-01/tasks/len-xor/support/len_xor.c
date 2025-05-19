// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "len_xor.h"

int my_strlen(const char *str)
{
	int res;

	for (res = 0; *str; ++str)
		++res;

	return res;
}

void equality_check(const char *str)
{
	int n = my_strlen(str);
	int i = 0;
	while (i < n) {
		char curr_char = *(str + i);
		char next_char = *(str + ((i + (1 << i)) % n));
		if (!(curr_char ^ next_char))
			printf("Address of %c: %p\n", *(str + i), str + i);
		i++;
	}
}
