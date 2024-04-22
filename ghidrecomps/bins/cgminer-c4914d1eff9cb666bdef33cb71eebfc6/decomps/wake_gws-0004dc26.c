
/* WARNING: Unknown calling convention */

void wake_gws(void)

{
  _mutex_lock(stgd_lock,"cgminer.c","wake_gws",0x14e5);
  pthread_cond_signal((pthread_cond_t *)&gws_cond);
  _mutex_unlock(stgd_lock,"cgminer.c","wake_gws",0x14e7);
  return;
}

