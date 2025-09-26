
int pt_send_nonce(float *matrix,float freq,uint8_t *state)

{
  uint8_t *state_local;
  float freq_local;
  float *matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  char lcd_info [16];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : hm_text sweep_online send nonce,freq:%f\n","pt_send_nonce",SUB84((double)freq,0),
         (int)((ulonglong)(double)freq >> 0x20));
  snprintf(tmp1,0x100,"hm_text sweep_online send nonce,freq:%f",tmp1,(double)freq);
  log_to_file(tmp1,time_stamp);
  print_fan_speed();
  reset_runtime_info(g_rt.sweep.mode);
  inc_freq_with_target(matrix,(g_rt.config)->asics,freq,0,state);
  usleep(100000);
  usleep(100000);
  snprintf(lcd_info,0x10,"Freq:%d",(int)freq);
  lcd_common_show("Nonce test",lcd_info,(char *)0x0);
  cancle_pause_recv_nonce();
  pt_send_work((g_rt.config)->chain,&g_rt);
  if ((g_rt.config)->is_super == false) {
    pause_recv_nonce();
    calc_nonce_stats_fast(&g_rt.stats,&g_rt.asic_stats);
    get_asic_nonce_status_fast();
  }
  else {
    get_register_info(0,0xe,true,"BM1370");
    pause_recv_nonce();
    calc_nonce_stats_super(&g_rt.stats,&g_rt.asic_stats);
    printf("g_rt.config->standard.asic_nonce_rate: %d\n",((g_rt.config)->standard).asic_nonce_rate);
    get_asic_nonce_status_super();
  }
  return 0;
}

