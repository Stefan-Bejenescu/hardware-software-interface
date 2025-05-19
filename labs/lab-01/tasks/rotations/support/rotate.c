// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>

#include "rotate.h"

void rotate_left(unsigned int *number, int bits)
{
	int shifted_bits = *number >> (sizeof(*number) * 8 - bits);
	*number <<= bits;
	*number |= shifted_bits;
}

void rotate_right(unsigned int *number, int bits)
{
	int shifted_bits = *number % (1 << (bits + 1));
	shifted_bits <<= (sizeof(*number) * 8 - bits);
	*number >>= bits;
	*number |= shifted_bits;
}
