
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Unknown calling convention */

void * bitmain_scanhash(void *arg)

{
  uint64_t *puVar1;
  uint64_t uVar2;
  ulonglong uVar3;
  uint64_t uVar4;
  all_parameters *paVar5;
  work *work;
  int iVar6;
  void *extraout_r0;
  void *extraout_r0_00;
  void *pvVar7;
  int *piVar8;
  pthread_mutex_t *__mutex;
  int iVar9;
  char cVar10;
  char *func;
  char *func_00;
  uint uVar11;
  char *__format;
  char *func_01;
  pthread_mutex_t *pool;
  int line;
  int line_00;
  int line_01;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  uint nonce;
  uint uVar16;
  bool bVar17;
  double dVar18;
  ulonglong uVar19;
  uint local_970;
  work *local_954;
  uchar hash1 [32];
  uchar hash2 [32];
  sha2_context ctx;
  char tmp42 [2048];
  
  __mutex = *(pthread_mutex_t **)(*(int *)((int)arg + 0x24) + 0x14);
  h._0_4_ = 0;
  h._4_4_ = 0;
  pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
  iVar6 = pthread_mutex_lock(__mutex);
  if (iVar6 != 0) {
    _mutex_lock((pthread_mutex_t *)"bitmain_scanhash",(char *)0x2e94,func,line);
  }
  iVar6 = pthread_rwlock_rdlock((pthread_rwlock_t *)(__mutex + 1));
  if (iVar6 != 0) {
    piVar8 = __errno_location();
    snprintf(tmp42,0x800,"WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar8,
             "driver-btm-c5.c","bitmain_scanhash",0x2e94);
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar6 = pthread_mutex_unlock(__mutex);
  if (iVar6 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"bitmain_scanhash",(char *)0x2e94,func_00,line_00);
  }
  do {
    while( true ) {
      if (nonce_read_out.nonce_num == 0) {
        iVar6 = pthread_rwlock_unlock((pthread_rwlock_t *)(__mutex + 1));
        if (iVar6 != 0) {
          _rw_unlock((pthread_rwlock_t *)"bitmain_scanhash",(char *)0x2eed,func_01,line_01);
        }
        (*selective_yield)();
        pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
        cgsleep_ms(1);
        pvVar7 = extraout_r0;
        uVar2 = hashtest_submit::pool_diff;
        uVar4 = hashtest_submit::net_diff;
        if ((((uint)h != 0 || h._4_4_ != 0) && (opt_debug != false)) &&
           ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
          snprintf(tmp42,0x800,"%s: hashes %u ...\n","bitmain_scanhash",
                   (int)((ulonglong)(uint)h * 0xffffffff),
                   (int)((ulonglong)(uint)h * 0xffffffff >> 0x20) - h._4_4_);
          _applog(7,tmp42,false);
          pvVar7 = extraout_r0_00;
          uVar2 = hashtest_submit::pool_diff;
          uVar4 = hashtest_submit::net_diff;
        }
        hashtest_submit::net_diff._4_4_ = (undefined4)(uVar4 >> 0x20);
        hashtest_submit::net_diff._0_4_ = (undefined4)uVar4;
        hashtest_submit::pool_diff._4_4_ = (undefined4)(uVar2 >> 0x20);
        hashtest_submit::pool_diff._0_4_ = (undefined4)uVar2;
        uVar19 = (ulonglong)(uint)h;
        h._0_4_ = (int)(uVar19 * 0xffffffff);
        h._4_4_ = (int)(uVar19 * 0xffffffff >> 0x20) - h._4_4_;
        return pvVar7;
      }
      iVar6 = 0;
      nonce = nonce_read_out.nonce_buffer[nonce_read_out.p_rd].nonce3;
      uVar14 = nonce_read_out.nonce_buffer[nonce_read_out.p_rd].job_id;
      puVar1 = &nonce_read_out.nonce_buffer[nonce_read_out.p_rd].nonce2;
      uVar2 = *puVar1;
      uVar11 = nonce_read_out.nonce_buffer[nonce_read_out.p_rd].chain_num;
      uVar16 = nonce_read_out.nonce_buffer[nonce_read_out.p_rd].work_id;
      uVar15 = nonce_read_out.nonce_buffer[nonce_read_out.p_rd].header_version >> 0x18 |
               nonce_read_out.nonce_buffer[nonce_read_out.p_rd].header_version << 0x18 |
               (nonce_read_out.nonce_buffer[nonce_read_out.p_rd].header_version & 0xff0000) >> 8 |
               (nonce_read_out.nonce_buffer[nonce_read_out.p_rd].header_version & 0xff00) << 8;
      do {
        iVar6 = iVar6 + 1;
      } while (iVar6 != 0x20);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,
                 "%s: job_id:0x%x   work_id:0x%x   nonce2:0x%llx   nonce3:0x%x   version:0x%x\n",
                 "bitmain_scanhash",uVar14,uVar16,(int)*puVar1,
                 *(undefined4 *)((int)&nonce_read_out.nonce_buffer[nonce_read_out.p_rd].nonce2 + 4),
                 nonce,uVar15);
        _applog(7,tmp42,false);
      }
      if (nonce_read_out.p_rd < 0x1ff) {
        nonce_read_out.p_rd = nonce_read_out.p_rd + 1;
      }
      else {
        nonce_read_out.p_rd = 0;
      }
      nonce_read_out.nonce_num = nonce_read_out.nonce_num - 1;
      if ((nonce != bitmain_scanhash::last_nonce3) || (uVar16 != bitmain_scanhash::last_workid))
      break;
LAB_0002b146:
      if (dev->chain_exist[uVar11] == 1) {
        inc_hw_errors((thr_info *)arg);
        dev->chain_hw[uVar11] = dev->chain_hw[uVar11] + 1;
      }
    }
    bitmain_scanhash::last_nonce3 = nonce;
    bitmain_scanhash::last_workid = uVar16;
    cVar10 = opt_debug;
    if (opt_debug != false) {
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
        cVar10 = '\x01';
      }
      else {
        snprintf(tmp42,0x800,"%s: Chain ID J%d ...\n","bitmain_scanhash",uVar11 + 1);
        _applog(7,tmp42,false);
        cVar10 = opt_debug;
      }
    }
    if ((uVar14 < given_id - 2) && (given_id < uVar14)) {
      if ((cVar10 != '\0') &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        __format = "%s: job_id error ...\n";
        goto LAB_0002b136;
      }
      goto LAB_0002b146;
    }
    if ((cVar10 != '\0') &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: given_id:%d job_id:%d switch:%d  ...\n","bitmain_scanhash",given_id,
               uVar14,given_id - uVar14);
      _applog(7,tmp42,false);
    }
    if (given_id - uVar14 == 1) {
      pool = __mutex + 0x61;
    }
    else if (given_id == uVar14) {
      pool = __mutex + 0x14;
    }
    else {
      if (given_id - uVar14 != 2) {
        if (opt_debug != false) {
          if ((use_syslog == false) && (opt_log_output == false)) {
            if (opt_log_level < 7) goto LAB_0002b146;
            __format = "%s: job_id non\'t found ...\n";
          }
          else {
            __format = "%s: job_id non\'t found ...\n";
          }
LAB_0002b136:
          snprintf(tmp42,0x800,__format,"bitmain_scanhash");
          _applog(7,tmp42,false);
        }
        goto LAB_0002b146;
      }
      pool = __mutex + 0xae;
    }
    get_work_by_nonce2((thr_info *)arg,&local_954,(pool *)&pool->__data,pools[(pool->__data).__lock]
                       ,uVar2,(int)pool + 0x70c,uVar15);
    work = local_954;
    dVar18 = local_954->sdiff;
    uVar19 = __fixunsdfdi(SUB84(dVar18,0),(int)((ulonglong)dVar18 >> 0x20));
    if (hashtest_submit::pool_diff != uVar19) {
      if (uVar19 == 0) {
        hashtest_submit::pool_diff_bit._0_4_ = 0xffffffff;
        hashtest_submit::pool_diff_bit._4_4_ = 0xffffffff;
      }
      else {
        uVar14 = 1;
        iVar6 = 0;
        uVar3 = uVar19;
        do {
          iVar9 = iVar6;
          uVar15 = uVar14;
          uVar12 = (uint)(uVar3 >> 0x21);
          uVar16 = (uint)((uVar3 & 0x100000000) != 0) << 0x1f | (uint)uVar3 >> 1;
          uVar3 = CONCAT44(uVar12,uVar16);
          uVar14 = uVar15 + 1;
          iVar6 = iVar9 + (uint)(0xfffffffe < uVar15);
        } while (uVar16 != 0 || uVar12 != 0);
        hashtest_submit::pool_diff_bit._0_4_ = uVar15 - 1;
        hashtest_submit::pool_diff_bit._4_4_ = iVar9 + -1 + (uint)(uVar15 != 0);
      }
      hashtest_submit::pool_diff = uVar19;
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: pool_diff:%d work_diff:%d pool_diff_bit:%d ...\n",
                 "hashtest_submit",(int)uVar19,(int)(uVar19 >> 0x20),dVar18,
                 (uint)hashtest_submit::pool_diff_bit,hashtest_submit::pool_diff_bit._4_4_);
        _applog(7,tmp42,false);
      }
    }
    dVar18 = current_diff;
    uVar19 = __fixunsdfdi(SUB84(current_diff,0),(int)((ulonglong)current_diff >> 0x20));
    if (hashtest_submit::net_diff != uVar19) {
      if (uVar19 == 0) {
        hashtest_submit::net_diff_bit._0_4_ = -1;
        hashtest_submit::net_diff_bit._4_4_ = -1;
      }
      else {
        uVar14 = 1;
        iVar6 = 0;
        uVar3 = uVar19;
        do {
          iVar9 = iVar6;
          uVar15 = uVar14;
          uVar12 = (uint)(uVar3 >> 0x21);
          uVar16 = (uint)((uVar3 & 0x100000000) != 0) << 0x1f | (uint)uVar3 >> 1;
          uVar3 = CONCAT44(uVar12,uVar16);
          uVar14 = uVar15 + 1;
          iVar6 = iVar9 + (uint)(0xfffffffe < uVar15);
        } while (uVar16 != 0 || uVar12 != 0);
        hashtest_submit::net_diff_bit._0_4_ = uVar15 - 1;
        hashtest_submit::net_diff_bit._4_4_ = iVar9 + -1 + (uint)(uVar15 != 0);
      }
      hashtest_submit::net_diff = uVar19;
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s:net_diff:%d current_diff:%d net_diff_bit %d ...\n",
                 "hashtest_submit",(int)uVar19,(int)(uVar19 >> 0x20),dVar18,
                 (int)hashtest_submit::net_diff_bit,hashtest_submit::net_diff_bit._4_4_);
        _applog(7,tmp42,false);
      }
    }
    ctx.state[0] = *(uint *)work->midstate;
    ctx.state[1] = *(uint *)(work->midstate + 4);
    ctx.state[2] = *(uint *)(work->midstate + 8);
    ctx.state[3] = *(uint *)(work->midstate + 0xc);
    ctx.state[4] = *(uint *)(work->midstate + 0x10);
    ctx.state[5] = *(uint *)(work->midstate + 0x14);
    ctx.state[6] = *(uint *)(work->midstate + 0x18);
    ctx.state[7] = *(uint *)(work->midstate + 0x1c);
    uVar14 = *(uint *)(work->data + 0x40);
    ctx.total[0] = 0x50;
    ctx.buffer._12_4_ =
         nonce << 0x18 | (nonce >> 8 & 0xff) << 0x10 | (nonce >> 0x10 & 0xff) << 8 | nonce >> 0x18;
    hash1._4_4_ = *(undefined4 *)(work->data + 0x44);
    hash1._8_4_ = *(undefined4 *)(work->data + 0x48);
    iVar6 = 0;
    ctx.total[1] = 0;
    ctx.buffer._0_4_ =
         uVar14 << 0x18 | (uVar14 >> 8 & 0xff) << 0x10 | (uVar14 >> 0x10 & 0xff) << 8 |
         uVar14 >> 0x18;
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
    do {
      uVar14 = *(uint *)(hash2 + iVar6);
      *(uint *)(hash1 + iVar6) =
           uVar14 << 0x18 | (uVar14 >> 8 & 0xff) << 0x10 | (uVar14 >> 0x10 & 0xff) << 8 |
           uVar14 >> 0x18;
      iVar6 = iVar6 + 4;
    } while (iVar6 != 0x20);
    if (hash1._28_4_ == 0) {
      puVar13 = (uint *)(hash1 + 0x1c);
      uVar14 = 0;
      do {
        puVar13 = puVar13 + -1;
        uVar15 = *puVar13;
        if ((((uVar15 & 0xff) != 0 || (uVar15 >> 8 & 0xff) != 0) || (uVar15 >> 0x10 & 0xff) != 0) ||
            uVar15 >> 0x18 != 0) {
          uVar15 = (int)uVar14 >> 0x1f;
          goto LAB_0002b580;
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 != 7);
      uVar14 = 7;
      uVar15 = 0;
LAB_0002b580:
      local_970 = (uint)hashtest_submit::pool_diff_bit >> 5 |
                  hashtest_submit::pool_diff_bit._4_4_ << 0x1b;
      bVar17 = hashtest_submit::pool_diff_bit._4_4_ >> 5 <= uVar15;
      if (uVar15 == hashtest_submit::pool_diff_bit._4_4_ >> 5) {
        bVar17 = local_970 <= uVar14;
      }
      if (!bVar17) goto LAB_0002b4a4;
      uVar14 = nonce >> (dev->check_bit + 0x18 & 0xff);
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"%s: chain %d which_asic_nonce %d which_core_nonce %d",
                 "hashtest_submit",uVar11,uVar14 & 0xff,nonce & 0x7f);
        _applog(5,tmp42,false);
        local_970 = (uint)hashtest_submit::pool_diff_bit >> 5 |
                    hashtest_submit::pool_diff_bit._4_4_ << 0x1b;
      }
      paVar5 = dev;
      uVar14 = uVar14 & 0xff;
      uVar16 = (uint)dev->chain_asic_nonce[uVar11][uVar14];
      iVar6 = *(int *)((int)dev->chain_asic_nonce[uVar11] + uVar14 * 8 + 4);
      uVar15 = (uint)hashtest_submit::pool_diff_bit & 0x1f;
      *(uint *)(dev->chain_asic_nonce[uVar11] + uVar14) = uVar16 + 1;
      *(uint *)((int)paVar5->chain_asic_nonce[uVar11] + uVar14 * 8 + 4) =
           iVar6 + (uint)(0xfffffffe < uVar16);
      uVar11 = *(uint *)(hash2 + local_970 * -4 + -8);
      if ((uVar11 << 0x18 | (uVar11 >> 8 & 0xff) << 0x10 | (uVar11 >> 0x10 & 0xff) << 8 |
          uVar11 >> 0x18) < 0xffffffffU >> uVar15) {
        uVar11 = 0x100;
        submit_nonce((thr_info *)arg,work,nonce);
      }
      else {
        if (0xfffffe <
            (hash1._24_4_ << 0x18 | ((uint)hash1._24_4_ >> 8 & 0xff) << 0x10 |
             ((uint)hash1._24_4_ >> 0x10 & 0xff) << 8 | (uint)hash1._24_4_ >> 0x18))
        goto LAB_0002b4a4;
        uVar11 = 0x100;
      }
    }
    else {
      if (dev->chain_exist[uVar11] == 1) {
        inc_hw_errors((thr_info *)arg);
        dev->chain_hw[uVar11] = dev->chain_hw[uVar11] + 1;
      }
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: HASH2_32[7] != 0","hashtest_submit");
        _applog(7,tmp42,false);
      }
LAB_0002b4a4:
      uVar11 = 0;
    }
    bVar17 = CARRY4((uint)h,uVar11);
    h._0_4_ = (uint)h + uVar11;
    h._4_4_ = h._4_4_ + (uint)bVar17;
    _free_work(&local_954,"driver-btm-c5.c","bitmain_scanhash",0x2eeb);
  } while( true );
}

