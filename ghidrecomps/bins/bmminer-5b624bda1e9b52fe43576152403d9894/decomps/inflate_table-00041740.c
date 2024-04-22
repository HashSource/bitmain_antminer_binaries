
undefined4
inflate_table(uint param_1,int param_2,uint param_3,int *param_4,uint *param_5,int param_6)

{
  int iVar1;
  short sVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  uint uVar8;
  ushort uVar9;
  uint uVar10;
  ushort *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined uVar18;
  ushort *local_94;
  int local_90;
  uint local_84;
  int local_7c;
  uint local_78;
  int local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  ushort auStack_40 [5];
  short local_36;
  short local_34;
  short local_32;
  short local_30;
  short local_2e;
  short local_2c;
  short local_2a;
  short local_28;
  short local_26;
  short local_24;
  short local_22;
  
  uVar10 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  if (param_3 != 0) {
    if (0x10 < param_3) {
      iVar3 = param_2 + 0x2e;
      do {
        uVar15 = uVar10 + 0x11;
        uVar10 = uVar10 + 0x10;
        HintPreloadData(iVar3);
        iVar1 = (uint)*(ushort *)(iVar3 + -0x2e) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        iVar1 = (uint)*(ushort *)(iVar3 + -0x2c) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        iVar1 = (uint)*(ushort *)(iVar3 + -0x2a) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        iVar1 = (uint)*(ushort *)(iVar3 + -0x28) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        iVar1 = (uint)*(ushort *)(iVar3 + -0x26) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        iVar1 = (uint)*(ushort *)(iVar3 + -0x24) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        iVar1 = (uint)*(ushort *)(iVar3 + -0x22) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        iVar1 = (uint)*(ushort *)(iVar3 + -0x20) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        iVar1 = (uint)*(ushort *)(iVar3 + -0x1e) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        iVar1 = (uint)*(ushort *)(iVar3 + -0x1c) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        iVar1 = (uint)*(ushort *)(iVar3 + -0x1a) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        iVar1 = (uint)*(ushort *)(iVar3 + -0x18) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        iVar1 = (uint)*(ushort *)(iVar3 + -0x16) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        iVar1 = (uint)*(ushort *)(iVar3 + -0x14) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        iVar1 = (uint)*(ushort *)(iVar3 + -0x12) * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
        puVar11 = (ushort *)(iVar3 + -0x10);
        iVar3 = iVar3 + 0x20;
        iVar1 = (uint)*puVar11 * 2;
        *(short *)((int)&local_60 + iVar1) = *(short *)((int)&local_60 + iVar1) + 1;
      } while (uVar15 < param_3 - 0xf);
    }
    puVar11 = (ushort *)(param_2 + (uVar10 - 1) * 2);
    do {
      puVar11 = puVar11 + 1;
      uVar10 = uVar10 + 1;
      *(short *)((int)&local_60 + (uint)*puVar11 * 2) =
           *(short *)((int)&local_60 + (uint)*puVar11 * 2) + 1;
    } while (uVar10 < param_3);
  }
  uVar10 = *param_5;
  if (local_44 >> 0x10 == 0) {
    if ((short)local_44 != 0) {
      uVar15 = 0xe;
      goto LAB_00041dde;
    }
    if (local_48._2_2_ != 0) {
      uVar15 = 0xd;
      goto LAB_00041dde;
    }
    if ((short)local_48 != 0) {
      uVar15 = 0xc;
      goto LAB_00041dde;
    }
    if (local_4c._2_2_ != 0) {
      uVar15 = 0xb;
      goto LAB_00041dde;
    }
    if ((short)local_4c != 0) {
      uVar15 = 10;
      goto LAB_00041dde;
    }
    if (local_50._2_2_ != 0) {
      uVar15 = 9;
      goto LAB_00041dde;
    }
    if ((short)local_50 != 0) {
      uVar15 = 8;
      goto LAB_00041dde;
    }
    if (local_54._2_2_ != 0) {
      uVar15 = 7;
      goto LAB_00041dde;
    }
    if ((short)local_54 != 0) {
      uVar15 = 6;
      goto LAB_00041dde;
    }
    if (local_58._2_2_ != 0) {
      uVar15 = 5;
      goto LAB_00041dde;
    }
    if ((short)local_58 != 0) {
      uVar15 = 4;
      goto LAB_00041dde;
    }
    if (local_5c._2_2_ != 0) {
      uVar15 = 3;
      goto LAB_00041dde;
    }
    if ((short)local_5c != 0) {
      uVar15 = 2;
      goto LAB_00041dde;
    }
    if (local_60._2_2_ == 0) {
      puVar4 = (undefined *)*param_4;
      *(undefined2 *)(puVar4 + 2) = 0;
      *(undefined2 *)(puVar4 + 6) = 0;
      *puVar4 = 0x40;
      puVar4[4] = 0x40;
      puVar4[1] = 1;
      puVar4[5] = 1;
      *param_4 = (int)(puVar4 + 8);
      *param_5 = 1;
      return 0;
    }
    if (uVar10 != 0) {
      uVar10 = 1;
    }
    uVar15 = 1;
  }
  else {
    uVar15 = 0xf;
LAB_00041dde:
    if (uVar15 < uVar10) {
      uVar10 = uVar15;
    }
    if (local_60._2_2_ == 0) {
      psVar7 = (short *)((int)&local_60 + 2);
      uVar16 = 1;
      do {
        uVar16 = uVar16 + 1;
        if (uVar16 == uVar15) break;
        psVar7 = psVar7 + 1;
      } while (*psVar7 == 0);
      iVar3 = 2;
      goto LAB_00041a0e;
    }
  }
  iVar3 = 2 - (uint)local_60._2_2_;
  if (iVar3 < 0) {
    return 0xffffffff;
  }
  uVar16 = 1;
LAB_00041a0e:
  iVar3 = iVar3 * 2 - (local_5c & 0xffff);
  if ((((((iVar3 < 0) || (iVar3 = iVar3 * 2 - (uint)local_5c._2_2_, iVar3 < 0)) ||
        (iVar3 = iVar3 * 2 - (local_58 & 0xffff), iVar3 < 0)) ||
       ((iVar3 = iVar3 * 2 - (uint)local_58._2_2_, iVar3 < 0 ||
        (iVar3 = iVar3 * 2 - (local_54 & 0xffff), iVar3 < 0)))) ||
      ((iVar3 = iVar3 * 2 - (uint)local_54._2_2_, iVar3 < 0 ||
       ((iVar3 = iVar3 * 2 - (local_50 & 0xffff), iVar3 < 0 ||
        (iVar3 = iVar3 * 2 - (uint)local_50._2_2_, iVar3 < 0)))))) ||
     ((iVar3 = iVar3 * 2 - (local_4c & 0xffff), iVar3 < 0 ||
      ((((iVar3 = iVar3 * 2 - (uint)local_4c._2_2_, iVar3 < 0 ||
         (iVar3 = iVar3 * 2 - (local_48 & 0xffff), iVar3 < 0)) ||
        (iVar3 = iVar3 * 2 - (uint)local_48._2_2_, iVar3 < 0)) ||
       ((iVar3 = iVar3 * 2 - (local_44 & 0xffff), iVar3 < 0 ||
        (iVar3 = iVar3 * 2 - (local_44 >> 0x10), iVar3 < 0)))))))) {
    return 0xffffffff;
  }
  if (iVar3 != 0) {
    uVar5 = 1 - param_1;
    if (1 < param_1) {
      uVar5 = 0;
    }
    if (uVar15 != 1) {
      uVar5 = uVar5 | 1;
    }
    if (uVar5 != 0) {
      return 0xffffffff;
    }
  }
  uVar5 = 0;
  auStack_40[2] = local_60._2_2_;
  auStack_40[1] = 0;
  auStack_40[4] = local_60._2_2_ + (short)local_5c + local_5c._2_2_;
  auStack_40[3] = local_60._2_2_ + (short)local_5c;
  local_36 = auStack_40[4] + (short)local_58;
  local_34 = local_36 + local_58._2_2_;
  local_32 = local_34 + (short)local_54;
  local_30 = local_32 + local_54._2_2_;
  local_2e = local_30 + (short)local_50;
  local_2c = local_2e + local_50._2_2_;
  local_2a = local_2c + (short)local_4c;
  local_28 = local_2a + local_4c._2_2_;
  local_26 = local_28 + (short)local_48;
  local_24 = local_26 + local_48._2_2_;
  local_22 = local_24 + (short)local_44;
  if (param_3 != 0) {
    puVar11 = (ushort *)(param_2 + -2);
    do {
      puVar11 = puVar11 + 1;
      uVar14 = (uint)*puVar11;
      if (uVar14 != 0) {
        uVar9 = auStack_40[uVar14];
        *(short *)(param_6 + (uint)uVar9 * 2) = (short)uVar5;
        auStack_40[uVar14] = uVar9 + 1;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 != param_3);
  }
  if (param_1 == 0) {
    local_68 = param_6;
    local_64 = param_6;
    local_7c = 0x13;
  }
  else if (param_1 == 1) {
    local_7c = 0x100;
    local_64 = DAT_00041e5c + 0x40;
    local_68 = DAT_00041e5c;
  }
  else {
    local_68 = DAT_00041e58;
    local_7c = -1;
    local_64 = DAT_00041e58 + 0x40;
  }
  if (uVar10 <= uVar16) {
    uVar10 = uVar16;
  }
  local_84 = 1 << (uVar10 & 0xff);
  local_90 = *param_4;
  if ((0x354 < local_84 && param_1 == 1) || (0x250 < local_84 && param_1 == 2)) {
    return 1;
  }
  uVar12 = local_84 - 1;
  local_78 = 0xffffffff;
  uVar5 = 0;
  uVar14 = 0;
  uVar8 = uVar10;
  uVar17 = uVar16;
  local_94 = (ushort *)(param_6 + -2);
  do {
    while( true ) {
      puVar11 = local_94 + 1;
      uVar9 = *puVar11;
      uVar13 = (uint)uVar9;
      if ((int)uVar13 < local_7c) {
        uVar18 = 0;
      }
      else if (local_7c < (int)uVar13) {
        uVar18 = *(undefined *)(local_68 + uVar13 * 2);
        uVar9 = *(ushort *)(local_64 + uVar13 * 2);
      }
      else {
        uVar18 = 0x60;
        uVar9 = 0;
      }
      iVar6 = 1 << (uVar8 & 0xff);
      iVar1 = 1 << (uVar16 & 0xff);
      puVar4 = (undefined *)(local_90 + (((uVar5 >> (uVar14 & 0xff)) + iVar6) - iVar1) * 4);
      iVar3 = iVar6;
      do {
        iVar3 = iVar3 - iVar1;
        *puVar4 = uVar18;
        puVar4[1] = (char)uVar16;
        *(ushort *)(puVar4 + 2) = uVar9;
        puVar4 = puVar4 + iVar1 * -4;
      } while (iVar3 != 0);
      for (uVar13 = 1 << (uVar17 - 1 & 0xff); (uVar13 & uVar5) != 0; uVar13 = uVar13 >> 1) {
      }
      if (uVar13 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = (uVar5 & uVar13 - 1) + uVar13;
      }
      sVar2 = *(short *)((int)&local_60 + uVar17 * 2) + -1;
      *(short *)((int)&local_60 + uVar17 * 2) = sVar2;
      if (sVar2 == 0) {
        if (uVar17 == uVar15) {
          if (uVar5 != 0) {
            *(undefined *)(local_90 + uVar5 * 4) = 0x40;
            local_90 = local_90 + uVar5 * 4;
            *(char *)(local_90 + 1) = (char)uVar16;
            *(undefined2 *)(local_90 + 2) = 0;
          }
          *param_4 = *param_4 + local_84 * 4;
          *param_5 = uVar10;
          return 0;
        }
        uVar17 = (uint)*(ushort *)(param_2 + (uint)local_94[2] * 2);
      }
      local_94 = puVar11;
      if ((uVar10 < uVar17) && (uVar13 = uVar5 & uVar12, uVar13 != local_78)) break;
      uVar16 = uVar17 - uVar14;
    }
    local_90 = local_90 + iVar6 * 4;
    if (uVar14 == 0) {
      uVar14 = uVar10;
    }
    uVar16 = uVar17 - uVar14;
    uVar8 = uVar16;
    if (uVar17 < uVar15) {
      iVar3 = (1 << (uVar16 & 0xff)) - (uint)*(ushort *)((int)&local_60 + uVar17 * 2);
      if (0 < iVar3) {
        puVar11 = (ushort *)((int)&local_60 + uVar17 * 2);
        do {
          uVar8 = uVar8 + 1;
          if (uVar15 <= uVar14 + uVar8) break;
          puVar11 = puVar11 + 1;
          iVar3 = iVar3 * 2 - (uint)*puVar11;
        } while (0 < iVar3);
      }
    }
    local_84 = local_84 + (1 << (uVar8 & 0xff));
    if (0x354 < local_84 && param_1 == 1) {
      return 1;
    }
    if (0x250 < local_84 && param_1 == 2) {
      return 1;
    }
    *(char *)(*param_4 + uVar13 * 4) = (char)uVar8;
    *(char *)(*param_4 + uVar13 * 4 + 1) = (char)uVar10;
    *(short *)(*param_4 + uVar13 * 4 + 2) = (short)(local_90 - *param_4 >> 2);
    local_78 = uVar13;
  } while( true );
}

