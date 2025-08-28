
/* WARNING: Unknown calling convention */

void clear_sock(pool *pool)

{
  int iVar1;
  ssize_t sVar2;
  char *func;
  int line;
  int line_00;
  int extraout_r3;
  int extraout_r3_00;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&pool->stratum_lock);
  line_00 = line;
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"clear_sock",(char *)0x6e5,func,line);
    line_00 = extraout_r3_00;
  }
  do {
    if (pool->sock == 0) break;
    sVar2 = recv(pool->sock,pool->sockbuf,0x1ffc,0);
    line_00 = extraout_r3;
  } while (0 < sVar2);
  _mutex_unlock_noyield(&pool->stratum_lock,"clear_sock",(char *)0x6ee,line_00);
  (*selective_yield)();
  clear_sockbuf(pool);
  return;
}

