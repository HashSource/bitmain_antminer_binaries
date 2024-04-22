
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_COMP_strings(void)

{
  ERR_STRING_DATA *str;
  char *pcVar1;
  
  str = DAT_000d260c;
  pcVar1 = ERR_func_error_string(DAT_000d260c->error);
  if (pcVar1 != (char *)0x0) {
    return;
  }
  ERR_load_strings(0,str);
  ERR_load_strings(0,str + 5);
  return;
}

