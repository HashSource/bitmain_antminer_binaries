
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Unknown calling convention */

void * stratum_sthread(void *userdata)

{
  char cVar1;
  stratum_share *psVar2;
  work *pwVar3;
  undefined4 uVar4;
  _Bool _Var5;
  pthread_t __th;
  thread_q *ptVar6;
  uint uVar7;
  int iVar8;
  stratum_share *__ptr;
  time_t tVar9;
  size_t sVar10;
  UT_hash_handle *pUVar11;
  UT_hash_bucket *pUVar12;
  uint uVar13;
  int iVar14;
  char *pcVar15;
  char *func;
  char *func_00;
  char *pcVar16;
  char *func_01;
  uint uVar17;
  char *func_02;
  char *func_03;
  char *func_04;
  char *func_05;
  char *func_06;
  int line;
  int line_00;
  int line_01;
  UT_hash_table *pUVar18;
  UT_hash_handle *pUVar19;
  int line_02;
  int line_03;
  int line_04;
  int line_05;
  int line_06;
  int iVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  UT_hash_handle *pUVar25;
  bool bVar26;
  char *pcVar27;
  int local_c8c;
  UT_hash_bucket *local_c84;
  uint nonce;
  work *work;
  uchar nonce2 [8];
  char noncehex [12];
  char threadname [16];
  char nonce2hex [20];
  char s [1024];
  char tmp42 [2048];
  
  __th = pthread_self();
  pthread_detach(__th);
                    /* WARNING: Load size is inaccurate */
  snprintf(threadname,0x10,"%d/SStratum",*userdata);
  RenameThread(threadname);
  ptVar6 = tq_new();
  uVar4 = tmp42._44_4_;
  *(thread_q **)((int)userdata + 0x2d8) = ptVar6;
  if (ptVar6 == (thread_q *)0x0) {
    builtin_strncpy(tmp42,"Failed to create stratum_q in stratum_sthread",0x2e);
    tmp42._46_2_ = SUB42(uVar4,2);
    _applog(3,tmp42,true);
    _quit(1);
  }
  uVar24 = 0;
  iVar20 = 0;
  iVar21 = 0;
LAB_000276bc:
  do {
    cVar1 = *(char *)((int)userdata + 0x69);
    while( true ) {
      if (cVar1 != '\0') {
        tq_freeze(*(thread_q **)((int)userdata + 0x2d8));
        return (void *)0x0;
      }
      work = (work *)tq_pop(*(thread_q **)((int)userdata + 0x2d8),(timespec *)0x0);
      uVar4 = tmp42._28_4_;
      if (work == (work *)0x0) {
        builtin_strncpy(tmp42,"Stratum q returned empty work",0x1e);
        tmp42._30_2_ = SUB42(uVar4,2);
        _applog(3,tmp42,true);
        _quit(1);
      }
      if (8 < work->nonce2_len) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                    /* WARNING: Load size is inaccurate */
          snprintf(tmp42,0x800,"Pool %d asking for inappropriately long nonce2 length %d",*userdata,
                   work->nonce2_len);
          _applog(3,tmp42,false);
          if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            builtin_strncpy(tmp42,"Not attempting to submit shares",0x20);
            _applog(3,tmp42,false);
          }
        }
        _free_work(&work,"cgminer.c","stratum_sthread",0x1d72);
        goto LAB_000276bc;
      }
      uVar7 = *(uint *)(work->data + 0x4c);
      iVar8 = (int)work->nonce2;
      iVar14 = *(int *)((int)&work->nonce2 + 4);
      nonce = uVar7;
      nonce2._0_4_ = iVar8;
      nonce2._4_4_ = iVar14;
      if ((uVar24 == uVar7) && (iVar21 == iVar14 && iVar20 == iVar8)) break;
      __bin2hex(noncehex,(uchar *)&nonce,4);
      __bin2hex(nonce2hex,nonce2,work->nonce2_len);
      __ptr = (stratum_share *)_cgcalloc(0x34,1,"cgminer.c","stratum_sthread",0x1d87);
      pwVar3 = work;
      tVar9 = time((time_t *)0x0);
      __ptr->sshare_time = tVar9;
      __ptr->work = work;
      memset(s,0,0x400);
      iVar20 = pthread_mutex_lock((pthread_mutex_t *)&sshare_lock);
      if (iVar20 != 0) {
        _mutex_lock((pthread_mutex_t *)"stratum_sthread",(char *)0x1d90,func,line);
      }
      __ptr->id = swork_id;
      swork_id = swork_id + 1;
      iVar20 = pthread_mutex_unlock((pthread_mutex_t *)&sshare_lock);
      if (iVar20 != 0) {
        _mutex_unlock_noyield((pthread_mutex_t *)"stratum_sthread",(char *)0x1d93,func_00,line_00);
      }
      (*selective_yield)();
      if (*(char *)((int)userdata + 0x284) == '\0') {
        pcVar15 = nonce2hex;
        pcVar27 = noncehex;
        pcVar16 = work->ntime;
        uVar24 = __ptr->id;
        snprintf(s,0x400,
                 "{\"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\"], \"id\": %d, \"method\": \"mining.submit\"}"
                 ,*(undefined4 *)((int)userdata + 0xac),work->job_id,pcVar15,pcVar16,pcVar27,uVar24)
        ;
      }
      else {
        pcVar15 = nonce2hex;
        uVar24 = work->version;
        pcVar27 = noncehex;
        pcVar16 = work->ntime;
        uVar24 = uVar24 << 0x18 | (uVar24 >> 8 & 0xff) << 0x10 | (uVar24 >> 0x10 & 0xff) << 8 |
                 uVar24 >> 0x18;
        snprintf(s,0x400,
                 "{\"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%08x\"], \"id\": %d, \"method\": \"mining.submit\"}"
                 ,*(undefined4 *)((int)userdata + 0xac),work->job_id,pcVar15,pcVar16,pcVar27,uVar24,
                 __ptr->id);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                    /* WARNING: Load size is inaccurate */
        snprintf(tmp42,0x800,"Submitting share %08lx to pool %d",
                 *(undefined4 *)(pwVar3->hash + 0x18),*userdata,pcVar15,pcVar16,pcVar27,uVar24);
        _applog(6,tmp42,false);
      }
