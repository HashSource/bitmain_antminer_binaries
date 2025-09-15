
undefined4 lcd_clear(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (lcd_inited == 0) {
    uVar2 = 0xfffffffe;
  }
  else if (param_1 == lcd_fd) {
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)lcd_mutex);
    if (iVar1 == 0) {
      memset(lcd_output,0x20,0x40);
      lseek(lcd_fd,0,0);
      write(lcd_fd,lcd_output,0x40);
      pthread_mutex_unlock((pthread_mutex_t *)lcd_mutex);
      uVar2 = 0;
    }
    else {
      printf("%s:%d","lcd_clear",0x61);
      puts("failed to lcd lock");
      uVar2 = 0xfffffffc;
    }
  }
  else {
    printf("%s:%d","lcd_clear",0x5d);
    puts("bad param");
    uVar2 = 0xfffffffd;
  }
  return uVar2;
}

