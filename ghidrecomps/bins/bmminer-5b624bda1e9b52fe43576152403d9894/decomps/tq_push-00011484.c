
/* WARNING: Unknown calling convention */

_Bool tq_push(thread_q *tq,void *data)

{
  bool bVar1;
  void **__ptr;
  tq_ent *ent;
  int iVar2;
  char *func;
  pthread_mutex_t *line;
  list_head *line_00;
  list_head *plVar3;
  
  func = DAT_00011504;
  line = DAT_00011508;
  __ptr = (void **)_cgcalloc(1,0xc,DAT_00011504,DAT_00011508->__size,0x469);
  plVar3 = (list_head *)(__ptr + 1);
  *__ptr = data;
  __ptr[1] = plVar3;
  __ptr[2] = plVar3;
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&tq->mutex);
  if (iVar2 != 0) {
    _mutex_lock(DAT_00011508,(char *)0x46d,func,(int)line);
  }
  line_00 = (list_head *)(uint)tq->frozen;
  bVar1 = line_00 != (list_head *)0x0;
  if (bVar1) {
    free(__ptr);
  }
  else {
    line_00 = (tq->q).prev;
    __ptr[1] = tq;
    (tq->q).prev = plVar3;
    line_00->next = plVar3;
    __ptr[2] = line_00;
  }
  pthread_cond_signal((pthread_cond_t *)&tq->cond);
  _mutex_unlock_noyield(&tq->mutex,DAT_00011508->__size,(char *)0x47a,(int)line_00);
  (**DAT_0001150c)();
  return !bVar1;
}

