
/* WARNING: Variable defined which should be unmapped: state_local */

int pt_send_nonce(float *curr_matrix,float *last_matrix,float freq,uint8_t *state)

{
  float fVar1;
  uint8_t *state_local;
  float freq_local;
  float *last_matrix_local;
  float *curr_matrix_local;
  char time_stamp [48];
  char tmp42 [256];
  
  snprintf(tmp42,0x100,"sweep_online send nonce, freq: %f",tmp42,(double)freq,state);
  puts(tmp42);
  set_pattern_test_voltage_by_step(g_diff + (g_rt.config)->tests[0].voltage,0x834,'\x05');
  reset_runtime_info(g_rt.sweep.mode);
  inc_freq_online_pll(curr_matrix,last_matrix,(g_rt.config)->asics);
  set_pattern_test_voltage_by_step(0x834,g_diff + (g_rt.config)->tests[0].voltage,'\x05');
  sleep(2);
  cancle_pause_recv_nonce();
  adc_get_domain_voltage((uint8_t)(g_rt.config)->chain,0,'\x03');
  set_chain_core_nonce_overflow_control((uint8_t)(g_rt.config)->chain,false);
  set_chain_rosc_pad_disable((uint8_t)(g_rt.config)->chain);
  pt_send_work((g_rt.config)->chain,&g_rt);
  if ((g_rt.config)->is_super == false) {
    pause_recv_nonce();
    calc_nonce_stats_fast(&g_rt.stats,&g_rt.asic_stats);
    get_asic_nonce_status_fast();
  }
  else {
    get_register_info(0,0xe,true,"BM1370");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    fVar1 = get_miner_power();
    printf("%s: on line power = %f \n","pt_send_nonce",SUB84((double)fVar1,0),
           (int)((ulonglong)(double)fVar1 >> 0x20));
    fVar1 = get_miner_power();
    snprintf(tmp42,0x800,"on line power = %f ",tmp42,(double)fVar1);
    log_to_file(tmp42,time_stamp);
    pause_recv_nonce();
    calc_nonce_stats_super(&g_rt.stats,&g_rt.asic_stats);
    printf("g_rt.config->standard.asic_nonce_rate: %d\n",((g_rt.config)->standard).asic_nonce_rate);
    get_asic_nonce_status_super();
  }
  builtin_strncpy(tmp42,"sweep send/receive..",0x14);
  tmp42[0x14] = '.';
  tmp42[0x15] = '\0';
  puts(tmp42);
  return 0;
}

