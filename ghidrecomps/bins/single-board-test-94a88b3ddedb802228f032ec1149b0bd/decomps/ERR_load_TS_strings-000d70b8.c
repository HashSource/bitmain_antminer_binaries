
void ERR_load_TS_strings(void)

{
  ERR_STRING_DATA *str;
  char *pcVar1;
  
  str = DAT_000d70dc;
  pcVar1 = ERR_func_error_string(DAT_000d70dc->error);
  if (pcVar1 != (char *)0x0) {
    return;
  }
  ERR_load_strings(0,str);
  ERR_load_strings(0,str + 0x34);
  return;
}

