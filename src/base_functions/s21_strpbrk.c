#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  if (!str1 || !str2) return S21_NULL;

  char *res = S21_NULL;
  s21_size_t str1_len = s21_strlen(str1);
  int exit = 0;

  for (s21_size_t i = 0; i < str1_len && exit != 1; i++) {
    if (s21_strchr(str2, str1[i]) != S21_NULL) {
      res = (char *)str1 + i;
      exit = 1;
    }
  }
  return res;
}