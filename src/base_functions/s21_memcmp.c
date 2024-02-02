#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  if (!str1 || !str2) return NULL_STR_ERROR;

  int res = 0;
  int exit = 0;

  for (s21_size_t i = 0; i < n && exit != 1; i++) {
    char cur1 = *((char *)str1 + i);
    char cur2 = *((char *)str2 + i);

    if (cur1 != cur2) {
      res = (cur1 > cur2) ? 1 : -1;
      exit = 1;
    }
  }

  return res;
}