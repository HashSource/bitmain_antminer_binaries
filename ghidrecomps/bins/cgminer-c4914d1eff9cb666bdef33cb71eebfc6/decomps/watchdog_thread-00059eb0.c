
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * watchdog_thread(void *userdata)

{
  _Bool _Var1;
  cgpu_info *cgpu_00;
  time_t tVar2;
  thr_info *ptVar3;
  int in_stack_fffff7b0;
  undefined4 in_stack_fffff7b4;
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
    hashmeter(-1,CONCAT44(in_stack_fffff7b4,in_stack_fffff7b0));
    cgtime(&now);
    if ((sched_paused == true) || (_Var1 = should_run(), _Var1)) {
      if ((sched_paused != false) && (_Var1 = should_run(), _Var1)) {
        if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          in_stack_fffff7b0 = schedstart.tm.tm_min;
          snprintf(tmp42,0x800,"Restarting execution as per start time %02d:%02d scheduled",
                   schedstart.tm.tm_hour);
          _applog(4,tmp42,false);
        }
        if ((schedstop.enable != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
          in_stack_fffff7b0 = schedstop.tm.tm_min;
          snprintf(tmp42,0x800,"Will pause execution as scheduled at %02d:%02d",schedstop.tm.tm_hour
                  );
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
        in_stack_fffff7b0 = schedstop.tm.tm_min;
        snprintf(tmp42,0x800,"Pausing execution as per stop time %02d:%02d scheduled",
                 schedstop.tm.tm_hour);
        _applog(4,tmp42,false);
      }
      if (schedstart.enable != true) {
        tmp42[0] = s_Terminating_execution_as_planned_0008dc80[0];
        tmp42[1] = s_Terminating_execution_as_planned_0008dc80[1];
        tmp42[2] = s_Terminating_execution_as_planned_0008dc80[2];
        tmp42[3] = s_Terminating_execution_as_planned_0008dc80[3];
        tmp42[4] = s_Terminating_execution_as_planned_0008dc80[4];
        tmp42[5] = s_Terminating_execution_as_planned_0008dc80[5];
        tmp42[6] = s_Terminating_execution_as_planned_0008dc80[6];
        tmp42[7] = s_Terminating_execution_as_planned_0008dc80[7];
        tmp42[8] = s_Terminating_execution_as_planned_0008dc80[8];
        tmp42[9] = s_Terminating_execution_as_planned_0008dc80[9];
        tmp42[10] = s_Terminating_execution_as_planned_0008dc80[10];
        tmp42[11] = s_Terminating_execution_as_planned_0008dc80[11];
        tmp42[12] = s_Terminating_execution_as_planned_0008dc80[12];
        tmp42[13] = s_Terminating_execution_as_planned_0008dc80[13];
        tmp42[14] = s_Terminating_execution_as_planned_0008dc80[14];
        tmp42[15] = s_Terminating_execution_as_planned_0008dc80[15];
        tmp42[16] = s_Terminating_execution_as_planned_0008dc80[16];
        tmp42[17] = s_Terminating_execution_as_planned_0008dc80[17];
        tmp42[18] = s_Terminating_execution_as_planned_0008dc80[18];
        tmp42[19] = s_Terminating_execution_as_planned_0008dc80[19];
        tmp42[20] = s_Terminating_execution_as_planned_0008dc80[20];
        tmp42[21] = s_Terminating_execution_as_planned_0008dc80[21];
        tmp42[22] = s_Terminating_execution_as_planned_0008dc80[22];
        tmp42[23] = s_Terminating_execution_as_planned_0008dc80[23];
        tmp42[24] = s_Terminating_execution_as_planned_0008dc80[24];
        tmp42[25] = s_Terminating_execution_as_planned_0008dc80[25];
        tmp42[26] = s_Terminating_execution_as_planned_0008dc80[26];
        tmp42[27] = s_Terminating_execution_as_planned_0008dc80[27];
        tmp42[28] = s_Terminating_execution_as_planned_0008dc80[28];
        tmp42[29] = s_Terminating_execution_as_planned_0008dc80[29];
        tmp42[30] = s_Terminating_execution_as_planned_0008dc80[30];
        tmp42[31] = s_Terminating_execution_as_planned_0008dc80[31];
        tmp42[32] = (char)ram0x0008dca0;
        _applog(3,tmp42,true);
        _quit(0);
        return (void *)0x0;
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        in_stack_fffff7b0 = schedstart.tm.tm_min;
        snprintf(tmp42,0x800,"Will restart execution as scheduled at %02d:%02d",
                 schedstart.tm.tm_hour);
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
        in_stack_fffff7b0 = cgpu_00->device_id;
        snprintf(dev_str,8,"%s %d",cgpu_00->drv->name);
        if ((ptVar3->getwork == false) && (cgpu_00->deven != DEV_DISABLED)) {
          if ((cgpu_00->status == LIFE_WELL) || (0x77 < now.tv_sec - (ptVar3->last).tv_sec)) {
            if ((cgpu_00->status == LIFE_WELL) && (0x78 < now.tv_sec - (ptVar3->last).tv_sec)) {
              *(undefined4 *)&cgpu_00->rolling = 0;
              *(undefined4 *)((int)&cgpu_00->rolling + 4) = 0;
              cgpu_00->status = LIFE_SICK;
              if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                snprintf(tmp42,0x800,"%s: Idle for more than 60 seconds, declaring SICK!",dev_str);
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
                         dev_str);
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
              snprintf(tmp42,0x800,"%s: Recovered, declaring WELL!",dev_str);
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

