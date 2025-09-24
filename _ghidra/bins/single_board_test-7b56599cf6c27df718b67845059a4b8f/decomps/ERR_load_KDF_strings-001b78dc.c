
undefined4 ERR_load_KDF_strings(void)

{
  char *pcVar1;
  
  pcVar1 = ERR_func_error_string(0x34067000);
  if (pcVar1 != (char *)0x0) {
    return 1;
  }
  ERR_load_strings_const(&KDF_str_functs);
  ERR_load_strings_const(KDF_str_reasons);
  return 1;
}

