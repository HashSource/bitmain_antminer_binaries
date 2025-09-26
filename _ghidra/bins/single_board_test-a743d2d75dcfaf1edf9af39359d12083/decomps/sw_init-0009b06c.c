
int sw_init(void *conf,void *sweep)

{
  int32_t iVar1;
  code *pcVar2;
  void *sweep_local;
  void *conf_local;
  config_ctx *conf_temp;
  
  sw_break = 0;
  memset(&g_rt,0,0x55578);
  if (*(char *)((int)conf + 0x2c) == '\0') {
    pcVar2 = (_func_int32_t_uint32_t_void_ptr *)0x99fe1;
  }
  else {
    pcVar2 = (code *)0x9a619;
  }
  g_rt.pt_ops.init = (code *)0x99281;
  g_rt.pt_ops.exit = (code *)0x994a9;
  g_rt.pt_ops.clear_stats = (code *)0x994f5;
  g_rt.pt_ops.reset = (code *)0x9950d;
  g_rt.pt_ops.process_nonce = (code *)0x99fad;
  g_rt.pt_ops.process_reg = (code *)0x99fc9;
  g_rt.pt_ops.send_work = pcVar2;
  g_rt.pt_ops.get_stats = (code *)0x9a9bd;
  g_rt.pt_ops.is_unbalance_happen = (code *)0x9a9cd;
  g_rt.pt_ops.is_recv_nonce_enough = (code *)0x9ace1;
  memcpy(&g_rt.sweep,sweep,0x50);
  g_rt.enable_get_register = 1;
  g_rt.pause_read_asic_temp = 0;
  if (*(char *)((int)conf + 0x2c) == '\0') {
    memcpy(g_rt.works_new,g_works_new,0x400);
  }
  else {
    g_rt.works[0] = g_works[0];
  }
  iVar1 = pt_init("/mnt/card/BM1370-pattern/pattern_16midstate.bin",conf);
  return iVar1;
}

