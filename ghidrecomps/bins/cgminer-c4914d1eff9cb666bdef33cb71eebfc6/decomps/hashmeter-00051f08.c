
/* WARNING: Removing unreachable block (ram,0x0005235e) */
/* WARNING: Removing unreachable block (ram,0x0005236c) */
/* WARNING: Removing unreachable block (ram,0x0005237a) */
/* WARNING: Removing unreachable block (ram,0x0005238a) */
/* WARNING: Removing unreachable block (ram,0x00052b08) */
/* WARNING: Removing unreachable block (ram,0x00052b16) */
/* WARNING: Removing unreachable block (ram,0x00052b24) */
/* WARNING: Removing unreachable block (ram,0x00052b32) */

void hashmeter(int thr_id,uint64_t hashes_done)

{
  bool bVar1;
  __time_t _Var2;
  int iVar3;
  int *piVar4;
  thr_info *ptVar5;
  char *in_r2;
  undefined4 in_r3;
  cgpu_info *pcVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 uVar10;
  UDItype UVar11;
  char *in_stack_fffff5d0;
  undefined4 uVar12;
  undefined4 in_stack_fffff5d4;
  DFtype a;
  undefined4 uVar13;
  undefined4 in_stack_fffff5d8;
  undefined4 in_stack_fffff5dc;
  undefined4 in_stack_fffff5e0;
  undefined4 in_stack_fffff5e4;
  uint64_t hashes_done_local;
  int thr_id_local;
  char logline [256];
  char tmp42 [2048];
  char displayed_r15 [16];
  char displayed_r5 [16];
  char displayed_r1 [16];
  char displayed_rolling [16];
  char displayed_hashes [16];
  sysinfo sInfo;
  uint64_t d64;
  double thr_mhs;
  double device_tdiff;
  cgpu_info *cgpu;
  thr_info *thr;
  double device_tdiff_1;
  cgpu_info *cgpu_1;
  thr_info *thr_1;
  int diff_t;
  time_t now_t;
  double tv_tdiff;
  int i;
  int local_mhashes_done_count;
  uint64_t local_mhashes_done_avg;
  uint64_t local_mhashes_done;
  _Bool showlog;
  
  uVar10 = CONCAT44(in_r3,in_r2);
  bVar1 = false;
  local_mhashes_done_avg = 0;
  local_mhashes_done_count = 0;
  iVar3 = sysinfo((sysinfo *)&sInfo);
  if (iVar3 == 0) {
    total_tv_end_sys = sInfo.uptime;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      piVar4 = __errno_location();
      iVar3 = *piVar4;
      piVar4 = __errno_location();
      in_stack_fffff5d0 = strerror(*piVar4);
      snprintf(tmp42,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar3);
      _applog(6,tmp42,false);
    }
    total_tv_end_sys = time((time_t *)0x0);
  }
  cgtime(&total_tv_end);
  tdiff(&total_tv_end,&tv_hashmeter);
  _Var2 = total_tv_end.tv_sec;
  dVar7 = (double)CONCAT44(last_total_secs._4_4_,last_total_secs._0_4_);
  if (total_tv_end.tv_sec - hashdisplay_t < opt_log_interval) {
    if (thr_id < 0) goto LAB_00052b60;
  }
  else {
    alt_status = switch_status != alt_status;
    hashdisplay_t = total_tv_end.tv_sec;
    bVar1 = true;
  }
  copy_time(&tv_hashmeter,&total_tv_end);
  if (thr_id < 0) {
    _mutex_lock(&hash_lock,"cgminer.c","hashmeter",0x1b9c);
    for (thr_id_local = 0; thr_id_local < mining_threads; thr_id_local = thr_id_local + 1) {
      ptVar5 = get_thread(thr_id_local);
      pcVar6 = ptVar5->cgpu;
      tdiff(&total_tv_end,&pcVar6->last_message_tv);
      copy_time(&pcVar6->last_message_tv,&total_tv_end);
      decay_time(&pcVar6->rolling,(double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),
                 (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8),
                 (double)CONCAT44(in_stack_fffff5e4,in_stack_fffff5e0));
      decay_time(&pcVar6->rolling1,(double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),
                 (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8),
                 (double)CONCAT44(in_stack_fffff5e4,in_stack_fffff5e0));
      decay_time(&pcVar6->rolling5,(double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),
                 (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8),
                 (double)CONCAT44(in_stack_fffff5e4,in_stack_fffff5e0));
      decay_time(&pcVar6->rolling15,(double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),
                 (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8),
                 (double)CONCAT44(in_stack_fffff5e4,in_stack_fffff5e0));
    }
    _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1bab);
    dVar7 = (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8);
  }
  else {
    ptVar5 = get_thread(thr_id);
    pcVar6 = ptVar5->cgpu;
    copy_time(&ptVar5->last,&total_tv_end);
    pcVar6->device_last_well = _Var2;
    dVar7 = tdiff(&total_tv_end,&pcVar6->last_message_tv);
    copy_time(&pcVar6->last_message_tv,&total_tv_end);
    dVar8 = (double)__floatundidf(in_r2,in_r3);
    dVar8 = (dVar8 / dVar7) / DAT_00052400;
    dVar7 = (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) ||
        (dVar7 = (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8), 6 < opt_log_level)))) {
      in_stack_fffff5d0 = in_r2;
      in_stack_fffff5d4 = in_r3;
      snprintf(tmp42,0x800,"[thread %d: %llu hashes, %.1f mhash/sec]",thr_id);
      _applog(7,tmp42,false);
      dVar7 = dVar8;
    }
    uVar10 = __aeabi_uldivmod(in_r2,in_r3,1000000,0);
    uVar12 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar13 = (undefined4)uVar10;
    _mutex_lock(&hash_lock,"cgminer.c","hashmeter",0x1b7f);
    dVar9 = pcVar6->total_mhashes;
    dVar8 = (double)__floatundidf(uVar13,uVar12);
    pcVar6->total_mhashes = dVar9 + dVar8;
    __floatundidf(uVar13,uVar12);
    decay_time(&pcVar6->rolling,(double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),dVar7,
               (double)CONCAT44(in_stack_fffff5e4,in_stack_fffff5e0));
    __floatundidf(uVar13,uVar12);
    decay_time(&pcVar6->rolling1,(double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),dVar7,
               (double)CONCAT44(in_stack_fffff5e4,in_stack_fffff5e0));
    __floatundidf(uVar13,uVar12);
    decay_time(&pcVar6->rolling5,(double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),dVar7,
               (double)CONCAT44(in_stack_fffff5e4,in_stack_fffff5e0));
    __floatundidf(uVar13,uVar12);
    decay_time(&pcVar6->rolling15,(double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),dVar7,
               (double)CONCAT44(in_stack_fffff5e4,in_stack_fffff5e0));
    _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1b86);
    if ((want_per_device_stats != false) && (bVar1)) {
      get_statline(logline,0x100,pcVar6);
      printf("%s          \r",logline);
      fflush(stdout);
    }
  }
  hashes_done_local._4_4_ = (undefined4)((ulonglong)uVar10 >> 0x20);
  hashes_done_local._0_4_ = (undefined4)uVar10;
  _mutex_lock(&hash_lock,"cgminer.c","hashmeter",0x1bae);
  dVar8 = (double)__floatundidf((undefined4)hashes_done_local,hashes_done_local._4_4_);
  total_mhashes_done = dVar8 + total_mhashes_done;
  if (bVar1) {
    g_local_mhashes_index = g_local_mhashes_index + 1;
    if (0xb < g_local_mhashes_index) {
      g_local_mhashes_index = 0;
    }
    i = 0;
    while( true ) {
      if (0xb < i) break;
      if (g_local_mhashes_dones[i] < 0.0 == NAN(g_local_mhashes_dones[i])) {
        __floatundidf((undefined4)local_mhashes_done_avg,local_mhashes_done_avg._4_4_);
        local_mhashes_done_avg = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0))
        ;
        local_mhashes_done_count = local_mhashes_done_count + 1;
      }
      i = i + 1;
    }
    if (0 < local_mhashes_done_count) {
      uVar10 = __aeabi_uldivmod((undefined4)local_mhashes_done_avg,local_mhashes_done_avg._4_4_,
                                local_mhashes_done_count,local_mhashes_done_count >> 0x1f);
    }
    local_mhashes_done._4_4_ = (undefined4)((ulonglong)uVar10 >> 0x20);
    local_mhashes_done._0_4_ = (undefined4)uVar10;
    __floatundidf((undefined4)local_mhashes_done,local_mhashes_done._4_4_);
    decay_time(&total_rolling,(double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),dVar7,
               (double)CONCAT44(in_stack_fffff5e4,in_stack_fffff5e0));
    __floatundidf((undefined4)hashes_done_local,hashes_done_local._4_4_);
    decay_time(&rolling1,(double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),dVar7,
               (double)CONCAT44(in_stack_fffff5e4,in_stack_fffff5e0));
    __floatundidf((undefined4)hashes_done_local,hashes_done_local._4_4_);
    decay_time(&rolling5,(double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),dVar7,
               (double)CONCAT44(in_stack_fffff5e4,in_stack_fffff5e0));
    __floatundidf((undefined4)hashes_done_local,hashes_done_local._4_4_);
    decay_time(&rolling15,(double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),dVar7,
               (double)CONCAT44(in_stack_fffff5e4,in_stack_fffff5e0));
    global_hashrate = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0));
    iVar3 = g_local_mhashes_index * 8;
    *(undefined4 *)(g_local_mhashes_dones + g_local_mhashes_index) = 0;
    *(undefined4 *)((int)g_local_mhashes_dones + iVar3 + 4) = 0;
  }
  dVar8 = g_local_mhashes_dones[g_local_mhashes_index];
  dVar7 = (double)__floatundidf((undefined4)hashes_done_local,hashes_done_local._4_4_);
  a = (DFtype)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0);
  g_local_mhashes_dones[g_local_mhashes_index] = dVar8 + dVar7;
  total_secs = (double)(longlong)total_tv_end_sys - (double)(longlong)total_tv_start_sys;
  dVar8 = total_secs - (double)CONCAT44(last_total_secs._4_4_,last_total_secs._0_4_);
  dVar7 = total_secs;
  if (dVar8 != DAT_00052b70 && dVar8 < DAT_00052b70 == (NAN(dVar8) || NAN(DAT_00052b70))) {
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      a = total_secs;
      snprintf(tmp42,0x800,"cgminer time error total_secs = %f last_total_secs = %f");
      _applog(3,tmp42,false);
    }
    _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1bde);
    zero_stats();
    _mutex_lock(&hash_lock,"cgminer.c","hashmeter",0x1be0);
    dVar7 = (double)CONCAT44(last_total_secs._4_4_,last_total_secs._0_4_);
  }
  uVar13 = (undefined4)((ulonglong)a >> 0x20);
  last_total_secs = dVar7;
  if (bVar1) {
    UVar11 = __fixunsdfdi(a);
    uVar12 = 4;
    d64._0_4_ = (char *)UVar11;
    d64._4_4_ = (size_t)(UVar11 >> 0x20);
    suffix_string(CONCAT44(uVar13,4),(char *)d64,d64._4_4_,(int)displayed_hashes);
    UVar11 = __fixunsdfdi((DFtype)CONCAT44(uVar13,uVar12));
    g_displayed_rolling = (double)(longlong)((int)(longlong)total_rolling / 10) / DAT_00052b80;
    uVar12 = 4;
    d64._0_4_ = (char *)UVar11;
    d64._4_4_ = (size_t)(UVar11 >> 0x20);
    suffix_string(CONCAT44(uVar13,4),(char *)d64,d64._4_4_,(int)displayed_rolling);
    UVar11 = __fixunsdfdi((DFtype)CONCAT44(uVar13,uVar12));
    uVar12 = 4;
    d64._0_4_ = (char *)UVar11;
    d64._4_4_ = (size_t)(UVar11 >> 0x20);
    suffix_string(CONCAT44(uVar13,4),(char *)d64,d64._4_4_,(int)displayed_r1);
    UVar11 = __fixunsdfdi((DFtype)CONCAT44(uVar13,uVar12));
    uVar12 = 4;
    d64._0_4_ = (char *)UVar11;
    d64._4_4_ = (size_t)(UVar11 >> 0x20);
    suffix_string(CONCAT44(uVar13,4),(char *)d64,d64._4_4_,(int)displayed_r5);
    UVar11 = __fixunsdfdi((DFtype)CONCAT44(uVar13,uVar12));
    d64._0_4_ = (char *)UVar11;
    d64._4_4_ = (size_t)(UVar11 >> 0x20);
    suffix_string(CONCAT44(uVar13,4),(char *)d64,d64._4_4_,(int)displayed_r15);
    snprintf(statusline,0x100,"(%ds):%s (1m):%s (5m):%s (15m):%s (avg):%sh/s",opt_log_interval,
             displayed_rolling,displayed_r1,displayed_r5,displayed_r15,displayed_hashes);
  }
  _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1c09);
  dVar7 = last_total_secs;
  if (bVar1) {
    printf("%s          \r",statusline);
    fflush(stdout);
    dVar7 = last_total_secs;
  }
LAB_00052b60:
  last_total_secs._4_4_ = (undefined4)((ulonglong)dVar7 >> 0x20);
  last_total_secs._0_4_ = SUB84(dVar7,0);
  return;
}

