#include "../s21_string.h"

long int s21_atol(char *str) {
  long int result = 0;
  int sign = 1;
  int i = 0;

  while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') i++;

  if (str[i] == '-') {
    sign = -1;
    i++;
  } else if (str[i] == '+')
    i++;

  while (str[i] >= '0' && str[i] <= '9') {
    if (result > (LONG_MAX - (str[i] - '0')) / 10)
      return sign == 1 ? LONG_MAX : LONG_MIN;

    result = result * 10 + (str[i] - '0');
    i++;
  }

  result *= sign;

  return result;
}