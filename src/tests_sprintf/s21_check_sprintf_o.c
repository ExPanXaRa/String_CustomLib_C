#include "../check_s21_sprintf.h"

START_TEST(test_sprintf_o_basic) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned int value = 12345;

  int count_result = s21_sprintf(buffer, "%o", value);
  int count_expected = sprintf(expected, "%o", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_o_flags_zero) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned int value = 54321;

  int count_result = s21_sprintf(buffer, "%010o", value);
  int count_expected = sprintf(expected, "%010o", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_o_flags_hash) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned int value = 9876;

  int count_result = s21_sprintf(buffer, "%#o", value);
  int count_expected = sprintf(expected, "%#o", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_o_negative) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int value = -1234;

  int count_result = s21_sprintf(buffer, "%o", value);
  int count_expected = sprintf(expected, "%o", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_o_width_flags_hash_zero) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned int value = 123;

  int count_result = s21_sprintf(buffer, "%#010o", value);
  int count_expected = sprintf(expected, "%#010o", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_o_negative_with_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int value = -9876;

  int count_result = s21_sprintf(buffer, "%.4o", value);
  int count_expected = sprintf(expected, "%.4o", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_o_zero_with_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int value = 0;

  int count_result = s21_sprintf(buffer, "%.3o", value);
  int count_expected = sprintf(expected, "%.3o", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_o_invalid_flags) {
  char buffer[100] = {0};
  char expected[100] = {0};
  int value = 132;

  int count_result = s21_sprintf(buffer, "% +-#010.4o", value);
  int count_expected = sprintf(expected, "%-#10.4o", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

Suite *s21_sprintf_o_suite(void) {
  Suite *s = suite_create("s21_sprintf_o");

  TCase *tc_core = tcase_create("SPRINTF");
  tcase_add_test(tc_core, test_sprintf_o_basic);
  tcase_add_test(tc_core, test_sprintf_o_flags_zero);
  tcase_add_test(tc_core, test_sprintf_o_flags_hash);
  tcase_add_test(tc_core, test_sprintf_o_negative);
  tcase_add_test(tc_core, test_sprintf_o_width_flags_hash_zero);
  tcase_add_test(tc_core, test_sprintf_o_negative_with_precision);
  tcase_add_test(tc_core, test_sprintf_o_zero_with_precision);
  tcase_add_test(tc_core, test_sprintf_o_invalid_flags);

  suite_add_tcase(s, tc_core);
  return s;
}