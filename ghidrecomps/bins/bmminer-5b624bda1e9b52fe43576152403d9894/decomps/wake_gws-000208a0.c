
/* WARNING: Unknown calling convention */

void wake_gws(void)

{
  int iVar1;
  int iVar2;
  char *in_r2;
  int in_r3;
  
  iVar2 = DAT_000208e0;
  iVar1 = pthread_mutex_lock(*(pthread_mutex_t **)(DAT_000208e0 + 0x454));
  if (iVar1 != 0) {
    _mutex_lock(DAT_000208ec,(char *)0x1494,in_r2,in_r3);
  }
  pthread_cond_signal(DAT_000208e4);
  iVar2 = pthread_mutex_unlock(*(pthread_mutex_t **)(iVar2 + 0x454));
  if (iVar2 != 0) {
    _mutex_unlock_noyield(DAT_000208ec,(char *)0x1496,in_r2,in_r3);
  }
  (**DAT_000208e8)();
  return;
}

