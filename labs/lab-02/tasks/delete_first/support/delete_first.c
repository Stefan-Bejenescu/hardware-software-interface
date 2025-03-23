// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "delete_first.h"

char *delete_first(char *s, char *pattern)
{
	char *s_nou;

	int i;
	for (i = 0; i < (strlen(s) - strlen(pattern) + 1); i++) {
		if (strstr(s, pattern) == (s + i)) {
			break;
		}
	}

	strcpy(s_nou, s);
	strcpy(s_nou + i, s_nou + i + strlen(pattern));
	
	return s_nou;
}
