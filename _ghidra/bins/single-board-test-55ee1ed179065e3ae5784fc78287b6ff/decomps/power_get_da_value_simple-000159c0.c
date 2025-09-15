
byte power_get_da_value_simple(void)

{
  byte bVar1;
  
  pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
  bVar1 = znyq_set_iic(power_iic_addr,power_iic_no,1,1,2,0);
  printf("power da value is %d\n",(uint)bVar1);
  pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
  return bVar1;
}

