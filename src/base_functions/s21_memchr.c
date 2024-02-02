#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  if (!str) return S21_NULL;

  char *res = S21_NULL;
  int ch_found = 0;
  for (s21_size_t i = 0; i < n && ch_found != 1; i++) {
    if (*((char *)str + i) == c) {
      res = (char *)str + i;
      ch_found = 1;
    }
  }
  return res;
}