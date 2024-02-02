#include "../check_s21_sprintf.h"

START_TEST(test_s21_sprintf_u_basic) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %u", 42);
  int expected_count = sprintf(expected, "Number: %u", 42);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_u_zero) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %u", 0);
  int expected_count = sprintf(expected, "Number: %u", 0);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_u_l) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %lu", 92233720333L);
  int expected_count = sprintf(expected, "Number: %lu", 92233720333L);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_u_h) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %hu", (short)32765);
  int expected_count = sprintf(expected, "Number: %hu", (short)32765);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_u_width) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %30u", 123);
  int expected_count = sprintf(expected, "Number: %30u", 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_u_width_zero_flag) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %030u", 123);
  int expected_count = sprintf(expected, "Number: %030u", 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_u_width_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %*u", 33, 123);
  int expected_count = sprintf(expected, "Number: %*u", 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_u_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %.10u", 123);
  int expected_count = sprintf(expected, "Number: %.10u", 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_u_zero_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %.u", 123);
  int expected_count = sprintf(expected, "Number: %.u", 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_u_precision_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %.*u", 33, 123);
  int expected_count = sprintf(expected, "Number: %.*u", 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_u_precision_width_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %*.*u", 44, 33, 123);
  int expected_count = sprintf(expected, "Number: %*.*u", 44, 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_u_width_asterix_flag_minus) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %-*u", 33, 123);
  int expected_count = sprintf(expected, "Number: %-*u", 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_u_invalid_flags) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %#0 +-*u", 33, 123);
  int expected_count = sprintf(expected, "Number: %-*u", 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

Suite *s21_sprintf_u_suite(void) {
  Suite *s = suite_create("s21_sprintf_u");

  TCase *tc_core = tcase_create("SPRINTF");

  tcase_add_test(tc_core, test_s21_sprintf_u_basic);

  tcase_add_test(tc_core, test_s21_sprintf_u_zero);
  tcase_add_test(tc_core, test_s21_sprintf_u_l);
  tcase_add_test(tc_core, test_s21_sprintf_u_h);
  tcase_add_test(tc_core, test_s21_sprintf_u_width);
  tcase_add_test(tc_core, test_s21_sprintf_u_width_zero_flag);
  tcase_add_test(tc_core, test_s21_sprintf_u_width_asterix);
  tcase_add_test(tc_core, test_s21_sprintf_u_precision);
  tcase_add_test(tc_core, test_s21_sprintf_u_zero_precision);
  tcase_add_test(tc_core, test_s21_sprintf_u_precision_asterix);
  tcase_add_test(tc_core, test_s21_sprintf_u_precision_width_asterix);
  tcase_add_test(tc_core, test_s21_sprintf_u_width_asterix_flag_minus);
  tcase_add_test(tc_core, test_s21_sprintf_u_invalid_flags);

  suite_add_tcase(s, tc_core);
  return s;
}