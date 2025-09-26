
void do_core_reset(uint8_t *state)

{
  uint8_t *state_local;
  char tmp42 [256];
  int asic;
  
  builtin_strncpy(tmp42,"do_core_rese",0xc);
  tmp42[0xc] = 't';
  tmp42[0xd] = '\0';
  puts(tmp42);
  snprintf(tmp42,0x100,"interval %d, total ASIC num %d",(g_rt.config)->interval,(g_rt.config)->asics
          );
  puts(tmp42);
  snprintf(tmp42,0x100,"ccdly pwth %d %d",((g_rt.config)->reg).ccdly_sel,
           ((g_rt.config)->reg).pwth_sel);
  puts(tmp42);
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
      snprintf(tmp42,0x100,"do_core_reset asic:%d",asic);
      puts(tmp42);
    }
  }
  return;
}

