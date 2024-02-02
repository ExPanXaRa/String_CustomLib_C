#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#include "s21_sprintf.h"
#include "s21_string.h"

#define NOT_MODIFIED -335
typedef struct {
  int plus;
  int minus;
  int space;
  int hashtag;
  int zero;
} flag;

int s21_sprintf(char *str, const char *format, ...);

void s21_reset_flags(flag *flags);
void s21_check_and_decrement_flags(flag *flags);
void s21_input_validation(flag *flags, char format, long *precision,
                          int precision_modified);
void s21_putchar_to_str(const char c, char *str, int *iter_str);
void s21_handle_sign(char *str, int *iter_str, flag flags, int is_negative);
void s21_handle_width(char *str, int *iter_str, int arg_len, flag flags,
                      long width);
void s21_handleSignAndWidth(flag flags, char *str, int *iter_str, int *counter,
                            int is_negative, long width);
void s21_del_spaces(char *str, int *iter_str);
int s21_get_digits_amount(long long num, int base);
void s21_null_to_str(char *str, int *iter_str, char format);
void s21_add_num_to_str(char *str, long long num, int base, int precision,
                        int *iter_str);
int s21_get_amount_of_sym_float(long double num, int precision, flag flags,
                                int is_negative);
int s21_get_amount_of_sym_exp(long double num, int precision, flag flags,
                              int g_format);
void s21_add_exp_to_str(long double num, char *str, int *iter_str, flag flags,
                        int precision, char format, int g_format);
void s21_add_float_to_str(long double num, char *str, int *iter_str, flag flags,
                          int precision);
void s21_char_format(va_list *specifier, char *str, int *iter_str, flag flags,
                     long width);
void s21_d_format(va_list *specifier, char *str, int *iter_str, flag flags,
                  int precision, char len_format, long width);
void s21_float_format(va_list *specifier, char *str, int *iter_str, flag flags,
                      char len_format, int precision, long width);
void s21_g_format(va_list *specifier, char *str, int *iter_str, flag flags,
                  char len_format, long precision, long width, char format);
void s21_e_format(va_list *specifier, char *str, int *iter_str, char format,
                  flag flags, char len_format, int precision, long width);
void s21_u_format(va_list *specifier, char *str, int *iter_str, flag flags,
                  int precision, char len_format, int width);
void s21_o_format(va_list *specifier, char *str, int *iter_str, flag flags,
                  int precision, char len_format, int width);
void s21_x_format(va_list *specifier, char *str, int *iter_str, char format,
                  flag flags, int precision, char len_format, int width);
void s21_p_format(va_list *specifier, char format, char *str, int *iter_str,
                  flag flags, int width);
void s21_string_format(va_list *specifier, char format, char *str,
                       int *iter_str, flag flags, int precision, long width);
void s21_handle_format(va_list *specifier, char format, char *str,
                       int *iter_str, flag flags, char len_format,
                       int precision, long width);
void s21_handle_flags(const char *format, int *iter_format, flag *flags);

void s21_num_from_format(const char *format, int *iter_format, long *buffer);
void s21_trim_float(long double num, long *precision);
int s21_count_mantissa(long double *num, long precision);
void s21_mantissa_to_str(int mantissa, char format, char *str, int *iter_str);

#endif  // SRC_S21_SPRINTF_H_