
undefined4 nuron_destroy(void)

{
  if (NURON_LIBNAME != (void *)0x0) {
    CRYPTO_free(NURON_LIBNAME);
  }
  NURON_LIBNAME = (void *)0x0;
  if (NURON_error_init == 0) {
    ERR_unload_strings(NURON_lib_error_code,(ERR_STRING_DATA *)NURON_str_functs);
    ERR_unload_strings(NURON_lib_error_code,(ERR_STRING_DATA *)NURON_str_reasons);
    ERR_unload_strings(0,(ERR_STRING_DATA *)NURON_lib_name);
    NURON_error_init = 1;
  }
  return 1;
}

