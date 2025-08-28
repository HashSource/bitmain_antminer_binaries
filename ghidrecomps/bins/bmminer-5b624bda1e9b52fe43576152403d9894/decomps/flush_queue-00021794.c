
/* WARNING: Unknown calling convention */

void flush_queue(cgpu_info *cgpu)

{
  int iVar1;
  char *func;
  int line;
  work *work;
  char tmp42 [2048];
  
  work = (work *)0x0;
  if (cgpu != (cgpu_info *)0x0) {
    iVar1 = pthread_rwlock_trywrlock((pthread_rwlock_t *)&cgpu->qlock);
    if (iVar1 == 0) {
      work = cgpu->unqueued_work;
      cgpu->unqueued_work = (work *)0x0;
      iVar1 = pthread_rwlock_unlock((pthread_rwlock_t *)&cgpu->qlock);
      if (iVar1 != 0) {
        _rw_unlock((pthread_rwlock_t *)"flush_queue",(char *)0x2520,func,line);
      }
      (*selective_yield)();
      if (((work != (work *)0x0) &&
          (_free_work(&work,"cgminer.c","flush_queue",0x2524), opt_debug != false)) &&
         ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
        builtin_strncpy(tmp42,"Discarded queued work it",0x18);
        tmp42[0x18] = 'e';
        tmp42[0x19] = 'm';
        tmp42[0x1a] = '\0';
        _applog(7,tmp42,false);
      }
    }
  }
  return;
}

