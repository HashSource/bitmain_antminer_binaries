
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_X509_strings(void)

{
  char *pcVar1;
  
  pcVar1 = ERR_func_error_string(0xb064000);
  if (pcVar1 != (char *)0x0) {
    return;
  }
  ERR_load_strings_const(&X509_str_functs);
  ERR_load_strings_const(X509_str_reasons);
  return;
}

