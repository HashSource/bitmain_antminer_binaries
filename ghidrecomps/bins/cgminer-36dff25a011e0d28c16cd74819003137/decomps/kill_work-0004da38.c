
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void kill_work(void)

{
  char tmp42 [2048];
  
  cg_completion_timeout(__kill_work,(void *)0x0,5000);
  tmp42[0] = s_Shutdown_signal_received__000a3a88[0];
  tmp42[1] = s_Shutdown_signal_received__000a3a88[1];
  tmp42[2] = s_Shutdown_signal_received__000a3a88[2];
  tmp42[3] = s_Shutdown_signal_received__000a3a88[3];
  tmp42[4] = s_Shutdown_signal_received__000a3a88[4];
  tmp42[5] = s_Shutdown_signal_received__000a3a88[5];
  tmp42[6] = s_Shutdown_signal_received__000a3a88[6];
  tmp42[7] = s_Shutdown_signal_received__000a3a88[7];
  tmp42[8] = s_Shutdown_signal_received__000a3a88[8];
  tmp42[9] = s_Shutdown_signal_received__000a3a88[9];
  tmp42[10] = s_Shutdown_signal_received__000a3a88[10];
  tmp42[11] = s_Shutdown_signal_received__000a3a88[11];
  tmp42[12] = s_Shutdown_signal_received__000a3a88[12];
  tmp42[13] = s_Shutdown_signal_received__000a3a88[13];
  tmp42[14] = s_Shutdown_signal_received__000a3a88[14];
  tmp42[15] = s_Shutdown_signal_received__000a3a88[15];
  tmp42[16] = s_Shutdown_signal_received__000a3a88[16];
  tmp42[17] = s_Shutdown_signal_received__000a3a88[17];
  tmp42[18] = s_Shutdown_signal_received__000a3a88[18];
  tmp42[19] = s_Shutdown_signal_received__000a3a88[19];
  tmp42[20] = s_Shutdown_signal_received__000a3a88[20];
  tmp42[21] = s_Shutdown_signal_received__000a3a88[21];
  tmp42[22] = s_Shutdown_signal_received__000a3a88[22];
  tmp42[23] = s_Shutdown_signal_received__000a3a88[23];
  tmp42._24_2_ = (undefined2)ram0x000a3aa0;
  _applog(3,tmp42,true);
  _quit(0);
  return;
}

