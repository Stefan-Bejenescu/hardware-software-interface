// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>

#include "odd_even.h"

int main(void)
{
	int *numbers, n;

	printf("Size of array: "); scanf("%d", &n);

	numbers = malloc(n * sizeof(int));

	if (!numbers) {
		perror("numbers could not be allocated");
		exit(1);
	}

	for (int i = 0; i < n; ++i) {
		printf("Number %d: ", i + 1);
		scanf("%d", numbers + i);
	}

	check_parity(numbers, n);

	free(numbers);

	return 0;
}
