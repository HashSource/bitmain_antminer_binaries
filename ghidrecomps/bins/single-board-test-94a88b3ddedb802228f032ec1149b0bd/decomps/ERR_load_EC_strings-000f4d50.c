
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_EC_strings(void)

{
  ERR_STRING_DATA *str;
  char *pcVar1;
  
  str = DAT_000f4d74;
  pcVar1 = ERR_func_error_string(DAT_000f4d74->error);
  if (pcVar1 != (char *)0x0) {
    return;
  }
  ERR_load_strings(0,str);
  ERR_load_strings(0,str + 0x91);
  return;
}

