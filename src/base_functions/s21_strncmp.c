#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  if (!str1 || !str2) return NULL_STR_ERROR;

  int res = 0;
  int exit = 0;

  for (s21_size_t i = 0; i < n && exit != 1; i++) {
    char cur1 = *(str1 + i);
    char cur2 = *(str2 + i);

    if (cur1 == '\0' && cur2 == '\0') {
      break;
    } else if (cur1 != cur2) {
      res = (cur1 > cur2) ? 1 : -1;
      exit = 1;
    }
  }

  return res;
}
