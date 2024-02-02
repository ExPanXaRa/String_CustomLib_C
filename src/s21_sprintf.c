#include "s21_sprintf.h"

void s21_reset_flags(flag *flags) {
  flags->minus = 0;
  flags->plus = 0;
  flags->space = 0;
  flags->hashtag = 0;
  flags->zero = 0;
}

void s21_check_and_decrement_flags(flag *flags) {
  if (flags->hashtag > 1) flags->hashtag = 1;
  if (flags->minus > 1) flags->minus = 1;
  if (flags->plus > 1) flags->plus = 1;
  if (flags->space > 1) flags->space = 1;
  if (flags->zero > 1) flags->zero = 1;
}

void s21_input_validation(flag *flags, char format, long *precision,
                          int precision_modified) {
  s21_check_and_decrement_flags(flags);

  if (format == 'd' || format == 'u' || format == 'i') {
    if (!precision_modified) *precision = 0;
    if (*precision != 0) flags->zero = 0;
    flags->hashtag = 0;
    if (format == 'u') {
      flags->plus = 0;
      flags->space = 0;
    }
  }

  if (format == 's' || format == 'c') {
    if (!precision_modified) *precision = NOT_MODIFIED;
    flags->plus = 0;
    flags->space = 0;
    flags->zero = 0;
    flags->hashtag = 0;
  }

  if (format == 'o' || format == 'x' || format == 'X') {
    if (!precision_modified) *precision = 0;
    if (*precision != 0) flags->zero = 0;
    flags->space = 0;
    flags->plus = 0;
  }

  if (format == 'x' || format == 'X') {
    if (flags->hashtag) flags->zero = 0;
  }

  if (flags->minus) flags->zero = 0;
  if (flags->plus) flags->space = 0;
}

void s21_putchar_to_str(const char c, char *str, int *iter_str) {
  str[*iter_str] = c;
  (*iter_str)++;
}

void s21_handle_sign(char *str, int *iter_str, flag flags, int is_negative) {
  if (flags.plus && !is_negative) {
    s21_putchar_to_str('+', str, iter_str);
  } else if (is_negative) {
    s21_putchar_to_str('-', str, iter_str);
  }
}

void s21_handle_width(char *str, int *iter_str, int arg_len, flag flags,
                      long width) {
  if (width > 0 && width > arg_len) {
    for (int i = 0; i < (int)width - arg_len; i++) {
      if (flags.zero)
        str[*iter_str + i] = '0';
      else
        str[*iter_str + i] = ' ';
    }
    (*iter_str) += width - arg_len;
  }
}

void s21_handleSignAndWidth(flag flags, char *str, int *iter_str, int *counter,
                            int is_negative, long width) {
  int num_position = 0;
  if (flags.space && !is_negative) {
    s21_putchar_to_str(' ', str, iter_str);
    (*counter)++;
  }

  if (flags.minus) {
    s21_handle_sign(str, iter_str, flags, is_negative);
    num_position = *iter_str;
    if (flags.space || flags.plus || is_negative)
      *(iter_str) += *counter - 1;
    else
      *(iter_str) += *counter;
  }

  if (flags.zero) {
    s21_handle_sign(str, iter_str, flags, is_negative);
    s21_handle_width(str, iter_str, *counter, flags, width);
  } else {
    s21_handle_width(str, iter_str, *counter, flags, width);
    if (!flags.minus) s21_handle_sign(str, iter_str, flags, is_negative);
  }

  if (flags.minus) *(iter_str) = num_position;
}

void s21_del_spaces(char *str, int *iter_str) {
  int len = s21_strlen(str);
  while (len > 0 && str[len - 1] == '0') {
    str[--len] = '\0';
    (*iter_str)--;
  }
}

int s21_get_digits_amount(long long num, int base) {
  if (num == 0) return 1;

  int amount = 0;
  while (num != 0) {
    num /= base;
    amount++;
  }
  return amount;
}

