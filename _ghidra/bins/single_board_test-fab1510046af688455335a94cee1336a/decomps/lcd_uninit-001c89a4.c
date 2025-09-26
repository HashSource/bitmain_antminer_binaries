
/* WARNING: Unknown calling convention */

int32_t lcd_uninit(int32_t ctx)

{
  int iVar1;
  char tmp42 [2048];
  
  if (lcd_inited == 0) {
    return 0;
  }
  iVar1 = close(ctx);
  if (iVar1 != 0) {
    builtin_strncpy(tmp42,"lcd close failed!!!\n",0x14);
    tmp42[0x14] = '\0';
    _applog(0,tmp42,false);
    iVar1 = -1;
  }
  lcd_inited = 0;
  return iVar1;
}

