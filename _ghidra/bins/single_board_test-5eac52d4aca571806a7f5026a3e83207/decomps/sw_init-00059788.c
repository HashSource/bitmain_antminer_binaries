
int sw_init(void *conf,void *sweep)

{
  int32_t iVar1;
  void *sweep_local;
  void *conf_local;
  
  sw_break = 0;
  memset(&g_rt,0,0x21918);
  g_rt.pt_ops.init = (code *)0x587cd;
  g_rt.pt_ops.exit = (code *)0x587e5;
  g_rt.pt_ops.clear_stats = (code *)0x58829;
  g_rt.pt_ops.reset = (code *)0x58841;
  g_rt.pt_ops.process_nonce = (code *)0x58d59;
  g_rt.pt_ops.process_reg = (code *)0x58d75;
  g_rt.pt_ops.send_work = (code *)0x58d8d;
  g_rt.pt_ops.get_stats = (code *)0x5946d;
  g_rt.pt_ops.is_unbalance_happen = (code *)0x5947d;
  g_rt.pt_ops.is_recv_nonce_enough = (code *)0x59771;
  memcpy(&g_rt.sweep,sweep,0x50);
  memcpy(g_rt.works,g_works,0x104);
  iVar1 = pt_init("/mnt/card/BM1370-pattern/pattern_16midstate.bin",conf);
  return iVar1;
}

