#include "../s21_string.h"

long int s21_strtol(char *str, char **endptr, int base) {
  long int result = 0;
  int sign = 1;
  int i = 0;
  int success = 0;

  while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') i++;

  if (str[i] == '-') {
    sign = -1;
    i++;
  } else if (str[i] == '+')
    i++;

  if (base == 0) {
    if (str[i] == '0') {
      success = 1;
      if (str[i + 1] == 'x' || str[i + 1] == 'X') {
        base = 16;
        i += 2;
        result = 0;
      } else {
        base = 8;
        i++;
      }
    } else
      base = 10;
  } else if (base == 16 && str[i] == '0' &&
             (str[i + 1] == 'x' || str[i + 1] == 'X')) {
    i += 2;
    result = 0;
    success = 1;
  }

  if (base != 16) {
    if ((base == 8 && !(str[i - 1] >= '0' && str[i - 1] <= '9')) ||
        (base == 10 && !(str[i] >= '0' && str[i] <= '9'))) {
      if (endptr != S21_NULL) *endptr = (char *)&str[0];

      return 0;
    }
  }

  while (1) {
    char current_char = str[i];
    if (base == 10) {
      if (current_char >= '0' && current_char <= '9') {
        success = 1;
        if (result > (LONG_MAX - (current_char - '0')) / base) {
          while ((current_char >= '0' && current_char <= '9') &&
                 current_char != '\0') {
            i++;
            current_char = str[i];
          }
          if (endptr != S21_NULL) *endptr = (char *)&str[i];
          return sign == 1 ? LONG_MAX : LONG_MIN;
        }

        result = result * base + (current_char - '0');
        i++;
      } else
        break;
    } else if (base == 8) {
      if ((current_char >= '0' && current_char <= '7') &&
          current_char != '\0') {
        success = 1;
        if (result > (LONG_MAX - (current_char - '0')) / base) {
          while (current_char >= '0' && current_char <= '7') {
            i++;
            current_char = str[i];
          }
          if (endptr != S21_NULL) *endptr = (char *)&str[i];
          return sign == 1 ? LONG_MAX : LONG_MIN;
        }

        result = result * base + (current_char - '0');
        i++;
      } else
        break;
    } else {
      if (current_char >= '0' && current_char <= '9') {
        success = 1;
        if (result > (LONG_MAX - (current_char - '0')) / base) {
          while (((current_char >= '0' && current_char <= '9') ||
                  (current_char >= 'a' && current_char <= 'f') ||
                  (current_char >= 'A' && current_char <= 'F')) &&
                 current_char != '\0') {
            i++;
            current_char = str[i];
          }
          if (endptr != S21_NULL) *endptr = (char *)&str[i];
          return sign == 1 ? LONG_MAX : LONG_MIN;
        }

        result = result * base + (current_char - '0');
        i++;
      } else if (current_char >= 'a' && current_char <= 'f') {
        success = 1;
        if (result > (LONG_MAX - (current_char - 'a' + 10)) / base) {
          while (((current_char >= '0' && current_char <= '9') ||
                  (current_char >= 'a' && current_char <= 'f') ||
                  (current_char >= 'A' && current_char <= 'F')) &&
                 current_char != '\0') {
            i++;
            current_char = str[i];
          }
          if (endptr != S21_NULL) *endptr = (char *)&str[i];
          return sign == 1 ? LONG_MAX : LONG_MIN;
        }

        result = result * base + (current_char - 'a' + 10);
        i++;
      } else if (current_char >= 'A' && current_char <= 'F') {
        success = 1;
        if (result > (LONG_MAX - (current_char - 'A' + 10)) / base) {
          while (((current_char >= '0' && current_char <= '9') ||
                  (current_char >= 'a' && current_char <= 'f') ||
                  (current_char >= 'A' && current_char <= 'F')) &&
                 current_char != '\0') {
            i++;
            current_char = str[i];
          }
          if (endptr != S21_NULL) *endptr = (char *)&str[i];
          return sign == 1 ? LONG_MAX : LONG_MIN;
        }

        result = result * base + (current_char - 'A' + 10);
        i++;
      } else
        break;
    }
  }

  result *= sign;

  if (success) {
    if (endptr != S21_NULL) *endptr = (char *)&str[i];
  } else {
    if (endptr != S21_NULL) *endptr = (char *)&str[0];
  }

  return result;
}