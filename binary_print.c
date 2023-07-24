#include "main.h"

 /**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int b, c, d, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	b = va_arg(types, unsigned int);
	c = 2147483648; /* (2 ^ 31) */
	a[0] = b / c;
	for (d = 1; d < 32; d++)
	{
		c /= 2;
		a[d] = (b / c) % 2;
	}
	for (d = 0, sum = 0, count = 0; d < 32; d++)
	{
		sum += a[d];
		if (sum || d == 31)
		{
			char e = '0' + a[d];

			write(1, &e, 1);
			count++;
		}
	}
	return (count);
}
