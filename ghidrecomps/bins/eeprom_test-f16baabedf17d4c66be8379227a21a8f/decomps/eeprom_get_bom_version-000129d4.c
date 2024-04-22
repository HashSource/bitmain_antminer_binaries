
_Bool eeprom_get_bom_version(uint8_t chain,uint8_t *bom_version)

{
  uint8_t uVar1;
  _Bool _Var2;
  uint8_t *bom_version_local;
  uint8_t chain_local;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist\n",(uint)chain);
    _Var2 = false;
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    uVar1 = eeprom_read_one_byte(0xfd,chain);
    *bom_version = uVar1;
    usleep(10000);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    _Var2 = eeprom_check_crc(chain);
  }
  return _Var2;
}

