
/* WARNING: Heritage AFTER dead removal. Example location: s1 : 0x0003e2ec */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int Curl_pgrsUpdate(int *param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  code *pcVar6;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  int iVar7;
  undefined4 *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint *puVar20;
  uint uVar21;
  uint uVar22;
  int *piVar23;
  bool bVar24;
  bool bVar25;
  bool bVar26;
  DFtype in_d0;
  DFtype a;
  DFtype extraout_d0;
  DFtype a_00;
  undefined4 in_s3;
  undefined4 in_s5;
  double dVar27;
  DItype DVar28;
  longlong lVar29;
  undefined8 uVar30;
  longlong lVar31;
  undefined8 local_c0;
  uint *local_b8;
  int *local_b4;
  undefined4 local_9c;
  int local_98;
  int local_94;
  undefined1 auStack_90 [12];
  undefined1 auStack_84 [12];
  undefined1 auStack_78 [12];
  undefined1 auStack_6c [10];
  undefined1 auStack_62 [10];
  undefined1 auStack_58 [10];
  undefined1 auStack_4e [10];
  undefined1 auStack_44 [10];
  undefined1 auStack_3a [14];
  
  iVar15 = *param_1;
  puVar10 = (uint *)(iVar15 + 0x488);
  iVar19 = *(int *)(iVar15 + 0x578);
  curlx_tvnow(&local_98);
  iVar12 = local_98;
  uVar11 = *puVar10;
  uVar14 = *(uint *)(iVar15 + 0x48c);
  dVar27 = (double)(longlong)(local_98 - *(int *)(iVar15 + 0x4f8)) +
           (double)(longlong)(local_94 - *(int *)(iVar15 + 0x4fc)) / 1000000.0;
  *(double *)(iVar15 + 0x4b0) = dVar27;
  __aeabi_l2d(uVar11,uVar14);
  if (dVar27 <= 0.0) {
    local_c0 = __fixdfdi(in_d0);
    uVar22 = *(uint *)(iVar15 + 0x494);
    uVar21 = *(uint *)(iVar15 + 0x490);
    *(DItype *)(iVar15 + 0x4b8) = local_c0;
    __aeabi_l2d(uVar21,uVar22);
  }
  else {
    local_c0 = __fixdfdi(in_d0);
    uVar22 = *(uint *)(iVar15 + 0x494);
    uVar21 = *(uint *)(iVar15 + 0x490);
    *(DItype *)(iVar15 + 0x4b8) = local_c0;
    __aeabi_l2d(uVar21,uVar22);
  }
  local_b4 = (int *)(iVar15 + 0x4b8);
  local_b8 = (uint *)(iVar15 + 0x490);
  DVar28 = __fixdfdi(in_d0);
  iVar7 = (int)((ulonglong)DVar28 >> 0x20);
  uVar18 = (uint)DVar28;
  bVar24 = iVar12 == *(int *)(iVar15 + 0x470);
  *(DItype *)(iVar15 + 0x4c0) = DVar28;
  if (bVar24) {
    iVar7 = 0;
  }
  a_00 = a;
  if (!bVar24) {
    bVar25 = SBORROW4(uVar22,uVar14) != SBORROW4(uVar22 - uVar14,(uint)(uVar21 < uVar11));
    bVar24 = (int)((uVar22 - uVar14) - (uint)(uVar21 < uVar11)) < 0;
    if (bVar24 != bVar25) {
      uVar21 = uVar11;
    }
    *(int *)(iVar15 + 0x470) = iVar12;
    iVar12 = *(int *)(iVar15 + 0x578);
    if (bVar24 != bVar25) {
      uVar22 = uVar14;
    }
    iVar13 = iVar12 + 1;
    *(int *)(iVar15 + 0x578) = iVar13;
    iVar19 = iVar19 % 6;
    iVar17 = iVar19 + 0xa3;
    puVar20 = (uint *)(iVar15 + iVar17 * 8);
    piVar23 = (int *)(iVar15 + (iVar19 + 0xa9) * 8);
    *puVar20 = uVar21;
    puVar20[1] = uVar22;
    *piVar23 = local_98;
    piVar23[1] = local_94;
    if (iVar13 == 1) {
      if ((int)((iVar7 - local_c0._4_4_) - (uint)(uVar18 < (uint)local_c0)) < 0 ==
          (SBORROW4(iVar7,local_c0._4_4_) !=
          SBORROW4(iVar7 - local_c0._4_4_,(uint)(uVar18 < (uint)local_c0)))) {
        *(uint *)(iVar15 + 0x498) = uVar18;
        *(int *)(iVar15 + 0x49c) = iVar7;
        iVar7 = 1;
      }
      else {
        iVar7 = 1;
        *(uint *)(iVar15 + 0x498) = (uint)local_c0;
        *(int *)(iVar15 + 0x49c) = local_c0._4_4_;
      }
    }
    else {
      bVar26 = SBORROW4(iVar13,5);
      bVar24 = iVar12 + -4 < 0;
      bVar25 = iVar13 != 5;
      puVar20 = (uint *)(iVar15 + iVar17 * 8);
      if (5 < iVar13) {
        uVar14 = 0xaaab;
      }
      if (bVar25 && bVar24 == bVar26) {
        uVar11 = uVar14 & 0xffff | 0x2aaa0000;
      }
      else {
        uVar11 = 0;
      }
      lVar29 = CONCAT44(uVar11,local_98);
      if (bVar25 && bVar24 == bVar26) {
        lVar29 = (longlong)(int)uVar11 * (longlong)iVar13;
      }
      iVar12 = (int)((ulonglong)lVar29 >> 0x20);
      if (bVar25 && bVar24 == bVar26) {
        iVar12 = iVar13 + (iVar12 - (iVar13 >> 0x1f)) * -6;
      }
      puVar8 = (undefined4 *)(iVar15 + (iVar12 + 0xa9) * 8);
      iVar19 = curlx_tvdiff(local_98,local_94,*puVar8,puVar8[1]);
      puVar9 = (uint *)(iVar15 + (iVar12 + 0xa3) * 8);
      uVar11 = *puVar20;
      if (iVar19 == 0) {
        iVar19 = 1;
      }
      uVar21 = *puVar9;
      uVar14 = uVar11 - uVar21;
      iVar12 = (puVar20[1] - puVar9[1]) - (uint)(uVar11 < uVar21);
      if (-iVar12 < (int)(uint)(0x418937 < uVar14)) {
        __aeabi_l2d(uVar14,iVar12);
        DVar28 = __fixdfdi(a);
        iVar7 = 1;
        *(DItype *)(iVar15 + 0x498) = DVar28;
        a_00 = extraout_d0;
      }
      else {
        uVar30 = __aeabi_ldivmod((int)((ulonglong)uVar14 * 1000),
                                 iVar12 * 1000 + (int)((ulonglong)uVar14 * 1000 >> 0x20),iVar19,
                                 iVar19 >> 0x1f);
        iVar7 = 1;
        *(undefined8 *)(iVar15 + 0x498) = uVar30;
      }
    }
  }
  uVar11 = *(uint *)(iVar15 + 0x4a8);
  if (-1 < (int)(uVar11 << 0x1b)) {
    pcVar6 = *(code **)(iVar15 + 0x1c4);
    if (pcVar6 == (code *)0x0) {
      pcVar6 = *(code **)(iVar15 + 0x1c0);
      if (pcVar6 == (code *)0x0) {
        if (iVar7 == 0) {
          return 0;
        }
        if (-1 < (int)(uVar11 << 0x18)) {
          if (*(int *)(iVar15 + 0x8698) != 0 || *(int *)(iVar15 + 0x869c) != 0) {
            curl_mfprintf(*(undefined4 *)(iVar15 + 0x150),
                          "** Resuming transfer from byte position %lld\n");
          }
          curl_mfprintf(*(undefined4 *)(iVar15 + 0x150),
                        "  %% Total    %% Received %% Xferd  Average Speed   Time    Time     Time  Current\n                                 Dload  Upload   Total   Spent    Left  Speed\n"
                       );
          uVar11 = *(uint *)(iVar15 + 0x4a8) | 0x80;
          *(uint *)(iVar15 + 0x4a8) = uVar11;
        }
        if ((int)(uVar11 << 0x1a) < 0) {
          if (-*(int *)(iVar15 + 0x4c4) < (int)(uint)(*(int *)(iVar15 + 0x4c0) != 0)) {
            uVar14 = *(uint *)(iVar15 + 0x480);
            iVar12 = *(int *)(iVar15 + 0x484);
            lVar29 = __aeabi_ldivmod(uVar14,iVar12);
            if (-iVar12 < (int)(uint)(10000 < uVar14)) {
              uVar30 = __aeabi_ldivmod(uVar14,iVar12,100,0);
              __aeabi_ldivmod(*local_b8,*(undefined4 *)(iVar15 + 0x494),(int)uVar30,
                              (int)((ulonglong)uVar30 >> 0x20));
            }
            else if (-iVar12 < (int)(uint)(uVar14 != 0)) {
              lVar31 = (ulonglong)*(uint *)(iVar15 + 0x490) * 100;
              __aeabi_ldivmod((int)lVar31,
                              *(int *)(iVar15 + 0x494) * 100 + (int)((ulonglong)lVar31 >> 0x20),
                              uVar14,iVar12);
            }
          }
          else {
            lVar29 = 0;
          }
        }
        else {
          lVar29 = 0;
        }
        iVar12 = (int)((ulonglong)lVar29 >> 0x20);
        if (((int)(uVar11 << 0x19) < 0) && (-*(int *)(iVar15 + 0x4bc) < (int)(uint)(*local_b4 != 0))
           ) {
          uVar11 = *(uint *)(iVar15 + 0x478);
          iVar19 = *(int *)(iVar15 + 0x47c);
          lVar31 = __aeabi_ldivmod(uVar11,iVar19);
          if (-iVar19 < (int)(uint)(10000 < uVar11)) {
            uVar30 = __aeabi_ldivmod(uVar11,iVar19,100,0);
            __aeabi_ldivmod(*puVar10,*(undefined4 *)(iVar15 + 0x48c),(int)uVar30,
                            (int)((ulonglong)uVar30 >> 0x20));
          }
          else if (-iVar19 < (int)(uint)(uVar11 != 0)) {
            lVar1 = (ulonglong)*(uint *)(iVar15 + 0x488) * 100;
            __aeabi_ldivmod((int)lVar1,
                            *(int *)(iVar15 + 0x48c) * 100 + (int)((ulonglong)lVar1 >> 0x20),uVar11,
                            iVar19);
          }
        }
        else {
          lVar31 = 0;
        }
        iVar19 = (int)((ulonglong)lVar31 >> 0x20);
        DVar28 = __fixdfdi(a_00);
        uVar2 = (undefined4)((ulonglong)DVar28 >> 0x20);
        bVar24 = (uint)lVar31 < (uint)lVar29;
        if ((int)((iVar19 - iVar12) - (uint)bVar24) < 0 !=
            (SBORROW4(iVar19,iVar12) != SBORROW4(iVar19 - iVar12,(uint)bVar24))) {
          lVar31 = lVar29;
        }
        iVar12 = (int)((ulonglong)lVar31 >> 0x20);
        lVar29 = 0;
        if (-iVar12 < (int)(uint)((int)lVar31 != 0)) {
          lVar29 = lVar31 - DVar28;
        }
        time2str(auStack_90,uVar2,(int)lVar29,(int)((ulonglong)lVar29 >> 0x20));
        time2str(auStack_84,extraout_r1,(int)lVar31,iVar12);
        time2str(auStack_78,extraout_r1_00,(int)DVar28,uVar2);
        if (*(int *)(iVar15 + 0x4a8) << 0x1a < 0) {
          uVar14 = *local_b8;
          iVar19 = *(int *)(iVar15 + 0x494);
          uVar11 = *(uint *)(iVar15 + 0x480);
          iVar12 = *(int *)(iVar15 + 0x484);
        }
        else {
          uVar14 = *local_b8;
          iVar19 = *(int *)(iVar15 + 0x494);
          uVar11 = uVar14;
          iVar12 = iVar19;
        }
        if (*(int *)(iVar15 + 0x4a8) << 0x19 < 0) {
          uVar22 = *(uint *)(iVar15 + 0x478);
          iVar13 = *(int *)(iVar15 + 0x47c);
          uVar21 = *puVar10;
          iVar7 = *(int *)(iVar15 + 0x48c);
        }
        else {
          uVar22 = *puVar10;
          iVar13 = *(int *)(iVar15 + 0x48c);
          uVar21 = uVar22;
          iVar7 = iVar13;
        }
        uVar18 = uVar11 + uVar22;
        iVar12 = iVar12 + iVar13 + (uint)CARRY4(uVar11,uVar22);
        iVar7 = iVar7 + iVar19 + (uint)CARRY4(uVar21,uVar14);
        if (-iVar12 < (int)(uint)(10000 < uVar18)) {
          uVar30 = __aeabi_ldivmod(uVar18,iVar12,100,0);
          uVar30 = __aeabi_ldivmod(uVar21 + uVar14,iVar7,(int)uVar30,
                                   (int)((ulonglong)uVar30 >> 0x20));
        }
        else if (-iVar12 < (int)(uint)(uVar18 != 0)) {
          lVar29 = (ulonglong)(uVar21 + uVar14) * 100;
          uVar30 = __aeabi_ldivmod((int)lVar29,iVar7 * 100 + (int)((ulonglong)lVar29 >> 0x20),uVar18
                                   ,iVar12);
        }
        else {
          uVar30 = 0;
        }
        local_9c = (undefined4)uVar30;
        uVar2 = *(undefined4 *)(iVar15 + 0x150);
        max5data(uVar18,iVar12,auStack_58);
        max5data(*puVar10,*(undefined4 *)(iVar15 + 0x48c),auStack_6c);
        max5data(*local_b8,*(undefined4 *)(iVar15 + 0x494),auStack_62);
        max5data(*local_b4,*(undefined4 *)(iVar15 + 0x4bc),auStack_4e);
        max5data(*(int *)(iVar15 + 0x4c0),*(undefined4 *)(iVar15 + 0x4c4),auStack_44);
        max5data(*(undefined4 *)(iVar15 + 0x498),*(undefined4 *)(iVar15 + 0x49c),auStack_3a);
        curl_mfprintf(uVar2,"\r%3lld %s  %3lld %s  %3lld %s  %s  %s %s %s %s %s",local_9c,
                      (int)((ulonglong)uVar30 >> 0x20));
        fflush(*(FILE **)(iVar15 + 0x150));
        return 0;
      }
      uVar16 = *(undefined4 *)(iVar15 + 0x1f8);
      uVar2 = __aeabi_l2d(*(undefined4 *)(iVar15 + 0x478),*(undefined4 *)(iVar15 + 0x47c));
      uVar3 = __aeabi_l2d(*puVar10,*(undefined4 *)(iVar15 + 0x48c));
      uVar4 = __aeabi_l2d(*(undefined4 *)(iVar15 + 0x480),*(undefined4 *)(iVar15 + 0x484));
      uVar5 = __aeabi_l2d(*local_b8,*(undefined4 *)(iVar15 + 0x494));
      iVar12 = (*pcVar6)(uVar2,(int)((ulonglong)a_00 >> 0x20),uVar3,in_s3,uVar4,in_s5,uVar5,uVar16);
    }
    else {
      iVar12 = (*pcVar6)(*(undefined4 *)(iVar15 + 0x1f8),pcVar6,*(undefined4 *)(iVar15 + 0x478),
                         *(undefined4 *)(iVar15 + 0x47c));
    }
    if (iVar12 != 0) {
      Curl_failf(iVar15,"Callback aborted");
      return iVar12;
    }
  }
  return 0;
}

