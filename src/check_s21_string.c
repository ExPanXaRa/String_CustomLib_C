#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "check_s21_sprintf.h"
#include "check_s21_sscanf.h"
#include "s21_string.h"

#define SUITE_QUANT 41

START_TEST(test_s21_memchr_char_found) {
  char str[] = "Hel\0lo, World!";

  char *result = (char *)s21_memchr(str, 'o', sizeof(str));
  char *expected = (char *)memchr(str, 'o', sizeof(str));

  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_char_not_found) {
  char str[] = "Hello, World!";

  char *result = (char *)s21_memchr(str, 'z', sizeof(str));
  char *expected = (char *)memchr(str, 'z', sizeof(str));

  ck_assert(result == S21_NULL && expected == NULL);
  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

START_TEST(test_s21_memchr_zero_length) {
  char str[] = "Hello, World!";

  char *result = (char *)s21_memchr(str, 'o', 0);
  char *expected = (char *)memchr(str, 'o', 0);

  ck_assert(result == S21_NULL && expected == NULL);
  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

START_TEST(test_s21_memchr_null_str) {
  char str[] = "\0";

  char *result = (char *)s21_memchr(str, 'o', 1);
  char *expected = (char *)memchr(str, 'o', 1);

  ck_assert(result == S21_NULL && expected == NULL);
  ck_assert_ptr_eq(result, S21_NULL);
}
END_TEST

Suite *s21_memchr_suite(void) {
  Suite *s = suite_create("s21_memchr");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_memchr_char_found);
  tcase_add_test(tc_core, test_s21_memchr_char_not_found);
  tcase_add_test(tc_core, test_s21_memchr_zero_length);
  tcase_add_test(tc_core, test_s21_memchr_null_str);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_memcmp_equal) {
  const char *s1 = "abc";
  const char *s2 = "abc";

  int result = s21_memcmp(s1, s2, 3);
  int expected = memcmp(s1, s2, 3);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memcmp_greater) {
  const char *s1 = "abcd";
  const char *s2 = "abc";

  int result = s21_memcmp(s1, s2, 4);
  int expected = memcmp(s1, s2, 4);

  ck_assert(result > 0 && expected > 0);
}
END_TEST

START_TEST(test_s21_memcmp_smaller) {
  const char *s1 = "abc";
  const char *s2 = "abcd";

  int result = s21_memcmp(s1, s2, 4);
  int expected = memcmp(s1, s2, 4);

  ck_assert(result < 0 && expected < 0);
}
END_TEST

START_TEST(test_s21_memcmp_null_str1) {
  const char *s1 = "\0";
  const char *s2 = "abcd";

  int result = s21_memcmp(s1, s2, 4);
  int expected = memcmp(s1, s2, 4);

  ck_assert(result < 0 && expected < 0);
}
END_TEST

START_TEST(test_s21_memcmp_null_str2) {
  const char *s1 = "abc";
  const char *s2 = "\0";

  int result = s21_memcmp(s1, s2, 4);
  int expected = memcmp(s1, s2, 4);

  ck_assert(result > 0 && expected > 0);
}
END_TEST

Suite *s21_memcmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_memcmp");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memcmp_equal);
  tcase_add_test(tc_core, test_s21_memcmp_greater);
  tcase_add_test(tc_core, test_s21_memcmp_smaller);
  tcase_add_test(tc_core, test_s21_memcmp_null_str1);
  tcase_add_test(tc_core, test_s21_memcmp_null_str2);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_memcpy_basic) {
  char s21_dest[10] = {0};
  char dest[10] = {0};
  const char *src = "example";

  s21_memcpy(s21_dest, src, 9);
  memcpy(dest, src, 9);

  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(test_s21_memcpy_zero_length) {
  char s21_dest[10] = "original";
  char dest[10] = "original";
  const char *src = "new";

  s21_memcpy(s21_dest, src, 0);
  memcpy(dest, src, 0);

  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(test_s21_memcpy_partial_copy) {
  char s21_dest[10] = "original";
  char dest[10] = "original";
  const char *src = "new";

  s21_memcpy(s21_dest, src, 2);
  memcpy(dest, src, 2);

  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(test_s21_memcpy_null_byte_src) {
  char s21_dest[10] = {0};
  char dest[10] = {0};
  const char *src = "\0";

  s21_memcpy(s21_dest, src, 9);
  memcpy(dest, src, 9);

  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_memcpy");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memcpy_basic);
  tcase_add_test(tc_core, test_s21_memcpy_zero_length);
  tcase_add_test(tc_core, test_s21_memcpy_partial_copy);
  tcase_add_test(tc_core, test_s21_memcpy_null_byte_src);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_memset_basic) {
  char s21_buffer[10] = {0};
  char buffer[10] = {0};

  s21_memset(s21_buffer, 'a', 5);
  memset(buffer, 'a', 5);
  ck_assert_mem_eq(s21_buffer, buffer, 10);
}
END_TEST

START_TEST(test_s21_memset_zero_length) {
  char s21_buffer[10] = "original";
  char buffer[10] = "original";

  s21_memset(s21_buffer, 'a', 0);

  ck_assert_str_eq(buffer, s21_buffer);
}
END_TEST

START_TEST(test_s21_memset_full_set) {
  char buffer[10] = {0};
  char s21_buffer[10] = {0};

  s21_memset(s21_buffer, 'b', sizeof(s21_buffer));
  memset(buffer, 'b', sizeof(buffer));

  ck_assert_mem_eq(buffer, s21_buffer, 10);
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_memset");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memset_basic);
  tcase_add_test(tc_core, test_s21_memset_zero_length);
  tcase_add_test(tc_core, test_s21_memset_full_set);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_strncat_full_concatenation) {
  char s21_dest[100] = "Hello, ";
  char dest[100] = "Hello, ";

  const char *src = "World!";
  strncat(dest, src, strlen(src));
  s21_strncat(s21_dest, src, strlen(src));

  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(test_s21_strncat_partial_concatenation) {
  char s21_dest[100] = "Hello, ";
  char dest[100] = "Hello, ";
  const char *src = "World!";

  strncat(dest, src, 3);
  s21_strncat(s21_dest, src, 3);

  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(test_s21_strncat_null_byte) {
  char s21_dest[100] = "Hello, ";
  char dest[100] = "Hello, ";
  const char *src = "Wo\0rld!";

  strncat(dest, src, 3);
  s21_strncat(s21_dest, src, 3);

  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(test_s21_strncat_zero_n) {
  char s21_dest[100] = "Hello, ";
  char dest[100] = "Hello, ";
  const char *src = "Wo\0rld!";

  strncat(dest, src, 0);
  s21_strncat(s21_dest, src, 0);

  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

Suite *s21_strncat_suite(void) {
  Suite *s = suite_create("s21_strncat");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncat_full_concatenation);
  tcase_add_test(tc_core, test_s21_strncat_partial_concatenation);
  tcase_add_test(tc_core, test_s21_strncat_null_byte);
  tcase_add_test(tc_core, test_s21_strncat_zero_n);

  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_strchr_find_char) {
  const char *str = "Hello, World!";
  char *original_res = strchr(str, 'W');
  char *s21_res = s21_strchr(str, 'W');
  ck_assert_ptr_eq(s21_res, original_res);
}
END_TEST

START_TEST(test_s21_strchr_char_not_found) {
  const char *str = "Hello, World!";
  char *original_res = strchr(str, 'Z');
  char *s21_res = s21_strchr(str, 'Z');
  ck_assert_ptr_eq(s21_res, original_res);
}
END_TEST

START_TEST(test_s21_strchr_char_is_null) {
  const char *str = "Hello, World!";
  char *original_res = strchr(str, '\0');
  char *s21_res = s21_strchr(str, '\0');
  ck_assert_ptr_eq(s21_res, original_res);
}
END_TEST

START_TEST(test_s21_strchr_null_byte) {
  const char *str = "Hell\0o, World!";
  char *original_res = strchr(str, 'd');
  char *s21_res = s21_strchr(str, 'd');
  ck_assert_ptr_eq(s21_res, original_res);
}
END_TEST

Suite *s21_strchr_suite(void) {
  Suite *s = suite_create("s21_strchr");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strchr_find_char);
  tcase_add_test(tc_core, test_s21_strchr_char_not_found);
  tcase_add_test(tc_core, test_s21_strchr_char_is_null);
  tcase_add_test(tc_core, test_s21_strchr_null_byte);

  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_strncmp_equal_str) {
  const char *str1 = "Hello, World!";
  const char *str2 = "Hello, World!";
  int res_original = strncmp(str1, str2, 13);
  int res_s21 = s21_strncmp(str1, str2, 13);
  ck_assert_int_eq(res_s21, res_original);
}
END_TEST

START_TEST(test_s21_strncmp_diff_str_lt_zero) {
  const char *str1 = "Hello, World!";
  const char *str2 = "Hello, Wxrld!";
  int res_original = strncmp(str1, str2, 13);
  int res_s21 = s21_strncmp(str1, str2, 13);
  ck_assert_int_lt(res_s21, 0);
  ck_assert_int_lt(res_original, 0);
}
END_TEST

START_TEST(test_s21_strncmp_diff_str_gt_zero) {
  const char *str1 = "Hello, Wxrld!";
  const char *str2 = "Hello, World!";
  int res_original = strncmp(str1, str2, 13);
  int res_s21 = s21_strncmp(str1, str2, 13);
  ck_assert_int_gt(res_s21, 0);
  ck_assert_int_gt(res_original, 0);
}
END_TEST

START_TEST(test_s21_strncmp_partial_cmp) {
  const char *str1 = "Hello, World!";
  const char *str2 = "Hello, Wx!ad!";
  int res_original = strncmp(str1, str2, 7);
  int res_s21 = s21_strncmp(str1, str2, 7);
  ck_assert_int_eq(res_s21, res_original);
}
END_TEST

START_TEST(test_s21_strncmp_partial_cmp_str2_lt_str1) {
  const char *str1 = "Hello, World!";
  const char *str2 = "Hello,";
  int res_original = strncmp(str1, str2, 10);
  int res_s21 = s21_strncmp(str1, str2, 10);
  ck_assert_int_gt(res_s21, 0);
  ck_assert_int_gt(res_original, 0);
}
END_TEST

START_TEST(test_s21_strncmp_null_byte) {
  const char *str1 = "Hell\0o, World!";
  const char *str2 = "Hell\0a, Wx!ad!";
  int res_original = strncmp(str1, str2, 7);
  int res_s21 = s21_strncmp(str1, str2, 7);
  ck_assert_int_eq(res_s21, res_original);
}
END_TEST

Suite *s21_strncmp_suite(void) {
  Suite *s = suite_create("s21_strncmp");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncmp_equal_str);
  tcase_add_test(tc_core, test_s21_strncmp_diff_str_lt_zero);
  tcase_add_test(tc_core, test_s21_strncmp_diff_str_gt_zero);
  tcase_add_test(tc_core, test_s21_strncmp_partial_cmp);
  tcase_add_test(tc_core, test_s21_strncmp_partial_cmp_str2_lt_str1);
  tcase_add_test(tc_core, test_s21_strncmp_null_byte);

  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_strncpy_basic) {
  char s21_dest[10] = {0};
  char dest[10] = {0};
  const char *src = "example";

  s21_strncpy(s21_dest, src, 8);
  strncpy(dest, src, 8);

  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(test_s21_strncpy_src_lt_n) {
  char s21_dest[10] = {0};
  char dest[10] = {0};
  const char *src = "example";

  s21_strncpy(s21_dest, src, 10);
  strncpy(dest, src, 10);

  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(test_s21_strncpy_zero_length) {
  char s21_dest[10] = "original";
  char dest[10] = "original";
  const char *src = "new";

  s21_strncpy(s21_dest, src, 0);

  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(test_s21_strncpy_partial_copy) {
  char s21_dest[10] = "original";
  char dest[10] = "original";
  const char *src = "new";

  s21_strncpy(s21_dest, src, 2);
  strncpy(dest, src, 2);

  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(test_s21_strncpy_null_byte) {
  char s21_dest[10] = {0};
  char dest[10] = {0};
  const char *src = "exa\0mple";

  s21_strncpy(s21_dest, src, 10);
  strncpy(dest, src, 10);

  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

Suite *s21_strncpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strncpy");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncpy_basic);
  tcase_add_test(tc_core, test_s21_strncpy_src_lt_n);
  tcase_add_test(tc_core, test_s21_strncpy_zero_length);
  tcase_add_test(tc_core, test_s21_strncpy_partial_copy);
  tcase_add_test(tc_core, test_s21_strncpy_null_byte);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_strcspn_normal) {
  char *str1 = "Hello, World!";
  char *str2 = "zxvc";

  s21_size_t s21_res = s21_strcspn(str1, str2);
  size_t res_original = strcspn(str1, str2);

  ck_assert_int_eq(s21_res, res_original);
}
END_TEST

START_TEST(test_s21_strcspn_equal_strs) {
  char *str1 = "Hello, World!";
  char *str2 = "Hello, World!";

  s21_size_t s21_res = s21_strcspn(str1, str2);
  size_t res_original = strcspn(str1, str2);

  ck_assert_int_eq(s21_res, res_original);
}
END_TEST

START_TEST(test_s21_strcspn_empty_strings) {
  char *str1 = "";
  char *str2 = "";

  s21_size_t s21_res = s21_strcspn(str1, str2);
  size_t res_original = strcspn(str1, str2);

  ck_assert_int_eq(s21_res, res_original);
}
END_TEST

START_TEST(test_s21_strcspn_str1_null_byte) {
  char *str1 = "Hel\0lo, world!";
  char *str2 = ",";

  s21_size_t s21_res = s21_strcspn(str1, str2);
  size_t res_original = strcspn(str1, str2);

  ck_assert_int_eq(s21_res, res_original);
}
END_TEST

START_TEST(test_s21_strcspn_str2_null_byte) {
  char *str1 = "Hello, world!";
  char *str2 = "\0";

  s21_size_t s21_res = s21_strcspn(str1, str2);
  size_t res_original = strcspn(str1, str2);

  ck_assert_int_eq(s21_res, res_original);
}
END_TEST

Suite *s21_strcspn_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strcspn");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strcspn_normal);
  tcase_add_test(tc_core, test_s21_strcspn_equal_strs);
  tcase_add_test(tc_core, test_s21_strcspn_empty_strings);
  tcase_add_test(tc_core, test_s21_strcspn_str1_null_byte);
  tcase_add_test(tc_core, test_s21_strcspn_str2_null_byte);

  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_positive_errnum) {
  int errnum = 5;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test_zero_errnum) {
  int errnum = 0;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test_large_errnum) {
  int errnum = 10000;
  char expect[128];
  sprintf(expect, "ERROR %d", errnum);
  ck_assert_str_eq(s21_strerror(errnum), expect);
}
END_TEST

Suite *s21_strerror_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strerror");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_positive_errnum);
  tcase_add_test(tc_core, test_zero_errnum);
  tcase_add_test(tc_core, test_large_errnum);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_strlen_normal) {
  char *str = "Hello, World!";

  s21_size_t s21_res = s21_strlen(str);
  size_t res_original = strlen(str);

  ck_assert_int_eq(s21_res, res_original);
}
END_TEST

START_TEST(test_s21_strlen_empty_str) {
  char *str = "";

  s21_size_t s21_res = s21_strlen(str);
  size_t res_original = strlen(str);

  ck_assert_int_eq(s21_res, res_original);
}
END_TEST

START_TEST(test_s21_strlen_null_byte) {
  char *str = "Hel\0lo, World!";

  s21_size_t s21_res = s21_strlen(str);
  size_t res_original = strlen(str);

  ck_assert_int_eq(s21_res, res_original);
}
END_TEST

Suite *s21_strlen_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strlen");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strlen_normal);
  tcase_add_test(tc_core, test_s21_strlen_empty_str);
  tcase_add_test(tc_core, test_s21_strlen_null_byte);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_strpbrk_normal) {
  char *str1 = "Hello, World!";
  char *str2 = "rld";

  char *s21_res = s21_strpbrk(str1, str2);
  char *res_original = strpbrk(str1, str2);

  ck_assert_str_eq(s21_res, res_original);
}
END_TEST

START_TEST(test_s21_strpbrk_no_match) {
  char *str1 = "Hello, World!";
  char *str2 = "jzf";

  char *s21_res = s21_strpbrk(str1, str2);
  char *res_original = strpbrk(str1, str2);

  ck_assert_ptr_eq(s21_res, res_original);
}
END_TEST

START_TEST(test_s21_strpbrk_empty_str2) {
  char *str1 = "Hello, World!";
  char *str2 = "";

  char *s21_res = s21_strpbrk(str1, str2);
  char *res_original = strpbrk(str1, str2);

  ck_assert_ptr_eq(s21_res, res_original);
}
END_TEST

START_TEST(test_s21_strpbrk_null_byte) {
  char *str1 = "Hel\0lo, World!";
  char *str2 = "Word!";

  char *s21_res = s21_strpbrk(str1, str2);
  char *res_original = strpbrk(str1, str2);

  ck_assert_ptr_eq(s21_res, res_original);
}
END_TEST

Suite *s21_strpbrk_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strpbrk");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strpbrk_normal);
  tcase_add_test(tc_core, test_s21_strpbrk_no_match);
  tcase_add_test(tc_core, test_s21_strpbrk_empty_str2);
  tcase_add_test(tc_core, test_s21_strpbrk_null_byte);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_strrchr_find_char) {
  const char *str = "Hello, World!";
  char *original_res = strrchr(str, 'W');
  char *s21_res = s21_strrchr(str, 'W');
  ck_assert_ptr_eq(s21_res, original_res);
}
END_TEST

START_TEST(test_s21_strrchr_char_not_found) {
  const char *str = "Hello, World!";
  char *original_res = strrchr(str, 'Z');
  char *s21_res = s21_strrchr(str, 'Z');
  ck_assert_ptr_eq(s21_res, original_res);
}
END_TEST

START_TEST(test_s21_strrchr_char_is_null) {
  const char *str = "Hello, World!";
  char *original_res = strrchr(str, '\0');
  char *s21_res = s21_strrchr(str, '\0');
  ck_assert_ptr_eq(s21_res, original_res);
}
END_TEST

START_TEST(test_s21_strrchr_null_byte) {
  const char *str = "Hell\0o, World!";
  char *original_res = strrchr(str, 'd');
  char *s21_res = s21_strrchr(str, 'd');
  ck_assert_ptr_eq(s21_res, original_res);
}
END_TEST

Suite *s21_strrchr_suite(void) {
  Suite *s = suite_create("s21_strrchr");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strrchr_find_char);
  tcase_add_test(tc_core, test_s21_strrchr_char_not_found);
  tcase_add_test(tc_core, test_s21_strrchr_char_is_null);
  tcase_add_test(tc_core, test_s21_strrchr_null_byte);

  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_strstr_normal) {
  const char *haystack = "Hello, World!";
  const char *needle = "lo, World!";

  char *s21_res = s21_strstr(haystack, needle);
  char *original_res = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_res, original_res);
}
END_TEST

START_TEST(test_s21_strstr_no_match) {
  const char *haystack = "Hello, world!";
  const char *needle = "abcd";

  char *s21_res = s21_strstr(haystack, needle);
  char *original_res = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_res, original_res);
}
END_TEST

START_TEST(test_s21_strstr_haystack_lt_needle) {
  const char *haystack = "abcd";
  const char *needle = "Hello, World!";

  char *s21_res = s21_strstr(haystack, needle);
  char *original_res = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_res, original_res);
}
END_TEST

