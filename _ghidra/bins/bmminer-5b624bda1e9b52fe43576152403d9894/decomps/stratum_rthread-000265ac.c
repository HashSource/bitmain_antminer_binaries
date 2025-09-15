
/* WARNING: Unknown calling convention */

void * stratum_rthread(void *userdata)

{
  stratum_share *psVar1;
  stratum_share *psVar2;
  char cVar3;
  _Bool _Var4;
  pthread_t __th;
  int iVar5;
  char *pcVar6;
  json_t *json;
  json_t *json_00;
  json_t *json_01;
  time_t tVar7;
  thr_info *ptVar8;
  char *pcVar9;
  pool *ppVar10;
  stratum_share *psVar11;
  uint uVar12;
  work *work;
  void *pvVar13;
  UT_hash_handle *pUVar14;
  json_type jVar15;
  char *func;
  char *func_00;
  char *func_01;
  char *func_02;
  char *func_03;
  char *func_04;
  char *func_05;
  uint uVar16;
  char *func_06;
  char *func_07;
  char *func_08;
  UT_hash_handle *pUVar17;
  char *func_09;
  char *func_10;
  char *func_11;
  char *func_12;
  char *func_13;
  char *func_14;
  char *func_15;
  char *func_16;
  undefined4 uVar18;
  char *func_17;
  char *func_18;
  char *reason_str;
  int iVar19;
  int line;
  int line_00;
  int line_01;
  int line_02;
  int line_03;
  int line_04;
  int line_05;
  int line_06;
  int line_07;
  int line_08;
  size_t sVar20;
  stratum_share *psVar21;
  int line_09;
  int line_10;
  int line_11;
  int line_12;
  int line_13;
  int line_14;
  int line_15;
  int line_16;
  undefined4 uVar22;
  int line_17;
  int line_18;
  uint uVar23;
  stratum_share *__ptr;
  UT_hash_bucket *pUVar24;
  UT_hash_table *pUVar25;
  pool *ppVar26;
  cgpu_info *cgpu;
  cgpu_info *pcVar27;
  bool bVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  json_int_t jVar32;
  json_t *local_a80;
  char *local_a74;
  work *local_a6c;
  int id;
  timeval timeout;
  char threadname [16];
  char where [20];
  char reason [32];
  char disposition [36];
  char hashshow [64];
  fd_set rd;
  json_error_t err;
  char tmp42 [2048];
  
  __th = pthread_self();
  pthread_detach(__th);
                    /* WARNING: Load size is inaccurate */
  snprintf(threadname,0x10,"%d/RStratum",*userdata);
  RenameThread(threadname);
  do {
    while( true ) {
      if (*(char *)((int)userdata + 0x69) != '\0') {
        suspend_stratum((pool *)userdata);
        return (void *)0x0;
      }
      _Var4 = sock_full((pool *)userdata);
      if ((!_Var4) && (_Var4 = cnx_needed((pool *)userdata), !_Var4)) {
        suspend_stratum((pool *)userdata);
        clear_stratum_shares((pool *)userdata);
        clear_pool_work((pool *)userdata);
        while ((_Var4 = cnx_needed((pool *)userdata), !_Var4 &&
               ((*(int *)((int)userdata + 100) == 0 ||
                (((ppVar26 = current_pool(), (pool *)userdata != ppVar26 &&
                  (pool_strategy != POOL_LOADBALANCE)) && (pool_strategy != POOL_BALANCE))))))) {
          iVar5 = pthread_mutex_lock((pthread_mutex_t *)&lp_lock);
          if (iVar5 != 0) {
            _mutex_lock((pthread_mutex_t *)"wait_lpcurrent",(char *)0x2628,func,line);
          }
          pthread_cond_wait((pthread_cond_t *)&lp_cond,(pthread_mutex_t *)&lp_lock);
          iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&lp_lock);
          if (iVar5 != 0) {
            _mutex_unlock_noyield
                      ((pthread_mutex_t *)"wait_lpcurrent",(char *)0x262a,func_00,line_00);
          }
          (*selective_yield)();
        }
        while (_Var4 = restart_stratum((pool *)userdata), !_Var4) {
          pool_died((pool *)userdata);
          if (*(char *)((int)userdata + 0x69) != '\0') {
            return (void *)0x0;
          }
          cgsleep_ms(5000);
        }
      }
      pcVar6 = hashshow + 0x3c;
      do {
        pcVar6 = pcVar6 + 4;
        pcVar6[0] = '\0';
        pcVar6[1] = '\0';
        pcVar6[2] = '\0';
        pcVar6[3] = '\0';
      } while ((__fd_mask *)pcVar6 != rd.fds_bits + 0x1f);
      iVar19 = *(int *)((int)userdata + 0x24c);
      timeout.tv_usec = 0;
      timeout.tv_sec = 0x5a;
      iVar5 = iVar19;
      if (iVar19 < 0) {
        iVar5 = iVar19 + 0x1f;
      }
      ((fd_set *)&rd)->fds_bits[iVar5 >> 5] =
           ((fd_set *)&rd)->fds_bits[iVar5 >> 5] | 1 << (iVar19 % 0x20 & 0xffU);
      _Var4 = sock_full((pool *)userdata);
      if ((!_Var4) &&
         (iVar5 = select(*(int *)((int)userdata + 0x24c) + 1,(fd_set *)&rd,(fd_set *)0x0,
                         (fd_set *)0x0,(timeval *)&timeout), iVar5 < 1)) break;
      pcVar6 = recv_line((pool *)userdata);
      if (pcVar6 == (char *)0x0) goto LAB_0002673a;
      stratum_resumed((pool *)userdata);
      _Var4 = parse_method((pool *)userdata,pcVar6);
      if (_Var4) {
LAB_0002667c:
        if (*(char *)((int)userdata + 0x2a8) != '\0') {
          local_a6c = make_work();
          *(undefined1 *)((int)userdata + 0x2a8) = 0;
          gen_stratum_work((pool *)userdata,local_a6c);
          local_a6c->longpoll = true;
          test_work_current(local_a6c);
          _free_work(&local_a6c,"cgminer.c","stratum_rthread",0x1d3b);
        }
      }
      else {
        json = json_loads(pcVar6,0,&err);
        if (json != (json_t *)0x0) {
          local_a80 = json_object_get(json,"result");
          json_00 = json_object_get(json,"error");
          json_01 = json_object_get(json,"id");
          if ((json_01 == (json_t *)0x0) || (json_01->type == JSON_NULL)) {
            if (json_00 == (json_t *)0x0) {
              pcVar9 = (char *)malloc(0x11);
              if (pcVar9 != (char *)0x0) {
                builtin_strncpy(pcVar9,"(unknown reason)",0x11);
              }
            }
            else {
              pcVar9 = json_dumps(json_00,3);
            }
            if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
              snprintf(tmp42,0x800,"JSON-RPC non method decode failed: %s",pcVar9);
              _applog(6,tmp42,false);
            }
            free(pcVar9);
LAB_00026f72:
            bVar28 = false;
            sVar20 = json->refcount;
          }
          else {
            jVar32 = json_integer_value(json_01);
            id = (int)jVar32;
            iVar5 = pthread_mutex_lock((pthread_mutex_t *)&sshare_lock);
            if (iVar5 != 0) {
              _mutex_lock((pthread_mutex_t *)"parse_stratum_response",(char *)0x1c0a,func_05,line_05
                         );
            }
            psVar1 = stratum_shares;
            uVar16 = (id & 0xffU) + 0x112410d + (id & 0xff000000U) +
                     ((uint)id >> 0x10 & 0xff) * 0x10000 + ((uint)id >> 8 & 0xff) * 0x100 ^ 0x7f76d;
            uVar12 = 0x9f49bac6 - uVar16 ^ uVar16 << 8;
            uVar23 = (-0x112410d - uVar16) - uVar12 ^ uVar12 >> 0xd;
            uVar16 = (uVar16 - uVar12) - uVar23 ^ uVar23 >> 0xc;
            uVar12 = (uVar12 - uVar23) - uVar16 ^ uVar16 << 0x10;
            uVar23 = (uVar23 - uVar16) - uVar12 ^ uVar12 >> 5;
            uVar16 = (uVar16 - uVar12) - uVar23 ^ uVar23 >> 3;
            uVar12 = (uVar12 - uVar23) - uVar16 ^ uVar16 << 10;
            uVar16 = (uVar23 - uVar16) - uVar12 ^ uVar12 >> 0xf;
            __ptr = stratum_shares;
            if (stratum_shares != (stratum_share *)0x0) {
              pUVar25 = (stratum_shares->hh).tbl;
              pUVar24 = pUVar25->buckets;
              __ptr = (stratum_share *)pUVar24[pUVar25->num_buckets - 1 & uVar16].hh_head;
              if (__ptr != (stratum_share *)0x0) {
                __ptr = (stratum_share *)((int)__ptr - pUVar25->hho);
              }
              for (; __ptr != (stratum_share *)0x0;
                  __ptr = (stratum_share *)((int)__ptr - pUVar25->hho)) {
                if (((uVar16 == (__ptr->hh).hashv) && ((__ptr->hh).keylen == 4)) &&
                   (iVar5 = memcmp((__ptr->hh).key,&id,4), iVar5 == 0)) {
                  pvVar13 = (__ptr->hh).prev;
                  psVar21 = (stratum_share *)(__ptr->hh).next;
                  if ((pvVar13 == (void *)0x0) && (psVar21 == (stratum_share *)0x0)) {
                    free(pUVar24);
                    free((psVar1->hh).tbl);
                    stratum_shares = psVar21;
                  }
                  else {
                    iVar5 = pUVar25->hho;
                    psVar11 = (stratum_share *)((int)pUVar25->tail - iVar5);
                    bVar28 = __ptr == psVar11;
                    if (bVar28) {
                      psVar11 = (stratum_share *)((int)pvVar13 + iVar5);
                    }
                    if (bVar28) {
                      pUVar25->tail = &psVar11->hh;
                    }
                    psVar11 = psVar21;
                    psVar2 = psVar21;
                    if (pvVar13 != (void *)0x0) {
                      *(stratum_share **)((int)pvVar13 + iVar5 + 8) = psVar21;
                      psVar21 = (stratum_share *)(__ptr->hh).next;
                      psVar11 = psVar1;
                      psVar2 = stratum_shares;
                    }
                    stratum_shares = psVar2;
                    pUVar25 = (psVar11->hh).tbl;
                    if (psVar21 != (stratum_share *)0x0) {
                      *(void **)((int)&(psVar21->hh).prev + pUVar25->hho) = pvVar13;
                    }
                    pUVar24 = pUVar25->buckets;
                    uVar16 = uVar16 & pUVar25->num_buckets - 1;
                    pUVar17 = (__ptr->hh).hh_next;
                    if (__ptr == (stratum_share *)pUVar24[uVar16].hh_head) {
                      pUVar24[uVar16].hh_head = pUVar17;
                    }
                    pUVar14 = (__ptr->hh).hh_prev;
                    pUVar24[uVar16].count = pUVar24[uVar16].count - 1;
                    if (pUVar14 != (UT_hash_handle *)0x0) {
                      pUVar14->hh_next = pUVar17;
                      pUVar17 = (__ptr->hh).hh_next;
                    }
                    if (pUVar17 != (UT_hash_handle *)0x0) {
                      pUVar17->hh_prev = pUVar14;
                    }
                    pUVar25->num_items = pUVar25->num_items - 1;
                  }
                  *(int *)((int)userdata + 0x2dc) = *(int *)((int)userdata + 0x2dc) + -1;
                  break;
                }
                __ptr = (stratum_share *)(__ptr->hh).hh_next;
                if (__ptr == (stratum_share *)0x0) break;
              }
            }
            iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&sshare_lock);
            if (iVar5 != 0) {
              _mutex_unlock_noyield
                        ((pthread_mutex_t *)"parse_stratum_response",(char *)0x1c12,func_06,line_06)
              ;
            }
            (*selective_yield)();
            if (__ptr == (stratum_share *)0x0) {
              if (local_a80 != (json_t *)0x0) {
                iVar5 = pthread_mutex_lock((pthread_mutex_t *)((int)userdata + 0xd4));
                if (iVar5 != 0) {
                  _mutex_lock((pthread_mutex_t *)"parse_stratum_response",(char *)0x1c1e,func_09,
                              line_09);
                }
                iVar5 = pthread_rwlock_rdlock((pthread_rwlock_t *)((int)userdata + 0xec));
                if (iVar5 != 0) {
                  _rd_lock((pthread_rwlock_t *)"parse_stratum_response",(char *)0x1c1e,func_10,
                           line_10);
                }
                iVar5 = pthread_mutex_unlock((pthread_mutex_t *)((int)userdata + 0xd4));
                if (iVar5 != 0) {
                  _mutex_unlock_noyield
                            ((pthread_mutex_t *)"parse_stratum_response",(char *)0x1c1e,func_11,
                             line_11);
                }
                dVar29 = *(double *)((int)userdata + 0x720);
                iVar5 = pthread_rwlock_unlock((pthread_rwlock_t *)((int)userdata + 0xec));
                if (iVar5 != 0) {
                  _rw_unlock((pthread_rwlock_t *)"parse_stratum_response",(char *)0x1c20,func_12,
                             line_12);
                }
                (*selective_yield)();
                if (local_a80->type == JSON_TRUE) {
                  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                    /* WARNING: Load size is inaccurate */
                    snprintf(tmp42,0x800,"Accepted untracked stratum share from pool %d",*userdata);
                    _applog(5,tmp42,false);
                  }
                  iVar5 = pthread_mutex_lock((pthread_mutex_t *)&stats_lock);
                  if (iVar5 != 0) {
                    _mutex_lock((pthread_mutex_t *)"parse_stratum_response",(char *)0x1c28,func_17,
                                line_17);
                  }
                  uVar16 = *(uint *)((int)userdata + 8);
                  total_diff_accepted = dVar29 + total_diff_accepted;
                  *(uint *)((int)userdata + 8) = uVar16 + 1;
                  *(uint *)((int)userdata + 0xc) =
                       *(int *)((int)userdata + 0xc) + (uint)(0xfffffffe < uVar16);
                  bVar28 = 0xfffffffe < (uint)total_accepted;
                  total_accepted._0_4_ = (uint)total_accepted + 1;
                  total_accepted._4_4_ = total_accepted._4_4_ + (uint)bVar28;
                  *(double *)((int)userdata + 0x48) = *(double *)((int)userdata + 0x48) + dVar29;
                  iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&stats_lock);
                  if (iVar5 != 0) {
                    _mutex_unlock_noyield
                              ((pthread_mutex_t *)"parse_stratum_response",(char *)0x1c2d,func_18,
                               line_18);
                  }
                }
                else {
                  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                    /* WARNING: Load size is inaccurate */
                    snprintf(tmp42,0x800,"Rejected untracked stratum share from pool %d",*userdata);
                    _applog(5,tmp42,false);
                  }
                  iVar5 = pthread_mutex_lock((pthread_mutex_t *)&stats_lock);
                  if (iVar5 != 0) {
                    _mutex_lock((pthread_mutex_t *)"parse_stratum_response",(char *)0x1c33,func_13,
                                line_13);
                  }
                  uVar16 = *(uint *)((int)userdata + 0x10);
                  total_diff_rejected = dVar29 + total_diff_rejected;
                  *(uint *)((int)userdata + 0x10) = uVar16 + 1;
                  *(uint *)((int)userdata + 0x14) =
                       *(int *)((int)userdata + 0x14) + (uint)(0xfffffffe < uVar16);
                  bVar28 = 0xfffffffe < (uint)total_rejected;
                  total_rejected._0_4_ = (uint)total_rejected + 1;
                  total_rejected._4_4_ = total_rejected._4_4_ + (uint)bVar28;
                  *(double *)((int)userdata + 0x50) = *(double *)((int)userdata + 0x50) + dVar29;
                  iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&stats_lock);
                  if (iVar5 != 0) {
                    _mutex_unlock_noyield
                              ((pthread_mutex_t *)"parse_stratum_response",(char *)0x1c38,func_14,
                               line_14);
                  }
                }
                (*selective_yield)();
              }
              goto LAB_00026f72;
            }
            work = __ptr->work;
            tVar7 = time((time_t *)0x0);
            iVar5 = tVar7 - __ptr->sshare_sent;
            if (((opt_debug != false) || (0 < iVar5)) &&
               ((use_syslog != false || ((opt_log_output != false || (5 < opt_log_level)))))) {
              snprintf(tmp42,0x800,"Pool %d stratum share result lag time %d seconds",
                       work->pool->pool_no,iVar5);
              _applog(6,tmp42,false);
            }
            uVar16 = *(uint *)(work->hash + 0x1c);
            iVar5 = 0;
            uVar16 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
                     uVar16 >> 0x18;
            tmp42[0] = (char)uVar16;
            tmp42[1] = (char)(uVar16 >> 8);
            tmp42[2] = (char)(uVar16 >> 0x10);
            tmp42[3] = (char)(uVar16 >> 0x18);
            uVar16 = *(uint *)(work->hash + 0x18);
            uVar16 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
                     uVar16 >> 0x18;
            tmp42[4] = (char)uVar16;
            tmp42[5] = (char)(uVar16 >> 8);
            tmp42[6] = (char)(uVar16 >> 0x10);
            tmp42[7] = (char)(uVar16 >> 0x18);
            uVar16 = *(uint *)(work->hash + 0x14);
            uVar16 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
                     uVar16 >> 0x18;
            tmp42[8] = (char)uVar16;
            tmp42[9] = (char)(uVar16 >> 8);
            tmp42[10] = (char)(uVar16 >> 0x10);
            tmp42[0xb] = (char)(uVar16 >> 0x18);
            uVar16 = *(uint *)(work->hash + 0x10);
            uVar16 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
                     uVar16 >> 0x18;
            tmp42[0xc] = (char)uVar16;
            tmp42[0xd] = (char)(uVar16 >> 8);
            tmp42[0xe] = (char)(uVar16 >> 0x10);
            tmp42[0xf] = (char)(uVar16 >> 0x18);
            uVar16 = *(uint *)(work->hash + 0xc);
            uVar16 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
                     uVar16 >> 0x18;
            tmp42[0x10] = (char)uVar16;
            tmp42[0x11] = (char)(uVar16 >> 8);
            tmp42[0x12] = (char)(uVar16 >> 0x10);
            tmp42[0x13] = (char)(uVar16 >> 0x18);
            uVar16 = *(uint *)(work->hash + 8);
            uVar16 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
                     uVar16 >> 0x18;
            tmp42[0x14] = (char)uVar16;
            tmp42[0x15] = (char)(uVar16 >> 8);
            tmp42[0x16] = (char)(uVar16 >> 0x10);
            tmp42[0x17] = (char)(uVar16 >> 0x18);
            uVar16 = *(uint *)(work->hash + 4);
            uVar16 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
                     uVar16 >> 0x18;
            tmp42[0x18] = (char)uVar16;
            tmp42[0x19] = (char)(uVar16 >> 8);
            tmp42[0x1a] = (char)(uVar16 >> 0x10);
            tmp42[0x1b] = (char)(uVar16 >> 0x18);
            uVar16 = *(uint *)work->hash;
            uVar16 = uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
                     uVar16 >> 0x18;
            tmp42[0x1c] = (char)uVar16;
            tmp42[0x1d] = (char)(uVar16 >> 8);
            tmp42[0x1e] = (char)(uVar16 >> 0x10);
            tmp42[0x1f] = (char)(uVar16 >> 0x18);
            do {
              if (tmp42[iVar5] != '\0') break;
              iVar5 = iVar5 + 1;
            } while (iVar5 != 0x1d);
            uVar16 = *(uint *)(tmp42 + iVar5);
            dVar29 = round(work->work_difficulty);
            __fixunsdfdi(SUB84(dVar29,0),(int)((ulonglong)dVar29 >> 0x20));
            suffix_string(work->share_diff,disposition,0x10,0);
            pcVar9 = disposition;
            snprintf(hashshow,0x40,"%08lx Diff %s/%llu%s",
                     uVar16 << 0x18 | (uVar16 >> 8 & 0xff) << 0x10 | (uVar16 >> 0x10 & 0xff) << 8 |
                     uVar16 >> 0x18,pcVar9);
            ppVar26 = work->pool;
            ptVar8 = get_thread(work->thr_id);
            pcVar27 = ptVar8->cgpu;
            if ((local_a80 == (json_t *)0x0) ||
               ((local_a80->type != JSON_TRUE &&
                ((work->gbt == false || (local_a80->type != JSON_NULL)))))) {
              iVar5 = pthread_mutex_lock((pthread_mutex_t *)&stats_lock);
              if (iVar5 != 0) {
                _mutex_lock((pthread_mutex_t *)"share_result",(char *)0xdb3,func_07,line_07);
              }
              dVar29 = pcVar27->diff_rejected;
              dVar31 = work->work_difficulty;
              dVar30 = ppVar26->diff_rejected;
              uVar16 = (uint)ppVar26->rejected;
              iVar19 = *(int *)((int)&ppVar26->rejected + 4);
              iVar5 = ppVar26->seq_rejects;
              pcVar27->rejected = pcVar27->rejected + 1;
              *(uint *)&ppVar26->rejected = uVar16 + 1;
              *(uint *)((int)&ppVar26->rejected + 4) = iVar19 + (uint)(0xfffffffe < uVar16);
              total_diff_rejected = dVar31 + total_diff_rejected;
              pcVar27->diff_rejected = dVar29 + dVar31;
              bVar28 = 0xfffffffe < (uint)total_rejected;
              total_rejected._0_4_ = (uint)total_rejected + 1;
              ppVar26->seq_rejects = iVar5 + 1;
              total_rejected._4_4_ = total_rejected._4_4_ + (uint)bVar28;
              ppVar26->diff_rejected = dVar30 + dVar31;
              iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&stats_lock);
              if (iVar5 != 0) {
                _mutex_unlock_noyield
                          ((pthread_mutex_t *)"share_result",(char *)0xdbb,func_08,line_08);
              }
              (*selective_yield)();
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                builtin_strncpy(tmp42,"PROOF OF WORK RESULT: false (booooo)",0x24);
                tmp42[0x24] = '\0';
                _applog(7,tmp42,false);
              }
              _Var4 = opt_realquiet;
              if ((opt_quiet == false) && (opt_realquiet == false)) {
                disposition[4] = 'c';
                disposition[5] = 't';
                builtin_strncpy(disposition,"reje",4);
                disposition[6] = '\0';
                memset(disposition + 7,0,0x1d);
                reason[0] = _Var4;
                cVar3 = _Var4;
                if (1 < total_pools) {
                  snprintf(where,0x14,"pool %d",work->pool->pool_no);
                  cVar3 = where[0];
                }
                where[0] = cVar3;
                local_a74 = where;
                if (work->gbt == false) {
                  local_a80 = json_object_get(json,"reject-reason");
                }
                if (local_a80 == (json_t *)0x0) {
                  if ((work->stratum != false) && (json_00 != (json_t *)0x0)) {
                    jVar15 = json_00->type;
                    if (jVar15 == JSON_ARRAY) {
                      json_00 = json_array_get(json_00,1);
                      if (json_00 == (json_t *)0x0) goto LAB_00026c6a;
                      jVar15 = json_00->type;
                    }
                    if (jVar15 == JSON_STRING) {
                      pcVar9 = json_string_value(json_00);
                      snprintf(reason,0x1f," (%s)",pcVar9);
                    }
                  }
                }
                else {
                  pcVar9 = json_string_value(local_a80);
                  uVar16 = strlen(pcVar9);
                  if (0x1b < uVar16) {
                    uVar16 = 0x1c;
                  }
                  reason[0] = ' ';
                  reason[1] = '(';
                  _cg_memcpy(reason + 2,pcVar9,uVar16,"cgminer.c","share_result",0xde3);
                  reason[uVar16 + 2] = ')';
                  reason[uVar16 + 3] = '\0';
                  _cg_memcpy(disposition + 7,pcVar9,uVar16,"cgminer.c","share_result",0xde8);
                  disposition[6] = ':';
                  disposition[uVar16 + 7] = '\0';
                }
LAB_00026c6a:
                if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                  snprintf(tmp42,0x800,"Rejected %s %s %d %s%s %s%s",hashshow,pcVar27->drv->name,
                           pcVar27->device_id,local_a74,reason,&DAT_00046bb8,&DAT_00046bb8);
                  _applog(5,tmp42,false);
                }
                sharelog(disposition,work);
              }
              iVar5 = ppVar26->seq_rejects;
              if (((10 < iVar5) && (work->stale == false)) &&
                 ((opt_disable_pool != false &&
                  ((1 < enabled_pools &&
                   (dVar29 = (double)__aeabi_l2d((uint)total_accepted,total_accepted._4_4_),
                   (dVar29 / total_secs) * 60.0 * 3.0 < (double)(longlong)iVar5)))))) {
                if ((use_syslog != false) || ((opt_log_output != false || (3 < opt_log_level)))) {
                  snprintf(tmp42,0x800,"Pool %d rejected %d sequential shares, disabling!",
                           ppVar26->pool_no,iVar5);
                  _applog(4,tmp42,false);
                }
                if (ppVar26->enabled == POOL_ENABLED) {
                  enabled_pools = enabled_pools + -1;
                }
                ppVar26->enabled = POOL_REJECTING;
                ppVar10 = current_pool();
                if (ppVar26 == ppVar10) {
                  switch_pools((pool *)0x0);
                }
                ppVar26->seq_rejects = 0;
              }
            }
            else {
              iVar5 = pthread_mutex_lock((pthread_mutex_t *)&stats_lock);
              if (iVar5 != 0) {
                _mutex_lock((pthread_mutex_t *)"share_result",(char *)0xd74,func_15,line_15);
              }
              uVar16 = (uint)ppVar26->accepted;
              iVar5 = *(int *)((int)&ppVar26->accepted + 4);
              dVar29 = pcVar27->diff_accepted;
              dVar31 = work->work_difficulty;
              dVar30 = ppVar26->diff_accepted;
              pcVar27->accepted = pcVar27->accepted + 1;
              *(uint *)&ppVar26->accepted = uVar16 + 1;
              *(uint *)((int)&ppVar26->accepted + 4) = iVar5 + (uint)(0xfffffffe < uVar16);
              total_diff_accepted = dVar31 + total_diff_accepted;
              pcVar27->diff_accepted = dVar29 + dVar31;
              bVar28 = 0xfffffffe < (uint)total_accepted;
              total_accepted._0_4_ = (uint)total_accepted + 1;
              ppVar26->diff_accepted = dVar30 + dVar31;
              total_accepted._4_4_ = total_accepted._4_4_ + (uint)bVar28;
              iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&stats_lock);
              if (iVar5 != 0) {
                _mutex_unlock_noyield
                          ((pthread_mutex_t *)"share_result",(char *)0xd7e,func_16,line_16);
              }
              (*selective_yield)();
              ppVar26->seq_rejects = 0;
              pcVar27->last_share_pool = ppVar26->pool_no;
              tVar7 = time((time_t *)0x0);
              _Var4 = opt_debug;
              uVar18 = *(undefined4 *)&work->work_difficulty;
              uVar22 = *(undefined4 *)((int)&work->work_difficulty + 4);
              pcVar27->last_share_pool_time = tVar7;
              *(undefined4 *)&pcVar27->last_share_diff = uVar18;
              *(undefined4 *)((int)&pcVar27->last_share_diff + 4) = uVar22;
              ppVar26->last_share_time = tVar7;
              *(undefined4 *)&ppVar26->last_share_diff = uVar18;
              *(undefined4 *)((int)&ppVar26->last_share_diff + 4) = uVar22;
              if ((_Var4 != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                builtin_strncpy(tmp42,"PROOF OF WORK RESULT: true (yay!!!)",0x24);
                _applog(7,tmp42,false);
              }
              if ((opt_quiet == false) && (opt_realquiet == false)) {
                if (total_pools < 2) {
                  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                    pcVar9 = pcVar27->drv->name;
                    snprintf(tmp42,0x800,"Accepted %s %s %d %s%s",hashshow,pcVar9,pcVar27->device_id
                             ,&DAT_00046bb8,&DAT_00046bb8);
                    _applog(5,tmp42,false);
                  }
                }
                else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)
                        ) {
                  pcVar9 = pcVar27->drv->name;
                  snprintf(tmp42,0x800,"Accepted %s %s %d pool %d %s%s",hashshow,pcVar9,
                           pcVar27->device_id,work->pool->pool_no,&DAT_00046bb8,&DAT_00046bb8);
                  _applog(5,tmp42,false);
                }
              }
              sharelog("accept",work);
              if ((opt_shares == 0) || (total_diff_accepted < (double)(longlong)opt_shares)) {
                if (ppVar26->enabled == POOL_REJECTING) {
                  if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
LAB_00027500:
                    ppVar26->enabled = POOL_ENABLED;
                    enabled_pools = enabled_pools + 1;
                  }
                  else {
                    snprintf(tmp42,0x800,"Rejecting pool %d now accepting shares, re-enabling!",
                             ppVar26->pool_no,pcVar9);
                    _applog(4,tmp42,false);
                    if (ppVar26->enabled != POOL_ENABLED) goto LAB_00027500;
                  }
                  switch_pools((pool *)0x0);
                }
                if (work->block != false) {
                  restart_threads();
                }
              }
              else {
                if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
                  snprintf(tmp42,0x800,
                           "Successfully mined %d accepted shares as requested and exiting.",
                           opt_shares,pcVar9);
                  _applog(4,tmp42,false);
                }
                kill_work();
              }
            }
            _free_work(&__ptr->work,"cgminer.c","parse_stratum_response",0x1c3f);
            bVar28 = true;
            free(__ptr);
            sVar20 = json->refcount;
          }
          if ((sVar20 != 0xffffffff) && (json->refcount = sVar20 - 1, sVar20 - 1 == 0)) {
            json_delete(json);
          }
          if (!bVar28) goto LAB_00026e06;
          goto LAB_0002667c;
        }
        if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 6)) {
LAB_00026e0a:
          if ((opt_log_output != false) || (5 < opt_log_level)) goto LAB_00026e18;
        }
        else {
          snprintf(tmp42,0x800,"JSON decode failed(%d): %s",err.line,err.text);
          _applog(6,tmp42,false);
LAB_00026e06:
          if (use_syslog == false) goto LAB_00026e0a;
LAB_00026e18:
          snprintf(tmp42,0x800,"Unknown stratum msg: %s",pcVar6);
          _applog(6,tmp42,false);
        }
      }
      free(pcVar6);
    }
    if (opt_debug == false) {
LAB_0002673a:
      if (use_syslog == false) goto LAB_0002673e;
LAB_0002674a:
                    /* WARNING: Load size is inaccurate */
      snprintf(tmp42,0x800,"Stratum connection to pool %d interrupted",*userdata);
      _applog(5,tmp42,false);
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (6 < opt_log_level)) {
                    /* WARNING: Load size is inaccurate */
        snprintf(tmp42,0x800,"Stratum select failed on pool %d with value %d",*userdata,iVar5);
        _applog(7,tmp42,false);
        goto LAB_0002673a;
      }
