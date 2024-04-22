
/* WARNING: Unknown calling convention */

void * watchpool_thread(void *userdata)

{
  pool *ppVar1;
  double dVar2;
  double dVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  pool *ppVar7;
  _Bool _Var8;
  uint uVar9;
  pool *ppVar10;
  int iVar11;
  time_t current_time;
  int **ppiVar12;
  JE **func;
  int *piVar13;
  _Bool *func_00;
  int iVar14;
  pthread_mutex_t *__mutex;
  pthread_mutex_t *line;
  pool *line_00;
  int **ppiVar15;
  void **ppvVar16;
  pool *pool;
  int iVar17;
  curl_ent *iter;
  undefined4 uVar18;
  void *pvVar19;
  stratum_share *tmpshare;
  void *__ptr;
  int iVar20;
  uint uVar21;
  void *pvVar22;
  pool *ppVar23;
  void *pvVar24;
  stratum_share *sshare;
  UT_hash_handle *_hd_hh_del;
  int iVar25;
  curl_ent *ent;
  bool bVar26;
  double dVar27;
  int local_858;
  cgtimer_t cgt;
  timeval now;
  timeval now_1;
  char tmp42 [2048];
  
  local_858 = 0;
  pthread_setcanceltype(1,(int *)0x0);
  RenameThread(DAT_000262d0);
  set_lowprio();
  piVar6 = DAT_000262e0;
  iVar5 = DAT_000262dc;
  piVar4 = DAT_000262d4;
  dVar3 = DAT_000262c8;
  dVar2 = DAT_000262c0;
  cgtimer_time(&cgt);
  do {
    local_858 = local_858 + 1;
    cgtime(&now);
    if (0x78 < local_858) {
      local_858 = 0;
    }
    if (0 < *piVar4) {
      iVar20 = 0;
      do {
        ppVar10 = *(pool **)(*piVar6 + iVar20 * 4);
        if ((*(char *)(iVar5 + 0x74d) == '\0') && (func = &jedata, opt_benchfile == (char *)0x0)) {
          __mutex = &ppVar10->pool_lock;
          line = __mutex;
          cgtime(&now_1);
          iVar11 = pthread_mutex_lock((pthread_mutex_t *)__mutex);
          func_00 = (_Bool *)func;
          if (iVar11 != 0) {
            _mutex_lock(DAT_000265a8,(char *)0x271d,(char *)func,(int)line);
            func_00 = (_Bool *)func;
          }
          line_00 = (pool *)(ppVar10->curlring).next;
          if ((pool *)&ppVar10->curlring == line_00) {
            ppVar23 = (pool *)0x0;
LAB_000262e8:
            iVar11 = pthread_mutex_unlock((pthread_mutex_t *)__mutex);
            if (iVar11 != 0) {
              _mutex_unlock_noyield(DAT_000265a8,(char *)0x272f,func_00,(int)line_00);
            }
            line_00 = (pool *)selective_yield;
            (*selective_yield)();
            if (((ppVar23 != (pool *)0x0) &&
                (line_00 = (pool *)(uint)opt_debug, (pool *)(uint)opt_debug != (pool *)0x0)) &&
               ((func_00 = &use_syslog, use_syslog != false ||
                ((opt_log_output != false || (line_00 = (pool *)opt_log_level, 6 < opt_log_level))))
               )) {
              uVar18 = DAT_0002658c;
              if (ppVar23 != (pool *)0x1) {
                uVar18 = DAT_00026588;
              }
              snprintf(tmp42,0x800,DAT_00026590,ppVar23,uVar18,ppVar10->pool_no);
              func_00 = (_Bool *)0x0;
              _applog(7,tmp42,false);
              line_00 = ppVar23;
            }
          }
          else {
            iVar11 = ppVar10->curls;
            if (1 < iVar11) {
              ppVar23 = (pool *)0x0;
              ppVar7 = (pool *)line_00->pool_no;
              ppVar1 = line_00;
              do {
                func_00 = (_Bool *)ppVar7;
                if (300 < now_1.tv_sec - *(int *)&ppVar1->accepted) {
                  piVar13 = (int *)ppVar1->prio;
                  iVar17 = ppVar1->pool_no;
                  ppVar23 = (pool *)((int)&ppVar23->pool_no + 1);
                  ppVar10->curls = iVar11 + -1;
                  *(int **)(iVar17 + 4) = piVar13;
                  *piVar13 = iVar17;
                  ppVar1->prio = 0;
                  ppVar1->pool_no = 0;
                  free(&ppVar1[-1].field_0x734);
                }
                line_00 = (pool *)0x0;
                if (&ppVar10->curlring == (list_head *)func_00) goto LAB_000262e8;
                iVar11 = ppVar10->curls;
                ppVar7 = (pool *)*(int *)func_00;
                ppVar1 = (pool *)func_00;
              } while (1 < iVar11);
            }
          }
          ppVar23 = (pool *)time((time_t *)0x0);
          iVar11 = pthread_mutex_lock(DAT_00026594);
          if (iVar11 != 0) {
            _mutex_lock((pthread_mutex_t *)DAT_0002659c,(char *)0x2741,func_00,(int)line_00);
          }
          pvVar24 = *(void **)(iVar5 + 0x480);
          if (pvVar24 != (void *)0x0) {
            pvVar19 = *(void **)((int)pvVar24 + 8);
            line_00 = *(pool **)(*(int *)((int)pvVar24 + 0x24) + 0x104);
            pvVar22 = (void *)0x0;
            __ptr = pvVar24;
            if (ppVar10 == line_00) goto LAB_000263aa;
LAB_00026396:
            pvVar24 = pvVar22;
            __ptr = pvVar19;
            if (pvVar19 != (void *)0x0) {
              while( true ) {
                pvVar19 = *(void **)((int)__ptr + 8);
                line_00 = *(pool **)(*(int *)((int)__ptr + 0x24) + 0x104);
                pvVar22 = pvVar24;
                if (ppVar10 != line_00) break;
LAB_000263aa:
                line_00 = (pool *)(*(int *)((int)__ptr + 0x2c) + 0x78);
                func_00 = (_Bool *)ppVar23;
                if ((int)ppVar23 <= (int)line_00) break;
                iVar11 = *(int *)((int)__ptr + 4);
                ppiVar12 = *(int ***)((int)__ptr + 8);
                if ((iVar11 == 0) && (ppiVar12 == (int **)0x0)) {
                  ppvVar16 = *(void ***)(iVar5 + 0x480);
                    /* WARNING: Load size is inaccurate */
                  free(**ppvVar16);
                  free(*ppvVar16);
                  *(undefined4 *)(iVar5 + 0x480) = 0;
                }
                else {
                  ppiVar15 = *(int ***)(iVar5 + 0x480);
                  piVar13 = *ppiVar15;
                  iVar17 = piVar13[5];
                  pvVar24 = (void *)(piVar13[4] - iVar17);
                  bVar26 = __ptr == pvVar24;
                  if (bVar26) {
                    pvVar24 = (void *)(iVar11 + iVar17);
                  }
                  if (bVar26) {
                    piVar13[4] = (int)pvVar24;
                  }
                  if (iVar11 == 0) {
                    *(int ***)(iVar5 + 0x480) = ppiVar12;
                    ppiVar15 = ppiVar12;
                  }
                  else {
                    *(int ***)(iVar17 + iVar11 + 8) = ppiVar12;
                    ppiVar12 = *(int ***)((int)__ptr + 8);
                  }
                  piVar13 = *ppiVar15;
                  if (ppiVar12 != (int **)0x0) {
                    *(int *)((int)ppiVar12 + piVar13[5] + 4) = iVar11;
                  }
                  iVar14 = *piVar13;
                  uVar9 = piVar13[1] - 1U & *(uint *)((int)__ptr + 0x1c);
                  iVar25 = iVar14 + uVar9 * 0xc;
                  iVar11 = *(int *)(iVar25 + 4);
                  iVar17 = *(int *)((int)__ptr + 0x10);
                  if (__ptr == *(void **)(iVar14 + uVar9 * 0xc)) {
                    *(int *)(iVar14 + uVar9 * 0xc) = iVar17;
                  }
                  iVar14 = *(int *)((int)__ptr + 0xc);
                  *(int *)(iVar25 + 4) = iVar11 + -1;
                  if (iVar14 != 0) {
                    *(int *)(iVar14 + 0x10) = iVar17;
                    iVar17 = *(int *)((int)__ptr + 0x10);
                  }
                  if (iVar17 != 0) {
                    *(int *)(iVar17 + 0xc) = iVar14;
                  }
                  piVar13[3] = piVar13[3] + -1;
                }
                line_00 = (pool *)0x2748;
                func_00 = (_Bool *)DAT_0002659c;
                _free_work((work **)((int)__ptr + 0x24),DAT_00026598,(char *)DAT_0002659c,0x2748);
                pvVar24 = (void *)((int)pvVar22 + 1);
                free(__ptr);
                __ptr = pvVar19;
                if (pvVar19 == (void *)0x0) goto LAB_00026466;
              }
              goto LAB_00026396;
            }
          }
LAB_00026466:
          iVar11 = pthread_mutex_unlock(DAT_00026594);
          if (iVar11 != 0) {
            _mutex_unlock_noyield
                      ((pthread_mutex_t *)DAT_0002659c,(char *)0x274e,func_00,(int)line_00);
          }
          (*selective_yield)();
          if (pvVar24 != (void *)0x0) {
            if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
              snprintf(tmp42,0x800,DAT_000265a0,pvVar24,ppVar10->pool_no);
              _applog(4,tmp42,false);
            }
            ppVar10->stale_shares = ppVar10->stale_shares + (int)pvVar24;
            bVar26 = CARRY4((uint)total_stale,(uint)pvVar24);
            total_stale._0_4_ = (uint)total_stale + (int)pvVar24;
            total_stale._4_4_ = total_stale._4_4_ + ((int)pvVar24 >> 0x1f) + (uint)bVar26;
          }
        }
        if (local_858 == 0x78) {
          uVar9 = ppVar10->last_shares;
          uVar21 = *(uint *)&ppVar10->diff1;
          dVar27 = (double)__aeabi_l2d(uVar21 - uVar9,
                                       (*(int *)((int)&ppVar10->diff1 + 4) - ((int)uVar9 >> 0x1f)) -
                                       (uint)(uVar21 < uVar9));
          ppVar10->last_shares = uVar21;
          dVar27 = (ppVar10->utility + dVar27 * dVar2) / dVar3;
          ppVar10->utility = dVar27;
          ppVar10->shares = (int)(longlong)dVar27;
        }
        if ((ppVar10->enabled != POOL_DISABLED) && (ppVar10->testing == false)) {
          _Var8 = pool_active(ppVar10,true);
          if (_Var8) {
            _Var8 = pool_tclear(ppVar10,&ppVar10->idle);
            if (_Var8) {
              pool_resus(ppVar10);
            }
          }
          else {
            cgtime(&ppVar10->tv_idle);
          }
          if (((ppVar10->idle == false) && (*(int *)(iVar5 + 0x41c) == 0)) &&
             ((iVar17 = ppVar10->prio, iVar11 = cp_prio(), iVar17 < iVar11 &&
              (opt_pool_fallback < now.tv_sec - (ppVar10->tv_idle).tv_sec)))) {
            if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
              snprintf(tmp42,0x800,DAT_000262d8,ppVar10->pool_no,ppVar10->rpc_url,opt_pool_fallback)
              ;
              _applog(4,tmp42,false);
            }
            switch_pools((pool *)0x0);
          }
        }
        iVar20 = iVar20 + 1;
      } while (iVar20 < *piVar4);
    }
    ppVar10 = current_pool();
    if (ppVar10->idle == false) {
      iVar20 = *(int *)(iVar5 + 0x41c);
    }
    else {
      switch_pools((pool *)0x0);
      iVar20 = *(int *)(iVar5 + 0x41c);
    }
    if ((iVar20 == 2) &&
       (iVar20 = now.tv_sec - rotate_tv.tv_sec,
       iVar20 != opt_rotate_period * 0x3c &&
       iVar20 + opt_rotate_period * -0x3c < 0 == SBORROW4(iVar20,opt_rotate_period * 0x3c))) {
      cgtime(DAT_000265a4);
      switch_pools((pool *)0x0);
    }
    cgsleep_ms_r(&cgt,5000);
    cgtimer_time(&cgt);
  } while( true );
}

