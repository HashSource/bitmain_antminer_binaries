
undefined4 aep_destroy(void)

{
  if (AEP_LIBNAME != (void *)0x0) {
    CRYPTO_free(AEP_LIBNAME);
  }
  AEP_LIBNAME = (void *)0x0;
  if (AEPHK_error_init == 0) {
    ERR_unload_strings(AEPHK_lib_error_code,(ERR_STRING_DATA *)AEPHK_str_functs);
    ERR_unload_strings(AEPHK_lib_error_code,(ERR_STRING_DATA *)AEPHK_str_reasons);
    AEPHK_error_init = 1;
  }
  return 1;
}

