
void inc_freq_delay(int start_freq,int end_freq,int temp)

{
  int temp_local;
  int end_freq_local;
  int start_freq_local;
  char time_stamp [48];
  char tmp1 [2048];
  int freq_count;
  
  freq_count = 0;
  while( true ) {
    if (((float)(longlong)temp <= gAsic_avg_temp) || (4 < freq_count)) break;
    sleep(1);
    freq_count = freq_count + 1;
  }
  if (freq_count == 5) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: inc_freq time out, gAsic_avg_temp=%f\n","inc_freq_delay",
           SUB84((double)gAsic_avg_temp,0),(int)((ulonglong)(double)gAsic_avg_temp >> 0x20));
    snprintf(tmp1,0x800,"inc_freq time out, gAsic_avg_temp=%f",tmp1,(double)gAsic_avg_temp);
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: inc_freq success, gAsic_avg_temp=%f\n","inc_freq_delay",
           SUB84((double)gAsic_avg_temp,0),(int)((ulonglong)(double)gAsic_avg_temp >> 0x20));
    snprintf(tmp1,0x800,"inc_freq success, gAsic_avg_temp=%f",tmp1,(double)gAsic_avg_temp);
    log_to_file(tmp1,time_stamp);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: inc_freq from %d to %d\n","inc_freq_delay",start_freq,end_freq);
  snprintf(tmp1,0x800,"inc_freq from %d to %d",start_freq,end_freq);
  log_to_file(tmp1,time_stamp);
  inc_freq_with_fixed_step_parallel
            ((uint8_t)gChain,'\x01',0,
             (uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Clk_Sel,start_freq,
             end_freq,6.25);
  sleep(2);
  return;
}

