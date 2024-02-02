#include "../check_s21_sscanf.h"

START_TEST(sscanf_c_) {
  char x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("123 456", "%c %c", &x, &y);
  int calc2 = sscanf("123 456", "%c %c", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_c_2) {
  char value = 0, value2 = 0;

  int calc = s21_sscanf("42", "%c", &value);
  int calc2 = sscanf("42", "%c", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_c_3) {
  const char* input = "10 20 a 30";
  char value1 = 0, value2 = 0, value3 = 0, value12 = 0, value22 = 0,
       value32 = 0;

  int calc = s21_sscanf(input, "%c %c%c", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%c %c%c", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_c_4) {
  const char* input = "hello";
  char value = 0, value2 = 0;

  int calc = s21_sscanf(input, "%c", &value);
  int calc2 = sscanf(input, "%c", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_c_5) {
  char x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("12a3 456", "%c %c", &x, &y);
  int calc2 = sscanf("12a3 456", "%c %c", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_c_6) {
  char x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("12.3 456", "%c %c", &x, &y);
  int calc2 = sscanf("12.3 456", "%c %c", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_c_7) {
  char x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf(" 999999999999 456 ", "%c %c", &x, &y);
  int calc2 = sscanf(" 999999999999 456 ", "%c %c", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_c_8) {
  char x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("-342 456", " %c %c", &x, &y);
  int calc2 = sscanf("-342 456", " %c %c", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_c_9) {
  const char* input = "-2,147483648 0 2147483647";
  char value1 = 0, value2 = 0, value3 = 0, value12 = 0, value22 = 0,
       value32 = 0;

  int calc = s21_sscanf(input, "%c %c, %c", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%c %c, %c", &value12, &value22, &value32);

  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
  ck_assert_int_eq(calc, calc2);
}

START_TEST(sscanf_c_10) {
  const char* input = "a";
  char value1 = 0, value12 = 0, value2 = 0, value22 = 0;

  int calc = s21_sscanf(input, "%c %c", &value1, &value2);
  int calc2 = sscanf(input, "%c %c", &value12, &value22);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
}

START_TEST(sscanf_c_11) {
  const char* input = "";
  char value = 0, value2 = 0;

  int calc = s21_sscanf(input, "%c", &value);
  int calc2 = sscanf(input, "%c", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_c_2_width) {
  char value = 0, value2 = 0;

  int calc2 = sscanf("42", "%22c", &value2);
  int calc = s21_sscanf("42", "%22c", &value);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_c_3_width) {
  const char* input = "10 20 a 30";
  char value1 = 0, value12 = 0;
  char value2 = 0, value22 = 0, value3 = 0, value32 = 0;

  int calc = s21_sscanf(input, "%c %c%c", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%c %c%c", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_c_4_width) {
  const char* input = "hello";
  char value = 0, value2 = 0;

  int calc = s21_sscanf(input, "%c", &value);
  int calc2 = sscanf(input, "%c", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_c_5_width) {
  char x = 0, x2 = 0;
  char y = 0, y2 = 0;
  int calc2 = sscanf("12a3 456", "%3c %c", &x2, &y2);
  int calc = s21_sscanf("12a3 456", "%3c %c", &x, &y);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_c_6_width) {
  char y = 0, y2 = 0;
  int calc = s21_sscanf("12.3 456", "%*c %c", &y);
  int calc2 = sscanf("12.3 456", "%*c %c", &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_c_7_width) {
  char x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf(" 999999999999     456 ", "%*c %*c");
  int calc2 = sscanf(" 999999999999 456 ", "%*c %*c");
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_c_8_width) {
  const char* input = "a";
  char value1 = 0, value12 = 0, value2 = 0, value22 = 0;

  int calc2 = sscanf(input, "%5c %5c", &value12, &value22);
  int calc = s21_sscanf(input, "%5c %5c", &value1, &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
}

START_TEST(sscanf_c_9_width) {
  const char* input = "";
  char value = 0, value2 = 0;

  int calc = s21_sscanf(input, "%3c", &value);
  int calc2 = sscanf(input, "%3c", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

Suite* s21_sscanf_c_format_suite(void) {
  Suite* s = suite_create("s21_sscanf_c");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sscanf_c_);
  tcase_add_test(tc_core, sscanf_c_2);
  tcase_add_test(tc_core, sscanf_c_3);
  tcase_add_test(tc_core, sscanf_c_4);
  tcase_add_test(tc_core, sscanf_c_5);
  tcase_add_test(tc_core, sscanf_c_6);
  tcase_add_test(tc_core, sscanf_c_7);
  tcase_add_test(tc_core, sscanf_c_8);
  tcase_add_test(tc_core, sscanf_c_9);
  tcase_add_test(tc_core, sscanf_c_10);
  tcase_add_test(tc_core, sscanf_c_11);
  tcase_add_test(tc_core, sscanf_c_2_width);
  tcase_add_test(tc_core, sscanf_c_3_width);
  tcase_add_test(tc_core, sscanf_c_4_width);
  tcase_add_test(tc_core, sscanf_c_5_width);
  tcase_add_test(tc_core, sscanf_c_6_width);
  tcase_add_test(tc_core, sscanf_c_7_width);
  tcase_add_test(tc_core, sscanf_c_8_width);
  tcase_add_test(tc_core, sscanf_c_9_width);

  suite_add_tcase(s, tc_core);

  return s;
}