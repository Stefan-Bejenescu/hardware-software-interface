// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "len_xor.h"

char *new_string(const char *cont_str) {
	char *res;

	res = calloc(STR_SIZE, sizeof(char));
	strcpy(res, cont_str);

	return res;
}

int my_strlen(const char *str) {
	int n = 0;

	char* aux = (char *) str;
	while (aux) {
		aux++;
		n++;
	}
	aux = NULL;

	return n;
}

void equality_check(const char *str) {
	int n = my_strlen(str);

	for (int i = 0; i < n; i++) {
		if (!(str[i] ^ str[(i + (1 << i)) % n])) {
			printf("Address of %c: %p\n", str[i], str + i);
		}
	}
}
