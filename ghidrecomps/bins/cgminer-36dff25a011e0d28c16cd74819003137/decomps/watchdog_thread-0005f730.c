
void * watchdog_thread(void *userdata)

{
  _Bool _Var1;
  cgpu_info *cgpu_00;
  time_t tVar2;
  thr_info *ptVar3;
  int iVar4;
  void *userdata_local;
  char tmp42 [2048];
  char dev_str [8];
  timeval now;
  timeval zero_tv;
  dev_enable *denable;
  thr_info *thr_1;
  cgpu_info *cgpu;
  thr_info *thr;
  uint interval;
  int i;
  
  pthread_setcanceltype(1,(int *)0x0);
  RenameThread("Watchdog");
  set_lowprio();
  memset(&zero_tv,0,8);
  cgtime(&rotate_tv);
  do {
    sleep(2);
    discard_stale();
    hashmeter(-1,0);
    cgtime(&now);
    if ((sched_paused == true) || (_Var1 = should_run(), _Var1)) {
      if ((sched_paused != false) && (_Var1 = should_run(), _Var1)) {
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
        sched_paused = false;
        for (i = 0; i < mining_threads; i = i + 1) {
          ptVar3 = get_thread(i);
          if (ptVar3->cgpu->deven != DEV_DISABLED) {
            ptVar3->pause = false;
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"Pushing sem post to thread %d",ptVar3->id);
              _applog(7,tmp42,false);
            }
            _cgsem_post(&ptVar3->sem,"cgminer.c","watchdog_thread",0x289f);
          }
        }
      }
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Pausing execution as per stop time %02d:%02d scheduled",
                 schedstop.tm.tm_hour,schedstop.tm.tm_min);
        _applog(4,tmp42,false);
      }
      if (schedstart.enable != true) {
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
      _rd_lock(&mining_thr_lock,"cgminer.c","watchdog_thread",0x287d);
      for (i = 0; i < mining_threads; i = i + 1) {
        mining_thr[i]->pause = true;
      }
      _rd_unlock(&mining_thr_lock,"cgminer.c","watchdog_thread",0x2884);
    }
    for (i = 0; i < total_devices; i = i + 1) {
      cgpu_00 = get_devices(i);
      ptVar3 = *cgpu_00->thr;
      if (ptVar3 != (thr_info *)0x0) {
        (*cgpu_00->drv->get_stats)(cgpu_00);
        iVar4 = cgpu_00->device_id;
        snprintf(dev_str,8,"%s %d",cgpu_00->drv->name,iVar4);
        if ((ptVar3->getwork == false) && (cgpu_00->deven != DEV_DISABLED)) {
          if ((cgpu_00->status == LIFE_WELL) || (0x77 < now.tv_sec - (ptVar3->last).tv_sec)) {
            if ((cgpu_00->status == LIFE_WELL) && (0x78 < now.tv_sec - (ptVar3->last).tv_sec)) {
              *(undefined4 *)&cgpu_00->rolling = 0;
              *(undefined4 *)((int)&cgpu_00->rolling + 4) = 0;
              cgpu_00->status = LIFE_SICK;
              if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                snprintf(tmp42,0x800,"%s: Idle for more than 60 seconds, declaring SICK!",dev_str,
                         iVar4);
                _applog(3,tmp42,false);
              }
              cgtime(&ptVar3->sick);
              dev_error(cgpu_00,REASON_DEV_SICK_IDLE_60);
              if ((opt_restart != false) && (_Var1 = is_re_open_core_now(), !_Var1)) {
                if ((use_syslog != false) || ((opt_log_output != false || (2 < opt_log_level)))) {
                  snprintf(tmp42,0x800,"%s: Attempting to restart",dev_str);
                  _applog(3,tmp42,false);
                }
                reinit_device(cgpu_00);
              }
            }
            else if ((cgpu_00->status == LIFE_SICK) && (600 < now.tv_sec - (ptVar3->last).tv_sec)) {
              cgpu_00->status = LIFE_DEAD;
              if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                snprintf(tmp42,0x800,"%s: Not responded for more than 10 minutes, declaring DEAD!",
                         dev_str,iVar4);
                _applog(3,tmp42,false);
              }
              cgtime(&ptVar3->sick);
              dev_error(cgpu_00,REASON_DEV_DEAD_IDLE_600);
            }
            else if ((0x3c < now.tv_sec - (ptVar3->sick).tv_sec) &&
                    (((cgpu_00->status == LIFE_SICK || (cgpu_00->status == LIFE_DEAD)) &&
                     (cgtime(&ptVar3->sick), opt_restart != false)))) {
              reinit_device(cgpu_00);
            }
          }
          else {
            if ((cgpu_00->status != LIFE_INIT) &&
               (((use_syslog != false || (opt_log_output != false)) || (2 < opt_log_level)))) {
              snprintf(tmp42,0x800,"%s: Recovered, declaring WELL!",dev_str,iVar4);
              _applog(3,tmp42,false);
            }
            cgpu_00->status = LIFE_WELL;
            tVar2 = time((time_t *)0x0);
            cgpu_00->device_last_well = tVar2;
          }
        }
      }
    }
  } while( true );
}

