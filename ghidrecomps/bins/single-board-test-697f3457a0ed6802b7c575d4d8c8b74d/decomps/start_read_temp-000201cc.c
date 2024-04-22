
/* WARNING: Unknown calling convention */

void start_read_temp(void)

{
  user_i2c_enable(cgpu.runtime,gChain);
  usleep(50000);
  pthread_create(DAT_0002020c,(pthread_attr_t *)0x0,read_all_sensor + 1,(void *)0x0);
  return;
}