START_TEST(test_s21_strstr_null_needle) {
  const char *haystack = "Hello\0, World!";
  const char *needle = "\0";

  char *s21_res = s21_strstr(haystack, needle);
  char *original_res = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_res, original_res);
}
END_TEST

START_TEST(test_s21_strstr_null_byte) {
  const char *haystack = "Hello\0, World!";
  const char *needle = "Wor";

  char *s21_res = s21_strstr(haystack, needle);
  char *original_res = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_res, original_res);
}
END_TEST

Suite *s21_strstr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strstr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strstr_normal);
  tcase_add_test(tc_core, test_s21_strstr_no_match);
  tcase_add_test(tc_core, test_s21_strstr_haystack_lt_needle);
  tcase_add_test(tc_core, test_s21_strstr_null_needle);
  tcase_add_test(tc_core, test_s21_strstr_null_byte);

  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_s21_strtok_normal) {
  const char delimiters[] = " ,.-";
  char str[] = "The..quick-brown,fox Hi";
  char str2[] = "The..quick-brown,fox Hi";

  char *token = {0}, *token2 = {0};

  token = s21_strtok(str, delimiters);
  token2 = strtok(str2, delimiters);

  while (token != S21_NULL || token2 != NULL) {
    ck_assert_str_eq(token, token2);
    token = s21_strtok(S21_NULL, delimiters);
    token2 = strtok(NULL, delimiters);
  }
}
END_TEST

