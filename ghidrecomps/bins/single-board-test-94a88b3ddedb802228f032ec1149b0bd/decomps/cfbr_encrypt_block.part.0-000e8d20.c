
void cfbr_encrypt_block_part_0
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,uint *param_5,
               int param_6,code *param_7)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  uint *puVar16;
  uint *puVar17;
  uint *puVar18;
  byte *pbVar19;
  uint uVar20;
  uint uVar21;
  byte bVar22;
  uint uVar23;
  int iVar24;
  uint *puVar25;
  uint uVar26;
  uint *puVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  byte *pbVar32;
  uint *puVar33;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  byte local_3c [24];
  
  local_4c = *param_5;
  uStack_48 = param_5[1];
  uStack_44 = param_5[2];
  uStack_40 = param_5[3];
  (*param_7)(param_5,param_5,param_4);
  uVar28 = param_3 + 7;
  uVar31 = param_3 + 0xe;
  if (-1 < (int)uVar28) {
    uVar31 = uVar28;
  }
  uVar31 = (int)uVar31 >> 3;
  if (param_6 == 0) {
    if (0 < (int)uVar31) {
      uVar20 = uVar31 >> 2;
      uVar23 = uVar31 & 0xfffffffc;
      if (uVar20 == 0 ||
          ((((uint)param_2 | (uint)param_1 | (uint)param_5) & 3) != 0 ||
          ((uVar31 < 4 || param_2 < param_1 + 1 && param_1 < param_2 + 1) ||
          param_5 < param_2 + 1 && param_2 < param_5 + 1))) {
        uVar23 = 0;
      }
      else {
        if (uVar20 < 9) {
          pbVar32 = local_3c;
          uVar21 = 0;
          puVar25 = param_1;
          puVar27 = param_5;
          puVar33 = param_2;
        }
        else {
          puVar18 = param_2 + 8;
          pbVar19 = &stack0xffffffe4;
          uVar30 = 0;
          puVar16 = param_1;
          puVar17 = param_5;
          do {
            pbVar32 = pbVar19;
            puVar33 = puVar18;
            puVar27 = puVar17 + 8;
            puVar25 = puVar16 + 8;
            uVar29 = *puVar16;
            uVar21 = uVar30 + 8;
            uVar26 = uVar30 + 9;
            HintPreloadData(puVar16 + 0x11);
            HintPreloadData(pbVar32 + 0x24);
            *(uint *)(pbVar32 + -0x20) = uVar29;
            puVar33[-8] = uVar29 ^ *puVar17;
            uVar30 = puVar16[1];
            *(uint *)(pbVar32 + -0x1c) = uVar30;
            puVar33[-7] = uVar30 ^ puVar17[1];
            uVar30 = puVar16[2];
            *(uint *)(pbVar32 + -0x18) = uVar30;
            puVar33[-6] = uVar30 ^ puVar17[2];
            uVar30 = puVar16[3];
            *(uint *)(pbVar32 + -0x14) = uVar30;
            puVar33[-5] = uVar30 ^ puVar17[3];
            uVar30 = puVar16[4];
            *(uint *)(pbVar32 + -0x10) = uVar30;
            puVar33[-4] = uVar30 ^ puVar17[4];
            uVar30 = puVar16[5];
            *(uint *)(pbVar32 + -0xc) = uVar30;
            puVar33[-3] = uVar30 ^ puVar17[5];
            uVar30 = puVar16[6];
            *(uint *)(pbVar32 + -8) = uVar30;
            puVar33[-2] = uVar30 ^ puVar17[6];
            uVar30 = puVar16[7];
            *(uint *)(pbVar32 + -4) = uVar30;
            puVar33[-1] = uVar30 ^ puVar17[7];
            puVar18 = puVar33 + 8;
            pbVar19 = pbVar32 + 0x20;
            uVar30 = uVar21;
            puVar16 = puVar25;
            puVar17 = puVar27;
          } while (uVar26 < uVar20 - 7);
        }
        iVar24 = 0;
        do {
          uVar30 = *(uint *)((int)puVar25 + iVar24);
          uVar21 = uVar21 + 1;
          *(uint *)(pbVar32 + iVar24) = uVar30;
          *(uint *)((int)puVar33 + iVar24) = uVar30 ^ *(uint *)((int)puVar27 + iVar24);
          iVar24 = iVar24 + 4;
        } while (uVar21 < uVar20);
        if (uVar31 == uVar23) goto LAB_000e8f0c;
      }
      do {
        bVar22 = *(byte *)((int)param_1 + uVar23);
        bVar15 = *(byte *)((int)param_5 + uVar23);
        local_3c[uVar23] = bVar22;
        *(byte *)((int)param_2 + uVar23) = bVar22 ^ bVar15;
        uVar23 = uVar23 + 1;
      } while ((int)uVar23 < (int)uVar31);
    }
  }
  else if (0 < (int)uVar31) {
    uVar20 = uVar31 >> 2;
    uVar23 = uVar31 & 0xfffffffc;
    if (uVar20 == 0 ||
        ((((uint)param_2 | (uint)param_1 | (uint)param_5) & 3) != 0 ||
        ((uVar31 < 4 || param_2 < param_1 + 1 && param_1 < param_2 + 1) ||
        param_5 < param_2 + 1 && param_2 < param_5 + 1))) {
      uVar23 = 0;
    }
    else {
      if (uVar20 < 9) {
        pbVar32 = local_3c;
        uVar21 = 0;
        puVar25 = param_2;
        puVar27 = param_1;
        puVar33 = param_5;
      }
      else {
        uVar21 = 0;
        puVar18 = param_2 + 8;
        pbVar19 = &stack0xffffffe4;
        puVar16 = param_1;
        puVar17 = param_5;
        do {
          pbVar32 = pbVar19;
          puVar25 = puVar18;
          puVar33 = puVar17 + 8;
          puVar27 = puVar16 + 8;
          uVar26 = *puVar17;
          uVar29 = uVar21 + 9;
          uVar30 = *puVar16;
          uVar21 = uVar21 + 8;
          HintPreloadData(puVar16 + 0x11);
          HintPreloadData(puVar17 + 0x11);
          *(uint *)(pbVar32 + -0x20) = uVar30 ^ uVar26;
          puVar25[-8] = uVar30 ^ uVar26;
          uVar26 = puVar17[1];
          uVar30 = puVar16[1];
          *(uint *)(pbVar32 + -0x1c) = uVar30 ^ uVar26;
          puVar25[-7] = uVar30 ^ uVar26;
          uVar26 = puVar16[2];
          uVar30 = puVar17[2];
          *(uint *)(pbVar32 + -0x18) = uVar30 ^ uVar26;
          puVar25[-6] = uVar30 ^ uVar26;
          uVar26 = puVar17[3];
          uVar30 = puVar16[3];
          *(uint *)(pbVar32 + -0x14) = uVar30 ^ uVar26;
          puVar25[-5] = uVar30 ^ uVar26;
          uVar26 = puVar17[4];
          uVar30 = puVar16[4];
          *(uint *)(pbVar32 + -0x10) = uVar30 ^ uVar26;
          puVar25[-4] = uVar30 ^ uVar26;
          uVar26 = puVar17[5];
          uVar30 = puVar16[5];
          *(uint *)(pbVar32 + -0xc) = uVar30 ^ uVar26;
          puVar25[-3] = uVar30 ^ uVar26;
          uVar26 = puVar17[6];
          uVar30 = puVar16[6];
          *(uint *)(pbVar32 + -8) = uVar30 ^ uVar26;
          puVar25[-2] = uVar30 ^ uVar26;
          uVar26 = puVar16[7];
          uVar30 = puVar17[7];
          *(uint *)(pbVar32 + -4) = uVar30 ^ uVar26;
          puVar25[-1] = uVar30 ^ uVar26;
          puVar18 = puVar25 + 8;
          pbVar19 = pbVar32 + 0x20;
          puVar16 = puVar27;
          puVar17 = puVar33;
        } while (uVar29 < uVar20 - 7);
      }
      iVar24 = 0;
      do {
        uVar21 = uVar21 + 1;
        uVar30 = *(uint *)((int)puVar33 + iVar24) ^ *(uint *)((int)puVar27 + iVar24);
        *(uint *)(pbVar32 + iVar24) = uVar30;
        *(uint *)((int)puVar25 + iVar24) = uVar30;
        iVar24 = iVar24 + 4;
      } while (uVar21 < uVar20);
      if (uVar31 == uVar23) goto LAB_000e8f0c;
    }
    do {
      bVar22 = *(byte *)((int)param_1 + uVar23) ^ *(byte *)((int)param_5 + uVar23);
      *(byte *)((int)param_2 + uVar23) = bVar22;
      uVar20 = uVar23 + 1;
      local_3c[uVar23] = bVar22;
      uVar23 = uVar20;
    } while ((int)uVar20 < (int)uVar31);
  }
