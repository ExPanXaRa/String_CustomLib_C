#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (!dest || !src) return S21_NULL;

  s21_size_t dest_len = s21_strlen(dest);
  for (s21_size_t i = 0; i < n; i++) {
    *(dest + i + dest_len) = *((char *)src + i);
  }

  return dest;
}