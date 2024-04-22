
/* WARNING: Unknown calling convention */

void tq_freezethaw(thread_q *tq,_Bool frozen)

{
  int iVar1;
  char *in_r2;
  int in_r3;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&tq->mutex);
  if (iVar1 != 0) {
    _mutex_lock(DAT_00010eb8,(char *)0x454,in_r2,in_r3);
  }
  tq->frozen = frozen;
  pthread_cond_signal((pthread_cond_t *)&tq->cond);
  _mutex_unlock_noyield(&tq->mutex,DAT_00010eb8->__size,(char *)0x457,in_r3);
  (**DAT_00010ebc)();
  return;
}

