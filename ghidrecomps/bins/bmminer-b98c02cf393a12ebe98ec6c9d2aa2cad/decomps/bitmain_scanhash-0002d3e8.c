
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 bitmain_scanhash(int param_1)

{
  DFtype DVar1;
  ulonglong uVar2;
  uint *puVar3;
  DFtype *pDVar4;
  UDItype *pUVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  uint *puVar9;
  char *__format;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  pthread_mutex_t *__mutex;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int *piVar18;
  uint uVar19;
  uint uVar20;
  bool bVar21;
  bool bVar22;
  undefined8 uVar23;
  DFtype DVar24;
  UDItype UVar25;
  DFtype a;
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
  
  __mutex = *(pthread_mutex_t **)(*(int *)(param_1 + 0x24) + 0x14);
  h = 0;
  DAT_00704ab4 = 0;
  pthread_mutex_lock(DAT_0002d718);
  iVar7 = pthread_mutex_lock(__mutex);
  uVar8 = DAT_0002ddfc;
  if (iVar7 != 0) {
    piVar18 = __errno_location();
    snprintf(acStack_828,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar18,
             "driver-btm-c5.c",uVar8,0x41c4);
    _applog(3,acStack_828,1);
    _quit(1);
  }
  iVar7 = pthread_rwlock_rdlock((pthread_rwlock_t *)(__mutex + 1));
  uVar8 = DAT_0002ddfc;
  if (iVar7 == 0) {
    iVar7 = pthread_mutex_unlock(__mutex);
    uVar8 = DAT_0002ddfc;
  }
  else {
    piVar18 = __errno_location();
    snprintf(acStack_828,0x800,"WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar18,
             "driver-btm-c5.c",uVar8,0x41c4);
    _applog(3,acStack_828,1);
    _quit(1);
    iVar7 = pthread_mutex_unlock(__mutex);
    uVar8 = DAT_0002ddfc;
  }
  DAT_0002ddfc = uVar8;
  if (iVar7 != 0) {
    piVar18 = __errno_location();
    snprintf(acStack_828,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar18,
             "driver-btm-c5.c",uVar8,0x41c4);
    _applog(3,acStack_828,1);
    _quit(1);
  }
  do {
    while( true ) {
      if (nonce_read_out._8_4_ == 0) {
        iVar7 = pthread_rwlock_unlock((pthread_rwlock_t *)(__mutex + 1));
        uVar8 = DAT_0002ddfc;
        if (iVar7 != 0) {
          piVar18 = __errno_location();
          snprintf(acStack_828,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar18,
                   "driver-btm-c5.c",uVar8,0x421c);
          _applog(3,acStack_828,1);
          _quit(1);
        }
        (*selective_yield)();
        pthread_mutex_unlock(DAT_0002d718);
        cgsleep_ms(1);
        if ((((h | DAT_00704ab4) != 0) && (opt_debug != '\0')) &&
           ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
          snprintf(acStack_828,0x800,"%s: hashes %u ...\n",DAT_0002d71c,-h,
                   (((h & 0xfffffffe) - DAT_00704ab4) - (uint)(h * -0x80000000 < h)) +
                   (uint)CARRY4(h * -0x80000000,h * 0x7fffffff));
          _applog(7,acStack_828,0);
        }
        uVar20 = h * -0x80000000;
        bVar21 = uVar20 < h;
        uVar16 = h * 0x7fffffff;
        uVar19 = h & 0xfffffffe;
        h = -h;
        DAT_00704ab4 = ((uVar19 - DAT_00704ab4) - (uint)bVar21) + (uint)CARRY4(uVar16,uVar20);
        return 0;
      }
      iVar7 = 0;
      uVar19 = *(uint *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x20);
      uVar16 = *(uint *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0xc);
      uVar8 = *(undefined4 *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x18);
      uVar13 = *(undefined4 *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x1c);
      a = *(DFtype *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x18);
      iVar14 = *(int *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x24);
      iVar17 = *(int *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x10);
      uVar20 = *(int *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x14) << 0x18 |
               *(uint *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x14) >> 0x18 |
               (*(uint *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x14) & 0xff0000) >> 8 |
               (*(uint *)(nonce_read_out + nonce_read_out._4_4_ * 0x3c + 0x14) & 0xff00) << 8;
      do {
        iVar7 = iVar7 + 1;
      } while (iVar7 != 0x20);
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,
                 "%s: job_id:0x%x   work_id:0x%x   nonce2:0x%llx   nonce3:0x%x   version:0x%x\n",
                 DAT_0002d71c,uVar16,iVar17,uVar8,uVar13,uVar19,uVar20);
        _applog(7,acStack_828,0);
      }
      bVar21 = (uint)nonce_read_out._4_4_ < 0x1fe;
      if (!bVar21) {
        nonce_read_out._4_4_ = 0;
      }
      piVar18 = (int *)((int)__mutex + 0x2e0);
      if (bVar21) {
        nonce_read_out._4_4_ = nonce_read_out._4_4_ + 1;
      }
      nonce_read_out._8_4_ = nonce_read_out._8_4_ + -1;
      if ((uVar19 != last_nonce3_15022) || (iVar17 != last_workid_15023)) break;
LAB_0002d62a:
      if (*(int *)(dev + (iVar14 + 2) * 4) == 1) {
        inc_hw_errors(param_1);
        iVar7 = dev + iVar14 * 4;
        *(int *)(iVar7 + 0xabc) = *(int *)(iVar7 + 0xabc) + 1;
      }
    }
    last_nonce3_15022 = uVar19;
    last_workid_15023 = iVar17;
    if (opt_debug == '\0') {
      if (given_id < uVar16 && uVar16 < given_id - 2) goto LAB_0002d62a;
LAB_0002d742:
      if (given_id - uVar16 != 1) {
        if (given_id != uVar16) {
          if (given_id - uVar16 != 2) goto LAB_0002d62a;
          goto LAB_0002d756;
        }
        goto LAB_0002d75e;
      }
      goto LAB_0002daea;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
      bVar22 = uVar16 <= given_id - 2;
      bVar21 = given_id - 2 == uVar16;
      if (bVar22 && !bVar21) {
        bVar22 = given_id <= uVar16;
        bVar21 = uVar16 == given_id;
      }
      if (!bVar22 || bVar21) goto LAB_0002daa2;
      bVar21 = true;
joined_r0x0002d606:
      if ((bVar21) && (opt_log_level < 7)) goto LAB_0002d62a;
LAB_0002d60c:
      __format = "%s: job_id error ...\n";
      uVar8 = DAT_0002d71c;
LAB_0002d616:
      snprintf(acStack_828,0x800,__format,uVar8);
      _applog(7,acStack_828,0);
      goto LAB_0002d62a;
    }
    snprintf(acStack_828,0x800,"%s: Chain ID J%d ...\n",DAT_0002dc90,iVar14 + 1);
    _applog(7,acStack_828,0);
    if (given_id < uVar16 && uVar16 < given_id - 2) {
      if (opt_debug != '\0') {
        if (use_syslog == '\0') {
          bVar21 = opt_log_output == '\0';
          goto joined_r0x0002d606;
        }
        goto LAB_0002d60c;
      }
      goto LAB_0002d62a;
    }
    if (opt_debug == '\0') goto LAB_0002d742;
