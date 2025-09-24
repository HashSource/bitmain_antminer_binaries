
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void pause_recv_nonce(void)

{
  g_rt.pause_recv_nonce = 1;
  return;
}

