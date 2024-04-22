
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_CONF_strings(void)

{
  ERR_STRING_DATA *str;
  char *pcVar1;
  
  str = DAT_000ce7b4;
  pcVar1 = ERR_func_error_string(DAT_000ce7b4->error);
  if (pcVar1 != (char *)0x0) {
    return;
  }
  ERR_load_strings(0,str);
  ERR_load_strings(0,str + 0x17);
  return;
}