START_TEST(test_s21_strtok_no_match_delim) {
  const char delimiters[] = " ";
  char str[] = "The_quick_brown_fox_Hi_He";
  char str2[] = "The_quick_brown_fox_Hi_He";

  char *token = {0}, *token2 = {0};

  token = s21_strtok(str, delimiters);
  token2 = strtok(str2, delimiters);

  while (token != S21_NULL || token2 != NULL) {
    ck_assert_str_eq(token, token2);
    token = s21_strtok(S21_NULL, delimiters);
    token2 = strtok(NULL, delimiters);
  }
}
END_TEST

START_TEST(test_s21_strtok_null_byte_str) {
  const char delimiters[] = " ";
  char str[] = "The quic\0\0k brown fox Hi";
  char str2[] = "The quic\0\0k brown fox Hi";

  char *token = {0}, *token2 = {0};

  token = s21_strtok(str, delimiters);
  token2 = strtok(str2, delimiters);

  while (token != S21_NULL || token2 != NULL) {
    ck_assert_str_eq(token, token2);
    token = s21_strtok(S21_NULL, delimiters);
    token2 = strtok(NULL, delimiters);
  }
}
END_TEST

START_TEST(test_s21_strtok_null_byte_delim) {
  const char delimiters[] = "\0";
  char str[] = "The.quick-brown,fox Hi";
  char str2[] = "The.quick-brown,fox Hi";

  char *token = {0}, *token2 = {0};

  token = s21_strtok(str, delimiters);
  token2 = strtok(str2, delimiters);

  while (token != S21_NULL || token2 != NULL) {
    ck_assert_str_eq(token, token2);
    token = s21_strtok(S21_NULL, delimiters);
    token2 = strtok(NULL, delimiters);
  }
}
END_TEST

