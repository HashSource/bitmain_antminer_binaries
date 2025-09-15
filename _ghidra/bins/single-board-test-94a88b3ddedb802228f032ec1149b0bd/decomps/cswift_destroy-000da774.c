
undefined4 cswift_destroy(void)

{
  if (CSWIFT_LIBNAME != (void *)0x0) {
    CRYPTO_free(CSWIFT_LIBNAME);
  }
  CSWIFT_LIBNAME = (void *)0x0;
  if (CSWIFT_error_init == 0) {
    ERR_unload_strings(CSWIFT_lib_error_code,(ERR_STRING_DATA *)CSWIFT_str_functs);
    ERR_unload_strings(CSWIFT_lib_error_code,(ERR_STRING_DATA *)CSWIFT_str_reasons);
    ERR_unload_strings(0,(ERR_STRING_DATA *)CSWIFT_lib_name);
    CSWIFT_error_init = 1;
  }
  return 1;
}

