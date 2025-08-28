
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 bitmain_scanhash(int param_1)

{
  ulonglong uVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  char *__format;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  pthread_mutex_t *__mutex;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  bool bVar17;
  undefined4 extraout_s1;
  DFtype extraout_d0;
  DFtype a;
  undefined8 uVar18;
  UDItype UVar19;
  uint local_970;
  uint local_954;
  uint local_950 [6];
  uint local_938 [10];
  undefined4 local_910;
  undefined4 local_90c;
  undefined4 local_908;
  undefined4 uStack_904;
  undefined4 uStack_900;
  undefined4 uStack_8fc;
  undefined4 local_8f8;
  undefined4 uStack_8f4;
  undefined4 uStack_8f0;
  undefined4 uStack_8ec;
  uint local_8e8;
  uint local_8e4;
  uint local_8e0;
  uint local_8dc;
  char acStack_828 [2052];
  undefined4 extraout_s1_00;
  
  __mutex = *(pthread_mutex_t **)(*(int *)(param_1 + 0x24) + 0x14);
  h = 0;
  DAT_00704ab4 = 0;
  pthread_mutex_lock((pthread_mutex_t *)nonce_mutex);
  iVar2 = pthread_mutex_lock(__mutex);
  if (iVar2 != 0) {
    piVar13 = __errno_location();
    snprintf(acStack_828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar13,
             "driver-btm-c5.c","bitmain_scanhash",0x41c4);
    _applog(3,acStack_828,1);
    _quit(1);
  }
  iVar2 = pthread_rwlock_rdlock((pthread_rwlock_t *)(__mutex + 1));
  if (iVar2 == 0) {
    iVar2 = pthread_mutex_unlock(__mutex);
  }
  else {
    piVar13 = __errno_location();
    snprintf(acStack_828,0x800,"WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar13,
             "driver-btm-c5.c","bitmain_scanhash",0x41c4);
    _applog(3,acStack_828,1);
    _quit(1);
    iVar2 = pthread_mutex_unlock(__mutex);
  }
  if (iVar2 != 0) {
    piVar13 = __errno_location();
    snprintf(acStack_828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar13,
             "driver-btm-c5.c","bitmain_scanhash",0x41c4);
    _applog(3,acStack_828,1);
    _quit(1);
  }
  do {
    while( true ) {
      if (nonce_read_out._8_4_ == 0) {
        iVar2 = pthread_rwlock_unlock((pthread_rwlock_t *)(__mutex + 1));
        if (iVar2 != 0) {
          piVar13 = __errno_location();
          snprintf(acStack_828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar13,
                   "driver-btm-c5.c","bitmain_scanhash",0x421c);
          _applog(3,acStack_828,1);
          _quit(1);
        }
        (*selective_yield)();
        pthread_mutex_unlock((pthread_mutex_t *)nonce_mutex);
        cgsleep_ms(1);
        if (((h != 0 || DAT_00704ab4 != 0) && (opt_debug != '\0')) &&
           ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
          snprintf(acStack_828,0x800,"%s: hashes %u ...\n","bitmain_scanhash",-h,
                   (((h & 0xfffffffe) - DAT_00704ab4) - (uint)(h * -0x80000000 < h)) +
                   (uint)CARRY4(h * -0x80000000,h * 0x7fffffff));
          _applog(7,acStack_828,0);
        }
        uVar15 = h * -0x80000000;
        bVar16 = uVar15 < h;
        uVar11 = h * 0x7fffffff;
        uVar14 = h & 0xfffffffe;
        h = -h;
        DAT_00704ab4 = ((uVar14 - DAT_00704ab4) - (uint)bVar16) + (uint)CARRY4(uVar11,uVar15);
        return 0;
      }
      iVar2 = 0;
      uVar14 = *(uint *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x20);
      uVar11 = *(uint *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0xc);
      uVar3 = *(undefined4 *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x18);
      uVar8 = *(undefined4 *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x1c);
      iVar9 = *(int *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x24);
      iVar12 = *(int *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x10);
      uVar15 = *(int *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x14) << 0x18 |
               *(uint *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x14) >> 0x18 |
               (*(uint *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x14) & 0xff0000) >> 8 |
               (*(uint *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x14) & 0xff00) << 8;
      do {
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x20);
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,
                 "%s: job_id:0x%x   work_id:0x%x   nonce2:0x%llx   nonce3:0x%x   version:0x%x\n",
                 "bitmain_scanhash",uVar11,iVar12,uVar3,uVar8,uVar14,uVar15);
        _applog(7,acStack_828,0);
      }
      bVar16 = (uint)nonce_read_out._4_4_ < 0x1fe;
      if (!bVar16) {
        nonce_read_out._4_4_ = 0;
      }
      piVar13 = (int *)((int)__mutex + 0x2e0);
      if (bVar16) {
        nonce_read_out._4_4_ = nonce_read_out._4_4_ + 1;
      }
      nonce_read_out._8_4_ = nonce_read_out._8_4_ + -1;
      if ((uVar14 != last_nonce3_15022) || (iVar12 != last_workid_15023)) break;
LAB_0002d62a:
      if (*(int *)(dev + (iVar9 + 2) * 4) == 1) {
        inc_hw_errors(param_1);
        iVar2 = dev + iVar9 * 4;
        *(int *)(iVar2 + 0xabc) = *(int *)(iVar2 + 0xabc) + 1;
      }
    }
    last_nonce3_15022 = uVar14;
    last_workid_15023 = iVar12;
    if (opt_debug == '\0') {
      if (given_id < uVar11 && uVar11 < given_id - 2) goto LAB_0002d62a;
LAB_0002d742:
      if (given_id - uVar11 != 1) {
        if (given_id != uVar11) {
          if (given_id - uVar11 != 2) goto LAB_0002d62a;
          goto LAB_0002d756;
        }
        goto LAB_0002d75e;
      }
      goto LAB_0002daea;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
      bVar17 = uVar11 <= given_id - 2;
      bVar16 = given_id - 2 == uVar11;
      if (bVar17 && !bVar16) {
        bVar17 = given_id <= uVar11;
        bVar16 = uVar11 == given_id;
      }
      if (!bVar17 || bVar16) goto LAB_0002daa2;
      bVar16 = true;
joined_r0x0002d606:
      if ((bVar16) && (opt_log_level < 7)) goto LAB_0002d62a;
LAB_0002d60c:
      __format = "%s: job_id error ...\n";
LAB_0002d616:
      snprintf(acStack_828,0x800,__format,"bitmain_scanhash");
      _applog(7,acStack_828,0);
      goto LAB_0002d62a;
    }
    snprintf(acStack_828,0x800,"%s: Chain ID J%d ...\n","bitmain_scanhash",iVar9 + 1);
    _applog(7,acStack_828,0);
    if (given_id < uVar11 && uVar11 < given_id - 2) {
      if (opt_debug != '\0') {
        if (use_syslog == '\0') {
          bVar16 = opt_log_output == '\0';
          goto joined_r0x0002d606;
        }
        goto LAB_0002d60c;
      }
      goto LAB_0002d62a;
    }
    if (opt_debug == '\0') goto LAB_0002d742;
