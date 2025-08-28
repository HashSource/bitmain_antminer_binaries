
/* WARNING: Unknown calling convention */

void * watchdog_thread(void *userdata)

{
  _Bool _Var1;
  thr_info *ptVar2;
  cgpu_info *dev;
  time_t tVar3;
  int iVar4;
  thr_info **pptVar5;
  char *func;
  char *func_00;
  alive aVar6;
  int line;
  thr_info **pptVar7;
  int line_00;
  int iVar9;
  int iVar10;
  timeval zero_tv;
  timeval now;
  char dev_str [8];
  char tmp42 [2048];
  thr_info **pptVar8;
  
  pthread_setcanceltype(1,(int *)0x0);
  RenameThread("Watchdog");
  set_lowprio();
  cgtime(&rotate_tv);
  do {
    sleep(2);
    discard_stale();
    hashmeter(-1,0);
    cgtime(&now);
    if (sched_paused == false) {
      _Var1 = should_run();
      if (_Var1) {
        if (sched_paused != false) goto LAB_00028526;
      }
      else {
        if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          snprintf(tmp42,0x800,"Pausing execution as per stop time %02d:%02d scheduled",
                   schedstop.tm.tm_hour,schedstop.tm.tm_min);
          _applog(4,tmp42,false);
        }
        if (schedstart.enable == false) {
          builtin_strncpy(tmp42,"Terminating execution as planned",0x20);
          tmp42[0x20] = '\0';
          _applog(3,tmp42,true);
          _quit(0);
          return (void *)0x0;
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          snprintf(tmp42,0x800,"Will restart execution as scheduled at %02d:%02d",
                   schedstart.tm.tm_hour,schedstart.tm.tm_min);
          _applog(4,tmp42,false);
        }
        sched_paused = true;
        iVar9 = pthread_rwlock_rdlock((pthread_rwlock_t *)&mining_thr_lock);
        if (iVar9 != 0) {
          _rd_lock((pthread_rwlock_t *)"watchdog_thread",(char *)0x2828,func,line);
        }
        if (0 < mining_threads) {
          pptVar5 = mining_thr + mining_threads;
          pptVar7 = mining_thr;
          do {
            pptVar8 = pptVar7 + 1;
            (*pptVar7)->pause = true;
            pptVar7 = pptVar8;
          } while (pptVar8 != pptVar5);
        }
        iVar9 = pthread_rwlock_unlock((pthread_rwlock_t *)&mining_thr_lock);
        if (iVar9 != 0) {
          _rw_unlock((pthread_rwlock_t *)"watchdog_thread",(char *)0x282f,func_00,line_00);
        }
        (*selective_yield)();
      }
    }
    else {
LAB_00028526:
      _Var1 = should_run();
      if (_Var1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          snprintf(tmp42,0x800,"Restarting execution as per start time %02d:%02d scheduled",
                   schedstart.tm.tm_hour,schedstart.tm.tm_min);
          _applog(4,tmp42,false);
        }
        if ((schedstop.enable != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
          snprintf(tmp42,0x800,"Will pause execution as scheduled at %02d:%02d",schedstop.tm.tm_hour
                   ,schedstop.tm.tm_min);
          _applog(4,tmp42,false);
        }
        iVar9 = 0;
        sched_paused = false;
        if (0 < mining_threads) {
          do {
            iVar10 = iVar9 + 1;
            ptVar2 = get_thread(iVar9);
            _Var1 = opt_debug;
            if (ptVar2->cgpu->deven != DEV_DISABLED) {
              ptVar2->pause = false;
              if ((_Var1 != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,"Pushing sem post to thread %d",ptVar2->id);
                _applog(7,tmp42,false);
              }
              _cgsem_post(&ptVar2->sem,"cgminer.c","watchdog_thread",0x284a);
            }
            iVar9 = iVar10;
          } while (iVar10 < mining_threads);
        }
      }
    }
    if (0 < total_devices) {
      iVar9 = 0;
      do {
        dev = get_devices(iVar9);
        ptVar2 = *dev->thr;
        if (ptVar2 != (thr_info *)0x0) {
          (*dev->drv->get_stats)(dev);
          iVar10 = dev->device_id;
          snprintf(dev_str,8,"%s %d",dev->drv->name,iVar10);
          _Var1 = use_syslog;
          if ((ptVar2->getwork == false) && (dev->deven != DEV_DISABLED)) {
            aVar6 = dev->status;
            iVar4 = now.tv_sec - (ptVar2->last).tv_sec;
            if (aVar6 == LIFE_WELL) {
              if (iVar4 < 0x79) {
LAB_00028786:
                if ((0x3c < now.tv_sec - (ptVar2->sick).tv_sec) &&
                   ((aVar6 - LIFE_SICK < 2 && (cgtime(&ptVar2->sick), opt_restart != false)))) {
LAB_000286c6:
                  reinit_device(dev);
                }
              }
              else {
                dev->status = LIFE_SICK;
                dev->rolling = 0.0;
                if (((_Var1 != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                  snprintf(tmp42,0x800,"%s: Idle for more than 60 seconds, declaring SICK!",dev_str,
                           iVar10);
                  _applog(3,tmp42,false);
                }
                cgtime(&ptVar2->sick);
                dev_error(dev,REASON_DEV_SICK_IDLE_60);
                if (opt_restart != false) {
                  if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                    snprintf(tmp42,0x800,"%s: Attempting to restart",dev_str,iVar10);
                    _applog(3,tmp42,false);
                  }
                  goto LAB_000286c6;
                }
              }
            }
            else if (iVar4 < 0x78) {
              if ((aVar6 != LIFE_INIT) &&
                 (((use_syslog != false || (opt_log_output != false)) || (2 < opt_log_level)))) {
                snprintf(tmp42,0x800,"%s: Recovered, declaring WELL!",dev_str,iVar10);
                _applog(3,tmp42,false);
              }
              dev->status = LIFE_WELL;
              tVar3 = time((time_t *)0x0);
              dev->device_last_well = tVar3;
            }
            else {
              if ((aVar6 != LIFE_SICK) || (iVar4 < 0x259)) goto LAB_00028786;
              dev->status = LIFE_DEAD;
              if (((_Var1 != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                snprintf(tmp42,0x800,"%s: Not responded for more than 10 minutes, declaring DEAD!",
                         dev_str,iVar10);
                _applog(3,tmp42,false);
              }
              cgtime(&ptVar2->sick);
              dev_error(dev,REASON_DEV_DEAD_IDLE_600);
            }
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < total_devices);
    }
  } while( true );
}