LAB_00027806:
      iVar20 = __ptr->sshare_time;
      tVar9 = time((time_t *)0x0);
      if (tVar9 <= iVar20 + 0x77) {
        sVar10 = strlen(s);
        _Var5 = stratum_send((pool *)userdata,s,sVar10);
        if (_Var5) {
          iVar20 = pthread_mutex_lock((pthread_mutex_t *)&sshare_lock);
          if (iVar20 != 0) {
            _mutex_lock((pthread_mutex_t *)"stratum_sthread",(char *)0x1db7,func_01,line_01);
          }
          uVar24 = (byte)__ptr->id + 0x112410d + (uint)*(byte *)((int)&__ptr->id + 3) * 0x1000000 +
                   (uint)*(byte *)((int)&__ptr->id + 2) * 0x10000 +
                   (uint)*(byte *)((int)&__ptr->id + 1) * 0x100 ^ 0x7f76d;
          uVar17 = 0x9f49bac6 - uVar24 ^ uVar24 << 8;
          (__ptr->hh).key = &__ptr->id;
          psVar2 = stratum_shares;
          uVar22 = (-0x112410d - uVar24) - uVar17 ^ uVar17 >> 0xd;
          (__ptr->hh).keylen = 4;
          uVar24 = (uVar24 - uVar17) - uVar22 ^ uVar22 >> 0xc;
          uVar17 = (uVar17 - uVar22) - uVar24 ^ uVar24 << 0x10;
          uVar22 = (uVar22 - uVar24) - uVar17 ^ uVar17 >> 5;
          uVar24 = (uVar24 - uVar17) - uVar22 ^ uVar22 >> 3;
          uVar17 = (uVar17 - uVar22) - uVar24 ^ uVar24 << 10;
          uVar24 = (uVar22 - uVar24) - uVar17 ^ uVar17 >> 0xf;
          (__ptr->hh).hashv = uVar24;
          if (psVar2 == (stratum_share *)0x0) {
            (__ptr->hh).next = (void *)0x0;
            (__ptr->hh).prev = (void *)0x0;
            stratum_shares = __ptr;
            pUVar18 = (UT_hash_table *)malloc(0x2c);
            (__ptr->hh).tbl = pUVar18;
            if (pUVar18 == (UT_hash_table *)0x0) goto LAB_00027e4c;
            pUVar18->buckets = (UT_hash_bucket *)0x0;
            pUVar18->num_buckets = 0;
            pUVar18->log2_num_buckets = 0;
            pUVar18->num_items = 0;
            pUVar18->tail = (UT_hash_handle *)0x0;
            pUVar18->hho = 0;
            pUVar18->ideal_chain_maxlen = 0;
            pUVar18->nonideal_items = 0;
            pUVar18->ineff_expands = 0;
            pUVar18->noexpand = 0;
            pUVar18->signature = 0;
            pUVar18 = (__ptr->hh).tbl;
            pUVar18->tail = (UT_hash_handle *)__ptr;
            pUVar18->hho = 0;
            pUVar18->num_buckets = 0x20;
            pUVar18->log2_num_buckets = 5;
            pUVar12 = (UT_hash_bucket *)malloc(0x180);
            pUVar18->buckets = pUVar12;
            if (pUVar12 == (UT_hash_bucket *)0x0) goto LAB_00027e4c;
            memset(pUVar12,0,0x180);
            pUVar18 = (__ptr->hh).tbl;
            pUVar18->signature = 0xa0111fe1;
          }
          else {
            pUVar18 = (psVar2->hh).tbl;
            (__ptr->hh).next = (void *)0x0;
            (__ptr->hh).tbl = pUVar18;
            pUVar18 = (psVar2->hh).tbl;
            pUVar11 = pUVar18->tail;
            iVar20 = pUVar18->hho;
            pUVar11->next = __ptr;
            (__ptr->hh).prev = (void *)((int)pUVar11 - iVar20);
            pUVar18->tail = (UT_hash_handle *)__ptr;
          }
          pUVar12 = pUVar18->buckets;
          uVar24 = uVar24 & pUVar18->num_buckets - 1;
          pUVar18->num_items = pUVar18->num_items + 1;
          pUVar11 = pUVar12[uVar24].hh_head;
          uVar17 = pUVar12[uVar24].count + 1;
          pUVar12[uVar24].count = uVar17;
          (__ptr->hh).hh_next = pUVar11;
          (__ptr->hh).hh_prev = (UT_hash_handle *)0x0;
          if (pUVar11 != (UT_hash_handle *)0x0) {
            pUVar11->hh_prev = (UT_hash_handle *)__ptr;
          }
          pUVar12[uVar24].hh_head = (UT_hash_handle *)__ptr;
          if (((pUVar12[uVar24].expand_mult + 1) * 10 <= uVar17) &&
             (pUVar18 = (__ptr->hh).tbl, pUVar18->noexpand != 1)) {
            sVar10 = pUVar18->num_buckets * 0x18;
            pUVar12 = (UT_hash_bucket *)malloc(sVar10);
            if (pUVar12 == (UT_hash_bucket *)0x0) {
LAB_00027e4c:
                    /* WARNING: Subroutine does not return */
              exit(-1);
            }
            memset(pUVar12,0,sVar10);
            pUVar18 = (__ptr->hh).tbl;
            uVar17 = pUVar18->num_buckets;
            pUVar18->nonideal_items = 0;
            uVar24 = pUVar18->num_items >> (pUVar18->log2_num_buckets + 1 & 0xff);
            uVar22 = uVar17 * 2 - 1;
            if ((uVar22 & pUVar18->num_items) != 0) {
              uVar24 = uVar24 + 1;
            }
            pUVar18->ideal_chain_maxlen = uVar24;
            if (uVar17 == 0) {
              local_c84 = pUVar18->buckets;
            }
            else {
              local_c84 = pUVar18->buckets;
              local_c8c = 0;
              do {
                pUVar11 = *(UT_hash_handle **)((int)&local_c84->hh_head + local_c8c);
                while (pUVar11 != (UT_hash_handle *)0x0) {
                  pUVar25 = pUVar11->hh_next;
                  uVar23 = uVar22 & pUVar11->hashv;
                  uVar13 = pUVar12[uVar23].count + 1;
                  pUVar12[uVar23].count = uVar13;
                  if (uVar24 < uVar13) {
                    pUVar18->nonideal_items = pUVar18->nonideal_items + 1;
                    uVar13 = __aeabi_uidiv(uVar13,uVar24);
                    pUVar12[uVar23].expand_mult = uVar13;
                  }
                  pUVar19 = pUVar12[uVar23].hh_head;
                  pUVar11->hh_prev = (UT_hash_handle *)0x0;
                  pUVar11->hh_next = pUVar19;
                  if (pUVar19 != (UT_hash_handle *)0x0) {
                    pUVar19->hh_prev = pUVar11;
                  }
                  pUVar12[uVar23].hh_head = pUVar11;
                  pUVar11 = pUVar25;
                }
                local_c8c = local_c8c + 0xc;
              } while (local_c8c != uVar17 * 0xc);
            }
            free(local_c84);
            pUVar18 = (__ptr->hh).tbl;
            uVar22 = pUVar18->nonideal_items;
            pUVar18->buckets = pUVar12;
            uVar24 = pUVar18->num_items >> 1;
            pUVar18->log2_num_buckets = pUVar18->log2_num_buckets + 1;
            uVar17 = uVar22;
            if (uVar22 <= uVar24) {
              uVar17 = 0;
            }
            pUVar18->num_buckets = pUVar18->num_buckets << 1;
            if (uVar24 < uVar22) {
              uVar17 = pUVar18->ineff_expands + 1;
              pUVar18->ineff_expands = uVar17;
              uVar24 = uVar17;
              if (1 < uVar17) {
                uVar24 = 1;
              }
              if (1 < uVar17) {
                pUVar18->noexpand = uVar24;
              }
            }
            else {
              pUVar18->ineff_expands = uVar17;
            }
          }
          *(int *)((int)userdata + 0x2dc) = *(int *)((int)userdata + 0x2dc) + 1;
          iVar20 = pthread_mutex_unlock((pthread_mutex_t *)&sshare_lock);
          if (iVar20 != 0) {
            _mutex_unlock_noyield
                      ((pthread_mutex_t *)"stratum_sthread",(char *)0x1dba,func_02,line_02);
          }
          (*selective_yield)();
          _Var5 = pool_tclear((pool *)userdata,(_Bool *)((int)userdata + 0x60));
          if ((_Var5) &&
             (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
                    /* WARNING: Load size is inaccurate */
            snprintf(tmp42,0x800,"Pool %d communication resumed, submitting work",*userdata);
            _applog(4,tmp42,false);
          }
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            builtin_strncpy(tmp42,"Successfully submitted, adding to stratum_shares db",0x34);
            _applog(7,tmp42,false);
          }
          tVar9 = time((time_t *)0x0);
          _Var5 = opt_debug;
          __ptr->sshare_sent = tVar9;
          iVar20 = tVar9 - __ptr->sshare_time;
          if (((_Var5 != false) || (0 < iVar20)) &&
             ((use_syslog != false || ((opt_log_output != false || (5 < opt_log_level)))))) {
                    /* WARNING: Load size is inaccurate */
            snprintf(tmp42,0x800,"Pool %d stratum share submission lag time %d seconds",*userdata,
                     iVar20);
            _applog(6,tmp42,false);
          }
          goto LAB_00027b54;
        }
        _Var5 = pool_tset((pool *)userdata,(_Bool *)((int)userdata + 0x60));
        if ((!_Var5) && (_Var5 = cnx_needed((pool *)userdata), _Var5)) {
          if ((use_syslog != false) || ((opt_log_output != false || (3 < opt_log_level)))) {
                    /* WARNING: Load size is inaccurate */
            snprintf(tmp42,0x800,"Pool %d stratum share submission failure",*userdata);
            _applog(4,tmp42,false);
          }
          total_ro = total_ro + 1;
          *(int *)((int)userdata + 0x84) = *(int *)((int)userdata + 0x84) + 1;
        }
        uVar4 = tmp42._48_4_;
        if (opt_lowmem == false) {
          iVar20 = pthread_mutex_lock((pthread_mutex_t *)((int)userdata + 0xd4));
          if (iVar20 != 0) {
            _mutex_lock((pthread_mutex_t *)"stratum_sthread",(char *)0x1dd0,func_03,line_03);
          }
          iVar20 = pthread_rwlock_rdlock((pthread_rwlock_t *)((int)userdata + 0xec));
          if (iVar20 != 0) {
            _rd_lock((pthread_rwlock_t *)"stratum_sthread",(char *)0x1dd0,func_04,line_04);
          }
          iVar20 = pthread_mutex_unlock((pthread_mutex_t *)((int)userdata + 0xd4));
          if (iVar20 != 0) {
            _mutex_unlock_noyield
                      ((pthread_mutex_t *)"stratum_sthread",(char *)0x1dd0,func_05,line_05);
          }
          pcVar15 = *(char **)((int)userdata + 0x264);
          if (pcVar15 != (char *)0x0) {
            uVar24 = strcmp(work->nonce1,pcVar15);
            pcVar15 = (char *)(1 - uVar24);
            if (1 < uVar24) {
              pcVar15 = (char *)0x0;
            }
          }
          iVar20 = pthread_rwlock_unlock((pthread_rwlock_t *)((int)userdata + 0xec));
          if (iVar20 != 0) {
            _rw_unlock((pthread_rwlock_t *)"stratum_sthread",(char *)0x1dd2,func_06,line_06);
          }
          (*selective_yield)();
          if (pcVar15 != (char *)0x0) goto code_r0x00027d68;
          if (opt_debug == false) goto LAB_00027c2a;
          if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7))
          goto LAB_00027c62;
          builtin_strncpy(tmp42,"No matching session id for resubmitting stratum shar",0x34);
          tmp42[0x34] = 'e';
          tmp42[0x35] = '\0';
          _applog(7,tmp42,false);
        }
        else {
          if (opt_debug == false) goto LAB_00027c2a;
          if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7))
          goto LAB_00027c62;
          builtin_strncpy(tmp42,"Lowmem option prevents resubmitting stratum share",0x32);
          tmp42._50_2_ = SUB42(uVar4,2);
          _applog(7,tmp42,false);
        }
      }
      if (opt_debug != false) {
        if (use_syslog == false) {
LAB_00027c62:
          if ((opt_log_output == false) && (opt_log_level < 7)) goto LAB_00027c2a;
        }
        uVar4 = tmp42._40_4_;
        builtin_strncpy(tmp42,"Failed to submit stratum share, discarding",0x2b);
        tmp42[0x2b] = SUB41(uVar4,3);
        _applog(7,tmp42,false);
      }
LAB_00027c2a:
      _free_work(&work,"cgminer.c","stratum_sthread",0x1de1);
      free(__ptr);
      bVar26 = 0xfffffffe < (uint)total_stale;
      total_stale._0_4_ = (uint)total_stale + 1;
      total_stale._4_4_ = total_stale._4_4_ + (uint)bVar26;
      *(int *)((int)userdata + 0x78) = *(int *)((int)userdata + 0x78) + 1;
LAB_00027b54:
      cVar1 = *(char *)((int)userdata + 0x69);
      iVar20 = iVar8;
      iVar21 = iVar14;
      uVar24 = uVar7;
    }
    if ((use_syslog != false) || ((opt_log_output != false || (5 < opt_log_level)))) {
                    /* WARNING: Load size is inaccurate */
      snprintf(tmp42,0x800,"Filtering duplicate share to pool %d",*userdata);
      _applog(6,tmp42,false);
    }
    _free_work(&work,"cgminer.c","stratum_sthread",0x1d7e);
  } while( true );
code_r0x00027d68:
  sleep(2);
  goto LAB_00027806;
}

