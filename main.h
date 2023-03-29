#ifndef MAIN_H
#define MAIN_H

char *_memcpy(char *dest, char *src, unsigned int n, unsigned int bufferlen);
int alloc_buffer(char *hold, int hlen, char *buffer, int size, double *total);
char *(*get_spec_func(char s))(va_list);
char *rot13_find(va_list s);
char *rev_find(va_list s);
char *binary_find(va_list n);
char *octal_find(va_list n);
int _printf(const char *format, ...);
char *char_find(va_list c);
char *string_find(va_list s);
char *percent_find(void);
char *int_find(va_list npoint);
char *unsigned_find(va_list unsign);
#endif
