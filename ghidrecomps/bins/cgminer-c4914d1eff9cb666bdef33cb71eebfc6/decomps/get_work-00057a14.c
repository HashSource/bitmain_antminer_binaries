
work * get_work(thr_info *thr,int thr_id)

{
  _Bool _Var1;
  time_t tVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int thr_id_local;
  thr_info *thr_local;
  char tmp42 [2048];
  work *work;
  time_t diff_t;
  cgpu_info *cgpu;
  
  cgpu = thr->cgpu;
  work = (work *)0x0;
  thread_reportout(thr);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"Popping work from get queue to get work",0x28);
    _applog(7,tmp42,false);
  }
  diff_t = time((time_t *)0x0);
  while (work == (work *)0x0) {
    work = hash_pop(true);
    _Var1 = stale_work(work,false);
    if (_Var1) {
      _discard_work(&work,"cgminer.c","get_work",0x21a1);
      wake_gws();
    }
  }
  tVar2 = time((time_t *)0x0);
  diff_t = tVar2 - diff_t;
  if (0 < diff_t) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Get work blocked for %ld seconds",diff_t);
      _applog(7,tmp42,false);
    }
    cgpu->last_device_valid_work = cgpu->last_device_valid_work + diff_t;
  }
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Got work from get queue to get work for thread %d",thr_id);
    _applog(7,tmp42,false);
  }
  work->thr_id = thr_id;
  if (opt_benchmark != false) {
    set_benchmark_work(cgpu,work);
  }
  thread_reportin(thr);
  work->mined = true;
  if (cgpu->drv->max_diff <= work->work_difficulty) {
    uVar3 = *(undefined4 *)&cgpu->drv->max_diff;
    uVar4 = *(undefined4 *)((int)&cgpu->drv->max_diff + 4);
  }
  else {
    uVar3 = *(undefined4 *)&work->work_difficulty;
    uVar4 = *(undefined4 *)((int)&work->work_difficulty + 4);
  }
  *(undefined4 *)&work->device_diff = uVar3;
  *(undefined4 *)((int)&work->device_diff + 4) = uVar4;
  if (cgpu->drv->min_diff <= work->device_diff) {
    uVar3 = *(undefined4 *)&work->device_diff;
    uVar4 = *(undefined4 *)((int)&work->device_diff + 4);
  }
  else {
    uVar3 = *(undefined4 *)&cgpu->drv->min_diff;
    uVar4 = *(undefined4 *)((int)&cgpu->drv->min_diff + 4);
  }
  *(undefined4 *)&work->device_diff = uVar3;
  *(undefined4 *)((int)&work->device_diff + 4) = uVar4;
  return work;
}

