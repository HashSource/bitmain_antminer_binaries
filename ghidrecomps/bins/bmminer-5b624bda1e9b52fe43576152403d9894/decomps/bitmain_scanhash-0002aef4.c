
/* WARNING: Unknown calling convention */

void * bitmain_scanhash(void *arg)

{
  uint64_t *puVar1;
  uint64_t nonce2;
  uint *puVar2;
  int iVar3;
  char *file;
  int *piVar4;
  work *work_00;
  thr_info *thr;
  pthread_mutex_t *__mutex;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int *piVar8;
  pthread_mutex_t *__mutex_00;
  bitmain_c5_info *info;
  int i_1;
  char cVar9;
  char *pcVar10;
  uint chain_id;
  pool *pool;
  uchar which_core_nonce;
  uint uVar11;
  int iVar12;
  int iVar13;
  int i;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  uint uVar17;
  uint job_id;
  uchar which_asic_nonce;
  uint *src_1;
  uint *src;
  uint *dest;
  uint uVar18;
  uint version;
  uint *src_2;
  uint nonce;
  uint nonce3;
  uint uVar19;
  uint work_id;
  bool bVar20;
  double dVar21;
  undefined8 uVar22;
  ulonglong uVar23;
  uint local_970;
  work *work;
  uchar hash1 [32];
  uchar hash2 [32];
  sha2_context ctx;
  char tmp42 [2048];
  
  puVar2 = DAT_0002b2c8;
  pcVar10 = (char *)0x0;
  iVar12 = 0;
  __mutex_00 = *(pthread_mutex_t **)(*(int *)((int)arg + 0x24) + 0x14);
  __mutex = (pthread_mutex_t *)(DAT_0002b2c8 + 4);
  *DAT_0002b2c8 = 0;
  puVar2[1] = 0;
  pthread_mutex_lock(__mutex);
  iVar5 = pthread_mutex_lock(__mutex_00);
  if (iVar5 != 0) {
    _mutex_lock((pthread_mutex_t *)DAT_0002b7b8,(char *)0x2e94,pcVar10,iVar12);
  }
  iVar5 = pthread_rwlock_rdlock((pthread_rwlock_t *)(__mutex_00 + 1));
  if (iVar5 != 0) {
    piVar8 = __errno_location();
    iVar12 = *piVar8;
    snprintf(tmp42,0x800,DAT_0002b7c0,iVar12,DAT_0002b7bc,DAT_0002b7b8,0x2e94);
    pcVar10 = (char *)0x1;
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar6 = pthread_mutex_unlock(__mutex_00);
  iVar3 = DAT_0002b2f8;
  iVar5 = DAT_0002b2f8;
  if (iVar6 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)DAT_0002b7b8,(char *)0x2e94,pcVar10,iVar12);
    iVar5 = DAT_0002b2f8;
  }
LAB_0002af48:
  iVar12 = *(int *)(iVar3 + 8);
