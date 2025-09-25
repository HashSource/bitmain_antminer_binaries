
void err_exit(char *err_info)

{
  char *err_info_local;
  char time_stamp [48];
  char tmp1 [256];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : warning:force exit test...\n","err_exit");
  builtin_strncpy(tmp1,"warning:force exit test.",0x18);
  tmp1[0x18] = '.';
  tmp1[0x19] = '.';
  tmp1[0x1a] = '\0';
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : exit info:%s\n","err_exit",err_info);
  snprintf(tmp1,0x100,"exit info:%s",err_info);
  log_to_file(tmp1,time_stamp);
  gStart_show_on_lcd = false;
  lcd_common_show("Board Protect","Force exit",err_info);
  pwm_set(gFan,100);
  chain_reset_low(gChain);
  usleep(200000);
  bitmain_power_off();
  usleep(200000);
  bitmain_power_off();
                    /* WARNING: Subroutine does not return */
  exit(1);
}

