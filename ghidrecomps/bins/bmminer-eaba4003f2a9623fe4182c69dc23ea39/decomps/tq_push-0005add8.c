
_Bool tq_push(thread_q *tq,void *data)

{
  void **__ptr;
  bool bVar1;
  void *data_local;
  thread_q *tq_local;
  tq_ent *ent;
  _Bool rc;
  
  __ptr = (void **)_cgcalloc(1,0xc,"util.c","tq_push",0x469);
  *__ptr = data;
  __ptr[1] = __ptr + 1;
  __ptr[2] = __ptr + 1;
  _mutex_lock(&tq->mutex,"util.c","tq_push",0x46d);
  bVar1 = tq->frozen == true;
  if (bVar1) {
    free(__ptr);
  }
  else {
    list_add_tail((list_head *)(__ptr + 1),&tq->q);
  }
  rc = !bVar1;
  pthread_cond_signal((pthread_cond_t *)&tq->cond);
  _mutex_unlock(&tq->mutex,"util.c","tq_push",0x47a);
  return rc;
}

