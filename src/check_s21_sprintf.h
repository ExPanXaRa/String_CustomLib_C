#ifndef S21_CHECK_SPRINTF
#define S21_CHECK_SPRINTF

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

Suite *s21_sprintf_c_suite(void);
Suite *s21_sprintf_d_suite(void);
Suite *s21_sprintf_u_suite(void);
Suite *s21_sprintf_f_suite(void);
Suite *s21_sprintf_g_suite(void);
Suite *s21_sprintf_e_suite(void);
Suite *s21_sprintf_o_suite(void);
Suite *s21_sprintf_x_suite(void);
Suite *s21_sprintf_p_suite(void);
Suite *s21_sprintf_s_suite(void);
Suite *s21_sprintf_i_suite(void);
Suite *s21_sprintf_other_suite(void);

#endif  // S21_CHECK_SPRINTF