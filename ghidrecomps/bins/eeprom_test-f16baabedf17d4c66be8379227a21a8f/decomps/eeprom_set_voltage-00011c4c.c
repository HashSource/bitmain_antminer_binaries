
_Bool eeprom_set_voltage(uint8_t chain,double voltage)

{
  _Bool _Var1;
  double in_d0;
  double dVar2;
  double voltage_local;
  uint8_t local_18;
  uint8_t chain_local;
  uint8_t vol;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain);
    _Var1 = false;
  }
  else {
    dVar2 = (in_d0 * DAT_00011ce8) / 5.0 - DAT_00011cf0;
    local_18 = (0.0 < dVar2) * (char)(longlong)dVar2;
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    usleep(10000);
    eeprom_write_one_byte('\x01',local_18,chain);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    _Var1 = eeprom_update_crc(chain);
  }
  return _Var1;
}