Suite *s21_strtok_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strtok");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strtok_normal);
  tcase_add_test(tc_core, test_s21_strtok_no_match_delim);
  tcase_add_test(tc_core, test_s21_strtok_null_byte_str);
  tcase_add_test(tc_core, test_s21_strtok_null_byte_delim);
  suite_add_tcase(s, tc_core);

  return s;
}

// Тест s21_to_upper
START_TEST(test_s21_to_upper) {
  char *test_str = s21_to_upper("aa");
  ck_assert_str_eq(test_str, "AA");
  free(test_str);

  test_str = s21_to_upper("a11a");
  ck_assert_str_eq(test_str, "A11A");
  free(test_str);

  test_str = s21_to_upper("AA");
  ck_assert_str_eq(test_str, "AA");
  free(test_str);

  test_str = s21_to_upper("");
  ck_assert_str_eq(test_str, "");
  free(test_str);

  test_str = s21_to_upper(S21_NULL);
  ck_assert_ptr_null(test_str);
}
END_TEST;

Suite *s21_to_upper_suite(void) {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_to_upper);

  suite_add_tcase(s, tc_core);

  return s;
}

// Тест s21_to_lower
START_TEST(test_s21_to_lower) {
  char *test_str = s21_to_lower("AA");
  ck_assert_str_eq(test_str, "aa");
  free(test_str);

  test_str = s21_to_lower("A11A");
  ck_assert_str_eq(test_str, "a11a");
  free(test_str);

  test_str = s21_to_lower("aa");
  ck_assert_str_eq(test_str, "aa");
  free(test_str);

  test_str = s21_to_lower("");
  ck_assert_str_eq(test_str, "");
  free(test_str);

  test_str = s21_to_lower(S21_NULL);
  ck_assert_ptr_null(test_str);
}
END_TEST;

