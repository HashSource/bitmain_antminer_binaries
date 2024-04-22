
void write_eeprom_store_into_at24c02(eeprom_store_t *eeprom,uint8_t chain)

{
  uint8_t chain_local;
  eeprom_store_t *eeprom_local;
  
  pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  usleep(10000);
  eeprom_write_one_byte('\0',eeprom->magic_num,chain);
  eeprom_write_one_byte('\x01',eeprom->chain_volt,chain);
  eeprom_write_bytes('\x02',eeprom->chain_freq_data,chain,'l');
  eeprom_write_bytes('n',eeprom->hash_rate,chain,'\x04');
  pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  return;
}

