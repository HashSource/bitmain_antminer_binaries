
uint8_t power_set_da_value_simple(uint8_t data)

{
  uint8_t uVar1;
  uint8_t data_local;
  uint8_t ret;
  uchar reg_addr;
  _Bool reg_addr_valid;
  
  pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  usleep(100000);
  uVar1 = znyq_set_iic(power_iic_addr,power_iic_no,false,true,'\x02',data);
  pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  return uVar1;
}

