
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_RAND_strings(void)

{
  char *pcVar1;
  
  pcVar1 = ERR_func_error_string(0x2407f000);
  if (pcVar1 != (char *)0x0) {
    return;
  }
  ERR_load_strings_const(&RAND_str_functs);
  ERR_load_strings_const(RAND_str_reasons);
  return;
}

