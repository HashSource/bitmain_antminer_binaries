
void change_pic_voltage_old(void)

{
  byte bVar1;
  byte bVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  puVar3 = chain_voltage_pic;
  uVar4 = 0;
  sleep(300);
  do {
    if (*(int *)(dev + (uVar4 + 2) * 4) != 0) {
      bVar1 = *puVar3;
      if (de_voltage <= bVar1) {
        bVar2 = de_voltage;
        do {
          bVar2 = bVar2 + 5;
          if (bVar1 <= bVar2) {
            bVar2 = bVar1;
          }
          pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
          pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
          pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
          write_EEPROM_iic(1,1,0x90,uVar4 & 0xff,0);
          pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
          if (*puVar3 == bVar2) break;
          cgsleep_ms(100);
          bVar1 = *puVar3;
        } while (bVar2 <= bVar1);
      }
    }
    uVar4 = uVar4 + 1;
    puVar3 = puVar3 + 1;
    if (uVar4 == 0x10) {
      return;
    }
  } while( true );
}

