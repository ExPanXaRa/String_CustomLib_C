#include "../check_s21_sscanf.h"

START_TEST(sscanf_e_) {
  float x, y, x2, y2;
  int calc = s21_sscanf("4.9e-15 1.6e-19", "%E %E", &x, &y);
  int calc2 = sscanf("4.9e-15 1.6e-19", "%E %E", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(x, x2);
  ck_assert_float_eq(y, y2);
}
END_TEST

START_TEST(sscanf_e_2) {
  float value, value2;

  int calc = s21_sscanf("1.3e-9", "%f", &value);
  int calc2 = sscanf("1.3e-9", "%f", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(value, value2);
}

START_TEST(sscanf_e_3) {
  const char* input = "2.2e-16 8.85e-12 a 30";
  float value1 = 0, value2 = 0, value3 = 0, value12 = 0, value22 = 0,
        value32 = 0;

  int calc = s21_sscanf(input, "%g %g %g", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%g %g %g", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(value1, value12);
  ck_assert_float_eq(value2, value22);
  ck_assert_float_eq(value3, value32);
}

START_TEST(sscanf_e_4) {
  const char* input = "hello";
  float value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%G", &value);
  int calc2 = sscanf(input, "%G", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(value, value2);
}

START_TEST(sscanf_e_5) {
  float x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("6.022e23a3 456", "%G %f", &x, &y);
  int calc2 = sscanf("6.022e23a3 456", "%G %f", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(x, x2);
  ck_assert_float_eq(y, y2);
}
END_TEST

START_TEST(sscanf_e_6) {
  float x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("1.989e30.3 456", "%e %E", &x, &y);
  int calc2 = sscanf("1.989e30.3 456", "%e %E", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(x, x2);
  ck_assert_float_eq(y, y2);
}
END_TEST

START_TEST(sscanf_e_7) {
  float x, y, x2, y2;
  int calc = s21_sscanf(" 1.5e12      456 ", "%g %f", &x, &y);
  int calc2 = sscanf(" 1.5e12      456 ", "%g %f", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(x, x2);
  ck_assert_float_eq(y, y2);
}
END_TEST

START_TEST(sscanf_e_8) {
  float x, y, x2, y2;
  int calc = s21_sscanf("-6.67e-11 456", "%e %e", &x, &y);
  int calc2 = sscanf("-6.67e-11 456", "%e %e", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(x, x2);
  ck_assert_float_eq(y, y2);
}
END_TEST

START_TEST(sscanf_e_9) {
  const char* input = "-1.5e12  0 1.5e12 ";
  float value1, value2, value3, value12, value22, value32;

  int calc = s21_sscanf(input, "%e %e %e", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%e %e %e", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(value1, value12);
  ck_assert_float_eq(value2, value22);
  ck_assert_float_eq(value3, value32);
}

START_TEST(sscanf_e_10) {
  const char* input = "1.5e12 ";
  float value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%e", &value);
  int calc2 = sscanf(input, "%e", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(value, value2);
}

START_TEST(sscanf_e_11) {
  const char* input = "";
  float value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%e", &value);
  int calc2 = sscanf(input, "%e", &value2);

  ck_assert_float_eq(calc, calc2);
  ck_assert_float_eq(value, value2);
}

START_TEST(sscanf_e_12) {
  float number = 0.0, number2 = 0.0;

  int calc = s21_sscanf("1.17549435e-38", "%12e", &number);
  int calc2 = sscanf("1.17549435e-38", "%12e", &number2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(number, number2);
}

START_TEST(sscanf_e_13) {
  float number = 0.0, number2 = 0.0;

  int calc = s21_sscanf("3.40282347e+38", "%e", &number);
  int calc2 = sscanf("3.40282347e+38", "%e", &number2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(number, number2);
}

START_TEST(sscanf_e_14) {
  float number = 0.0, number2 = 0.0;

  int calc = s21_sscanf("0.0e+00", "%E", &number);
  int calc2 = sscanf("0.0e+00", "%E", &number2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(number, number2);
}

START_TEST(sscanf_e_15) {
  float number = 0.0, number2 = 0.0;

  int calc = s21_sscanf("-7.1234567e-12", "%13f", &number);
  int calc2 = sscanf("-7.1234567e-12", "%13f", &number2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(number, number2);
}

START_TEST(sscanf_e_2_long) {
  long double value, value2;

  int calc = s21_sscanf("1.3e-9", "%13Lf", &value);
  int calc2 = sscanf("1.3e-9", "%13Lf", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_ldouble_eq(value, value2);
}

START_TEST(sscanf_e_4_long) {
  const char* input = "hello";
  long double value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%LG", &value);
  int calc2 = sscanf(input, "%LG", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_ldouble_eq(value, value2);
}

START_TEST(sscanf_e_7_long) {
  long double x, y, x2, y2;
  int calc = s21_sscanf(" 1.5e12      456 ", "%Lg %Lf", &x, &y);
  int calc2 = sscanf(" 1.5e12      456 ", "%Lg %Lf", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_ldouble_eq(x, x2);
  ck_assert_ldouble_eq(y, y2);
}
END_TEST

START_TEST(sscanf_e_9_long) {
  const char* input = "-1.5e12  0 1.5e12 ";
  long double value1, value2, value3, value12, value22, value32;

  int calc = s21_sscanf(input, "%Le %Le %Le", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%Le %Le %Le", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_ldouble_eq(value1, value12);
  ck_assert_ldouble_eq(value2, value22);
  ck_assert_ldouble_eq(value3, value32);
}

START_TEST(sscanf_e_10_long) {
  const char* input = "1.5e12 ";
  long double value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%Le", &value);
  int calc2 = sscanf(input, "%Le", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_ldouble_eq(value, value2);
}

START_TEST(sscanf_e_11_long) {
  const char* input = "";
  long double value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%Le", &value);
  int calc2 = sscanf(input, "%Le", &value2);

  ck_assert_ldouble_eq(calc, calc2);
  ck_assert_ldouble_eq(value, value2);
}

START_TEST(sscanf_e_14_long) {
  long double number = 0.0, number2 = 0.0;

  int calc = s21_sscanf("0.0e+00", "%LE", &number);
  int calc2 = sscanf("0.0e+00", "%LE", &number2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_ldouble_eq(number, number2);
}

START_TEST(sscanf_e_17) {
  float y, y2;
  int calc = s21_sscanf("4.9e-15 1.6e-19", "%*E %E", &y);
  int calc2 = sscanf("4.9e-15 1.6e-19", "%*E %E", &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(y, y2);
}
END_TEST

START_TEST(sscanf_e_18) {
  int calc = s21_sscanf("1.3e-9", "%*f");
  int calc2 = sscanf("1.3e-9", "%*f");

  ck_assert_int_eq(calc, calc2);
}

START_TEST(sscanf_e_19) {
  float x, x2;
  int calc = s21_sscanf("5e", "%e", &x);
  int calc2 = sscanf("5e", "%e", &x2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_float_eq(x, x2);
}

START_TEST(sscanf_e_20) {
  long double x, x2;
  int calc = s21_sscanf("5e", "%Le", &x);
  int calc2 = sscanf("5e", "%Le", &x2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_ldouble_eq(x, x2);
}

Suite* s21_sscanf_e_format_suite(void) {
  Suite* s = suite_create("s21_sscanf_e_E_f_g_G");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sscanf_e_);
  tcase_add_test(tc_core, sscanf_e_2);
  tcase_add_test(tc_core, sscanf_e_3);
  tcase_add_test(tc_core, sscanf_e_4);
  tcase_add_test(tc_core, sscanf_e_5);
  tcase_add_test(tc_core, sscanf_e_6);
  tcase_add_test(tc_core, sscanf_e_7);
  tcase_add_test(tc_core, sscanf_e_8);
  tcase_add_test(tc_core, sscanf_e_9);
  tcase_add_test(tc_core, sscanf_e_10);
  tcase_add_test(tc_core, sscanf_e_11);
  tcase_add_test(tc_core, sscanf_e_12);
  tcase_add_test(tc_core, sscanf_e_13);
  tcase_add_test(tc_core, sscanf_e_14);
  tcase_add_test(tc_core, sscanf_e_15);
  tcase_add_test(tc_core, sscanf_e_17);
  tcase_add_test(tc_core, sscanf_e_18);
  tcase_add_test(tc_core, sscanf_e_19);
  tcase_add_test(tc_core, sscanf_e_20);
  tcase_add_test(tc_core, sscanf_e_2_long);
  tcase_add_test(tc_core, sscanf_e_4_long);
  tcase_add_test(tc_core, sscanf_e_7_long);
  tcase_add_test(tc_core, sscanf_e_9_long);
  tcase_add_test(tc_core, sscanf_e_10_long);
  tcase_add_test(tc_core, sscanf_e_11_long);
  tcase_add_test(tc_core, sscanf_e_14_long);

  suite_add_tcase(s, tc_core);

  return s;
}
