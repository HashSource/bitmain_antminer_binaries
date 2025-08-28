
/* WARNING: Unknown calling convention */

void * watchpool_thread(void *userdata)

{
  stratum_share *psVar1;
  stratum_share *__ptr;
  stratum_share *psVar2;
  stratum_share *psVar3;
  _Bool _Var4;
  uint uVar5;
  pool *ppVar6;
  int iVar7;
  time_t tVar8;
  stratum_share *psVar9;
  list_head *plVar10;
  stratum_share *psVar11;
  UT_hash_handle *pUVar12;
  char *func;
  list_head *plVar13;
  char *func_00;
  char *func_01;
  void *pvVar14;
  UT_hash_bucket *pUVar15;
  UT_hash_handle *pUVar16;
  char *func_02;
  int line;
  list_head *plVar17;
  int line_00;
  int line_01;
  pool *ppVar18;
  int line_02;
  int iVar19;
  list_head *plVar20;
  char *pcVar21;
  int iVar22;
  uint uVar23;
  stratum_share *psVar24;
  UT_hash_table *pUVar25;
  bool bVar26;
  double dVar27;
  int local_858;
  cgtimer_t cgt;
  timeval now;
  timeval now_1;
  char tmp42 [2048];
  
  local_858 = 0;
  pthread_setcanceltype(1,(int *)0x0);
  RenameThread("Watchpool");
  set_lowprio();
  cgtimer_time(&cgt);
  do {
    local_858 = local_858 + 1;
    cgtime(&now);
    if (0x78 < local_858) {
      local_858 = 0;
    }
    if (0 < total_pools) {
      iVar22 = 0;
      do {
        ppVar6 = pools[iVar22];
        if ((opt_benchmark == false) && (opt_benchfile == (char *)0x0)) {
          cgtime(&now_1);
          iVar7 = pthread_mutex_lock((pthread_mutex_t *)&ppVar6->pool_lock);
          if (iVar7 != 0) {
            _mutex_lock((pthread_mutex_t *)"reap_curl",(char *)0x271d,func,line);
          }
          plVar17 = (ppVar6->curlring).next;
          if (&ppVar6->curlring == plVar17) {
            iVar7 = 0;
LAB_000262e8:
            iVar19 = pthread_mutex_unlock((pthread_mutex_t *)&ppVar6->pool_lock);
            if (iVar19 != 0) {
              _mutex_unlock_noyield((pthread_mutex_t *)"reap_curl",(char *)0x272f,func_00,line_00);
            }
            (*selective_yield)();
            if (((iVar7 != 0) && (opt_debug != false)) &&
               ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
              pcVar21 = "";
              if (iVar7 != 1) {
                pcVar21 = "s";
              }
              snprintf(tmp42,0x800,"Reaped %d curl%s from pool %d",iVar7,pcVar21,ppVar6->pool_no);
              _applog(7,tmp42,false);
            }
          }
          else {
            iVar19 = ppVar6->curls;
            if (1 < iVar19) {
              iVar7 = 0;
              plVar10 = plVar17->next;
              do {
                plVar20 = plVar10;
                if (300 < now_1.tv_sec - (int)plVar17[1].next) {
                  plVar13 = plVar17->prev;
                  plVar10 = plVar17->next;
                  iVar7 = iVar7 + 1;
                  ppVar6->curls = iVar19 + -1;
                  plVar10->prev = plVar13;
                  plVar13->next = plVar10;
                  plVar17->prev = (list_head *)0x0;
                  plVar17->next = (list_head *)0x0;
                  free(&plVar17[-1].prev);
                }
                if (&ppVar6->curlring == plVar20) goto LAB_000262e8;
                iVar19 = ppVar6->curls;
                plVar10 = plVar20->next;
                plVar17 = plVar20;
              } while (1 < iVar19);
            }
          }
          tVar8 = time((time_t *)0x0);
          iVar7 = pthread_mutex_lock((pthread_mutex_t *)&sshare_lock);
          if (iVar7 != 0) {
            _mutex_lock((pthread_mutex_t *)"prune_stratum_shares",(char *)0x2741,func_01,line_01);
          }
          psVar24 = stratum_shares;
          if (stratum_shares != (stratum_share *)0x0) {
            psVar24 = (stratum_share *)0x0;
            ppVar18 = stratum_shares->work->pool;
            psVar11 = (stratum_share *)(stratum_shares->hh).next;
            __ptr = stratum_shares;
            psVar2 = stratum_shares;
            while( true ) {
              psVar1 = psVar11;
              stratum_shares = psVar2;
              if ((ppVar6 == ppVar18) && (__ptr->sshare_time + 0x78 < tVar8)) {
                pvVar14 = (__ptr->hh).prev;
                psVar11 = (stratum_share *)(__ptr->hh).next;
                if ((pvVar14 == (void *)0x0) && (psVar11 == (stratum_share *)0x0)) {
                  free(((psVar2->hh).tbl)->buckets);
                  free((psVar2->hh).tbl);
                  stratum_shares = psVar11;
                }
                else {
                  pUVar25 = (psVar2->hh).tbl;
                  iVar7 = pUVar25->hho;
                  psVar9 = (stratum_share *)((int)pUVar25->tail - iVar7);
                  bVar26 = __ptr == psVar9;
                  if (bVar26) {
                    psVar9 = (stratum_share *)((int)pvVar14 + iVar7);
                  }
                  if (bVar26) {
                    pUVar25->tail = &psVar9->hh;
                  }
                  psVar9 = psVar11;
                  psVar3 = psVar11;
                  if (pvVar14 != (void *)0x0) {
                    *(stratum_share **)((int)pvVar14 + iVar7 + 8) = psVar11;
                    psVar11 = (stratum_share *)(__ptr->hh).next;
                    psVar9 = psVar2;
                    psVar3 = stratum_shares;
                  }
                  stratum_shares = psVar3;
                  pUVar25 = (psVar9->hh).tbl;
                  if (psVar11 != (stratum_share *)0x0) {
                    *(void **)((int)&(psVar11->hh).prev + pUVar25->hho) = pvVar14;
                  }
                  pUVar15 = pUVar25->buckets;
                  uVar5 = pUVar25->num_buckets - 1 & (__ptr->hh).hashv;
                  pUVar12 = (__ptr->hh).hh_next;
                  if (__ptr == (stratum_share *)pUVar15[uVar5].hh_head) {
                    pUVar15[uVar5].hh_head = pUVar12;
                  }
                  pUVar16 = (__ptr->hh).hh_prev;
                  pUVar15[uVar5].count = pUVar15[uVar5].count - 1;
                  if (pUVar16 != (UT_hash_handle *)0x0) {
                    pUVar16->hh_next = pUVar12;
                    pUVar12 = (__ptr->hh).hh_next;
                  }
                  if (pUVar12 != (UT_hash_handle *)0x0) {
                    pUVar12->hh_prev = pUVar16;
                  }
                  pUVar25->num_items = pUVar25->num_items - 1;
                }
                _free_work(&__ptr->work,"cgminer.c","prune_stratum_shares",0x2748);
                psVar24 = (stratum_share *)((int)&(psVar24->hh).tbl + 1);
                free(__ptr);
              }
              if (psVar1 == (stratum_share *)0x0) break;
              ppVar18 = psVar1->work->pool;
              psVar11 = (stratum_share *)(psVar1->hh).next;
              __ptr = psVar1;
              psVar2 = stratum_shares;
            }
          }
          iVar7 = pthread_mutex_unlock((pthread_mutex_t *)&sshare_lock);
          if (iVar7 != 0) {
            _mutex_unlock_noyield
                      ((pthread_mutex_t *)"prune_stratum_shares",(char *)0x274e,func_02,line_02);
          }
          (*selective_yield)();
          if (psVar24 != (stratum_share *)0x0) {
            if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
              snprintf(tmp42,0x800,"Lost %d shares due to no stratum share response from pool %d",
                       psVar24,ppVar6->pool_no);
              _applog(4,tmp42,false);
            }
            ppVar6->stale_shares = (int)&(psVar24->hh).tbl + ppVar6->stale_shares;
            bVar26 = CARRY4((uint)total_stale,(uint)psVar24);
            total_stale._0_4_ = (int)&(psVar24->hh).tbl + (uint)total_stale;
            total_stale._4_4_ = total_stale._4_4_ + ((int)psVar24 >> 0x1f) + (uint)bVar26;
          }
        }
        if (local_858 == 0x78) {
          uVar5 = ppVar6->last_shares;
          uVar23 = (uint)ppVar6->diff1;
          dVar27 = (double)__aeabi_l2d(uVar23 - uVar5,
                                       (*(int *)((int)&ppVar6->diff1 + 4) - ((int)uVar5 >> 0x1f)) -
                                       (uint)(uVar23 < uVar5));
          ppVar6->last_shares = uVar23;
          dVar27 = (ppVar6->utility + dVar27 * 0.63) / 1.63;
          ppVar6->utility = dVar27;
          ppVar6->shares = (int)(longlong)dVar27;
        }
        if ((ppVar6->enabled != POOL_DISABLED) && (ppVar6->testing == false)) {
          _Var4 = pool_active(ppVar6,true);
          if (_Var4) {
            _Var4 = pool_tclear(ppVar6,&ppVar6->idle);
            if (_Var4) {
              pool_resus(ppVar6);
            }
          }
          else {
            cgtime(&ppVar6->tv_idle);
          }
          if (((ppVar6->idle == false) && (pool_strategy == POOL_FAILOVER)) &&
             ((iVar19 = ppVar6->prio, iVar7 = cp_prio(), iVar19 < iVar7 &&
              (opt_pool_fallback < now.tv_sec - (ppVar6->tv_idle).tv_sec)))) {
            if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
              snprintf(tmp42,0x800,"Pool %d %s stable for >%d seconds",ppVar6->pool_no,
                       ppVar6->rpc_url,opt_pool_fallback);
              _applog(4,tmp42,false);
            }
            switch_pools((pool *)0x0);
          }
        }
        iVar22 = iVar22 + 1;
      } while (iVar22 < total_pools);
    }
    ppVar6 = current_pool();
    if (ppVar6->idle != false) {
      switch_pools((pool *)0x0);
    }
    if ((pool_strategy == POOL_ROTATE) &&
       (iVar22 = now.tv_sec - rotate_tv.tv_sec,
       iVar22 != opt_rotate_period * 0x3c &&
       iVar22 + opt_rotate_period * -0x3c < 0 == SBORROW4(iVar22,opt_rotate_period * 0x3c))) {
      cgtime(&rotate_tv);
      switch_pools((pool *)0x0);
    }
    cgsleep_ms_r(&cgt,5000);
    cgtimer_time(&cgt);
  } while( true );
}

