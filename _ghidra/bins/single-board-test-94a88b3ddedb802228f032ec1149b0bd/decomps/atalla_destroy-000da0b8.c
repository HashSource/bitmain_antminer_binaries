
undefined4 atalla_destroy(void)

{
  if (ATALLA_LIBNAME != (void *)0x0) {
    CRYPTO_free(ATALLA_LIBNAME);
  }
  ATALLA_LIBNAME = (void *)0x0;
  if (ATALLA_error_init == 0) {
    ERR_unload_strings(ATALLA_lib_error_code,(ERR_STRING_DATA *)ATALLA_str_functs);
    ERR_unload_strings(ATALLA_lib_error_code,(ERR_STRING_DATA *)ATALLA_str_reasons);
    ERR_unload_strings(0,(ERR_STRING_DATA *)ATALLA_lib_name);
    ATALLA_error_init = 1;
  }
  return 1;
}

