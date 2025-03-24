// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>

#include "vector_max.h"

int vector_max(int *v, int len)
{
	int max;
	unsigned int i;
	i = 0;
	max = v[i];
	goto check_loop;

check_next:
	i = i + 1;
	if (v[i] > max) {
		goto reset_max;
	}
	goto check_loop;
	return -1;

reset_max:
	max = v[i];
	goto check_loop;

check_loop:
	if (i + 1 < len) {
		goto check_next;
	}
	goto solution;

solution:
	return max;
}
