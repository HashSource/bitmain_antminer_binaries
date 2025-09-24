
void do_core_reset(uint8_t *state)

{
  uint8_t *state_local;
  char time_stamp [48];
  char tmp1 [256];
  int asic;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : do_core_reset\n","do_core_reset");
  builtin_strncpy(tmp1,"do_core_rese",0xc);
  tmp1[0xc] = 't';
  tmp1[0xd] = '\0';
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : interval %d, total ASIC num %d\n","do_core_reset",(g_rt.config)->interval,
         (g_rt.config)->asics);
  snprintf(tmp1,0x100,"interval %d, total ASIC num %d",(g_rt.config)->interval,(g_rt.config)->asics)
  ;
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : ccdly pwth %d %d\n","do_core_reset",((g_rt.config)->reg).ccdly_sel,
         ((g_rt.config)->reg).pwth_sel);
  snprintf(tmp1,0x100,"ccdly pwth %d %d",((g_rt.config)->reg).ccdly_sel,
           ((g_rt.config)->reg).pwth_sel);
  log_to_file(tmp1,time_stamp);
  for (asic = 0; asic < (g_rt.config)->asics; asic = asic + 1) {
    if (state == (uint8_t *)0x0) {
      set_asic_core_srst_fast((uint8_t)(g_rt.config)->chain,asic * (g_rt.config)->interval);
      usleep(10000);
      set_asic_clock_select_control
                ((uint8_t)(g_rt.config)->chain,asic * (g_rt.config)->interval,
                 (uint8_t)((g_rt.config)->reg).pulse_mode,'\0');
      usleep(10000);
      set_asic_clock_delay_control
                ((uint8_t)(g_rt.config)->chain,asic * (g_rt.config)->interval,
                 (uint8_t)((g_rt.config)->reg).pwth_sel,(uint8_t)((g_rt.config)->reg).ccdly_sel,'\0'
                );
      set_asic_core_enable((uint8_t)(g_rt.config)->chain,asic * (g_rt.config)->interval);
      usleep(10000);
    }
    else if (state[asic] == '\0') {
      set_asic_core_srst_fast((uint8_t)(g_rt.config)->chain,asic * (g_rt.config)->interval);
      usleep(10000);
      set_asic_clock_select_control
                ((uint8_t)(g_rt.config)->chain,asic * (g_rt.config)->interval,
                 (uint8_t)((g_rt.config)->reg).pulse_mode,'\0');
      usleep(10000);
      set_asic_clock_delay_control
                ((uint8_t)(g_rt.config)->chain,asic * (g_rt.config)->interval,
                 (uint8_t)((g_rt.config)->reg).pwth_sel,(uint8_t)((g_rt.config)->reg).ccdly_sel,'\0'
                );
      set_asic_core_enable((uint8_t)(g_rt.config)->chain,asic * (g_rt.config)->interval);
      usleep(10000);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : do_core_reset asic:%d\n","do_core_reset",asic);
      snprintf(tmp1,0x100,"do_core_reset asic:%d",asic);
      log_to_file(tmp1,time_stamp);
    }
  }
  return;
}

