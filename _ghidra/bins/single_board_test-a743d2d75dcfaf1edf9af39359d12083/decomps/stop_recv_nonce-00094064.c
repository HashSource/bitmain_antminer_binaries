
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void stop_recv_nonce(void)

{
  g_rt.recv_nonce = 0;
  return;
}