LAB_0002673e:
      if ((opt_log_output != false) || (4 < opt_log_level)) goto LAB_0002674a;
    }
    *(int *)((int)userdata + 0x80) = *(int *)((int)userdata + 0x80) + 1;
    total_go = total_go + 1;
    iVar5 = pthread_mutex_lock((pthread_mutex_t *)((int)userdata + 0xd4));
    if (iVar5 != 0) {
      _mutex_lock((pthread_mutex_t *)"supports_resume",(char *)0x1cc9,func_01,line_01);
    }
    iVar5 = pthread_rwlock_rdlock((pthread_rwlock_t *)((int)userdata + 0xec));
    if (iVar5 != 0) {
      _rd_lock((pthread_rwlock_t *)"supports_resume",(char *)0x1cc9,func_02,line_02);
    }
    iVar5 = pthread_mutex_unlock((pthread_mutex_t *)((int)userdata + 0xd4));
    if (iVar5 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)"supports_resume",(char *)0x1cc9,func_03,line_03);
    }
    iVar19 = *(int *)((int)userdata + 0x27c);
    iVar5 = pthread_rwlock_unlock((pthread_rwlock_t *)((int)userdata + 0xec));
    if (iVar5 != 0) {
      _rw_unlock((pthread_rwlock_t *)"supports_resume",(char *)0x1ccb,func_04,line_04);
    }
    (*selective_yield)();
    if ((iVar19 == 0) || (opt_lowmem != false)) {
      clear_stratum_shares((pool *)userdata);
    }
    clear_pool_work((pool *)userdata);
    ppVar26 = current_pool();
    if ((pool *)userdata == ppVar26) {
      restart_threads();
    }
    while (_Var4 = restart_stratum((pool *)userdata), !_Var4) {
      pool_died((pool *)userdata);
      if (*(char *)((int)userdata + 0x69) != '\0') {
        return (void *)0x0;
      }
      cgsleep_ms(5000);
    }
  } while( true );
}