Suite *s21_to_lower_suite(void) {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_to_lower);

  suite_add_tcase(s, tc_core);

  return s;
}

// Тест s21_insert
START_TEST(test_s21_insert) {
  char *test_str = s21_insert("123", "77", 0);
  ck_assert_str_eq(test_str, "77123");
  free(test_str);

  test_str = s21_insert("123", "77", 1);
  ck_assert_str_eq(test_str, "17723");
  free(test_str);

  test_str = s21_insert("123", "77", 2);
  ck_assert_str_eq(test_str, "12773");
  free(test_str);

  test_str = s21_insert("123", "77", 3);
  ck_assert_str_eq(test_str, "12377");
  free(test_str);

  test_str = s21_insert("123", "77", -1);
  ck_assert_ptr_null(test_str);

  test_str = s21_insert("123", "77", 8);
  ck_assert_ptr_null(test_str);

  test_str = s21_insert(S21_NULL, "77", 1);
  ck_assert_ptr_null(test_str);

  test_str = s21_insert("123", S21_NULL, 2);
  ck_assert_ptr_null(test_str);

  test_str = s21_insert(S21_NULL, S21_NULL, 2);
  ck_assert_ptr_null(test_str);
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *s = suite_create("s21_insert");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_insert);

  suite_add_tcase(s, tc_core);

  return s;
}

