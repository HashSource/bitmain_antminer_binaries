
/* WARNING: Unknown calling convention */

int32_t lcd_write(int32_t ctx,int8_t line,int8_t *data,uint32_t size)

{
  int iVar1;
  int8_t *__src;
  int iVar2;
  uint __n;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  char tmp42 [2048];
  
  iVar2 = (int)line;
  if (lcd_inited == 0) {
    return -2;
  }
  if (lcd_fd == ctx) {
    bVar5 = 0x3f < size;
    bVar4 = size == 0x40;
    if (size < 0x41) {
      bVar5 = 2 < (byte)line;
      bVar4 = line == '\x03';
    }
    if (!bVar5 || bVar4) {
      iVar1 = pthread_mutex_lock((pthread_mutex_t *)&lcd_mutex);
      if (iVar1 == 0) {
        iVar1 = 0;
        do {
          __n = size;
          if (0xf < size) {
            __n = 0x10;
          }
          uVar3 = iVar2 + 1;
          __src = data + iVar1;
          iVar1 = iVar1 + __n;
          memcpy(lcd_output + iVar2,__src,__n);
          size = size - __n;
          iVar2 = (int)(char)uVar3;
        } while ((uVar3 & 0xff) < 4 && size != 0);
        write(lcd_fd,lcd_output,0x40);
        pthread_mutex_unlock((pthread_mutex_t *)&lcd_mutex);
        return 0;
      }
      builtin_strncpy(tmp42,"failed to lcd lock\n",0x14);
      _applog(0,tmp42,false);
      return -4;
    }
  }
  builtin_strncpy(tmp42,"bad para",8);
  tmp42[8] = 'm';
  tmp42[9] = '\n';
  tmp42[10] = '\0';
  _applog(1,tmp42,false);
  return -3;
}

