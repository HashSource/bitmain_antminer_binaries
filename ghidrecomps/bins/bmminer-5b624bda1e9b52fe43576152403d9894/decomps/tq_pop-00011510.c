
/* WARNING: Unknown calling convention */

void * tq_pop(thread_q *tq,timespec *abstime)

{
  int iVar1;
  list_head *plVar2;
  char *func;
  int line;
  thread_q *line_00;
  thread_q *extraout_r3;
  thread_q *extraout_r3_00;
  thread_q *extraout_r3_01;
  list_head *plVar3;
  pthread_mutex_t *__mutex;
  void *pvVar4;
  
  __mutex = &tq->mutex;
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)__mutex);
  if (iVar1 != 0) {
    _mutex_lock((pthread_mutex_t *)"tq_pop",(char *)0x486,func,line);
  }
  line_00 = (thread_q *)(tq->q).next;
  if (tq == line_00) {
    if (abstime == (timespec *)0x0) {
      iVar1 = pthread_cond_wait((pthread_cond_t *)&tq->cond,(pthread_mutex_t *)__mutex);
      line_00 = extraout_r3_01;
    }
    else {
      iVar1 = pthread_cond_timedwait
                        ((pthread_cond_t *)&tq->cond,(pthread_mutex_t *)__mutex,(timespec *)abstime)
      ;
      line_00 = extraout_r3_00;
    }
    if (iVar1 != 0) {
      pvVar4 = (void *)0x0;
      goto LAB_00011542;
    }
    line_00 = (thread_q *)(tq->q).next;
    if (tq == line_00) {
      pvVar4 = (void *)0x0;
      goto LAB_00011542;
    }
  }
  plVar2 = (line_00->q).prev;
  plVar3 = (line_00->q).next;
  pvVar4 = *(void **)((int)&line_00[-1].cond + 0x2c);
  plVar3->prev = plVar2;
  plVar2->next = plVar3;
  (line_00->q).prev = (list_head *)0x0;
  (line_00->q).next = (list_head *)0x0;
  free((void *)((int)&line_00[-1].cond + 0x2c));
  line_00 = extraout_r3;
LAB_00011542:
  _mutex_unlock_noyield(__mutex,"tq_pop",(char *)0x4a0,(int)line_00);
  (*selective_yield)();
  return pvVar4;
}

