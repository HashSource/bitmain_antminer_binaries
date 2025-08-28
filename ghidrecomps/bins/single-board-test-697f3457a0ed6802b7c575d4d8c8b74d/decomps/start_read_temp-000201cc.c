
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void start_read_temp(void)

{
  user_i2c_enable(cgpu.runtime,gChain);
  usleep(50000);
  pthread_create(&cgpu.read_temp,(pthread_attr_t *)0x0,(__start_routine *)0x1ff09,(void *)0x0);
  return;
}

