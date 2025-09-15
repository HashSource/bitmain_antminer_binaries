
int file_do(int *param_1,undefined1 *param_2)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  ushort **ppuVar4;
  uint uVar5;
  char *pcVar6;
  size_t sVar7;
  void *__buf;
  uint uVar8;
  size_t sVar9;
  int iVar10;
  byte *__nptr;
  undefined4 *puVar11;
  int iVar12;
  void *pvVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  longlong lVar18;
  longlong lVar19;
  __off64_t _Var20;
  undefined8 uVar21;
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
  stat64 sStack_90;
  
  iVar12 = *param_1;
  bVar2 = true;
  curlx_tvnow(&local_cc);
  *param_2 = 1;
  Curl_initinfo(iVar12);
  Curl_pgrsStartNow(iVar12);
  if (*(char *)(iVar12 + 0x309) != '\0') {
    iVar3 = *param_1;
    puVar11 = *(undefined4 **)(iVar3 + 0x14c);
    pvVar13 = (void *)(iVar3 + 0x59c);
    pcVar6 = strchr((char *)*puVar11,0x2f);
    curlx_tvnow(&local_c4);
    iVar12 = *param_1;
    *(void **)(iVar12 + 0x144) = pvVar13;
    if ((pcVar6 == (char *)0x0) || (pcVar6[1] == '\0')) {
      return 0x25;
    }
    iVar10 = 0x441;
    if (*(int *)(iVar3 + 0x8698) == 0 && *(int *)(iVar3 + 0x869c) == 0) {
      iVar10 = 0x241;
    }
    iVar12 = open64((char *)*puVar11,iVar10,*(undefined4 *)(iVar12 + 0x334));
    if (iVar12 < 0) {
      Curl_failf(iVar3,"Can\'t open %s for writing",*puVar11);
      return 0x17;
    }
    if (*(int *)(iVar3 + 0x86b4) != -1 || *(int *)(iVar3 + 0x86b0) != -1) {
      Curl_pgrsSetUploadSize(iVar3);
    }
    if (*(int *)(iVar3 + 0x869c) < 0) {
      iVar10 = __fxstat64(3,iVar12,&sStack_90);
      if (iVar10 != 0) {
        close(iVar12);
        Curl_failf(iVar3,"Can\'t get the size of %s",*puVar11);
        return 0x17;
      }
      *(uint *)(iVar3 + 0x8698) = (uint)sStack_90.st_size;
      *(int *)(iVar3 + 0x869c) = sStack_90.st_size._4_4_;
    }
    while (iVar10 = Curl_fillreadbuffer(param_1,0x4000,&local_d8), iVar10 == 0) {
      iVar10 = (int)local_d8 >> 0x1f;
      if ((int)local_d8 < 1) {
        iVar3 = Curl_pgrsUpdate(param_1);
        if (iVar3 == 0) {
          iVar10 = 0;
        }
        else {
          iVar10 = 0x2a;
        }
        break;
      }
      uVar8 = *(uint *)(iVar3 + 0x8698);
      iVar15 = *(int *)(iVar3 + 0x869c);
      __buf = pvVar13;
      sVar9 = local_d8;
      if (uVar8 != 0 || iVar15 != 0) {
        sVar9 = local_d8 - uVar8;
        __buf = (void *)(iVar3 + uVar8 + 0x59c);
        if ((int)((iVar15 - iVar10) - (uint)(uVar8 < local_d8)) < 0 ==
            (SBORROW4(iVar15,iVar10) != SBORROW4(iVar15 - iVar10,(uint)(uVar8 < local_d8)))) {
          *(uint *)(iVar3 + 0x8698) = uVar8 - local_d8;
          *(uint *)(iVar3 + 0x869c) = (iVar15 - iVar10) - (uint)(uVar8 < local_d8);
          sVar9 = 0;
          __buf = pvVar13;
        }
        else {
          *(undefined4 *)(iVar3 + 0x8698) = 0;
          *(undefined4 *)(iVar3 + 0x869c) = 0;
        }
      }
      sVar7 = write(iVar12,__buf,sVar9);
      if (sVar9 != sVar7) {
        iVar10 = 0x37;
        break;
      }
      Curl_pgrsSetUploadCounter(iVar3);
      iVar10 = Curl_pgrsUpdate(param_1);
      if (iVar10 != 0) {
        iVar10 = 0x2a;
        break;
      }
      iVar10 = Curl_speedcheck(iVar3,local_c4,uStack_c0);
      if (iVar10 != 0) break;
    }
    close(iVar12);
    return iVar10;
  }
  iVar10 = *(int *)(*(int *)(*param_1 + 0x14c) + 8);
  iVar3 = __fxstat64(3,iVar10,&sStack_90);
  if (iVar3 == -1) {
    local_f0 = 0;
    iStack_ec = 0;
    bVar2 = false;
  }
  else {
    local_f0 = (uint)sStack_90.st_size;
    iStack_ec = sStack_90.st_size._4_4_;
    *(__time_t *)(iVar12 + 0x8700) = sStack_90.st_mtim.tv_sec;
    if (((*(int *)(iVar12 + 0x8694) == 0) && (*(int *)(iVar12 + 0x270) != 0)) &&
       (iVar3 = Curl_meets_timecondition(iVar12), iVar3 == 0)) {
      *param_2 = 1;
      return 0;
    }
  }
  pvVar13 = (void *)(iVar12 + 0x59c);
  if (((*(char *)(iVar12 + 0x307) != '\0') && (*(char *)(iVar12 + 0x304) != '\0')) && (bVar2)) {
    curl_msnprintf(pvVar13,0x4001,"Content-Length: %lld\r\n",*(char *)(iVar12 + 0x304),local_f0,
                   iStack_ec);
    iVar3 = Curl_client_write(param_1,3,pvVar13,0);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = Curl_client_write(param_1,3,"Accept-ranges: bytes\r\n",0);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = Curl_gmtime(sStack_90.st_mtim.tv_sec,&local_bc);
    if (iVar3 != 0) {
      return iVar3;
    }
    if (local_a4 == 0) {
      local_a4 = 6;
    }
    else {
      local_a4 = local_a4 + -1;
    }
    curl_msnprintf(pvVar13,0x3fff,"Last-Modified: %s, %02d %s %4d %02d:%02d:%02d GMT\r\n",
                   (&Curl_wkday)[local_a4],local_b0,*(undefined4 *)(Curl_month + local_ac * 4),
                   local_a8 + 0x76c,local_b4,local_b8,local_bc);
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
    uVar8 = (uint)*local_d4;
    if (uVar8 != 0) {
      ppuVar4 = __ctype_b_loc();
      do {
        if ((-1 < (int)((uint)(*ppuVar4)[uVar8] << 0x12)) && (uVar8 != 0x2d)) break;
        local_d4 = __nptr + 1;
        uVar8 = (uint)__nptr[1];
        __nptr = local_d4;
      } while (uVar8 != 0);
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
  uVar8 = *(uint *)(iVar12 + 0x8698);
  iVar3 = *(int *)(iVar12 + 0x869c);
  if (iVar3 < 0) {
    if (!bVar2) {
      Curl_failf(iVar12,"Can\'t get the size of file.");
      return 0x1a;
    }
    bVar17 = CARRY4(uVar8,(uint)sStack_90.st_size);
    uVar8 = uVar8 + (uint)sStack_90.st_size;
    iVar3 = iVar3 + sStack_90.st_size._4_4_ + (uint)bVar17;
    *(uint *)(iVar12 + 0x8698) = uVar8;
    *(int *)(iVar12 + 0x869c) = iVar3;
  }
  if ((int)((iStack_ec - iVar3) - (uint)(local_f0 < uVar8)) < 0 !=
      (SBORROW4(iStack_ec,iVar3) != SBORROW4(iStack_ec - iVar3,(uint)(local_f0 < uVar8)))) {
    Curl_failf(iVar12,"failed to resume file:// transfer");
    return 0x24;
  }
  uVar14 = *(uint *)(iVar12 + 0x60);
  iVar15 = *(int *)(iVar12 + 100);
  if (*(int *)(iVar12 + 100) < (int)(uint)(*(uint *)(iVar12 + 0x60) == 0)) {
    uVar14 = local_f0 - uVar8;
    iVar15 = (iStack_ec - iVar3) - (uint)(local_f0 < uVar8);
  }
  bVar17 = (bool)(bVar2 ^ 1);
  if (uVar14 == 0 && iVar15 == 0) {
    bVar17 = true;
  }
  if (bVar17) {
    if (!bVar2) goto LAB_00059fbe;
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  Curl_pgrsSetDownloadSize(iVar12,iVar12 + 0x8600,uVar14,iVar15);
  uVar8 = *(uint *)(iVar12 + 0x8698);
  iVar3 = *(int *)(iVar12 + 0x869c);
LAB_00059fbe:
  if ((uVar8 == 0 && iVar3 == 0) ||
     (_Var20 = lseek64(iVar10,CONCAT44(iVar3,uVar8),0), _Var20 == CONCAT44(iVar3,uVar8))) {
    uVar8 = 0;
    iVar3 = 0;
    Curl_pgrsTime(iVar12,7);
    do {
      if ((bVar2) && ((int)(uint)(0x3ffe < uVar14) <= -iVar15)) {
        sVar9 = curlx_sotouz(uVar14,iVar15);
      }
      else {
        sVar9 = 0x3fff;
      }
      uVar5 = read(iVar10,pvVar13,sVar9);
      if ((int)uVar5 < 1) {
LAB_0005a28e:
        iVar16 = 0;
        break;
      }
      bVar17 = bVar2;
      if (uVar14 != 0 || iVar15 != 0) {
        bVar17 = false;
      }
      *(undefined1 *)(iVar12 + uVar5 + 0x59c) = 0;
      if (bVar17) goto LAB_0005a28e;
      bVar17 = CARRY4(uVar8,uVar5);
      uVar8 = uVar8 + uVar5;
      iVar3 = iVar3 + ((int)uVar5 >> 0x1f) + (uint)bVar17;
      if (bVar2) {
        bVar17 = uVar14 < uVar5;
        uVar14 = uVar14 - uVar5;
        iVar15 = (iVar15 - ((int)uVar5 >> 0x1f)) - (uint)bVar17;
      }
      uVar21 = Curl_client_write(param_1,1,pvVar13,uVar5);
      if ((int)uVar21 != 0) {
        return (int)uVar21;
      }
      Curl_pgrsSetDownloadCounter(iVar12,(int)((ulonglong)uVar21 >> 0x20),uVar8,iVar3);
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

