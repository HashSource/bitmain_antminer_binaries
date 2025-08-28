
void hashmeter(int thr_id,uint64_t hashes_done)

{
  bool bVar1;
  ulonglong uVar2;
  __time_t _Var3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  thr_info *ptVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  cgpu_info *pcVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  undefined8 uVar15;
  uint64_t uVar16;
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
  
  bVar1 = false;
  uVar15 = 0;
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
      pcVar6 = strerror(*piVar5);
      snprintf(tmp42,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar4,pcVar6);
      _applog(6,tmp42,false);
    }
    total_tv_end_sys = time((time_t *)0x0);
  }
  cgtime(&total_tv_end);
  dVar11 = tdiff(&total_tv_end,&tv_hashmeter);
  _Var3 = total_tv_end.tv_sec;
  uVar2 = CONCAT44(global_hashrate._4_4_,(undefined4)global_hashrate);
  dVar12 = (double)CONCAT44(last_total_secs._4_4_,last_total_secs._0_4_);
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
      ptVar7 = get_thread(thr_id_local);
      pcVar10 = ptVar7->cgpu;
      dVar12 = tdiff(&total_tv_end,&pcVar10->last_message_tv);
      copy_time(&pcVar10->last_message_tv,&total_tv_end);
      decay_time(&pcVar10->rolling,0.0,dVar12,(double)(longlong)opt_log_interval);
      decay_time(&pcVar10->rolling1,0.0,dVar12,60.0);
      decay_time(&pcVar10->rolling5,0.0,dVar12,300.0);
      decay_time(&pcVar10->rolling15,0.0,dVar12,900.0);
    }
    _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1b60);
    hashes_done_local = hashes_done;
  }
  else {
    ptVar7 = get_thread(thr_id);
    pcVar10 = ptVar7->cgpu;
    copy_time(&ptVar7->last,&total_tv_end);
    pcVar10->device_last_well = _Var3;
    dVar12 = tdiff(&total_tv_end,&pcVar10->last_message_tv);
    copy_time(&pcVar10->last_message_tv,&total_tv_end);
    hashes_done_local._0_4_ = (undefined4)hashes_done;
    hashes_done_local._4_4_ = (undefined4)(hashes_done >> 0x20);
    dVar13 = (double)__aeabi_ul2d((undefined4)hashes_done_local,hashes_done_local._4_4_);
    dVar13 = (dVar13 / dVar12) / 1000000.0;
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      thr_mhs._0_4_ = SUB84(dVar13,0);
      thr_mhs._4_4_ = (undefined4)((ulonglong)dVar13 >> 0x20);
      snprintf(tmp42,0x800,"[thread %d: %llu hashes, %.1f mhash/sec]",thr_id,
               (undefined4)hashes_done_local,hashes_done_local._4_4_,thr_mhs._0_4_,thr_mhs._4_4_);
      _applog(7,tmp42,false);
    }
    hashes_done_local =
         __aeabi_uldivmod((undefined4)hashes_done_local,hashes_done_local._4_4_,1000000,0);
    uVar9 = (undefined4)(hashes_done_local >> 0x20);
    uVar8 = (undefined4)hashes_done_local;
    _mutex_lock(&hash_lock,"cgminer.c","hashmeter",0x1b34);
    dVar14 = pcVar10->total_mhashes;
    dVar13 = (double)__aeabi_ul2d(uVar8,uVar9);
    pcVar10->total_mhashes = dVar14 + dVar13;
    dVar13 = (double)__aeabi_ul2d(uVar8,uVar9);
    decay_time(&pcVar10->rolling,dVar13,dVar12,(double)(longlong)opt_log_interval);
    dVar13 = (double)__aeabi_ul2d(uVar8,uVar9);
    decay_time(&pcVar10->rolling1,dVar13,dVar12,60.0);
    dVar13 = (double)__aeabi_ul2d(uVar8,uVar9);
    decay_time(&pcVar10->rolling5,dVar13,dVar12,300.0);
    dVar13 = (double)__aeabi_ul2d(uVar8,uVar9);
    decay_time(&pcVar10->rolling15,dVar13,dVar12,900.0);
    _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1b3b);
    if ((want_per_device_stats != false) && (bVar1)) {
      get_statline(logline,0x100,pcVar10);
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
  _mutex_lock(&hash_lock,"cgminer.c","hashmeter",0x1b63);
  dVar12 = (double)__aeabi_ul2d((undefined4)hashes_done_local,hashes_done_local._4_4_);
  total_mhashes_done = dVar12 + total_mhashes_done;
  if (bVar1) {
    g_local_mhashes_index = g_local_mhashes_index + 1;
    if (0xb < g_local_mhashes_index) {
      g_local_mhashes_index = 0;
    }
    i = 0;
    while( true ) {
      local_mhashes_done_avg._4_4_ = (undefined4)((ulonglong)uVar15 >> 0x20);
      local_mhashes_done_avg._0_4_ = (undefined4)uVar15;
      if (0xb < i) break;
      if (0.0 <= g_local_mhashes_dones[i]) {
        dVar12 = (double)__aeabi_ul2d((undefined4)local_mhashes_done_avg,
                                      local_mhashes_done_avg._4_4_);
        uVar15 = __fixunsdfdi(SUB84(dVar12 + g_local_mhashes_dones[i],0),
                              (int)((ulonglong)(dVar12 + g_local_mhashes_dones[i]) >> 0x20));
        local_mhashes_done_count = local_mhashes_done_count + 1;
      }
      i = i + 1;
    }
    uVar16 = hashes_done_local;
    if (0 < local_mhashes_done_count) {
      uVar16 = __aeabi_uldivmod((undefined4)local_mhashes_done_avg,local_mhashes_done_avg._4_4_,
                                local_mhashes_done_count,local_mhashes_done_count >> 0x1f);
    }
    local_mhashes_done._4_4_ = (undefined4)(uVar16 >> 0x20);
    local_mhashes_done._0_4_ = (undefined4)uVar16;
    dVar12 = (double)__aeabi_ul2d((undefined4)local_mhashes_done,local_mhashes_done._4_4_);
    decay_time(&total_rolling,dVar12,(double)(longlong)opt_log_interval,
               (double)(longlong)opt_log_interval);
    dVar12 = (double)__aeabi_ul2d((undefined4)hashes_done_local,hashes_done_local._4_4_);
    decay_time(&rolling1,dVar12,dVar11,60.0);
    dVar12 = (double)__aeabi_ul2d((undefined4)hashes_done_local,hashes_done_local._4_4_);
    decay_time(&rolling5,dVar12,dVar11,300.0);
    dVar12 = (double)__aeabi_ul2d((undefined4)hashes_done_local,hashes_done_local._4_4_);
    decay_time(&rolling15,dVar12,dVar11,900.0);
    global_hashrate =
         __fixunsdfdi(SUB84(total_rolling * 1000000.0,0),
                      (int)((ulonglong)(total_rolling * 1000000.0) >> 0x20));
    iVar4 = g_local_mhashes_index * 8;
    *(undefined4 *)(g_local_mhashes_dones + g_local_mhashes_index) = 0;
    *(undefined4 *)((int)g_local_mhashes_dones + iVar4 + 4) = 0;
  }
  iVar4 = g_local_mhashes_index;
  dVar11 = g_local_mhashes_dones[g_local_mhashes_index];
  dVar12 = (double)__aeabi_ul2d((undefined4)hashes_done_local,hashes_done_local._4_4_);
  g_local_mhashes_dones[iVar4] = dVar11 + dVar12;
  dVar12 = (double)(longlong)total_tv_end_sys - (double)(longlong)total_tv_start_sys;
  total_secs._0_4_ = SUB84(dVar12,0);
  total_secs._4_4_ = (undefined4)((ulonglong)dVar12 >> 0x20);
  uVar8 = total_secs._4_4_;
  dVar11 = dVar12;
  if (86400.0 < dVar12 - (double)CONCAT44(last_total_secs._4_4_,last_total_secs._0_4_)) {
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      uVar9 = total_secs._0_4_;
      total_secs = dVar12;
      snprintf(tmp42,0x800,"cgminer time error total_secs = %d last_total_secs = %d",
               last_total_secs._4_4_,uVar9,uVar8,last_total_secs._0_4_,last_total_secs._4_4_);
      _applog(3,tmp42,false);
      dVar12 = total_secs;
    }
    total_secs = dVar12;
    _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1b93);
    zero_stats();
    _mutex_lock(&hash_lock,"cgminer.c","hashmeter",0x1b95);
    dVar12 = (double)CONCAT44(last_total_secs._4_4_,last_total_secs._0_4_);
    dVar11 = total_secs;
  }
  total_secs = dVar11;
  last_total_secs = dVar12;
  if (bVar1) {
    dVar12 = (total_mhashes_done / total_secs) * 1000000.0;
    uVar16 = __fixunsdfdi(SUB84(dVar12,0),(int)((ulonglong)dVar12 >> 0x20));
    suffix_string(uVar16,displayed_hashes,0x10,4);
    uVar16 = __fixunsdfdi(SUB84(total_rolling * 1000000.0,0),
                          (int)((ulonglong)(total_rolling * 1000000.0) >> 0x20));
    g_displayed_rolling = (double)(longlong)((int)(longlong)total_rolling / 10) / 100.0;
    suffix_string(uVar16,displayed_rolling,0x10,4);
    uVar16 = __fixunsdfdi(SUB84(rolling1 * 1000000.0,0),
                          (int)((ulonglong)(rolling1 * 1000000.0) >> 0x20));
    suffix_string(uVar16,displayed_r1,0x10,4);
    uVar16 = __fixunsdfdi(SUB84(rolling5 * 1000000.0,0),
                          (int)((ulonglong)(rolling5 * 1000000.0) >> 0x20));
    suffix_string(uVar16,displayed_r5,0x10,4);
    uVar16 = __fixunsdfdi(SUB84(rolling15 * 1000000.0,0),
                          (int)((ulonglong)(rolling15 * 1000000.0) >> 0x20));
    suffix_string(uVar16,displayed_r15,0x10,4);
    snprintf(statusline,0x100,"(%ds):%s (1m):%s (5m):%s (15m):%s (avg):%sh/s",opt_log_interval,
             displayed_rolling,displayed_r1,displayed_r5,displayed_r15,displayed_hashes);
  }
  _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1bbe);
  dVar12 = last_total_secs;
  uVar2 = global_hashrate;
  if (bVar1) {
    if (curses_active == true) {
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
        snprintf(tmp42,0x800,"%s",statusline);
        _applog(6,tmp42,false);
        dVar12 = last_total_secs;
        uVar2 = global_hashrate;
      }
    }
    else {
      printf("%s          \r",statusline);
      fflush(stdout);
      dVar12 = last_total_secs;
      uVar2 = global_hashrate;
    }
  }
LAB_00020dbe:
  global_hashrate._4_4_ = (undefined4)(uVar2 >> 0x20);
  global_hashrate._0_4_ = (undefined4)uVar2;
  last_total_secs._4_4_ = (undefined4)((ulonglong)dVar12 >> 0x20);
  last_total_secs._0_4_ = SUB84(dVar12,0);
  return;
}

