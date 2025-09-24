
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_DSA_strings(void)

{
  char *pcVar1;
  
  pcVar1 = ERR_func_error_string(0xa064000);
  if (pcVar1 != (char *)0x0) {
    return;
  }
  ERR_load_strings_const(&DSA_str_functs);
  ERR_load_strings_const(DSA_str_reasons);
  return;
}

