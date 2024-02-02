#include "../check_s21_sscanf.h"

START_TEST(sscanf_n_) {
  int x, y, x2, y2;
  int calc = s21_sscanf("123 456", "%d%n %d", &x, &y, &y);
  int calc2 = sscanf("123 456", "%d%n %d", &x2, &y2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_n_2) {
  int x, y, x2, y2;
  int calc = s21_sscanf("123 456", "%d %d%n", &x, &y, &y);
  int calc2 = sscanf("123 456", "%d %d%n", &x2, &y2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_n_2_3) {
  char x[10], y[10], x2[10], y2[10];
  int z, z2;
  int calc = s21_sscanf("123 456", "%s %s%n", x, y, &z);
  int calc2 = sscanf("123 456", "%s %s%n", x2, y2, &z2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(x, x2);
  ck_assert_str_eq(y, y2);
  ck_assert_int_eq(z, z2);
}
END_TEST

START_TEST(sscanf_n_2_5) {
  char x, y, x2, y2;
  int z, z2;
  int calc = s21_sscanf("a b", "%c %c%n", &x, &y, &z);
  int calc2 = sscanf("a b", "%c %c%n", &x2, &y2, &z2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
  ck_assert_int_eq(z, z2);
}
END_TEST

START_TEST(sscanf_n_3) {
  int x, x2;
  int calc = s21_sscanf("123 456", "%n", &x);
  int calc2 = sscanf("123 456", "%n", &x2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
}
END_TEST

START_TEST(sscanf_n_4) {
  int x, x2, y, y2;
  int calc = s21_sscanf("123 456", "%n%d", &x, &y);
  int calc2 = sscanf("123 456", "%n%d", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_n_5) {
  int x, x2, y, y2;
  int calc = s21_sscanf("123 456", "%n %d", &x, &y);
  int calc2 = sscanf("123 456", "%n %d", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_n_6) {
  int x = 0, x2 = 0;
  int calc = s21_sscanf("", "%n", &x);
  int calc2 = sscanf("", "%n", &x2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
}
END_TEST

START_TEST(sscanf_n_7) {
  char x[10], x2[10], z[10], z2[10];
  int y, y2;
  int calc = s21_sscanf("123 456", "%s %n %s", x, &y, z);
  int calc2 = sscanf("123 456", "%s %n %s", x2, &y2, z2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(x, x2);
  ck_assert_int_eq(y, y2);
  ck_assert_str_eq(z, z2);
}
END_TEST

START_TEST(sscanf_n_8) {
  int x, x2, y, y2;
  int calc = s21_sscanf("123123", "%d %n", &x, &y);
  int calc2 = sscanf("123123", "%d %n", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_n_9) {
  int x, x2, y, y2;
  int calc = s21_sscanf("123123", "%d%n", &x, &y);
  int calc2 = sscanf("123123", "%d%n", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_n_10) {
  int x, x2, y, y2;
  int calc = s21_sscanf("123 123", "%d %n", &x, &y);
  int calc2 = sscanf("123 123", "%d %n", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_n_11) {
  int x, x2, y, y2;
  int calc = s21_sscanf("123 123", "%d%n", &x, &y);
  int calc2 = sscanf("123 123", "%d%n", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_n_12) {
  int x, x2, y, y2;
  int calc = s21_sscanf("123 456", "%n%d", &x, &y);
  int calc2 = sscanf("123 456", "%n%d", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_n_13) {
  int y, y2;
  int calc = s21_sscanf("123 456", "%*d%n %d", &y, &y);
  int calc2 = sscanf("123 456", "%*d%n %d", &y2, &y2);
  ck_assert_int_eq(calc, calc2);

  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_n_14) {
  int y, y2;
  int calc = s21_sscanf("123 456", "%*d %d%n", &y, &y);
  int calc2 = sscanf("123 456", "%*d %d%n", &y2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(y, y2);
}
END_TEST

Suite *s21_sscanf_n_format_suite(void) {
  Suite *s = suite_create("s21_sscanf_n");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sscanf_n_);
  tcase_add_test(tc_core, sscanf_n_2);
  tcase_add_test(tc_core, sscanf_n_2_3);
  tcase_add_test(tc_core, sscanf_n_2_5);
  tcase_add_test(tc_core, sscanf_n_3);
  tcase_add_test(tc_core, sscanf_n_4);
  tcase_add_test(tc_core, sscanf_n_5);
  tcase_add_test(tc_core, sscanf_n_6);
  tcase_add_test(tc_core, sscanf_n_7);
  tcase_add_test(tc_core, sscanf_n_8);
  tcase_add_test(tc_core, sscanf_n_9);
  tcase_add_test(tc_core, sscanf_n_10);
  tcase_add_test(tc_core, sscanf_n_11);
  tcase_add_test(tc_core, sscanf_n_12);
  tcase_add_test(tc_core, sscanf_n_13);
  tcase_add_test(tc_core, sscanf_n_14);

  suite_add_tcase(s, tc_core);

  return s;
}