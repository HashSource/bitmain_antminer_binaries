
void * tq_pop(thread_q *tq,timespec *abstime)

{
  int iVar1;
  list_head *entry;
  list_head **__ptr;
  timespec *abstime_local;
  thread_q *tq_local;
  char tmp42 [2048];
  tq_ent *ent;
  int ret;
  int rc;
  void *rval;
  
  rval = (void *)0x0;
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s line %d","tq_pop",0x492);
    _applog(7,tmp42,false);
  }
  iVar1 = _mutex_trylock(&tq->mutex,"util.c","tq_pop",0x493);
  if (iVar1 != 0) {
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
      return (void *)0x0;
    }
    snprintf(tmp42,0x800,"mutex_trylock failed in %s %d","tq_pop",iVar1);
    _applog(4,tmp42,false);
    return (void *)0x0;
  }
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
  _mutex_unlock(&tq->mutex,"util.c","tq_pop",0x4b7);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s line %d","tq_pop",0x4b8);
    _applog(7,tmp42,false);
  }
  return rval;
}

