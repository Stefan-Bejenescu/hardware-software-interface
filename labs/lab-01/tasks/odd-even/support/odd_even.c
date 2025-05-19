// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>

#include "odd_even.h"

void print_binary(int number, int nr_bits)
{
	char *bits = malloc(nr_bits);
	if (!bits) {
		printf("Error allocating memory for bits array\n");
		return;
	}

	for (int i = nr_bits - 1; i >= 0; i--) {
		*(bits + i) = number & 1;
		number >>= 1;
	}

	printf("0b");
	for (int i = 0; i < nr_bits; i++) {
		printf("%d", *(bits + i));
	}
	printf("\n");

	free(bits);
}

void check_parity(int *numbers, int n)
{
	for (int i = 0; i < n; i++) {
		int num = *(numbers + i);

		if (num & 1) {
			printf("0x%08X\n", num);
		} else {
			print_binary(num, 8);
		}
	}
}
