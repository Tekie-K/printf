#include "main.h"
/**
 * hdle_pt - Prints argument based on its type
 * @_formatt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: 1 or 2;
 */
int hdle_pt(const char *_formatt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	_formatt_t _formatt_types[] = {
		{'c', prt_ch}, {'s', prt_str}, {'%', prt_pct},
		{'i', prt_integer}, {'d', prt_integer}, {'b', prt_bin},
		{'u', prt_u}, {'o', prt_oct}, {'x', prt_hex},
		{'X', prt_HEX}, {'p', pointer}, {'S', prt_non_prt},
		{'r', prt_rev}, {'R', prt_r13}, {'\0', NULL}
	};
	for (i = 0; _formatt_types[i]._formatt != '\0'; i++)
		if (_formatt[*ind] == _formatt_types[i]._formatt)
			return (_formatt_types[i].fn(list, buffer, flags, width, precision, size));

	if (_formatt_types[i]._formatt == '\0')
	{
		if (_formatt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (_formatt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (_formatt[*ind] != ' ' && _formatt[*ind] != '%')
				--(*ind);
			if (_formatt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &_formatt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