void s21_null_to_str(char *str, int *iter_str, char format) {
  if (format == 'p') {
    s21_putchar_to_str('(', str, iter_str);
    s21_putchar_to_str('n', str, iter_str);
    s21_putchar_to_str('i', str, iter_str);
    s21_putchar_to_str('l', str, iter_str);
    s21_putchar_to_str(')', str, iter_str);
  } else {
    s21_putchar_to_str('(', str, iter_str);
    s21_putchar_to_str('n', str, iter_str);
    s21_putchar_to_str('u', str, iter_str);
    s21_putchar_to_str('l', str, iter_str);
    s21_putchar_to_str('l', str, iter_str);
    s21_putchar_to_str(')', str, iter_str);
  }
  /* https://imgur.com/IBHoP7z */
}

void s21_add_num_to_str(char *str, long long num, int base, int precision,
                        int *iter_str) {
  int counter = s21_get_digits_amount(num, base);

  while (precision - counter > 0) {
    s21_putchar_to_str('0', str, iter_str);
    precision--;
  }

  while (counter > 0) {
    long long tmp = num / pow(base, counter - 1);
    s21_putchar_to_str('0' + (char)tmp, (char *)str, iter_str);
    num -= tmp * pow(base, counter - 1);
    counter--;
  }
}

int s21_get_amount_of_sym_float(long double num, int precision, flag flags,
                                int is_negative) {
  int counter = 0;
  counter = precision != 0 ? precision + 1 : precision;

  if (is_negative || flags.plus) counter++;
  if (flags.hashtag && !precision) counter++;

  num = roundl(num * powl(10.0L, (long double)precision)) /
        powl(10.0L, (long double)precision);

  long long int_part = (long long)num;

  counter += s21_get_digits_amount(int_part, 10);

  return counter;
}

int s21_get_amount_of_sym_exp(long double num, int precision, flag flags,
                              int g_format) {
  long double print_matissa = 1;

  if (g_format) print_matissa = num < 10 ? 0 : 1;

  int counter = 0;
  counter = precision != 0 ? precision + 3 : precision + 2;

  if (num < 10 && g_format) counter = 0;
  if (num < 0 || flags.plus) counter++;
  if (flags.hashtag && !precision) counter++;

  if (num < 0) num = -num;

  int mantissa = s21_count_mantissa(&num, precision);

  int zeros = 0;
  long double tmp = num * powl(10.0L, precision);

  if (g_format) {
    while ((long long)tmp % 10 == 0) {
      tmp = tmp / 10.0;
      zeros++;
    }
  }

  int int_part = (int)num;

  counter += s21_get_digits_amount(int_part, 10);

  if (print_matissa) {
    int mants_len = s21_get_digits_amount(mantissa, 10);
    counter += mants_len > 1 ? mants_len : mants_len + 1;
  }

  counter -= zeros;

  return counter;
}

int s21_count_mantissa(long double *num, long precision) {
  int mantissa = 0;
  while (*num >= 10) {
    *num /= 10;
    mantissa += 1;
  }

  while (*num < 1 && fabsl(*num) >= 1e-20) {
    *num *= 10;
    mantissa -= 1;
  }

  *num = roundl(*num * powl(10.0L, (long double)precision)) /
         powl(10.0L, (long double)precision);

  if (*num >= 10) {
    *num /= 10;
    mantissa += 1;
  }

  return mantissa;
}

void s21_mantissa_to_str(int mantissa, char format, char *str, int *iter_str) {
  s21_putchar_to_str(format, (char *)str, iter_str);

  if (mantissa >= 0)
    s21_putchar_to_str('+', (char *)str, iter_str);
  else {
    s21_putchar_to_str('-', (char *)str, iter_str);
    mantissa = -mantissa;
  }

  if (mantissa < 10) {
    s21_putchar_to_str('0', (char *)str, iter_str);
    s21_putchar_to_str('0' + mantissa, (char *)str, iter_str);
  } else
    s21_add_num_to_str(str, mantissa, 10, 0, iter_str);
}

