
void * pt_read_temp(void *arg)

{
  int32_t iVar1;
  pthread_t __th;
  void *arg_local;
  char time_stamp [48];
  char tmp42 [256];
  uint8_t sensor_addr [2];
  char lcd_data [16];
  int8_t data [2];
  pattern_runtime_ctx *ctx;
  uint8_t i;
  uint8_t sleep_counter;
  
  snprintf(tmp42,0x100,"Start %s","pt_read_temp");
  puts(tmp42);
  while (*(int *)((int)arg + 0x55548) != 0) {
    iVar1 = read_sensor_on_switch((g_rt.config)->chain,0);
    *(char *)((int)arg + 0x55538) = (char)iVar1;
    iVar1 = read_sensor_on_switch((g_rt.config)->chain,1);
    *(char *)((int)arg + 0x55539) = (char)iVar1;
    iVar1 = read_sensor_on_switch((g_rt.config)->chain,2);
    *(char *)((int)arg + 0x5553a) = (char)iVar1;
    iVar1 = read_sensor_on_switch((g_rt.config)->chain,3);
    *(char *)((int)arg + 0x5553b) = (char)iVar1;
    read_sensor_on_switch((g_rt.config)->chain,4);
    read_sensor_on_switch((g_rt.config)->chain,5);
    read_sensor_on_switch((g_rt.config)->chain,6);
    read_sensor_on_switch((g_rt.config)->chain,7);
    read_sensor_on_switch((g_rt.config)->chain,8);
    read_sensor_on_switch((g_rt.config)->chain,9);
    read_sensor_on_switch((g_rt.config)->chain,10);
    read_sensor_on_switch((g_rt.config)->chain,0xb);
    if ((*(int *)(*(int *)((int)arg + 0x55508) + 0x94) == 2) &&
       (3 < (int)((uint)*(byte *)((int)arg + 0x55538) - (uint)*(byte *)((int)arg + 0x55539)))) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Water flow reversal!\n","pt_read_temp");
      builtin_strncpy(tmp42,"Water flow reversal!",0x14);
      tmp42[0x14] = '\0';
      log_to_file(tmp42,time_stamp);
      if (g_sweep_err_code == 0) {
        g_sweep_err_code = 6;
      }
      bitmain_power_off();
    }
    sleep_counter = '\0';
    while ((*(int *)((int)arg + 0x55548) != 0 && (sleep_counter < 0x14))) {
      sleep(1);
      sleep_counter = sleep_counter + '\x01';
    }
  }
  snprintf(tmp42,0x100,"%s stop","pt_read_temp");
  puts(tmp42);
  __th = pthread_self();
  pthread_detach(__th);
  return (void *)0x0;
}

