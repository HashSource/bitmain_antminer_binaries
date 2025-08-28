
/* WARNING: Unknown calling convention */

void tq_freezethaw(thread_q *tq,_Bool frozen)

{
  int iVar1;
  char *func;
  int line;
  int line_00;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&tq->mutex);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"tq_freezethaw",(char *)0x454,func,line);
  }
  tq->frozen = frozen;
  pthread_cond_signal((pthread_cond_t *)&tq->cond);
  _mutex_unlock_noyield(&tq->mutex,"tq_freezethaw",(char *)0x457,line_00);
  (*selective_yield)();
  return;
}

