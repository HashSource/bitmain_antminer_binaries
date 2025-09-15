
void flush_queue(cgpu_info *cgpu)

{
  int iVar1;
  cgpu_info *cgpu_local;
  char tmp42 [2048];
  work *work;
  
  work = (work *)0x0;
  if ((cgpu != (cgpu_info *)0x0) &&
     (iVar1 = _wr_trylock(&cgpu->qlock,"cgminer.c","flush_queue",0x256e), iVar1 == 0)) {
    work = cgpu->unqueued_work;
    cgpu->unqueued_work = (work *)0x0;
    _wr_unlock(&cgpu->qlock,"cgminer.c","flush_queue",0x2575);
    if (((work != (work *)0x0) &&
        (_free_work(&work,"cgminer.c","flush_queue",0x2579), opt_debug != false)) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Discarded queued work it",0x18);
      tmp42[0x18] = 'e';
      tmp42[0x19] = 'm';
      tmp42[0x1a] = '\0';
      _applog(7,tmp42,false);
    }
  }
  return;
}

