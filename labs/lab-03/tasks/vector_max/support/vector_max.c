// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>

#include "vector_max.h"

int vector_max(int *v, int len)
{
	int max;
	unsigned int i = 1;
	max = v[0];

check_end:
	if (i == len) goto end;

check_elem:
	if (max < v[i]) goto change_max;
	goto iterate;

change_max:
	max = v[i];

iterate:
	i++;
	goto check_end;

end:
	return max;
}
