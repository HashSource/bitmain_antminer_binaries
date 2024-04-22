
/* WARNING: Unknown calling convention */

void eeprom_erase_all(void)

{
  int j;
  int i;
  
  pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  for (i = 0; i < 0x10; i = i + 1) {
    if (chain_list[i] != 0) {
      for (j = 0; j < 0x100; j = j + 1) {
        eeprom_write_one_byte((uint8_t)j,'\0',(uint8_t)i);
      }
    }
  }
  usleep(10000);
  pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  return;
}

