
/* WARNING: Unknown calling convention */

void update_work_stats(thr_info *thr,work *work)

{
  char cVar1;
  undefined8 *puVar2;
  int *piVar3;
  int iVar4;
  time_t tVar5;
  char *in_r2;
  pool *line;
  pool *ppVar6;
  cgpu_info *pcVar7;
  int iVar8;
  double dVar9;
  double dVar10;
  uint64_t uVar11;
  undefined8 uVar12;
  int64_t iVar13;
  char tmp42 [2048];
  
  dVar10 = *(double *)DAT_00022104;
  line = DAT_00022104;
  uVar11 = share_diff(work);
  work->share_diff = uVar11;
  dVar9 = (double)__aeabi_ul2d();
  piVar3 = DAT_00022114;
  if (dVar10 <= dVar9) {
    line = work->pool;
    iVar8 = line->solved;
    iVar4 = *DAT_00022114;
    cVar1 = *DAT_00022118;
    work->block = true;
    line->solved = iVar8 + 1;
    *piVar3 = iVar4 + 1;
    work->mandatory = true;
    if (((cVar1 != '\0') || (*DAT_0002211c != '\0')) || (in_r2 = *DAT_00022120, 4 < (int)in_r2)) {
      line = (pool *)line->pool_no;
      snprintf(tmp42,0x800,DAT_00022124);
      in_r2 = (char *)0x0;
      _applog(5,tmp42,false);
    }
  }
  iVar4 = pthread_mutex_lock(DAT_00022108);
  if (iVar4 != 0) {
    _mutex_lock(DAT_00022128,(char *)0x2208,in_r2,(int)line);
  }
  puVar2 = DAT_0002210c;
  dVar10 = work->device_diff;
  dVar9 = (double)__aeabi_l2d(*(undefined4 *)DAT_0002210c,*(undefined4 *)((int)DAT_0002210c + 4));
  uVar12 = __aeabi_d2lz(SUB84(dVar9 + dVar10,0),(int)((ulonglong)(dVar9 + dVar10) >> 0x20));
  pcVar7 = thr->cgpu;
  *puVar2 = uVar12;
  dVar9 = (double)__aeabi_l2d(*(undefined4 *)&pcVar7->diff1,*(undefined4 *)((int)&pcVar7->diff1 + 4)
                             );
  iVar13 = __aeabi_d2lz(SUB84(dVar10 + dVar9,0),(int)((ulonglong)(dVar10 + dVar9) >> 0x20));
  ppVar6 = work->pool;
  pcVar7->diff1 = iVar13;
  dVar9 = (double)__aeabi_l2d(*(undefined4 *)&ppVar6->diff1,*(undefined4 *)((int)&ppVar6->diff1 + 4)
                             );
  iVar13 = __aeabi_d2lz(SUB84(dVar10 + dVar9,0),(int)((ulonglong)(dVar10 + dVar9) >> 0x20));
  ppVar6->diff1 = iVar13;
  tVar5 = time((time_t *)0x0);
  pcVar7->last_device_valid_work = tVar5;
  iVar4 = pthread_mutex_unlock(DAT_00022108);
  if (iVar4 != 0) {
    _mutex_unlock_noyield(DAT_00022128,(char *)0x220d,in_r2,(int)line);
  }
  (**DAT_00022110)();
  return;
}

