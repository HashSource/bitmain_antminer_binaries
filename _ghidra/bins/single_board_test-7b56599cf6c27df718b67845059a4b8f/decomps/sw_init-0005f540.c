
int sw_init(void *conf,void *sweep)

{
  int32_t iVar1;
  void *sweep_local;
  void *conf_local;
  
  sw_break = 0;
  memset(&g_rt,0,0x23678);
  g_rt.pt_ops.init = (code *)0x5e481;
  g_rt.pt_ops.exit = (code *)0x5e499;
  g_rt.pt_ops.clear_stats = (code *)0x5e4e5;
  g_rt.pt_ops.reset = (code *)0x5e4fd;
  g_rt.pt_ops.process_nonce = (code *)0x5ea51;
  g_rt.pt_ops.process_reg = (code *)0x5ea6d;
  g_rt.pt_ops.send_work = (code *)0x5ea85;
  g_rt.pt_ops.get_stats = (code *)0x5f209;
  g_rt.pt_ops.is_unbalance_happen = (code *)0x5f219;
  g_rt.pt_ops.is_recv_nonce_enough = (code *)0x5f529;
  memcpy(&g_rt.sweep,sweep,0x50);
  memcpy(g_rt.works,g_works,0x1b0);
  iVar1 = pt_init("/mnt/card/BM1368-pattern/pattern_16midstate.bin",conf);
  return iVar1;
}