LAB_0002daa2:
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
      if (given_id - uVar16 == 1) {
LAB_0002daea:
        piVar18 = (int *)((int)__mutex + 0xa18);
      }
      else if (given_id != uVar16) {
        if (given_id - uVar16 != 2) {
LAB_0002db4e:
          if (opt_log_level < 7) goto LAB_0002d62a;
LAB_0002dade:
          __format = "%s: job_id non\'t found ...\n";
          uVar8 = DAT_0002dc90;
          goto LAB_0002d616;
        }
LAB_0002d756:
        piVar18 = (int *)((int)__mutex + 0x1150);
      }
    }
    else {
      snprintf(acStack_828,0x800,"%s: given_id:%d job_id:%d switch:%d  ...\n",DAT_0002dc90,given_id,
               uVar16,given_id - uVar16);
      _applog(7,acStack_828,0);
      if (given_id - uVar16 == 1) goto LAB_0002daea;
      if (given_id != uVar16) {
        if (given_id - uVar16 == 2) goto LAB_0002d756;
        if (opt_debug != '\0') {
          if ((use_syslog == '\0') && (opt_log_output == '\0')) goto LAB_0002db4e;
          goto LAB_0002dade;
        }
        goto LAB_0002d62a;
      }
    }
LAB_0002d75e:
    get_work_by_nonce2(param_1,&local_954,piVar18,*(undefined4 *)(pools + *piVar18 * 4),uVar8,uVar13
                       ,uVar20);
    uVar16 = local_954;
    uVar23 = *(undefined8 *)(local_954 + 0x138);
    DVar24 = (DFtype)__fixunsdfdi(a);
    pDVar4 = DAT_0002dc98;
    if ((int)((ulonglong)DVar24 >> 0x20) != *(int *)((int)DAT_0002dc98 + 4) ||
        SUB84(DVar24,0) != *(int *)DAT_0002dc98) {
      *(undefined4 *)(DAT_0002dc98 + 1) = 0;
      *(undefined4 *)((int)pDVar4 + 0xc) = 0;
      *pDVar4 = DVar24;
      cVar6 = opt_debug;
      if (DVar24 == 0.0) {
        iVar7 = -1;
        iVar17 = -1;
      }
      else {
        uVar20 = 1;
        iVar7 = 0;
        DVar1 = DVar24;
        do {
          iVar17 = iVar7;
          uVar11 = uVar20;
          uVar15 = (uint)((ulonglong)DVar1 >> 0x21);
          uVar10 = (uint)(((ulonglong)DVar1 & 0x100000000) != 0) << 0x1f | SUB84(DVar1,0) >> 1;
          DVar1 = (DFtype)CONCAT44(uVar15,uVar10);
          uVar20 = uVar11 + 1;
          iVar7 = iVar17 + (uint)(0xfffffffe < uVar11);
        } while ((uVar10 | uVar15) != 0);
        iVar7 = uVar11 - 1;
        iVar17 = iVar17 + -1 + (uint)(uVar11 != 0);
      }
      *(int *)(pDVar4 + 1) = iVar7;
      *(int *)((int)pDVar4 + 0xc) = iVar17;
      if ((cVar6 != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s: pool_diff:%d work_diff:%d pool_diff_bit:%d ...\n",
                 DAT_0002dc8c,DVar24,uVar23,iVar7,iVar17);
        _applog(7,acStack_828,0);
        a = DVar24;
      }
    }
    uVar23 = current_diff;
    UVar25 = __fixunsdfdi(a);
    pUVar5 = DAT_0002dc9c;
    if ((int)(UVar25 >> 0x20) != *(int *)((int)DAT_0002dc9c + 4) ||
        (int)UVar25 != *(int *)DAT_0002dc9c) {
      *DAT_0002dc9c = UVar25;
      cVar6 = opt_debug;
      if (UVar25 == 0) {
        iVar7 = -1;
        iVar17 = -1;
      }
      else {
        uVar20 = 1;
        iVar7 = 0;
        uVar2 = UVar25;
        do {
          iVar17 = iVar7;
          uVar15 = uVar20;
          uVar10 = (uint)(uVar2 >> 0x21);
          uVar11 = (uint)((uVar2 & 0x100000000) != 0) << 0x1f | (uint)uVar2 >> 1;
          uVar2 = CONCAT44(uVar10,uVar11);
          uVar20 = uVar15 + 1;
          iVar7 = iVar17 + (uint)(0xfffffffe < uVar15);
        } while ((uVar11 | uVar10) != 0);
        iVar7 = uVar15 - 1;
        iVar17 = iVar17 + -1 + (uint)(uVar15 != 0);
      }
      *(int *)(pUVar5 + 1) = iVar7;
      *(int *)((int)pUVar5 + 0xc) = iVar17;
      if ((cVar6 != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s:net_diff:%d current_diff:%d net_diff_bit %d ...\n",
                 DAT_0002dc8c,UVar25,uVar23,iVar7,iVar17);
        _applog(7,acStack_828,0);
      }
    }
    local_908 = *(undefined4 *)(uVar16 + 0x80);
    uStack_904 = *(undefined4 *)(uVar16 + 0x84);
    uStack_900 = *(undefined4 *)(uVar16 + 0x88);
    uStack_8fc = *(undefined4 *)(uVar16 + 0x8c);
    local_8f8 = *(undefined4 *)(uVar16 + 0x90);
    uStack_8f4 = *(undefined4 *)(uVar16 + 0x94);
    uStack_8f0 = *(undefined4 *)(uVar16 + 0x98);
    uStack_8ec = *(undefined4 *)(uVar16 + 0x9c);
    local_90c = 0;
    uVar20 = *(uint *)(uVar16 + 0x40);
    local_910 = 0x50;
    local_8dc = uVar19 << 0x18 | (uVar19 >> 8 & 0xff) << 0x10 | (uVar19 >> 0x10 & 0xff) << 8 |
                uVar19 >> 0x18;
    local_950[1] = *(uint *)(uVar16 + 0x44);
    local_950[2] = *(uint *)(uVar16 + 0x48);
    local_8e8 = uVar20 << 0x18 | (uVar20 >> 8 & 0xff) << 0x10 | (uVar20 >> 0x10 & 0xff) << 8 |
                uVar20 >> 0x18;
    local_8e4 = local_950[1] << 0x18 | (local_950[1] >> 8 & 0xff) << 0x10 |
                (local_950[1] >> 0x10 & 0xff) << 8 | local_950[1] >> 0x18;
    local_8e0 = local_950[2] << 0x18 | (local_950[2] >> 8 & 0xff) << 0x10 |
                (local_950[2] >> 0x10 & 0xff) << 8 | local_950[2] >> 0x18;
    local_950[0] = uVar19;
    sha2_finish(&local_910,local_950);
    memset(&local_910,0,0xe8);
    sha2(local_950,0x20,local_938 + 2);
    puVar3 = DAT_0002dc94;
    puVar9 = &local_954;
    puVar12 = local_938 + 1;
    do {
      puVar12 = puVar12 + 1;
      uVar20 = *puVar12;
      puVar9 = puVar9 + 1;
      *puVar9 = uVar20 << 0x18 | (uVar20 >> 8 & 0xff) << 0x10 | (uVar20 >> 0x10 & 0xff) << 8 |
                uVar20 >> 0x18;
    } while (puVar12 != local_938 + 9);
    if (local_938[1] == 0) {
      puVar9 = local_938 + 1;
      uVar20 = 0;
      do {
        puVar9 = puVar9 + -1;
        if (*puVar9 != 0) {
          uVar11 = (int)uVar20 >> 0x1f;
          goto LAB_0002db84;
        }
        uVar20 = uVar20 + 1;
      } while (uVar20 != 7);
      uVar20 = 7;
      uVar11 = 0;
LAB_0002db84:
      uVar15 = *DAT_0002dc94;
      local_970 = uVar15 >> 5 | DAT_0002dc94[1] << 0x1b;
      uVar10 = DAT_0002dc94[1] >> 5;
      bVar21 = uVar10 <= uVar11;
      if (uVar11 == uVar10) {
        bVar21 = local_970 <= uVar20;
      }
      if (!bVar21) goto LAB_0002d970;
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s: chain %d which_asic_nonce %d which_core_nonce %d",
                 DAT_0002dc8c,iVar14,uVar19 / 0x3000000,uVar19 & 0x7f);
        _applog(7,acStack_828,0);
        uVar15 = *puVar3;
        local_970 = uVar15 >> 5 | puVar3[1] << 0x1b;
      }
      iVar7 = dev + (uVar19 / 0x3000000 + iVar14 * 0x80) * 8;
      uVar20 = *(uint *)(iVar7 + 0xafc);
      *(uint *)(iVar7 + 0xafc) = uVar20 + 1;
      *(uint *)(iVar7 + 0xb00) = *(int *)(iVar7 + 0xb00) + (uint)(0xfffffffe < uVar20);
      uVar20 = local_938[-local_970];
      if ((uVar20 << 0x18 | (uVar20 >> 8 & 0xff) << 0x10 | (uVar20 >> 0x10 & 0xff) << 8 |
          uVar20 >> 0x18) < 0xffffffffU >> (uVar15 & 0x1f)) {
        uVar20 = 0x100;
        submit_nonce(param_1,uVar16,uVar19);
      }
      else {
        if (0xfffffe <
            (local_938[0] << 0x18 | (local_938[0] >> 8 & 0xff) << 0x10 |
             (local_938[0] >> 0x10 & 0xff) << 8 | local_938[0] >> 0x18)) goto LAB_0002d970;
        uVar20 = 0x100;
      }
    }
    else {
      if (*(int *)(dev + (iVar14 + 2) * 4) == 1) {
        inc_hw_errors(param_1);
        iVar7 = dev + iVar14 * 4;
        *(int *)(iVar7 + 0xabc) = *(int *)(iVar7 + 0xabc) + 1;
      }
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"%s: HASH2_32[7] != 0",DAT_0002dc8c);
        _applog(7,acStack_828,0);
      }
LAB_0002d970:
      uVar20 = 0;
    }
    bVar21 = CARRY4(uVar20,h);
    h = uVar20 + h;
    DAT_00704ab4 = DAT_00704ab4 + bVar21;
    _free_work(&local_954,"driver-btm-c5.c",DAT_0002dc88,0x421a);
  } while( true );
}

