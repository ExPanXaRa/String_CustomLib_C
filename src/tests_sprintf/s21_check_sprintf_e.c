#include "../check_s21_sprintf.h"

START_TEST(test_sprintf_e) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double value = 123.456;

  int count_result = s21_sprintf(buffer, "%e", value);
  int count_expected = sprintf(expected, "%e", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_E) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double value = 123.456;

  int count_result = s21_sprintf(buffer, "%E", value);
  int count_expected = sprintf(expected, "%E", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_negative_e) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double value = -789.012;

  int count_result = s21_sprintf(buffer, "%e", value);
  int count_expected = sprintf(expected, "%e", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_zero_e) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double value = 0.0;

  int count_result = s21_sprintf(buffer, "%e", value);
  int count_expected = sprintf(expected, "%e", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_e_L_width) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%30Le", value);
  int count_expected = sprintf(expected, "%30Le", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_e_L_width_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%*Le", 30, value);
  int count_expected = sprintf(expected, "%*Le", 30, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_e_L_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%.10Le", value);
  int count_expected = sprintf(expected, "%.10Le", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_e_L_precision_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%.*Le", 10, value);
  int count_expected = sprintf(expected, "%.*Le", 10, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_e_L_width_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%30.10Le", value);
  int count_expected = sprintf(expected, "%30.10Le", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_e_L_width_precision_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%*.*Le", 30, 10, value);
  int count_expected = sprintf(expected, "%*.*Le", 30, 10, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_e_L_width_precision_asterix_flags_plus_minus) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%+-*.*Le", 30, 10, value);
  int count_expected = sprintf(expected, "%+-*.*Le", 30, 10, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_e_L_width_precision_asterix_flags_space_minus) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "% -*.*Le", 30, 10, value);
  int count_expected = sprintf(expected, "% -*.*Le", 30, 10, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_e_L_width_zero_precision_asterix_flags_hashtag_minus) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%#-*.*Le", 30, 0, value);
  int count_expected = sprintf(expected, "%#-*.*Le", 30, 0, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_e_L_width_zero_precision_asterix_invalid_flags) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%# +0-*.*Le", 30, 0, value);
  int count_expected = sprintf(expected, "%+#-*.*Le", 30, 0, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

Suite *s21_sprintf_e_suite(void) {
  Suite *s = suite_create("s21_sprintf_e");

  TCase *tc_core = tcase_create("SPRINTF");

  tcase_add_test(tc_core, test_sprintf_e);
  tcase_add_test(tc_core, test_sprintf_E);
  tcase_add_test(tc_core, test_sprintf_negative_e);
  tcase_add_test(tc_core, test_sprintf_zero_e);
  tcase_add_test(tc_core, test_sprintf_e_L_width);
  tcase_add_test(tc_core, test_sprintf_e_L_precision);
  tcase_add_test(tc_core, test_sprintf_e_L_width_asterix);
  tcase_add_test(tc_core, test_sprintf_e_L_precision_asterix);
  tcase_add_test(tc_core, test_sprintf_e_L_width_precision);
  tcase_add_test(tc_core, test_sprintf_e_L_width_precision_asterix);
  tcase_add_test(tc_core,
                 test_sprintf_e_L_width_precision_asterix_flags_plus_minus);
  tcase_add_test(tc_core,
                 test_sprintf_e_L_width_precision_asterix_flags_space_minus);
  tcase_add_test(
      tc_core,
      test_sprintf_e_L_width_zero_precision_asterix_flags_hashtag_minus);
  tcase_add_test(tc_core,
                 test_sprintf_e_L_width_zero_precision_asterix_invalid_flags);

  suite_add_tcase(s, tc_core);
  return s;
}