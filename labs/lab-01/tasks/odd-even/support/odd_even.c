// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>

#include "odd_even.h"

void print_binary(int number, int nr_bits)
{
	char *bits = malloc(sizeof(*bits) * nr_bits);
	if (!bits) {
		perror("Failed to allocate bits");
		exit(1);
	}

	for (int i = 0; i < nr_bits; i++) {
		*(bits + i) = 1 & number;
		number >>= 1;
	}

	printf("0b");
	for (int i = nr_bits - 1; i > -1; --i) {
		printf("%d", *(bits + i));
	}
	printf("\n");

	free(bits);
}

void check_parity(int *numbers, int n)
{
	for (int i = 0; i < n; i++) {
		int x = *(numbers + i);
		if (x & 1) {
			printf("0x%08X\n", x);
		} else {
			print_binary(x, 8);
		}
	}
}
