#include "main.h"

/**
 * is_prt - decides if a char is printable
 * @c: Char to be decided or evaluated
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_prt(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * app_hex - Append ascci to hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 *
 * Return: Always 3
 */
int app_hex(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_dig - checks and verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_dig(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * conv_siz_numb - puts or casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int conv_siz_numb(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * conv_siz_unsg - Casts number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int conv_siz_unsg(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
