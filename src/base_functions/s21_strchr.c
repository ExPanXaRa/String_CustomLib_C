#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  if (!str) return S21_NULL;

  char *res = S21_NULL;
  s21_size_t len = s21_strlen(str);

  if (c == '\0') {
    res = (char *)str + len;
  } else {
    int ch_found = 0;
    for (s21_size_t i = 0; i < len && ch_found != 1; i++) {
      if (*(str + i) == c) {
        res = (char *)str + i;
        ch_found = 1;
      }
    }
  }

  return res;
}
