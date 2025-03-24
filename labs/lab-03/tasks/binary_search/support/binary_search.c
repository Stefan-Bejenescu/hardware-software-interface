// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>

#include "binary_search.h"

int binary_search(int *v, int len, int dest)
{
	int start = 0;
	int end = len - 1;
	int middle;
	goto loop_check;

loop_check:
	if (start <= end) {
		goto solution_check;
	}
	goto print_not_found;

solution_check:
	middle = (start + end) / 2;
	if (v[middle] == dest) {
		goto print_found;
	}
	if (dest < v[middle]) {
		goto reset_end;
	}
	goto reset_start;

reset_end:
	end = middle - 1;
	goto loop_check;

reset_start:
	start = middle + 1;
	goto loop_check;

print_found:
	return middle;

print_not_found:
	return -1;
}
