
void power_check_protocal_type(void)

{
  byte bVar1;
  
  pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
  bVar1 = znyq_set_iic(power_iic_addr,power_iic_no,1,1,0,0);
  if (bVar1 == 0xf5) {
    printf("power protocal %02x, using package cmd\n",0xf5);
    power_protocal_type = 2;
  }
  else {
    printf("power protocal %02x, using simple cmd\n",(uint)bVar1);
    power_protocal_type = 1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
  return;
}

