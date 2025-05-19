// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "delete_first.h"

char *delete_first(char *s, char *pattern)
{
	for (int i = 0; *(s + i); i++) {
		int k = 0, j = i;
		while (*(s + j) && *(pattern + k) && !(*(s + j) ^ *(pattern + k))) j++, k++;

		if (!(*(pattern + k))) {
			while (*(s + i + k)) {
				*(s + i) = *(s + i + k);
				i++;
			}
			*(s + i) = *(s + i + k);
		}
	}

	return s;
}