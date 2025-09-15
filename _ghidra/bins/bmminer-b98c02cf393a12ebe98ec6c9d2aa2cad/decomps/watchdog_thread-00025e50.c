
void watchdog_thread(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  time_t tVar5;
  int *piVar6;
  undefined4 extraout_r1;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  undefined4 uVar12;
  int local_840 [2];
  char acStack_838 [8];
  char local_830 [2052];
  
  pthread_setcanceltype(1,(int *)0x0);
  RenameThread("Watchdog");
  set_lowprio();
  cgtime(&rotate_tv);
  do {
    sleep(2);
    discard_stale();
    hashmeter(0xffffffff,extraout_r1,0,0);
    cgtime(local_840);
    if (sched_paused == '\0') {
      iVar2 = should_run();
      if (iVar2 == 0) {
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 4)) {
          if (schedstart[0] == '\0') {
LAB_0002639a:
            builtin_strncpy(local_830,"Terminating execution as planned",0x20);
            local_830[0x20] = 0;
            _applog(3,local_830,1);
                    /* WARNING: Subroutine does not return */
            __quit(0,1);
          }
LAB_000261f0:
          if (3 < opt_log_level) goto LAB_000261f6;
        }
        else {
          snprintf(local_830,0x800,"Pausing execution as per stop time %02d:%02d scheduled",
                   schedstop._12_4_,schedstop._8_4_);
          _applog(4,local_830,0);
          if (schedstart[0] == '\0') goto LAB_0002639a;
          if ((use_syslog == '\0') && (opt_log_output == '\0')) goto LAB_000261f0;
LAB_000261f6:
          snprintf(local_830,0x800,"Will restart execution as scheduled at %02d:%02d",
                   schedstart._12_4_,schedstart._8_4_);
          _applog(4,local_830,0);
        }
        sched_paused = '\x01';
        iVar2 = pthread_rwlock_rdlock((pthread_rwlock_t *)mining_thr_lock);
        if (iVar2 != 0) {
          piVar6 = __errno_location();
          snprintf(local_830,0x800,"WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar6,
                   "cgminer.c","watchdog_thread",0x2849);
          _applog(3,local_830,1);
                    /* WARNING: Subroutine does not return */
          __quit(1,1);
        }
        if (0 < mining_threads) {
          piVar7 = mining_thr + mining_threads;
          piVar6 = mining_thr;
          do {
            piVar10 = piVar6 + 1;
            *(undefined1 *)(*piVar6 + 0x3c) = 1;
            piVar6 = piVar10;
          } while (piVar10 != piVar7);
        }
        iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)mining_thr_lock);
        if (iVar2 != 0) {
          piVar6 = __errno_location();
          snprintf(local_830,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar6,
                   "cgminer.c","watchdog_thread",0x2850);
          _applog(3,local_830,1);
                    /* WARNING: Subroutine does not return */
          __quit(1);
        }
        (*selective_yield)();
      }
      else if (sched_paused != '\0') goto LAB_00025ef2;
    }
    else {
LAB_00025ef2:
      iVar2 = should_run();
      if (iVar2 != 0) {
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 4)) {
          if (schedstop[0] != '\0') {
LAB_00026352:
            if (3 < opt_log_level) goto LAB_00025f64;
          }
        }
        else {
          snprintf(local_830,0x800,"Restarting execution as per start time %02d:%02d scheduled",
                   schedstart._12_4_,schedstart._8_4_);
          _applog(4,local_830,0);
          if (schedstop[0] != '\0') {
            if ((use_syslog == '\0') && (opt_log_output == '\0')) goto LAB_00026352;
LAB_00025f64:
            snprintf(local_830,0x800,"Will pause execution as scheduled at %02d:%02d",
                     schedstop._12_4_,schedstop._8_4_);
            _applog(4,local_830,0);
          }
        }
        iVar2 = 0;
        sched_paused = '\0';
        if (0 < mining_threads) {
          do {
            puVar3 = (undefined4 *)get_thread(iVar2);
            cVar1 = opt_debug;
            if (*(int *)(puVar3[9] + 0x20) != 1) {
              *(undefined1 *)(puVar3 + 0xf) = 0;
              if ((cVar1 != '\0') &&
                 (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
                snprintf(local_830,0x800,"Pushing sem post to thread %d",*puVar3);
                _applog(7,local_830,0);
              }
              _cgsem_post(puVar3 + 4,"cgminer.c","watchdog_thread",0x286b);
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < mining_threads);
        }
      }
    }
    if (0 < total_devices) {
      iVar2 = 0;
      do {
        iVar4 = get_devices(iVar2);
        iVar11 = **(int **)(iVar4 + 0x98);
        if (iVar11 != 0) {
          (**(code **)(*(int *)(iVar4 + 4) + 0x20))();
          uVar12 = *(undefined4 *)(iVar4 + 8);
          snprintf(acStack_838,8,"%s %d",*(undefined4 *)(*(int *)(iVar4 + 4) + 8),uVar12);
          cVar1 = use_syslog;
          if ((*(char *)(iVar11 + 0x3d) == '\0') && (*(int *)(iVar4 + 0x20) != 1)) {
            iVar9 = *(int *)(iVar4 + 0x60);
            if (iVar9 == 0) {
              if (0x78 < local_840[0] - *(int *)(iVar11 + 0x2c)) {
                *(undefined8 *)(iVar4 + 0x30) = 0;
                *(undefined4 *)(iVar4 + 0x60) = 1;
                if (((cVar1 != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
                  snprintf(local_830,0x800,"%s: Idle for more than 60 seconds, declaring SICK!",
                           acStack_838,uVar12);
                  _applog(3,local_830,0);
                }
                cgtime(iVar11 + 0x34);
                dev_error(iVar4,3);
                if (opt_restart != '\0') {
                  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
                    snprintf(local_830,0x800,"%s: Attempting to restart",acStack_838,uVar12);
                    _applog(3,local_830,0);
                  }
LAB_000260f4:
                  if (*(int *)(iVar4 + 0x20) != 1) {
                    reinit_device_part_38(iVar4);
                  }
                }
              }
            }
            else {
              iVar8 = local_840[0] - *(int *)(iVar11 + 0x2c);
              if (iVar8 < 0x78) {
                if ((iVar9 != 4) &&
                   (((use_syslog != '\0' || (opt_log_output != '\0')) || (2 < opt_log_level)))) {
                  snprintf(local_830,0x800,"%s: Recovered, declaring WELL!",acStack_838,uVar12);
                  _applog(3,local_830,0);
                }
                *(undefined4 *)(iVar4 + 0x60) = 0;
                tVar5 = time((time_t *)0x0);
                *(time_t *)(iVar4 + 0xf0) = tVar5;
              }
              else if (iVar9 == 1) {
                if (iVar8 < 0x259) {
                  if (0x3c < local_840[0] - *(int *)(iVar11 + 0x34)) goto LAB_0002632e;
                }
                else {
                  *(undefined4 *)(iVar4 + 0x60) = 2;
                  if (((cVar1 != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
                    snprintf(local_830,0x800,
                             "%s: Not responded for more than 10 minutes, declaring DEAD!",
                             acStack_838,uVar12);
                    _applog(3,local_830,0);
                  }
                  cgtime(iVar11 + 0x34);
                  dev_error(iVar4,4);
                }
              }
              else if ((0x3c < local_840[0] - *(int *)(iVar11 + 0x34)) && (iVar9 == 2)) {
LAB_0002632e:
                cgtime(iVar11 + 0x34);
                if (opt_restart != '\0') goto LAB_000260f4;
              }
            }
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < total_devices);
    }
  } while( true );
}

