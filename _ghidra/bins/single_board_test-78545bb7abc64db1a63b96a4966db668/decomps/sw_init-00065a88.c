
int sw_init(void *conf,void *sweep)

{
  int32_t iVar1;
  code *pcVar2;
  void *sweep_local;
  void *conf_local;
  config_ctx *conf_temp;
  
  sw_break = 0;
  memset(&g_rt,0,0x846e8);
  if (*(char *)((int)conf + 0x30) == '\0') {
    pcVar2 = (_func_int32_t_uint32_t_void_ptr *)0x64c85;
  }
  else {
    pcVar2 = (code *)0x653ad;
  }
  g_rt.pt_ops.init = (code *)0x646a9;
  g_rt.pt_ops.exit = (code *)0x646c1;
  g_rt.pt_ops.clear_stats = (code *)0x64709;
  g_rt.pt_ops.reset = (code *)0x64721;
  g_rt.pt_ops.process_nonce = (code *)0x64c55;
  g_rt.pt_ops.process_reg = (code *)0x64c6d;
  g_rt.pt_ops.send_work = pcVar2;
  g_rt.pt_ops.get_stats = (code *)0x65751;
  g_rt.pt_ops.is_unbalance_happen = (code *)0x65761;
  g_rt.pt_ops.is_recv_nonce_enough = (code *)0x65a71;
  memcpy(&g_rt.sweep,sweep,0x50);
  if (*(char *)((int)conf + 0x30) == '\0') {
    memcpy(g_rt.works_new,g_works_new,0x400);
  }
  else {
    g_rt.works[0] = g_works[0];
  }
  iVar1 = pt_init("/mnt/card/BM1370-pattern/pattern_16midstate.bin",conf);
  return iVar1;
}

