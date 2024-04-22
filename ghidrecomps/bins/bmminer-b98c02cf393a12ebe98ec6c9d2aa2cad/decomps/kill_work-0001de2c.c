
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void kill_work(void)

{
  undefined4 local_808;
  undefined4 uStack_804;
  undefined4 uStack_800;
  undefined4 uStack_7fc;
  undefined4 local_7f8;
  undefined4 uStack_7f4;
  undefined2 local_7f0;
  
  cg_completion_timeout(0x20795,0,5000);
  local_808._0_1_ = s_Shutdown_signal_received__0005c894[0];
  local_808._1_1_ = s_Shutdown_signal_received__0005c894[1];
  local_808._2_1_ = s_Shutdown_signal_received__0005c894[2];
  local_808._3_1_ = s_Shutdown_signal_received__0005c894[3];
  uStack_804._0_1_ = s_Shutdown_signal_received__0005c894[4];
  uStack_804._1_1_ = s_Shutdown_signal_received__0005c894[5];
  uStack_804._2_1_ = s_Shutdown_signal_received__0005c894[6];
  uStack_804._3_1_ = s_Shutdown_signal_received__0005c894[7];
  uStack_800._0_1_ = s_Shutdown_signal_received__0005c894[8];
  uStack_800._1_1_ = s_Shutdown_signal_received__0005c894[9];
  uStack_800._2_1_ = s_Shutdown_signal_received__0005c894[10];
  uStack_800._3_1_ = s_Shutdown_signal_received__0005c894[11];
  uStack_7fc._0_1_ = s_Shutdown_signal_received__0005c894[12];
  uStack_7fc._1_1_ = s_Shutdown_signal_received__0005c894[13];
  uStack_7fc._2_1_ = s_Shutdown_signal_received__0005c894[14];
  uStack_7fc._3_1_ = s_Shutdown_signal_received__0005c894[15];
  local_7f8._0_1_ = s_Shutdown_signal_received__0005c894[16];
  local_7f8._1_1_ = s_Shutdown_signal_received__0005c894[17];
  local_7f8._2_1_ = s_Shutdown_signal_received__0005c894[18];
  local_7f8._3_1_ = s_Shutdown_signal_received__0005c894[19];
  uStack_7f4._0_1_ = s_Shutdown_signal_received__0005c894[20];
  uStack_7f4._1_1_ = s_Shutdown_signal_received__0005c894[21];
  uStack_7f4._2_1_ = s_Shutdown_signal_received__0005c894[22];
  uStack_7f4._3_1_ = s_Shutdown_signal_received__0005c894[23];
  local_7f0 = (undefined2)ram0x0005c8ac;
  _applog(3,&local_808,1);
                    /* WARNING: Subroutine does not return */
  __quit(0,1);
}

