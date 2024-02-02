#include "../check_s21_sprintf.h"

START_TEST(test_sprintf_g) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double value = 123.456;

  int count_result = s21_sprintf(buffer, "%g", value);
  int count_expected = sprintf(expected, "%g", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_g_l) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double value = 123.456;

  int count_result = s21_sprintf(buffer, "%lg", value);
  int count_expected = sprintf(expected, "%lg", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_g_L) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 1222222222222223.4567891;

  int count_result = s21_sprintf(buffer, "%Lg", value);
  int count_expected = sprintf(expected, "%Lg", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_negative_g) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double value = -789.012;

  int count_result = s21_sprintf(buffer, "%g", value);
  int count_expected = sprintf(expected, "%g", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_negative_g_l) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double value = -789.012;

  int count_result = s21_sprintf(buffer, "%lg", value);
  int count_expected = sprintf(expected, "%lg", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_negative_g_L) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = -1222222222222223.4567891;

  int count_result = s21_sprintf(buffer, "%Lg", value);
  int count_expected = sprintf(expected, "%Lg", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_zero_g) {
  char buffer[100] = {0};
  char expected[100] = {0};
  double value = 0.0;

  int count_result = s21_sprintf(buffer, "%g", value);
  int count_expected = sprintf(expected, "%g", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_g_L_width) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%30Lg", value);
  int count_expected = sprintf(expected, "%30Lg", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_g_L_width_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%*Lg", 30, value);
  int count_expected = sprintf(expected, "%*Lg", 30, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_g_L_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%.10Lg", value);
  int count_expected = sprintf(expected, "%.10Lg", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_g_L_precision_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%.*Lg", 10, value);
  int count_expected = sprintf(expected, "%.*Lg", 10, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_g_L_width_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%30.10Lg", value);
  int count_expected = sprintf(expected, "%30.10Lg", value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_g_L_width_precision_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%*.*Lg", 30, 10, value);
  int count_expected = sprintf(expected, "%*.*Lg", 30, 10, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_g_L_width_precision_asterix_flags_plus_zero) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%0+*.*Lg", 30, 10, value);
  int count_expected = sprintf(expected, "%0+*.*Lg", 30, 10, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_g_L_width_precision_asterix_flags_plus_minus) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%-+*.*Lg", 30, 10, value);
  int count_expected = sprintf(expected, "%-+*.*Lg", 30, 10, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_negative_g_L_width_precision_asterix_flags_plus_minus) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = -123.456;

  int count_result = s21_sprintf(buffer, "%-+*.*Lg", 30, 10, value);
  int count_expected = sprintf(expected, "%-+*.*Lg", 30, 10, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_g_L_width_precision_asterix_flag_hashtag) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%#*.*Lg", 5, 3, value);
  int count_expected = sprintf(expected, "%#*.*Lg", 5, 3, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_g_L_width_precision_asterix_flag_space) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "% *.*Lg", 30, 10, value);
  int count_expected = sprintf(expected, "% *.*Lg", 30, 10, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_g_L_width_asterix_flag_zero) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%0*Lg", 30, value);
  int count_expected = sprintf(expected, "%0*Lg", 30, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_g_L_width_precision_asterix_invalid_flags) {
  char buffer[100] = {0};
  char expected[100] = {0};
  long double value = 123.456;

  int count_result = s21_sprintf(buffer, "%+0-# *.*Lg", 30, 10, value);
  int count_expected = sprintf(expected, "%+-*.*Lg", 30, 10, value);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

Suite *s21_sprintf_g_suite(void) {
  Suite *s = suite_create("s21_sprintf_g");

  TCase *tc_core = tcase_create("SPRINTF");

  tcase_add_test(tc_core, test_sprintf_g);
  tcase_add_test(tc_core, test_sprintf_g_l);
  tcase_add_test(tc_core, test_sprintf_g_L);
  tcase_add_test(tc_core, test_sprintf_zero_g);
  tcase_add_test(tc_core, test_sprintf_negative_g);
  tcase_add_test(tc_core, test_sprintf_negative_g_l);
  tcase_add_test(tc_core, test_sprintf_negative_g_L);
  tcase_add_test(tc_core, test_sprintf_g_L_width);
  tcase_add_test(tc_core, test_sprintf_g_L_precision);
  tcase_add_test(tc_core, test_sprintf_g_L_width_asterix);
  tcase_add_test(tc_core, test_sprintf_g_L_precision_asterix);
  tcase_add_test(tc_core, test_sprintf_g_L_width_precision);
  tcase_add_test(tc_core, test_sprintf_g_L_width_precision_asterix);
  tcase_add_test(tc_core,
                 test_sprintf_g_L_width_precision_asterix_flags_plus_zero);
  tcase_add_test(tc_core,
                 test_sprintf_g_L_width_precision_asterix_flags_plus_minus);
  tcase_add_test(
      tc_core,
      test_sprintf_negative_g_L_width_precision_asterix_flags_plus_minus);
  tcase_add_test(tc_core,
                 test_sprintf_g_L_width_precision_asterix_flag_hashtag);
  tcase_add_test(tc_core, test_sprintf_g_L_width_precision_asterix_flag_space);
  tcase_add_test(tc_core, test_sprintf_g_L_width_asterix_flag_zero);
  tcase_add_test(tc_core,
                 test_sprintf_g_L_width_precision_asterix_invalid_flags);

  suite_add_tcase(s, tc_core);
  return s;
}