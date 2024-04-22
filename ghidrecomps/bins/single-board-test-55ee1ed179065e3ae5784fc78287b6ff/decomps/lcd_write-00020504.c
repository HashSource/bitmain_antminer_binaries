
undefined4 lcd_write(int param_1,byte param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint __n;
  uint uVar3;
  uint local_20;
  byte local_15;
  int local_c;
  
  local_c = 0;
  if (lcd_inited == 0) {
    uVar2 = 0xfffffffe;
  }
  else if (((param_1 == lcd_fd) && (param_2 < 4)) && (param_4 < 0x41)) {
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)lcd_mutex);
    local_20 = param_4;
    local_15 = param_2;
    if (iVar1 == 0) {
      do {
        __n = local_20;
        if (0xf < local_20) {
          __n = 0x10;
        }
        uVar3 = (uint)local_15;
        local_15 = local_15 + 1;
        memcpy(lcd_output + uVar3 * 0x10,(void *)(param_3 + local_c),__n);
        local_c = local_c + __n;
        local_20 = local_20 - __n;
      } while ((local_20 != 0) && (local_15 < 4));
      write(lcd_fd,lcd_output,0x40);
      pthread_mutex_unlock((pthread_mutex_t *)lcd_mutex);
      uVar2 = 0;
    }
    else {
      printf("%s:%d","lcd_write",0x3b);
      puts("failed to lcd lock");
      uVar2 = 0xfffffffc;
    }
  }
  else {
    printf("%s:%d","lcd_write",0x36);
    puts("bad param");
    uVar2 = 0xfffffffd;
  }
  return uVar2;
}

