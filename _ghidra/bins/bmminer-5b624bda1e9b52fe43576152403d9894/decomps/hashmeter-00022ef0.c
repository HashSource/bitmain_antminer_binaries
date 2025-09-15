
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void hashmeter(int thr_id,uint64_t hashes_done)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  ulonglong uVar4;
  __time_t _Var5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  thr_info *ptVar9;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  char *func_03;
  char *func_04;
  char *func_05;
  char *func_06;
  int line;
  int line_00;
  int line_01;
  uint uVar10;
  int line_02;
  int line_03;
  int line_04;
  int line_05;
  int line_06;
  cgpu_info *pcVar11;
  int iVar12;
  double *pdVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  undefined8 uVar18;
  uint64_t uVar19;
  undefined8 local_8cc;
  char displayed_hashes [16];
  char displayed_rolling [16];
  char displayed_r1 [16];
  char displayed_r5 [16];
  sysinfo sInfo;
  char tmp42 [2048];
  
  iVar6 = sysinfo((sysinfo *)&sInfo);
  if (iVar6 == 0) {
    total_tv_end_sys = sInfo.uptime;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      piVar7 = __errno_location();
      iVar6 = *piVar7;
      pcVar8 = strerror(iVar6);
      snprintf(tmp42,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar6,pcVar8);
      _applog(6,tmp42,false);
    }
    total_tv_end_sys = time((time_t *)0x0);
  }
  cgtime(&total_tv_end);
  dVar14 = tdiff(&total_tv_end,&tv_hashmeter);
  _Var5 = total_tv_end.tv_sec;
  uVar4 = CONCAT44(global_hashrate._4_4_,(undefined4)global_hashrate);
  if (total_tv_end.tv_sec - hashdisplay_t < opt_log_interval) {
    if (thr_id < 0) goto LAB_00023314;
    copy_time(&tv_hashmeter,&total_tv_end);
    bVar3 = false;
LAB_00022fa6:
    ptVar9 = get_thread(thr_id);
    pcVar11 = ptVar9->cgpu;
    copy_time(&ptVar9->last,&total_tv_end);
    pcVar11->device_last_well = _Var5;
    dVar15 = tdiff(&total_tv_end,&pcVar11->last_message_tv);
    copy_time(&pcVar11->last_message_tv,&total_tv_end);
    local_8cc._4_4_ = (undefined4)(hashes_done >> 0x20);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      uVar19 = hashes_done;
      dVar17 = (double)__aeabi_ul2d();
      snprintf(tmp42,0x800,"[thread %d: %llu hashes, %.1f mhash/sec]",thr_id,uVar19,
               (dVar17 / dVar15) / 1000000.0);
      _applog(7,tmp42,false);
    }
    local_8cc._0_4_ = (undefined4)hashes_done;
    local_8cc = __aeabi_uldivmod((undefined4)local_8cc,local_8cc._4_4_,1000000,0);
    iVar6 = pthread_mutex_lock((pthread_mutex_t *)&hash_lock);
    if (iVar6 != 0) {
      _mutex_lock((pthread_mutex_t *)"hashmeter",(char *)0x1b2d,func,line);
    }
    dVar17 = (double)__aeabi_ul2d((int)local_8cc,(int)(local_8cc >> 0x20));
    lVar1 = (longlong)opt_log_interval;
    pcVar11->total_mhashes = pcVar11->total_mhashes + dVar17;
    decay_time(&pcVar11->rolling,dVar17,dVar15,(double)lVar1);
    decay_time(&pcVar11->rolling1,dVar17,dVar15,60.0);
    decay_time(&pcVar11->rolling5,dVar17,dVar15,300.0);
    decay_time(&pcVar11->rolling15,dVar17,dVar15,900.0);
    iVar6 = pthread_mutex_unlock((pthread_mutex_t *)&hash_lock);
    if (iVar6 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)"hashmeter",(char *)0x1b34,func_00,line_00);
    }
    (*selective_yield)();
    if ((want_per_device_stats != false) && (bVar3)) {
      get_statline(tmp42,0x100,pcVar11);
      printf("%s          \r",tmp42);
      fflush(stdout);
    }
  }
  else {
    hashdisplay_t = total_tv_end.tv_sec;
    copy_time(&tv_hashmeter,&total_tv_end);
    if (-1 < thr_id) {
      bVar3 = true;
      goto LAB_00022fa6;
    }
    iVar6 = pthread_mutex_lock((pthread_mutex_t *)&hash_lock);
    if (iVar6 != 0) {
      _mutex_lock((pthread_mutex_t *)"hashmeter",(char *)0x1b4a,func_05,line_05);
    }
    if (0 < mining_threads) {
      iVar6 = 0;
      do {
        iVar12 = iVar6 + 1;
        ptVar9 = get_thread(iVar6);
        pcVar11 = ptVar9->cgpu;
        dVar15 = tdiff(&total_tv_end,&pcVar11->last_message_tv);
        copy_time(&pcVar11->last_message_tv,&total_tv_end);
        decay_time(&pcVar11->rolling,0.0,dVar15,(double)(longlong)opt_log_interval);
        decay_time(&pcVar11->rolling1,0.0,dVar15,60.0);
        decay_time(&pcVar11->rolling5,0.0,dVar15,300.0);
        decay_time(&pcVar11->rolling15,0.0,dVar15,900.0);
        iVar6 = iVar12;
      } while (iVar12 < mining_threads);
    }
    iVar6 = pthread_mutex_unlock((pthread_mutex_t *)&hash_lock);
    if (iVar6 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)"hashmeter",(char *)0x1b59,func_06,line_06);
    }
    bVar3 = true;
    (*selective_yield)();
    local_8cc = hashes_done;
  }
  iVar6 = pthread_mutex_lock((pthread_mutex_t *)&hash_lock);
  if (iVar6 != 0) {
    _mutex_lock((pthread_mutex_t *)"hashmeter",(char *)0x1b5c,func_01,line_01);
  }
  dVar15 = (double)__aeabi_ul2d((undefined4)local_8cc,local_8cc._4_4_);
  total_mhashes_done = dVar15 + total_mhashes_done;
  if (bVar3) {
    g_local_mhashes_index = g_local_mhashes_index + 1;
    iVar6 = 0;
    if (0xb < g_local_mhashes_index) {
      g_local_mhashes_index = 0;
    }
    uVar18 = 0;
    pdVar13 = g_local_mhashes_dones;
    do {
      dVar17 = *pdVar13;
      pdVar13 = pdVar13 + 1;
      if (0.0 <= dVar17) {
        dVar16 = (double)__aeabi_ul2d((int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
        iVar6 = iVar6 + 1;
        dVar17 = dVar17 + dVar16;
        uVar18 = __fixunsdfdi(SUB84(dVar17,0),(int)((ulonglong)dVar17 >> 0x20));
      }
    } while (pdVar13 != (double *)&g_local_mhashes_index);
    if (iVar6 != 0) {
      local_8cc = __aeabi_uldivmod((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),iVar6,iVar6 >> 0x1f)
      ;
    }
    lVar1 = (longlong)opt_log_interval;
    dVar17 = (double)__aeabi_ul2d((int)local_8cc,(int)(local_8cc >> 0x20));
    decay_time(&total_rolling,dVar17,(double)lVar1,(double)lVar1);
    decay_time(&rolling1,dVar15,dVar14,60.0);
    decay_time(&rolling5,dVar15,dVar14,300.0);
    decay_time(&rolling15,dVar15,dVar14,900.0);
    global_hashrate =
         __fixunsdfdi(SUB84(total_rolling * 1000000.0,0),
                      (int)((ulonglong)(total_rolling * 1000000.0) >> 0x20));
    iVar6 = g_local_mhashes_index;
    dVar14 = 0.0;
    g_local_mhashes_dones[g_local_mhashes_index] = 0.0;
  }
  else {
    dVar14 = g_local_mhashes_dones[g_local_mhashes_index];
    iVar6 = g_local_mhashes_index;
  }
  dVar17 = last_total_secs;
  lVar1 = (longlong)total_tv_start_sys;
  lVar2 = (longlong)total_tv_end_sys;
  g_local_mhashes_dones[iVar6] = dVar15 + dVar14;
  total_secs = (double)lVar2 - (double)lVar1;
  dVar14 = total_secs;
  if (86400.0 < total_secs - dVar17) {
    uVar10 = (uint)use_syslog;
    if (((use_syslog != 0) || (uVar10 = (uint)opt_log_output, opt_log_output != 0)) ||
       (uVar10 = opt_log_level, 2 < opt_log_level)) {
      snprintf(tmp42,0x800,"cgminer time error total_secs = %d last_total_secs = %d",uVar10,
               total_secs,dVar17);
      _applog(3,tmp42,false);
    }
    iVar6 = pthread_mutex_unlock((pthread_mutex_t *)&hash_lock);
    if (iVar6 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)"hashmeter",(char *)0x1b8c,func_02,line_02);
    }
    (*selective_yield)();
    zero_stats();
    iVar6 = pthread_mutex_lock((pthread_mutex_t *)&hash_lock);
    dVar14 = last_total_secs;
    if (iVar6 != 0) {
      _mutex_lock((pthread_mutex_t *)"hashmeter",(char *)0x1b8e,func_03,line_03);
      dVar14 = last_total_secs;
    }
  }
  last_total_secs = dVar14;
  if (bVar3) {
    dVar14 = (total_mhashes_done / total_secs) * 1000000.0;
    uVar19 = __fixunsdfdi(SUB84(dVar14,0),(int)((ulonglong)dVar14 >> 0x20));
    suffix_string(uVar19,displayed_hashes,0x10,4);
    g_displayed_rolling = (double)(longlong)((int)(longlong)total_rolling / 10) / 100.0;
    uVar19 = __fixunsdfdi(SUB84(total_rolling * 1000000.0,0),
                          (int)((ulonglong)(total_rolling * 1000000.0) >> 0x20));
    suffix_string(uVar19,displayed_rolling,0x10,4);
    uVar19 = __fixunsdfdi(SUB84(rolling1 * 1000000.0,0),
                          (int)((ulonglong)(rolling1 * 1000000.0) >> 0x20));
    suffix_string(uVar19,displayed_r1,0x10,4);
    uVar19 = __fixunsdfdi(SUB84(rolling5 * 1000000.0,0),
                          (int)((ulonglong)(rolling5 * 1000000.0) >> 0x20));
    suffix_string(uVar19,displayed_r5,0x10,4);
    uVar19 = __fixunsdfdi(SUB84(rolling15 * 1000000.0,0),
                          (int)((ulonglong)(rolling15 * 1000000.0) >> 0x20));
    suffix_string(uVar19,tmp42,0x10,4);
    snprintf(statusline,0x100,"(%ds):%s (1m):%s (5m):%s (15m):%s (avg):%sh/s",opt_log_interval,
             displayed_rolling,displayed_r1,displayed_r5,tmp42,displayed_hashes);
  }
  iVar6 = pthread_mutex_unlock((pthread_mutex_t *)&hash_lock);
  if (iVar6 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"hashmeter",(char *)0x1bb7,func_04,line_04);
  }
  (*selective_yield)();
  uVar4 = global_hashrate;
  if (bVar3) {
    printf("%s          \r",statusline);
    fflush(stdout);
    uVar4 = global_hashrate;
  }
LAB_00023314:
  global_hashrate._4_4_ = (undefined4)(uVar4 >> 0x20);
  global_hashrate._0_4_ = (undefined4)uVar4;
  return;
}

