#include "../check_s21_sscanf.h"

START_TEST(sscanf_s_) {
  char x[20] = {0}, y[20] = {0}, x2[20] = {0}, y2[20] = {0};
  int calc = s21_sscanf("0xFF 456", "%s %s", x, y);
  int calc2 = sscanf("0xFF 456", "%s %s", x2, y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(x, x2);
  ck_assert_str_eq(y, y2);
}
END_TEST

START_TEST(sscanf_s_2) {
  char value[20] = {0}, value2[20] = {0};

  int calc = s21_sscanf("3E8", "%s", value);
  int calc2 = sscanf("3E8", "%s", value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value, value2);
}

START_TEST(sscanf_s_3) {
  const char* input = "10 FF a 30";
  char value1[20] = {0}, value2[20] = {0}, value3[20] = {0}, value12[20] = {0},
       value22[20] = {0}, value32[20] = {0};

  int calc = s21_sscanf(input, "%s %s %s", value1, value2, value3);
  int calc2 = sscanf(input, "%s %s %s", value12, value22, value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value1, value12);
  ck_assert_str_eq(value2, value22);
  ck_assert_str_eq(value3, value32);
}

START_TEST(sscanf_s_4) {
  const char* input = "hello";
  char value[20] = {0}, value2[20] = {0};

  int calc = s21_sscanf(input, "%s", value);
  int calc2 = sscanf(input, "%s", value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value, value2);
}

START_TEST(sscanf_s_5) {
  const char* input = "";
  char value[20] = {0}, value2[20] = {0};

  int calc = s21_sscanf(input, "%s", value);
  int calc2 = sscanf(input, "%s", value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value, value2);
}

START_TEST(sscanf_s_6) {
  const char* input = "10 FF a 30";
  char value1[20] = {0}, value2[20] = {0}, value3[20] = {0}, value12[20] = {0},
       value22[20] = {0}, value32[20] = {0};

  int calc = s21_sscanf(input, "%s%s %s", value1, value2, value3);
  int calc2 = sscanf(input, "%s%s %s", value12, value22, value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value1, value12);
  ck_assert_str_eq(value2, value22);
  ck_assert_str_eq(value3, value32);
}

START_TEST(sscanf_s_7) {
  const char* input = "Hello 10 FF, a 30";
  char value1[20] = {0}, value2[20] = {0}, value3[20] = {0}, value12[20] = {0},
       value22[20] = {0}, value32[20] = {0};

  int calc = s21_sscanf(input, "Hello %s %s, %s", value1, value2, value3);
  int calc2 = sscanf(input, "Hello %s %s, %s", value12, value22, value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value1, value12);
  ck_assert_str_eq(value2, value22);
  ck_assert_str_eq(value3, value32);
}

START_TEST(sscanf_s_8) {
  const char* input = "10";
  char value1[20] = {0}, value2[20] = {0}, value3[20] = {0}, value12[20] = {0},
       value22[20] = {0}, value32[20] = {0};

  int calc = s21_sscanf(input, "%s %s %s", value1, value2, value3);
  int calc2 = sscanf(input, "%s %s %s", value12, value22, value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value1, value12);
  ck_assert_str_eq(value2, value22);
  ck_assert_str_eq(value3, value32);
}

START_TEST(sscanf_s_9) {
  const char* input = "10765765ufhfdjghdghfkglkjgkjgdhgfsf FF a 30";
  char value1[40] = {0}, value2[40] = {0}, value3[40] = {0}, value12[40] = {0},
       value22[40] = {0}, value32[40] = {0};

  int calc = s21_sscanf(input, "%s %s %s", value1, value2, value3);
  int calc2 = sscanf(input, "%s %s %s", value12, value22, value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value1, value12);
  ck_assert_str_eq(value2, value22);
  ck_assert_str_eq(value3, value32);
}

START_TEST(sscanf_s_10) {
  const char* input = "sadfsadf\tafasdfasd\tadfsadfsadf\tadfsdaf a 30";
  char value2[20] = {0}, value3[20] = {0}, value22[20] = {0}, value32[20] = {0};

  int calc = s21_sscanf(input, "%*s%s%s", value2, value3);
  int calc2 = sscanf(input, "%*s%s%s", value22, value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value2, value22);
  ck_assert_str_eq(value3, value32);
}

START_TEST(sscanf_s_width) {
  char x[20] = {0}, x2[20] = {0};
  char y[20] = {0}, y2[20] = {0};
  int calc = s21_sscanf("0xFF 456", "%4s %1s", x, y);
  int calc2 = sscanf("0xFF 456", "%4s %1s", x2, y2);
  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(x, x2);
  ck_assert_str_eq(y, y2);
}
END_TEST

START_TEST(sscanf_s_2_width) {
  char value[20] = {0}, value2[20] = {0};

  int calc = s21_sscanf("3E8", "%10s", value);
  int calc2 = sscanf("3E8", "%10s", value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value, value2);
}

START_TEST(sscanf_s_3_width) {
  const char* input = "10 FF a 30";
  char value1[20] = {0}, value2[20] = {0}, value3[20] = {0}, value12[20] = {0},
       value22[20] = {0}, value32[20] = {0};

  int calc = s21_sscanf(input, "%4s %4s %s", value1, value2, value3);
  int calc2 = sscanf(input, "%4s %4s %s", value12, value22, value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value1, value12);
  ck_assert_str_eq(value2, value22);
  ck_assert_str_eq(value3, value32);
}

START_TEST(sscanf_s_4_width) {
  const char* input = "hello";
  char value[20] = {0}, value2[20] = {0};

  int calc = s21_sscanf(input, "%20s", value);
  int calc2 = sscanf(input, "%20s", value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value, value2);
}

START_TEST(sscanf_s_5_width) {
  const char* input = "";
  char value[20] = {0}, value2[20] = {0};

  int calc = s21_sscanf(input, "%12s", value);
  int calc2 = sscanf(input, "%12s", value2);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value, value2);
}

