
undefined AT24C02_read_one_byte(undefined param_1,undefined param_2)

{
  undefined uVar1;
  
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  uVar1 = write_EEPROM_iic(1,1,param_1,param_2,0);
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  return uVar1;
}

