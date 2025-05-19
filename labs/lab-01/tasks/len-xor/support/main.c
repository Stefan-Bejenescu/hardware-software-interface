// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "len_xor.h"

char *new_string(const char *cont_str)
{
	char *res;

	res = calloc(STR_SIZE, sizeof(char));
	strcpy(res, cont_str);

	return res;
}

int main(void)
{
	char *str;

	str = new_string("ababababacccbacbacbacbacbabc");

	printf("len(\"%s\") = %d\n", str, my_strlen(str));
	equality_check(str);

	// free memory
	free(str);

	return 0;
}