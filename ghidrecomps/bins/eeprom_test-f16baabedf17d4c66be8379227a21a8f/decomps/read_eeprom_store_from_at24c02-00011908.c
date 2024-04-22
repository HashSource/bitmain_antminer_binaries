
eeprom_store_t * read_eeprom_store_from_at24c02(eeprom_store_t *eeprom_store,uint8_t chain)

{
  uint8_t uVar1;
  uint8_t chain_local;
  eeprom_store_t *eeprom_store_local;
  eeprom_store_t *eeprom;
  
  pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  usleep(10000);
  uVar1 = eeprom_read_one_byte('\0',chain);
  eeprom_store->magic_num = uVar1;
  uVar1 = eeprom_read_one_byte('\x01',chain);
  eeprom_store->chain_volt = uVar1;
  eeprom_read_bytes('\x02',eeprom_store->chain_freq_data,chain,'l');
  eeprom_read_bytes('n',eeprom_store->hash_rate,chain,'\x04');
  pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  return eeprom_store;
}

