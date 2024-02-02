#include "../check_s21_sprintf.h"

START_TEST(test_sprintf_p_non_null) {
  char buffer[100];
  char expected[100];
  int* ptr = (int*)0x12345678;

  int count_result = s21_sprintf(buffer, "%p", ptr);
  int count_expected = sprintf(expected, "%p", ptr);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_p_width) {
  char buffer[100];
  char expected[100];
  int* ptr = (int*)0x12345678;

  int count_result = s21_sprintf(buffer, "%30p", ptr);
  int count_expected = sprintf(expected, "%30p", ptr);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_p_null) {
  char buffer[100];
  char expected[100];
  int* ptr = NULL;

  int count_result = s21_sprintf(buffer, "%p", ptr);
  int count_expected = sprintf(expected, "%p", ptr);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

Suite* s21_sprintf_p_suite(void) {
  Suite* s = suite_create("s21_sprintf_p");

  TCase* tc_core = tcase_create("SPRINTF");
  tcase_add_test(tc_core, test_sprintf_p_non_null);
  tcase_add_test(tc_core, test_sprintf_p_width);
  tcase_add_test(tc_core, test_sprintf_p_null);

  suite_add_tcase(s, tc_core);
  return s;
}