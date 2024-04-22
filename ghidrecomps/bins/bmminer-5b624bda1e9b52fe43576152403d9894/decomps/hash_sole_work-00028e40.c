
/* WARNING: Removing unreachable block (ram,0x00028ed4) */
/* WARNING: Unknown calling convention */

void hash_sole_work(thr_info *mythr)

{
  longlong lVar1;
  __time_t _Var2;
  __suseconds_t _Var3;
  _Bool _Var4;
  uint max_nonce;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  long cycle;
  int iVar10;
  int iVar11;
  cgpu_info *cgpu;
  cgpu_info *dev;
  device_drv *drv_00;
  device_drv *drv;
  timeval *b;
  timeval *ptVar12;
  int thr_id_00;
  int thr_id;
  _func__Bool_thr_info_ptr_work_ptr *p_Var13;
  timeval *b_00;
  pool *ppVar14;
  dev_enable dVar15;
  dev_enable dVar16;
  dev_enable dVar17;
  bool bVar18;
  double dVar19;
  double dVar20;
  int64_t iVar21;
  int in_stack_fffff768;
  undefined4 in_stack_fffff76c;
  uint local_86c;
  _Bool primary;
  work *work;
  timeval getwork_start;
  timeval tv_start;
  timeval tv_workstart;
  timeval tv_lastupdate;
  timespec rgtp;
  
  dev = mythr->cgpu;
  drv_00 = dev->drv;
  thr_id_00 = mythr->id;
  iVar9 = opt_log_interval / 5;
  if (iVar9 == 0) {
    iVar9 = 1;
  }
  if (mythr->device_thread == 0) {
    _primary = 1;
  }
  else {
    _primary = (uint)mythr->primary_thread;
  }
  local_86c = (*drv_00->can_limit_work)(mythr);
  cgtime(&getwork_start);
  cgtime(&tv_lastupdate);
  if (dev->shutdown == false) {
    iVar10 = iVar9 * 1000000;
    lVar1 = 0;
    dVar16 = DEV_ENABLED;
    dVar17 = DEV_ENABLED;
    do {
      work = get_work(mythr,thr_id_00);
      mythr->work_restart = false;
      dev->new_work = true;
      cgtime(&tv_workstart);
      p_Var13 = drv_00->prepare_work;
      work->nonce = 0;
      *(undefined4 *)&dev->max_hashes = 0;
      *(undefined4 *)((int)&dev->max_hashes + 4) = 0;
      _Var4 = (*p_Var13)(mythr,work);
      if (!_Var4) {
        if (((*DAT_0002921c != '\0') || (*DAT_00029220 != '\0')) || (2 < *DAT_00029224)) {
          snprintf((char *)&rgtp,0x800,DAT_00029228,thr_id_00);
          _applog(3,(char *)&rgtp,false);
        }
        break;
      }
      dVar20 = drv_00->max_diff;
      dVar19 = work->work_difficulty;
      if (dVar20 != dVar19 && dVar20 < dVar19 == (NAN(dVar20) || NAN(dVar19))) {
        dVar20 = dVar19;
      }
      if ((int)((uint)(dVar20 < drv_00->min_diff) << 0x1f) < 0) {
        dVar20 = drv_00->min_diff;
      }
      b = &(dev->cgminer_stats).getwork_wait_max;
      b_00 = &(dev->cgminer_stats).getwork_wait_min;
      work->device_diff = dVar20;
LAB_00028ff6:
      cgtime(&tv_start);
      subtime(&tv_start,&getwork_start);
      addtime(&getwork_start,&(dev->cgminer_stats).getwork_wait);
      _Var4 = time_more(&getwork_start,b);
      if (_Var4) {
        copy_time(b,&getwork_start);
        _Var4 = time_less(&getwork_start,b_00);
        if (_Var4) goto LAB_00029188;
      }
      else {
        _Var4 = time_less(&getwork_start,b_00);
        if (_Var4) {
LAB_00029188:
          copy_time(b_00,&getwork_start);
        }
      }
      ppVar14 = work->pool;
      (dev->cgminer_stats).getwork_calls = (dev->cgminer_stats).getwork_calls + 1;
      ptVar12 = &(ppVar14->cgminer_stats).getwork_wait_max;
      addtime(&getwork_start,&(ppVar14->cgminer_stats).getwork_wait);
      _Var4 = time_more(&getwork_start,ptVar12);
      if (_Var4) {
        copy_time(ptVar12,&getwork_start);
      }
      ptVar12 = &(ppVar14->cgminer_stats).getwork_wait_min;
      _Var4 = time_less(&getwork_start,ptVar12);
      if (_Var4) {
        copy_time(ptVar12,&getwork_start);
      }
      (ppVar14->cgminer_stats).getwork_calls = (ppVar14->cgminer_stats).getwork_calls + 1;
      cgtime(&work->tv_work_start);
      pthread_setcancelstate(1,(int *)0x0);
      thread_reportin(mythr);
      iVar21 = (*drv_00->scanhash)(mythr,work,CONCAT44(in_stack_fffff76c,in_stack_fffff768));
      iVar8 = (int)((ulonglong)iVar21 >> 0x20);
      uVar5 = (uint)iVar21;
      thread_reportout(mythr);
      pthread_setcancelstate(0,(int *)0x0);
      pthread_testcancel();
      cgtime(&getwork_start);
      _Var3 = getwork_start.tv_usec;
      _Var2 = getwork_start.tv_sec;
      if (iVar8 != -1 || uVar5 != 0xffffffff) {
        iVar7 = *(int *)((int)&dev->max_hashes + 4);
        lVar1 = iVar21 + lVar1;
        bVar18 = *(uint *)&dev->max_hashes < uVar5;
        if ((int)((iVar7 - iVar8) - (uint)bVar18) < 0 !=
            (SBORROW4(iVar7,iVar8) != SBORROW4(iVar7 - iVar8,(uint)bVar18))) {
          dev->max_hashes = iVar21;
        }
        iVar8 = getwork_start.tv_sec - tv_start.tv_sec;
        iVar7 = getwork_start.tv_usec - tv_start.tv_usec;
        if (iVar7 < 0) {
          iVar8 = iVar8 + -1;
          iVar7 = iVar7 + 1000000;
        }
        dVar17 = dVar17 + iVar8;
        dVar15 = dVar16 + iVar7;
        dVar16 = dVar15;
        if (1000000 < (int)dVar15) {
          dVar16 = dVar15 + 0xfff0c000;
          dVar17 = dVar17 + DEV_DISABLED;
        }
        if (1000000 < (int)dVar15) {
          dVar16 = dVar16 + 0xfffffdc0;
        }
        iVar8 = getwork_start.tv_sec - tv_workstart.tv_sec;
        if (getwork_start.tv_usec - tv_workstart.tv_usec < 0) {
          iVar8 = iVar8 + -1;
        }
        if ((int)dVar17 < iVar9) {
          if (local_86c != 0xffffffff) {
            iVar7 = dVar16 + 0x7ff;
            if (-1 < (int)(dVar16 + 0x400)) {
              iVar7 = dVar16 + 0x400;
            }
            iVar7 = __aeabi_idiv(1000000,iVar7 >> 10);
            iVar7 = (iVar7 + 0x10) * iVar9;
            uVar5 = __aeabi_uidiv(0xfffffc00,iVar7);
            if (uVar5 < local_86c) {
              local_86c = 0xffffffff;
            }
            else {
              local_86c = local_86c * iVar7 >> 10;
            }
            goto LAB_0002913c;
          }
        }
        else {
          if (iVar9 < (int)dVar17) {
            local_86c = __aeabi_uidiv(iVar9 * local_86c,dVar17);
          }
          else if (100000 < (int)dVar16) {
            uVar6 = __aeabi_idiv(iVar10 + dVar16,(int)(iVar10 + 0x3ffU & iVar10 >> 0x20) >> 10);
            local_86c = __aeabi_uidiv(local_86c << 10,uVar6);
          }
LAB_0002913c:
          iVar7 = _Var3 - tv_lastupdate.tv_usec;
          bVar18 = iVar7 < 0;
          if (bVar18) {
            iVar7 = iVar7 + 0xf4000;
          }
          iVar11 = _Var2 - tv_lastupdate.tv_sec;
          if (bVar18) {
            iVar11 = iVar11 + -1;
            iVar7 = iVar7 + 0x240;
          }
          if (((lVar1 != 0) && ((0 < iVar11 || (200000 < iVar7)))) || (opt_log_interval <= iVar11))
          {
            hashmeter(thr_id_00,CONCAT44(in_stack_fffff76c,in_stack_fffff768));
            lVar1 = 0;
            copy_time(&tv_lastupdate,&getwork_start);
          }
          if (mythr->work_restart != false) {
            if (_primary == 0) {
              rgtp.tv_sec = _primary;
              rgtp.tv_nsec = mythr->device_thread * 250000000;
              nanosleep((timespec *)&rgtp,(timespec *)0x0);
            }
            goto LAB_00028f42;
          }
          if ((mythr->pause != false) ||
             (dVar16 = dev->deven, dVar17 = dVar16, dVar16 != DEV_ENABLED)) {
            dVar17 = DEV_ENABLED;
            mt_disable(mythr,thr_id_00,drv_00);
            dVar16 = DEV_ENABLED;
          }
        }
        iVar7 = *(int *)((int)&dev->max_hashes + 4);
        if (opt_scantime < iVar8) goto LAB_00028f42;
        bVar18 = iVar7 == 0;
        if (iVar7 == 0) {
          bVar18 = *(uint *)&dev->max_hashes < 0xfffffffe;
        }
        if ((!bVar18) || (_Var4 = stale_work(work,false), _Var4)) goto LAB_00028f42;
        goto LAB_00028ff6;
      }
      if ((use_syslog != false) || ((opt_log_output != false || (2 < opt_log_level)))) {
        in_stack_fffff768 = dev->device_id;
        snprintf((char *)&rgtp,0x800,DAT_0002934c,drv_00->name);
        _applog(3,(char *)&rgtp,false);
      }
      dev->deven = DEV_DISABLED;
      dev_error(dev,REASON_THREAD_ZERO_HASH);
      dev->shutdown = true;
LAB_00028f42:
      _free_work(&work,DAT_00029214,DAT_00029218,0x23fe);
    } while (dev->shutdown == false);
  }
  dev->deven = DEV_DISABLED;
  return;
}

