#include "../check_s21_sprintf.h"

START_TEST(test_sprintf_n) {
  char buffer[100];
  char expected[100];
  int n_val_res = 0;
  int n_val_orig = 0;

  int n_val2_res = 0;
  int n_val2_orig = 0;

  int count_result =
      s21_sprintf(buffer, "123%n123123%n", &n_val_res, &n_val2_res);
  int count_expected =
      sprintf(expected, "123%n123123%n", &n_val_orig, &n_val2_orig);

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
  ck_assert_int_eq(n_val_res, n_val_orig);
  ck_assert_int_eq(n_val2_res, n_val2_orig);
}
END_TEST

START_TEST(test_sprintf_percent) {
  char buffer[100];
  char expected[100];

  int count_result = s21_sprintf(buffer, "%%X");
  int count_expected = sprintf(expected, "%%X");

  ck_assert_str_eq(buffer, expected);
  ck_assert_int_eq(count_result, count_expected);
}
END_TEST

Suite *s21_sprintf_other_suite(void) {
  Suite *s = suite_create("s21_sprintf_other");

  TCase *tc_core = tcase_create("SPRINTF");
  tcase_add_test(tc_core, test_sprintf_n);
  tcase_add_test(tc_core, test_sprintf_percent);

  suite_add_tcase(s, tc_core);
  return s;
}