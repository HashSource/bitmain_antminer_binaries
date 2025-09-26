
void pt_inc_freq_delay(int start_freq,int end_freq,int temp)

{
  int temp_local;
  int end_freq_local;
  int start_freq_local;
  char time_stamp [48];
  char tmp1 [2048];
  int freq_count;
  
  for (freq_count = 0;
      ((int)((uint)(g_rt.asic_avg_temp < (float)(longlong)temp) << 0x1f) < 0 && (freq_count < 5));
      freq_count = freq_count + 1) {
    sleep(1);
  }
  if (freq_count == 5) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: inc_freq time out, g_rt.asic_avg_temp = %f\n","pt_inc_freq_delay",
           SUB84((double)g_rt.asic_avg_temp,0),(int)((ulonglong)(double)g_rt.asic_avg_temp >> 0x20))
    ;
    snprintf(tmp1,0x800,"inc_freq time out, g_rt.asic_avg_temp = %f",tmp1,(double)g_rt.asic_avg_temp
            );
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: inc_freq success, g_rt.asic_avg_temp = %f\n","pt_inc_freq_delay",
           SUB84((double)g_rt.asic_avg_temp,0),(int)((ulonglong)(double)g_rt.asic_avg_temp >> 0x20))
    ;
    snprintf(tmp1,0x800,"inc_freq success, g_rt.asic_avg_temp = %f",tmp1,(double)g_rt.asic_avg_temp)
    ;
    log_to_file(tmp1,time_stamp);
  }
  snprintf(tmp1,0x100,"inc_freq: from %d to %d",start_freq,end_freq);
  puts(tmp1);
  inc_freq_with_fix((uint8_t)(g_rt.config)->chain,(uint8_t)((g_rt.config)->reg).clk_sel,start_freq,
                    end_freq,6.25);
  sleep(2);
  return;
}