START_TEST(sscanf_s_6_width) {
  const char* input = "10 FF a 30";
  char value1[20] = {0}, value2[20] = {0}, value3[20] = {0}, value12[20] = {0},
       value22[20] = {0}, value32[20] = {0};

  int calc = s21_sscanf(input, "%2s%s %s", value1, value2, value3);
  int calc2 = sscanf(input, "%2s%s %s", value12, value22, value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value1, value12);
  ck_assert_str_eq(value2, value22);
  ck_assert_str_eq(value3, value32);
}

START_TEST(sscanf_s_7_width) {
  const char* input = "Hello 10 FF, a 30";
  char value1[20] = {0}, value2[20] = {0}, value3[20] = {0}, value12[20] = {0},
       value22[20] = {0}, value32[20] = {0};

  int calc = s21_sscanf(input, "Hello %13s %2s, %1s", value1, value2, value3);
  int calc2 = sscanf(input, "Hello %13s %2s, %1s", value12, value22, value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value1, value12);
  ck_assert_str_eq(value2, value22);
  ck_assert_str_eq(value3, value32);
}

START_TEST(sscanf_s_8_width) {
  const char* input = "10";
  char value1[20] = {0}, value2[20] = {0}, value3[20] = {0}, value12[20] = {0},
       value22[20] = {0}, value32[20] = {0};

  int calc = s21_sscanf(input, "%12s %12s %s", value1, value2, value3);
  int calc2 = sscanf(input, "%12s %12s %s", value12, value22, value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value1, value12);
  ck_assert_str_eq(value2, value22);
  ck_assert_str_eq(value3, value32);
}

START_TEST(sscanf_s_9_width) {
  const char* input = "10765765ufhfdjghdghfkglkjgkjgdhgfsf FF a 30";
  char value1[20] = {0}, value2[20] = {0}, value3[20] = {0}, value12[20] = {0},
       value22[20] = {0}, value32[20] = {0};

  int calc = s21_sscanf(input, "%3s %3s %3s", value1, value2, value3);
  int calc2 = sscanf(input, "%3s %3s %3s", value12, value22, value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value1, value12);
  ck_assert_str_eq(value2, value22);
  ck_assert_str_eq(value3, value32);
}

START_TEST(sscanf_s_10_width) {
  const char* input = "sadfsadf\tafasdfasd\tadfsadfsadf\tadfsdaf a 30";
  char value2[20] = {0}, value3[20] = {0}, value22[20] = {0}, value32[20] = {0};

  int calc = s21_sscanf(input, "%*s%12s%s", value2, value3);
  int calc2 = sscanf(input, "%*s%12s%s", value22, value32);

  ck_assert_int_eq(calc, calc2);
  ck_assert_str_eq(value2, value22);
  ck_assert_str_eq(value3, value32);
}

Suite* s21_sscanf_s_format_suite(void) {
  Suite* s = suite_create("s21_sscanf_s");
  TCase* tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sscanf_s_);
  tcase_add_test(tc_core, sscanf_s_2);
  tcase_add_test(tc_core, sscanf_s_3);
  tcase_add_test(tc_core, sscanf_s_4);
  tcase_add_test(tc_core, sscanf_s_5);
  tcase_add_test(tc_core, sscanf_s_6);
  tcase_add_test(tc_core, sscanf_s_7);
  tcase_add_test(tc_core, sscanf_s_8);
  tcase_add_test(tc_core, sscanf_s_9);
  tcase_add_test(tc_core, sscanf_s_10);
  tcase_add_test(tc_core, sscanf_s_width);
  tcase_add_test(tc_core, sscanf_s_2_width);
  tcase_add_test(tc_core, sscanf_s_3_width);
  tcase_add_test(tc_core, sscanf_s_4_width);
  tcase_add_test(tc_core, sscanf_s_5_width);
  tcase_add_test(tc_core, sscanf_s_6_width);
  tcase_add_test(tc_core, sscanf_s_7_width);
  tcase_add_test(tc_core, sscanf_s_8_width);
  tcase_add_test(tc_core, sscanf_s_9_width);
  tcase_add_test(tc_core, sscanf_s_10_width);

  suite_add_tcase(s, tc_core);

  return s;
}