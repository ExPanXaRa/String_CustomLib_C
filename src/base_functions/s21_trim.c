#include <stdio.h>
#include <stdlib.h>

#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (!src) return S21_NULL;

  char *result = malloc(sizeof(char) * (s21_strlen(src) + 1));
  if (!result) return S21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(src); i++) result[i] = src[i];

  result[s21_strlen(src)] = '\0';

  if (!trim_chars) return result;

  s21_size_t src_len = s21_strlen(src);
  for (s21_size_t i = 0; i < s21_strlen(trim_chars); i++) {
    if (result[0] == trim_chars[i]) {
      for (s21_size_t j = 0; j < src_len; j++) result[j] = result[j + 1];
      i = 0;
      src_len--;
    }

    if (src_len >= 1 && result[src_len - 1] == trim_chars[i]) {
      result[src_len - 1] = '\0';
      i = -1;
      src_len--;
    }
  }

  return result;
}
