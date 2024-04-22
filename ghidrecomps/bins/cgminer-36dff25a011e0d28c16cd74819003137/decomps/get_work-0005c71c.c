
work * get_work(thr_info *thr,int thr_id)

{
  _Bool _Var1;
  time_t tVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
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
    tmp42[0] = s_Popping_work_from_get_queue_to_g_000a4b98[0];
    tmp42[1] = s_Popping_work_from_get_queue_to_g_000a4b98[1];
    tmp42[2] = s_Popping_work_from_get_queue_to_g_000a4b98[2];
    tmp42[3] = s_Popping_work_from_get_queue_to_g_000a4b98[3];
    tmp42[4] = s_Popping_work_from_get_queue_to_g_000a4b98[4];
    tmp42[5] = s_Popping_work_from_get_queue_to_g_000a4b98[5];
    tmp42[6] = s_Popping_work_from_get_queue_to_g_000a4b98[6];
    tmp42[7] = s_Popping_work_from_get_queue_to_g_000a4b98[7];
    tmp42[8] = s_Popping_work_from_get_queue_to_g_000a4b98[8];
    tmp42[9] = s_Popping_work_from_get_queue_to_g_000a4b98[9];
    tmp42[10] = s_Popping_work_from_get_queue_to_g_000a4b98[10];
    tmp42[11] = s_Popping_work_from_get_queue_to_g_000a4b98[11];
    tmp42[12] = s_Popping_work_from_get_queue_to_g_000a4b98[12];
    tmp42[13] = s_Popping_work_from_get_queue_to_g_000a4b98[13];
    tmp42[14] = s_Popping_work_from_get_queue_to_g_000a4b98[14];
    tmp42[15] = s_Popping_work_from_get_queue_to_g_000a4b98[15];
    tmp42[16] = s_Popping_work_from_get_queue_to_g_000a4b98[16];
    tmp42[17] = s_Popping_work_from_get_queue_to_g_000a4b98[17];
    tmp42[18] = s_Popping_work_from_get_queue_to_g_000a4b98[18];
    tmp42[19] = s_Popping_work_from_get_queue_to_g_000a4b98[19];
    tmp42[20] = s_Popping_work_from_get_queue_to_g_000a4b98[20];
    tmp42[21] = s_Popping_work_from_get_queue_to_g_000a4b98[21];
    tmp42[22] = s_Popping_work_from_get_queue_to_g_000a4b98[22];
    tmp42[23] = s_Popping_work_from_get_queue_to_g_000a4b98[23];
    tmp42[24] = s_Popping_work_from_get_queue_to_g_000a4b98[24];
    tmp42[25] = s_Popping_work_from_get_queue_to_g_000a4b98[25];
    tmp42[26] = s_Popping_work_from_get_queue_to_g_000a4b98[26];
    tmp42[27] = s_Popping_work_from_get_queue_to_g_000a4b98[27];
    tmp42[28] = s_Popping_work_from_get_queue_to_g_000a4b98[28];
    tmp42[29] = s_Popping_work_from_get_queue_to_g_000a4b98[29];
    tmp42[30] = s_Popping_work_from_get_queue_to_g_000a4b98[30];
    tmp42[31] = s_Popping_work_from_get_queue_to_g_000a4b98[31];
    tmp42[32] = s_Popping_work_from_get_queue_to_g_000a4b98[32];
    tmp42[33] = s_Popping_work_from_get_queue_to_g_000a4b98[33];
    tmp42[34] = s_Popping_work_from_get_queue_to_g_000a4b98[34];
    tmp42[35] = s_Popping_work_from_get_queue_to_g_000a4b98[35];
    tmp42[36] = s_Popping_work_from_get_queue_to_g_000a4b98[36];
    tmp42[37] = s_Popping_work_from_get_queue_to_g_000a4b98[37];
    tmp42[38] = s_Popping_work_from_get_queue_to_g_000a4b98[38];
    tmp42[39] = s_Popping_work_from_get_queue_to_g_000a4b98[39];
    _applog(7,tmp42,false);
  }
  diff_t = time((time_t *)0x0);
  while (work == (work *)0x0) {
    work = hash_pop(true);
    _Var1 = stale_work(work,false);
    if (_Var1) {
      _discard_work(&work,"cgminer.c","get_work",0x219f);
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
  dVar5 = cgpu->drv->max_diff;
  dVar6 = work->work_difficulty;
  if (dVar5 == dVar6 || dVar5 < dVar6 != (NAN(dVar5) || NAN(dVar6))) {
    uVar3 = *(undefined4 *)&cgpu->drv->max_diff;
    uVar4 = *(undefined4 *)((int)&cgpu->drv->max_diff + 4);
  }
  else {
    uVar3 = *(undefined4 *)&work->work_difficulty;
    uVar4 = *(undefined4 *)((int)&work->work_difficulty + 4);
  }
  *(undefined4 *)&work->device_diff = uVar3;
  *(undefined4 *)((int)&work->device_diff + 4) = uVar4;
  dVar5 = cgpu->drv->min_diff;
  dVar6 = work->device_diff;
  if (dVar5 == dVar6 || dVar5 < dVar6 != (NAN(dVar5) || NAN(dVar6))) {
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

