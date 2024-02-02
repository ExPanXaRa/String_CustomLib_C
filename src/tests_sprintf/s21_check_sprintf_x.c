#include "../check_s21_sprintf.h"

START_TEST(test_sprintf_x_basic) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned int value = 0x1a3b;

  int count_result = s21_sprintf(buffer, "%x", value);
  int count_expected = sprintf(expected, "%x", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_x_h) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned short value = 0x1a3b;

  int count_result = s21_sprintf(buffer, "%hx", value);
  int count_expected = sprintf(expected, "%hx", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_x_l) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned long value = 0x1a3b;

  int count_result = s21_sprintf(buffer, "%lx", value);
  int count_expected = sprintf(expected, "%lx", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_X) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned int value = 0x1a3b;

  int count_result = s21_sprintf(buffer, "%X", value);
  int count_expected = sprintf(expected, "%X", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_x_zero) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned int value = 0;

  int count_result = s21_sprintf(buffer, "%x", value);
  int count_expected = sprintf(expected, "%x", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_x_width) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned int value = 123;

  int count_result = s21_sprintf(buffer, "%30x", value);
  int count_expected = sprintf(expected, "%30x", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_x_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned int value = 123;

  int count_result = s21_sprintf(buffer, "%.4x", value);
  int count_expected = sprintf(expected, "%.4x", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_x_width_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned int value = 123;

  int count_result = s21_sprintf(buffer, "%30.4x", value);
  int count_expected = sprintf(expected, "%30.4x", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_x_width_precision_flags_minus) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned int value = 123;

  int count_result = s21_sprintf(buffer, "%-30.4x", value);
  int count_expected = sprintf(expected, "%-30.4x", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_x_width_precision_flags_minus_hash) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned int value = 123;

  int count_result = s21_sprintf(buffer, "%#-30.4x", value);
  int count_expected = sprintf(expected, "%#-30.4x", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_x_width_flags_zero) {
  char buffer[100] = {0};
  char expected[100] = {0};
  unsigned int value = 123;

  int count_result = s21_sprintf(buffer, "%030x", value);
  int count_expected = sprintf(expected, "%030x", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

Suite *s21_sprintf_x_suite(void) {
  Suite *s = suite_create("s21_sprintf_x");

  TCase *tc_core = tcase_create("SPRINTF");
  tcase_add_test(tc_core, test_sprintf_x_basic);
  tcase_add_test(tc_core, test_sprintf_x_h);
  tcase_add_test(tc_core, test_sprintf_x_l);
  tcase_add_test(tc_core, test_sprintf_X);
  tcase_add_test(tc_core, test_sprintf_x_zero);
  tcase_add_test(tc_core, test_sprintf_x_width);
  tcase_add_test(tc_core, test_sprintf_x_precision);
  tcase_add_test(tc_core, test_sprintf_x_width_precision);
  tcase_add_test(tc_core, test_sprintf_x_width_precision_flags_minus);
  tcase_add_test(tc_core, test_sprintf_x_width_precision_flags_minus_hash);
  tcase_add_test(tc_core, test_sprintf_x_width_flags_zero);

  suite_add_tcase(s, tc_core);
  return s;
}