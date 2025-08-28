
void ERR_unload_GOST_strings(void)

{
  if (GOST_error_init == 0) {
    ERR_unload_strings(GOST_lib_error_code,(ERR_STRING_DATA *)GOST_str_functs);
    ERR_unload_strings(GOST_lib_error_code,(ERR_STRING_DATA *)GOST_str_reasons);
    GOST_error_init = 1;
  }
  return;
}

