// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "pixel.h"
#include "pixels.h"

#define GET_PIXEL(a, i, j) (*(*((a) + (i)) + (j)))

void reverse_pic(struct picture *pic)
{
	struct pixel **pix_array = pic->pix_array;
	int num_rows = pic->height;
	int width = pic->width;

	int row_1 = 0, row_2 = num_rows - 1;
	while (row_1 < row_2) {
		for (int j = 0; j < width; j++) {
			struct pixel aux = pix_array[row_1][j];
			pix_array[row_1][j] = pix_array[row_2][j];
			pix_array[row_2][j] = aux;
		}

		row_1++;
		row_2--;
	}
}

void color_to_gray(struct picture *pic)
{
	for (int i = 0; i < pic->height; i++) {
		for (int j = 0; j < pic->width; ++j) {
			GET_PIXEL(pic->pix_array, i, j).R *= 0.3;
			GET_PIXEL(pic->pix_array, i, j).G *= 0.59;
			GET_PIXEL(pic->pix_array, i, j).B *= 0.11;
		}
	}
}
