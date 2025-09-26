
/* WARNING: Unknown calling convention */

int32_t uart_init(void)

{
  int32_t iVar1;
  char tmp42 [2048];
  
  iVar1 = 0;
  if (platform_inited == 0) {
    builtin_strncpy(tmp42,"please init platform first!!",0x1c);
    tmp42[0x1c] = '\n';
    tmp42[0x1d] = '\0';
    _applog(0,tmp42,false);
    iVar1 = -1;
  }
  return iVar1;
}