void s21_add_exp_to_str(long double num, char *str, int *iter_str, flag flags,
                        int precision, char format, int g_format) {
  int print_exp = 1;

  if (g_format) print_exp = num > 10 ? 1 : 0;

  if (num < 0) num = -num;

  int mantissa = s21_count_mantissa(&num, precision);

  int int_part = (int)num;
  long double fractional_part = num - int_part;

  s21_add_num_to_str(str, int_part, 10, 0, iter_str);

  if ((fractional_part || num < 10) && (precision != 0 || flags.hashtag))
    s21_putchar_to_str('.', str, iter_str);

  for (int i = 0; i < precision; i++) {
    fractional_part *= 10;
    int digit = (int)(fractional_part);
    if (fabsl(fractional_part - digit - 1) <= 1e-7) digit++;
    s21_putchar_to_str('0' + digit, (char *)str, iter_str);
    fractional_part -= digit;
  }

  if (g_format) s21_del_spaces(str, iter_str);

  if (print_exp) {
    s21_mantissa_to_str(mantissa, format, str, iter_str);
  }
}

void s21_add_float_to_str(long double num, char *str, int *iter_str, flag flags,
                          int precision) {
  if (num < 0) {
    num = -num;
  }

  num = roundl(num * powl(10.0L, (long double)precision)) /
        powl(10.0L, (long double)precision);

  long long int_part = (long long)num;
  long double float_part = num - int_part;

  if (int_part > 0)
    s21_add_num_to_str(str, int_part, 10, 0, iter_str);
  else
    s21_putchar_to_str('0', str, iter_str);

  if (precision != 0 || flags.hashtag) s21_putchar_to_str('.', str, iter_str);

  for (int i = 0; i < precision; i++) {
    float_part *= 10;
    int digit = (int)float_part;
    if (fabsl(float_part - digit - 1) <= 1e-7) digit++;
    s21_putchar_to_str('0' + digit, str, iter_str);
    float_part -= digit;
  }
}

void s21_char_format(va_list *specifier, char *str, int *iter_str, flag flags,
                     long width) {
  int var = va_arg(*specifier, int);
  int arg_len = 1;

  s21_handleSignAndWidth(flags, str, iter_str, &arg_len, 0, width);

  s21_putchar_to_str(var, str, iter_str);
  if (width >= arg_len && flags.minus) *(iter_str) += width - arg_len;
}

void s21_d_format(va_list *specifier, char *str, int *iter_str, flag flags,
                  int precision, char len_format, long width) {
  long num = 0;
  int is_negative = 0;

  if (len_format == 'h')
    num = (short int)va_arg(*specifier, int);
  else if (len_format == 'l')
    num = va_arg(*specifier, long);
  else
    num = va_arg(*specifier, int);

  int counter = s21_get_digits_amount(num, 10);

  if (precision >= counter) counter += precision - counter;
  if (flags.plus && num >= 0) counter++;

  if (num < 0) {
    num = -num;
    is_negative = 1;
    counter++;
  }

  s21_handleSignAndWidth(flags, str, iter_str, &counter, is_negative, width);
  s21_add_num_to_str(str, num, 10, precision, iter_str);
  if (width >= counter && flags.minus) *(iter_str) += width - counter;
}

void s21_float_format(va_list *specifier, char *str, int *iter_str, flag flags,
                      char len_format, int precision, long width) {
  long double num = 0;
  int is_negative = 0;
  if (len_format == 'L')
    num = va_arg(*specifier, long double);
  else
    num = va_arg(*specifier, double);

  if (num < 0) is_negative = 1;

  int counter = s21_get_amount_of_sym_float(num, precision, flags, is_negative);

  s21_handleSignAndWidth(flags, str, iter_str, &counter, is_negative, width);
  s21_add_float_to_str(num, str, iter_str, flags, precision);
  if (width >= counter && flags.minus) *(iter_str) += width - counter;
}

void s21_trim_float(long double num, long *precision) {
  int test_pow = 1;
  while (num < 1 && (int)(num * powl(10.0L, (long double)test_pow)) == 0 &&
         test_pow < 4) {
    (*precision)++;
    test_pow++;
  }
  while (num >= 1 &&
         (int)(num / powl(10.0L, (long double)(test_pow - 1))) != 0 &&
         test_pow <= 6) {
    (*precision)--;
    test_pow++;
  }
  long double tmp = num * powl(10.0L, *precision);

  while ((long long)roundl(tmp) % 10 == 0) {
    (*precision)--;
    tmp /= 10.0L;
  }
}

