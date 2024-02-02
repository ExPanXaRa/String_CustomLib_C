#include "../check_s21_sprintf.h"

START_TEST(test_s21_sprintf_d_basic) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %d", 42);
  int expected_count = sprintf(expected, "Number: %d", 42);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_negative) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %d", -123);
  int expected_count = sprintf(expected, "Number: %d", -123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_zero) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %d", 0);
  int expected_count = sprintf(expected, "Number: %d", 0);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_l) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %ld", 92233720333L);
  int expected_count = sprintf(expected, "Number: %ld", 92233720333L);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_h) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %hd", (short)-32765);
  int expected_count = sprintf(expected, "Number: %hd", (short)-32765);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_width) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %30d", 123);
  int expected_count = sprintf(expected, "Number: %30d", 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_width_zero_flag) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %030d", 123);
  int expected_count = sprintf(expected, "Number: %030d", 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_width_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %*d", 33, 123);
  int expected_count = sprintf(expected, "Number: %*d", 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %.33d", 123);
  int expected_count = sprintf(expected, "Number: %.33d", 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_zero_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %.d", 123);
  int expected_count = sprintf(expected, "Number: %.d", 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_precision_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %.*d", 33, 123);
  int expected_count = sprintf(expected, "Number: %.*d", 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_precision_width_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %*.*d", 44, 33, 123);
  int expected_count = sprintf(expected, "Number: %*.*d", 44, 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_precision_width_asterix_flag_plus) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %+*.*d", 44, 33, 123);
  int expected_count = sprintf(expected, "Number: %+*.*d", 44, 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_precision_width_asterix_flag_space) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: % *.*d", 44, 33, 123);
  int expected_count = sprintf(expected, "Number: % *.*d", 44, 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_width_asterix_flag_minus) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %-*d", 33, 123);
  int expected_count = sprintf(expected, "Number: %-*d", 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_negative_d_width_asterix_flag_minus) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %-*d", 33, -123);
  int expected_count = sprintf(expected, "Number: %-*d", 33, -123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_width_asterix_flag_minus_plus) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %+-*d", 33, 123);
  int expected_count = sprintf(expected, "Number: %+-*d", 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_mult_width_asterix_flag_minus_plus) {
  char buffer[1000] = {0};
  char expected[1000] = {0};

  int result_count = s21_sprintf(buffer, "Number: %+-*d %+-*d %+-*d %+-*d", 33,
                                 123, 33, 23, 33, 223, 33, 11111111);
  int expected_count = sprintf(expected, "Number: %+-*d %+-*d %+-*d %+-*d", 33,
                               123, 33, 23, 33, 223, 33, 11111111);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_negative_d_mult_width_asterix_flag_minus_plus) {
  char buffer[1000] = {0};
  char expected[1000] = {0};

  int result_count = s21_sprintf(buffer, "Number: %+-*d %+-*d %+-*d %+-*d", 33,
                                 -123, 33, -23, 33, -223, 33, -11111111);
  int expected_count = sprintf(expected, "Number: %+-*d %+-*d %+-*d %+-*d", 33,
                               -123, 33, -23, 33, -223, 33, -11111111);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_d_invalid_flags) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %#0 +-*d", 33, 123);
  int expected_count = sprintf(expected, "Number: %+-*d", 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

Suite *s21_sprintf_d_suite(void) {
  Suite *s = suite_create("s21_sprintf_d");

  TCase *tc_core = tcase_create("SPRINTF");

  tcase_add_test(tc_core, test_s21_sprintf_d_basic);
  tcase_add_test(tc_core, test_s21_sprintf_d_negative);
  tcase_add_test(tc_core, test_s21_sprintf_d_zero);
  tcase_add_test(tc_core, test_s21_sprintf_d_l);
  tcase_add_test(tc_core, test_s21_sprintf_d_h);
  tcase_add_test(tc_core, test_s21_sprintf_d_width);
  tcase_add_test(tc_core, test_s21_sprintf_d_width_zero_flag);
  tcase_add_test(tc_core, test_s21_sprintf_d_width_asterix);
  tcase_add_test(tc_core, test_s21_sprintf_d_precision);
  tcase_add_test(tc_core, test_s21_sprintf_d_zero_precision);
  tcase_add_test(tc_core, test_s21_sprintf_d_precision_asterix);
  tcase_add_test(tc_core, test_s21_sprintf_d_precision_width_asterix);
  tcase_add_test(tc_core, test_s21_sprintf_d_precision_width_asterix_flag_plus);
  tcase_add_test(tc_core,
                 test_s21_sprintf_d_precision_width_asterix_flag_space);
  tcase_add_test(tc_core, test_s21_sprintf_d_width_asterix_flag_minus);
  tcase_add_test(tc_core, test_s21_sprintf_negative_d_width_asterix_flag_minus);

  tcase_add_test(tc_core, test_s21_sprintf_d_width_asterix_flag_minus_plus);
  tcase_add_test(tc_core,
                 test_s21_sprintf_d_mult_width_asterix_flag_minus_plus);
  tcase_add_test(
      tc_core, test_s21_sprintf_negative_d_mult_width_asterix_flag_minus_plus);
  tcase_add_test(tc_core, test_s21_sprintf_d_invalid_flags);

  suite_add_tcase(s, tc_core);
  return s;
}