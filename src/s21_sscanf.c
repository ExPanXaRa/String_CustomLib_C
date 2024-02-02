#include <limits.h>

#include "s21_string.h"

int s21_str_split(char symb) {
  return (symb == ' ' || symb == '\n' || symb == '\t');
}

int s21_is_dig_or_sign(char symb, char format, int base) {
  if (base == 16)
    return ((symb >= '0' && symb <= '9') || symb == '-' ||
            (symb >= 'A' && symb <= 'F') || (symb >= 'a' && symb <= 'f') ||
            symb == 'x');

  if (format == 'f')
    return ((symb >= '0' && symb <= '9') || symb == '-' || symb == '.' ||
            symb == 'e');
  else
    return ((symb >= '0' && symb <= '9') || symb == '-');
}

char *s21_create_str_cpy(char *src, long *size, char format, int base) {
  long length = 0;
  while (s21_is_dig_or_sign(src[length], format, base)) length++;

  if (*size > length) *size = length;

  if (*size == 0) return S21_NULL;
  char *str_cpy = malloc(sizeof(char) * (*size + 1));
  if (!str_cpy)
    str_cpy = S21_NULL;
  else {
    s21_strncpy(str_cpy, src, *size);
    str_cpy[*size] = '\0';
  }

  return str_cpy;
}

void s21_char_format_sscanf(va_list *specifier, const char *str, int *iter_str,
                            int *end, int assign_suppr, long width) {
  if (assign_suppr) {
    if (width > 0 && width <= (long int)s21_strlen(str))
      (*iter_str) += width - 1;
    return;
  }

  char *var = va_arg(*specifier, char *);
  if (str + *iter_str && str[*iter_str] != '\0') {
    *var = str[*iter_str];

    if (width > 0 && width <= (long int)s21_strlen(str))
      (*iter_str) += width - 1;
  } else
    *end = 0;
}

void s21_d_format_sscanf(va_list *specifier, const char *str, int *iter_str,
                         int *end, char len_format, int assign_suppr,
                         long width) {
  if (assign_suppr) {
    int i = 0;
    while (s21_is_dig_or_sign(str[*iter_str + i], 'd', 10)) i++;

    if (width > 0 && width < i) i = width;

    (*iter_str) += i - 1;
    return;
  }

  char *str_cpy = (char *)str + *iter_str;
  long tmp = s21_atol(str_cpy);
  if (!(tmp == 0 && str_cpy[0] != '0')) {
    if (width > 0) {
      str_cpy = s21_create_str_cpy(str_cpy, &width, 'd', 10);
      if (!str_cpy) {
        *end = 0;
        return;
      }
    }
    tmp = s21_atol(str_cpy);

    if (len_format == 'h') {
      if (tmp <= SHRT_MAX && tmp >= SHRT_MIN) {
        short *var = va_arg(*specifier, short *);
        *var = (short)tmp;
      }
    } else if (len_format == 'l') {
      long *var = va_arg(*specifier, long *);
      *var = tmp;
    } else {
      int *var = va_arg(*specifier, int *);
      *var = (int)tmp;
    }

    if (width > 0 && width <= (long int)s21_strlen(str)) {
      if (str_cpy) free(str_cpy);
      (*iter_str) += width - 1;
    } else {
      int i = 0;
      while (s21_is_dig_or_sign(str[*iter_str + i], 'd', 10)) i++;
      (*iter_str) += i - 1;
    }
  } else
    *end = 0;
}

void s21_i_format(va_list *specifier, const char *str, int *iter_str, int *end,
                  char len_format, int assign_suppr, long width) {
  char *endptr = S21_NULL;
  char *str_cpy = (char *)str + *iter_str;
  if (width > 0) {
    str_cpy = s21_create_str_cpy(str_cpy, &width, 'i', 16);
    if (!str_cpy) {
      *end = 0;
      return;
    }
  }
  long tmp = s21_strtol(str_cpy, &endptr, 0);
  (*iter_str) += endptr - str_cpy - 1;

  if (assign_suppr) {
    if (width > 0 && str_cpy) free(str_cpy);
    return;
  }

  if (str_cpy == endptr) {
    *end = 0;
    if (width > 0 && str_cpy) free(str_cpy);
    return;
  }

  if (len_format == 'h') {
    if (tmp <= SHRT_MAX) {
      short *var = va_arg(*specifier, short *);
      *var = (short)tmp;
    }
  } else if (len_format == 'l') {
    long *var = va_arg(*specifier, long *);
    *var = tmp;
  } else {
    int *var = va_arg(*specifier, int *);
    *var = (int)tmp;
  }

  if (width > 0 && str_cpy) free(str_cpy);
}