void s21_g_format(va_list *specifier, char *str, int *iter_str, flag flags,
                  char len_format, long precision, long width, char format) {
  long double num = 0;
  int is_neg = 0;
  int counter = 0;
  if (len_format == 'L')
    num = va_arg(*specifier, long double);
  else
    num = va_arg(*specifier, double);

  if (num == 0) {
    counter = 1;
    s21_handleSignAndWidth(flags, str, iter_str, &counter, 0, width);
    s21_putchar_to_str('0', str, iter_str);
    return;
  }

  if (num < 0) {
    is_neg = 1;
    num = -num;
  }

  if (num > 1e-4 && num < 1e6 &&
      precision >= s21_get_digits_amount((long long)num, 10)) {
    s21_trim_float(num, &precision);
    if (num >= 1 && fabsl((long long)num - num) <= 1e-18) {
      counter += s21_get_digits_amount((long long)num, 10);
      s21_handleSignAndWidth(flags, str, iter_str, &counter, is_neg, width);
      s21_add_num_to_str(str, num, 10, 0, iter_str);
    } else {
      counter += s21_get_amount_of_sym_float(num, precision, flags, is_neg);
      s21_handleSignAndWidth(flags, str, iter_str, &counter, is_neg, width);
      s21_add_float_to_str(num, str, iter_str, flags, precision);
    }

    if (width >= counter && flags.minus) *(iter_str) += width - counter;

    if (fabsl((int)num - num) > 1e-18 && precision != 0)
      s21_del_spaces(str, iter_str);
  } else {
    if (format == 'G')
      format = 'E';
    else
      format = 'e';

    if (!precision) precision = 1;
    if (is_neg) counter++;
    counter += s21_get_amount_of_sym_exp(num, precision - 1, flags, 1);

    s21_handleSignAndWidth(flags, str, iter_str, &counter, is_neg, width);
    s21_add_exp_to_str(num, str, iter_str, flags, precision - 1, format, 1);
    if (width >= counter && flags.minus) *(iter_str) += width - counter;
  }
}

void s21_e_format(va_list *specifier, char *str, int *iter_str, char format,
                  flag flags, char len_format, int precision, long width) {
  long double num = 0;
  int is_negative = 0;
  if (len_format == 'L')
    num = va_arg(*specifier, long double);
  else
    num = va_arg(*specifier, double);

  if (num < 0) is_negative = 1;

  int counter = s21_get_amount_of_sym_exp(num, precision, flags, 0);

  s21_handleSignAndWidth(flags, str, iter_str, &counter, is_negative, width);
  s21_add_exp_to_str(num, str, iter_str, flags, precision, format, 0);
  if (width >= counter && flags.minus) *(iter_str) += width - counter;
}

void s21_u_format(va_list *specifier, char *str, int *iter_str, flag flags,
                  int precision, char len_format, int width) {
  unsigned long num = 0;

  if (len_format == 'h')
    num = (unsigned short int)va_arg(*specifier, unsigned int);
  else if (len_format == 'l')
    num = va_arg(*specifier, unsigned long);
  else
    num = va_arg(*specifier, unsigned int);

  int counter = s21_get_digits_amount(num, 10);
  if (precision >= counter) counter += precision - counter;

  s21_handleSignAndWidth(flags, str, iter_str, &counter, 0, width);
  s21_add_num_to_str(str, num, 10, precision, iter_str);
  if (width >= counter && flags.minus) *(iter_str) += width - counter;
}

void s21_o_format(va_list *specifier, char *str, int *iter_str, flag flags,
                  int precision, char len_format, int width) {
  unsigned long num = 0;

  if (len_format == 'h')
    num = (unsigned short int)va_arg(*specifier, unsigned int);
  else if (len_format == 'l')
    num = va_arg(*specifier, unsigned long);
  else
    num = va_arg(*specifier, unsigned int);

  int counter = s21_get_digits_amount(num, 8);
  if (flags.hashtag && num != 0 && precision < counter) counter++;
  if (precision >= counter) counter += precision - counter;
  s21_handleSignAndWidth(flags, str, iter_str, &counter, 0, width);

  if (flags.hashtag && precision < counter && num != 0)
    s21_putchar_to_str('0', str, iter_str);

  s21_add_num_to_str(str, num, 8, precision, iter_str);
  if (width >= counter && flags.minus) *(iter_str) += width - counter;
}

