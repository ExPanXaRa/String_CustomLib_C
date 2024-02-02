#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  if (!str) return NULL_STR_ERROR;

  s21_size_t res = 0;
  while (str[res] != '\0') {
    res++;
  }
  return res;
}
