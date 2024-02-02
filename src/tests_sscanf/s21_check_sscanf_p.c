#include "../check_s21_sscanf.h"

START_TEST(sscanf_p_) {
  char* buffer = "0x1F1CD3E6";
  void *x = NULL, *x2 = NULL;
  int calc = s21_sscanf(buffer, "%p", &x);
  int calc2 = sscanf(buffer, "%p", &x2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_ptr_eq(x, x2);
}
END_TEST

START_TEST(sscanf_p_2) {
  char* buffer = "0x1F1CD3E6";
  int calc = s21_sscanf(buffer, "%*p");
  int calc2 = sscanf(buffer, "%*p");
  ck_assert_int_eq(calc, calc2);
}
END_TEST

Suite* s21_sscanf_p_format_suite(void) {
  Suite* s = suite_create("s21_sscanf_p");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sscanf_p_);
  tcase_add_test(tc_core, sscanf_p_2);

  suite_add_tcase(s, tc_core);

  return s;
}