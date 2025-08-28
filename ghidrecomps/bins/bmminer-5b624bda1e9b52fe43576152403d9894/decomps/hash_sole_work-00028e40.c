
/* WARNING: Removing unreachable block (ram,0x00028ed4) */
/* WARNING: Unknown calling convention */

void hash_sole_work(thr_info *mythr)

{
  uint64_t hashes_done;
  __time_t _Var1;
  __suseconds_t _Var2;
  _Bool _Var3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  cgpu_info *cgpu;
  cgpu_info *dev;
  device_drv *drv;
  timeval *b;
  timeval *ptVar11;
  int thr_id;
  _func__Bool_thr_info_ptr_work_ptr *p_Var12;
  timeval *b_00;
  pool *ppVar13;
  dev_enable dVar14;
  dev_enable dVar15;
  dev_enable dVar16;
  bool bVar17;
  double dVar18;
  int64_t iVar19;
  uint local_86c;
  uint local_858;
  work *local_84c;
  timeval getwork_start;
  timeval tv_start;
  timeval tv_workstart;
  timeval tv_lastupdate;
  timespec rgtp;
  
  dev = mythr->cgpu;
  drv = dev->drv;
  thr_id = mythr->id;
  iVar8 = opt_log_interval / 5;
  if (iVar8 == 0) {
    iVar8 = 1;
  }
  if (mythr->device_thread == 0) {
    local_858 = 1;
  }
  else {
    local_858 = (uint)mythr->primary_thread;
  }
  local_86c = (*drv->can_limit_work)(mythr);
  cgtime(&getwork_start);
  cgtime(&tv_lastupdate);
  if (dev->shutdown == false) {
    iVar9 = iVar8 * 1000000;
    hashes_done = 0;
    dVar15 = DEV_ENABLED;
    dVar16 = DEV_ENABLED;
    do {
      local_84c = get_work(mythr,thr_id);
      mythr->work_restart = false;
      dev->new_work = true;
      cgtime(&tv_workstart);
      p_Var12 = drv->prepare_work;
      local_84c->nonce = 0;
      *(undefined4 *)&dev->max_hashes = 0;
      *(undefined4 *)((int)&dev->max_hashes + 4) = 0;
      _Var3 = (*p_Var12)(mythr,local_84c);
      if (!_Var3) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          snprintf((char *)&rgtp,0x800,"work prepare failed, exiting mining thread %d",thr_id);
          _applog(3,(char *)&rgtp,false);
        }
        break;
      }
      dVar18 = drv->max_diff;
      if (local_84c->work_difficulty < drv->max_diff) {
        dVar18 = local_84c->work_difficulty;
      }
      if ((int)((uint)(dVar18 < drv->min_diff) << 0x1f) < 0) {
        dVar18 = drv->min_diff;
      }
      b = &(dev->cgminer_stats).getwork_wait_max;
      b_00 = &(dev->cgminer_stats).getwork_wait_min;
      local_84c->device_diff = dVar18;
LAB_00028ff6:
      cgtime(&tv_start);
      subtime(&tv_start,&getwork_start);
      addtime(&getwork_start,&(dev->cgminer_stats).getwork_wait);
      _Var3 = time_more(&getwork_start,b);
      if (_Var3) {
        copy_time(b,&getwork_start);
        _Var3 = time_less(&getwork_start,b_00);
        if (_Var3) goto LAB_00029188;
      }
      else {
        _Var3 = time_less(&getwork_start,b_00);
        if (_Var3) {
LAB_00029188:
          copy_time(b_00,&getwork_start);
        }
      }
      ppVar13 = local_84c->pool;
      (dev->cgminer_stats).getwork_calls = (dev->cgminer_stats).getwork_calls + 1;
      ptVar11 = &(ppVar13->cgminer_stats).getwork_wait_max;
      addtime(&getwork_start,&(ppVar13->cgminer_stats).getwork_wait);
      _Var3 = time_more(&getwork_start,ptVar11);
      if (_Var3) {
        copy_time(ptVar11,&getwork_start);
      }
      ptVar11 = &(ppVar13->cgminer_stats).getwork_wait_min;
      _Var3 = time_less(&getwork_start,ptVar11);
      if (_Var3) {
        copy_time(ptVar11,&getwork_start);
      }
      (ppVar13->cgminer_stats).getwork_calls = (ppVar13->cgminer_stats).getwork_calls + 1;
      cgtime(&local_84c->tv_work_start);
      pthread_setcancelstate(1,(int *)0x0);
      thread_reportin(mythr);
      iVar19 = (*drv->scanhash)(mythr,local_84c,(ulonglong)(local_86c + local_84c->nonce));
      iVar7 = (int)((ulonglong)iVar19 >> 0x20);
      thread_reportout(mythr);
      pthread_setcancelstate(0,(int *)0x0);
      pthread_testcancel();
      cgtime(&getwork_start);
      _Var2 = getwork_start.tv_usec;
      _Var1 = getwork_start.tv_sec;
      if (iVar19 != -1) {
        iVar6 = *(int *)((int)&dev->max_hashes + 4);
        hashes_done = iVar19 + hashes_done;
        bVar17 = (uint)dev->max_hashes < (uint)iVar19;
        if ((int)((iVar6 - iVar7) - (uint)bVar17) < 0 !=
            (SBORROW4(iVar6,iVar7) != SBORROW4(iVar6 - iVar7,(uint)bVar17))) {
          dev->max_hashes = iVar19;
        }
        iVar7 = getwork_start.tv_sec - tv_start.tv_sec;
        iVar6 = getwork_start.tv_usec - tv_start.tv_usec;
        if (iVar6 < 0) {
          iVar7 = iVar7 + -1;
          iVar6 = iVar6 + 1000000;
        }
        dVar16 = dVar16 + iVar7;
        dVar14 = dVar15 + iVar6;
        dVar15 = dVar14;
        if (1000000 < (int)dVar14) {
          dVar15 = dVar14 - 0xf4000;
          dVar16 = dVar16 + DEV_DISABLED;
        }
        if (1000000 < (int)dVar14) {
          dVar15 = dVar15 - 0x240;
        }
        iVar7 = getwork_start.tv_sec - tv_workstart.tv_sec;
        if (getwork_start.tv_usec - tv_workstart.tv_usec < 0) {
          iVar7 = iVar7 + -1;
        }
        if ((int)dVar16 < iVar8) {
          if (local_86c != 0xffffffff) {
            iVar6 = dVar15 + 0x7ff;
            if (-1 < (int)(dVar15 + 0x400)) {
              iVar6 = dVar15 + 0x400;
            }
            iVar6 = __aeabi_idiv(1000000,iVar6 >> 10);
            iVar6 = (iVar6 + 0x10) * iVar8;
            uVar4 = __aeabi_uidiv(0xfffffc00,iVar6);
            if (uVar4 < local_86c) {
              local_86c = 0xffffffff;
            }
            else {
              local_86c = local_86c * iVar6 >> 10;
            }
            goto LAB_0002913c;
          }
        }
        else {
          if (iVar8 < (int)dVar16) {
            local_86c = __aeabi_uidiv(iVar8 * local_86c,dVar16);
          }
          else if (100000 < (int)dVar15) {
            uVar5 = __aeabi_idiv(iVar9 + dVar15,(int)(iVar9 + 0x3ffU & iVar9 >> 0x20) >> 10);
            local_86c = __aeabi_uidiv(local_86c << 10,uVar5);
          }
LAB_0002913c:
          iVar6 = _Var2 - tv_lastupdate.tv_usec;
          bVar17 = iVar6 < 0;
          if (bVar17) {
            iVar6 = iVar6 + 0xf4000;
          }
          iVar10 = _Var1 - tv_lastupdate.tv_sec;
          if (bVar17) {
            iVar10 = iVar10 + -1;
            iVar6 = iVar6 + 0x240;
          }
          if (((hashes_done != 0) && ((0 < iVar10 || (200000 < iVar6)))) ||
             (opt_log_interval <= iVar10)) {
            hashmeter(thr_id,hashes_done);
            hashes_done = 0;
            copy_time(&tv_lastupdate,&getwork_start);
          }
          if (mythr->work_restart != false) {
            if (local_858 == 0) {
              rgtp.tv_sec = local_858;
              rgtp.tv_nsec = mythr->device_thread * 250000000;
              nanosleep((timespec *)&rgtp,(timespec *)0x0);
            }
            goto LAB_00028f42;
          }
          if ((mythr->pause != false) ||
             (dVar15 = dev->deven, dVar16 = dVar15, dVar15 != DEV_ENABLED)) {
            dVar16 = DEV_ENABLED;
            mt_disable(mythr,thr_id,drv);
            dVar15 = DEV_ENABLED;
          }
        }
        iVar6 = *(int *)((int)&dev->max_hashes + 4);
        if (opt_scantime < iVar7) goto LAB_00028f42;
        bVar17 = iVar6 == 0;
        if (iVar6 == 0) {
          bVar17 = (uint)dev->max_hashes < 0xfffffffe;
        }
        if ((!bVar17) || (_Var3 = stale_work(local_84c,false), _Var3)) goto LAB_00028f42;
        goto LAB_00028ff6;
      }
      if ((use_syslog != false) || ((opt_log_output != false || (2 < opt_log_level)))) {
        snprintf((char *)&rgtp,0x800,"%s %d failure, disabling!",drv->name,dev->device_id);
        _applog(3,(char *)&rgtp,false);
      }
      dev->deven = DEV_DISABLED;
      dev_error(dev,REASON_THREAD_ZERO_HASH);
      dev->shutdown = true;
LAB_00028f42:
      _free_work(&local_84c,"cgminer.c","hash_sole_work",0x23fe);
    } while (dev->shutdown == false);
  }
  dev->deven = DEV_DISABLED;
  return;
}

