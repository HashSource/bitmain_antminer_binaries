
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_pwth(void)

{
  char time_stamp [48];
  char tmp1 [256];
  int asic;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : s21 set pwth 3 test\n","set_pwth");
  builtin_strncpy(tmp1,"s21 set pwth 3 test",0x14);
  log_to_file(tmp1,time_stamp);
  for (asic = 0; asic < (g_rt.config)->asics; asic = asic + 1) {
    set_asic_clock_delay_control
              ((uint8_t)(g_rt.config)->chain,asic * (g_rt.config)->interval,'\x03',
               (uint8_t)((g_rt.config)->reg).ccdly_sel,'\0');
    usleep(10000);
  }
  return;
}

