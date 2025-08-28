
void _discard_work(work **workptr,char *file,char *func,int line)

{
  work *pwVar1;
  bool bVar2;
  int line_local;
  char *func_local;
  char *file_local;
  work **workptr_local;
  char tmp42 [2048];
  work *work;
  
  pwVar1 = *workptr;
  if (pwVar1 == (work *)0x0) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"Discard work called with NULL work from %s %s:%d",file,func,line);
      _applog(3,tmp42,false);
    }
  }
  else {
    if (((pwVar1->clone == true) || (pwVar1->rolls != 0)) || (pwVar1->mined == true)) {
      if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Discarded cloned or rolled work",0x20);
        _applog(7,tmp42,false);
      }
    }
    else {
      if (pwVar1->pool != (pool *)0x0) {
        pwVar1->pool->discarded_work = pwVar1->pool->discarded_work + 1;
        pwVar1->pool->quota_used = pwVar1->pool->quota_used + -1;
        pwVar1->pool->works = pwVar1->pool->works + -1;
      }
      bVar2 = 0xfffffffe < (uint)total_discarded;
      total_discarded._0_4_ = (uint)total_discarded + 1;
      total_discarded._4_4_ = total_discarded._4_4_ + (uint)bVar2;
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Discarded wo",0xc);
        tmp42[0xc] = 'r';
        tmp42[0xd] = 'k';
        tmp42[0xe] = '\0';
        _applog(7,tmp42,false);
      }
    }
    _free_work(workptr,file,func,line);
  }
  return;
}

