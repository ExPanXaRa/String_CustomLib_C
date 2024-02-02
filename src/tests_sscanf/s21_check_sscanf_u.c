#include "../check_s21_sscanf.h"

START_TEST(sscanf_u_) {
  unsigned int x, y, x2, y2;
  int calc = s21_sscanf("123 456", "%u %u", &x, &y);
  int calc2 = sscanf("123 456", "%u %u", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_u_2) {
  unsigned int value, value2;

  int calc = s21_sscanf("42", "%u", &value);
  int calc2 = sscanf("42", "%u", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_u_3) {
  const char* input = "10 20 a 30";
  unsigned int value1 = 0, value2 = 0, value3 = 0, value12 = 0, value22 = 0,
               value32 = 0;

  int calc = s21_sscanf(input, "%u %u %u", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%u %u %u", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_u_4) {
  const char* input = "hello";
  unsigned int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%u", &value);
  int calc2 = sscanf(input, "%u", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_u_5) {
  unsigned int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("12a3 456", "%u %u", &x, &y);
  int calc2 = sscanf("12a3 456", "%u %u", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_u_6) {
  unsigned int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("12.3 456", "%u %u", &x, &y);
  int calc2 = sscanf("12.3 456", "%u %u", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_u_7) {
  unsigned int x, y, x2, y2;
  int calc = s21_sscanf(" 999999999999     456 ", "%u %u", &x, &y);
  int calc2 = sscanf(" 999999999999 456 ", "%u %u", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_u_8) {
  unsigned int x, y, x2, y2;
  int calc = s21_sscanf("-342 456", "%u %u", &x, &y);
  int calc2 = sscanf("-342 456", "%u %u", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_u_9) {
  const char* input = "-2147483648 0 2147483647";
  unsigned int value1, value2, value3, value12, value22, value32;

  int calc = s21_sscanf(input, "%u %u %u", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%u %u %u", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_u_10) {
  const char* input = "9999999999999999999999";
  unsigned int value = 0, value2 = 0;

  int calc = s21_sscanf(input, "%u", &value);
  int calc2 = sscanf(input, "%u", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_u_11) {
  const char* input = "";
  unsigned int value = 0, value2 = 0;

  int calc = s21_sscanf(input, "%u", &value);
  int calc2 = sscanf(input, "%u", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_u_width) {
  unsigned short int x, y, x2, y2;
  int calc = s21_sscanf("123 456", "%hu %hu", &x, &y);
  int calc2 = sscanf("123 456", "%hu %hu", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_u_2_width) {
  unsigned long int value, value2;

  int calc = s21_sscanf("42", "%lu", &value);
  int calc2 = sscanf("42", "%lu", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_u_3_width) {
  const char* input = "10 20 a 30";
  unsigned int value1 = 0, value2 = 0, value22 = 0, value12 = 0;
  unsigned long int value3 = 0, value32 = 0;

  int calc = s21_sscanf(input, "%12u %1u %3lu", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%12u %1u %3lu", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_u_4_width) {
  const char* input = "hello";
  unsigned short int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%2hu", &value);
  int calc2 = sscanf(input, "%2hu", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_u_5_width) {
  unsigned short int x = 0, x2 = 0;
  unsigned long int y = 0, y2 = 0;
  int calc = s21_sscanf("12a3 456", "%2hu %1lu", &x, &y);
  int calc2 = sscanf("12a3 456", "%2hu %1lu", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_u_6_width) {
  unsigned int x = 0, x2 = 0;
  int calc = s21_sscanf("12.3 456", "%*u %u", &x);
  int calc2 = sscanf("12.3 456", "%*u %u", &x2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
}
END_TEST

START_TEST(sscanf_u_7_width) {
  unsigned int x, y, x2, y2;
  int calc = s21_sscanf(" 999999999999     456 ", "%70u %30u", &x, &y);
  int calc2 = sscanf(" 999999999999 456 ", "%70u %30u", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_u_8_width) {
  unsigned long int x, x2;
  unsigned int y, y2;
  int calc = s21_sscanf("-342 456", "%12lu %u", &x, &y);
  int calc2 = sscanf("-342 456", "%12lu %u", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_u_9_width) {
  const char* input = "-2147483648 0 2147483647";
  unsigned int value1, value12;
  unsigned short int value3, value32;

  int calc = s21_sscanf(input, "%u %*u %4hu", &value1, &value3);
  int calc2 = sscanf(input, "%u %*u %4hu", &value12, &value32);

  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value3, value32);
  ck_assert_int_eq(calc, calc2);
}

START_TEST(sscanf_u_10_width) {
  const char* input = "9999999999999999999999";

  int calc = s21_sscanf(input, "%*u");
  int calc2 = sscanf(input, "%*u");

  ck_assert_int_eq(calc, calc2);
}

START_TEST(sscanf_u_11_width) {
  const char* input = "";
  unsigned long int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%24lu", &value);
  int calc2 = sscanf(input, "%24lu", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

Suite* s21_sscanf_u_format_suite(void) {
  Suite* s = suite_create("s21_sscanf_u");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sscanf_u_);
  tcase_add_test(tc_core, sscanf_u_2);
  tcase_add_test(tc_core, sscanf_u_3);
  tcase_add_test(tc_core, sscanf_u_4);
  tcase_add_test(tc_core, sscanf_u_5);
  tcase_add_test(tc_core, sscanf_u_6);
  tcase_add_test(tc_core, sscanf_u_7);
  tcase_add_test(tc_core, sscanf_u_8);
  tcase_add_test(tc_core, sscanf_u_9);
  tcase_add_test(tc_core, sscanf_u_10);
  tcase_add_test(tc_core, sscanf_u_11);
  tcase_add_test(tc_core, sscanf_u_width);
  tcase_add_test(tc_core, sscanf_u_2_width);
  tcase_add_test(tc_core, sscanf_u_3_width);
  tcase_add_test(tc_core, sscanf_u_4_width);
  tcase_add_test(tc_core, sscanf_u_5_width);
  tcase_add_test(tc_core, sscanf_u_6_width);
  tcase_add_test(tc_core, sscanf_u_7_width);
  tcase_add_test(tc_core, sscanf_u_8_width);
  tcase_add_test(tc_core, sscanf_u_9_width);
  tcase_add_test(tc_core, sscanf_u_10_width);
  tcase_add_test(tc_core, sscanf_u_11_width);

  suite_add_tcase(s, tc_core);

  return s;
}