
/* WARNING: Unknown calling convention */

void * watchdog_thread(void *userdata)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  char *pcVar4;
  int *piVar5;
  int *piVar6;
  _Bool _Var7;
  thr_info *ptVar8;
  thr_info *thr;
  cgpu_info *dev;
  time_t tVar9;
  int iVar10;
  thr_info **pptVar11;
  _Bool *func;
  alive aVar12;
  thr_info **line;
  thr_info **pptVar13;
  int iVar14;
  int iVar15;
  cgpu_info *cgpu;
  thr_info *thr_1;
  int in_stack_fffff7b8;
  undefined4 in_stack_fffff7bc;
  timeval zero_tv;
  timeval now;
  char dev_str [8];
  char tmp42 [2048];
  
  pthread_setcanceltype(1,(int *)0x0);
  RenameThread(DAT_000287a8);
  set_lowprio();
  piVar6 = DAT_000287e8;
  cgtime(DAT_000287ac);
  do {
    sleep(2);
    discard_stale();
    hashmeter(-1,CONCAT44(in_stack_fffff7bc,in_stack_fffff7b8));
    cgtime(&now);
    if (sched_paused == false) {
      _Var7 = should_run();
      if (_Var7) {
        if (sched_paused != false) goto LAB_00028526;
      }
      else {
        if (((use_syslog != false) || (*DAT_00028988 != '\0')) || (3 < *DAT_0002898c)) {
          in_stack_fffff7b8 = *(int *)(DAT_00028990 + 8);
          snprintf(tmp42,0x800,DAT_00028994,*(undefined4 *)(DAT_00028990 + 0xc));
          _applog(4,tmp42,false);
        }
        if (schedstart.enable == false) {
          tmp42._0_4_ = *DAT_000289a0;
          tmp42._4_4_ = DAT_000289a0[1];
          tmp42._8_4_ = DAT_000289a0[2];
          tmp42._12_4_ = DAT_000289a0[3];
          tmp42._16_4_ = DAT_000289a0[4];
          tmp42._20_4_ = DAT_000289a0[5];
          tmp42._24_4_ = DAT_000289a0[6];
          tmp42._28_4_ = DAT_000289a0[7];
          tmp42[32] = (char)DAT_000289a0[8];
          _applog(3,tmp42,true);
          _quit(0);
          return (void *)0x0;
        }
        if (((use_syslog != false) || (*DAT_00028988 != '\0')) || (3 < *DAT_0002898c)) {
          in_stack_fffff7b8 = schedstart.tm.tm_min;
          snprintf(tmp42,0x800,DAT_00028998,schedstart.tm.tm_hour);
          _applog(4,tmp42,false);
        }
        line = (thr_info **)0x1;
        func = &sched_paused;
        sched_paused = true;
        iVar14 = pthread_rwlock_rdlock(DAT_0002899c);
        if (iVar14 != 0) {
          _rd_lock(DAT_000289a4,(char *)0x2828,func,(int)line);
        }
        if (0 < *piVar6) {
          pptVar11 = mining_thr + *piVar6;
          pptVar13 = mining_thr;
          do {
            line = pptVar13 + 1;
            func = (_Bool *)*pptVar13;
            *(_Bool *)((int)func + 0x3c) = true;
            pptVar13 = line;
          } while (line != pptVar11);
        }
        iVar14 = pthread_rwlock_unlock(DAT_0002899c);
        if (iVar14 != 0) {
          _rw_unlock(DAT_000289a4,(char *)0x282f,func,(int)line);
        }
        (*selective_yield)();
      }
    }
    else {
LAB_00028526:
      _Var7 = should_run();
      if (_Var7) {
        if (((use_syslog != false) || (*DAT_000287b0 != '\0')) || (3 < *DAT_000287b4)) {
          in_stack_fffff7b8 = schedstart.tm.tm_min;
          snprintf(tmp42,0x800,DAT_000287b8,schedstart.tm.tm_hour);
          _applog(4,tmp42,false);
        }
        if ((*DAT_000287bc != '\0') &&
           (((use_syslog != false || (*DAT_000287b0 != '\0')) || (3 < *DAT_000287b4)))) {
          in_stack_fffff7b8 = *(int *)(DAT_000287bc + 8);
          snprintf(tmp42,0x800,DAT_000287e4,*(undefined4 *)(DAT_000287bc + 0xc));
          _applog(4,tmp42,false);
        }
        pcVar4 = DAT_000287c0;
        piVar3 = DAT_000287b4;
        pcVar2 = DAT_000287b0;
        iVar14 = 0;
        sched_paused = false;
        if (0 < *piVar6) {
          do {
            iVar15 = iVar14 + 1;
            ptVar8 = get_thread(iVar14);
            if (ptVar8->cgpu->deven != DEV_DISABLED) {
              cVar1 = *pcVar4;
              ptVar8->pause = false;
              if ((cVar1 != '\0') && (((use_syslog != false || (*pcVar2 != '\0')) || (6 < *piVar3)))
                 ) {
                snprintf(tmp42,0x800,DAT_000287c4,ptVar8->id);
                _applog(7,tmp42,false);
              }
              _cgsem_post(&ptVar8->sem,DAT_000287c8,DAT_000287cc,0x284a);
            }
            iVar14 = iVar15;
          } while (iVar15 < *piVar6);
        }
      }
    }
    iVar14 = DAT_000287ec;
    piVar5 = DAT_000287d0;
    piVar3 = DAT_000287b4;
    pcVar2 = DAT_000287b0;
    if (0 < *DAT_000287d0) {
      iVar15 = 0;
      do {
        dev = get_devices(iVar15);
        ptVar8 = *dev->thr;
        if (ptVar8 != (thr_info *)0x0) {
          (*dev->drv->get_stats)(dev);
          in_stack_fffff7b8 = dev->device_id;
          snprintf(dev_str,8,DAT_000287dc,dev->drv->name);
          _Var7 = use_syslog;
          if ((ptVar8->getwork == false) && (dev->deven != DEV_DISABLED)) {
            aVar12 = dev->status;
            iVar10 = now.tv_sec - (ptVar8->last).tv_sec;
            if (aVar12 == LIFE_WELL) {
              if (iVar10 < 0x79) {
LAB_00028786:
                if ((0x3c < now.tv_sec - (ptVar8->sick).tv_sec) &&
                   ((aVar12 + ~LIFE_WELL < 2 &&
                    (cgtime(&ptVar8->sick), *(char *)(iVar14 + 0x824) != '\0')))) {
LAB_000286c6:
                  reinit_device(dev);
                }
              }
              else {
                dev->status = LIFE_SICK;
                dev->rolling = 0.0;
                if (((_Var7 != false) || (*pcVar2 != '\0')) || (2 < *piVar3)) {
                  snprintf(tmp42,0x800,DAT_000287d4,dev_str);
                  _applog(3,tmp42,false);
                }
                cgtime(&ptVar8->sick);
                dev_error(dev,REASON_DEV_SICK_IDLE_60);
                if (*(char *)(iVar14 + 0x824) != '\0') {
                  if (((use_syslog != false) || (*pcVar2 != '\0')) || (2 < *piVar3)) {
                    snprintf(tmp42,0x800,DAT_000287d8,dev_str);
                    _applog(3,tmp42,false);
                  }
                  goto LAB_000286c6;
                }
              }
            }
            else if (iVar10 < 0x78) {
              if ((aVar12 != LIFE_INIT) &&
                 (((use_syslog != false || (*pcVar2 != '\0')) || (2 < *piVar3)))) {
                snprintf(tmp42,0x800,DAT_000287e0,dev_str);
                _applog(3,tmp42,false);
              }
              dev->status = LIFE_WELL;
              tVar9 = time((time_t *)0x0);
              dev->device_last_well = tVar9;
            }
            else {
              if ((aVar12 != LIFE_SICK) || (iVar10 < 0x259)) goto LAB_00028786;
              dev->status = LIFE_DEAD;
              if (((_Var7 != false) || (*pcVar2 != '\0')) || (2 < *piVar3)) {
                snprintf(tmp42,0x800,DAT_00028984,dev_str);
                _applog(3,tmp42,false);
              }
              cgtime(&ptVar8->sick);
              dev_error(dev,REASON_DEV_DEAD_IDLE_600);
            }
          }
        }
        iVar15 = iVar15 + 1;
      } while (iVar15 < *piVar5);
    }
  } while( true );
}