// Тест s21_trim
START_TEST(test_s21_trim) {
  char *test_str = s21_trim("123", "1");
  ck_assert_str_eq(test_str, "23");
  free(test_str);

  test_str = s21_trim("231", "1");
  ck_assert_str_eq(test_str, "23");
  free(test_str);

  test_str = s21_trim("1231", "1");
  ck_assert_str_eq(test_str, "23");
  free(test_str);

  test_str = s21_trim("12321", "12");
  ck_assert_str_eq(test_str, "3");
  free(test_str);

  test_str = s21_trim("12321", "47");
  ck_assert_str_eq(test_str, "12321");
  free(test_str);

  test_str = s21_trim("12321", "123");
  ck_assert(s21_strlen(test_str) == 0);
  free(test_str);

  test_str = s21_trim(S21_NULL, "1");
  ck_assert_ptr_null(test_str);

  test_str = s21_trim("123", S21_NULL);
  ck_assert_str_eq(test_str, "123");
  free(test_str);

  test_str = s21_trim(S21_NULL, S21_NULL);
  ck_assert_ptr_null(test_str);
}
Suite *s21_trim_suite(void) {
  Suite *s = suite_create("s21_trim");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_trim);

  suite_add_tcase(s, tc_core);
  return s;
}

int run_test_case(Suite *(*func)(void)) {
  Suite *s;
  SRunner *sr;
  int number_failed = 0;

  s = func();
  sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK); /* remove comment for valgrind */
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}

