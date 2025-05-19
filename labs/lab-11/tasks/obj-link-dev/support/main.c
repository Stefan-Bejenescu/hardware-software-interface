// SPDX-License-Identifier: BSD-3-Clause

extern int set_price(int price);
extern void print_price(void);

extern int qty;
extern void print_quantity(void);

int main(void)
{
	/*
	 * TODO: Make it so you print:
	 *    price is 21
	 *    quantity is 42
	 * without directly calling a printing function.
	 */

	set_price(21);
	print_price();

	qty = 42;
	print_quantity();

	return 0;
}