void s21_unsigned_int_format(va_list *specifier, const char *str, int *iter_str,
                             char format, int *end, char len_format,
                             int assign_suppr, long width) {
  int base = 10;
  if (format == 'x')
    base = 16;
  else if (format == 'o')
    base = 8;

  char *endptr = S21_NULL;
  char *str_cpy = (char *)str + *iter_str;
  if (width > 0) {
    str_cpy = s21_create_str_cpy(str_cpy, &width, 'u', base);
    if (!str_cpy) {
      *end = 0;
      return;
    }
  }

  unsigned long tmp = s21_strtoul(str_cpy, &endptr, base);
  (*iter_str) += endptr - str_cpy - 1;

  if (assign_suppr) {
    if (width > 0 && str_cpy) free(str_cpy);
    return;
  }

  if (str_cpy == endptr) {
    *end = 0;
    if (width > 0 && str_cpy) free(str_cpy);
    return;
  }

  if (len_format == 'h' && (tmp <= SHRT_MAX)) {
    unsigned short *var = va_arg(*specifier, unsigned short *);
    *var = (unsigned short)tmp;
  } else if (len_format == 'l') {
    unsigned long *var = va_arg(*specifier, unsigned long *);
    *var = tmp;
  } else {
    unsigned int *var = va_arg(*specifier, unsigned int *);
    *var = (unsigned int)tmp;
  }

  if (width > 0)
    if (str_cpy) free(str_cpy);
}

void s21_pointer_format(va_list *specifier, const char *str, int *iter_str,
                        int *end, int assign_suppr) {
  char *endptr = S21_NULL;
  unsigned long tmp = s21_strtoul(str + *iter_str, &endptr, 16);
  if (str + *iter_str == endptr) {
    *end = 0;
    return;
  }

  (*iter_str) += endptr - (str + *iter_str) - 1;

  if (assign_suppr) return;

  void **ptr = va_arg(*specifier, void **);
  *ptr = (void *)tmp;
}

void s21_long_double_format(va_list *specifier, const char *str, int *iter_str,
                            int *end, int assign_suppr, long width) {
  char *endptr = S21_NULL;
  char *str_cpy = (char *)str + *iter_str;
  if (width > 0) {
    str_cpy = s21_create_str_cpy(str_cpy, &width, 'f', 10);
    if (!str_cpy) {
      *end = 0;
      return;
    }
  }
  long double tmp = s21_strtold(str_cpy, &endptr);
  if (endptr == str_cpy) {
    (*end) = 0;
    return;
  }
  (*iter_str) += endptr - str_cpy - 1;

  if (assign_suppr) {
    if (width > 0 && str_cpy) free(str_cpy);
    return;
  }

  long double *var = va_arg(*specifier, long double *);
  *var = tmp;

  if (str_cpy == endptr) *end = 0;

  if (width > 0 && str_cpy) free(str_cpy);
}

void s21_float_format_sscanf(va_list *specifier, const char *str, int *iter_str,
                             int *end, int assign_suppr, long width) {
  char *endptr = S21_NULL;
  char *str_cpy = (char *)str + *iter_str;
  if (width > 0) {
    str_cpy = s21_create_str_cpy(str_cpy, &width, 'f', 10);
    if (!str_cpy) {
      *end = 0;
      return;
    }
  }

  float tmp = s21_strtod(str_cpy, &endptr);
  if (endptr == str_cpy) {
    (*end) = 0;
    return;
  }

  (*iter_str) += endptr - str_cpy - 1;

  if (assign_suppr) {
    if (width > 0 && str_cpy) free(str_cpy);
    return;
  }

  float *var = va_arg(*specifier, float *);
  *var = tmp;

  if (str_cpy == endptr) *end = 0;

  if (width > 0 && str_cpy) free(str_cpy);
}

void s21_string_format_sscanf(va_list *specifier, const char *str,
                              int *iter_str, int assign_suppr, long width) {
  if (assign_suppr) {
    int i = 0;
    while (!s21_str_split(str[*iter_str + i]) && str[*iter_str + i] != '\0')
      i++;

    if (width > 0 && width < i) i = width;

    (*iter_str) += i - 1;
    return;
  }

  char *var = va_arg(*specifier, char *);

  int i = 0;
  while (!s21_str_split(str[*iter_str + i]) && str[*iter_str + i] != '\0') {
    if (width > 0 && i == width) break;

    var[i] = str[*iter_str + i];
    i++;
  }

  var[i] = '\0';
  (*iter_str) += i - 1;
}

void s21_n_format(va_list *specifier, const char *str, int *iter_str,
                  const char *format, int *iter_format) {
  int *var = va_arg(*specifier, int *);
  if (*iter_str > 0) {
    if (s21_str_split(*(str + *iter_str - 1))) (*iter_str)--;
  }
  if (*iter_format > 0) {
    *var = (s21_str_split(format[*iter_format - 1]) && str[*iter_str] != '\0'
                ? *iter_str + 1
                : *iter_str);
  }
  if (*iter_str == 0) *var = 0;
  (*iter_str)--;
}

