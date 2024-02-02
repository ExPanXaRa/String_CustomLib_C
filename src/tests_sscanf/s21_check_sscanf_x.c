#include "../check_s21_sscanf.h"

START_TEST(sscanf_x_) {
  unsigned int x, y, x2, y2;
  int calc = s21_sscanf("fFfF 456", "%x %x", &x, &y);
  int calc2 = sscanf("fFfF 456", "%x %x", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_x_2) {
  unsigned int value, value2;

  int calc = s21_sscanf("aA313Ff", "%x", &value);
  int calc2 = sscanf("aA313Ff", "%x", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_x_3) {
  const char* input = "10 Af72 a 30";
  unsigned int value1 = 0, value2 = 0, value3 = 0, value12 = 0, value22 = 0,
               value32 = 0;

  int calc = s21_sscanf(input, "%x %x %x", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%x %x %x", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_x_4) {
  const char* input = "hello";
  unsigned int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%x", &value);
  int calc2 = sscanf(input, "%x", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_x_5) {
  unsigned int x, y, x2, y2;
  int calc = s21_sscanf("0xA 456", "%x %x", &x, &y);
  int calc2 = sscanf("0xA 456", "%x %x", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_x_6) {
  unsigned int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("0xF.3 456", "%x %x", &x, &y);
  int calc2 = sscanf("0xF.3 456", "%x %x", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_x_7) {
  unsigned int x, y, x2, y2;
  int calc = s21_sscanf(" FFFFFFFFFFFFFFFFFFFFFF     456 ", "%x %x", &x, &y);
  int calc2 = sscanf(" FFFFFFFFFFFFFFFFFFFFFF 456 ", "%x %x", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_x_8) {
  unsigned int x, y, x2, y2;
  int calc = s21_sscanf("-3fFfF 456", "%x %x", &x, &y);
  int calc2 = sscanf("-3fFfF 456", "%x %x", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_x_9) {
  const char* input = "-2147483648 0 2147483647";
  unsigned int value1, value2, value3, value12, value22, value32;

  int calc = s21_sscanf(input, "%x %x %x", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%x %x %x", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_x_10) {
  const char* input = "fFfFfFfFaAaF326523645";
  unsigned int value = 0, value2 = 0;

  int calc = s21_sscanf(input, "%x", &value);
  int calc2 = sscanf(input, "%x", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_x_11) {
  const char* input = "";
  unsigned int value = 0, value2 = 0;

  int calc = s21_sscanf(input, "%x", &value);
  int calc2 = sscanf(input, "%x", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_x_12) {
  const char* input = "fFfFfFfFaAaF326523645";
  unsigned int value = 0, value2 = 0;

  int calc = s21_sscanf(input, "%X", &value);
  int calc2 = sscanf(input, "%X", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_x_13) {
  const char* input = "fffffffffffffffffffffffffff";
  unsigned int value = 0, value2 = 0;

  int calc = s21_sscanf(input, "%X", &value);
  int calc2 = sscanf(input, "%X", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_x_width) {
  unsigned short int x, y, x2, y2;
  int calc = s21_sscanf("0xFF 456", "%hx %hx", &x, &y);
  int calc2 = sscanf("0xFF 456", "%hx %hx", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_x_2_width) {
  unsigned long int value, value2;

  int calc = s21_sscanf("3E8", "%lx", &value);
  int calc2 = sscanf("3E8", "%lx", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_x_3_width) {
  const char* input = "10 FF a 30";
  unsigned int value1 = 0, value2 = 0, value22 = 0, value12 = 0;
  unsigned long int value3 = 0, value32 = 0;

  int calc = s21_sscanf(input, "%12x %1x %3lx", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%12x %1x %3lx", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_x_4_width) {
  const char* input = "hello";
  unsigned short int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%2hx", &value);
  int calc2 = sscanf(input, "%2hx", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_x_5_width) {
  unsigned short int x = 0, x2 = 0;
  unsigned long int y = 0, y2 = 0;
  int calc = s21_sscanf("12a3 FF", "%2hx %1lx", &x, &y);
  int calc2 = sscanf("12a3 FF", "%2hx %1lx", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_x_6_width) {
  unsigned int x = 0, x2 = 0;
  int calc = s21_sscanf("3E8.3 456", "%*x %x", &x);
  int calc2 = sscanf("3E8.3 456", "%*x %x", &x2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
}
END_TEST

START_TEST(sscanf_x_7_width) {
  unsigned int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc =
      s21_sscanf(" FFFFFFFFFFFFFFFFFFFFFFFFFF     456 ", "%70x %30x", &x, &y);
  int calc2 = sscanf(" FFFFFFFFFFFFFFFFFFFFFFFFFF 456 ", "%70x %30x", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_x_8_width) {
  unsigned long int x = 0, x2 = 0;
  unsigned int y = 0, y2 = 0;
  int calc = s21_sscanf("-A34 456", "%12lx %x", &x, &y);
  int calc2 = sscanf("-A34 456", "%12lx %x", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_x_9_width) {
  const char* input = "-0xFF 0 0xFF";
  unsigned int value1, value12;
  unsigned short int value3, value32;

  int calc = s21_sscanf(input, "%x %*x %hx", &value1, &value3);
  int calc2 = sscanf(input, "%x %*x %hx", &value12, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_x_10_width) {
  const char* input = "9999999999999999999999";
  unsigned int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%*x");
  int calc2 = sscanf(input, "%*x");

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_x_11_width) {
  const char* input = "";
  unsigned long int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%23lx", &value);
  int calc2 = sscanf(input, "%23lx", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

Suite* s21_sscanf_x_format_suite(void) {
  Suite* s = suite_create("s21_sscanf_x_X");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sscanf_x_);
  tcase_add_test(tc_core, sscanf_x_2);
  tcase_add_test(tc_core, sscanf_x_3);
  tcase_add_test(tc_core, sscanf_x_4);
  tcase_add_test(tc_core, sscanf_x_5);
  tcase_add_test(tc_core, sscanf_x_6);
  tcase_add_test(tc_core, sscanf_x_7);
  tcase_add_test(tc_core, sscanf_x_8);
  tcase_add_test(tc_core, sscanf_x_9);
  tcase_add_test(tc_core, sscanf_x_10);
  tcase_add_test(tc_core, sscanf_x_11);
  tcase_add_test(tc_core, sscanf_x_12);
  tcase_add_test(tc_core, sscanf_x_13);
  tcase_add_test(tc_core, sscanf_x_width);
  tcase_add_test(tc_core, sscanf_x_2_width);
  tcase_add_test(tc_core, sscanf_x_3_width);
  tcase_add_test(tc_core, sscanf_x_4_width);
  tcase_add_test(tc_core, sscanf_x_5_width);
  tcase_add_test(tc_core, sscanf_x_6_width);
  tcase_add_test(tc_core, sscanf_x_7_width);
  tcase_add_test(tc_core, sscanf_x_8_width);
  tcase_add_test(tc_core, sscanf_x_9_width);
  tcase_add_test(tc_core, sscanf_x_10_width);
  tcase_add_test(tc_core, sscanf_x_11_width);

  suite_add_tcase(s, tc_core);

  return s;
}