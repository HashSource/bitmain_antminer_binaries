
/* WARNING: Unknown calling convention */

_Bool tq_push(thread_q *tq,void *data)

{
  bool bVar1;
  undefined4 *__ptr;
  int iVar2;
  char *func;
  int line;
  list_head *plVar3;
  int line_00;
  list_head *plVar4;
  
  __ptr = (undefined4 *)_cgcalloc(1,0xc,"util.c","tq_push",0x469);
  plVar4 = (list_head *)(__ptr + 1);
  *__ptr = data;
  __ptr[1] = plVar4;
  __ptr[2] = plVar4;
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&tq->mutex);
  if (iVar2 != 0) {
    _mutex_lock((pthread_mutex_t *)"tq_push",(char *)0x46d,func,line);
  }
  bVar1 = tq->frozen != false;
  if (bVar1) {
    free(__ptr);
  }
  else {
    plVar3 = (tq->q).prev;
    __ptr[1] = tq;
    (tq->q).prev = plVar4;
    plVar3->next = plVar4;
    __ptr[2] = plVar3;
  }
  pthread_cond_signal((pthread_cond_t *)&tq->cond);
  _mutex_unlock_noyield(&tq->mutex,"tq_push",(char *)0x47a,line_00);
  (*selective_yield)();
  return !bVar1;
}

