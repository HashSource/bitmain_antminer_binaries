
/* WARNING: Unknown calling convention */

void power_check_type(void)

{
  uchar uVar1;
  uint8_t ret;
  
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar1 = i2c_read(0x5200000);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if (uVar1 != 0xf5) {
    puts("power type APW8 2000W");
    g_power_type = 1;
    return;
  }
  puts("power type APW9 3600W");
  g_power_type = 2;
  return;
}

