#include <stdio.h>
#include <stdlib.h>

#include "../s21_string.h"

// После вызова функции чистить память
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (!src || !str) return S21_NULL;

  s21_size_t src_size = 0;
  while (src[src_size] != '\0') src_size++;

  if (start_index > src_size) return S21_NULL;

  s21_size_t str_size = 0;
  while (str[str_size] != '\0') str_size++;

  char *result = malloc(sizeof(char) * (src_size + str_size + 1));
  if (!result) return S21_NULL;

  s21_size_t k = 0;
  for (s21_size_t i = 0; i <= src_size; i++) {
    if (i == start_index) {
      for (s21_size_t j = 0; j < str_size; j++) {
        result[k] = str[j];
        k++;
      }
      if (start_index == src_size) continue;
    }
    result[k] = src[i];
    k++;
  }
  result[src_size + str_size] = '\0';

  return result;
}