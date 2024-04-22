
_Bool tq_push(thread_q *tq,void *data)

{
  void **__ptr;
  bool bVar1;
  void *data_local;
  thread_q *tq_local;
  char tmp42 [2048];
  tq_ent *ent;
  _Bool rc;
  
  __ptr = (void **)_cgcalloc(1,0xc,"util.c","tq_push",0x474);
  *__ptr = data;
  __ptr[1] = __ptr + 1;
  __ptr[2] = __ptr + 1;
  _mutex_lock(&tq->mutex,"util.c","tq_push",0x478);
  bVar1 = tq->frozen == true;
  if (bVar1) {
    free(__ptr);
  }
  else {
    list_add_tail((list_head *)(__ptr + 1),&tq->q);
  }
  rc = !bVar1;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s line %d","tq_push",0x483);
    _applog(7,tmp42,false);
  }
  pthread_cond_signal((pthread_cond_t *)&tq->cond);
  _mutex_unlock(&tq->mutex,"util.c","tq_push",0x485);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s line %d","tq_push",0x486);
    _applog(7,tmp42,false);
  }
  return rc;
}

