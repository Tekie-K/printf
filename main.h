#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct _formatt - Struct op
 *
 * @_formatt: The format.
 * @fn: The function associated.
 */
struct _formatt
{
	char _formatt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct _formatt _formatt_t - Struct op
 *
 * @_formatt: The format.
 * @fm_t: The function associated.
 */
typedef struct _formatt _formatt_t;

int _printf(const char *format, ...);
int hdle_pt(const char *_formatt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int prt_ch(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_pct(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int prt_integer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_u(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_hex(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_HEX(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int hex(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int prt_non_prt(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int gt_flgs(const char *format, int *i);
int get_w(const char *format, int *i, va_list list);
int gt_prc(const char *format, int *i, va_list list);
int gt_sz(const char *format, int *i);

/*Function to print string in reverse*/
int prt_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int prt_r13(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int hdle_wrt(char c, char buffer[],
	int flags, int width, int precision, int size);
int wrt_numb(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int wrt_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int wrt_ptr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int wrt_unsg(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/******************* UTILS *******************/
int is_prt(char);
int app_hex(char, char[], int);
int is_dig(char);

long int conv_siz_numb(long int num, int size);
long int conv_siz_unsg(unsigned long int num, int size);

#endif /* MAIN_H */
