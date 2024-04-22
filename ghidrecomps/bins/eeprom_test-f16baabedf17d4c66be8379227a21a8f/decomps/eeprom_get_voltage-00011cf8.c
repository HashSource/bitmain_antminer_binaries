
_Bool eeprom_get_voltage(uint8_t chain,double *voltage)

{
  byte bVar1;
  _Bool _Var2;
  double *voltage_local;
  uint8_t chain_local;
  uint32_t vol;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain);
    _Var2 = false;
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    usleep(10000);
    bVar1 = eeprom_read_one_byte('\x01',chain);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    *voltage = ((double)(ulonglong)(bVar1 + 200) * 5.0) / DAT_00011d90;
    _Var2 = eeprom_check_crc(chain);
  }
  return _Var2;
}

