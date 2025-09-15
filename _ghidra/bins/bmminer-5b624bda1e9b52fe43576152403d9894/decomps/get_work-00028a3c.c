
/* WARNING: Unknown calling convention */

work * get_work(thr_info *thr,int thr_id)

{
  work *pwVar1;
  _Bool _Var2;
  time_t tVar3;
  time_t tVar4;
  uchar (*pauVar5) [160];
  int iVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  cgpu_info *cgpu;
  cgpu_info *pcVar10;
  bool bVar11;
  double dVar12;
  double dVar13;
  work *work;
  char tmp42 [2048];
  
  work = (work *)0x0;
  pcVar10 = thr->cgpu;
  thread_reportout(thr);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"Popping work from get queue to get work",0x28);
    _applog(7,tmp42,false);
  }
  tVar3 = time((time_t *)0x0);
  while (work == (work *)0x0) {
    while( true ) {
      pwVar1 = work;
      work = hash_pop(true);
      _Var2 = stale_work(work,SUB41(pwVar1,0));
      if (!_Var2) break;
      _discard_work(&work,"cgminer.c","get_work",0x214c);
      wake_gws();
      if (work != (work *)0x0) goto LAB_00028abe;
    }
  }
LAB_00028abe:
  tVar4 = time((time_t *)0x0);
  iVar9 = tVar4 - tVar3;
  cVar7 = opt_debug;
  if (0 < iVar9) {
    if (opt_debug != false) {
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
        cVar7 = '\x01';
      }
      else {
        snprintf(tmp42,0x800,"Get work blocked for %d seconds",iVar9);
        _applog(7,tmp42,false);
        cVar7 = opt_debug;
      }
    }
    pcVar10->last_device_valid_work = pcVar10->last_device_valid_work + iVar9;
  }
  if ((cVar7 != '\0') &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Got work from get queue to get work for thread %d",thr_id);
    _applog(7,tmp42,false);
  }
  _Var2 = opt_benchmark;
  work->thr_id = thr_id;
  if (_Var2 == false) goto LAB_00028b38;
  iVar6 = pcVar10->lodiff;
  iVar9 = iVar6 + pcVar10->direction;
  pcVar10->lodiff = iVar9;
  if (iVar9 < 1) {
    iVar6 = 1;
  }
  if (iVar9 < 1) {
    pcVar10->direction = iVar6;
LAB_00028c00:
    pauVar5 = bench_lodiff_bins;
    iVar6 = 0x2139;
  }
  else {
    if (iVar9 < 0x10) goto LAB_00028c00;
    iVar6 = -1;
    pcVar10->direction = -1;
    pauVar5 = bench_hidiff_bins;
    iVar8 = pcVar10->hidiff + 1;
    bVar11 = pcVar10->hidiff + -0xe < 0;
    if (0xf < iVar8) {
      iVar6 = 0;
    }
    iVar9 = iVar6;
    if (iVar8 == 0xf || bVar11 != SBORROW4(iVar8,0xf)) {
      pcVar10->hidiff = iVar8;
      iVar9 = iVar8;
    }
    if (iVar8 != 0xf && bVar11 == SBORROW4(iVar8,0xf)) {
      pcVar10->hidiff = iVar6;
    }
    iVar6 = 0x2135;
  }
  _cg_memcpy(work,pauVar5 + iVar9,0xa0,"cgminer.c","set_benchmark_work",iVar6);
LAB_00028b38:
  thread_reportin(thr);
  dVar13 = pcVar10->drv->max_diff;
  dVar12 = pcVar10->drv->min_diff;
  work->mined = true;
  if (work->work_difficulty < dVar13) {
    dVar13 = work->work_difficulty;
  }
  if ((int)((uint)(dVar13 < dVar12) << 0x1f) < 0) {
    dVar13 = dVar12;
  }
  work->device_diff = dVar13;
  return work;
}

