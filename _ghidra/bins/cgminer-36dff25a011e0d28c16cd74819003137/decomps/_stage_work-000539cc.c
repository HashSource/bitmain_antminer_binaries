
void _stage_work(work *work)

{
  work *work_local;
  char tmp42 [2048];
  
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Pushing work from pool %d to hash queue",work->pool->pool_no);
    _applog(7,tmp42,false);
  }
  work->work_block = work_block;
  test_work_current(work);
  work->pool->works = work->pool->works + 1;
  hash_push(work);
  return;
}

