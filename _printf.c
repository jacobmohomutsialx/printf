#include <stddef.h>
#include <stdio.h>


/**
 * _printf - function that prints output
 * @format: is a character string
 * Return: the number of characters to be printed
 */

int _printf(const char *format, ...)
{
	va_list valist;
	int i, buffend = 0;
	double tBuffer = 0;
	double *t;
	char *h;
	char buffer[BUFSIZE];
	char *(*spec_func)(va_list) = NULL;

	if (!format)
		return (-1);
	va_start(valist, format);
	t = &tBuffer;
	for (i = 0; i < BUFSIZE; i++)
		buffer[i] = 0;
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			spec_func = get_spec_func(format[i]);
			h = (spec_func) ? spec_func(valist) : nothing_found(format[i]);
			if (h)
				buffend = alloc_buffer(h, _strlen(h), buffer, buffend, t);
		}
		else
		{
			h = chartos(format[i]);
			buffend = alloc_buffer(h, 1, buffer, buffend, t);
		}
	}
	_puts(buffer, buffend);
	va_end(valist);
	return (tBuffer + buffend);
}
