
void AT24C02_write_one_byte(undefined param_1,undefined param_2,undefined param_3)

{
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  write_EEPROM_iic(0,1,param_1,param_3,param_2);
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  return;
}

