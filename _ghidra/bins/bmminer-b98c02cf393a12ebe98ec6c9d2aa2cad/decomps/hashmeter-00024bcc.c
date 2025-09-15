
/* WARNING: Heritage AFTER dead removal. Example location: s1 : 0x0002502e */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void hashmeter(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  double dVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  char *__format;
  int iVar9;
  byte bVar10;
  undefined1 *puVar11;
  undefined4 extraout_s0;
  double in_d0;
  double extraout_d0;
  DFtype extraout_d0_00;
  DFtype extraout_d0_01;
  undefined4 uVar13;
  double dVar12;
  double extraout_d0_02;
  undefined4 uVar14;
  undefined4 in_s3;
  double dVar15;
  undefined8 uVar16;
  double dVar17;
  UDItype UVar18;
  undefined4 local_8e8;
  undefined4 uStack_8e4;
  undefined1 auStack_8d8 [16];
  undefined1 auStack_8c8 [16];
  undefined1 auStack_8b8 [16];
  undefined1 auStack_8a8 [16];
  sysinfo local_898;
  char acStack_858 [2052];
  
  uVar16 = CONCAT44(param_4,param_3);
  iVar5 = sysinfo(&local_898);
  if (iVar5 == 0) {
    total_tv_end_sys = local_898.uptime;
  }
  else {
    if (((use_syslog != 0) || (opt_log_output != 0)) || (5 < (int)opt_log_level)) {
      piVar6 = __errno_location();
      iVar5 = *piVar6;
      strerror(iVar5);
      snprintf(acStack_858,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar5);
      _applog(6,acStack_858,0);
    }
    total_tv_end_sys = time((time_t *)0x0);
  }
  cgtime(&total_tv_end);
  tdiff(&total_tv_end,&tv_hashmeter);
  iVar5 = (int)total_tv_end;
  extraout_s0 = SUB84(in_d0,0);
  uVar13 = (undefined4)((ulonglong)in_d0 >> 0x20);
  if ((int)total_tv_end - hashdisplay_t < opt_log_interval) {
    if (param_1 < 0) {
      return;
    }
    copy_time(&tv_hashmeter,&total_tv_end);
    bVar10 = 0;
LAB_00024cb4:
    iVar7 = get_thread(param_1);
    iVar9 = *(int *)(iVar7 + 0x24);
    copy_time(iVar7 + 0x2c,&total_tv_end);
    *(int *)(iVar9 + 0xf0) = iVar5;
    tdiff(&total_tv_end,iVar9 + 0x8c);
    copy_time(iVar9 + 0x8c,&total_tv_end);
    if ((opt_debug != '\0') &&
       (((use_syslog != 0 || (opt_log_output != 0)) || (6 < (int)opt_log_level)))) {
      __floatundidf(param_3,param_4);
      snprintf(acStack_858,0x800,"[thread %d: %llu hashes, %.1f mhash/sec]",param_1);
      _applog(7,acStack_858,0);
    }
    uVar16 = __aeabi_uldivmod(param_3,param_4,&DAT_000f4240,0);
    iVar5 = pthread_mutex_lock((pthread_mutex_t *)hash_lock);
    if (iVar5 != 0) {
      piVar6 = __errno_location();
      iVar5 = *piVar6;
      goto LAB_00025428;
    }
    dVar17 = (double)__floatundidf((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
    uVar8 = SUB84(dVar17,0);
    *(double *)(iVar9 + 0x50) = *(double *)(iVar9 + 0x50) + dVar17;
    if (0.0 < in_d0) {
      decay_time_part_37(uVar8,uVar13,extraout_s0,in_s3,SUB84((double)(longlong)opt_log_interval,0),
                         iVar9 + 0x30);
      if ((0.0 < in_d0) &&
         (decay_time_part_37(uVar8,uVar13,extraout_s0,in_s3,0,iVar9 + 0x38), 0.0 < in_d0)) {
        decay_time_part_37(uVar8,uVar13,extraout_s0,in_s3,0,iVar9 + 0x40);
        if (0.0 < in_d0) {
          decay_time_part_37(uVar8,uVar13,extraout_s0,in_s3,0,iVar9 + 0x48);
        }
      }
    }
    iVar5 = pthread_mutex_unlock((pthread_mutex_t *)hash_lock);
    if (iVar5 == 0) {
      (*selective_yield)();
      if ((bVar10 & want_per_device_stats) != 0) {
        get_statline(acStack_858,0x100,iVar9);
        printf("%s          \r",acStack_858);
        fflush(stdout);
      }
      iVar5 = pthread_mutex_lock((pthread_mutex_t *)hash_lock);
      if (iVar5 != 0) goto LAB_00025414;
      total_mhashes_done = total_mhashes_done + dVar17;
      dVar12 = extraout_d0;
      if (bVar10 != 0) goto LAB_000250e8;
      iVar5 = g_local_mhashes_index * 8;
      dVar15 = *(double *)(g_local_mhashes_dones + iVar5);
      bVar3 = false;
      dVar12 = extraout_d0;
LAB_00024e7c:
      dVar4 = last_total_secs;
      lVar1 = (longlong)total_tv_end_sys;
      lVar2 = (longlong)total_tv_start_sys;
      *(double *)(g_local_mhashes_dones + iVar5) = dVar17 + dVar15;
      total_secs = (double)lVar1 - (double)lVar2;
      if (total_secs - dVar4 <= 86400.0) {
        last_total_secs = total_secs;
        if (!bVar3) goto LAB_00024f40;
LAB_00025258:
        UVar18 = __fixunsdfdi(dVar12);
        suffix_string((int)UVar18,(int)(UVar18 >> 0x20),auStack_8d8,0x10);
        g_displayed_rolling = (double)(longlong)((int)(longlong)total_rolling / 10) / 100.0;
        UVar18 = __fixunsdfdi(dVar12);
        suffix_string((int)UVar18,(int)(UVar18 >> 0x20),auStack_8c8,0x10);
        UVar18 = __fixunsdfdi(dVar12);
        suffix_string((int)UVar18,(int)(UVar18 >> 0x20),auStack_8b8,0x10);
        UVar18 = __fixunsdfdi(dVar12);
        suffix_string((int)UVar18,(int)(UVar18 >> 0x20),auStack_8a8,0x10);
        UVar18 = __fixunsdfdi(dVar12);
        suffix_string((int)UVar18,(int)(UVar18 >> 0x20),acStack_858,0x10);
        snprintf(statusline,0x100,"(%ds):%s (1m):%s (5m):%s (15m):%s (avg):%sh/s",opt_log_interval);
        iVar5 = pthread_mutex_unlock((pthread_mutex_t *)hash_lock);
        if (iVar5 == 0) {
          (*selective_yield)();
          printf("%s          \r",statusline);
          fflush(stdout);
          return;
        }
      }
      else {
        if (((use_syslog != 0) || (opt_log_output != 0)) || (2 < (int)opt_log_level)) {
          snprintf(acStack_858,0x800,"cgminer time error total_secs = %d last_total_secs = %d");
          _applog(3,acStack_858,0);
        }
        iVar5 = pthread_mutex_unlock((pthread_mutex_t *)hash_lock);
        if (iVar5 != 0) {
          piVar6 = __errno_location();
          iVar5 = *piVar6;
          goto LAB_000254ac;
        }
        (*selective_yield)();
        zero_stats();
        iVar5 = pthread_mutex_lock((pthread_mutex_t *)hash_lock);
        if (iVar5 != 0) {
          piVar6 = __errno_location();
          iVar5 = *piVar6;
          goto LAB_00025428;
        }
        dVar12 = extraout_d0_00;
        if (bVar3) goto LAB_00025258;
LAB_00024f40:
        iVar5 = pthread_mutex_unlock((pthread_mutex_t *)hash_lock);
        if (iVar5 == 0) {
          (*selective_yield)();
          return;
        }
      }
      piVar6 = __errno_location();
      snprintf(acStack_858,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar6);
      goto LAB_00025442;
    }
    piVar6 = __errno_location();
    iVar5 = *piVar6;
LAB_000254ac:
    __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
  }
  else {
    hashdisplay_t = (int)total_tv_end;
    copy_time(&tv_hashmeter,&total_tv_end);
    if (-1 < param_1) {
      bVar10 = 1;
      goto LAB_00024cb4;
    }
    iVar5 = pthread_mutex_lock((pthread_mutex_t *)hash_lock);
    if (iVar5 == 0) {
      if (0 < mining_threads) {
        iVar5 = 0;
        do {
          iVar7 = get_thread(iVar5);
          iVar7 = *(int *)(iVar7 + 0x24);
          tdiff(&total_tv_end,iVar7 + 0x8c);
          copy_time(iVar7 + 0x8c,&total_tv_end);
          if (0.0 < in_d0) {
            decay_time_part_37(0,uVar13,extraout_s0,in_s3,
                               SUB84((double)(longlong)opt_log_interval,0),iVar7 + 0x30);
            if ((0.0 < in_d0) &&
               (decay_time_part_37(0,uVar13,extraout_s0,in_s3,0,iVar7 + 0x38), 0.0 < in_d0)) {
              decay_time_part_37(0,uVar13,extraout_s0,in_s3,0,iVar7 + 0x40);
              if (0.0 < in_d0) {
                decay_time_part_37(0,uVar13,extraout_s0,in_s3,0,iVar7 + 0x48);
              }
            }
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < mining_threads);
      }
      iVar5 = pthread_mutex_unlock((pthread_mutex_t *)hash_lock);
      if (iVar5 != 0) {
        piVar6 = __errno_location();
        iVar5 = *piVar6;
        goto LAB_000254ac;
      }
      (*selective_yield)();
      iVar5 = pthread_mutex_lock((pthread_mutex_t *)hash_lock);
      if (iVar5 == 0) {
        dVar17 = (double)__floatundidf(param_3,param_4);
        total_mhashes_done = total_mhashes_done + dVar17;
        dVar12 = in_d0;
LAB_000250e8:
        iVar5 = 0;
        UVar18 = 0;
        g_local_mhashes_index = g_local_mhashes_index + 1;
        if (0xb < g_local_mhashes_index) {
          g_local_mhashes_index = 0;
        }
        puVar11 = g_local_mhashes_dones;
        do {
          dVar15 = *(double *)puVar11;
          puVar11 = (undefined1 *)((int)puVar11 + 8);
          if (0.0 <= dVar15) {
            __floatundidf((int)UVar18,(int)(UVar18 >> 0x20));
            iVar5 = iVar5 + 1;
            UVar18 = __fixunsdfdi(dVar12);
            dVar12 = extraout_d0_01;
          }
        } while ((int *)puVar11 != &g_local_mhashes_index);
        if (iVar5 != 0) {
          uVar16 = __aeabi_uldivmod((int)UVar18,(int)(UVar18 >> 0x20),iVar5,iVar5 >> 0x1f);
        }
        uStack_8e4 = (undefined4)((ulonglong)uVar16 >> 0x20);
        local_8e8 = (undefined4)uVar16;
        lVar1 = (longlong)opt_log_interval;
        uVar13 = (undefined4)((ulonglong)dVar12 >> 0x20);
        if (0.0 < (double)lVar1) {
          uVar8 = __floatundidf(local_8e8,uStack_8e4);
          uVar14 = SUB84((double)lVar1,0);
          decay_time_part_37(uVar8,uVar13,uVar14,in_s3,uVar14,&total_rolling);
        }
        if (0.0 < in_d0) {
          uVar8 = SUB84(dVar17,0);
          decay_time_part_37(uVar8,uVar13,extraout_s0,in_s3,0,&rolling1);
          dVar12 = (double)CONCAT44(uVar13,uVar8);
          if (0.0 < in_d0) {
            decay_time_part_37(uVar8,uVar13,extraout_s0,in_s3,0,&rolling5);
            dVar12 = (double)CONCAT44(uVar13,uVar8);
            if (0.0 < in_d0) {
              decay_time_part_37(uVar8,uVar13,extraout_s0,in_s3,0,&rolling15);
              dVar12 = (double)CONCAT44(uVar13,uVar8);
            }
          }
        }
        bVar3 = true;
        global_hashrate = __fixunsdfdi(dVar12);
        dVar15 = 0.0;
        iVar5 = g_local_mhashes_index * 8;
        *(undefined8 *)(g_local_mhashes_dones + iVar5) = 0;
        dVar12 = extraout_d0_02;
        goto LAB_00024e7c;
      }
LAB_00025414:
      piVar6 = __errno_location();
      iVar5 = *piVar6;
    }
    else {
      piVar6 = __errno_location();
      iVar5 = *piVar6;
    }
LAB_00025428:
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
  }
  snprintf(acStack_858,0x800,__format,iVar5);
LAB_00025442:
  _applog(3,acStack_858,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

