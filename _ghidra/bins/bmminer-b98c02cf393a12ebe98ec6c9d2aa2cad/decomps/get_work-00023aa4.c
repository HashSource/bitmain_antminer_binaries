
int get_work(int param_1,undefined4 param_2)

{
  time_t tVar1;
  time_t tVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  bool bVar10;
  double dVar11;
  double dVar12;
  int local_82c;
  char local_828 [2052];
  
  local_82c = 0;
  iVar9 = *(int *)(param_1 + 0x24);
  thread_reportout();
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    builtin_strncpy(local_828,"Popping work from get queue to get work",0x28);
    _applog(7,local_828,0);
  }
  tVar1 = time((time_t *)0x0);
  while (local_82c == 0) {
    local_82c = hash_pop(1);
    iVar7 = stale_work(local_82c,0);
    if (iVar7 != 0) {
      _discard_work(&local_82c,"cgminer.c","get_work",0x2168);
      wake_gws();
    }
  }
  tVar2 = time((time_t *)0x0);
  iVar7 = tVar2 - tVar1;
  cVar4 = opt_debug;
  if (0 < iVar7) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(local_828,0x800,"Get work blocked for %d seconds",iVar7);
      _applog(7,local_828,0);
    }
    cVar4 = opt_debug;
    *(int *)(iVar9 + 0xe8) = iVar7 + *(int *)(iVar9 + 0xe8);
  }
  if ((cVar4 != '\0') && (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))
     ) {
    snprintf(local_828,0x800,"Got work from get queue to get work for thread %d",param_2);
    _applog(7,local_828,0);
  }
  cVar4 = opt_benchmark;
  *(undefined4 *)(local_82c + 0x100) = param_2;
  if (cVar4 == '\0') goto LAB_00023be4;
  iVar3 = *(int *)(iVar9 + 0x17c);
  iVar7 = *(int *)(iVar9 + 0x180) + iVar3;
  *(int *)(iVar9 + 0x17c) = iVar7;
  if (iVar7 < 1) {
    iVar3 = 1;
  }
  if (iVar7 < 1) {
    *(int *)(iVar9 + 0x180) = iVar3;
LAB_00023ce8:
    puVar8 = bench_lodiff_bins;
    uVar6 = 0x2155;
  }
  else {
    if (iVar7 < 0x10) goto LAB_00023ce8;
    iVar3 = -1;
    *(undefined4 *)(iVar9 + 0x180) = 0xffffffff;
    puVar8 = bench_hidiff_bins;
    iVar5 = *(int *)(iVar9 + 0x178) + 1;
    bVar10 = *(int *)(iVar9 + 0x178) + -0xe < 0;
    if (0xf < iVar5) {
      iVar3 = 0;
    }
    iVar7 = iVar3;
    if (iVar5 == 0xf || bVar10 != SBORROW4(iVar5,0xf)) {
      *(int *)(iVar9 + 0x178) = iVar5;
      iVar7 = iVar5;
    }
    if (iVar5 != 0xf && bVar10 == SBORROW4(iVar5,0xf)) {
      *(int *)(iVar9 + 0x178) = iVar3;
    }
    uVar6 = 0x2151;
  }
  _cg_memcpy(local_82c,puVar8 + iVar7 * 0xa0,0xa0,"cgminer.c","set_benchmark_work",uVar6);
LAB_00023be4:
  *(undefined1 *)(param_1 + 0x3d) = 0;
  cgtime(param_1 + 0x2c);
  iVar7 = *(int *)(param_1 + 0x24);
  *(undefined4 *)(iVar7 + 0x60) = 0;
  tVar1 = time((time_t *)0x0);
  iVar9 = *(int *)(iVar9 + 4);
  *(time_t *)(iVar7 + 0xf0) = tVar1;
  dVar12 = *(double *)(iVar9 + 0x68);
  dVar11 = *(double *)(iVar9 + 0x70);
  *(undefined1 *)(local_82c + 0x110) = 1;
  if (*(double *)(local_82c + 0x178) < dVar12) {
    dVar12 = *(double *)(local_82c + 0x178);
  }
  if ((int)((uint)(dVar12 < dVar11) << 0x1f) < 0) {
    dVar12 = dVar11;
  }
  *(double *)(local_82c + 0xe0) = dVar12;
  return local_82c;
}

