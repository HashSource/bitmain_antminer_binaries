
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void stop_read_temp(void)

{
  pthread_cancel(cgpu.read_temp);
  pthread_join(cgpu.read_temp,(void **)0x0);
  return;
}

