
void ERR_load_GOST_strings(void)

{
  if (GOST_lib_error_code == 0) {
    GOST_lib_error_code = ERR_get_next_error_library();
  }
  if (GOST_error_init == 0) {
    return;
  }
  GOST_error_init = 0;
  ERR_load_strings(GOST_lib_error_code,(ERR_STRING_DATA *)GOST_str_functs);
  ERR_load_strings(GOST_lib_error_code,(ERR_STRING_DATA *)GOST_str_reasons);
  return;
}

