#include "../check_s21_sprintf.h"

START_TEST(test_sprintf_s_basic) {
  char buffer[100] = {0};
  char expected[100] = {0};
  char* str = "Hello, World!";

  int count_result = s21_sprintf(buffer, "%s", str);
  int count_expected = sprintf(expected, "%s", str);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_s_null) {
  char buffer[100] = {0};
  char expected[100] = {0};
  char* str = NULL;

  int count_result = s21_sprintf(buffer, "%s", str);
  int count_expected = sprintf(expected, "%s", str);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_sprintf_s_empty) {
  char buffer[100] = {0};
  char expected[100] = {0};
  char* str = "";

  int count_result = s21_sprintf(buffer, "%s", str);
  int count_expected = sprintf(expected, "%s", str);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

START_TEST(test_s21_sprintf_s_width) {
  char buffer[100] = {0};
  char expected[100] = {0};
  char* str = "Hello, World!";

  int result_count = s21_sprintf(buffer, "%20s", str);
  int expected_count = sprintf(expected, "%20s", str);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_s_width_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};
  char* str = "Hello, World!";

  int result_count = s21_sprintf(buffer, "%*s", 20, str);
  int expected_count = sprintf(expected, "%*s", 20, str);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_s_precision) {
  char buffer[100] = {0};
  char expected[100] = {0};
  char* str = "Hello, World!";

  int result_count = s21_sprintf(buffer, "%5s", str);
  int expected_count = sprintf(expected, "%5s", str);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_s_precision_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};
  char* str = "Hello, World!";

  int result_count = s21_sprintf(buffer, "%.*s", 5, str);
  int expected_count = sprintf(expected, "%.*s", 5, str);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_s_width_precision_asterix) {
  char buffer[100] = {0};
  char expected[100] = {0};
  char* str = "Hello, World!";

  int result_count = s21_sprintf(buffer, "%*.*s", 20, 10, str);
  int expected_count = sprintf(expected, "%*.*s", 20, 10, str);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_s_minus_and_width) {
  char buffer[100] = {0};
  char expected[100] = {0};

  char* str = "Hello, World!";

  int result_count = s21_sprintf(buffer, "%-20s", str);
  int expected_count = sprintf(expected, "%-20s", str);
  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

START_TEST(test_s21_sprintf_s_invalid_flags) {
  char buffer[100] = {0};
  char expected[100] = {0};

  char* str = "Hello, World!";

  int result_count = s21_sprintf(buffer, "Character: % +#0s", str);
  int expected_count = sprintf(expected, "Character: %s", str);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(result_count, expected_count);
}
END_TEST

Suite* s21_sprintf_s_suite(void) {
  Suite* s = suite_create("s21_sprintf_s");
  TCase* tc_core = tcase_create("SPRINTF");

  tcase_add_test(tc_core, test_sprintf_s_basic);
  tcase_add_test(tc_core, test_sprintf_s_null);
  tcase_add_test(tc_core, test_sprintf_s_empty);
  tcase_add_test(tc_core, test_s21_sprintf_s_width);
  tcase_add_test(tc_core, test_s21_sprintf_s_width_asterix);
  tcase_add_test(tc_core, test_s21_sprintf_s_precision);
  tcase_add_test(tc_core, test_s21_sprintf_s_precision_asterix);
  tcase_add_test(tc_core, test_s21_sprintf_s_width_precision_asterix);
  tcase_add_test(tc_core, test_s21_sprintf_s_minus_and_width);
  tcase_add_test(tc_core, test_s21_sprintf_s_invalid_flags);

  suite_add_tcase(s, tc_core);
  return s;
}
