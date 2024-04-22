
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void kill_work(void)

{
  char tmp42 [2048];
  
  cg_completion_timeout(__kill_work + 1,(void *)0x0,5000);
  tmp42[0] = s_Shutdown_signal_received__0004c2b0[0];
  tmp42[1] = s_Shutdown_signal_received__0004c2b0[1];
  tmp42[2] = s_Shutdown_signal_received__0004c2b0[2];
  tmp42[3] = s_Shutdown_signal_received__0004c2b0[3];
  tmp42[4] = s_Shutdown_signal_received__0004c2b0[4];
  tmp42[5] = s_Shutdown_signal_received__0004c2b0[5];
  tmp42[6] = s_Shutdown_signal_received__0004c2b0[6];
  tmp42[7] = s_Shutdown_signal_received__0004c2b0[7];
  tmp42[8] = s_Shutdown_signal_received__0004c2b0[8];
  tmp42[9] = s_Shutdown_signal_received__0004c2b0[9];
  tmp42[10] = s_Shutdown_signal_received__0004c2b0[10];
  tmp42[11] = s_Shutdown_signal_received__0004c2b0[11];
  tmp42[12] = s_Shutdown_signal_received__0004c2b0[12];
  tmp42[13] = s_Shutdown_signal_received__0004c2b0[13];
  tmp42[14] = s_Shutdown_signal_received__0004c2b0[14];
  tmp42[15] = s_Shutdown_signal_received__0004c2b0[15];
  tmp42[16] = s_Shutdown_signal_received__0004c2b0[16];
  tmp42[17] = s_Shutdown_signal_received__0004c2b0[17];
  tmp42[18] = s_Shutdown_signal_received__0004c2b0[18];
  tmp42[19] = s_Shutdown_signal_received__0004c2b0[19];
  tmp42[20] = s_Shutdown_signal_received__0004c2b0[20];
  tmp42[21] = s_Shutdown_signal_received__0004c2b0[21];
  tmp42[22] = s_Shutdown_signal_received__0004c2b0[22];
  tmp42[23] = s_Shutdown_signal_received__0004c2b0[23];
  tmp42._24_2_ = (undefined2)ram0x0004c2c8;
  _applog(3,tmp42,true);
  _quit(0);
  return;
}

