
undefined power_set_da_value_simple(undefined param_1)

{
  undefined uVar1;
  
  pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
  usleep(100000);
  uVar1 = znyq_set_iic(power_iic_addr,power_iic_no,0,1,2,param_1);
  pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
  return uVar1;
}

