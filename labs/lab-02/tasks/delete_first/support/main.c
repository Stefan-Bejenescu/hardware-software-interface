// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>

#include "delete_first.h"

int main(void)
{
	/**
	 * TODO: Is the declaration of the s variable correct considering that
	 * we're calling the delete_first function on it? Why? Modify if necessary.
	 */
	char s[101] = "She sells seashells by the seashore";
	char pattern[101] = "se";

	(void) s;
	(void) pattern;

	char *res = delete_first(s, pattern);

	res ? puts(res) : puts("Implement function!");

	return 0;
}
