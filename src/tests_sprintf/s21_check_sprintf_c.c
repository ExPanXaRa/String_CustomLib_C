

#include "../check_s21_sprintf.h"

START_TEST(test_s21_sprintf_c_normal) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Character: %c", 'A');
  int expected_count = sprintf(expected, "Character: %c", 'A');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_c_minus) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Character: %-c", 'A');
  int expected_count = sprintf(expected, "Character: %-c", 'A');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_c_width) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Character: %20c", 'A');
  int expected_count = sprintf(expected, "Character: %20c", 'A');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_c_width_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Character: %*c", 20, 'A');
  int expected_count = sprintf(expected, "Character: %*c", 20, 'A');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_c_minus_and_width) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Character: %-20c", 'A');
  int expected_count = sprintf(expected, "Character: %-20c", 'A');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_c_null) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Character: %c", '\0');
  int expected_count = sprintf(expected, "Character: %c", '\0');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_c_newline) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Character: %c", '\n');
  int expected_count = sprintf(expected, "Character: %c", '\n');
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_c_invalid_flags) {
  char buffer[100] = {0};
  char expected[100] = {0};

  int result_count = s21_sprintf(buffer, "Character: % +#0c", '\n');
  int expected_count = sprintf(expected, "Character: %c", '\n');

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

Suite *s21_sprintf_c_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sprintf_c");

  tc_core = tcase_create("SPRINTF");

  tcase_add_test(tc_core, test_s21_sprintf_c_normal);
  tcase_add_test(tc_core, test_s21_sprintf_c_minus);
  tcase_add_test(tc_core, test_s21_sprintf_c_width);
  tcase_add_test(tc_core, test_s21_sprintf_c_width_asterix);
  tcase_add_test(tc_core, test_s21_sprintf_c_minus_and_width);
  tcase_add_test(tc_core, test_s21_sprintf_c_null);
  tcase_add_test(tc_core, test_s21_sprintf_c_newline);
  tcase_add_test(tc_core, test_s21_sprintf_c_invalid_flags);

  suite_add_tcase(s, tc_core);

  return s;
}