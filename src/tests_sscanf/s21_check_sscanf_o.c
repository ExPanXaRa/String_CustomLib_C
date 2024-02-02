#include "../check_s21_sscanf.h"

START_TEST(sscan_o_) {
  unsigned int x, y, x2, y2;
  int calc = s21_sscanf("123 456", "%o %o", &x, &y);
  int calc2 = sscanf("123 456", "%o %o", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscan_o_2) {
  unsigned int value, value2;

  int calc = s21_sscanf("42", "%o", &value);
  int calc2 = sscanf("42", "%o", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscan_o_3) {
  const char* input = "10 20 a 30";
  unsigned int value1 = 0, value2 = 0, value3 = 0, value12 = 0, value22 = 0,
               value32 = 0;

  int calc = s21_sscanf(input, "%o %o %o", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%o %o %o", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscan_o_4) {
  const char* input = "hello";
  unsigned int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%o", &value);
  int calc2 = sscanf(input, "%o", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscan_o_5) {
  unsigned int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("12a3 456", "%o %o", &x, &y);
  int calc2 = sscanf("12a3 456", "%o %o", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscan_o_6) {
  unsigned int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("12.3 456", "%o %o", &x, &y);
  int calc2 = sscanf("12.3 456", "%o %o", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscan_o_7) {
  unsigned int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf(" 999999999999     456 ", "%o %o", &x, &y);
  int calc2 = sscanf(" 999999999999 456 ", "%o %o", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscan_o_8) {
  unsigned int x, y, x2, y2;
  int calc = s21_sscanf("-342 456", "%o %o", &x, &y);
  int calc2 = sscanf("-342 456", "%o %o", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscan_o_9) {
  const char* input = "-2147483648 0 2147483647";
  unsigned int value1 = 0, value2 = 0, value3 = 0, value12 = 0, value22 = 0,
               value32 = 0;

  int calc = s21_sscanf(input, "%o %o %o", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%o %o %o", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscan_o_10) {
  const char* input = "9999999999999999999999";
  unsigned int value = 0, value2 = 0;

  int calc = s21_sscanf(input, "%o", &value);
  int calc2 = sscanf(input, "%o", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscan_o_11) {
  const char* input = "";
  unsigned int value = 0, value2 = 0;

  int calc = s21_sscanf(input, "%o", &value);
  int calc2 = sscanf(input, "%o", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscan_o_15) {
  const char* input = "07777777777777777";
  unsigned int value = 0, value2 = 0;

  int calc = s21_sscanf(input, "%o", &value);
  int calc2 = sscanf(input, "%o", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_o_width) {
  unsigned short int x, y, x2, y2;
  int calc = s21_sscanf("123 456", "%ho %ho", &x, &y);
  int calc2 = sscanf("123 456", "%ho %ho", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_o_2_width) {
  unsigned long int value, value2;

  int calc = s21_sscanf("42", "%lo", &value);
  int calc2 = sscanf("42", "%lo", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_o_3_width) {
  const char* input = "10 20 a 30";
  unsigned int value1 = 0, value2 = 0, value22 = 0, value12 = 0;
  unsigned long int value3 = 0, value32 = 0;

  int calc = s21_sscanf(input, "%12o %1o %3lo", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%12o %1o %3lo", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_o_4_width) {
  const char* input = "hello";
  unsigned short int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%2ho", &value);
  int calc2 = sscanf(input, "%2ho", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_o_5_width) {
  unsigned short int x = 0, x2 = 0;
  unsigned long int y = 0, y2 = 0;
  int calc = s21_sscanf("12a3 456", "%2ho %1lo", &x, &y);
  int calc2 = sscanf("12a3 456", "%2ho %1lo", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_o_6_width) {
  unsigned int x = 0, x2 = 0;
  int calc = s21_sscanf("12.3 456", "%*o %o", &x);
  int calc2 = sscanf("12.3 456", "%*o %o", &x2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
}
END_TEST

START_TEST(sscanf_o_7_width) {
  unsigned int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf(" 999999999999     456 ", "%70o %30o", &x, &y);
  int calc2 = sscanf(" 999999999999 456 ", "%70o %30o", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_o_8_width) {
  unsigned long int x, x2;
  unsigned int y, y2;
  int calc = s21_sscanf("-342 456", "%12lo %o", &x, &y);
  int calc2 = sscanf("-342 456", "%12lo %o", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_o_9_width) {
  const char* input = "-2147483648 0 2147483647";
  unsigned int value1 = 0, value12 = 0;
  unsigned short int value3 = 0, value32 = 0;

  int calc = s21_sscanf(input, "%o %*o %4ho", &value1, &value3);
  int calc2 = sscanf(input, "%o %*o %4ho", &value12, &value32);

  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value3, value32);
  ck_assert_int_eq(calc, calc2);
}

START_TEST(sscanf_o_10_width) {
  const char* input = "9999999999999999999999";

  int calc = s21_sscanf(input, "%*o");
  int calc2 = sscanf(input, "%*o");

  ck_assert_int_eq(calc, calc2);
}

START_TEST(sscanf_o_11_width) {
  const char* input = "";
  unsigned long int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%24lo", &value);
  int calc2 = sscanf(input, "%24lo", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscan_o_12) {
  unsigned int y, y2;
  int calc = s21_sscanf("123 456", "%*o %o", &y);
  int calc2 = sscanf("123 456", "%*o %o", &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscan_o_13) {
  int calc = s21_sscanf("42", "%*o");
  int calc2 = sscanf("42", "%*o");

  ck_assert_int_eq(calc, calc2);
}

Suite* s21_sscanf_o_format_suite(void) {
  Suite* s = suite_create("s21_sscanf_o");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sscan_o_);
  tcase_add_test(tc_core, sscan_o_2);
  tcase_add_test(tc_core, sscan_o_3);
  tcase_add_test(tc_core, sscan_o_4);
  tcase_add_test(tc_core, sscan_o_5);
  tcase_add_test(tc_core, sscan_o_6);
  tcase_add_test(tc_core, sscan_o_7);
  tcase_add_test(tc_core, sscan_o_8);
  tcase_add_test(tc_core, sscan_o_9);
  tcase_add_test(tc_core, sscan_o_10);
  tcase_add_test(tc_core, sscan_o_11);
  tcase_add_test(tc_core, sscan_o_12);
  tcase_add_test(tc_core, sscan_o_13);
  tcase_add_test(tc_core, sscan_o_15);
  tcase_add_test(tc_core, sscanf_o_width);
  tcase_add_test(tc_core, sscanf_o_2_width);
  tcase_add_test(tc_core, sscanf_o_3_width);
  tcase_add_test(tc_core, sscanf_o_4_width);
  tcase_add_test(tc_core, sscanf_o_5_width);
  tcase_add_test(tc_core, sscanf_o_6_width);
  tcase_add_test(tc_core, sscanf_o_7_width);
  tcase_add_test(tc_core, sscanf_o_8_width);
  tcase_add_test(tc_core, sscanf_o_9_width);
  tcase_add_test(tc_core, sscanf_o_10_width);
  tcase_add_test(tc_core, sscanf_o_11_width);

  suite_add_tcase(s, tc_core);

  return s;
}