void s21_x_format(va_list *specifier, char *str, int *iter_str, char format,
                  flag flags, int precision, char len_format, int width) {
  unsigned long num = 0;

  if (len_format == 'h')
    num = (unsigned short int)va_arg(*specifier, unsigned int);
  else if (len_format == 'l')
    num = va_arg(*specifier, unsigned long);
  else
    num = va_arg(*specifier, unsigned int);

  int counter = s21_get_digits_amount(num, 16);
  int position_counter = counter;

  if (precision >= counter) position_counter += precision - counter;

  if (flags.hashtag) position_counter += 2;

  s21_handleSignAndWidth(flags, str, iter_str, &position_counter, 0, width);

  if (flags.hashtag && num != 0) {
    s21_putchar_to_str('0', str, iter_str);
    if (format == 'x')
      s21_putchar_to_str('x', str, iter_str);
    else
      s21_putchar_to_str('X', str, iter_str);
  }

  if (precision != 0) {
    while (precision - counter > 0) {
      s21_putchar_to_str('0', str, iter_str);
      precision--;
    }
  }

  int to_upper = 0;
  if (format == 'X') to_upper = 32;

  while (counter > 0) {
    unsigned long tmp = num / pow(16, counter - 1);
    if (tmp < 10)
      s21_putchar_to_str('0' + (char)tmp, (char *)str, iter_str);
    else
      s21_putchar_to_str('a' - to_upper + tmp - 10, (char *)str, iter_str);
    num -= tmp * pow(16, counter - 1);
    counter--;
  }

  if (width >= position_counter && flags.minus)
    *(iter_str) += width - position_counter;
}

void s21_p_format(va_list *specifier, char format, char *str, int *iter_str,
                  flag flags, int width) {
  void *ptr = va_arg(*specifier, void *);

  if (ptr != S21_NULL) {
    unsigned long num = (unsigned long)ptr;

    int counter = s21_get_digits_amount(num, 16);
    int position_counter = counter + 2;

    s21_handleSignAndWidth(flags, str, iter_str, &position_counter, 0, width);

    s21_putchar_to_str('0', (char *)str, iter_str);
    s21_putchar_to_str('x', (char *)str, iter_str);

    while (counter > 0) {
      unsigned long tmp = num / pow(16, counter - 1);
      if (tmp < 10)
        s21_putchar_to_str('0' + tmp, (char *)str, iter_str);
      else
        s21_putchar_to_str('a' + tmp - 10, (char *)str, iter_str);
      num -= tmp * pow(16, counter - 1);
      counter--;
    }

    if (width >= position_counter && flags.minus)
      *(iter_str) += width - position_counter;
  } else {
    s21_null_to_str(str, iter_str, format);
  }
}

void s21_string_format(va_list *specifier, char format, char *str,
                       int *iter_str, flag flags, int precision, long width) {
  char *var = va_arg(*specifier, char *);
  int arg_len = 0;

  if (var != S21_NULL)
    arg_len = s21_strlen(var);
  else
    arg_len = 6;

  if (precision != NOT_MODIFIED && (precision < arg_len && precision > -1))
    arg_len += precision - arg_len;

  s21_handleSignAndWidth(flags, str, iter_str, &arg_len, 0, width);

  if (var != S21_NULL) {
    for (int i = 0; i < arg_len; i++) {
      s21_putchar_to_str(*(var + i), str, iter_str);
    }
  } else {
    s21_null_to_str(str, iter_str, format);
  }

  if (width >= arg_len && flags.minus) *(iter_str) += width - arg_len;
}

