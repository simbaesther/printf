#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format.
 * @*format: is a character string,
 * composed of zero or more directives.
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	convert_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	/*Calling parser function*/
	printed_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}
