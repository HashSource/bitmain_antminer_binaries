
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_register_stage_2(void)

{
  char time_stamp [48];
  char tmp1 [256];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set chain inactive\n","set_register_stage_2");
  builtin_strncpy(tmp1,"Set chain inacti",0x10);
  tmp1[0x10] = 'v';
  tmp1[0x11] = 'e';
  tmp1[0x12] = '\0';
  log_to_file(tmp1,time_stamp);
  set_chain_inactive((uint8_t)(g_rt.config)->chain);
  usleep(10000);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set asic address, interval:%d\n","set_register_stage_2",(g_rt.config)->interval);
  snprintf(tmp1,0x100,"Set asic address, interval:%d",(g_rt.config)->interval);
  log_to_file(tmp1,time_stamp);
  set_chain_asic_address((uint8_t)(g_rt.config)->chain,(g_rt.config)->interval);
  usleep(10000);
  set_chain_clock_select_control
            ((uint8_t)(g_rt.config)->chain,(uint8_t)((g_rt.config)->reg).pulse_mode,
             (uint8_t)((g_rt.config)->reg).clk_sel);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set pulse_mode = 0x%02x, clk_sel = 0x%02x\n","set_register_stage_2",
         ((g_rt.config)->reg).pulse_mode,((g_rt.config)->reg).clk_sel);
  snprintf(tmp1,0x100,"Set pulse_mode = 0x%02x, clk_sel = 0x%02x",((g_rt.config)->reg).pulse_mode,
           ((g_rt.config)->reg).clk_sel);
  log_to_file(tmp1,time_stamp);
  usleep(10000);
  set_chain_clock_delay_control
            ((uint8_t)(g_rt.config)->chain,(uint8_t)((g_rt.config)->reg).pwth_sel,
             (uint8_t)((g_rt.config)->reg).clk_sel,(uint8_t)((g_rt.config)->reg).swpf_mode);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set pwth_sel = 0x%02x, ccdly_sel = 0x%02x, swpf_mode = 0x%02x\n",
         "set_register_stage_2",((g_rt.config)->reg).pwth_sel,((g_rt.config)->reg).clk_sel,
         ((g_rt.config)->reg).swpf_mode);
  snprintf(tmp1,0x100,"Set pwth_sel = 0x%02x, ccdly_sel = 0x%02x, swpf_mode = 0x%02x",
           ((g_rt.config)->reg).pwth_sel,((g_rt.config)->reg).clk_sel,((g_rt.config)->reg).swpf_mode
          );
  log_to_file(tmp1,time_stamp);
  usleep(10000);
  set_chain_adc_control_disable((uint8_t)(g_rt.config)->chain);
  set_chain_iodriver_clko_ds((uint8_t)(g_rt.config)->chain,'\x01');
  set_chain_rosc_pad_disable((uint8_t)(g_rt.config)->chain);
  enable_work_send();
  _set_uart_relay((uint8_t)(g_rt.config)->interval);
  usleep(10000);
  usleep(1000000);
  return;
}

