
void tq_freezethaw(thread_q *tq,_Bool frozen)

{
  _Bool frozen_local;
  thread_q *tq_local;
  
  _mutex_lock(&tq->mutex,"util.c","tq_freezethaw",0x454);
  tq->frozen = frozen;
  pthread_cond_signal((pthread_cond_t *)&tq->cond);
  _mutex_unlock(&tq->mutex,"util.c","tq_freezethaw",0x457);
  return;
}

