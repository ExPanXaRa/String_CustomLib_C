#include "../s21_string.h"

long double s21_strtold(const char *str, char **endptr) {
  long double result = 0.0L;
  int i = 0;
  int sign = 1;
  int exponent_sign = 1;
  int has_fraction = 0;
  int has_exponent = 0;
  long double fraction_multiplier = 1.0L;
  int exponent = 0;
  int success = 0;

  while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') i++;

  if (str[i] == '-') {
    sign = -1;
    i++;
  } else if (str[i] == '+')
    i++;

  if (s21_strncmp(&str[i], "inf", 3) == 0 ||
      s21_strncmp(&str[i], "Inf", 3) == 0 ||
      s21_strncmp(&str[i], "INF", 3) == 0 ||
      s21_strncmp(&str[i], "iNf", 3) == 0 ||
      s21_strncmp(&str[i], "iNF", 3) == 0 ||
      s21_strncmp(&str[i], "InF", 3) == 0 ||
      s21_strncmp(&str[i], "INf", 3) == 0 ||
      s21_strncmp(&str[i], "inF", 3) == 0) {
    if (endptr != S21_NULL) *endptr = (char *)&str[i + 3];
    return sign == 1 ? INFINITY : -INFINITY;
  } else if (s21_strncmp(&str[i], "nan", 3) == 0 ||
             s21_strncmp(&str[i], "NAN", 3) == 0 ||
             s21_strncmp(&str[i], "nAn", 3) == 0 ||
             s21_strncmp(&str[i], "NAn", 3) == 0 ||
             s21_strncmp(&str[i], "naN", 3) == 0 ||
             s21_strncmp(&str[i], "NaN", 3) == 0 ||
             s21_strncmp(&str[i], "nAN", 3) == 0 ||
             s21_strncmp(&str[i], "Nan", 3) == 0) {
    if (endptr != S21_NULL) *endptr = (char *)&str[i + 3];
    return NAN;
  }

  while (1) {
    char current_char = str[i];

    if (current_char >= '0' && current_char <= '9') {
      success = 1;
      if (result > (DBL_MAX - (current_char - '0')) / 10.0L) {
        if (endptr != S21_NULL) {
          *endptr = (char *)&str[i];
        }
        return sign == 1 ? LDBL_MAX : -LDBL_MAX;
      }

      if (!has_exponent) result = result * 10.0L + (current_char - '0');

      if (has_exponent) exponent = exponent * 10.0L + (current_char - '0');

      if (has_fraction && !has_exponent) fraction_multiplier *= 0.1L;

      i++;
    } else if (current_char == '.' && !has_fraction) {
      has_fraction = 1;
      i++;
    } else if ((current_char == 'e' || current_char == 'E') && !has_exponent) {
      has_exponent = 1;
      i++;

      if (str[i] == '-') {
        exponent_sign = -1;
        i++;
      } else if (str[i] == '+')
        i++;
    } else
      break;
  }

  result *= sign;

  if (has_fraction) result = result * fraction_multiplier;

  if (has_exponent) {
    int j;
    long double exponent_multiplier = 1.0L;

    for (j = 0; j < exponent; j++) exponent_multiplier *= 10.0L;

    if (exponent_sign < 0) exponent_multiplier = 1.0L / exponent_multiplier;

    result = result * exponent_multiplier;
  }

  if (success) {
    if (endptr != S21_NULL) *endptr = (char *)&str[i];
  } else {
    if (endptr != S21_NULL) *endptr = (char *)&str[0];
  }

  return result;
}