joined_r0x0002af4e:
  if (iVar12 == 0) {
    iVar5 = pthread_rwlock_unlock((pthread_rwlock_t *)(__mutex_00 + 1));
    if (iVar5 != 0) {
      _rw_unlock(DAT_0002b7b8,(char *)0x2eed,pcVar10,iVar12);
    }
    (**DAT_0002b2d8)();
    pthread_mutex_unlock(DAT_0002b2dc);
    pvVar7 = (void *)0x1;
    cgsleep_ms(1);
    uVar17 = *puVar2;
    uVar18 = puVar2[1];
    if ((((uVar17 | uVar18) != 0) && (*DAT_0002b2e0 != '\0')) &&
       ((*DAT_0002b2e4 != '\0' || ((*DAT_0002b2e8 != '\0' || (6 < *DAT_0002b7b4)))))) {
      snprintf(tmp42,0x800,DAT_0002b2ec,DAT_0002b2c4,(int)((ulonglong)uVar17 * 0xffffffff),
               (int)((ulonglong)uVar17 * 0xffffffff >> 0x20) - uVar18);
      pvVar7 = (void *)0x7;
      _applog(7,tmp42,false);
      uVar17 = *puVar2;
      uVar18 = puVar2[1];
    }
    *puVar2 = (uint)((ulonglong)uVar17 * 0xffffffff);
    puVar2[1] = (int)((ulonglong)uVar17 * 0xffffffff >> 0x20) - uVar18;
    return pvVar7;
  }
  iVar13 = 0;
  nonce = *(uint *)(iVar5 + *(int *)(iVar5 + 4) * 0x3c + 0x20);
  uVar17 = *(uint *)(iVar5 + *(int *)(iVar5 + 4) * 0x3c + 0xc);
  iVar12 = iVar5 + *(int *)(iVar5 + 4) * 0x3c;
  puVar1 = (uint64_t *)(iVar12 + 0x18);
  nonce2 = *puVar1;
  iVar6 = *(int *)(iVar5 + *(int *)(iVar5 + 4) * 0x3c + 0x24);
  chain_id = *(uint *)(iVar5 + 4);
  uVar19 = *(uint *)(iVar5 + chain_id * 0x3c + 0x10);
  uVar18 = *(uint *)(iVar5 + *(int *)(iVar5 + 4) * 0x3c + 0x14) >> 0x18 |
           *(int *)(iVar5 + *(int *)(iVar5 + 4) * 0x3c + 0x14) << 0x18 |
           (*(uint *)(iVar5 + *(int *)(iVar5 + 4) * 0x3c + 0x14) & 0xff0000) >> 8 |
           (*(uint *)(iVar5 + *(int *)(iVar5 + 4) * 0x3c + 0x14) & 0xff00) << 8;
  do {
    iVar13 = iVar13 + 1;
  } while (iVar13 != 0x20);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < *DAT_0002b2bc)))) {
    snprintf(tmp42,0x800,DAT_0002b2c0,DAT_0002b2c4,uVar17,uVar19,*(undefined4 *)puVar1,
             *(undefined4 *)(iVar12 + 0x1c),nonce,uVar18);
    _applog(7,tmp42,false);
  }
  puVar16 = DAT_0002b2c8;
  if (*(uint *)(iVar3 + 4) < 0x1ff) {
    iVar12 = *(int *)(iVar5 + 4) + 1;
  }
  else {
    iVar12 = 0;
  }
  *(int *)(iVar5 + 4) = iVar12;
  uVar14 = puVar2[10];
  *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + -1;
  if ((nonce != uVar14) || (uVar19 != puVar16[0xb])) {
    puVar2[10] = nonce;
    puVar2[0xb] = uVar19;
    cVar9 = opt_debug;
    if (opt_debug != false) {
      if (((use_syslog == false) && (opt_log_output == false)) && (*DAT_0002b2bc < 7)) {
        cVar9 = '\x01';
      }
      else {
        snprintf(tmp42,0x800,DAT_0002b2cc,DAT_0002b2c4,iVar6 + 1);
        _applog(7,tmp42,false);
        cVar9 = opt_debug;
      }
    }
    iVar12 = DAT_0002b2fc;
    uVar19 = *(uint *)(DAT_0002b2fc + 0x78);
    if ((uVar19 - 2 <= uVar17) || (uVar17 <= uVar19)) {
      if ((cVar9 != '\0') &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < *DAT_0002b2bc)))) {
        snprintf(tmp42,0x800,DAT_0002b2f0,DAT_0002b2c4,uVar19,uVar17,uVar19 - uVar17);
        _applog(7,tmp42,false);
        uVar19 = *(uint *)(iVar12 + 0x78);
      }
      if (uVar19 - uVar17 == 1) {
        pool = (pool *)(__mutex_00 + 0x61);
      }
      else if (uVar19 == uVar17) {
        pool = (pool *)(__mutex_00 + 0x14);
      }
      else {
        if (uVar19 - uVar17 != 2) {
          if (opt_debug != false) {
            pcVar10 = DAT_0002b7b0;
            if ((use_syslog == false) && (opt_log_output == false)) {
              iVar12 = *DAT_0002b7b4;
              goto joined_r0x0002b700;
            }
            goto LAB_0002b136;
          }
          goto LAB_0002b146;
        }
        pool = (pool *)(__mutex_00 + 0xae);
      }
      get_work_by_nonce2((thr_info *)arg,&work,pool,*(pool **)(*DAT_0002b2f4 + pool->pool_no * 4),
                         nonce2,(uint)pool->ntime,uVar18);
      work_00 = work;
      dVar21 = work->sdiff;
      uVar23 = __fixunsdfdi(SUB84(dVar21,0),(int)((ulonglong)dVar21 >> 0x20));
      uVar18 = (uint)(uVar23 >> 0x20);
      uVar17 = (uint)uVar23;
      if (uVar18 != puVar2[0xd] || uVar17 != puVar2[0xc]) {
        *(ulonglong *)(DAT_0002b2c8 + 0xc) = uVar23;
        if (uVar23 == 0) {
          uVar19 = 0xffffffff;
          uVar14 = 0xffffffff;
        }
        else {
          uVar19 = 1;
          iVar12 = 0;
          do {
            iVar13 = iVar12;
            uVar14 = uVar19;
            uVar15 = (uint)(uVar23 >> 0x21);
            uVar11 = (uint)((uVar23 & 0x100000000) != 0) << 0x1f | (uint)uVar23 >> 1;
            uVar23 = CONCAT44(uVar15,uVar11);
            uVar19 = uVar14 + 1;
            iVar12 = iVar13 + (uint)(0xfffffffe < uVar14);
          } while ((uVar11 | uVar15) != 0);
          uVar19 = uVar14 - 1;
          uVar14 = iVar13 + -1 + (uint)(uVar14 != 0);
        }
        puVar2[0xe] = uVar19;
        puVar2[0xf] = uVar14;
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < *DAT_0002b540)))) {
          snprintf(tmp42,0x800,DAT_0002b564,DAT_0002b55c,uVar17,uVar18,dVar21,uVar19,uVar14);
          _applog(7,tmp42,false);
        }
      }
      uVar22 = *DAT_0002b544;
      uVar23 = __fixunsdfdi((int)uVar22,(int)((ulonglong)uVar22 >> 0x20));
      uVar18 = (uint)(uVar23 >> 0x20);
      uVar17 = (uint)uVar23;
      if (uVar18 != puVar2[0x11] || uVar17 != puVar2[0x10]) {
        *(ulonglong *)(DAT_0002b548 + 0x40) = uVar23;
        if (uVar23 == 0) {
          uVar19 = 0xffffffff;
          uVar14 = 0xffffffff;
        }
        else {
          uVar19 = 1;
          iVar12 = 0;
          do {
            iVar13 = iVar12;
            uVar14 = uVar19;
            uVar15 = (uint)(uVar23 >> 0x21);
            uVar11 = (uint)((uVar23 & 0x100000000) != 0) << 0x1f | (uint)uVar23 >> 1;
            uVar23 = CONCAT44(uVar15,uVar11);
            uVar19 = uVar14 + 1;
            iVar12 = iVar13 + (uint)(0xfffffffe < uVar14);
          } while ((uVar11 | uVar15) != 0);
          uVar19 = uVar14 - 1;
          uVar14 = iVar13 + -1 + (uint)(uVar14 != 0);
        }
        puVar2[0x12] = uVar19;
        puVar2[0x13] = uVar14;
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < *DAT_0002b540)))) {
          snprintf(tmp42,0x800,DAT_0002b560,DAT_0002b55c,uVar17,uVar18,uVar22,uVar19,uVar14);
          _applog(7,tmp42,false);
        }
      }
      ctx.state[0] = *(uint *)work_00->midstate;
      ctx.state[1] = *(uint *)(work_00->midstate + 4);
      ctx.state[2] = *(uint *)(work_00->midstate + 8);
      ctx.state[3] = *(uint *)(work_00->midstate + 0xc);
      ctx.state[4] = *(uint *)(work_00->midstate + 0x10);
      ctx.state[5] = *(uint *)(work_00->midstate + 0x14);
      ctx.state[6] = *(uint *)(work_00->midstate + 0x18);
      ctx.state[7] = *(uint *)(work_00->midstate + 0x1c);
      uVar17 = *(uint *)(work_00->data + 0x40);
      ctx.total[0] = 0x50;
      ctx.buffer._12_4_ =
           nonce << 0x18 | (nonce >> 8 & 0xff) << 0x10 | (nonce >> 0x10 & 0xff) << 8 | nonce >> 0x18
      ;
      hash1._4_4_ = *(undefined4 *)(work_00->data + 0x44);
      hash1._8_4_ = *(undefined4 *)(work_00->data + 0x48);
      iVar12 = 0;
      ctx.total[1] = 0;
      ctx.buffer._0_4_ =
           uVar17 << 0x18 | (uVar17 >> 8 & 0xff) << 0x10 | (uVar17 >> 0x10 & 0xff) << 8 |
           uVar17 >> 0x18;
      ctx.buffer._4_4_ =
           hash1._4_4_ << 0x18 | ((uint)hash1._4_4_ >> 8 & 0xff) << 0x10 |
           ((uint)hash1._4_4_ >> 0x10 & 0xff) << 8 | (uint)hash1._4_4_ >> 0x18;
      ctx.buffer._8_4_ =
           hash1._8_4_ << 0x18 | ((uint)hash1._8_4_ >> 8 & 0xff) << 0x10 |
           ((uint)hash1._8_4_ >> 0x10 & 0xff) << 8 | (uint)hash1._8_4_ >> 0x18;
      hash1._0_4_ = nonce;
      sha2_finish(&ctx,hash1);
      memset(&ctx,0,0xe8);
      sha2(hash1,0x20,hash2);
      piVar4 = DAT_0002b7c4;
      piVar8 = DAT_0002b54c;
      do {
        uVar17 = *(uint *)(hash2 + iVar12);
        *(uint *)(hash1 + iVar12) =
             uVar17 << 0x18 | (uVar17 >> 8 & 0xff) << 0x10 | (uVar17 >> 0x10 & 0xff) << 8 |
             uVar17 >> 0x18;
        iVar12 = iVar12 + 4;
      } while (iVar12 != 0x20);
      if (hash1._28_4_ == 0) {
        puVar16 = (uint *)(hash1 + 0x1c);
        uVar17 = 0;
        do {
          puVar16 = puVar16 + -1;
          uVar18 = *puVar16;
          if ((uVar18 << 0x18 | (uVar18 >> 8 & 0xff) << 0x10 | (uVar18 >> 0x10 & 0xff) << 8 |
              uVar18 >> 0x18) != 0) {
            uVar18 = (int)uVar17 >> 0x1f;
            goto LAB_0002b580;
          }
          uVar17 = uVar17 + 1;
        } while (uVar17 != 7);
        uVar17 = 7;
        uVar18 = 0;
LAB_0002b580:
        uVar14 = puVar2[0xe];
        uVar19 = puVar2[0xf] >> 5;
        local_970 = uVar14 >> 5 | puVar2[0xf] << 0x1b;
        bVar20 = uVar19 <= uVar18;
        if (uVar18 == uVar19) {
          bVar20 = local_970 <= uVar17;
        }
        if (!bVar20) goto LAB_0002b4a4;
        iVar12 = *DAT_0002b7c4;
        uVar17 = nonce >> (*(byte *)(iVar12 + 0x2fba) + 0x18 & 0xff);
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < *DAT_0002b7b4)) {
          snprintf(tmp42,0x800,DAT_0002b7a8,DAT_0002b7ac,iVar6,uVar17 & 0xff,nonce & 0x7f);
          _applog(5,tmp42,false);
          uVar14 = puVar2[0xe];
          iVar12 = *piVar4;
          local_970 = uVar14 >> 5 | puVar2[0xf] << 0x1b;
        }
        iVar12 = iVar12 + ((uVar17 & 0xff) + iVar6 * 0x40 + 0x157) * 8;
        uVar17 = *(uint *)(iVar12 + 2);
        *(uint *)(iVar12 + 2) = uVar17 + 1;
        *(uint *)(iVar12 + 6) = *(int *)(iVar12 + 6) + (uint)(0xfffffffe < uVar17);
        uVar17 = *(uint *)(hash1 + local_970 * -4 + 0x18);
        if ((uVar17 << 0x18 | (uVar17 >> 8 & 0xff) << 0x10 | (uVar17 >> 0x10 & 0xff) << 8 |
            uVar17 >> 0x18) < 0xffffffffU >> (uVar14 & 0x1f)) {
          uVar17 = 0x100;
          submit_nonce((thr_info *)arg,work_00,nonce);
        }
        else {
          if (0xfffffe <
              (hash1._24_4_ << 0x18 | ((uint)hash1._24_4_ >> 8 & 0xff) << 0x10 |
               ((uint)hash1._24_4_ >> 0x10 & 0xff) << 8 | (uint)hash1._24_4_ >> 0x18))
          goto LAB_0002b4a4;
          uVar17 = 0x100;
        }
      }
      else {
        if (*(int *)(*DAT_0002b54c + (iVar6 + 2) * 4) == 1) {
          inc_hw_errors((thr_info *)arg);
          iVar12 = *piVar8 + (iVar6 + 0x29e) * 4;
          *(int *)(iVar12 + 2) = *(int *)(iVar12 + 2) + 1;
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < *DAT_0002b540)))) {
          snprintf(tmp42,0x800,DAT_0002b558,DAT_0002b55c);
          _applog(7,tmp42,false);
        }
