
/* WARNING: Unknown calling convention */

int32_t lcd_init(int8_t *path2dev)

{
  int iVar1;
  char tmp42 [2048];
  
  if (lcd_inited != 0) {
    return 0;
  }
  if (path2dev == (int8_t *)0x0) {
    builtin_strncpy(tmp42,"bad para",8);
    tmp42[8] = 'm';
    tmp42[9] = '\n';
    tmp42[10] = '\0';
    _applog(0,tmp42,false);
    iVar1 = -3;
  }
  else {
    iVar1 = open(path2dev,0x802);
    lcd_fd = iVar1;
    if (iVar1 < 0) {
      builtin_strncpy(tmp42,"open lcd failed!!!\n",0x14);
      _applog(0,tmp42,false);
      iVar1 = -1;
    }
    else {
      lcd_inited = 1;
    }
  }
  return iVar1;
}

