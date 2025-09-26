
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void test_singal(void)

{
  pthread_cond_signal((pthread_cond_t *)&upload_cond);
  return;
}

