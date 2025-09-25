
undefined4 ERR_load_TS_strings(void)

{
  char *pcVar1;
  
  pcVar1 = ERR_func_error_string(0x2f06e000);
  if (pcVar1 != (char *)0x0) {
    return 1;
  }
  ERR_load_strings_const(&TS_str_functs);
  ERR_load_strings_const(TS_str_reasons);
  return 1;
}

