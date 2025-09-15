
eeprom_store_t * read_eeprom_store_from_at24c02(eeprom_store_t *eeprom_store,uint8_t chain)

{
  uint8_t uVar1;
  uint8_t chain_local;
  eeprom_store_t *eeprom_store_local;
  eeprom_store_t *eeprom_1;
  eeprom_store_t *eeprom;
  
  uVar1 = array_read_one_byte('\0',chain);
  eeprom_store->magic_num = uVar1;
  uVar1 = array_read_one_byte('\x01',chain);
  eeprom_store->chain_volt = uVar1;
  array_read_bytes('\x02',eeprom_store->chain_freq_data,chain,0x3c);
  array_read_bytes('n',eeprom_store->hash_rate,chain,4);
  uVar1 = eeprom_target_eeprom_version();
  if (uVar1 == eeprom_store->magic_num) {
    uVar1 = array_read_one_byte(0x87,chain);
    eeprom_store->chain_volt_mode2 = uVar1;
    array_read_bytes(0x88,eeprom_store->chain_freq_data_mode2,chain,0x3c);
    array_read_bytes(0xf4,eeprom_store->hash_rate_mode2,chain,4);
  }
  return eeprom_store;
}

