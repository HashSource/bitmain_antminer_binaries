
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
  char *pcVar5;
  thr_info *ptVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 extraout_r1;
  cgpu_info *pcVar9;
  undefined4 extraout_s0;
  double dVar10;
  double dVar11;
  undefined4 extraout_s1;
  DFtype a;
  undefined4 extraout_s1_00;
  DFtype extraout_d0;
  DFtype a_01;
  DFtype a_02;
  DFtype a_03;
  DFtype a_04;
  double dVar12;
  double dVar13;
  uint64_t uVar14;
  UDItype UVar15;
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
  DFtype a_00;
  
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
      pcVar5 = strerror(*piVar4);
      snprintf(tmp42,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar3,pcVar5);
      _applog(6,tmp42,false);
    }
    total_tv_end_sys = time((time_t *)0x0);
  }
  cgtime(&total_tv_end);
  dVar10 = tdiff(&total_tv_end,&tv_hashmeter);
  _Var2 = total_tv_end.tv_sec;
  dVar11 = (double)CONCAT44(last_total_secs._4_4_,last_total_secs._0_4_);
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
      ptVar6 = get_thread(thr_id_local);
      pcVar9 = ptVar6->cgpu;
      dVar11 = tdiff(&total_tv_end,&pcVar9->last_message_tv);
      copy_time(&pcVar9->last_message_tv,&total_tv_end);
      decay_time(&pcVar9->rolling,0.0,dVar11,(double)(longlong)opt_log_interval);
      decay_time(&pcVar9->rolling1,0.0,dVar11,60.0);
      decay_time(&pcVar9->rolling5,0.0,dVar11,300.0);
      decay_time(&pcVar9->rolling15,0.0,dVar11,900.0);
    }
    _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1bab);
    hashes_done_local = hashes_done;
  }
  else {
    ptVar6 = get_thread(thr_id);
    pcVar9 = ptVar6->cgpu;
    copy_time(&ptVar6->last,&total_tv_end);
    pcVar9->device_last_well = _Var2;
    dVar11 = tdiff(&total_tv_end,&pcVar9->last_message_tv);
    copy_time(&pcVar9->last_message_tv,&total_tv_end);
    hashes_done_local._0_4_ = (undefined4)hashes_done;
    hashes_done_local._4_4_ = (undefined4)(hashes_done >> 0x20);
    dVar12 = (double)__floatundidf((undefined4)hashes_done_local,hashes_done_local._4_4_);
    dVar12 = (dVar12 / dVar11) / 1000000.0;
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      thr_mhs._0_4_ = SUB84(dVar12,0);
      thr_mhs._4_4_ = (undefined4)((ulonglong)dVar12 >> 0x20);
      snprintf(tmp42,0x800,"[thread %d: %llu hashes, %.1f mhash/sec]",thr_id,
               (undefined4)hashes_done_local,hashes_done_local._4_4_,thr_mhs._0_4_,thr_mhs._4_4_);
      _applog(7,tmp42,false);
    }
    hashes_done_local =
         __aeabi_uldivmod((undefined4)hashes_done_local,hashes_done_local._4_4_,1000000,0);
    uVar8 = (undefined4)(hashes_done_local >> 0x20);
    uVar7 = (undefined4)hashes_done_local;
    _mutex_lock(&hash_lock,"cgminer.c","hashmeter",0x1b7f);
    dVar13 = pcVar9->total_mhashes;
    dVar12 = (double)__floatundidf(uVar7,uVar8);
    pcVar9->total_mhashes = dVar13 + dVar12;
    dVar12 = (double)__floatundidf(uVar7,uVar8);
    decay_time(&pcVar9->rolling,dVar12,dVar11,(double)(longlong)opt_log_interval);
    dVar12 = (double)__floatundidf(uVar7,uVar8);
    decay_time(&pcVar9->rolling1,dVar12,dVar11,60.0);
    dVar12 = (double)__floatundidf(uVar7,uVar8);
    decay_time(&pcVar9->rolling5,dVar12,dVar11,300.0);
    dVar12 = (double)__floatundidf(uVar7,uVar8);
    decay_time(&pcVar9->rolling15,dVar12,dVar11,900.0);
    _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1b86);
    if ((want_per_device_stats != false) && (bVar1)) {
      get_statline(logline,0x100,pcVar9);
      printf("%s          \r",logline);
      fflush(stdout);
    }
  }
  _mutex_lock(&hash_lock,"cgminer.c","hashmeter",0x1bae);
  dVar11 = (double)__floatundidf((undefined4)hashes_done_local,hashes_done_local._4_4_);
  total_mhashes_done = dVar11 + total_mhashes_done;
  if (bVar1) {
    g_local_mhashes_index = g_local_mhashes_index + 1;
    if (0xb < g_local_mhashes_index) {
      g_local_mhashes_index = 0;
    }
    i = 0;
    while( true ) {
      if (0xb < i) break;
      if (0.0 <= g_local_mhashes_dones[i]) {
        uVar7 = __floatundidf((undefined4)local_mhashes_done_avg,local_mhashes_done_avg._4_4_);
        local_mhashes_done_avg = __fixunsdfdi((DFtype)CONCAT44(extraout_s1,uVar7));
        local_mhashes_done_count = local_mhashes_done_count + 1;
      }
      i = i + 1;
    }
    uVar14 = hashes_done_local;
    if (0 < local_mhashes_done_count) {
      uVar14 = __aeabi_uldivmod((undefined4)local_mhashes_done_avg,local_mhashes_done_avg._4_4_,
                                local_mhashes_done_count,local_mhashes_done_count >> 0x1f);
    }
    local_mhashes_done._4_4_ = (undefined4)(uVar14 >> 0x20);
    local_mhashes_done._0_4_ = (undefined4)uVar14;
    dVar11 = (double)__floatundidf((undefined4)local_mhashes_done,local_mhashes_done._4_4_);
    decay_time(&total_rolling,dVar11,(double)(longlong)opt_log_interval,
               (double)(longlong)opt_log_interval);
    dVar11 = (double)__floatundidf((undefined4)hashes_done_local,hashes_done_local._4_4_);
    decay_time(&rolling1,dVar11,dVar10,60.0);
    dVar11 = (double)__floatundidf((undefined4)hashes_done_local,hashes_done_local._4_4_);
    decay_time(&rolling5,dVar11,dVar10,300.0);
    dVar11 = (double)__floatundidf((undefined4)hashes_done_local,hashes_done_local._4_4_);
    decay_time(&rolling15,dVar11,dVar10,900.0);
    global_hashrate = __fixunsdfdi(a);
    iVar3 = g_local_mhashes_index * 8;
    *(undefined4 *)(g_local_mhashes_dones + g_local_mhashes_index) = 0;
    *(undefined4 *)((int)g_local_mhashes_dones + iVar3 + 4) = 0;
  }
  dVar11 = g_local_mhashes_dones[g_local_mhashes_index];
  uVar7 = __floatundidf((undefined4)hashes_done_local,hashes_done_local._4_4_);
  a_00 = (DFtype)CONCAT44(extraout_s1_00,extraout_s0);
  g_local_mhashes_dones[g_local_mhashes_index] = dVar11 + (double)CONCAT44(extraout_r1,uVar7);
  dVar11 = (double)(longlong)total_tv_end_sys - (double)(longlong)total_tv_start_sys;
  total_secs._0_4_ = SUB84(dVar11,0);
  total_secs._4_4_ = (undefined4)((ulonglong)dVar11 >> 0x20);
  uVar7 = total_secs._4_4_;
  dVar10 = dVar11;
  if (86400.0 < dVar11 - (double)CONCAT44(last_total_secs._4_4_,last_total_secs._0_4_)) {
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      uVar8 = total_secs._0_4_;
      total_secs = dVar11;
      snprintf(tmp42,0x800,"cgminer time error total_secs = %f last_total_secs = %f",
               last_total_secs._0_4_,uVar8,uVar7,last_total_secs._0_4_,last_total_secs._4_4_);
      _applog(3,tmp42,false);
      dVar11 = total_secs;
    }
    total_secs = dVar11;
    _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1bde);
    zero_stats();
    _mutex_lock(&hash_lock,"cgminer.c","hashmeter",0x1be0);
    dVar11 = (double)CONCAT44(last_total_secs._4_4_,last_total_secs._0_4_);
    a_00 = extraout_d0;
    dVar10 = total_secs;
  }
  total_secs = dVar10;
  last_total_secs = dVar11;
  if (bVar1) {
    UVar15 = __fixunsdfdi(a_00);
    suffix_string(UVar15,displayed_hashes,0x10,4);
    UVar15 = __fixunsdfdi(a_01);
    g_displayed_rolling = (double)(longlong)((int)(longlong)total_rolling / 10) / 100.0;
    suffix_string(UVar15,displayed_rolling,0x10,4);
    UVar15 = __fixunsdfdi(a_02);
    suffix_string(UVar15,displayed_r1,0x10,4);
    UVar15 = __fixunsdfdi(a_03);
    suffix_string(UVar15,displayed_r5,0x10,4);
    UVar15 = __fixunsdfdi(a_04);
    suffix_string(UVar15,displayed_r15,0x10,4);
    snprintf(statusline,0x100,"(%ds):%s (1m):%s (5m):%s (15m):%s (avg):%sh/s",opt_log_interval,
             displayed_rolling,displayed_r1,displayed_r5,displayed_r15,displayed_hashes);
  }
  _mutex_unlock(&hash_lock,"cgminer.c","hashmeter",0x1c09);
  dVar11 = last_total_secs;
  if (bVar1) {
    printf("%s          \r",statusline);
    fflush(stdout);
    dVar11 = last_total_secs;
  }
LAB_00052b60:
  last_total_secs._4_4_ = (undefined4)((ulonglong)dVar11 >> 0x20);
  last_total_secs._0_4_ = SUB84(dVar11,0);
  return;
}

