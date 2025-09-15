
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void patten_info_destory(void)

{
  if (g_patten.patten_start != (uchar *)0x0) {
    free(g_patten.patten_start);
  }
  if (g_patten.is_nonce_match != (uchar *)0x0) {
    free(g_patten.is_nonce_match);
  }
  if (g_patten.asic_recv_nonces != (int *)0x0) {
    free(g_patten.asic_recv_nonces);
  }
  pthread_mutex_destroy((pthread_mutex_t *)&g_patten.patten_mutex);
  return;
}

