
void hashmeter(int thr_id,uint64_t hashes_done)

{
  time_t *ptVar1;
  int iVar2;
  timeval *end;
  undefined8 *puVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  time_t tVar7;
  thr_info *ptVar8;
  thr_info *thr;
  thr_info *thr_1;
  undefined4 in_r2;
  cgpu_info *func;
  undefined4 in_r3;
  int iVar9;
  double *pdVar10;
  uint line;
  cgpu_info *pcVar11;
  cgpu_info *cgpu;
  cgpu_info *cgpu_1;
  double *pdVar12;
  int iVar13;
  int iVar14;
  time_t now_t;
  double **ppdVar15;
  double *pdVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  double in_stack_fffff708;
  undefined4 uVar24;
  uint64_t uVar23;
  double in_stack_fffff710;
  undefined4 in_stack_fffff718;
  undefined4 in_stack_fffff71c;
  cgpu_info *local_8d4;
  double *local_8d0;
  undefined4 local_8cc;
  undefined4 local_8c8;
  time_t *local_8c4;
  char displayed_hashes [16];
  char displayed_rolling [16];
  char displayed_r1 [16];
  char displayed_r5 [16];
  sysinfo sInfo;
  char tmp42 [2048];
  
  uVar21 = CONCAT44(in_r3,in_r2);
  iVar4 = sysinfo((sysinfo *)&sInfo);
  if (iVar4 == 0) {
    local_8c4 = DAT_0002320c;
    *DAT_0002320c = sInfo.uptime;
  }
  else {
    if (((*DAT_00023200 != '\0') || (*DAT_00023204 != '\0')) || (5 < (int)*DAT_00023674)) {
      piVar5 = __errno_location();
      uVar24 = (undefined4)((ulonglong)in_stack_fffff708 >> 0x20);
      iVar4 = *piVar5;
      pcVar6 = strerror(iVar4);
      in_stack_fffff708 = (double)CONCAT44(uVar24,pcVar6);
      snprintf(tmp42,0x800,DAT_00023208,iVar4);
      _applog(6,tmp42,false);
    }
    ptVar1 = DAT_0002320c;
    local_8c4 = DAT_0002320c;
    tVar7 = time((time_t *)0x0);
    *ptVar1 = tVar7;
  }
  iVar2 = DAT_00023214;
  iVar4 = DAT_00023210;
  cgtime((timeval *)(DAT_00023210 + 0x58c));
  tdiff((timeval *)(iVar4 + 0x58c),(timeval *)(iVar4 + 0x520));
  iVar14 = *(int *)(iVar4 + 0x58c);
  iVar9 = *(int *)(iVar2 + 0x7f8);
  pcVar6 = (char *)(iVar14 - *(int *)(iVar4 + 0x594));
  if ((int)pcVar6 < iVar9) {
    if (thr_id < 0) {
      return;
    }
    copy_time((timeval *)(iVar4 + 0x520),(timeval *)(iVar4 + 0x58c));
    local_8d4 = (cgpu_info *)0x0;
  }
  else {
    *(int *)(iVar4 + 0x594) = iVar14;
    copy_time((timeval *)(iVar4 + 0x520),(timeval *)(iVar4 + 0x58c));
    if (thr_id < 0) {
      iVar14 = pthread_mutex_lock(DAT_00023498);
      if (iVar14 != 0) {
        _mutex_lock(DAT_00023678,(char *)0x1b4a,pcVar6,iVar9);
      }
      piVar5 = DAT_000234b0;
      iVar9 = *DAT_000234b0;
      if (0 < iVar9) {
        iVar14 = 0;
        do {
          iVar13 = iVar14 + 1;
          ptVar8 = get_thread(iVar14);
          pcVar11 = ptVar8->cgpu;
          tdiff(DAT_000234ac,&pcVar11->last_message_tv);
          copy_time(&pcVar11->last_message_tv,DAT_000234ac);
          decay_time(&pcVar11->rolling,in_stack_fffff708,in_stack_fffff710,
                     (double)CONCAT44(in_stack_fffff71c,in_stack_fffff718));
          decay_time(&pcVar11->rolling1,in_stack_fffff708,in_stack_fffff710,
                     (double)CONCAT44(in_stack_fffff71c,in_stack_fffff718));
          decay_time(&pcVar11->rolling5,in_stack_fffff708,in_stack_fffff710,
                     (double)CONCAT44(in_stack_fffff71c,in_stack_fffff718));
          decay_time(&pcVar11->rolling15,in_stack_fffff708,in_stack_fffff710,
                     (double)CONCAT44(in_stack_fffff71c,in_stack_fffff718));
          iVar9 = *piVar5;
          iVar14 = iVar13;
        } while (iVar13 < iVar9);
      }
      iVar14 = pthread_mutex_unlock(DAT_00023498);
      if (iVar14 != 0) {
        _mutex_unlock_noyield(DAT_00023678,(char *)0x1b59,pcVar6,iVar9);
      }
      ppdVar15 = DAT_000234b4;
      func = (cgpu_info *)0x1;
      local_8d4 = (cgpu_info *)0x1;
      pdVar10 = *DAT_000234b4;
      (*(code *)pdVar10)();
      goto LAB_00023094;
    }
    local_8d4 = (cgpu_info *)0x1;
  }
  ptVar8 = get_thread(thr_id);
  pcVar11 = ptVar8->cgpu;
  copy_time(&ptVar8->last,DAT_00023218);
  end = DAT_00023218;
  pcVar11->device_last_well = iVar14;
  dVar17 = tdiff(end,&pcVar11->last_message_tv);
  copy_time(&pcVar11->last_message_tv,DAT_00023218);
  if ((*DAT_0002321c != '\0') &&
     (((*DAT_0002348c != 0 || (*DAT_00023490 != 0)) || (6 < (int)*DAT_00023674)))) {
    in_stack_fffff708 = (double)CONCAT44(in_r3,in_r2);
    dVar20 = (double)__aeabi_ul2d();
    in_stack_fffff710 = (dVar20 / dVar17) / DAT_00023458;
    snprintf(tmp42,0x800,DAT_000234a8,thr_id);
    _applog(7,tmp42,false);
  }
  func = (cgpu_info *)(::cgpu.results[0x1d] + 0xe4f);
  iVar14 = 0;
  uVar21 = __aeabi_uldivmod(in_r2,in_r3);
  iVar9 = pthread_mutex_lock(DAT_00023220);
  if (iVar9 != 0) {
    _mutex_lock(DAT_00023678,(char *)0x1b2d,(char *)func,iVar14);
  }
  dVar17 = (double)__aeabi_ul2d((int)uVar21,(int)((ulonglong)uVar21 >> 0x20));
  pcVar11->total_mhashes = pcVar11->total_mhashes + dVar17;
  decay_time(&pcVar11->rolling,in_stack_fffff708,in_stack_fffff710,
             (double)CONCAT44(in_stack_fffff71c,in_stack_fffff718));
  decay_time(&pcVar11->rolling1,in_stack_fffff708,in_stack_fffff710,
             (double)CONCAT44(in_stack_fffff71c,in_stack_fffff718));
  decay_time(&pcVar11->rolling5,in_stack_fffff708,in_stack_fffff710,
             (double)CONCAT44(in_stack_fffff71c,in_stack_fffff718));
  decay_time(&pcVar11->rolling15,in_stack_fffff708,in_stack_fffff710,
             (double)CONCAT44(in_stack_fffff71c,in_stack_fffff718));
  iVar9 = pthread_mutex_unlock(DAT_00023220);
  if (iVar9 != 0) {
    _mutex_unlock_noyield(DAT_00023678,(char *)0x1b34,(char *)func,iVar14);
  }
  ppdVar15 = DAT_00023240;
  (*(code *)*DAT_00023240)();
  pdVar10 = (double *)(uint)*DAT_00023224;
  if ((pdVar10 != (double *)0x0) && (func = local_8d4, local_8d4 != (cgpu_info *)0x0)) {
    get_statline(tmp42,0x100,pcVar11);
    printf(DAT_0002349c,tmp42);
    pdVar10 = DAT_000234a4;
    fflush(*(FILE **)DAT_000234a4);
    func = pcVar11;
  }
LAB_00023094:
  local_8c8 = (undefined4)((ulonglong)uVar21 >> 0x20);
  local_8cc = (undefined4)uVar21;
  iVar9 = pthread_mutex_lock(DAT_00023220);
  if (iVar9 != 0) {
    _mutex_lock(DAT_00023678,(char *)0x1b5c,(char *)func,(int)pdVar10);
  }
  dVar17 = (double)__aeabi_ul2d(local_8cc,local_8c8);
  iVar9 = *(int *)(iVar4 + 0x588);
  total_mhashes_done = dVar17 + total_mhashes_done;
  if (local_8d4 == (cgpu_info *)0x0) {
    local_8d0 = DAT_00023480;
    dVar20 = DAT_00023480[iVar9];
  }
  else {
    iVar9 = iVar9 + 1;
    iVar14 = 0;
    if (0xb < iVar9) {
      iVar9 = 0;
    }
    *(int *)(DAT_00023210 + 0x588) = iVar9;
    pdVar10 = DAT_00023228;
    uVar22 = 0;
    pdVar12 = DAT_00023228 + 0xc;
    local_8d0 = DAT_00023228;
    pdVar16 = DAT_00023228;
    do {
      dVar20 = *pdVar16;
      pdVar16 = pdVar16 + 1;
      if (dVar20 < 0.0 == NAN(dVar20)) {
        dVar18 = (double)__aeabi_ul2d((int)uVar22,(int)((ulonglong)uVar22 >> 0x20));
        iVar14 = iVar14 + 1;
        uVar22 = __fixunsdfdi(SUB84(dVar20 + dVar18,0),(int)((ulonglong)(dVar20 + dVar18) >> 0x20));
      }
    } while (pdVar16 != pdVar12);
    if (iVar14 != 0) {
      uVar21 = __aeabi_uldivmod((int)uVar22,(int)((ulonglong)uVar22 >> 0x20),iVar14,iVar14 >> 0x1f);
    }
    puVar3 = DAT_00023230;
    pdVar16 = DAT_0002322c;
    __aeabi_ul2d((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),*(undefined4 *)(iVar2 + 0x7f8));
    decay_time(pdVar16,in_stack_fffff708,in_stack_fffff710,
               (double)CONCAT44(in_stack_fffff71c,in_stack_fffff718));
    decay_time(DAT_00023234,in_stack_fffff708,in_stack_fffff710,
               (double)CONCAT44(in_stack_fffff71c,in_stack_fffff718));
    decay_time(DAT_00023238,in_stack_fffff708,in_stack_fffff710,
               (double)CONCAT44(in_stack_fffff71c,in_stack_fffff718));
    decay_time(DAT_0002323c,in_stack_fffff708,in_stack_fffff710,
               (double)CONCAT44(in_stack_fffff71c,in_stack_fffff718));
    dVar20 = *pdVar16 * DAT_000231f0;
    uVar21 = __fixunsdfdi(SUB84(dVar20,0),(int)((ulonglong)dVar20 >> 0x20));
    iVar9 = *(int *)(iVar4 + 0x588);
    *puVar3 = uVar21;
    dVar20 = DAT_000231f8;
    pdVar10[iVar9] = DAT_000231f8;
  }
  pdVar16 = DAT_00023488;
  dVar18 = DAT_00023450;
  uVar24 = (undefined4)((ulonglong)in_stack_fffff708 >> 0x20);
  local_8d0 = local_8d0 + iVar9;
  iVar9 = *DAT_00023484;
  iVar4 = *local_8c4;
  pdVar10 = DAT_00023488 + 5;
  dVar19 = *pdVar10;
  *local_8d0 = dVar17 + dVar20;
  dVar20 = (double)(longlong)iVar4 - (double)(longlong)iVar9;
  dVar17 = dVar20 - dVar19;
  *pdVar16 = dVar20;
  if (dVar17 == dVar18 || dVar17 < dVar18 != (NAN(dVar17) || NAN(dVar18))) {
    *pdVar10 = dVar20;
    dVar17 = DAT_00023650;
    pdVar12 = DAT_0002367c;
  }
  else {
    line = (uint)*DAT_0002348c;
    if (((line != 0) || (line = (uint)*DAT_00023490, line != 0)) ||
       (line = *DAT_00023674, 2 < (int)line)) {
      snprintf(tmp42,0x800,DAT_00023494,line,dVar20,dVar19);
      uVar24 = (undefined4)((ulonglong)dVar20 >> 0x20);
      local_8d0 = (double *)0x0;
      _applog(3,tmp42,false);
    }
    iVar4 = pthread_mutex_unlock(DAT_00023498);
    if (iVar4 != 0) {
      _mutex_unlock_noyield(DAT_00023678,(char *)0x1b8c,(char *)local_8d0,line);
    }
    pdVar10 = *ppdVar15;
    (*(code *)pdVar10)();
    zero_stats();
    iVar4 = pthread_mutex_lock(DAT_00023498);
    dVar17 = DAT_00023650;
    pdVar12 = DAT_0002367c;
    if (iVar4 != 0) {
      _mutex_lock(DAT_00023678,(char *)0x1b8e,(char *)local_8d0,(int)pdVar10);
      dVar17 = DAT_00023650;
      pdVar12 = DAT_0002367c;
    }
  }
  DAT_00023650 = dVar17;
  DAT_0002367c = pdVar12;
  if (local_8d4 != (cgpu_info *)0x0) {
    dVar20 = (total_mhashes_done / *pdVar16) * dVar17;
    uVar21 = __fixunsdfdi(SUB84(dVar20,0),(int)((ulonglong)dVar20 >> 0x20));
    uVar23 = CONCAT44(uVar24,4);
    suffix_string(uVar23,(char *)uVar21,(size_t)((ulonglong)uVar21 >> 0x20),(int)displayed_hashes);
    uVar24 = (undefined4)(uVar23 >> 0x20);
    dVar20 = *DAT_00023660 * dVar17;
    *pdVar12 = (double)(longlong)((int)(longlong)*DAT_00023660 / 10) / DAT_00023658;
    uVar21 = __fixunsdfdi(SUB84(dVar20,0),(int)((ulonglong)dVar20 >> 0x20));
    uVar23 = CONCAT44(uVar24,4);
    suffix_string(uVar23,(char *)uVar21,(size_t)((ulonglong)uVar21 >> 0x20),(int)displayed_rolling);
    uVar24 = (undefined4)(uVar23 >> 0x20);
    uVar21 = __fixunsdfdi(SUB84(*DAT_00023664 * dVar17,0),
                          (int)((ulonglong)(*DAT_00023664 * dVar17) >> 0x20));
    uVar23 = CONCAT44(uVar24,4);
    suffix_string(uVar23,(char *)uVar21,(size_t)((ulonglong)uVar21 >> 0x20),(int)displayed_r1);
    uVar24 = (undefined4)(uVar23 >> 0x20);
    uVar21 = __fixunsdfdi(SUB84(*DAT_00023668 * dVar17,0),
                          (int)((ulonglong)(*DAT_00023668 * dVar17) >> 0x20));
    uVar23 = CONCAT44(uVar24,4);
    suffix_string(uVar23,(char *)uVar21,(size_t)((ulonglong)uVar21 >> 0x20),(int)displayed_r5);
    uVar24 = (undefined4)(uVar23 >> 0x20);
    uVar21 = __fixunsdfdi(SUB84(*DAT_0002366c * dVar17,0),
                          (int)((ulonglong)(*DAT_0002366c * dVar17) >> 0x20));
    suffix_string(CONCAT44(uVar24,4),(char *)uVar21,(size_t)((ulonglong)uVar21 >> 0x20),(int)tmp42);
    pdVar10 = *(double **)(iVar2 + 0x7f8);
    local_8d0 = DAT_00023670;
    snprintf((char *)(pdVar12 + 1),0x100,(char *)DAT_00023670,pdVar10,displayed_rolling,displayed_r1
             ,displayed_r5,tmp42,displayed_hashes);
  }
  iVar4 = pthread_mutex_unlock(DAT_00023498);
  if (iVar4 != 0) {
    _mutex_unlock_noyield(DAT_00023678,(char *)0x1bb7,(char *)local_8d0,(int)pdVar10);
  }
  (*(code *)*ppdVar15)();
  if (local_8d4 != (cgpu_info *)0x0) {
    printf(DAT_0002349c,DAT_000234a0);
    fflush(*(FILE **)DAT_000234a4);
  }
  return;
}

