
/* WARNING: Heritage AFTER dead removal. Example location: s1 : 0x0002502e */
/* WARNING: Restarted to delay deadcode elimination for space: register */

void hashmeter(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  double *pdVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int iVar8;
  int *piVar9;
  char *pcVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  double *pdVar14;
  byte bVar15;
  double *pdVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  double dVar20;
  double dVar21;
  undefined4 in_s3;
  double dVar22;
  undefined8 uVar23;
  double dVar24;
  UDItype UVar25;
  double in_stack_fffff700;
  DFtype DVar26;
  undefined4 local_8e8;
  undefined4 uStack_8e4;
  double *local_8dc;
  undefined auStack_8d8 [16];
  undefined auStack_8c8 [16];
  undefined auStack_8b8 [16];
  undefined auStack_8a8 [16];
  sysinfo local_898;
  char acStack_858 [2052];
  
  uVar23 = CONCAT44(param_4,param_3);
  iVar8 = sysinfo(&local_898);
  if (iVar8 == 0) {
    total_tv_end_sys = local_898.uptime;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
      piVar9 = __errno_location();
      uVar17 = (undefined4)((ulonglong)in_stack_fffff700 >> 0x20);
      iVar8 = *piVar9;
      pcVar10 = strerror(iVar8);
      in_stack_fffff700 = (double)CONCAT44(uVar17,pcVar10);
      snprintf(acStack_858,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar8);
      _applog(6,acStack_858,0);
    }
    total_tv_end_sys = time((time_t *)0x0);
  }
  cgtime(&total_tv_end);
  dVar20 = (double)tdiff(&total_tv_end,&tv_hashmeter);
  iVar8 = (int)total_tv_end;
  uVar17 = SUB84(dVar20,0);
  if ((int)total_tv_end - hashdisplay_t < opt_log_interval) {
    if (param_1 < 0) {
      return;
    }
    copy_time(&tv_hashmeter,&total_tv_end);
    bVar15 = 0;
LAB_00024cb4:
    iVar11 = get_thread(param_1);
    iVar13 = *(int *)(iVar11 + 0x24);
    copy_time(iVar11 + 0x2c,DAT_00024fa8);
    uVar18 = DAT_00024fa8;
    *(int *)(iVar13 + 0xf0) = iVar8;
    dVar21 = (double)tdiff(uVar18,iVar13 + 0x8c);
    uVar12 = (undefined4)((ulonglong)dVar21 >> 0x20);
    uVar18 = SUB84(dVar21,0);
    copy_time(iVar13 + 0x8c,DAT_00024fa8);
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      __floatundidf(param_3,param_4);
      in_stack_fffff700 = (double)CONCAT44(param_4,param_3);
      snprintf(acStack_858,0x800,"[thread %d: %llu hashes, %.1f mhash/sec]",param_1);
      _applog(7,acStack_858,0);
    }
    uVar23 = __aeabi_uldivmod(param_3,param_4,&DAT_000f4240,0);
    iVar8 = pthread_mutex_lock((pthread_mutex_t *)hash_lock);
    if (iVar8 != 0) {
      piVar9 = __errno_location();
      iVar8 = *piVar9;
      goto LAB_00025428;
    }
    dVar24 = (double)__floatundidf((int)uVar23,(int)((ulonglong)uVar23 >> 0x20));
    uVar19 = SUB84(dVar24,0);
    *(double *)(iVar13 + 0x50) = *(double *)(iVar13 + 0x50) + dVar24;
    if (0.0 < dVar21) {
      decay_time_part_37(uVar19,uVar12,uVar18,in_s3,SUB84((double)(longlong)opt_log_interval,0),
                         iVar13 + 0x30);
      if ((0.0 < dVar21) &&
         (decay_time_part_37(uVar19,uVar12,uVar18,in_s3,(int)DAT_00024f88,iVar13 + 0x38),
         0.0 < dVar21)) {
        decay_time_part_37(uVar19,uVar12,uVar18,in_s3,(int)DAT_00024f90,iVar13 + 0x40);
        if (0.0 < dVar21) {
          decay_time_part_37(uVar19,uVar12,uVar18,in_s3,(int)DAT_00024f98,iVar13 + 0x48);
        }
      }
    }
    iVar8 = pthread_mutex_unlock((pthread_mutex_t *)hash_lock);
    if (iVar8 == 0) {
      (*selective_yield)();
      if ((bVar15 & want_per_device_stats) != 0) {
        get_statline(acStack_858,0x100,iVar13);
        printf("%s          \r",acStack_858);
        fflush(stdout);
      }
      iVar8 = pthread_mutex_lock((pthread_mutex_t *)hash_lock);
      if (iVar8 != 0) goto LAB_00025414;
      total_mhashes_done = total_mhashes_done + dVar24;
      if (bVar15 != 0) goto LAB_000250e8;
      local_8dc = DAT_00024fac;
      dVar20 = DAT_00024fac[g_local_mhashes_index];
      bVar3 = false;
      iVar8 = g_local_mhashes_index;
LAB_00024e7c:
      pdVar4 = DAT_00024fb0;
      dVar21 = DAT_00024fa0;
      lVar1 = (longlong)total_tv_end_sys;
      lVar2 = (longlong)total_tv_start_sys;
      pdVar16 = DAT_00024fb0 + 4;
      dVar22 = *pdVar16;
      local_8dc[iVar8] = dVar24 + dVar20;
      dVar20 = (double)lVar1 - (double)lVar2;
      dVar22 = dVar20 - dVar22;
      *pdVar4 = dVar20;
      if (dVar22 == dVar21 || dVar22 < dVar21 != (NAN(dVar22) || NAN(dVar21))) {
        *pdVar16 = dVar20;
        if (!bVar3) goto LAB_00024f40;
LAB_00025258:
        pdVar4 = DAT_00025528;
        UVar25 = __fixunsdfdi(in_stack_fffff700);
        DVar26 = (DFtype)CONCAT44((int)((ulonglong)in_stack_fffff700 >> 0x20),4);
        suffix_string((int)UVar25,(int)(UVar25 >> 0x20),auStack_8d8,0x10);
        *pdVar4 = (double)(longlong)((int)(longlong)total_rolling / 10) / DAT_00025520;
        UVar25 = __fixunsdfdi(DVar26);
        DVar26 = (DFtype)CONCAT44((int)((ulonglong)DVar26 >> 0x20),4);
        suffix_string((int)UVar25,(int)(UVar25 >> 0x20),auStack_8c8,0x10);
        UVar25 = __fixunsdfdi(DVar26);
        DVar26 = (DFtype)CONCAT44((int)((ulonglong)DVar26 >> 0x20),4);
        suffix_string((int)UVar25,(int)(UVar25 >> 0x20),auStack_8b8,0x10);
        UVar25 = __fixunsdfdi(DVar26);
        DVar26 = (DFtype)CONCAT44((int)((ulonglong)DVar26 >> 0x20),4);
        suffix_string((int)UVar25,(int)(UVar25 >> 0x20),auStack_8a8,0x10);
        UVar25 = __fixunsdfdi(DVar26);
        suffix_string((int)UVar25,(int)(UVar25 >> 0x20),acStack_858,0x10);
        snprintf((char *)(pdVar4 + 1),0x100,"(%ds):%s (1m):%s (5m):%s (15m):%s (avg):%sh/s",
                 opt_log_interval);
        iVar8 = pthread_mutex_unlock((pthread_mutex_t *)hash_lock);
        if (iVar8 == 0) {
          (*selective_yield)();
          printf("%s          \r",pdVar4 + 1);
          fflush(stdout);
          return;
        }
      }
      else {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
          snprintf(acStack_858,0x800,"cgminer time error total_secs = %d last_total_secs = %d");
          _applog(3,acStack_858,0);
          in_stack_fffff700 = dVar20;
        }
        iVar8 = pthread_mutex_unlock((pthread_mutex_t *)hash_lock);
        if (iVar8 != 0) {
          piVar9 = __errno_location();
          iVar8 = *piVar9;
          goto LAB_000254ac;
        }
        (*selective_yield)();
        zero_stats();
        iVar8 = pthread_mutex_lock((pthread_mutex_t *)hash_lock);
        if (iVar8 != 0) {
          piVar9 = __errno_location();
          iVar8 = *piVar9;
          goto LAB_00025428;
        }
        if (bVar3) goto LAB_00025258;
LAB_00024f40:
        iVar8 = pthread_mutex_unlock((pthread_mutex_t *)hash_lock);
        if (iVar8 == 0) {
          (*selective_yield)();
          return;
        }
      }
      piVar9 = __errno_location();
      snprintf(acStack_858,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar9);
      goto LAB_00025442;
    }
    piVar9 = __errno_location();
    iVar8 = *piVar9;
