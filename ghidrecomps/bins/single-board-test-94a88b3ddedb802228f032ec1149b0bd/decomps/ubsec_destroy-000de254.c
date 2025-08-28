
undefined4 ubsec_destroy(void)

{
  if (UBSEC_LIBNAME != (void *)0x0) {
    CRYPTO_free(UBSEC_LIBNAME);
  }
  UBSEC_LIBNAME = (void *)0x0;
  if (UBSEC_error_init == 0) {
    ERR_unload_strings(UBSEC_lib_error_code,(ERR_STRING_DATA *)UBSEC_str_functs);
    ERR_unload_strings(UBSEC_lib_error_code,(ERR_STRING_DATA *)UBSEC_str_reasons);
    ERR_unload_strings(0,(ERR_STRING_DATA *)UBSEC_lib_name);
    UBSEC_error_init = 1;
  }
  return 1;
}

