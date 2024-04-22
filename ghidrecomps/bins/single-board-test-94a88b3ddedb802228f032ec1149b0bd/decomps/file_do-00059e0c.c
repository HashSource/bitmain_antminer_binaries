
int file_do(int *param_1,undefined *param_2)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  ushort **ppuVar4;
  char *pcVar5;
  size_t sVar6;
  void *__buf;
  uint uVar7;
  size_t sVar8;
  int iVar9;
  byte *__nptr;
  char **ppcVar10;
  uint uVar11;
  int iVar12;
  void *pvVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  bool bVar17;
  longlong lVar18;
  longlong lVar19;
  __off64_t _Var20;
  undefined8 uVar21;
  uint in_stack_fffffeec;
  uint local_f0;
  int iStack_ec;
  int local_e8;
  int local_e4;
  uint local_d8;
  byte *local_d4;
  byte *local_d0;
  undefined4 local_cc;
  undefined4 uStack_c8;
  undefined4 local_c4;
  undefined4 uStack_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  undefined auStack_90 [52];
  int iStack_5c;
  __time_t local_40;
  
  iVar12 = *param_1;
  bVar2 = true;
  curlx_tvnow(&local_cc);
  *param_2 = 1;
  Curl_initinfo(iVar12);
  Curl_pgrsStartNow(iVar12);
  if (*(char *)(iVar12 + 0x309) != '\0') {
    iVar3 = *param_1;
    ppcVar10 = *(char ***)(iVar3 + 0x14c);
    pvVar13 = (void *)(iVar3 + 0x59c);
    pcVar5 = strchr(*ppcVar10,0x2f);
    curlx_tvnow(&local_c4);
    iVar12 = *param_1;
    *(void **)(iVar12 + 0x144) = pvVar13;
    if ((pcVar5 == (char *)0x0) || (pcVar5[1] == '\0')) {
      return 0x25;
    }
    iVar9 = 0x441;
    if ((*(uint *)(iVar3 + 0x8698) | *(uint *)(iVar3 + 0x869c)) == 0) {
      iVar9 = 0x241;
    }
    iVar12 = open64(*ppcVar10,iVar9,*(undefined4 *)(iVar12 + 0x334));
    if (iVar12 < 0) {
      Curl_failf(iVar3,DAT_0005a398,*ppcVar10);
      return 0x17;
    }
    if (*(int *)(iVar3 + 0x86b4) != -1 || *(int *)(iVar3 + 0x86b0) != -1) {
      Curl_pgrsSetUploadSize(iVar3);
    }
    if (*(int *)(iVar3 + 0x869c) < 0) {
      iVar9 = __fxstat64(3,iVar12,(stat64 *)auStack_90);
      if (iVar9 != 0) {
        close(iVar12);
        Curl_failf(iVar3,DAT_0005a3d4,*ppcVar10);
        return 0x17;
      }
      *(undefined4 *)(iVar3 + 0x8698) = auStack_90._48_4_;
      *(int *)(iVar3 + 0x869c) = iStack_5c;
    }
    while (iVar9 = Curl_fillreadbuffer(param_1,0x4000,&local_d8), iVar9 == 0) {
      iVar9 = (int)local_d8 >> 0x1f;
      if ((int)local_d8 < 1) {
        iVar3 = Curl_pgrsUpdate(param_1);
        if (iVar3 == 0) {
          iVar9 = 0;
        }
        else {
          iVar9 = 0x2a;
        }
        break;
      }
      uVar7 = *(uint *)(iVar3 + 0x8698);
      uVar11 = *(uint *)(iVar3 + 0x869c);
      __buf = pvVar13;
      sVar8 = local_d8;
      if ((uVar7 | uVar11) != 0) {
        sVar8 = local_d8 - uVar7;
        __buf = (void *)(iVar3 + uVar7 + 0x59c);
        if ((int)((uVar11 - iVar9) - (uint)(uVar7 < local_d8)) < 0 ==
            (SBORROW4(uVar11,iVar9) != SBORROW4(uVar11 - iVar9,(uint)(uVar7 < local_d8)))) {
          *(uint *)(iVar3 + 0x8698) = uVar7 - local_d8;
          *(uint *)(iVar3 + 0x869c) = (uVar11 - iVar9) - (uint)(uVar7 < local_d8);
          sVar8 = 0;
          __buf = pvVar13;
        }
        else {
          *(undefined4 *)(iVar3 + 0x8698) = 0;
          *(undefined4 *)(iVar3 + 0x869c) = 0;
        }
      }
      sVar6 = write(iVar12,__buf,sVar8);
      if (sVar8 != sVar6) {
        iVar9 = 0x37;
        break;
      }
      Curl_pgrsSetUploadCounter(iVar3);
      iVar9 = Curl_pgrsUpdate(param_1);
      if (iVar9 != 0) {
        iVar9 = 0x2a;
        break;
      }
      iVar9 = Curl_speedcheck(iVar3,local_c4,uStack_c0);
      if (iVar9 != 0) break;
    }
    close(iVar12);
    return iVar9;
  }
  iVar9 = *(int *)(*(int *)(*param_1 + 0x14c) + 8);
  iVar3 = __fxstat64(3,iVar9,(stat64 *)auStack_90);
  if (iVar3 == -1) {
    local_f0 = 0;
    iStack_ec = 0;
    bVar2 = false;
  }
  else {
    local_f0 = auStack_90._48_4_;
    iStack_ec = iStack_5c;
    *(__time_t *)(iVar12 + 0x8700) = local_40;
    if (((*(int *)(iVar12 + 0x8694) == 0) && (*(int *)(iVar12 + 0x270) != 0)) &&
       (iVar3 = Curl_meets_timecondition(iVar12), iVar3 == 0)) {
      *param_2 = 1;
      return 0;
    }
  }
  pvVar13 = (void *)(iVar12 + 0x59c);
  if (((*(char *)(iVar12 + 0x307) != '\0') && (*(char *)(iVar12 + 0x304) != '\0')) && (bVar2)) {
    curl_msnprintf(pvVar13,0x4001,DAT_0005a380,*(char *)(iVar12 + 0x304),local_f0,iStack_ec);
    iVar3 = Curl_client_write(param_1,3,pvVar13,0);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = Curl_client_write(param_1,3,DAT_0005a384,0);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = Curl_gmtime(local_40,&local_bc);
    if (iVar3 != 0) {
      return iVar3;
    }
    if (local_a4 == 0) {
      local_a4 = 6;
    }
    else {
      local_a4 = local_a4 + -1;
    }
    curl_msnprintf(pvVar13,0x3fff,DAT_0005a390,*(undefined4 *)(DAT_0005a38c + local_a4 * 4),local_b0
                   ,*(undefined4 *)(DAT_0005a388 + local_ac * 4),local_a8 + 0x76c,local_b4,local_b8,
                   local_bc);
    uVar21 = Curl_client_write(param_1,3,pvVar13,0);
    Curl_pgrsSetDownloadSize(iVar12,(int)((ulonglong)uVar21 >> 0x20),local_f0,iStack_ec);
    return (int)uVar21;
  }
  iVar3 = *param_1;
  if ((*(char *)(iVar3 + 0x8691) == '\0') || (*(char **)(iVar3 + 0x8694) == (char *)0x0)) {
    *(undefined4 *)(iVar3 + 0x60) = 0xffffffff;
    *(undefined4 *)(iVar3 + 100) = 0xffffffff;
  }
  else {
    lVar18 = strtoll(*(char **)(iVar3 + 0x8694),(char **)&local_d4,0);
    __nptr = local_d4;
    uVar7 = (uint)*local_d4;
    if (uVar7 != 0) {
      ppuVar4 = __ctype_b_loc();
      do {
        if ((-1 < (int)((uint)(*ppuVar4)[uVar7] << 0x12)) && (uVar7 != 0x2d)) break;
        local_d4 = __nptr + 1;
        uVar7 = (uint)__nptr[1];
        __nptr = local_d4;
      } while (uVar7 != 0);
    }
    lVar19 = strtoll((char *)__nptr,(char **)&local_d0,0);
    lVar1 = lVar19;
    if (local_d4 == local_d0) {
      lVar1 = -1;
    }
    local_e4 = (int)((ulonglong)lVar18 >> 0x20);
    local_e8 = (int)lVar18;
    if (-1 < lVar18 && (local_d4 == local_d0 || lVar19 == -1)) {
      *(int *)(iVar3 + 0x8698) = local_e8;
      *(int *)(iVar3 + 0x869c) = local_e4;
    }
    else if (lVar18 < 0) {
      *(int *)(iVar3 + 0x8698) = local_e8;
      *(int *)(iVar3 + 0x869c) = local_e4;
      *(int *)(iVar3 + 0x60) = -local_e8;
      *(uint *)(iVar3 + 100) = -local_e4 - (uint)(local_e8 != 0);
    }
    else {
      *(int *)(iVar3 + 0x8698) = local_e8;
      *(int *)(iVar3 + 0x869c) = local_e4;
      *(longlong *)(iVar3 + 0x60) = (lVar1 - lVar18) + 1;
    }
  }
  uVar7 = *(uint *)(iVar12 + 0x8698);
  uVar11 = *(uint *)(iVar12 + 0x869c);
  if ((int)uVar11 < 0) {
    if (!bVar2) {
      Curl_failf(iVar12,DAT_0005a394);
      return 0x1a;
    }
    bVar17 = CARRY4(uVar7,auStack_90._48_4_);
    uVar7 = uVar7 + auStack_90._48_4_;
    uVar11 = uVar11 + iStack_5c + (uint)bVar17;
    *(uint *)(iVar12 + 0x8698) = uVar7;
    *(uint *)(iVar12 + 0x869c) = uVar11;
  }
  if ((int)((iStack_ec - uVar11) - (uint)(local_f0 < uVar7)) < 0 !=
      (SBORROW4(iStack_ec,uVar11) != SBORROW4(iStack_ec - uVar11,(uint)(local_f0 < uVar7)))) {
    Curl_failf(iVar12,DAT_0005a37c);
    return 0x24;
  }
  uVar14 = *(uint *)(iVar12 + 0x60);
  uVar15 = *(uint *)(iVar12 + 100);
  if ((int)(uVar15 - (uVar14 == 0)) < 0 != (SBORROW4(uVar15,(uint)(uVar14 == 0)) != false)) {
    uVar14 = local_f0 - uVar7;
    uVar15 = (iStack_ec - uVar11) - (uint)(local_f0 < uVar7);
  }
  bVar17 = (bool)(bVar2 ^ 1);
  if ((uVar14 | uVar15) == 0) {
    bVar17 = true;
  }
  if (bVar17) {
    if (!bVar2) goto LAB_00059fbe;
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  Curl_pgrsSetDownloadSize(iVar12,iVar12 + 0x8600,uVar14,uVar15);
  uVar7 = *(uint *)(iVar12 + 0x8698);
  uVar11 = *(uint *)(iVar12 + 0x869c);
LAB_00059fbe:
  if (((uVar7 | uVar11) == 0) ||
     (_Var20 = lseek64(iVar9,(ulonglong)in_stack_fffffeec << 0x20,iVar12 + 0x8600),
     (uint)((ulonglong)_Var20 >> 0x20) == uVar11 && (uint)_Var20 == uVar7)) {
    uVar7 = 0;
    iVar3 = 0;
    Curl_pgrsTime(iVar12,7);
    do {
      if ((bVar2) &&
         ((int)(-(uint)(0x3ffe < uVar14) - uVar15) < 0 ==
          (SBORROW4(-uVar15,(uint)(0x3ffe < uVar14)) != false))) {
        sVar8 = curlx_sotouz(uVar14,uVar15);
      }
      else {
        sVar8 = 0x3fff;
      }
      uVar11 = read(iVar9,pvVar13,sVar8);
      if ((int)uVar11 < 1) {
LAB_0005a28e:
        iVar16 = 0;
        break;
      }
      bVar17 = bVar2;
      if ((uVar14 | uVar15) != 0) {
        bVar17 = false;
      }
      *(undefined *)(iVar12 + uVar11 + 0x59c) = 0;
      if (bVar17) goto LAB_0005a28e;
      bVar17 = CARRY4(uVar7,uVar11);
      uVar7 = uVar7 + uVar11;
      iVar3 = iVar3 + ((int)uVar11 >> 0x1f) + (uint)bVar17;
      if (bVar2) {
        bVar17 = uVar14 < uVar11;
        uVar14 = uVar14 - uVar11;
        uVar15 = (uVar15 - ((int)uVar11 >> 0x1f)) - (uint)bVar17;
      }
      uVar21 = Curl_client_write(param_1,1,pvVar13,uVar11);
      if ((int)uVar21 != 0) {
        return (int)uVar21;
      }
      Curl_pgrsSetDownloadCounter(iVar12,(int)((ulonglong)uVar21 >> 0x20),uVar7,iVar3);
      iVar16 = Curl_pgrsUpdate(param_1);
      if (iVar16 != 0) {
        iVar16 = 0x2a;
        break;
      }
      iVar16 = Curl_speedcheck(iVar12,local_cc,uStack_c8);
    } while (iVar16 == 0);
    iVar12 = Curl_pgrsUpdate(param_1);
    if (iVar12 != 0) {
      iVar16 = 0x2a;
    }
  }
  else {
    iVar16 = 0x24;
  }
  return iVar16;
}

