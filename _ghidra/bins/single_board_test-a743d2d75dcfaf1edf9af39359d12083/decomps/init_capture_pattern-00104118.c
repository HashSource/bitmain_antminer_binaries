
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void init_capture_pattern(void)

{
  memset(g_noncemap,0,0x4000);
  memset(g_unique_nonce,0,0x1c00);
  memset(g_asic_unique_nonce,0,0x1c00);
  pthread_mutex_init((pthread_mutex_t *)&g_map_mutex,(pthread_mutexattr_t *)0x0);
  fd_log0 = (FILE *)0x0;
  fd_log = (FILE *)0x0;
  return;
}

