// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "find_max.h"

void *find_max(void *arr, int n, size_t element_size,
				int (*compare)(const void *, const void *))
{
	void *elem_max = arr;

	for (int i = 0; i < n; i++) {
		void *elem = (char *)arr + i * element_size;

		if (compare(elem, elem_max) > 0) {
			elem_max = elem;
		}
	}

	return elem_max;
}

int compare(const void *a, const void *b)
{
	return *(int *) a > *(int *) b ? 1 : 0;
}