LAB_0002daa2:
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
      if (given_id - uVar11 == 1) {
LAB_0002daea:
        piVar13 = (int *)((int)__mutex + 0xa18);
      }
      else if (given_id != uVar11) {
        if (given_id - uVar11 != 2) {
LAB_0002db4e:
          if (opt_log_level < 7) goto LAB_0002d62a;
LAB_0002dade:
          __format = "%s: job_id non\'t found ...\n";
          goto LAB_0002d616;
        }
LAB_0002d756:
        piVar13 = (int *)((int)__mutex + 0x1150);
      }
    }
    else {
      snprintf(acStack_828,0x800,"%s: given_id:%d job_id:%d switch:%d  ...\n","bitmain_scanhash",
               given_id,uVar11,given_id - uVar11);
      _applog(7,acStack_828,0);
      if (given_id - uVar11 == 1) goto LAB_0002daea;
      if (given_id != uVar11) {
        if (given_id - uVar11 == 2) goto LAB_0002d756;
        if (opt_debug != '\0') {
          if ((use_syslog == '\0') && (opt_log_output == '\0')) goto LAB_0002db4e;
          goto LAB_0002dade;
        }
        goto LAB_0002d62a;
      }
    }
LAB_0002d75e:
    uVar3 = get_work_by_nonce2(param_1,&local_954,piVar13,*(undefined4 *)(pools + *piVar13 * 4),
                               uVar3,uVar8,uVar15);
    uVar11 = local_954;
    uVar18 = *(undefined8 *)(local_954 + 0x138);
    UVar19 = __fixunsdfdi((DFtype)CONCAT44(extraout_s1,uVar3));
    a = extraout_d0;
    if (UVar19 != pool_diff_14987) {
      if (UVar19 == 0) {
        pool_diff_bit_14989._0_4_ = 0xffffffff;
        pool_diff_bit_14989._4_4_ = 0xffffffff;
      }
      else {
        uVar15 = 1;
        iVar2 = 0;
        uVar1 = UVar19;
        do {
          iVar12 = iVar2;
          uVar6 = uVar15;
          uVar10 = (uint)(uVar1 >> 0x21);
          uVar5 = (uint)((uVar1 & 0x100000000) != 0) << 0x1f | (uint)uVar1 >> 1;
          uVar1 = CONCAT44(uVar10,uVar5);
          uVar15 = uVar6 + 1;
          iVar2 = iVar12 + (uint)(0xfffffffe < uVar6);
        } while (uVar5 != 0 || uVar10 != 0);
        pool_diff_bit_14989._0_4_ = uVar6 - 1;
        pool_diff_bit_14989._4_4_ = iVar12 + -1 + (uint)(uVar6 != 0);
      }
      pool_diff_14987 = UVar19;
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s: pool_diff:%d work_diff:%d pool_diff_bit:%d ...\n",
                 "hashtest_submit",UVar19,uVar18,(uint)pool_diff_bit_14989,pool_diff_bit_14989._4_4_
                );
        uVar3 = _applog(7,acStack_828,0);
        a = (DFtype)CONCAT44(extraout_s1_00,uVar3);
      }
    }
    uVar18 = current_diff;
    UVar19 = __fixunsdfdi(a);
    if (UVar19 != net_diff_14988) {
      if (UVar19 == 0) {
        net_diff_bit_14990._0_4_ = -1;
        net_diff_bit_14990._4_4_ = -1;
      }
      else {
        uVar15 = 1;
        iVar2 = 0;
        uVar1 = UVar19;
        do {
          iVar12 = iVar2;
          uVar10 = uVar15;
          uVar5 = (uint)(uVar1 >> 0x21);
          uVar6 = (uint)((uVar1 & 0x100000000) != 0) << 0x1f | (uint)uVar1 >> 1;
          uVar1 = CONCAT44(uVar5,uVar6);
          uVar15 = uVar10 + 1;
          iVar2 = iVar12 + (uint)(0xfffffffe < uVar10);
        } while (uVar6 != 0 || uVar5 != 0);
        net_diff_bit_14990._0_4_ = uVar10 - 1;
        net_diff_bit_14990._4_4_ = iVar12 + -1 + (uint)(uVar10 != 0);
      }
      net_diff_14988 = UVar19;
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s:net_diff:%d current_diff:%d net_diff_bit %d ...\n",
                 "hashtest_submit",UVar19,uVar18,(int)net_diff_bit_14990,net_diff_bit_14990._4_4_);
        _applog(7,acStack_828,0);
      }
    }
    local_908 = *(undefined4 *)(uVar11 + 0x80);
    uStack_904 = *(undefined4 *)(uVar11 + 0x84);
    uStack_900 = *(undefined4 *)(uVar11 + 0x88);
    uStack_8fc = *(undefined4 *)(uVar11 + 0x8c);
    local_8f8 = *(undefined4 *)(uVar11 + 0x90);
    uStack_8f4 = *(undefined4 *)(uVar11 + 0x94);
    uStack_8f0 = *(undefined4 *)(uVar11 + 0x98);
    uStack_8ec = *(undefined4 *)(uVar11 + 0x9c);
    local_90c = 0;
    uVar15 = *(uint *)(uVar11 + 0x40);
    local_910 = 0x50;
    local_8dc = uVar14 << 0x18 | (uVar14 >> 8 & 0xff) << 0x10 | (uVar14 >> 0x10 & 0xff) << 8 |
                uVar14 >> 0x18;
    local_950[1] = *(uint *)(uVar11 + 0x44);
    local_950[2] = *(uint *)(uVar11 + 0x48);
    local_8e8 = uVar15 << 0x18 | (uVar15 >> 8 & 0xff) << 0x10 | (uVar15 >> 0x10 & 0xff) << 8 |
                uVar15 >> 0x18;
    local_8e4 = local_950[1] << 0x18 | (local_950[1] >> 8 & 0xff) << 0x10 |
                (local_950[1] >> 0x10 & 0xff) << 8 | local_950[1] >> 0x18;
    local_8e0 = local_950[2] << 0x18 | (local_950[2] >> 8 & 0xff) << 0x10 |
                (local_950[2] >> 0x10 & 0xff) << 8 | local_950[2] >> 0x18;
    local_950[0] = uVar14;
    sha2_finish(&local_910,local_950);
    memset(&local_910,0,0xe8);
    sha2(local_950,0x20,local_938 + 2);
    puVar4 = &local_954;
    puVar7 = local_938 + 1;
    do {
      puVar7 = puVar7 + 1;
      uVar15 = *puVar7;
      puVar4 = puVar4 + 1;
      *puVar4 = uVar15 << 0x18 | (uVar15 >> 8 & 0xff) << 0x10 | (uVar15 >> 0x10 & 0xff) << 8 |
                uVar15 >> 0x18;
    } while (puVar7 != local_938 + 9);
    if (local_938[1] == 0) {
      puVar4 = local_938 + 1;
      uVar15 = 0;
      do {
        puVar4 = puVar4 + -1;
        if (*puVar4 != 0) {
          uVar6 = (int)uVar15 >> 0x1f;
          goto LAB_0002db84;
        }
        uVar15 = uVar15 + 1;
      } while (uVar15 != 7);
      uVar15 = 7;
      uVar6 = 0;
LAB_0002db84:
      local_970 = (uint)pool_diff_bit_14989 >> 5 | pool_diff_bit_14989._4_4_ << 0x1b;
      bVar16 = pool_diff_bit_14989._4_4_ >> 5 <= uVar6;
      if (uVar6 == pool_diff_bit_14989._4_4_ >> 5) {
        bVar16 = local_970 <= uVar15;
      }
      if (!bVar16) goto LAB_0002d970;
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s: chain %d which_asic_nonce %d which_core_nonce %d",
                 "hashtest_submit",iVar9,uVar14 / 0x3000000,uVar14 & 0x7f);
        _applog(7,acStack_828,0);
        local_970 = (uint)pool_diff_bit_14989 >> 5 | pool_diff_bit_14989._4_4_ << 0x1b;
      }
      uVar6 = (uint)pool_diff_bit_14989 & 0x1f;
      iVar2 = dev + (uVar14 / 0x3000000 + iVar9 * 0x80) * 8;
      uVar15 = *(uint *)(iVar2 + 0xafc);
      *(uint *)(iVar2 + 0xafc) = uVar15 + 1;
      *(uint *)(iVar2 + 0xb00) = *(int *)(iVar2 + 0xb00) + (uint)(0xfffffffe < uVar15);
      uVar15 = local_938[-local_970];
      if ((uVar15 << 0x18 | (uVar15 >> 8 & 0xff) << 0x10 | (uVar15 >> 0x10 & 0xff) << 8 |
          uVar15 >> 0x18) < 0xffffffffU >> uVar6) {
        uVar15 = 0x100;
        submit_nonce(param_1,uVar11,uVar14);
      }
      else {
        if (0xfffffe <
            (local_938[0] << 0x18 | (local_938[0] >> 8 & 0xff) << 0x10 |
             (local_938[0] >> 0x10 & 0xff) << 8 | local_938[0] >> 0x18)) goto LAB_0002d970;
        uVar15 = 0x100;
      }
    }
    else {
      if (*(int *)(dev + (iVar9 + 2) * 4) == 1) {
        inc_hw_errors(param_1);
        iVar2 = dev + iVar9 * 4;
        *(int *)(iVar2 + 0xabc) = *(int *)(iVar2 + 0xabc) + 1;
      }
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s: HASH2_32[7] != 0","hashtest_submit");
        _applog(7,acStack_828,0);
      }
LAB_0002d970:
      uVar15 = 0;
    }
    bVar16 = CARRY4(uVar15,h);
    h = uVar15 + h;
    DAT_00704ab4 = DAT_00704ab4 + (uint)bVar16;
    _free_work(&local_954,"driver-btm-c5.c","bitmain_scanhash",0x421a);
  } while( true );
}

