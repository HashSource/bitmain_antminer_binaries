
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void change_pic_voltage_old(void)

{
  byte bVar1;
  byte bVar2;
  byte voltage;
  int iVar3;
  
  iVar3 = 0;
  sleep(300);
  do {
    if ((dev->chain_exist[iVar3] != 0) &&
       (bVar1 = chain_voltage_pic[iVar3], bVar2 = de_voltage, de_voltage <= bVar1)) {
      do {
        voltage = bVar2 + 5;
        if (bVar1 < (byte)(bVar2 + 5)) {
          voltage = bVar1;
        }
        pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
        set_pic_voltage((uchar)iVar3,voltage);
        pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
        pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
        get_pic_voltage((uchar)iVar3);
        pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
        if (chain_voltage_pic[iVar3] == voltage) break;
        cgsleep_ms(100);
        bVar1 = chain_voltage_pic[iVar3];
        bVar2 = voltage;
      } while (voltage <= bVar1);
    }
    iVar3 = iVar3 + 1;
    if (iVar3 == 0x10) {
      return;
    }
  } while( true );
}

