
int pattern_test(float *matrix)

{
  int iVar1;
  float *matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  
  iVar1 = pt_before_send_nonce(matrix);
  if (iVar1 == 0) {
    set_chain_baud((uint8_t)(g_rt.config)->chain,((g_rt.config)->speed).baudrate);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Set chain baud as %d\n","pattern_test",((g_rt.config)->speed).baudrate);
    snprintf(tmp1,0x100,"Set chain baud as %d",((g_rt.config)->speed).baudrate);
    log_to_file(tmp1,time_stamp);
    usleep(100000);
    pt_send_work((g_rt.config)->chain,&g_rt);
    stop_threads();
    power_down_and_fan((g_rt.config)->chain);
    calc_nonce_stats_fast(&g_rt.stats,&g_rt.asic_stats);
    get_asic_nonce_status_fast();
    iVar1 = 0;
  }
  else {
    stop_threads();
    power_down_and_fan((g_rt.config)->chain);
    iVar1 = -1;
  }
  return iVar1;
}

