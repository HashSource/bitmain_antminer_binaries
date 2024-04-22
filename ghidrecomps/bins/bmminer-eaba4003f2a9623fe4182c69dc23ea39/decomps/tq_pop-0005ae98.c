
void * tq_pop(thread_q *tq,timespec *abstime)

{
  int iVar1;
  list_head *entry;
  list_head **__ptr;
  timespec *abstime_local;
  thread_q *tq_local;
  tq_ent *ent;
  int rc;
  void *rval;
  
  rval = (void *)0x0;
  _mutex_lock(&tq->mutex,"util.c","tq_pop",0x486);
  iVar1 = list_empty(&tq->q);
  if (iVar1 != 0) {
    if (abstime == (timespec *)0x0) {
      rc = pthread_cond_wait((pthread_cond_t *)&tq->cond,(pthread_mutex_t *)&tq->mutex);
    }
    else {
      rc = pthread_cond_timedwait
                     ((pthread_cond_t *)&tq->cond,(pthread_mutex_t *)&tq->mutex,(timespec *)abstime)
      ;
    }
    if ((rc != 0) || (iVar1 = list_empty(&tq->q), iVar1 != 0)) goto out;
  }
  entry = (tq->q).next;
  __ptr = &entry[-1].prev;
  rval = *__ptr;
  list_del(entry);
  free(__ptr);
out:
  _mutex_unlock(&tq->mutex,"util.c","tq_pop",0x4a0);
  return rval;
}

