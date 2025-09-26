
/* WARNING: Unknown calling convention */

int32_t lcd_clear(int32_t ctx)

{
  int iVar1;
  int32_t iVar2;
  char tmp42 [2048];
  
  if (lcd_inited == 0) {
    iVar2 = -2;
  }
  else if (ctx == lcd_fd) {
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)&lcd_mutex);
    if (iVar1 == 0) {
      memset(lcd_output,0x20,0x40);
      iVar2 = lcd_fd;
      lseek(lcd_fd,0,0);
      write(iVar2,lcd_output,0x40);
      pthread_mutex_unlock((pthread_mutex_t *)&lcd_mutex);
      iVar2 = 0;
    }
    else {
      iVar2 = -4;
      builtin_strncpy(tmp42,"failed to lcd lock\n",0x14);
      _applog(0,tmp42,false);
    }
  }
  else {
    iVar2 = -3;
    builtin_strncpy(tmp42,"bad para",8);
    tmp42[8] = 'm';
    tmp42[9] = '\n';
    tmp42[10] = '\0';
    _applog(1,tmp42,false);
  }
  return iVar2;
}

