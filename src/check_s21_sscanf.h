#ifndef S21_CHECK_SSCANF
#define S21_CHECK_SSCANF

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

Suite *s21_sscanf_d_format_suite(void);
Suite *s21_sscanf_i_format_suite(void);
Suite *s21_sscanf_u_format_suite(void);
Suite *s21_sscanf_o_format_suite(void);
Suite *s21_sscanf_x_format_suite(void);
Suite *s21_sscanf_n_format_suite(void);
Suite *s21_sscanf_s_format_suite(void);
Suite *s21_sscanf_c_format_suite(void);
Suite *s21_sscanf_e_format_suite(void);
Suite *s21_sscanf_p_format_suite(void);

#endif  // S21_CHECK_SSCANF