
undefined4 surewarehk_destroy(void)

{
  if (SUREWARE_error_init == 0) {
    ERR_unload_strings(SUREWARE_lib_error_code,(ERR_STRING_DATA *)SUREWARE_str_functs);
    ERR_unload_strings(SUREWARE_lib_error_code,(ERR_STRING_DATA *)SUREWARE_str_reasons);
    ERR_unload_strings(0,(ERR_STRING_DATA *)SUREWARE_lib_name);
    SUREWARE_error_init = 1;
  }
  return 1;
}

