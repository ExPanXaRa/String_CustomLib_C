#include "../s21_string.h"

int s21_isDelimiter(const char c, const char *delim) {
  int result = s21_strchr(delim, c) != S21_NULL ? 1 : 0;
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  char *start_of_token = S21_NULL;
  static char *next_token;

  if (str != S21_NULL) {
    next_token = str;
  }

  if (next_token != S21_NULL) {
    while (*next_token != '\0' && s21_isDelimiter(*next_token, delim)) {
      ++next_token;
    }

    if (*next_token != '\0') {
      start_of_token = next_token;

      while (*next_token != '\0' && !s21_isDelimiter(*next_token, delim)) {
        ++next_token;
      }

      if (*next_token != '\0') {
        *next_token = '\0';
        ++next_token;
      } else {
        next_token = S21_NULL;
      }
    } else {
      next_token = S21_NULL;
    }
  }

  return start_of_token;
}