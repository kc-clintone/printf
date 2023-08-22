#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define MIN 1
#define POS 2
#define ZERO 4
#define HASHTAG 8
#define SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmrt - Struct op
 * @fmrt: The format.
 * @fn: The function associated.
 */
struct fmrt
{
	char fmrt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmrt fmrt_t - Struct op
 * @fmt: format
 * @fmrt_t: associated func
 */
typedef struct fmrt fmrt_t;

int _printf(const char *format, ...);
int print_handler(const char *fmrt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* control functions */
void log_to_console(char bfr[], int *index);
int _character(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _integer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _uppercase_hex(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hex(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width,
int precision, int size);
int _forbidden(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int getAllFlags(const char *format, int *i);
int getWidth(const char *format, int *i, va_list list);
int getPrec(const char *format, int *i, va_list list);
int getSize(const char *format, int *i);
int _pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* print string in reverse*/
int _reverse_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* print in rot 13*/
int _rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handlers */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,
char buffer[], int flags, int width, int precision, int size);

/*utilities*/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* _MAIN_H_ */
