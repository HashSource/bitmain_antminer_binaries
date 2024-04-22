
/* WARNING: Unknown calling convention */
/* Local variable reason_val:json_t *[r0:4] conflicts with parameter, skipped. */

void * stratum_rthread(void *userdata)

{
  char cVar1;
  double dVar2;
  code **ppcVar3;
  pthread_mutex_t *ppVar4;
  int *piVar5;
  stratum_share *psVar6;
  stratum_share *psVar7;
  _Bool _Var8;
  pool *pool;
  pthread_t __th;
  int sel_ret;
  char *pcVar9;
  char *s;
  json_t *json;
  json_t *res_val;
  json_t *json_00;
  json_t *err_val;
  json_t *json_01;
  json_t *id_val;
  int iVar10;
  time_t tVar11;
  time_t now_t;
  thr_info *ptVar12;
  thr_info *thr;
  char *reasontmp;
  size_t reasonLen;
  pool *ppVar13;
  stratum_share *psVar14;
  char *__retval;
  char *s_1;
  uint uVar15;
  work *work_00;
  work *work;
  void *pvVar16;
  UT_hash_handle *pUVar17;
  char *pcVar18;
  json_error_t *error;
  uint uVar19;
  char *pcVar20;
  UT_hash_handle *pUVar21;
  undefined4 uVar22;
  char *reason_str;
  undefined4 *puVar23;
  int iVar24;
  pool_strategy line;
  char **ppcVar25;
  json_type jVar26;
  uint line_00;
  code *line_01;
  work *line_02;
  char *pcVar27;
  size_t sVar28;
  stratum_share *psVar29;
  double *pdVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  uint uVar33;
  stratum_share *__ptr;
  UT_hash_handle *_hd_hh_del;
  uint *dest;
  undefined4 uVar34;
  UT_hash_bucket *pUVar35;
  char *ss;
  UT_hash_table *pUVar36;
  pool *ppVar37;
  pool *pool_1;
  cgpu_info *cgpu;
  cgpu_info *pcVar38;
  timeval *ptVar39;
  int srdiff;
  bool bVar40;
  double dVar41;
  double dVar42;
  double dVar43;
  double dVar44;
  json_int_t jVar45;
  timeval *in_stack_fffff558;
  uint in_stack_fffff55c;
  json_t *local_a80;
  char *local_a74;
  work *work_1;
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
  pcVar18 = DAT_00026808;
  snprintf(threadname,0x10,DAT_00026808,*userdata);
  ppcVar3 = DAT_0002682c;
  dVar2 = DAT_00026800;
  RenameThread(threadname);
  do {
    while( true ) {
      if (*(char *)((int)userdata + 0x69) != '\0') {
        suspend_stratum((pool *)userdata);
        return (void *)0x0;
      }
      _Var8 = sock_full((pool *)userdata);
      if ((!_Var8) && (_Var8 = cnx_needed((pool *)userdata), !_Var8)) {
        suspend_stratum((pool *)userdata);
        clear_stratum_shares((pool *)userdata);
        clear_pool_work((pool *)userdata);
        while ((_Var8 = cnx_needed((pool *)userdata), !_Var8 &&
               ((line = *(pool_strategy *)((int)userdata + 100),
                *(pool_strategy *)((int)userdata + 100) == POOL_FAILOVER ||
                (((ppVar37 = current_pool(), (pool *)userdata != ppVar37 &&
                  (pool_strategy != POOL_LOADBALANCE)) &&
                 (line = pool_strategy, pool_strategy != POOL_BALANCE))))))) {
          iVar10 = pthread_mutex_lock(DAT_0002680c);
          if (iVar10 != 0) {
            _mutex_lock(DAT_00027648,(char *)0x2628,pcVar18,line);
          }
          pthread_cond_wait(DAT_00026810,(pthread_mutex_t *)((int)DAT_00026810 + -0x1c));
          iVar10 = pthread_mutex_unlock(DAT_0002680c);
          if (iVar10 != 0) {
            _mutex_unlock_noyield(DAT_00027648,(char *)0x262a,pcVar18,line);
          }
          (**ppcVar3)();
        }
        while (_Var8 = restart_stratum((pool *)userdata), !_Var8) {
          pool_died((pool *)userdata);
          if (*(char *)((int)userdata + 0x69) != '\0') {
            return (void *)0x0;
          }
          cgsleep_ms(5000);
        }
      }
      puVar23 = (undefined4 *)(hashshow + 0x3c);
      do {
        puVar23 = puVar23 + 1;
        *puVar23 = 0;
      } while (puVar23 != rd.fds_bits + 0x1f);
      iVar24 = *(int *)((int)userdata + 0x24c);
      timeout.tv_usec = 0;
      timeout.tv_sec = 0x5a;
      iVar10 = iVar24;
      if (iVar24 < 0) {
        iVar10 = iVar24 + 0x1f;
      }
      pcVar18 = (char *)(iVar10 >> 5);
      ((fd_set *)&rd)->fds_bits[(int)pcVar18] =
           ((fd_set *)&rd)->fds_bits[(int)pcVar18] | 1 << (iVar24 % 0x20 & 0xffU);
      _Var8 = sock_full((pool *)userdata);
      pcVar9 = (char *)(uint)_Var8;
      ptVar39 = in_stack_fffff558;
      if (pcVar9 != (char *)0x0) break;
      ptVar39 = (timeval *)&timeout;
      in_stack_fffff558 =
           (timeval *)
           select(*(int *)((int)userdata + 0x24c) + 1,(fd_set *)&rd,(fd_set *)0x0,(fd_set *)0x0,
                  ptVar39);
      pcVar20 = DAT_00026ff4;
      pcVar18 = pcVar9;
      if (0 < (int)in_stack_fffff558) break;
      if (*DAT_00027008 == '\0') goto LAB_00026736;
      if (((*DAT_00026ff4 != '\0') || (*DAT_00026ff8 != '\0')) ||
         (pcVar18 = DAT_00026ff8, 6 < *DAT_00026ffc)) {
                    /* WARNING: Load size is inaccurate */
        snprintf(tmp42,0x800,DAT_0002700c,*userdata);
        _applog(7,tmp42,false);
        cVar1 = *pcVar20;
        goto LAB_0002673a;
      }
LAB_0002673e:
      in_stack_fffff558 = ptVar39;
      if ((*pcVar18 != '\0') || (4 < *DAT_0002681c)) {
LAB_0002674a:
                    /* WARNING: Load size is inaccurate */
        snprintf(tmp42,0x800,DAT_00026820,*userdata);
        _applog(5,tmp42,false);
      }
      ppcVar25 = DAT_00026824;
      pcVar18 = *DAT_00026824;
      *(int *)((int)userdata + 0x80) = *(int *)((int)userdata + 0x80) + 1;
      pcVar18 = pcVar18 + 1;
      *ppcVar25 = pcVar18;
      iVar10 = pthread_mutex_lock((pthread_mutex_t *)((int)userdata + 0xd4));
      if (iVar10 != 0) {
        _mutex_lock((pthread_mutex_t *)DAT_0002764c,(char *)0x1cc9,pcVar18,(int)ppcVar25);
      }
      iVar10 = pthread_rwlock_rdlock((pthread_rwlock_t *)((int)userdata + 0xec));
      if (iVar10 != 0) {
        _rd_lock(DAT_0002764c,(char *)0x1cc9,pcVar18,(int)ppcVar25);
      }
      iVar10 = pthread_mutex_unlock((pthread_mutex_t *)((int)userdata + 0xd4));
      if (iVar10 != 0) {
        _mutex_unlock_noyield((pthread_mutex_t *)DAT_0002764c,(char *)0x1cc9,pcVar18,(int)ppcVar25);
      }
      iVar24 = *(int *)((int)userdata + 0x27c);
      iVar10 = pthread_rwlock_unlock((pthread_rwlock_t *)((int)userdata + 0xec));
      if (iVar10 != 0) {
        _rw_unlock(DAT_0002764c,(char *)0x1ccb,pcVar18,(int)ppcVar25);
      }
      (**ppcVar3)();
      if ((iVar24 == 0) || (*DAT_00026828 != '\0')) {
        clear_stratum_shares((pool *)userdata);
      }
      clear_pool_work((pool *)userdata);
      ppVar37 = current_pool();
      if ((pool *)userdata == ppVar37) {
        restart_threads();
      }
      while (_Var8 = restart_stratum((pool *)userdata), !_Var8) {
        pool_died((pool *)userdata);
        if (*(char *)((int)userdata + 0x69) != '\0') {
          return (void *)0x0;
        }
        cgsleep_ms(5000);
      }
    }
    in_stack_fffff558 = ptVar39;
    pcVar9 = recv_line((pool *)userdata);
    ptVar39 = in_stack_fffff558;
    if (pcVar9 == (char *)0x0) {
LAB_00026736:
      in_stack_fffff558 = ptVar39;
      cVar1 = *DAT_00026814;
LAB_0002673a:
      pcVar18 = DAT_00026818;
      ptVar39 = in_stack_fffff558;
      if (cVar1 == '\0') goto LAB_0002673e;
      goto LAB_0002674a;
    }
    stratum_resumed((pool *)userdata);
    _Var8 = parse_method((pool *)userdata,pcVar9);
    if (_Var8) {
LAB_0002667c:
      if (*(char *)((int)userdata + 0x2a8) != '\0') {
        work_1 = make_work();
        *(undefined *)((int)userdata + 0x2a8) = 0;
        gen_stratum_work((pool *)userdata,work_1);
        work_1->longpoll = true;
        test_work_current(work_1);
        pcVar18 = DAT_00027004;
        _free_work(&work_1,DAT_00026fec,DAT_00027004,0x1d3b);
      }
    }
    else {
      error = &err;
      json = json_loads(pcVar9,0,error);
      pcVar18 = DAT_00026ff4;
      if (json == (json_t *)0x0) {
        if (((*DAT_00026ff4 != '\0') || (*DAT_00026ff8 != '\0')) || (5 < *DAT_00026ffc)) {
          in_stack_fffff558 = (timeval *)err.text;
          snprintf(tmp42,0x800,DAT_00027014,err.line);
          _applog(6,tmp42,false);
          cVar1 = *pcVar18;
          goto LAB_00026e06;
        }
LAB_00026e0a:
        if ((*DAT_00026ff8 == '\0') && (pcVar18 = DAT_00026ff8, *DAT_00026ffc < 6))
        goto LAB_00026686;
      }
      else {
        local_a80 = json_object_get(json,DAT_000269f8);
        json_00 = json_object_get(json,DAT_000269fc);
        json_01 = json_object_get(json,DAT_00026a00);
        if ((json_01 == (json_t *)0x0) || (jVar26 = json_01->type, jVar26 == JSON_NULL)) {
          if (json_00 == (json_t *)0x0) {
            ss = (char *)malloc(0x11);
            if ((undefined4 *)ss != (undefined4 *)0x0) {
              uVar22 = DAT_00027364[1];
              uVar31 = DAT_00027364[2];
              uVar32 = DAT_00027364[3];
              uVar34 = DAT_00027364[4];
              *(undefined4 *)ss = *DAT_00027364;
              *(undefined4 *)((int)ss + 4) = uVar22;
              *(undefined4 *)((int)ss + 8) = uVar31;
              *(undefined4 *)((int)ss + 0xc) = uVar32;
              *(char *)((int)ss + 0x10) = (char)uVar34;
            }
          }
          else {
            ss = json_dumps(json_00,3);
          }
          if (((*DAT_00026ff4 != '\0') || (*DAT_00026ff8 != '\0')) ||
             (pcVar18 = DAT_00026ff8, 5 < *DAT_00026ffc)) {
            snprintf(tmp42,0x800,DAT_00027010,ss);
            pcVar18 = (char *)0x0;
            _applog(6,tmp42,false);
          }
          free(ss);
LAB_00026f72:
          bVar40 = false;
          sVar28 = json->refcount;
          if (sVar28 == 0xffffffff) goto LAB_00026dfc;
LAB_00026f7c:
          json->refcount = sVar28 - 1;
          if (sVar28 - 1 != 0) goto LAB_00026dfc;
          json_delete(json);
          if (bVar40) goto LAB_0002667c;
        }
        else {
          jVar45 = json_integer_value(json_01);
          id = (int)jVar45;
          iVar10 = pthread_mutex_lock(DAT_00026a04);
          if (iVar10 != 0) {
            _mutex_lock((pthread_mutex_t *)DAT_00027630,(char *)0x1c0a,(char *)error,jVar26);
          }
          psVar6 = stratum_shares;
          line_00 = (id & 0xffU) + 0x112410d + (id & 0xff000000U);
          uVar19 = line_00 + ((uint)id >> 8 & 0xff) * 0x100 + ((uint)id >> 0x10 & 0xff) * 0x10000 ^
                   0x7f76d;
          uVar15 = 0x9f49bac6 - uVar19 ^ uVar19 << 8;
          uVar33 = (-0x112410d - uVar19) - uVar15 ^ uVar15 >> 0xd;
          uVar19 = (uVar19 - uVar15) - uVar33 ^ uVar33 >> 0xc;
          uVar15 = (uVar15 - uVar33) - uVar19 ^ uVar19 << 0x10;
          uVar33 = (uVar33 - uVar19) - uVar15 ^ uVar15 >> 5;
          uVar19 = (uVar19 - uVar15) - uVar33 ^ uVar33 >> 3;
          pcVar18 = (char *)(uVar33 - uVar19);
          uVar19 = (uVar15 - uVar33) - uVar19 ^ uVar19 << 10;
          uVar19 = (int)pcVar18 - uVar19 ^ uVar19 >> 0xf;
          __ptr = stratum_shares;
          if (stratum_shares != (stratum_share *)0x0) {
            pUVar36 = (stratum_shares->hh).tbl;
            pUVar35 = pUVar36->buckets;
            uVar15 = pUVar36->num_buckets - 1 & uVar19;
            pcVar18 = (char *)(uVar15 * 3);
            __ptr = (stratum_share *)pUVar35[uVar15].hh_head;
            if (__ptr != (stratum_share *)0x0) {
              pcVar18 = (char *)pUVar36->hho;
              __ptr = (stratum_share *)((int)__ptr - (int)pcVar18);
            }
            for (; __ptr != (stratum_share *)0x0; __ptr = (stratum_share *)((int)__ptr - line_00)) {
              line_00 = (__ptr->hh).hashv;
              if (((uVar19 == line_00) &&
                  (pcVar18 = (char *)(__ptr->hh).keylen, pcVar18 == (char *)0x4)) &&
                 (iVar10 = memcmp((__ptr->hh).key,&id,4), iVar10 == 0)) {
                pvVar16 = (__ptr->hh).prev;
                psVar29 = (stratum_share *)(__ptr->hh).next;
                if ((pvVar16 == (void *)0x0) && (psVar29 == (stratum_share *)0x0)) {
                  free(pUVar35);
                  free((psVar6->hh).tbl);
                  stratum_shares = psVar29;
                }
                else {
                  iVar10 = pUVar36->hho;
                  psVar14 = (stratum_share *)((int)pUVar36->tail - iVar10);
                  bVar40 = __ptr == psVar14;
                  if (bVar40) {
                    psVar14 = (stratum_share *)((int)pvVar16 + iVar10);
                  }
                  if (bVar40) {
                    pUVar36->tail = &psVar14->hh;
                  }
                  psVar14 = psVar29;
                  psVar7 = psVar29;
                  if (pvVar16 != (void *)0x0) {
                    *(stratum_share **)((int)pvVar16 + iVar10 + 8) = psVar29;
                    psVar29 = (stratum_share *)(__ptr->hh).next;
                    psVar14 = psVar6;
                    psVar7 = stratum_shares;
                  }
                  stratum_shares = psVar7;
                  pUVar36 = (psVar14->hh).tbl;
                  if (psVar29 != (stratum_share *)0x0) {
                    *(void **)((int)&(psVar29->hh).prev + pUVar36->hho) = pvVar16;
                  }
                  pUVar35 = pUVar36->buckets;
                  uVar19 = uVar19 & pUVar36->num_buckets - 1;
                  pUVar21 = (__ptr->hh).hh_next;
                  if (__ptr == (stratum_share *)pUVar35[uVar19].hh_head) {
                    pUVar35[uVar19].hh_head = pUVar21;
                  }
                  pUVar17 = (__ptr->hh).hh_prev;
                  pUVar35[uVar19].count = pUVar35[uVar19].count - 1;
                  if (pUVar17 != (UT_hash_handle *)0x0) {
                    pUVar17->hh_next = pUVar21;
                    pUVar21 = (__ptr->hh).hh_next;
                  }
                  if (pUVar21 != (UT_hash_handle *)0x0) {
                    pUVar21->hh_prev = pUVar17;
                  }
                  pcVar18 = (char *)(pUVar36->num_items - 1);
                  pUVar36->num_items = (uint)pcVar18;
                }
                line_00 = *(int *)((int)userdata + 0x2dc) - 1;
                *(uint *)((int)userdata + 0x2dc) = line_00;
                break;
              }
              __ptr = (stratum_share *)(__ptr->hh).hh_next;
              if (__ptr == (stratum_share *)0x0) break;
              line_00 = pUVar36->hho;
            }
          }
          iVar10 = pthread_mutex_unlock(DAT_00026a04);
          if (iVar10 != 0) {
            _mutex_unlock_noyield((pthread_mutex_t *)DAT_00027630,(char *)0x1c12,pcVar18,line_00);
          }
          line_01 = *ppcVar3;
          (*line_01)();
          if (__ptr == (stratum_share *)0x0) {
            if (local_a80 != (json_t *)0x0) {
              iVar10 = pthread_mutex_lock((pthread_mutex_t *)((int)userdata + 0xd4));
              if (iVar10 != 0) {
                _mutex_lock((pthread_mutex_t *)DAT_00027630,(char *)0x1c1e,pcVar18,(int)line_01);
              }
              iVar10 = pthread_rwlock_rdlock((pthread_rwlock_t *)((int)userdata + 0xec));
              if (iVar10 != 0) {
                _rd_lock(DAT_00027630,(char *)0x1c1e,pcVar18,(int)line_01);
              }
              iVar10 = pthread_mutex_unlock((pthread_mutex_t *)((int)userdata + 0xd4));
              if (iVar10 != 0) {
                _mutex_unlock_noyield
                          ((pthread_mutex_t *)DAT_00027630,(char *)0x1c1e,pcVar18,(int)line_01);
              }
              pdVar30 = (double *)((int)userdata + 0x720);
              dVar41 = *pdVar30;
              iVar10 = pthread_rwlock_unlock((pthread_rwlock_t *)((int)userdata + 0xec));
              if (iVar10 != 0) {
                _rw_unlock(DAT_00027630,(char *)0x1c20,pcVar18,(int)pdVar30);
              }
              (**ppcVar3)();
              if (local_a80->type == JSON_TRUE) {
                if (((*DAT_0002732c != '\0') || (*DAT_00027618 != '\0')) ||
                   (iVar10 = *DAT_0002761c, pcVar18 = DAT_00027618, 4 < iVar10)) {
                    /* WARNING: Load size is inaccurate */
                  iVar10 = *userdata;
                  snprintf(tmp42,0x800,DAT_00027620);
                  pcVar18 = (char *)0x0;
                  _applog(5,tmp42,false);
                }
                iVar24 = pthread_mutex_lock(DAT_00027624);
                if (iVar24 != 0) {
                  _mutex_lock((pthread_mutex_t *)DAT_00027630,(char *)0x1c28,pcVar18,iVar10);
                }
                ppcVar25 = DAT_0002762c;
                pdVar30 = DAT_00027628;
                dVar42 = *DAT_00027628;
                uVar19 = *(uint *)((int)userdata + 8);
                pcVar20 = *DAT_0002762c;
                pcVar27 = DAT_0002762c[1];
                *(uint *)((int)userdata + 8) = uVar19 + 1;
                *(uint *)((int)userdata + 0xc) =
                     *(int *)((int)userdata + 0xc) + (uint)(0xfffffffe < uVar19);
                pcVar18 = pcVar20 + 1;
                pcVar27 = pcVar27 + ((char *)0xfffffffe < pcVar20);
                *(double *)((int)userdata + 0x48) = *(double *)((int)userdata + 0x48) + dVar41;
                ppVar4 = DAT_00027624;
                *pdVar30 = dVar41 + dVar42;
                *ppcVar25 = pcVar18;
                ppcVar25[1] = pcVar27;
                iVar10 = pthread_mutex_unlock(ppVar4);
                if (iVar10 != 0) {
                  _mutex_unlock_noyield
                            ((pthread_mutex_t *)DAT_00027630,(char *)0x1c2d,pcVar18,(int)pcVar27);
                }
              }
              else {
                if (((*DAT_0002732c != '\0') || (*DAT_00027330 != '\0')) ||
                   (iVar10 = *DAT_00027344, pcVar18 = DAT_00027330, 4 < iVar10)) {
                    /* WARNING: Load size is inaccurate */
                  iVar10 = *userdata;
                  snprintf(tmp42,0x800,DAT_00027334);
                  pcVar18 = (char *)0x0;
                  _applog(5,tmp42,false);
                }
                iVar24 = pthread_mutex_lock(DAT_00027338);
                if (iVar24 != 0) {
                  _mutex_lock((pthread_mutex_t *)DAT_00027630,(char *)0x1c33,pcVar18,iVar10);
                }
                ppcVar25 = DAT_00027340;
                pdVar30 = DAT_0002733c;
                dVar42 = *DAT_0002733c;
                uVar19 = *(uint *)((int)userdata + 0x10);
                pcVar20 = *DAT_00027340;
                pcVar27 = DAT_00027340[1];
                *(uint *)((int)userdata + 0x10) = uVar19 + 1;
                *(uint *)((int)userdata + 0x14) =
                     *(int *)((int)userdata + 0x14) + (uint)(0xfffffffe < uVar19);
                pcVar18 = pcVar20 + 1;
                pcVar27 = pcVar27 + ((char *)0xfffffffe < pcVar20);
                *(double *)((int)userdata + 0x50) = *(double *)((int)userdata + 0x50) + dVar41;
                ppVar4 = DAT_00027338;
                *pdVar30 = dVar41 + dVar42;
                *ppcVar25 = pcVar18;
                ppcVar25[1] = pcVar27;
                iVar10 = pthread_mutex_unlock(ppVar4);
                if (iVar10 != 0) {
                  _mutex_unlock_noyield
                            ((pthread_mutex_t *)DAT_00027630,(char *)0x1c38,pcVar18,(int)pcVar27);
                }
              }
              (**ppcVar3)();
            }
            goto LAB_00026f72;
          }
          work_00 = __ptr->work;
          tVar11 = time((time_t *)0x0);
          ptVar39 = (timeval *)(tVar11 - __ptr->sshare_sent);
          if (((opt_debug != false) || (0 < (int)ptVar39)) &&
             ((*DAT_00026a08 != '\0' || ((*DAT_00026a0c != '\0' || (5 < *DAT_00027344)))))) {
            snprintf(tmp42,0x800,DAT_00026a10,work_00->pool->pool_no);
            _applog(6,tmp42,false);
            in_stack_fffff558 = ptVar39;
          }
          dest = (uint *)tmp42;
          uVar19 = *(uint *)(work_00->hash + 0x1c);
          iVar10 = 0;
          uVar19 = uVar19 << 0x18 | (uVar19 >> 8 & 0xff) << 0x10 | (uVar19 >> 0x10 & 0xff) << 8 |
                   uVar19 >> 0x18;
          tmp42[0] = (char)uVar19;
          tmp42[1] = (char)(uVar19 >> 8);
          tmp42[2] = (char)(uVar19 >> 0x10);
          tmp42[3] = (char)(uVar19 >> 0x18);
          uVar19 = *(uint *)(work_00->hash + 0x18);
          uVar19 = uVar19 << 0x18 | (uVar19 >> 8 & 0xff) << 0x10 | (uVar19 >> 0x10 & 0xff) << 8 |
                   uVar19 >> 0x18;
          tmp42[4] = (char)uVar19;
          tmp42[5] = (char)(uVar19 >> 8);
          tmp42[6] = (char)(uVar19 >> 0x10);
          tmp42[7] = (char)(uVar19 >> 0x18);
          uVar19 = *(uint *)(work_00->hash + 0x14);
          uVar19 = uVar19 << 0x18 | (uVar19 >> 8 & 0xff) << 0x10 | (uVar19 >> 0x10 & 0xff) << 8 |
                   uVar19 >> 0x18;
          tmp42[8] = (char)uVar19;
          tmp42[9] = (char)(uVar19 >> 8);
          tmp42[10] = (char)(uVar19 >> 0x10);
          tmp42[11] = (char)(uVar19 >> 0x18);
          uVar19 = *(uint *)(work_00->hash + 0x10);
          uVar19 = uVar19 << 0x18 | (uVar19 >> 8 & 0xff) << 0x10 | (uVar19 >> 0x10 & 0xff) << 8 |
                   uVar19 >> 0x18;
          tmp42[12] = (char)uVar19;
          tmp42[13] = (char)(uVar19 >> 8);
          tmp42[14] = (char)(uVar19 >> 0x10);
          tmp42[15] = (char)(uVar19 >> 0x18);
          uVar19 = *(uint *)(work_00->hash + 0xc);
          uVar19 = uVar19 << 0x18 | (uVar19 >> 8 & 0xff) << 0x10 | (uVar19 >> 0x10 & 0xff) << 8 |
                   uVar19 >> 0x18;
          tmp42[16] = (char)uVar19;
          tmp42[17] = (char)(uVar19 >> 8);
          tmp42[18] = (char)(uVar19 >> 0x10);
          tmp42[19] = (char)(uVar19 >> 0x18);
          uVar19 = *(uint *)(work_00->hash + 8);
          uVar19 = uVar19 << 0x18 | (uVar19 >> 8 & 0xff) << 0x10 | (uVar19 >> 0x10 & 0xff) << 8 |
                   uVar19 >> 0x18;
          tmp42[20] = (char)uVar19;
          tmp42[21] = (char)(uVar19 >> 8);
          tmp42[22] = (char)(uVar19 >> 0x10);
          tmp42[23] = (char)(uVar19 >> 0x18);
          uVar19 = *(uint *)(work_00->hash + 4);
          uVar19 = uVar19 << 0x18 | (uVar19 >> 8 & 0xff) << 0x10 | (uVar19 >> 0x10 & 0xff) << 8 |
                   uVar19 >> 0x18;
          tmp42[24] = (char)uVar19;
          tmp42[25] = (char)(uVar19 >> 8);
          tmp42[26] = (char)(uVar19 >> 0x10);
          tmp42[27] = (char)(uVar19 >> 0x18);
          uVar19 = *(uint *)work_00->hash;
          uVar19 = uVar19 << 0x18 | (uVar19 >> 8 & 0xff) << 0x10 | (uVar19 >> 0x10 & 0xff) << 8 |
                   uVar19 >> 0x18;
          tmp42[28] = (char)uVar19;
          tmp42[29] = (char)(uVar19 >> 8);
          tmp42[30] = (char)(uVar19 >> 0x10);
          tmp42[31] = (char)(uVar19 >> 0x18);
          do {
            if (*(char *)((int)dest + iVar10) != '\0') break;
            iVar10 = iVar10 + 1;
          } while (iVar10 != 0x1d);
          uVar19 = *(uint *)((int)dest + iVar10);
          dVar41 = round((double)CONCAT44(in_stack_fffff55c,in_stack_fffff558));
          __fixunsdfdi(SUB84(dVar41,0),(int)((ulonglong)dVar41 >> 0x20));
          suffix_string((ulonglong)in_stack_fffff55c << 0x20,*(char **)&work_00->share_diff,
                        *(size_t *)((int)&work_00->share_diff + 4),(int)disposition);
          in_stack_fffff558 = (timeval *)disposition;
          pcVar18 = DAT_00026d54;
          snprintf(hashshow,0x40,DAT_00026d54,
                   uVar19 << 0x18 | (uVar19 >> 8 & 0xff) << 0x10 | (uVar19 >> 0x10 & 0xff) << 8 |
                   uVar19 >> 0x18);
          ppVar37 = work_00->pool;
          line_02 = work_00;
          ptVar12 = get_thread(work_00->thr_id);
          pcVar38 = ptVar12->cgpu;
          if ((local_a80 == (json_t *)0x0) ||
             ((line_02 = (work *)local_a80->type, line_02 != (work *)0x5 &&
              ((pcVar18 = (char *)(uint)work_00->gbt, pcVar18 == (char *)0x0 ||
               (line_02 != (work *)0x7)))))) {
            iVar10 = pthread_mutex_lock(DAT_00026d58);
            if (iVar10 != 0) {
              _mutex_lock(DAT_00027634,(char *)0xdb3,pcVar18,(int)line_02);
            }
            ppcVar25 = DAT_00026dac;
            pdVar30 = DAT_00026d5c;
            dVar42 = pcVar38->diff_rejected;
            dVar44 = work_00->work_difficulty;
            dVar43 = ppVar37->diff_rejected;
            uVar19 = *(uint *)&ppVar37->rejected;
            iVar24 = *(int *)((int)&ppVar37->rejected + 4);
            dVar41 = *DAT_00026d5c;
            iVar10 = ppVar37->seq_rejects;
            pcVar38->rejected = pcVar38->rejected + 1;
            *(uint *)&ppVar37->rejected = uVar19 + 1;
            *(uint *)((int)&ppVar37->rejected + 4) = iVar24 + (uint)(0xfffffffe < uVar19);
            pcVar18 = *ppcVar25;
            pcVar27 = ppcVar25[1];
            pcVar38->diff_rejected = dVar42 + dVar44;
            pcVar20 = pcVar18 + 1;
            ppVar37->seq_rejects = iVar10 + 1;
            pcVar27 = pcVar27 + ((char *)0xfffffffe < pcVar18);
            ppVar37->diff_rejected = dVar43 + dVar44;
            ppVar4 = DAT_00026d58;
            *pdVar30 = dVar44 + dVar41;
            *ppcVar25 = pcVar20;
            ppcVar25[1] = pcVar27;
            iVar10 = pthread_mutex_unlock(ppVar4);
            if (iVar10 != 0) {
              _mutex_unlock_noyield(DAT_00027634,(char *)0xdbb,pcVar20,(int)pcVar27);
            }
            (**ppcVar3)();
            if ((opt_debug != false) &&
               (((*DAT_00026d60 != '\0' || (*DAT_00026d64 != '\0')) || (6 < *DAT_00027344)))) {
              tmp42._0_4_ = *DAT_00026db0;
              tmp42._4_4_ = DAT_00026db0[1];
              tmp42._8_4_ = DAT_00026db0[2];
              tmp42._12_4_ = DAT_00026db0[3];
              tmp42._16_4_ = DAT_00026db0[4];
              tmp42._20_4_ = DAT_00026db0[5];
              tmp42._24_4_ = DAT_00026db0[6];
              tmp42._28_4_ = DAT_00026db0[7];
              tmp42._32_4_ = DAT_00026db0[8];
              tmp42[36] = (char)DAT_00026db0[9];
              _applog(7,(char *)dest,false);
            }
            if ((*DAT_00026d68 == '\0') && (cVar1 = *DAT_00026d6c, cVar1 == '\0')) {
              disposition._0_4_ = *DAT_00026d70;
              disposition._4_2_ = (undefined2)DAT_00026d70[1];
              disposition[6] = (char)((uint)DAT_00026d70[1] >> 0x10);
              memset(disposition + 7,0,0x1d);
              reason[0] = cVar1;
              if (*DAT_00026d74 < 2) {
                where[0] = '\0';
              }
              else {
                snprintf(where,0x14,DAT_00026d78,work_00->pool->pool_no);
              }
              local_a74 = where;
              if (work_00->gbt == false) {
                local_a80 = json_object_get(json,DAT_00026d7c);
              }
              if (local_a80 == (json_t *)0x0) {
                if ((work_00->stratum != false) && (json_00 != (json_t *)0x0)) {
                  jVar26 = json_00->type;
                  if (jVar26 == JSON_ARRAY) {
                    json_00 = json_array_get(json_00,1);
                    if (json_00 == (json_t *)0x0) goto LAB_00026c6a;
                    jVar26 = json_00->type;
                  }
                  if (jVar26 == JSON_STRING) {
                    pcVar18 = json_string_value(json_00);
                    snprintf(reason,0x1f,DAT_00027614,pcVar18);
                  }
                }
              }
              else {
                pcVar18 = json_string_value(local_a80);
                reasontmp = (char *)strlen(pcVar18);
                if ((char *)0x1b < reasontmp) {
                  reasontmp = (char *)0x1c;
                }
                reason[0] = ' ';
                reason[1] = '(';
                _cg_memcpy(reason + 2,pcVar18,(uint)reasontmp,DAT_00026d84,(char *)DAT_00026d80,
                           0xde3);
                in_stack_fffff55c = 0xde8;
                (reason + 2)[(int)reasontmp] = ')';
                (reason + 3)[(int)reasontmp] = '\0';
                in_stack_fffff558 = DAT_00026d80;
                _cg_memcpy(disposition + 7,pcVar18,(uint)reasontmp,DAT_00026d84,(char *)DAT_00026d80
                           ,0xde8);
                disposition[6] = ':';
                (disposition + 7)[(int)reasontmp] = '\0';
              }
LAB_00026c6a:
              if (((*DAT_00026d60 != '\0') || (*DAT_00026d64 != '\0')) || (4 < *DAT_00026d88)) {
                in_stack_fffff558 = (timeval *)pcVar38->drv->name;
                in_stack_fffff55c = pcVar38->device_id;
                snprintf((char *)dest,0x800,DAT_00026d8c,hashshow,in_stack_fffff558,
                         in_stack_fffff55c,local_a74,reason,DAT_00026da4,DAT_00026da4);
                _applog(5,(char *)dest,false);
              }
              sharelog(disposition,work_00);
            }
            piVar5 = DAT_00026d94;
            ptVar39 = (timeval *)ppVar37->seq_rejects;
            if (((10 < (int)ptVar39) && (work_00->stale == false)) &&
               ((*DAT_00026d90 != '\0' && (1 < *DAT_00026d94)))) {
              dVar42 = (double)(longlong)(int)ptVar39;
              dVar41 = (double)__aeabi_l2d(*DAT_00026d98,DAT_00026d98[1]);
              dVar41 = (dVar41 / *DAT_00026d9c) * dVar2 * 3.0;
              if (dVar42 != dVar41 && dVar42 < dVar41 == (NAN(dVar42) || NAN(dVar41))) {
                if (((*DAT_00026d60 != '\0') || (*DAT_00026d64 != '\0')) || (3 < *DAT_00026d88)) {
                  snprintf((char *)dest,0x800,DAT_00026da0,ppVar37->pool_no);
                  _applog(4,(char *)dest,false);
                  in_stack_fffff558 = ptVar39;
                }
                if (ppVar37->enabled == POOL_ENABLED) {
                  *piVar5 = *piVar5 + -1;
                }
                ppVar37->enabled = POOL_REJECTING;
                ppVar13 = current_pool();
                if (ppVar37 == ppVar13) {
                  switch_pools((pool *)0x0);
                }
                ppVar37->seq_rejects = 0;
              }
            }
          }
          else {
            iVar10 = pthread_mutex_lock(DAT_00027338);
            if (iVar10 != 0) {
              _mutex_lock(DAT_00027634,(char *)0xd74,pcVar18,(int)line_02);
            }
            ppcVar25 = DAT_00027348;
            uVar19 = *(uint *)&ppVar37->accepted;
            iVar10 = *(int *)((int)&ppVar37->accepted + 4);
            dVar41 = pcVar38->diff_accepted;
            dVar43 = work_00->work_difficulty;
            dVar42 = ppVar37->diff_accepted;
            pcVar38->accepted = pcVar38->accepted + 1;
            *(uint *)&ppVar37->accepted = uVar19 + 1;
            *(uint *)((int)&ppVar37->accepted + 4) = iVar10 + (uint)(0xfffffffe < uVar19);
            pcVar18 = *ppcVar25;
            pcVar27 = ppcVar25[1];
            total_diff_accepted = dVar43 + total_diff_accepted;
            pcVar38->diff_accepted = dVar41 + dVar43;
            pcVar20 = pcVar18 + 1;
            ppVar37->diff_accepted = dVar42 + dVar43;
            ppVar4 = DAT_00027338;
            pcVar27 = pcVar27 + ((char *)0xfffffffe < pcVar18);
            *ppcVar25 = pcVar20;
            ppcVar25[1] = pcVar27;
            iVar10 = pthread_mutex_unlock(ppVar4);
            if (iVar10 != 0) {
              _mutex_unlock_noyield(DAT_00027634,(char *)0xd7e,pcVar20,(int)pcVar27);
            }
            (**ppcVar3)();
            ppVar37->seq_rejects = 0;
            pcVar38->last_share_pool = ppVar37->pool_no;
            tVar11 = time((time_t *)0x0);
            _Var8 = opt_debug;
            uVar22 = *(undefined4 *)&work_00->work_difficulty;
            uVar31 = *(undefined4 *)((int)&work_00->work_difficulty + 4);
            pcVar38->last_share_pool_time = tVar11;
            *(undefined4 *)&pcVar38->last_share_diff = uVar22;
            *(undefined4 *)((int)&pcVar38->last_share_diff + 4) = uVar31;
            ppVar37->last_share_time = tVar11;
            *(undefined4 *)&ppVar37->last_share_diff = uVar22;
            *(undefined4 *)((int)&ppVar37->last_share_diff + 4) = uVar31;
            if ((_Var8 != false) &&
               (((*DAT_0002732c != '\0' || (*DAT_00027330 != '\0')) || (6 < *DAT_00027344)))) {
              tmp42._0_4_ = *DAT_00027368;
              tmp42._4_4_ = DAT_00027368[1];
              tmp42._8_4_ = DAT_00027368[2];
              tmp42._12_4_ = DAT_00027368[3];
              tmp42._16_4_ = DAT_00027368[4];
              tmp42._20_4_ = DAT_00027368[5];
              tmp42._24_4_ = DAT_00027368[6];
              tmp42._28_4_ = DAT_00027368[7];
              tmp42._32_4_ = DAT_00027368[8];
              _applog(7,(char *)dest,false);
            }
            if ((*DAT_0002734c == '\0') && (*DAT_00027350 == '\0')) {
              if (*DAT_00027354 < 2) {
                if (((*DAT_0002732c != '\0') || (*DAT_00027618 != '\0')) || (4 < *DAT_0002761c)) {
                  in_stack_fffff558 = (timeval *)pcVar38->drv->name;
                  in_stack_fffff55c = pcVar38->device_id;
                  snprintf((char *)dest,0x800,DAT_00027638,hashshow,in_stack_fffff558,
                           in_stack_fffff55c,DAT_00027650,DAT_00027650);
                  _applog(5,(char *)dest,false);
                }
              }
              else if (((*DAT_0002732c != '\0') || (*DAT_00027330 != '\0')) || (4 < *DAT_00027344))
              {
                in_stack_fffff558 = (timeval *)pcVar38->drv->name;
                in_stack_fffff55c = pcVar38->device_id;
                snprintf((char *)dest,0x800,DAT_00027358,hashshow,in_stack_fffff558,
                         in_stack_fffff55c,work_00->pool->pool_no,DAT_0002736c,DAT_0002736c);
                _applog(5,(char *)dest,false);
              }
            }
            sharelog(DAT_0002735c,work_00);
            if ((opt_shares == 0) || (total_diff_accepted < (double)(longlong)opt_shares)) {
              if (ppVar37->enabled == POOL_REJECTING) {
                if (((*DAT_0002763c == '\0') && (*DAT_00027618 == '\0')) && (*DAT_0002761c < 4)) {
LAB_00027500:
                  piVar5 = DAT_00027640;
                  ppVar37->enabled = POOL_ENABLED;
                  *piVar5 = *piVar5 + 1;
                }
                else {
                  snprintf((char *)dest,0x800,DAT_00027644,ppVar37->pool_no);
                  _applog(4,(char *)dest,false);
                  if (ppVar37->enabled != POOL_ENABLED) goto LAB_00027500;
                }
                switch_pools((pool *)0x0);
              }
              if (work_00->block != false) {
                restart_threads();
              }
            }
            else {
              if (((*DAT_0002732c != '\0') || (*DAT_00027330 != '\0')) || (3 < *DAT_00027344)) {
                snprintf((char *)dest,0x800,DAT_00027360);
                _applog(4,(char *)dest,false);
              }
              kill_work();
            }
          }
          pcVar18 = DAT_00026ff0;
          _free_work(&__ptr->work,DAT_00026fec,DAT_00026ff0,0x1c3f);
          bVar40 = true;
          free(__ptr);
          sVar28 = json->refcount;
          if (sVar28 != 0xffffffff) goto LAB_00026f7c;
LAB_00026dfc:
          if (bVar40) goto LAB_0002667c;
        }
        cVar1 = *DAT_00026ff4;
LAB_00026e06:
        if (cVar1 == '\0') goto LAB_00026e0a;
      }
      snprintf(tmp42,0x800,DAT_00027000,pcVar9);
      pcVar18 = (char *)0x0;
      _applog(6,tmp42,false);
    }
LAB_00026686:
    free(pcVar9);
  } while( true );
}

