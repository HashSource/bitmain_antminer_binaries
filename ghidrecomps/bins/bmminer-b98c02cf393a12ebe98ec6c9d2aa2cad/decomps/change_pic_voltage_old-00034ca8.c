
void change_pic_voltage_old(void)

{
  byte bVar1;
  byte *pbVar2;
  pthread_mutex_t *__mutex;
  byte bVar3;
  byte *pbVar4;
  uint uVar5;
  
  __mutex = DAT_00034d44;
  pbVar2 = DAT_00034d40;
  uVar5 = 0;
  sleep(300);
  pbVar4 = pbVar2;
  do {
    if (*(int *)(dev + (uVar5 + 2) * 4) != 0) {
      bVar3 = pbVar2[0x10];
      bVar1 = *pbVar4;
      if (bVar3 <= bVar1) {
        do {
          bVar3 = bVar3 + 5;
          if (bVar1 <= bVar3) {
            bVar3 = bVar1;
          }
          pthread_mutex_lock(__mutex);
          pthread_mutex_unlock(__mutex);
          pthread_mutex_lock(__mutex);
          write_EEPROM_iic(1,1,0x90,uVar5 & 0xff,0);
          pthread_mutex_unlock(__mutex);
          if (*pbVar4 == bVar3) break;
          cgsleep_ms(100);
          bVar1 = *pbVar4;
        } while (bVar3 <= bVar1);
      }
    }
    uVar5 = uVar5 + 1;
    pbVar4 = pbVar4 + 1;
    if (uVar5 == 0x10) {
      return;
    }
  } while( true );
}

