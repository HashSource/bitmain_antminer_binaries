
_Bool eeprom_set_pcb_version(uint8_t chain,uint8_t pcb_version)

{
  _Bool _Var1;
  uint8_t pcb_version_local;
  uint8_t chain_local;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist\n",(uint)chain);
    _Var1 = false;
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    eeprom_write_one_byte(0xfc,pcb_version,chain);
    usleep(10000);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    _Var1 = eeprom_update_crc(chain);
  }
  return _Var1;
}