int main(void) {
  Suite *(*suites[SUITE_QUANT])(void) = {s21_memchr_suite,
                                         s21_memcmp_suite,
                                         s21_memcpy_suite,
                                         s21_memset_suite,
                                         s21_strncat_suite,
                                         s21_strchr_suite,
                                         s21_strncmp_suite,
                                         s21_strncpy_suite,
                                         s21_strcspn_suite,
                                         s21_strerror_suite,
                                         s21_strlen_suite,
                                         s21_strpbrk_suite,
                                         s21_strrchr_suite,
                                         s21_strstr_suite,
                                         s21_strtok_suite,
                                         s21_to_upper_suite,
                                         s21_to_lower_suite,
                                         s21_insert_suite,
                                         s21_trim_suite,
                                         s21_sscanf_d_format_suite,
                                         s21_sscanf_i_format_suite,
                                         s21_sscanf_u_format_suite,
                                         s21_sscanf_o_format_suite,
                                         s21_sscanf_x_format_suite,
                                         s21_sscanf_n_format_suite,
                                         s21_sscanf_s_format_suite,
                                         s21_sscanf_c_format_suite,
                                         s21_sscanf_e_format_suite,
                                         s21_sscanf_p_format_suite,
                                         s21_sprintf_c_suite,
                                         s21_sprintf_d_suite,
                                         s21_sprintf_i_suite,
                                         s21_sprintf_f_suite,
                                         s21_sprintf_g_suite,
                                         s21_sprintf_e_suite,
                                         s21_sprintf_u_suite,
                                         s21_sprintf_o_suite,
                                         s21_sprintf_x_suite,
                                         s21_sprintf_p_suite,
                                         s21_sprintf_s_suite,
                                         s21_sprintf_other_suite};

  for (int i = 0; i < SUITE_QUANT; i++) {
    if (suites[i] != S21_NULL) run_test_case(suites[i]);
  }
  return 0;
}