void s21_format_check(char symb, va_list *specifier, const char *str,
                      int *iter_str, int *calc, int *end, const char *format,
                      int *iter_format, char len_format, int assign_suppr,
                      long width) {
  if (symb == 'c') {
    s21_char_format_sscanf(specifier, str, iter_str, end, assign_suppr, width);
  } else if (symb == 'd')
    s21_d_format_sscanf(specifier, str, iter_str, end, len_format, assign_suppr,
                        width);
  else if (symb == 'i')
    s21_i_format(specifier, str, iter_str, end, len_format, assign_suppr,
                 width);
  else if (symb == 'e' || symb == 'E' || symb == 'g' || symb == 'G' ||
           symb == 'f') {
    if (len_format == 'L')
      s21_long_double_format(specifier, str, iter_str, end, assign_suppr,
                             width);
    else
      s21_float_format_sscanf(specifier, str, iter_str, end, assign_suppr,
                              width);
  } else if (symb == 'o')
    s21_unsigned_int_format(specifier, str, iter_str, 'o', end, len_format,
                            assign_suppr, width);
  else if (symb == 's')
    s21_string_format_sscanf(specifier, str, iter_str, assign_suppr, width);
  else if (symb == 'u')
    s21_unsigned_int_format(specifier, str, iter_str, 'u', end, len_format,
                            assign_suppr, width);
  else if (symb == 'x' || symb == 'X')
    s21_unsigned_int_format(specifier, str, iter_str, 'x', end, len_format,
                            assign_suppr, width);
  else if (symb == 'p')
    s21_pointer_format(specifier, str, iter_str, end, assign_suppr);
  else if (symb == 'n') {
    s21_n_format(specifier, str, iter_str, format, iter_format);
    (*calc)--;
  } else {
    *end = 0;
    (*calc)--;
  }
}

void s21_n_spec_at_the_end(const char *format, int *i_format,
                           va_list *specifier, const char *str, int i_str,
                           int *calc, int *end) {
  if (s21_strchr(format + *i_format, '%') &&
      s21_strchr(format + *i_format, 'n')) {
    int assign_suppr = 0;
    long width = 0;
    char len_format = '\0';

    s21_format_check('n', specifier, str, &i_str, calc, end, format, i_format,
                     len_format, assign_suppr, width);
    (*calc)++;
  }
}

int is_whitespace(const char *str) {
  while (*str) {
    if (*str != ' ') return 0;
    str++;
  }
  return 1;
}

int s21_char_check(const char *format, int iter_format) {
  int otv = 0;

  for (; format[iter_format] != '%' && !s21_str_split(format[iter_format]) &&
         format[iter_format] != '\0' && otv == 0;
       iter_format++) {
    if (format[iter_format] == 'c') otv = 1;
  }

  return otv;
}

int s21_sscanf(const char *str, const char *format, ...) {
  if ((!str || !format || *str == '\0' || is_whitespace(str)) &&
      !s21_strchr(format, 'n'))
    return -1;

  va_list specifier;
  va_start(specifier, format);
  int calc = 0, end = 1;
  int iter_str = 0, iter_format = 0;

  int assign_suppr = 0;
  long width = 0;

  for (; *(str + iter_str) && *(format + iter_format) && end;
       iter_str++, iter_format++) {
    if (format[iter_format] == '%' && format[iter_format + 1] == '%') {
      iter_format++;
    } else if (s21_str_split(str[iter_str]) &&
               !s21_char_check(format, iter_format + 1)) {
      iter_format--;
    } else if (s21_str_split(format[iter_format])) {
      iter_str--;
    } else if (format[iter_format] == '%') {
      // assignment suppersion
      if (format[iter_format + 1] == '*') {
        assign_suppr = 1;
        iter_format++;
      }
      // width
      if (format[iter_format + 1] >= '1' && format[iter_format + 1] <= '9') {
        char *endptr = S21_NULL;
        width = s21_strtol((char *)(format + iter_format + 1), &endptr, 10);
        iter_format += endptr - (format + iter_format) - 1;
      }

      while (format[iter_format + 1] == '0') iter_format++;

      // length
      char len_format = format[iter_format + 1];
      if (len_format == 'l' || len_format == 'h' || len_format == 'L')
        iter_format++;

      s21_format_check(format[iter_format + 1], &specifier, str, &iter_str,
                       &calc, &end, format, &iter_format, len_format,
                       assign_suppr, width);
      iter_format++;

      if (end && !assign_suppr) calc++;
    } else if (str[iter_str] == format[iter_format]) {
      continue;
    } else {
      end = 0;
    }
    assign_suppr = 0;
    width = 0;
  }

  if (*(str + iter_str) == '\0' && *(format + iter_format))
    s21_n_spec_at_the_end(format, &iter_format, &specifier, str, iter_str,
                          &calc, &end);

  va_end(specifier);
  return calc;
}
