
/* WARNING: Unknown calling convention */

void * stratum_sthread(void *userdata)

{
  char cVar1;
  byte *pbVar2;
  char **ppcVar3;
  char *pcVar4;
  pthread_mutex_t *ppVar5;
  char *pcVar6;
  uint *puVar7;
  _Bool _Var8;
  pool *pool;
  thread_q *ptVar9;
  uint uVar10;
  int iVar11;
  int **__ptr;
  stratum_share *sshare;
  int *piVar12;
  time_t tVar13;
  char *pcVar14;
  void *pvVar15;
  UT_hash_bucket *_he_new_buckets;
  void *pvVar16;
  undefined4 uVar17;
  int ssdiff;
  int iVar18;
  char *pcVar19;
  char *pcVar20;
  uint uVar21;
  void *pvVar22;
  work *line;
  int *piVar23;
  void *pvVar24;
  int iVar25;
  work *pwVar26;
  int iVar27;
  int **ppiVar28;
  size_t __size;
  UT_hash_handle *_he_thh;
  _Bool sessionid_match;
  int iVar29;
  uint uVar30;
  uint uVar31;
  UT_hash_bucket *_he_newbkt;
  UT_hash_handle *_he_hh_nxt;
  void **ppvVar32;
  int local_c8c;
  void *local_c84;
  uint nonce;
  work *work;
  uchar nonce2 [8];
  char noncehex [12];
  char threadname [16];
  char nonce2hex [20];
  char s [1024];
  char tmp42 [2048];
  
  pool = (pool *)pthread_self();
  pthread_detach((pthread_t)pool);
                    /* WARNING: Load size is inaccurate */
  snprintf(threadname,0x10,DAT_0002791c,*userdata);
  RenameThread(threadname);
  ptVar9 = tq_new();
  *(thread_q **)((int)userdata + 0x2d8) = ptVar9;
  if (ptVar9 == (thread_q *)0x0) {
    tmp42._0_4_ = *DAT_00027920;
    tmp42._4_4_ = DAT_00027920[1];
    tmp42._8_4_ = DAT_00027920[2];
    tmp42._12_4_ = DAT_00027920[3];
    tmp42._16_4_ = DAT_00027920[4];
    tmp42._20_4_ = DAT_00027920[5];
    tmp42._24_4_ = DAT_00027920[6];
    tmp42._28_4_ = DAT_00027920[7];
    tmp42._32_4_ = DAT_00027920[8];
    tmp42._36_4_ = DAT_00027920[9];
    tmp42._40_4_ = DAT_00027920[10];
    tmp42[44] = (char)(short)DAT_00027920[0xb];
    tmp42[45] = (char)((ushort)(short)DAT_00027920[0xb] >> 8);
    _applog(3,tmp42,true);
    _quit(1);
  }
  uVar31 = 0;
  iVar27 = 0;
  iVar29 = 0;
LAB_000276bc:
  do {
    cVar1 = *(char *)((int)userdata + 0x69);
    while( true ) {
      if (cVar1 != '\0') {
        tq_freeze(*(thread_q **)((int)userdata + 0x2d8));
        return (void *)0x0;
      }
      work = (work *)tq_pop(*(thread_q **)((int)userdata + 0x2d8),(timespec *)0x0);
      if (work == (work *)0x0) {
        tmp42._0_4_ = *DAT_00027fa4;
        tmp42._4_4_ = DAT_00027fa4[1];
        tmp42._8_4_ = DAT_00027fa4[2];
        tmp42._12_4_ = DAT_00027fa4[3];
        tmp42._16_4_ = DAT_00027fa4[4];
        tmp42._20_4_ = DAT_00027fa4[5];
        tmp42._24_4_ = DAT_00027fa4[6];
        tmp42[28] = (char)(short)DAT_00027fa4[7];
        tmp42[29] = (char)((ushort)(short)DAT_00027fa4[7] >> 8);
        _applog(3,tmp42,true);
        _quit(1);
      }
      pcVar19 = DAT_00027f90;
      if (8 < work->nonce2_len) {
        if (((*DAT_00027f90 != '\0') || (*DAT_00027f7c != '\0')) || (2 < *DAT_00027f80)) {
                    /* WARNING: Load size is inaccurate */
          snprintf(tmp42,0x800,DAT_00027f94,*userdata,work->nonce2_len);
          _applog(3,tmp42,false);
          if (((*pcVar19 != '\0') || (*DAT_00027f7c != '\0')) || (2 < *DAT_00027f80)) {
            tmp42._0_4_ = *DAT_00027fa0;
            tmp42._4_4_ = DAT_00027fa0[1];
            tmp42._8_4_ = DAT_00027fa0[2];
            tmp42._12_4_ = DAT_00027fa0[3];
            tmp42._16_4_ = DAT_00027fa0[4];
            tmp42._20_4_ = DAT_00027fa0[5];
            tmp42._24_4_ = DAT_00027fa0[6];
            tmp42._28_4_ = DAT_00027fa0[7];
            _applog(3,tmp42,false);
          }
        }
        _free_work(&work,DAT_00027f98,DAT_00027f74->__size,0x1d72);
        goto LAB_000276bc;
      }
      uVar10 = *(uint *)(work->data + 0x4c);
      iVar11 = *(int *)&work->nonce2;
      iVar18 = *(int *)((int)&work->nonce2 + 4);
      nonce = uVar10;
      nonce2._0_4_ = iVar11;
      nonce2._4_4_ = iVar18;
      if ((uVar31 == uVar10) && (iVar29 == iVar18 && iVar27 == iVar11)) break;
      __bin2hex(noncehex,(uchar *)&nonce,4);
      __bin2hex(nonce2hex,nonce2,work->nonce2_len);
      __ptr = (int **)_cgcalloc(0x34,1,DAT_00027924,DAT_00027928,0x1d87);
      pwVar26 = work;
      piVar12 = (int *)time((time_t *)0x0);
      pcVar19 = (char *)0x400;
      __ptr[0xb] = piVar12;
      __ptr[9] = (int *)work;
      line = work;
      memset(s,0,0x400);
      iVar27 = pthread_mutex_lock(DAT_0002792c);
      if (iVar27 != 0) {
        _mutex_lock((pthread_mutex_t *)DAT_00027f74,(char *)0x1d90,pcVar19,(int)line);
      }
      ppVar5 = DAT_0002792c;
      __ptr[10] = (int *)swork_id;
      iVar29 = swork_id + 1;
      swork_id = iVar29;
      iVar27 = pthread_mutex_unlock(ppVar5);
      if (iVar27 != 0) {
        _mutex_unlock_noyield((pthread_mutex_t *)DAT_00027f74,(char *)0x1d93,pcVar19,iVar29);
      }
      (*selective_yield)();
      if (*(char *)((int)userdata + 0x284) == '\0') {
        pcVar19 = nonce2hex;
        pcVar14 = noncehex;
        pcVar20 = work->ntime;
        piVar12 = __ptr[10];
        snprintf(s,0x400,DAT_00027cc0,*(undefined4 *)((int)userdata + 0xac),work->job_id,pcVar19,
                 pcVar20,pcVar14,piVar12);
      }
      else {
        pcVar19 = nonce2hex;
        uVar31 = work->version;
        pcVar14 = noncehex;
        pcVar20 = work->ntime;
        piVar12 = (int *)(uVar31 << 0x18 | (uVar31 >> 8 & 0xff) << 0x10 |
                          (uVar31 >> 0x10 & 0xff) << 8 | uVar31 >> 0x18);
        snprintf(s,0x400,DAT_00027930,*(undefined4 *)((int)userdata + 0xac),work->job_id,pcVar19,
                 pcVar20,pcVar14,piVar12,__ptr[10]);
      }
      pcVar6 = DAT_00027934;
      if (((*DAT_00027934 != '\0') || (*DAT_00027938 != '\0')) ||
         (pbVar2 = DAT_00027948, ppcVar3 = DAT_00027944, piVar23 = DAT_0002793c,
         pcVar4 = DAT_00027938, 5 < *DAT_0002793c)) {
                    /* WARNING: Load size is inaccurate */
        snprintf(tmp42,0x800,DAT_00027940,*(undefined4 *)(pwVar26->hash + 0x18),*userdata,pcVar19,
                 pcVar20,pcVar14,piVar12);
        _applog(6,tmp42,false);
        pbVar2 = DAT_00027948;
        ppcVar3 = DAT_00027944;
        piVar23 = DAT_0002793c;
        pcVar4 = DAT_00027938;
      }
LAB_00027806:
      piVar12 = __ptr[0xb];
      iVar27 = (int)piVar12 + 0x77;
      tVar13 = time((time_t *)0x0);
      pcVar19 = DAT_00027cb4;
      if (tVar13 <= iVar27) {
        pcVar14 = (char *)strlen(s);
        _Var8 = stratum_send((pool *)userdata,s,(ssize_t)pcVar14);
        if (_Var8) {
          iVar27 = pthread_mutex_lock(DAT_0002792c);
          if (iVar27 != 0) {
            _mutex_lock(DAT_00027cc8,(char *)0x1db7,pcVar14,(int)piVar12);
          }
          iVar27 = DAT_0002794c;
          uVar31 = *(byte *)(__ptr + 10) + 0x112410d +
                   (uint)*(byte *)((int)__ptr + 0x2b) * 0x1000000 +
                   (uint)*(byte *)((int)__ptr + 0x2a) * 0x10000 +
                   (uint)*(byte *)((int)__ptr + 0x29) * 0x100 ^ 0x7f76d;
          uVar21 = 0x9f49bac6 - uVar31 ^ uVar31 << 8;
          __ptr[5] = (int *)(__ptr + 10);
          ppiVar28 = *(int ***)(iVar27 + 0x480);
          uVar30 = (-0x112410d - uVar31) - uVar21 ^ uVar21 >> 0xd;
          __ptr[6] = (int *)0x4;
          uVar31 = (uVar31 - uVar21) - uVar30 ^ uVar30 >> 0xc;
          uVar21 = (uVar21 - uVar30) - uVar31 ^ uVar31 << 0x10;
          uVar30 = (uVar30 - uVar31) - uVar21 ^ uVar21 >> 5;
          uVar31 = (uVar31 - uVar21) - uVar30 ^ uVar30 >> 3;
          uVar21 = (uVar21 - uVar30) - uVar31 ^ uVar31 << 10;
          piVar12 = (int *)((uVar30 - uVar31) - uVar21 ^ uVar21 >> 0xf);
          __ptr[7] = piVar12;
          if (ppiVar28 == (int **)0x0) {
            __ptr[2] = (int *)0x0;
            __ptr[1] = (int *)0x0;
            *(int ***)(iVar27 + 0x480) = __ptr;
            piVar23 = (int *)malloc(0x2c);
            *__ptr = piVar23;
            if (piVar23 == (int *)0x0) goto LAB_00027e4c;
            *piVar23 = 0;
            piVar23[1] = 0;
            piVar23[2] = 0;
            piVar23[3] = 0;
            piVar23[4] = 0;
            piVar23[5] = 0;
            piVar23[6] = 0;
            piVar23[7] = 0;
            piVar23[8] = 0;
            piVar23[9] = 0;
            piVar23[10] = 0;
            ppvVar32 = (void **)*__ptr;
            ppvVar32[4] = __ptr;
            ppvVar32[5] = (void *)0x0;
            ppvVar32[1] = (void *)0x20;
            ppvVar32[2] = (void *)0x5;
            pvVar15 = malloc(0x180);
            *ppvVar32 = pvVar15;
            if (pvVar15 == (void *)0x0) goto LAB_00027e4c;
            memset(pvVar15,0,0x180);
            piVar23 = *__ptr;
            piVar23[10] = -0x5feee01f;
          }
          else {
            piVar23 = *ppiVar28;
            __ptr[2] = (int *)0x0;
            *__ptr = piVar23;
            piVar23 = *ppiVar28;
            iVar27 = piVar23[4];
            iVar29 = piVar23[5];
            *(int ***)(iVar27 + 8) = __ptr;
            __ptr[1] = (int *)(iVar27 - iVar29);
            piVar23[4] = (int)__ptr;
          }
          iVar27 = *piVar23;
          uVar21 = (uint)piVar12 & piVar23[1] - 1U;
          piVar23[3] = piVar23[3] + 1;
          iVar29 = iVar27 + uVar21 * 0xc;
          piVar12 = *(int **)(iVar27 + uVar21 * 0xc);
          uVar31 = *(int *)(iVar29 + 4) + 1;
          *(uint *)(iVar29 + 4) = uVar31;
          __ptr[4] = piVar12;
          __ptr[3] = (int *)0x0;
          if (piVar12 != (int *)0x0) {
            piVar12[3] = (int)__ptr;
          }
          iVar29 = *(int *)(iVar29 + 8) + 1;
          pcVar19 = (char *)(iVar29 * 5);
          *(int ***)(iVar27 + uVar21 * 0xc) = __ptr;
          if ((uint)(iVar29 * 10) <= uVar31) {
            pcVar19 = (char *)(*__ptr)[9];
            if (pcVar19 != (char *)0x1) {
              __size = (*__ptr)[1] * 0x18;
              pvVar15 = malloc(__size);
              if (pvVar15 == (void *)0x0) {
LAB_00027e4c:
                    /* WARNING: Subroutine does not return */
                exit(-1);
              }
              memset(pvVar15,0,__size);
              ppvVar32 = (void **)*__ptr;
              pvVar24 = ppvVar32[1];
              ppvVar32[7] = (void *)0x0;
              pvVar22 = (void *)((uint)ppvVar32[3] >> ((int)ppvVar32[2] + 1U & 0xff));
              uVar31 = (int)pvVar24 * 2 - 1;
              if ((uVar31 & (uint)ppvVar32[3]) != 0) {
                pvVar22 = (void *)((int)pvVar22 + 1);
              }
              ppvVar32[6] = pvVar22;
              if (pvVar24 == (void *)0x0) {
                local_c84 = *ppvVar32;
              }
              else {
                local_c84 = *ppvVar32;
                local_c8c = 0;
                do {
                  iVar27 = *(int *)((int)local_c84 + local_c8c);
                  while (iVar27 != 0) {
                    iVar29 = *(int *)(iVar27 + 0x10);
                    uVar21 = uVar31 & *(uint *)(iVar27 + 0x1c);
                    pvVar16 = (void *)(*(int *)((int)pvVar15 + uVar21 * 0xc + 4) + 1);
                    *(void **)((int)pvVar15 + uVar21 * 0xc + 4) = pvVar16;
                    if (pvVar22 < pvVar16) {
                      ppvVar32[7] = (void *)((int)ppvVar32[7] + 1);
                      uVar17 = __aeabi_uidiv(pvVar16,pvVar22);
                      *(undefined4 *)((int)pvVar15 + uVar21 * 0xc + 8) = uVar17;
                    }
                    iVar25 = *(int *)((int)pvVar15 + uVar21 * 0xc);
                    *(undefined4 *)(iVar27 + 0xc) = 0;
                    *(int *)(iVar27 + 0x10) = iVar25;
                    if (iVar25 != 0) {
                      *(int *)(iVar25 + 0xc) = iVar27;
                    }
                    *(int *)((int)pvVar15 + uVar21 * 0xc) = iVar27;
                    iVar27 = iVar29;
                  }
                  local_c8c = local_c8c + 0xc;
                } while (local_c8c != (int)pvVar24 * 0xc);
              }
              free(local_c84);
              ppvVar32 = (void **)*__ptr;
              pvVar22 = ppvVar32[7];
              pcVar19 = (char *)ppvVar32[3];
              *ppvVar32 = pvVar15;
              ppvVar32[2] = (void *)((int)ppvVar32[2] + 1);
              pvVar15 = pvVar22;
              if (pvVar22 <= (void *)((uint)pcVar19 >> 1)) {
                pvVar15 = (void *)0x0;
              }
              ppvVar32[1] = (void *)((int)ppvVar32[1] << 1);
              if ((void *)((uint)pcVar19 >> 1) < pvVar22) {
                pvVar22 = (void *)((int)ppvVar32[8] + 1);
                ppvVar32[8] = pvVar22;
                pvVar15 = pvVar22;
                if ((void *)0x1 < pvVar22) {
                  pvVar15 = (void *)0x1;
                }
                if ((void *)0x1 < pvVar22) {
                  ppvVar32[9] = pvVar15;
                }
              }
              else {
                ppvVar32[8] = pvVar15;
              }
            }
          }
          ppVar5 = DAT_00027ca4;
          iVar29 = *(int *)((int)userdata + 0x2dc) + 1;
          *(int *)((int)userdata + 0x2dc) = iVar29;
          iVar27 = pthread_mutex_unlock(ppVar5);
          if (iVar27 != 0) {
            _mutex_unlock_noyield((pthread_mutex_t *)DAT_00027f74,(char *)0x1dba,pcVar19,iVar29);
          }
          (*selective_yield)();
          _Var8 = pool_tclear((pool *)userdata,(_Bool *)((int)userdata + 0x60));
          if ((_Var8) && (((*pcVar6 != '\0' || (*DAT_00027ca8 != '\0')) || (3 < *DAT_00027cac)))) {
                    /* WARNING: Load size is inaccurate */
            snprintf(tmp42,0x800,DAT_00027cb0,*userdata);
            _applog(4,tmp42,false);
          }
          pcVar19 = DAT_00027cb4;
          if ((*DAT_00027cb4 != '\0') &&
             (((*pcVar6 != '\0' || (*DAT_00027ca8 != '\0')) || (6 < *DAT_00027cac)))) {
            tmp42._0_4_ = *DAT_00027cb8;
            tmp42._4_4_ = DAT_00027cb8[1];
            tmp42._8_4_ = DAT_00027cb8[2];
            tmp42._12_4_ = DAT_00027cb8[3];
            tmp42._16_4_ = DAT_00027cb8[4];
            tmp42._20_4_ = DAT_00027cb8[5];
            tmp42._24_4_ = DAT_00027cb8[6];
            tmp42._28_4_ = DAT_00027cb8[7];
            tmp42._32_4_ = DAT_00027cb8[8];
            tmp42._36_4_ = DAT_00027cb8[9];
            tmp42._40_4_ = DAT_00027cb8[10];
            tmp42._44_4_ = DAT_00027cb8[0xb];
            tmp42._48_4_ = DAT_00027cb8[0xc];
            _applog(7,tmp42,false);
          }
          piVar12 = (int *)time((time_t *)0x0);
          cVar1 = *pcVar19;
          __ptr[0xc] = piVar12;
          if (((cVar1 != '\0') || (0 < (int)piVar12 - (int)__ptr[0xb])) &&
             ((*pcVar6 != '\0' || ((*DAT_00027ca8 != '\0' || (5 < *DAT_00027cac)))))) {
                    /* WARNING: Load size is inaccurate */
            snprintf(tmp42,0x800,DAT_00027cbc,*userdata,(int)piVar12 - (int)__ptr[0xb]);
            _applog(6,tmp42,false);
          }
          goto LAB_00027b54;
        }
        _Var8 = pool_tset((pool *)userdata,(_Bool *)((int)userdata + 0x60));
        if ((!_Var8) && (_Var8 = cnx_needed((pool *)userdata), _Var8)) {
          if ((*pcVar6 != '\0') || ((*pcVar4 != '\0' || (3 < *piVar23)))) {
                    /* WARNING: Load size is inaccurate */
            snprintf(tmp42,0x800,DAT_00027f88,*userdata);
            _applog(4,tmp42,false);
          }
          iVar27 = *(int *)((int)userdata + 0x84);
          pcVar14 = *ppcVar3 + 1;
          *ppcVar3 = pcVar14;
          *(int *)((int)userdata + 0x84) = iVar27 + 1;
        }
        pcVar19 = DAT_00027f78;
        pwVar26 = (work *)(uint)*pbVar2;
        if (pwVar26 == (work *)0x0) {
          iVar27 = pthread_mutex_lock((pthread_mutex_t *)((int)userdata + 0xd4));
          if (iVar27 != 0) {
            _mutex_lock((pthread_mutex_t *)DAT_00027f74,(char *)0x1dd0,pcVar14,(int)pwVar26);
          }
          iVar27 = pthread_rwlock_rdlock((pthread_rwlock_t *)((int)userdata + 0xec));
          if (iVar27 != 0) {
            _rd_lock(DAT_00027f74,(char *)0x1dd0,pcVar14,(int)pwVar26);
          }
          iVar27 = pthread_mutex_unlock((pthread_mutex_t *)((int)userdata + 0xd4));
          if (iVar27 != 0) {
            _mutex_unlock_noyield
                      ((pthread_mutex_t *)DAT_00027f74,(char *)0x1dd0,pcVar14,(int)pwVar26);
          }
          pcVar20 = *(char **)((int)userdata + 0x264);
          if (pcVar20 != (char *)0x0) {
            pwVar26 = work;
            uVar31 = strcmp(work->nonce1,pcVar20);
            pcVar20 = (char *)(1 - uVar31);
            if (1 < uVar31) {
              pcVar20 = (char *)0x0;
            }
          }
          iVar27 = pthread_rwlock_unlock((pthread_rwlock_t *)((int)userdata + 0xec));
          if (iVar27 != 0) {
            _rw_unlock(DAT_00027f74,(char *)0x1dd2,pcVar14,(int)pwVar26);
          }
          (*selective_yield)();
          pcVar19 = DAT_00027f78;
          if (pcVar20 != (char *)0x0) goto code_r0x00027d68;
          if (*DAT_00027f78 == '\0') goto LAB_00027c2a;
          if (((*pcVar6 == '\0') && (*DAT_00027f7c == '\0')) &&
             (pcVar14 = DAT_00027f7c, *DAT_00027f80 < 7)) goto LAB_00027c62;
          tmp42._0_4_ = *DAT_00027f8c;
          tmp42._4_4_ = DAT_00027f8c[1];
          tmp42._8_4_ = DAT_00027f8c[2];
          tmp42._12_4_ = DAT_00027f8c[3];
          tmp42._16_4_ = DAT_00027f8c[4];
          tmp42._20_4_ = DAT_00027f8c[5];
          tmp42._24_4_ = DAT_00027f8c[6];
          tmp42._28_4_ = DAT_00027f8c[7];
          tmp42._32_4_ = DAT_00027f8c[8];
          tmp42._36_4_ = DAT_00027f8c[9];
          tmp42._40_4_ = DAT_00027f8c[10];
          tmp42._44_4_ = DAT_00027f8c[0xb];
          tmp42._48_4_ = DAT_00027f8c[0xc];
          tmp42._52_2_ = (undefined2)DAT_00027f8c[0xd];
          _applog(7,tmp42,false);
        }
        else {
          if (*DAT_00027f78 == '\0') goto LAB_00027c2a;
          if (((*pcVar6 == '\0') && (*DAT_00027f7c == '\0')) &&
             (pcVar14 = DAT_00027f7c, *DAT_00027f80 < 7)) goto LAB_00027c62;
          tmp42._0_4_ = *DAT_00027f84;
          tmp42._4_4_ = DAT_00027f84[1];
          tmp42._8_4_ = DAT_00027f84[2];
          tmp42._12_4_ = DAT_00027f84[3];
          tmp42._16_4_ = DAT_00027f84[4];
          tmp42._20_4_ = DAT_00027f84[5];
          tmp42._24_4_ = DAT_00027f84[6];
          tmp42._28_4_ = DAT_00027f84[7];
          tmp42._32_4_ = DAT_00027f84[8];
          tmp42._36_4_ = DAT_00027f84[9];
          tmp42._40_4_ = DAT_00027f84[10];
          tmp42._44_4_ = DAT_00027f84[0xb];
          tmp42[48] = (char)(short)DAT_00027f84[0xc];
          tmp42[49] = (char)((ushort)(short)DAT_00027f84[0xc] >> 8);
          _applog(7,tmp42,false);
        }
      }
      if (*pcVar19 != '\0') {
        pcVar14 = DAT_00027ca8;
        if (*pcVar6 == '\0') {
LAB_00027c62:
          if ((*pcVar14 == '\0') && (*DAT_00027cac < 7)) goto LAB_00027c2a;
        }
        tmp42._0_4_ = *DAT_00027cd0;
        tmp42._4_4_ = DAT_00027cd0[1];
        tmp42._8_4_ = DAT_00027cd0[2];
        tmp42._12_4_ = DAT_00027cd0[3];
        tmp42._16_4_ = DAT_00027cd0[4];
        tmp42._20_4_ = DAT_00027cd0[5];
        tmp42._24_4_ = DAT_00027cd0[6];
        tmp42._28_4_ = DAT_00027cd0[7];
        tmp42._32_4_ = DAT_00027cd0[8];
        tmp42._36_4_ = DAT_00027cd0[9];
        tmp42._40_3_ = (undefined3)DAT_00027cd0[10];
        _applog(7,tmp42,false);
      }
LAB_00027c2a:
      _free_work(&work,DAT_00027cc4,DAT_00027cc8->__size,0x1de1);
      free(__ptr);
      puVar7 = DAT_00027ccc;
      uVar31 = *DAT_00027ccc;
      uVar21 = DAT_00027ccc[1];
      *(int *)((int)userdata + 0x78) = *(int *)((int)userdata + 0x78) + 1;
      *puVar7 = uVar31 + 1;
      puVar7[1] = uVar21 + (0xfffffffe < uVar31);
LAB_00027b54:
      cVar1 = *(char *)((int)userdata + 0x69);
      iVar27 = iVar11;
      iVar29 = iVar18;
      uVar31 = uVar10;
    }
    if ((*DAT_00027f90 != '\0') || ((*DAT_00027f7c != '\0' || (5 < *DAT_00027f80)))) {
                    /* WARNING: Load size is inaccurate */
      snprintf(tmp42,0x800,DAT_00027f9c,*userdata);
      _applog(6,tmp42,false);
    }
    _free_work(&work,DAT_00027f98,DAT_00027f74->__size,0x1d7e);
  } while( true );
code_r0x00027d68:
  sleep(2);
  goto LAB_00027806;
}