LAB_000e8f0c:
  uVar31 = param_3 & ~((int)param_3 >> 0x20);
  if ((int)param_3 < 0) {
    uVar31 = uVar28;
  }
  iVar24 = (int)uVar31 >> 3;
  param_3 = (int)param_3 % 8;
  if (param_3 == 0) {
    uVar31 = *(uint *)((int)&uStack_48 + iVar24);
    uVar28 = *(uint *)((int)&uStack_44 + iVar24);
    uVar23 = *(uint *)(local_3c + iVar24 + -4);
    *param_5 = *(uint *)((int)&local_4c + iVar24);
    param_5[1] = uVar31;
    param_5[2] = uVar28;
    param_5[3] = uVar23;
  }
  else {
    uVar31 = 8 - param_3;
    bVar22 = *(byte *)((int)&local_4c + iVar24 + 2);
    bVar15 = *(byte *)((int)&uStack_48 + iVar24 + 3);
    bVar1 = *(byte *)((int)&local_4c + iVar24 + 1);
    bVar2 = *(byte *)((int)&local_4c + iVar24 + 3);
    bVar3 = *(byte *)((int)&uStack_44 + iVar24);
    bVar4 = *(byte *)((int)&uStack_48 + iVar24);
    bVar5 = *(byte *)((int)&uStack_48 + iVar24 + 1);
    bVar6 = *(byte *)((int)&uStack_44 + iVar24 + 1);
    bVar7 = *(byte *)((int)&uStack_48 + iVar24 + 2);
    bVar8 = *(byte *)((int)&uStack_44 + iVar24 + 2);
    *(byte *)param_5 =
         (byte)((int)(uint)bVar1 >> (uVar31 & 0xff)) |
         *(char *)((int)&local_4c + iVar24) << (param_3 & 0xff);
    bVar9 = local_3c[iVar24 + -1];
    bVar10 = *(byte *)((int)&uStack_44 + iVar24 + 3);
    bVar11 = local_3c[iVar24 + -3];
    bVar12 = local_3c[iVar24 + -4];
    *(byte *)((int)param_5 + 2) =
         bVar22 << (param_3 & 0xff) | (byte)((int)(uint)bVar2 >> (uVar31 & 0xff));
    bVar13 = local_3c[iVar24 + -2];
    bVar14 = local_3c[iVar24];
    *(byte *)((int)param_5 + 1) =
         bVar1 << (param_3 & 0xff) | (byte)((int)(uint)bVar22 >> (uVar31 & 0xff));
    *(byte *)((int)param_5 + 3) =
         bVar2 << (param_3 & 0xff) | (byte)((int)(uint)bVar4 >> (uVar31 & 0xff));
    *(byte *)(param_5 + 1) = bVar4 << (param_3 & 0xff) | (byte)((int)(uint)bVar5 >> (uVar31 & 0xff))
    ;
    *(byte *)((int)param_5 + 5) =
         bVar5 << (param_3 & 0xff) | (byte)((int)(uint)bVar7 >> (uVar31 & 0xff));
    *(byte *)((int)param_5 + 6) =
         bVar7 << (param_3 & 0xff) | (byte)((int)(uint)bVar15 >> (uVar31 & 0xff));
    *(byte *)(param_5 + 2) = bVar3 << (param_3 & 0xff) | (byte)((int)(uint)bVar6 >> (uVar31 & 0xff))
    ;
    *(byte *)((int)param_5 + 7) =
         (byte)((int)(uint)bVar3 >> (uVar31 & 0xff)) | bVar15 << (param_3 & 0xff);
    *(byte *)((int)param_5 + 9) =
         (byte)((int)(uint)bVar8 >> (uVar31 & 0xff)) | bVar6 << (param_3 & 0xff);
    *(byte *)(param_5 + 3) =
         (byte)((int)(uint)bVar11 >> (uVar31 & 0xff)) | bVar12 << (param_3 & 0xff);
    *(byte *)((int)param_5 + 10) =
         bVar8 << (param_3 & 0xff) | (byte)((int)(uint)bVar10 >> (uVar31 & 0xff));
    *(byte *)((int)param_5 + 0xb) =
         bVar10 << (param_3 & 0xff) | (byte)((int)(uint)bVar12 >> (uVar31 & 0xff));
    *(byte *)((int)param_5 + 0xd) =
         bVar11 << (param_3 & 0xff) | (byte)((int)(uint)bVar13 >> (uVar31 & 0xff));
    *(byte *)((int)param_5 + 0xe) =
         (byte)((int)(uint)bVar9 >> (uVar31 & 0xff)) | bVar13 << (param_3 & 0xff);
    *(byte *)((int)param_5 + 0xf) =
         bVar9 << (param_3 & 0xff) | (byte)((int)(uint)bVar14 >> (uVar31 & 0xff));
  }
  return;
}