LAB_000254ac:
    pcVar10 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
  }
  else {
    hashdisplay_t = (int)total_tv_end;
    copy_time(&tv_hashmeter,&total_tv_end);
    if (-1 < param_1) {
      bVar15 = 1;
      goto LAB_00024cb4;
    }
    iVar8 = pthread_mutex_lock((pthread_mutex_t *)hash_lock);
    uVar7 = DAT_00025238;
    uVar6 = DAT_00025230;
    uVar5 = DAT_00025228;
    dVar24 = DAT_00025220;
    if (iVar8 == 0) {
      dVar21 = dVar20;
      if (0 < mining_threads) {
        iVar8 = 0;
        do {
          iVar11 = get_thread(iVar8);
          iVar11 = *(int *)(iVar11 + 0x24);
          dVar22 = (double)tdiff(&total_tv_end,iVar11 + 0x8c);
          uVar12 = (undefined4)((ulonglong)dVar22 >> 0x20);
          uVar18 = SUB84(dVar22,0);
          copy_time(iVar11 + 0x8c,&total_tv_end);
          dVar21 = dVar22;
          if (0.0 < dVar22) {
            uVar19 = SUB84(dVar24,0);
            dVar21 = (double)CONCAT44(uVar12,uVar19);
            decay_time_part_37(uVar19,uVar12,uVar18,in_s3,
                               SUB84((double)(longlong)opt_log_interval,0),iVar11 + 0x30);
            if ((0.0 < dVar22) &&
               (decay_time_part_37(uVar19,uVar12,uVar18,in_s3,(int)uVar5,iVar11 + 0x38),
               0.0 < dVar22)) {
              decay_time_part_37(uVar19,uVar12,uVar18,in_s3,(int)uVar6,iVar11 + 0x40);
              if (0.0 < dVar22) {
                decay_time_part_37(uVar19,uVar12,uVar18,in_s3,(int)uVar7,iVar11 + 0x48);
              }
            }
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < mining_threads);
      }
      iVar8 = pthread_mutex_unlock((pthread_mutex_t *)hash_lock);
      if (iVar8 != 0) {
        piVar9 = __errno_location();
        iVar8 = *piVar9;
        goto LAB_000254ac;
      }
      (*selective_yield)();
      iVar8 = pthread_mutex_lock((pthread_mutex_t *)hash_lock);
      if (iVar8 == 0) {
        dVar24 = (double)__floatundidf(param_3,param_4);
        total_mhashes_done = total_mhashes_done + dVar24;
LAB_000250e8:
        pdVar4 = DAT_00025248;
        iVar8 = 0;
        UVar25 = 0;
        g_local_mhashes_index = g_local_mhashes_index + 1;
        if (0xb < g_local_mhashes_index) {
          g_local_mhashes_index = 0;
        }
        pdVar14 = DAT_00025248 + 0xc;
        local_8dc = DAT_00025248;
        pdVar16 = DAT_00025248;
        do {
          dVar22 = *pdVar16;
          pdVar16 = pdVar16 + 1;
          if (dVar22 < 0.0 == NAN(dVar22)) {
            __floatundidf((int)UVar25,(int)(UVar25 >> 0x20));
            iVar8 = iVar8 + 1;
            UVar25 = __fixunsdfdi(in_stack_fffff700);
          }
        } while (pdVar14 != pdVar16);
        if (iVar8 != 0) {
          uVar23 = __aeabi_uldivmod((int)UVar25,(int)(UVar25 >> 0x20),iVar8,iVar8 >> 0x1f);
        }
        uStack_8e4 = (undefined4)((ulonglong)uVar23 >> 0x20);
        local_8e8 = (undefined4)uVar23;
        lVar1 = (longlong)opt_log_interval;
        uVar18 = (undefined4)((ulonglong)dVar21 >> 0x20);
        if (0.0 < (double)lVar1) {
          uVar12 = __floatundidf(local_8e8,uStack_8e4);
          uVar19 = SUB84((double)lVar1,0);
          decay_time_part_37(uVar12,uVar18,uVar19,in_s3,uVar19,&total_rolling);
        }
        if (0.0 < dVar20) {
          uVar12 = SUB84(dVar24,0);
          decay_time_part_37(uVar12,uVar18,uVar17,in_s3,(int)DAT_00025228,&rolling1);
          if ((0.0 < dVar20) &&
             (decay_time_part_37(uVar12,uVar18,uVar17,in_s3,(int)DAT_00025230,&rolling5),
             0.0 < dVar20)) {
            decay_time_part_37(uVar12,uVar18,uVar17,in_s3,(int)DAT_00025238,&rolling15);
          }
        }
        bVar3 = true;
        global_hashrate = __fixunsdfdi(in_stack_fffff700);
        iVar8 = g_local_mhashes_index;
        dVar20 = DAT_00025220;
        pdVar4[g_local_mhashes_index] = DAT_00025220;
        goto LAB_00024e7c;
      }
LAB_00025414:
      piVar9 = __errno_location();
      iVar8 = *piVar9;
    }
    else {
      piVar9 = __errno_location();
      iVar8 = *piVar9;
    }
LAB_00025428:
    pcVar10 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
  }
  snprintf(acStack_858,0x800,pcVar10,iVar8);
LAB_00025442:
  _applog(3,acStack_858,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

