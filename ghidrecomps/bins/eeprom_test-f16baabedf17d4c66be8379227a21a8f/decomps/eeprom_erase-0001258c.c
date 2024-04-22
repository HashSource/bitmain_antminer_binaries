
void eeprom_erase(uint8_t chain)

{
  uint8_t chain_local;
  int i;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain);
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    for (i = 0; i < 0x100; i = i + 1) {
      eeprom_write_one_byte((uint8_t)i,'\0',chain);
    }
    usleep(10000);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  }
  return;
}

