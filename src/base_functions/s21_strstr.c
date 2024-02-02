#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (!haystack || !needle) return S21_NULL;

  char *res = S21_NULL;
  s21_size_t needle_l = s21_strlen(needle);
  s21_size_t haystack_l = s21_strlen(haystack);

  if (needle_l > haystack_l) {
    return res;
  }

  if (needle_l == 0) {
    return (char *)haystack;
  }

  s21_size_t j = 0;
  for (s21_size_t i = 0; i <= haystack_l - needle_l; i++) {
    for (; j < needle_l; j++) {
      if (haystack[i + j] != needle[j]) {
        break;
      }
    }
    if (j == needle_l) {
      res = (char *)haystack + i;
      break;
    }
  }

  return res;
}
