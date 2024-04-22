
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void watchdog_thread(void)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  time_t tVar6;
  int *piVar7;
  undefined4 extraout_r1;
  int *piVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  undefined4 uVar13;
  int local_840 [2];
  char acStack_838 [8];
  undefined4 local_830;
  undefined4 uStack_82c;
  undefined4 uStack_828;
  undefined4 uStack_824;
  undefined4 local_820;
  undefined4 uStack_81c;
  undefined4 uStack_818;
  undefined4 uStack_814;
  undefined local_810;
  
  pthread_setcanceltype(1,(int *)0x0);
  uVar1 = DAT_00026040;
  RenameThread("Watchdog");
  set_lowprio();
  cgtime(DAT_00026048);
  do {
    sleep(2);
    discard_stale();
    hashmeter(0xffffffff,extraout_r1,0,0);
    cgtime(local_840);
    if (sched_paused == '\0') {
      iVar3 = should_run();
      if (iVar3 == 0) {
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 4)) {
          if (schedstart[0] == '\0') {
LAB_0002639a:
            local_830._0_1_ = s_Terminating_execution_as_planned_0005de60[0];
            local_830._1_1_ = s_Terminating_execution_as_planned_0005de60[1];
            local_830._2_1_ = s_Terminating_execution_as_planned_0005de60[2];
            local_830._3_1_ = s_Terminating_execution_as_planned_0005de60[3];
            uStack_82c._0_1_ = s_Terminating_execution_as_planned_0005de60[4];
            uStack_82c._1_1_ = s_Terminating_execution_as_planned_0005de60[5];
            uStack_82c._2_1_ = s_Terminating_execution_as_planned_0005de60[6];
            uStack_82c._3_1_ = s_Terminating_execution_as_planned_0005de60[7];
            uStack_828._0_1_ = s_Terminating_execution_as_planned_0005de60[8];
            uStack_828._1_1_ = s_Terminating_execution_as_planned_0005de60[9];
            uStack_828._2_1_ = s_Terminating_execution_as_planned_0005de60[10];
            uStack_828._3_1_ = s_Terminating_execution_as_planned_0005de60[11];
            uStack_824._0_1_ = s_Terminating_execution_as_planned_0005de60[12];
            uStack_824._1_1_ = s_Terminating_execution_as_planned_0005de60[13];
            uStack_824._2_1_ = s_Terminating_execution_as_planned_0005de60[14];
            uStack_824._3_1_ = s_Terminating_execution_as_planned_0005de60[15];
            local_820._0_1_ = s_Terminating_execution_as_planned_0005de60[16];
            local_820._1_1_ = s_Terminating_execution_as_planned_0005de60[17];
            local_820._2_1_ = s_Terminating_execution_as_planned_0005de60[18];
            local_820._3_1_ = s_Terminating_execution_as_planned_0005de60[19];
            uStack_81c._0_1_ = s_Terminating_execution_as_planned_0005de60[20];
            uStack_81c._1_1_ = s_Terminating_execution_as_planned_0005de60[21];
            uStack_81c._2_1_ = s_Terminating_execution_as_planned_0005de60[22];
            uStack_81c._3_1_ = s_Terminating_execution_as_planned_0005de60[23];
            uStack_818._0_1_ = s_Terminating_execution_as_planned_0005de60[24];
            uStack_818._1_1_ = s_Terminating_execution_as_planned_0005de60[25];
            uStack_818._2_1_ = s_Terminating_execution_as_planned_0005de60[26];
            uStack_818._3_1_ = s_Terminating_execution_as_planned_0005de60[27];
            uStack_814._0_1_ = s_Terminating_execution_as_planned_0005de60[28];
            uStack_814._1_1_ = s_Terminating_execution_as_planned_0005de60[29];
            uStack_814._2_1_ = s_Terminating_execution_as_planned_0005de60[30];
            uStack_814._3_1_ = s_Terminating_execution_as_planned_0005de60[31];
            local_810 = (undefined)ram0x0005de80;
            _applog(3,&local_830,1);
                    /* WARNING: Subroutine does not return */
            __quit(0,1);
          }
LAB_000261f0:
          if (3 < opt_log_level) goto LAB_000261f6;
        }
        else {
          snprintf((char *)&local_830,0x800,"Pausing execution as per stop time %02d:%02d scheduled"
                   ,schedstop._12_4_,schedstop._8_4_);
          _applog(4,&local_830,0);
          if (schedstart[0] == '\0') goto LAB_0002639a;
          if ((use_syslog == '\0') && (opt_log_output == '\0')) goto LAB_000261f0;
LAB_000261f6:
          snprintf((char *)&local_830,0x800,"Will restart execution as scheduled at %02d:%02d",
                   schedstart._12_4_,schedstart._8_4_);
          _applog(4,&local_830,0);
        }
        sched_paused = '\x01';
        iVar3 = pthread_rwlock_rdlock((pthread_rwlock_t *)mining_thr_lock);
        uVar13 = DAT_0002640c;
        if (iVar3 != 0) {
          piVar7 = __errno_location();
          snprintf((char *)&local_830,0x800,"WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
                   *piVar7,"cgminer.c",uVar13,0x2849);
          _applog(3,&local_830,1);
                    /* WARNING: Subroutine does not return */
          __quit(1,1);
        }
        if (0 < mining_threads) {
          piVar8 = mining_thr + mining_threads;
          piVar7 = mining_thr;
          do {
            piVar11 = piVar7 + 1;
            *(undefined *)(*piVar7 + 0x3c) = 1;
            piVar7 = piVar11;
          } while (piVar11 != piVar8);
        }
        iVar3 = pthread_rwlock_unlock((pthread_rwlock_t *)mining_thr_lock);
        uVar13 = DAT_0002640c;
        if (iVar3 != 0) {
          piVar7 = __errno_location();
          snprintf((char *)&local_830,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                   *piVar7,"cgminer.c",uVar13,0x2850);
          _applog(3,&local_830,1);
                    /* WARNING: Subroutine does not return */
          __quit(1);
        }
        (*selective_yield)();
      }
      else if (sched_paused != '\0') goto LAB_00025ef2;
    }
    else {
LAB_00025ef2:
      iVar3 = should_run();
      if (iVar3 != 0) {
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 4)) {
          if (schedstop[0] != '\0') {
LAB_00026352:
            if (3 < opt_log_level) goto LAB_00025f64;
          }
        }
        else {
          snprintf((char *)&local_830,0x800,
                   "Restarting execution as per start time %02d:%02d scheduled",schedstart._12_4_,
                   schedstart._8_4_);
          _applog(4,&local_830,0);
          if (schedstop[0] != '\0') {
            if ((use_syslog == '\0') && (opt_log_output == '\0')) goto LAB_00026352;
LAB_00025f64:
            snprintf((char *)&local_830,0x800,"Will pause execution as scheduled at %02d:%02d",
                     schedstop._12_4_,schedstop._8_4_);
            _applog(4,&local_830,0);
          }
        }
        uVar13 = DAT_0002604c;
        iVar3 = 0;
        sched_paused = '\0';
        if (0 < mining_threads) {
          do {
            puVar4 = (undefined4 *)get_thread(iVar3);
            cVar2 = opt_debug;
            if (*(int *)(puVar4[9] + 0x20) != 1) {
              *(undefined *)(puVar4 + 0xf) = 0;
              if ((cVar2 != '\0') &&
                 (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
                snprintf((char *)&local_830,0x800,"Pushing sem post to thread %d",*puVar4);
                _applog(7,&local_830,0);
              }
              _cgsem_post(puVar4 + 4,"cgminer.c",uVar13,0x286b);
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < mining_threads);
        }
      }
    }
    if (0 < total_devices) {
      iVar3 = 0;
      do {
        iVar5 = get_devices(iVar3);
        iVar12 = **(int **)(iVar5 + 0x98);
        if (iVar12 != 0) {
          (**(code **)(*(int *)(iVar5 + 4) + 0x20))();
          uVar13 = *(undefined4 *)(iVar5 + 8);
          snprintf(acStack_838,8,"%s %d",*(undefined4 *)(*(int *)(iVar5 + 4) + 8),uVar13);
          cVar2 = use_syslog;
          if ((*(char *)(iVar12 + 0x3d) == '\0') && (*(int *)(iVar5 + 0x20) != 1)) {
            iVar10 = *(int *)(iVar5 + 0x60);
            if (iVar10 == 0) {
              if (0x78 < local_840[0] - *(int *)(iVar12 + 0x2c)) {
                *(undefined8 *)(iVar5 + 0x30) = uVar1;
                *(undefined4 *)(iVar5 + 0x60) = 1;
                if (((cVar2 != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
                  snprintf((char *)&local_830,0x800,
                           "%s: Idle for more than 60 seconds, declaring SICK!",acStack_838,uVar13);
                  _applog(3,&local_830,0);
                }
                cgtime(iVar12 + 0x34);
                dev_error(iVar5,3);
                if (opt_restart != '\0') {
                  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
                    snprintf((char *)&local_830,0x800,"%s: Attempting to restart",acStack_838,uVar13
                            );
                    _applog(3,&local_830,0);
                  }
LAB_000260f4:
                  if (*(int *)(iVar5 + 0x20) != 1) {
                    reinit_device_part_38(iVar5);
                  }
                }
              }
            }
            else {
              iVar9 = local_840[0] - *(int *)(iVar12 + 0x2c);
              if (iVar9 < 0x78) {
                if ((iVar10 != 4) &&
                   (((use_syslog != '\0' || (opt_log_output != '\0')) || (2 < opt_log_level)))) {
                  snprintf((char *)&local_830,0x800,"%s: Recovered, declaring WELL!",acStack_838,
                           uVar13);
                  _applog(3,&local_830,0);
                }
                *(undefined4 *)(iVar5 + 0x60) = 0;
                tVar6 = time((time_t *)0x0);
                *(time_t *)(iVar5 + 0xf0) = tVar6;
              }
              else if (iVar10 == 1) {
                if (iVar9 < 0x259) {
                  if (0x3c < local_840[0] - *(int *)(iVar12 + 0x34)) goto LAB_0002632e;
                }
                else {
                  *(undefined4 *)(iVar5 + 0x60) = 2;
                  if (((cVar2 != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
                    snprintf((char *)&local_830,0x800,
                             "%s: Not responded for more than 10 minutes, declaring DEAD!",
                             acStack_838,uVar13);
                    _applog(3,&local_830,0);
                  }
                  cgtime(iVar12 + 0x34);
                  dev_error(iVar5,4);
                }
              }
              else if ((0x3c < local_840[0] - *(int *)(iVar12 + 0x34)) && (iVar10 == 2)) {
LAB_0002632e:
                cgtime(iVar12 + 0x34);
                if (opt_restart != '\0') goto LAB_000260f4;
              }
            }
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < total_devices);
    }
  } while( true );
}

