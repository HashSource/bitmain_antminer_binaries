
/* WARNING: Unknown calling convention */

void change_pic_voltage_old(void)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  byte voltage;
  int iVar4;
  int i;
  int iVar5;
  
  piVar3 = DAT_000346d0;
  iVar2 = DAT_000346cc;
  iVar4 = 0;
  iVar5 = DAT_000346cc + 0x7c;
  sleep(300);
  do {
    voltage = *(byte *)(iVar2 + 0x91);
    if ((*(int *)(*piVar3 + (iVar4 + 2) * 4) != 0) &&
       (bVar1 = *(byte *)(iVar5 + iVar4), voltage <= bVar1)) {
      do {
        voltage = voltage + 5;
        if (bVar1 < voltage) {
          voltage = bVar1;
        }
        pthread_mutex_lock(DAT_000346c8);
        set_pic_voltage((uchar)iVar4,voltage);
        pthread_mutex_unlock(DAT_000346c8);
        pthread_mutex_lock(DAT_000346c8);
        get_pic_voltage((uchar)iVar4);
        pthread_mutex_unlock(DAT_000346c8);
        if (*(byte *)(iVar5 + iVar4) == voltage) break;
        cgsleep_ms(100);
        bVar1 = *(byte *)(iVar5 + iVar4);
      } while (voltage <= bVar1);
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 0x10) {
      return;
    }
  } while( true );
}

