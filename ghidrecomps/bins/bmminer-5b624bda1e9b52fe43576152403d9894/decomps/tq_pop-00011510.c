
/* WARNING: Unknown calling convention */

void * tq_pop(thread_q *tq,timespec *abstime)

{
  int iVar1;
  int rc;
  list_head *plVar2;
  char *in_r2;
  int in_r3;
  thread_q *line;
  list_head *plVar3;
  pthread_mutex_t *__mutex;
  void *pvVar4;
  
  __mutex = &tq->mutex;
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)__mutex);
  if (iVar1 != 0) {
    _mutex_lock(DAT_00011590,(char *)0x486,in_r2,in_r3);
  }
  line = (thread_q *)(tq->q).next;
  if (tq == line) {
    if (abstime == (timespec *)0x0) {
      rc = pthread_cond_wait((pthread_cond_t *)&tq->cond,(pthread_mutex_t *)__mutex);
    }
    else {
      rc = pthread_cond_timedwait
                     ((pthread_cond_t *)&tq->cond,(pthread_mutex_t *)__mutex,(timespec *)abstime);
    }
    if (rc != 0) {
      pvVar4 = (void *)0x0;
      goto out;
    }
    line = (thread_q *)(tq->q).next;
    if (tq == line) {
      pvVar4 = (void *)0x0;
      goto out;
    }
  }
  plVar2 = (line->q).prev;
  plVar3 = (line->q).next;
  pvVar4 = *(void **)((int)&line[-1].cond + 0x2c);
  plVar3->prev = plVar2;
  plVar2->next = plVar3;
  (line->q).prev = (list_head *)0x0;
  (line->q).next = (list_head *)0x0;
  free((void *)((int)&line[-1].cond + 0x2c));
out:
  _mutex_unlock_noyield(__mutex,DAT_00011590->__size,(char *)0x4a0,(int)line);
  (**DAT_00011594)();
  return pvVar4;
}

