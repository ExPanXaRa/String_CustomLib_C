#include "../check_s21_sprintf.h"

START_TEST(test_s21_sprintf_i_basic) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %i", 42);
  int expected_count = sprintf(expected, "Number: %i", 42);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_negative_i) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %i", -123);
  int expected_count = sprintf(expected, "Number: %i", -123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_zero) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %i", 0);
  int expected_count = sprintf(expected, "Number: %i", 0);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_l) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %li", 92233720333L);
  int expected_count = sprintf(expected, "Number: %li", 92233720333L);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_h) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %hi", (short)-32765);
  int expected_count = sprintf(expected, "Number: %hi", (short)-32765);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_width) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %30i", 123);
  int expected_count = sprintf(expected, "Number: %30i", 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_width_zero_flag) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %030i", 123);
  int expected_count = sprintf(expected, "Number: %030i", 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_width_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %*i", 33, 123);
  int expected_count = sprintf(expected, "Number: %*i", 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %.33i", 123);
  int expected_count = sprintf(expected, "Number: %.33i", 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_zero_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %.i", 123);
  int expected_count = sprintf(expected, "Number: %.i", 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_precision_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %.*i", 33, 123);
  int expected_count = sprintf(expected, "Number: %.*i", 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_precision_width_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %*.*i", 44, 33, 123);
  int expected_count = sprintf(expected, "Number: %*.*i", 44, 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_precision_width_asterix_flag_plus) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %+*.*i", 44, 33, 123);
  int expected_count = sprintf(expected, "Number: %+*.*i", 44, 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_precision_width_asterix_flag_space) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: % *.*i", 44, 33, 123);
  int expected_count = sprintf(expected, "Number: % *.*i", 44, 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_width_asterix_flag_minus) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %-*i", 33, 123);
  int expected_count = sprintf(expected, "Number: %-*i", 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_negative_i_width_asterix_flag_minus) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %-*i", 33, -123);
  int expected_count = sprintf(expected, "Number: %-*i", 33, -123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_width_asterix_flag_minus_plus) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %+-*i", 33, 123);
  int expected_count = sprintf(expected, "Number: %+-*i", 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_mult_width_asterix_flag_minus_plus) {
  char buffer[1000] = {0};
  char expected[1000] = {0};

  int result_count = s21_sprintf(buffer, "Number: %+-*i %+-*i %+-*i %+-*i", 33,
                                 123, 33, 23, 33, 223, 33, 11111111);
  int expected_count = sprintf(expected, "Number: %+-*i %+-*i %+-*i %+-*i", 33,
                               123, 33, 23, 33, 223, 33, 11111111);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_negative_i_mult_width_asterix_flag_minus_plus) {
  char buffer[1000] = {0};
  char expected[1000] = {0};

  int result_count = s21_sprintf(buffer, "Number: %+-*i %+-*i %+-*i %+-*i", 33,
                                 -123, 33, -23, 33, -223, 33, -11111111);
  int expected_count = sprintf(expected, "Number: %+-*i %+-*i %+-*i %+-*i", 33,
                               -123, 33, -23, 33, -223, 33, -11111111);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_i_invalid_flags) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Number: %#0 +-*i", 33, 123);
  int expected_count = sprintf(expected, "Number: %+-*i", 33, 123);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

Suite *s21_sprintf_i_suite(void) {
  Suite *s = suite_create("s21_sprintf_i");

  TCase *tc_core = tcase_create("SPRINTF");

  tcase_add_test(tc_core, test_s21_sprintf_i_basic);
  tcase_add_test(tc_core, test_s21_sprintf_negative_i);
  tcase_add_test(tc_core, test_s21_sprintf_i_zero);
  tcase_add_test(tc_core, test_s21_sprintf_i_l);
  tcase_add_test(tc_core, test_s21_sprintf_i_h);
  tcase_add_test(tc_core, test_s21_sprintf_i_width);
  tcase_add_test(tc_core, test_s21_sprintf_i_width_zero_flag);
  tcase_add_test(tc_core, test_s21_sprintf_i_width_asterix);
  tcase_add_test(tc_core, test_s21_sprintf_i_precision);
  tcase_add_test(tc_core, test_s21_sprintf_i_zero_precision);
  tcase_add_test(tc_core, test_s21_sprintf_i_precision_asterix);
  tcase_add_test(tc_core, test_s21_sprintf_i_precision_width_asterix);
  tcase_add_test(tc_core, test_s21_sprintf_i_precision_width_asterix_flag_plus);
  tcase_add_test(tc_core,
                 test_s21_sprintf_i_precision_width_asterix_flag_space);
  tcase_add_test(tc_core, test_s21_sprintf_i_width_asterix_flag_minus);
  tcase_add_test(tc_core, test_s21_sprintf_negative_i_width_asterix_flag_minus);

  tcase_add_test(tc_core, test_s21_sprintf_i_width_asterix_flag_minus_plus);
  tcase_add_test(tc_core,
                 test_s21_sprintf_i_mult_width_asterix_flag_minus_plus);
  tcase_add_test(
      tc_core, test_s21_sprintf_negative_i_mult_width_asterix_flag_minus_plus);
  tcase_add_test(tc_core, test_s21_sprintf_i_invalid_flags);

  suite_add_tcase(s, tc_core);
  return s;
}