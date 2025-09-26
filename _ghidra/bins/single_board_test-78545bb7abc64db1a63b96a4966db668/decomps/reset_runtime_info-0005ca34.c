
void reset_runtime_info(int sweep_mode)

{
  pattern_work_new *ppVar1;
  int sweep_mode_local;
  char tmp42 [256];
  pattern_work *works;
  pattern_work *work;
  pattern_work_new *works_new;
  pattern_work_new *work_new;
  int core;
  int big_core;
  int asic;
  int pattern;
  
  memset(&g_rt.stats,0,0x2a2c);
  memset(&g_rt.asic_stats,0,0x81208);
  g_rt.send_nonce_num = 0;
  g_rt.chain_status = 0;
  g_rt.is_chain_unbalance = '\0';
  if (sweep_mode == 0) {
    g_rt.recv_nonce = 0;
    g_rt.read_temp = 0;
  }
  snprintf(tmp42,0x100,"======pause_recv_nonce=%d",g_rt.pause_recv_nonce);
  puts(tmp42);
  if ((g_rt.config)->is_super == false) {
    for (asic = 0; asic < (g_rt.config)->asics; asic = asic + 1) {
      ppVar1 = g_rt.works_new[asic];
      for (big_core = 0; big_core < (g_rt.config)->big_core; big_core = big_core + 1) {
        for (core = 0; core < (g_rt.config)->samll_core_num_in_big_core; core = core + 1) {
          for (pattern = 0; pattern < (g_rt.config)->patter_num; pattern = pattern + 1) {
            ppVar1[pattern + (g_rt.config)->patter_num *
                             (big_core * (g_rt.config)->samll_core_num_in_big_core + core)].
            nonce_repeat = 0;
          }
        }
      }
    }
  }
  else {
    send_set_config_command((uint8_t)(g_rt.config)->chain,'\x01',0,0x90,0);
  }
  return;
}

