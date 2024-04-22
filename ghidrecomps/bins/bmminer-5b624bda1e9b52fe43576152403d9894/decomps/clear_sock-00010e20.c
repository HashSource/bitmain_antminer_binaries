
/* WARNING: Unknown calling convention */

void clear_sock(pool *pool)

{
  int iVar1;
  ssize_t sVar2;
  ssize_t n;
  char *in_r2;
  int in_r3;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&pool->stratum_lock);
  if (iVar1 != 0) {
    _mutex_lock(DAT_00010e74,(char *)0x6e5,in_r2,in_r3);
  }
  do {
    if (pool->sock == 0) break;
    in_r3 = 0;
    sVar2 = recv(pool->sock,pool->sockbuf,0x1ffc,0);
  } while (0 < sVar2);
  _mutex_unlock_noyield(&pool->stratum_lock,DAT_00010e74->__size,(char *)0x6ee,in_r3);
  (**DAT_00010e78)();
  clear_sockbuf(pool);
  return;
}

