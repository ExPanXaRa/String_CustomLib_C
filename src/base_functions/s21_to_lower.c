#include <stdlib.h>

#include "../s21_string.h"

// После вызова функции чистить память
void *s21_to_lower(const char *str) {
  if (!str) return S21_NULL;

  s21_size_t size = 0;
  while (str[size] != '\0') size++;

  char *result = malloc(sizeof(char) * (size + 1));
  if (!result) return S21_NULL;

  for (s21_size_t i = 0; i < size; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z')
      result[i] = str[i] + 32;
    else
      result[i] = str[i];
  }
  result[size] = '\0';

  return result;
}
