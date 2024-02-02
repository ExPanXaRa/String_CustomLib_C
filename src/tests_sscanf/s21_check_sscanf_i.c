#include "../check_s21_sscanf.h"

START_TEST(sscanf_i_) {
  int x, y, x2, y2;
  int calc = s21_sscanf("0xFF 456", "%i %i", &x, &y);
  int calc2 = sscanf("0xFF 456", "%i %i", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_i_2) {
  int value, value2;

  int calc = s21_sscanf("3E8", "%i", &value);
  int calc2 = sscanf("3E8", "%i", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_3) {
  const char* input = "10 FF a 30";
  int value1 = 0, value2 = 0, value3 = 0, value12 = 0, value22 = 0, value32 = 0;

  int calc = s21_sscanf(input, "%i %i %i", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%i %i %i", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_i_4) {
  const char* input = "hello";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%i", &value);
  int calc2 = sscanf(input, "%i", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_5) {
  int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("12a3 FF", "%i %i", &x, &y);
  int calc2 = sscanf("12a3 FF", "%i %i", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_i_6) {
  int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("3E8.3 456", "%i %i", &x, &y);
  int calc2 = sscanf("3E8.3 456", "%i %i", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_i_7) {
  int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc =
      s21_sscanf(" FFFFFFFFFFFFFFFFFFFFFFFFFF     456 ", "%i %i", &x, &y);
  int calc2 = sscanf(" FFFFFFFFFFFFFFFFFFFFFFFFFF 456 ", "%i %i", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_i_8) {
  int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc = s21_sscanf("-A34 456", "%i %i", &x, &y);
  int calc2 = sscanf("-A34 456", "%i %i", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_i_9) {
  const char* input = "-0xFF 0 0xFF";
  int value1, value2, value3, value12, value22, value32;

  int calc = s21_sscanf(input, "%i %i %i", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%i %i %i", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_i_10) {
  const char* input = "9999999999999999999999";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%i", &value);
  int calc2 = sscanf(input, "%i", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_11) {
  const char* input = "";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%i", &value);
  int calc2 = sscanf(input, "%i", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_width) {
  short int x, y, x2, y2;
  int calc = s21_sscanf("0xFF 456", "%hi %hi", &x, &y);
  int calc2 = sscanf("0xFF 456", "%hi %hi", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_i_2_width) {
  long int value, value2;

  int calc = s21_sscanf("3E8", "%li", &value);
  int calc2 = sscanf("3E8", "%li", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_3_width) {
  const char* input = "10 FF a 30";
  int value1 = 0, value2 = 0, value22 = 0, value12 = 0;
  long int value3 = 0, value32 = 0;

  int calc = s21_sscanf(input, "%12i %1i %3li", &value1, &value2, &value3);
  int calc2 = sscanf(input, "%12i %1i %3li", &value12, &value22, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value2, value22);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_i_4_width) {
  const char* input = "hello";
  short int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%2hi", &value);
  int calc2 = sscanf(input, "%2hi", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_5_width) {
  short int x = 0, x2 = 0;
  long int y = 0, y2 = 0;
  int calc = s21_sscanf("12a3 FF", "%2hi %1li", &x, &y);
  int calc2 = sscanf("12a3 FF", "%2hi %1li", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_i_6_width) {
  int x = 0, x2 = 0;
  int calc = s21_sscanf("3E8.3 456", "%*i %i", &x);
  int calc2 = sscanf("3E8.3 456", "%*i %i", &x2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
}
END_TEST

START_TEST(sscanf_i_7_width) {
  int x = 0, y = 0, x2 = 0, y2 = 0;
  int calc =
      s21_sscanf(" FFFFFFFFFFFFFFFFFFFFFFFFFF     456 ", "%70i %30i", &x, &y);
  int calc2 = sscanf(" FFFFFFFFFFFFFFFFFFFFFFFFFF 456 ", "%70i %30i", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_i_8_width) {
  long int x = 0, x2 = 0;
  int y = 0, y2 = 0;
  int calc = s21_sscanf("-A34 456", "%12li %i", &x, &y);
  int calc2 = sscanf("-A34 456", "%12li %i", &x2, &y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(x, x2);
  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_i_9_width) {
  const char* input = "-0xFF 0 0xFF";
  int value1, value12;
  short int value3, value32;

  int calc = s21_sscanf(input, "%i %*i %hi", &value1, &value3);
  int calc2 = sscanf(input, "%i %*i %hi", &value12, &value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value1, value12);
  ck_assert_int_eq(value3, value32);
}

START_TEST(sscanf_i_10_width) {
  const char* input = "9999999999999999999999";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%*i");
  int calc2 = sscanf(input, "%*i");

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_11_width) {
  const char* input = "";
  long int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%23li", &value);
  int calc2 = sscanf(input, "%23li", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_12) {
  int y, y2;
  int calc = s21_sscanf("0xFF 456", "%*i %i", &y);
  int calc2 = sscanf("0xFF 456", "%*i %i", &y2);
  ck_assert_int_eq(calc, calc2);

  ck_assert_int_eq(y, y2);
}
END_TEST

START_TEST(sscanf_i_13) {
  int calc = s21_sscanf("3E8", "%*i");
  int calc2 = sscanf("3E8", "%*i");

  ck_assert_int_eq(calc, calc2);
}

START_TEST(sscanf_i_14) {
  const char* input = "055";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%i", &value);
  int calc2 = sscanf(input, "%i", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_15) {
  const char* input = "55";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%i", &value);
  int calc2 = sscanf(input, "%i", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_16) {
  const char* input = "0x55a";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%i", &value);
  int calc2 = sscanf(input, "%i", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_17) {
  const char* input = "07777777777777777777777777777777777777777777";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%i", &value);
  int calc2 = sscanf(input, "%i", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_18) {
  const char* input = "r";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%i", &value);
  int calc2 = sscanf(input, "%i", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_19) {
  const char* input = "0xFFFFFFFFFFFFFFFFFFFFFFFFF";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%i", &value);
  int calc2 = sscanf(input, "%i", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_20) {
  const char* input = "0xt";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%i", &value);
  int calc2 = sscanf(input, "%i", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

START_TEST(sscanf_i_21) {
  const char* input = "0xfffffffffffffffffffffffffffff";
  int value = -10, value2 = -10;

  int calc = s21_sscanf(input, "%i", &value);
  int calc2 = sscanf(input, "%i", &value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_int_eq(value, value2);
}

Suite* s21_sscanf_i_format_suite(void) {
  Suite* s = suite_create("s21_sscanf_i");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sscanf_i_);
  tcase_add_test(tc_core, sscanf_i_2);
  tcase_add_test(tc_core, sscanf_i_3);
  tcase_add_test(tc_core, sscanf_i_4);
  tcase_add_test(tc_core, sscanf_i_5);
  tcase_add_test(tc_core, sscanf_i_6);
  tcase_add_test(tc_core, sscanf_i_7);
  tcase_add_test(tc_core, sscanf_i_8);
  tcase_add_test(tc_core, sscanf_i_9);
  tcase_add_test(tc_core, sscanf_i_10);
  tcase_add_test(tc_core, sscanf_i_11);
  tcase_add_test(tc_core, sscanf_i_12);
  tcase_add_test(tc_core, sscanf_i_13);
  tcase_add_test(tc_core, sscanf_i_14);
  tcase_add_test(tc_core, sscanf_i_15);
  tcase_add_test(tc_core, sscanf_i_16);
  tcase_add_test(tc_core, sscanf_i_17);
  tcase_add_test(tc_core, sscanf_i_18);
  tcase_add_test(tc_core, sscanf_i_19);
  tcase_add_test(tc_core, sscanf_i_20);
  tcase_add_test(tc_core, sscanf_i_21);
  tcase_add_test(tc_core, sscanf_i_width);
  tcase_add_test(tc_core, sscanf_i_2_width);
  tcase_add_test(tc_core, sscanf_i_3_width);
  tcase_add_test(tc_core, sscanf_i_4_width);
  tcase_add_test(tc_core, sscanf_i_5_width);
  tcase_add_test(tc_core, sscanf_i_6_width);
  tcase_add_test(tc_core, sscanf_i_7_width);
  tcase_add_test(tc_core, sscanf_i_8_width);
  tcase_add_test(tc_core, sscanf_i_9_width);
  tcase_add_test(tc_core, sscanf_i_10_width);
  tcase_add_test(tc_core, sscanf_i_11_width);

  suite_add_tcase(s, tc_core);

  return s;
}