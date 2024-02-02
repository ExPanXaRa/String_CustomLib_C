#include "../check_s21_sscanf.h"

START_TEST(sscanf_d_) {
  int x, y, x2, y2;
  int calc = s21_sscanf("123 456", "%d %d", &x, &y);
  int calc2 = sscanf("123 456", "%d %d", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_d_2) {
  int value, value2;

  int calc = s21_sscanf("42", "%d", &value);
  int calc2 = sscanf("42", "%d", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_d_3) {
  const char* input = "10 20 a 30";
  int value1 = 0, value2 = 0, value3 = 0, value12 = 0, value22 = 0, value32 = 0;

  int calc = s21_sscanf(input, "%d %d %d", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%d %d %d", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_d_4) {
  const char* input = "hello";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%d", &value);
  int calc2 = sscanf(input, "%d", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_d_5) {
  int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("12a3 456", "%d %d", &x, &y);
  int calc2 = sscanf("12a3 456", "%d %d", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_d_6) {
  int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("12.3 456", "%d %d", &x, &y);
  int calc2 = sscanf("12.3 456", "%d %d", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_d_7) {
  int x, y, x2, y2;
  int calc = s21_sscanf(" 999999999999     456 ", "%d %d", &x, &y);
  int calc2 = sscanf(" 999999999999 456 ", "%d %d", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_d_8) {
  int x, y, x2, y2;
  int calc = s21_sscanf("-342 456", "%d %d", &x, &y);
  int calc2 = sscanf("-342 456", "%d %d", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_d_9) {
  const char* input = "-2147483648 0 2147483647";
  int value1, value2, value3, value12, value22, value32;

  int calc = s21_sscanf(input, "%d %d %d", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%d %d %d", &value12, &value22, &value32);

  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
  ck_assert_int_eq(calc, calc2);
}

START_TEST(sscanf_d_10) {
  const char* input = "9999999999999999999999";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%d", &value);
  int calc2 = sscanf(input, "%d", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_d_11) {
  const char* input = "";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%d", &value);
  int calc2 = sscanf(input, "%d", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_d_width) {
  short int x, y, x2, y2;
  int calc = s21_sscanf("123 456", "%hd %hd", &x, &y);
  int calc2 = sscanf("123 456", "%hd %hd", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_d_2_width) {
  long int value, value2;

  int calc = s21_sscanf("42", "%ld", &value);
  int calc2 = sscanf("42", "%ld", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_d_3_width) {
  const char* input = "10 20 a 30";
  int value1 = 0, value2 = 0, value22 = 0, value12 = 0;
  long int value3 = 0, value32 = 0;

  int calc = s21_sscanf(input, "%12d %1d %3ld", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%12d %1d %3ld", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_d_4_width) {
  const char* input = "hello";
  short int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%2hd", &value);
  int calc2 = sscanf(input, "%2hd", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_d_5_width) {
  short int x = 0, x2 = 0;
  long int y = 0, y2 = 0;
  int calc = s21_sscanf("12a3 456", "%2hd %1ld", &x, &y);
  int calc2 = sscanf("12a3 456", "%2hd %1ld", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_d_6_width) {
  int x = 0, x2 = 0;
  int calc = s21_sscanf("12.3 456", "%*d %d", &x);
  int calc2 = sscanf("12.3 456", "%*d %d", &x2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
}
END_TEST

START_TEST(sscanf_d_7_width) {
  int x, y, x2, y2;
  int calc = s21_sscanf(" 999999999999     456 ", "%70d %30d", &x, &y);
  int calc2 = sscanf(" 999999999999 456 ", "%70d %30d", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_d_8_width) {
  long int x, x2;
  int y, y2;
  int calc = s21_sscanf("-342 456", "%12ld %d", &x, &y);
  int calc2 = sscanf("-342 456", "%12ld %d", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_d_9_width) {
  const char* input = "-2147483648 0 2147483647";
  int value1, value12;
  short int value3, value32;

  int calc = s21_sscanf(input, "%d %*d %4hd", &value1, &value3);
  int calc2 = sscanf(input, "%d %*d %4hd", &value12, &value32);

  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value3, value32);
  ck_assert_int_eq(calc, calc2);
}

START_TEST(sscanf_d_10_width) {
  const char* input = "9999999999999999999999";

  int calc = s21_sscanf(input, "%*d");
  int calc2 = sscanf(input, "%*d");

  ck_assert_int_eq(calc, calc2);
}

START_TEST(sscanf_d_11_width) {
  const char* input = "";
  long int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%24ld", &value);
  int calc2 = sscanf(input, "%24ld", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_d_12) {
  int y, y2;
  int calc = s21_sscanf("123 456", "%*d %d", &y);
  int calc2 = sscanf("123 456", "%*d %d", &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_d_13) {
  int calc = s21_sscanf("42", "%*d");
  int calc2 = sscanf("42", "%*d");

  ck_assert_int_eq(calc, calc2);
}

Suite* s21_sscanf_d_format_suite(void) {
  Suite* s = suite_create("s21_sscanf_d");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sscanf_d_);
  tcase_add_test(tc_core, sscanf_d_2);
  tcase_add_test(tc_core, sscanf_d_3);
  tcase_add_test(tc_core, sscanf_d_4);
  tcase_add_test(tc_core, sscanf_d_5);
  tcase_add_test(tc_core, sscanf_d_6);
  tcase_add_test(tc_core, sscanf_d_7);
  tcase_add_test(tc_core, sscanf_d_8);
  tcase_add_test(tc_core, sscanf_d_9);
  tcase_add_test(tc_core, sscanf_d_10);
  tcase_add_test(tc_core, sscanf_d_11);
  tcase_add_test(tc_core, sscanf_d_12);
  tcase_add_test(tc_core, sscanf_d_13);
  tcase_add_test(tc_core, sscanf_d_width);
  tcase_add_test(tc_core, sscanf_d_2_width);
  tcase_add_test(tc_core, sscanf_d_3_width);
  tcase_add_test(tc_core, sscanf_d_4_width);
  tcase_add_test(tc_core, sscanf_d_5_width);
  tcase_add_test(tc_core, sscanf_d_6_width);
  tcase_add_test(tc_core, sscanf_d_7_width);
  tcase_add_test(tc_core, sscanf_d_8_width);
  tcase_add_test(tc_core, sscanf_d_9_width);
  tcase_add_test(tc_core, sscanf_d_10_width);
  tcase_add_test(tc_core, sscanf_d_11_width);

  suite_add_tcase(s, tc_core);

  return s;
}