#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  if (!str) return S21_NULL;

  char *res = S21_NULL;
  s21_size_t len = s21_strlen(str);
  if (c == '\0') {
    res = (char *)str + len;
  } else {
    for (s21_size_t i = 0; i < len; i++) {
      if (*(str + i) == c) {
        res = (char *)str + i;
      }
    }
  }

  return res;
}
