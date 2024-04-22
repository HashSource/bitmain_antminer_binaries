
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_EVP_strings(void)

{
  ERR_STRING_DATA *str;
  char *pcVar1;
  
  str = DAT_000b2380;
  pcVar1 = ERR_func_error_string(DAT_000b2380->error);
  if (pcVar1 != (char *)0x0) {
    return;
  }
  ERR_load_strings(0,str);
  ERR_load_strings(0,str + 0x50);
  return;
}

