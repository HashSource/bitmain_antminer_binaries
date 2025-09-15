
undefined4 hwcrhk_destroy(void)

{
  if (HWCRHK_LIBNAME != (void *)0x0) {
    CRYPTO_free(HWCRHK_LIBNAME);
  }
  HWCRHK_LIBNAME = (void *)0x0;
  if (HWCRHK_error_init == 0) {
    ERR_unload_strings(HWCRHK_lib_error_code,(ERR_STRING_DATA *)HWCRHK_str_functs);
    ERR_unload_strings(HWCRHK_lib_error_code,(ERR_STRING_DATA *)HWCRHK_str_reasons);
    ERR_unload_strings(0,(ERR_STRING_DATA *)HWCRHK_lib_name);
    HWCRHK_error_init = 1;
  }
  return 1;
}