LAB_0002b4a4:
        uVar17 = 0;
      }
      pcVar10 = DAT_0002b554;
      file = DAT_0002b550;
      uVar18 = *puVar2;
      *puVar2 = uVar18 + uVar17;
      puVar2[1] = puVar2[1] + (uint)CARRY4(uVar18,uVar17);
      _free_work(&work,file,pcVar10,0x2eeb);
      goto LAB_0002af48;
    }
    if (cVar9 != '\0') {
      pcVar10 = DAT_0002b2d0;
      if ((use_syslog == false) && (opt_log_output == false)) {
        iVar12 = *DAT_0002b7b4;
joined_r0x0002b700:
        if (iVar12 < 7) goto LAB_0002b146;
      }
LAB_0002b136:
      snprintf(tmp42,0x800,pcVar10,DAT_0002b2c4);
      _applog(7,tmp42,false);
    }
  }
LAB_0002b146:
  piVar8 = DAT_0002b2d4;
  pcVar10 = (char *)(iVar6 + 2);
  if (*(int *)(*DAT_0002b2d4 + (int)pcVar10 * 4) != 1) goto LAB_0002af48;
  inc_hw_errors((thr_info *)arg);
  iVar12 = *piVar8 + (iVar6 + 0x29e) * 4;
  pcVar10 = (char *)(*(int *)(iVar12 + 2) + 1);
  *(char **)(iVar12 + 2) = pcVar10;
  iVar12 = *(int *)(iVar3 + 8);
  goto joined_r0x0002af4e;
}

