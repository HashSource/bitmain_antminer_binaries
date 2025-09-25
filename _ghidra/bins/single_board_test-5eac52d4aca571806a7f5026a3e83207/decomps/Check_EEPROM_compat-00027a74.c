
_Bool Check_EEPROM_compat(uint32_t EEPROM_length)

{
  uint32_t EEPROM_length_local;
  int oldState;
  _Bool res;
  
  pthread_setcancelstate(1,&oldState);
  res = Check_EEPROM(EEPROM_length);
  pthread_setcancelstate(oldState,(int *)0x0);
  return res;
}

