
void reset_runtime_info(int sweep_mode)

{
  int iVar1;
  pattern_work *ppVar2;
  int sweep_mode_local;
  char time_stamp [48];
  char tmp1 [256];
  pattern_work *works;
  pattern_work *work;
  int core;
  int asic;
  int pattern;
  
  memset(&g_rt.stats,0,0x130c);
  memset(&g_rt.asic_stats,0,0x2203c);
  g_rt.send_nonce_num = 0;
  g_rt.chain_status = 0;
  g_rt.is_chain_unbalance = '\0';
  if (sweep_mode == 0) {
    g_rt.recv_nonce = 0;
    g_rt.read_temp = 0;
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : ======pause_recv_nonce=%d\n","reset_runtime_info",g_rt.pause_recv_nonce);
  snprintf(tmp1,0x100,"======pause_recv_nonce=%d",g_rt.pause_recv_nonce);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : var:%d,%d,%d\n","reset_runtime_info",(g_rt.config)->samll_core_num_in_big_core,
         (g_rt.config)->big_core,(g_rt.config)->patter_num);
  snprintf(tmp1,0x100,"var:%d,%d,%d",(g_rt.config)->samll_core_num_in_big_core,
           (g_rt.config)->big_core,(g_rt.config)->patter_num);
  log_to_file(tmp1,time_stamp);
  for (asic = 0; asic < (g_rt.config)->asics; asic = asic + 1) {
    ppVar2 = g_rt.works[asic];
    for (core = 0; iVar1 = (g_rt.config)->big_core * (g_rt.config)->samll_core_num_in_big_core,
        iVar1 - core != 0 && core <= iVar1; core = core + 1) {
      for (pattern = 0; pattern < (g_rt.config)->patter_num; pattern = pattern + 1) {
        ppVar2[pattern + core * (g_rt.config)->patter_num].nonce_repeat = 0;
      }
    }
  }
  return;
}

