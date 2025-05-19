// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>

#include "binary_search.h"

int binary_search(int *v, int len, int dest)
{
	int start = 0;
	int end = len - 1;
	int middle;
	int elem;

cb_loop:
	if (start > end) goto not_found;
	middle = (start + end) / 2;
	elem = v[middle];
	if (elem == dest) goto found;
	if (elem > dest) goto move_right;
	
move_left:
	start = middle + 1;
	goto cb_loop;

move_right:
	end = middle - 1;
	goto cb_loop;

found:
	return middle;

not_found:
	return -1;
}
