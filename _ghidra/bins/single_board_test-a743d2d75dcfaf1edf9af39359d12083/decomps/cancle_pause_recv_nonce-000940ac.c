
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void cancle_pause_recv_nonce(void)

{
  g_rt.pause_recv_nonce = 0;
  return;
}

