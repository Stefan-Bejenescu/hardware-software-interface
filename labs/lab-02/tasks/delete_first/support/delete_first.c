// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "delete_first.h"

char *delete_first(char *s, char *pattern)
{
	int nr_char_pattern = strlen(pattern);
	int nr_char_s = strlen(s);
	char *s2 = strstr(s, pattern);

	if (!s2) {
		return s;
	}

	char *result = malloc(nr_char_s - nr_char_pattern + 1);

	int i;
	for (i = 0; i < (nr_char_s - nr_char_pattern + 1); i++) {
		if (s2 == (s + i)) {
			break;
		}
	}

	strncpy(result, s, s2 - s);
	strcat(result, s2 + nr_char_pattern);

	return result;
}