void s21_handle_format(va_list *specifier, char format, char *str,
                       int *iter_str, flag flags, char len_format,
                       int precision, long width) {
  switch (format) {
    case 'c':
      s21_char_format(specifier, str, iter_str, flags, width);
      break;
    case 'i':
    case 'd':
      s21_d_format(specifier, str, iter_str, flags, precision, len_format,
                   width);
      break;
    case 'f':
      s21_float_format(specifier, str, iter_str, flags, len_format, precision,
                       width);
      break;
    case 'G':
    case 'g':
      s21_g_format(specifier, str, iter_str, flags, len_format, precision,
                   width, format);
      break;
    case 'E':
    case 'e':
      s21_e_format(specifier, str, iter_str, format, flags, len_format,
                   precision, width);
      break;
    case 'o':
      s21_o_format(specifier, str, iter_str, flags, precision, len_format,
                   width);
      break;
    case 's':
      s21_string_format(specifier, format, str, iter_str, flags, precision,
                        width);
      break;
    case 'u':
      s21_u_format(specifier, str, iter_str, flags, precision, len_format,
                   width);
      break;
    case 'X':
    case 'x':
      s21_x_format(specifier, str, iter_str, format, flags, precision,
                   len_format, width);
      break;
    case 'p':
      s21_p_format(specifier, format, str, iter_str, flags, width);
      break;
    case '%':
      s21_putchar_to_str('%', str, iter_str);
      break;
    default:
      break;
  }

  if (format == 'n') {
    int *var = va_arg(*specifier, int *);
    if (var != S21_NULL) *var = (*iter_str);
  }
}

void s21_handle_flags(const char *format, int *iter_format, flag *flags) {
  while (format[*iter_format] == '-' || format[*iter_format] == '+' ||
         format[*iter_format] == ' ' || format[*iter_format] == '#' ||
         format[*iter_format] == '0') {
    switch (format[*iter_format]) {
      case '-':
        flags->minus++;
        break;
      case '+':
        flags->plus++;
        break;
      case ' ':
        flags->space++;
        break;
      case '#':
        flags->hashtag++;
        break;
      case '0':
        flags->zero++;
        break;
      default:
        break;
    }
    (*iter_format)++;
  }
}

void s21_num_from_format(const char *format, int *iter_format, long *buffer) {
  char *endptr = S21_NULL;
  *buffer = s21_strtol((char *)(format + *iter_format), &endptr, 10);
  *iter_format += endptr - (format + *iter_format);
}

int s21_sprintf(char *str, const char *format, ...) {
  if (!str || !format || *format == '\0') return -1;

  s21_strncpy(str, "\0", 1);

  va_list specifier;
  va_start(specifier, format);

  flag flags = {0};

  int iter_str = 0, iter_format = 0;

  long precision = 6;
  long width = 0;

  while (*(format + iter_format)) {
    if (format[iter_format] == '%') {
      int precision_modified = 0;
      iter_format++;

      /* flags */
      s21_handle_flags(format, &iter_format, &flags);

      /* width */
      if (format[iter_format] >= '0' && format[iter_format] <= '9') {
        s21_num_from_format(format, &iter_format, &width);
      } else if (format[iter_format] == '*') {
        width = va_arg(specifier, int);
        iter_format++;
      }

      /* precision */
      if (format[iter_format] == '.') {
        precision_modified = 1;
        iter_format++;
        if (format[iter_format] >= '0' && format[iter_format] <= '9') {
          s21_num_from_format(format, &iter_format, &precision);
        } else if (format[iter_format] == '*') {
          precision = va_arg(specifier, int);
          iter_format++;
        } else {
          precision = 0;
        }
      }

      /* length */
      char len_format = 0;
      len_format = format[iter_format];
      if (len_format == 'l' || len_format == 'h' || len_format == 'L')
        iter_format++;

      /* format */
      s21_input_validation(&flags, format[iter_format], &precision,
                           precision_modified);

      s21_handle_format(&specifier, format[iter_format], str, &iter_str, flags,
                        len_format, precision, width);
      iter_format++;
    } else {
      s21_putchar_to_str(format[iter_format], str, &iter_str);
      iter_format++;
    }
    s21_reset_flags(&flags);
    width = 0;
    precision = 6;
  }

  str[iter_str] = '\0';
  va_end(specifier);
  return iter_str;
}
