#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - Prints to standard output
 * @format: characters
 * Return: length of string
 */

int _printf(const char *format, ...)
{
int len1 = strlen(format);
char c;
int count = 0;
for (int i = 0; i < len1; i++)
{
format[i];
if (format[i] == '%')
{
char id[2] = { '%', format[++i]};
if (id[1] == " ")
{
write(1, &format[++i], 1);
return (0);
}
else
{
va_list args;
va_start(args, *format);
if (id[1] == 'c')
{
c = va_arg(args, int);
write(1, &c, 1);
return (0);
}
else if (id[1] == 's')
{
char *s = va_arg(args, char *);
while (*s != '\0')
{
for (int j = 0; j < strlen(s); j++)
write(1, &s[j], 1);
return (0);
}
}
else
{
printf("Not supported");
break;
}
va_end(args);
}
}
else
write(1, &format[i], 1);
}
}
