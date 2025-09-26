
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void stop_threads(void)

{
  char tmp42 [256];
  
  builtin_strncpy(tmp42,"stop threads ent",0x10);
  tmp42[0x10] = 'e';
  tmp42[0x11] = 'r';
  tmp42[0x12] = '\0';
  puts(tmp42);
  g_rt.read_temp = 0;
  g_rt.recv_nonce = 0;
  g_pwm_enable = false;
  if (g_power_handle != 0) {
    pthread_cancel(g_power_handle);
  }
  sleep(5);
  builtin_strncpy(tmp42,"stop threads end",0x10);
  tmp42._16_2_ = tmp42._16_2_ & 0xff00;
  puts(tmp42);
  return;
}

