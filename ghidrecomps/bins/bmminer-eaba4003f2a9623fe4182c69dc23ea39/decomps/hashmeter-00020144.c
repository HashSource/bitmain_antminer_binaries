
void hashmeter(int thr_id,uint64_t hashes_done)

{
  bool bVar1;
  ulonglong uVar2;
  __time_t _Var3;
  int iVar4;
  int *piVar5;
  thr_info *ptVar6;
  undefined4 uVar7;
  char *in_r2;
  uint in_r3;
  cgpu_info *pcVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  char *in_stack_fffff5c8;
  uint in_stack_fffff5cc;
  undefined4 uVar15;
  undefined4 in_stack_fffff5d0;
  undefined4 in_stack_fffff5d4;
  undefined4 in_stack_fffff5d8;
  undefined4 in_stack_fffff5dc;
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
  double device_tdiff_1;
  cgpu_info *cgpu_1;
  thr_info *thr_1;
  double thr_mhs;
  double device_tdiff;
  cgpu_info *cgpu;
  thr_info *thr;
  int diff_t;
  time_t now_t;
  double tv_tdiff;
  int i;
  int local_mhashes_done_count;
  uint64_t local_mhashes_done_avg;
  uint64_t local_mhashes_done;
  _Bool showlog;
  
  uVar13 = CONCAT44(in_r3,in_r2);
  bVar1 = false;
  uVar14 = 0;
  local_mhashes_done_count = 0;
  iVar4 = sysinfo((sysinfo *)&sInfo);
  if (iVar4 == 0) {
    total_tv_end_sys = sInfo.uptime;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      piVar5 = __errno_location();
      iVar4 = *piVar5;
      piVar5 = __errno_location();
      in_stack_fffff5c8 = strerror(*piVar5);
      snprintf(tmp42,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar4);
      _applog(6,tmp42,false);
    }
    total_tv_end_sys = time((time_t *)0x0);
  }
  cgtime(&total_tv_end);
  tdiff(&total_tv_end,&tv_hashmeter);
  _Var3 = total_tv_end.tv_sec;
  uVar2 = CONCAT44(global_hashrate._4_4_,(undefined4)global_hashrate);
  dVar9 = (double)CONCAT44(last_total_secs._4_4_,last_total_secs._0_4_);
  if (total_tv_end.tv_sec - hashdisplay_t < opt_log_interval) {
    if (thr_id < 0) goto LAB_00020dbe;
  }
  else {
    alt_status = switch_status != alt_status;
    hashdisplay_t = total_tv_end.tv_sec;
    bVar1 = true;
  }
  copy_time(&tv_hashmeter,&total_tv_end);
  if (thr_id < 0) {
    _mutex_lock(&hash_lock,"cgminer.c","hashmeter",0x1b51);
    for (thr_id_local = 0; thr_id_local < mining_threads; thr_id_local = thr_id_local + 1) {
      ptVar6 = get_thread(thr_id_local);
      pcVar8 = ptVar6->cgpu;
      tdiff(&total_tv_end,&pcVar8->last_message_tv);
      copy_time(&pcVar8->last_message_tv,&total_tv_end);
      decay_time(&pcVar8->rolling,(double)CONCAT44(in_stack_fffff5cc,in_stack_fffff5c8),
                 (double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),
                 (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8));
      decay_time(&pcVar8->rolling1,(double)CONCAT44(in_stack_fffff5cc,in_stack_fffff5c8),
                 (double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),
                 (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8));
      decay_time(&pcVar8->rolling5,(double)CONCAT44(in_stack_fffff5cc,in_stack_fffff5c8),
                 (double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),
                 (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8));
      decay_time(&pcVar8->rolling15,(double)CONCAT44(in_stack_fffff5cc,in_stack_fffff5c8),
                 (double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0),
                 (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8));
    }
    _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1b60);
    dVar9 = (double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0);
  }
  else {
    ptVar6 = get_thread(thr_id);
    pcVar8 = ptVar6->cgpu;
    copy_time(&ptVar6->last,&total_tv_end);
    pcVar8->device_last_well = _Var3;
    dVar9 = tdiff(&total_tv_end,&pcVar8->last_message_tv);
    copy_time(&pcVar8->last_message_tv,&total_tv_end);
    dVar10 = (double)__aeabi_ul2d(in_r2,in_r3);
    dVar10 = (dVar10 / dVar9) / DAT_00020648;
    dVar9 = (double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) ||
        (dVar9 = (double)CONCAT44(in_stack_fffff5d4,in_stack_fffff5d0), 6 < opt_log_level)))) {
      in_stack_fffff5c8 = in_r2;
      in_stack_fffff5cc = in_r3;
      snprintf(tmp42,0x800,"[thread %d: %llu hashes, %.1f mhash/sec]",thr_id);
      _applog(7,tmp42,false);
      dVar9 = dVar10;
    }
    uVar13 = __aeabi_uldivmod(in_r2,in_r3,1000000,0);
    uVar7 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar15 = (undefined4)uVar13;
    _mutex_lock(&hash_lock,"cgminer.c","hashmeter",0x1b34);
    dVar12 = pcVar8->total_mhashes;
    dVar10 = (double)__aeabi_ul2d(uVar15,uVar7);
    pcVar8->total_mhashes = dVar12 + dVar10;
    __aeabi_ul2d(uVar15,uVar7);
    decay_time(&pcVar8->rolling,(double)CONCAT44(in_stack_fffff5cc,in_stack_fffff5c8),dVar9,
               (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8));
    __aeabi_ul2d(uVar15,uVar7);
    decay_time(&pcVar8->rolling1,(double)CONCAT44(in_stack_fffff5cc,in_stack_fffff5c8),dVar9,
               (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8));
    __aeabi_ul2d(uVar15,uVar7);
    decay_time(&pcVar8->rolling5,(double)CONCAT44(in_stack_fffff5cc,in_stack_fffff5c8),dVar9,
               (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8));
    __aeabi_ul2d(uVar15,uVar7);
    decay_time(&pcVar8->rolling15,(double)CONCAT44(in_stack_fffff5cc,in_stack_fffff5c8),dVar9,
               (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8));
    _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1b3b);
    if ((want_per_device_stats != false) && (bVar1)) {
      get_statline(logline,0x100,pcVar8);
      if (curses_active == true) {
        if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
          snprintf(tmp42,0x800,"%s",logline);
          _applog(6,tmp42,false);
        }
      }
      else {
        printf("%s          \r",logline);
        fflush(stdout);
      }
    }
  }
  hashes_done_local._4_4_ = (undefined4)((ulonglong)uVar13 >> 0x20);
  hashes_done_local._0_4_ = (undefined4)uVar13;
  _mutex_lock(&hash_lock,"cgminer.c","hashmeter",0x1b63);
  dVar10 = (double)__aeabi_ul2d((undefined4)hashes_done_local,hashes_done_local._4_4_);
  total_mhashes_done = dVar10 + total_mhashes_done;
  if (bVar1) {
    g_local_mhashes_index = g_local_mhashes_index + 1;
    if (0xb < g_local_mhashes_index) {
      g_local_mhashes_index = 0;
    }
    i = 0;
    while( true ) {
      local_mhashes_done_avg._4_4_ = (undefined4)((ulonglong)uVar14 >> 0x20);
      local_mhashes_done_avg._0_4_ = (undefined4)uVar14;
      if (0xb < i) break;
      if (g_local_mhashes_dones[i] < 0.0 == NAN(g_local_mhashes_dones[i])) {
        dVar10 = (double)__aeabi_ul2d((undefined4)local_mhashes_done_avg,
                                      local_mhashes_done_avg._4_4_);
        uVar14 = __fixunsdfdi(SUB84(dVar10 + g_local_mhashes_dones[i],0),
                              (int)((ulonglong)(dVar10 + g_local_mhashes_dones[i]) >> 0x20));
        local_mhashes_done_count = local_mhashes_done_count + 1;
      }
      i = i + 1;
    }
    if (0 < local_mhashes_done_count) {
      uVar13 = __aeabi_uldivmod((undefined4)local_mhashes_done_avg,local_mhashes_done_avg._4_4_,
                                local_mhashes_done_count,local_mhashes_done_count >> 0x1f);
    }
    local_mhashes_done._4_4_ = (undefined4)((ulonglong)uVar13 >> 0x20);
    local_mhashes_done._0_4_ = (undefined4)uVar13;
    __aeabi_ul2d((undefined4)local_mhashes_done,local_mhashes_done._4_4_);
    decay_time(&total_rolling,(double)CONCAT44(in_stack_fffff5cc,in_stack_fffff5c8),dVar9,
               (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8));
    __aeabi_ul2d((undefined4)hashes_done_local,hashes_done_local._4_4_);
    decay_time(&rolling1,(double)CONCAT44(in_stack_fffff5cc,in_stack_fffff5c8),dVar9,
               (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8));
    __aeabi_ul2d((undefined4)hashes_done_local,hashes_done_local._4_4_);
    decay_time(&rolling5,(double)CONCAT44(in_stack_fffff5cc,in_stack_fffff5c8),dVar9,
               (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8));
    __aeabi_ul2d((undefined4)hashes_done_local,hashes_done_local._4_4_);
    decay_time(&rolling15,(double)CONCAT44(in_stack_fffff5cc,in_stack_fffff5c8),dVar9,
               (double)CONCAT44(in_stack_fffff5dc,in_stack_fffff5d8));
    global_hashrate =
         __fixunsdfdi(SUB84(total_rolling * DAT_00020648,0),
                      (int)((ulonglong)(total_rolling * DAT_00020648) >> 0x20));
    iVar4 = g_local_mhashes_index * 8;
    *(undefined4 *)(g_local_mhashes_dones + g_local_mhashes_index) = 0;
    *(undefined4 *)((int)g_local_mhashes_dones + iVar4 + 4) = 0;
  }
  iVar4 = g_local_mhashes_index;
  dVar12 = g_local_mhashes_dones[g_local_mhashes_index];
  dVar10 = (double)__aeabi_ul2d((undefined4)hashes_done_local,hashes_done_local._4_4_);
  dVar9 = (double)((ulonglong)in_stack_fffff5cc << 0x20);
  g_local_mhashes_dones[iVar4] = dVar12 + dVar10;
  dVar10 = (double)(longlong)total_tv_end_sys - (double)(longlong)total_tv_start_sys;
  dVar11 = dVar10 - (double)CONCAT44(last_total_secs._4_4_,last_total_secs._0_4_);
  total_secs._0_4_ = SUB84(dVar10,0);
  total_secs._4_4_ = (undefined4)((ulonglong)dVar10 >> 0x20);
  uVar15 = total_secs._4_4_;
  dVar12 = dVar10;
  if (dVar11 != DAT_00020d50 && dVar11 < DAT_00020d50 == (NAN(dVar11) || NAN(DAT_00020d50))) {
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      uVar7 = total_secs._0_4_;
      total_secs = dVar10;
      snprintf(tmp42,0x800,"cgminer time error total_secs = %d last_total_secs = %d",
               last_total_secs._4_4_,uVar7,uVar15,last_total_secs._0_4_,last_total_secs._4_4_);
      _applog(3,tmp42,false);
      dVar12 = total_secs;
      dVar9 = dVar10;
    }
    total_secs = dVar12;
    _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1b93);
    zero_stats();
    _mutex_lock(&hash_lock,"cgminer.c","hashmeter",0x1b95);
    dVar10 = (double)CONCAT44(last_total_secs._4_4_,last_total_secs._0_4_);
    dVar12 = total_secs;
  }
  total_secs = dVar12;
  uVar15 = (undefined4)((ulonglong)dVar9 >> 0x20);
  last_total_secs = dVar10;
  if (bVar1) {
    dVar9 = (total_mhashes_done / total_secs) * DAT_00020d58;
    uVar13 = __fixunsdfdi(SUB84(dVar9,0),(int)((ulonglong)dVar9 >> 0x20));
    suffix_string(CONCAT44(uVar15,4),(char *)uVar13,(size_t)((ulonglong)uVar13 >> 0x20),
                  (int)displayed_hashes);
    uVar13 = __fixunsdfdi(SUB84(total_rolling * DAT_00020d58,0),
                          (int)((ulonglong)(total_rolling * DAT_00020d58) >> 0x20));
    g_displayed_rolling = (double)(longlong)((int)(longlong)total_rolling / 10) / DAT_00020d60;
    suffix_string(CONCAT44(uVar15,4),(char *)uVar13,(size_t)((ulonglong)uVar13 >> 0x20),
                  (int)displayed_rolling);
    uVar13 = __fixunsdfdi(SUB84(rolling1 * DAT_00020d58,0),
                          (int)((ulonglong)(rolling1 * DAT_00020d58) >> 0x20));
    suffix_string(CONCAT44(uVar15,4),(char *)uVar13,(size_t)((ulonglong)uVar13 >> 0x20),
                  (int)displayed_r1);
    uVar13 = __fixunsdfdi(SUB84(rolling5 * DAT_00020d58,0),
                          (int)((ulonglong)(rolling5 * DAT_00020d58) >> 0x20));
    suffix_string(CONCAT44(uVar15,4),(char *)uVar13,(size_t)((ulonglong)uVar13 >> 0x20),
                  (int)displayed_r5);
    uVar13 = __fixunsdfdi(SUB84(rolling15 * DAT_00020d58,0),
                          (int)((ulonglong)(rolling15 * DAT_00020d58) >> 0x20));
    suffix_string(CONCAT44(uVar15,4),(char *)uVar13,(size_t)((ulonglong)uVar13 >> 0x20),
                  (int)displayed_r15);
    snprintf(statusline,0x100,"(%ds):%s (1m):%s (5m):%s (15m):%s (avg):%sh/s",opt_log_interval,
             displayed_rolling,displayed_r1,displayed_r5,displayed_r15,displayed_hashes);
  }
  _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1bbe);
  dVar9 = last_total_secs;
  uVar2 = global_hashrate;
  if (bVar1) {
    if (curses_active == true) {
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
        snprintf(tmp42,0x800,"%s",statusline);
        _applog(6,tmp42,false);
        dVar9 = last_total_secs;
        uVar2 = global_hashrate;
      }
    }
    else {
      printf("%s          \r",statusline);
      fflush(stdout);
      dVar9 = last_total_secs;
      uVar2 = global_hashrate;
    }
  }
LAB_00020dbe:
  global_hashrate._4_4_ = (undefined4)(uVar2 >> 0x20);
  global_hashrate._0_4_ = (undefined4)uVar2;
  last_total_secs._4_4_ = (undefined4)((ulonglong)dVar9 >> 0x20);
  last_total_secs._0_4_ = SUB84(dVar9,0);
  return;
}

