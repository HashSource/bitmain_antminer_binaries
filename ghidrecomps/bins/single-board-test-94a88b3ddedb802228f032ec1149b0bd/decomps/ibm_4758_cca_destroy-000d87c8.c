
undefined4 ibm_4758_cca_destroy(void)

{
  if (CCA4758_error_init == 0) {
    ERR_unload_strings(CCA4758_lib_error_code,(ERR_STRING_DATA *)CCA4758_str_functs);
    ERR_unload_strings(CCA4758_lib_error_code,(ERR_STRING_DATA *)CCA4758_str_reasons);
    CCA4758_error_init = 1;
  }
  if (CCA4758_LIB_NAME != (void *)0x0) {
    CRYPTO_free(CCA4758_LIB_NAME);
  }
  CCA4758_LIB_NAME = (void *)0x0;
  return 1;
}

