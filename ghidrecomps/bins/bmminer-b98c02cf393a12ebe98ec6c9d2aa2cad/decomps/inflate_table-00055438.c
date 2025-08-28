
undefined4
inflate_table(uint param_1,int param_2,uint param_3,int *param_4,uint *param_5,char *param_6)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  ushort uVar8;
  uint uVar9;
  ushort *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  char cVar17;
  ushort *local_94;
  int local_90;
  uint local_84;
  int local_7c;
  uint local_78;
  char *local_68;
  char *local_64;
  ushort local_60 [2];
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
  
  uVar9 = 0;
  local_60[0] = 0;
  local_60[1] = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  if (param_3 != 0) {
    if (0x10 < param_3) {
      iVar2 = param_2 + 0x2e;
      do {
        uVar14 = uVar9 + 0x11;
        uVar9 = uVar9 + 0x10;
        HintPreloadData(iVar2);
        local_60[*(ushort *)(iVar2 + -0x2e)] = local_60[*(ushort *)(iVar2 + -0x2e)] + 1;
        local_60[*(ushort *)(iVar2 + -0x2c)] = local_60[*(ushort *)(iVar2 + -0x2c)] + 1;
        local_60[*(ushort *)(iVar2 + -0x2a)] = local_60[*(ushort *)(iVar2 + -0x2a)] + 1;
        local_60[*(ushort *)(iVar2 + -0x28)] = local_60[*(ushort *)(iVar2 + -0x28)] + 1;
        local_60[*(ushort *)(iVar2 + -0x26)] = local_60[*(ushort *)(iVar2 + -0x26)] + 1;
        local_60[*(ushort *)(iVar2 + -0x24)] = local_60[*(ushort *)(iVar2 + -0x24)] + 1;
        local_60[*(ushort *)(iVar2 + -0x22)] = local_60[*(ushort *)(iVar2 + -0x22)] + 1;
        local_60[*(ushort *)(iVar2 + -0x20)] = local_60[*(ushort *)(iVar2 + -0x20)] + 1;
        local_60[*(ushort *)(iVar2 + -0x1e)] = local_60[*(ushort *)(iVar2 + -0x1e)] + 1;
        local_60[*(ushort *)(iVar2 + -0x1c)] = local_60[*(ushort *)(iVar2 + -0x1c)] + 1;
        local_60[*(ushort *)(iVar2 + -0x1a)] = local_60[*(ushort *)(iVar2 + -0x1a)] + 1;
        local_60[*(ushort *)(iVar2 + -0x18)] = local_60[*(ushort *)(iVar2 + -0x18)] + 1;
        local_60[*(ushort *)(iVar2 + -0x16)] = local_60[*(ushort *)(iVar2 + -0x16)] + 1;
        local_60[*(ushort *)(iVar2 + -0x14)] = local_60[*(ushort *)(iVar2 + -0x14)] + 1;
        local_60[*(ushort *)(iVar2 + -0x12)] = local_60[*(ushort *)(iVar2 + -0x12)] + 1;
        puVar10 = (ushort *)(iVar2 + -0x10);
        iVar2 = iVar2 + 0x20;
        local_60[*puVar10] = local_60[*puVar10] + 1;
      } while (uVar14 < param_3 - 0xf);
    }
    puVar10 = (ushort *)(param_2 + (uVar9 - 1) * 2);
    do {
      puVar10 = puVar10 + 1;
      uVar9 = uVar9 + 1;
      local_60[*puVar10] = local_60[*puVar10] + 1;
    } while (uVar9 < param_3);
  }
  uVar9 = *param_5;
  if (local_44 >> 0x10 == 0) {
    if ((short)local_44 != 0) {
      uVar14 = 0xe;
      goto LAB_00055ad6;
    }
    if (local_48._2_2_ != 0) {
      uVar14 = 0xd;
      goto LAB_00055ad6;
    }
    if ((short)local_48 != 0) {
      uVar14 = 0xc;
      goto LAB_00055ad6;
    }
    if (local_4c._2_2_ != 0) {
      uVar14 = 0xb;
      goto LAB_00055ad6;
    }
    if ((short)local_4c != 0) {
      uVar14 = 10;
      goto LAB_00055ad6;
    }
    if (local_50._2_2_ != 0) {
      uVar14 = 9;
      goto LAB_00055ad6;
    }
    if ((short)local_50 != 0) {
      uVar14 = 8;
      goto LAB_00055ad6;
    }
    if (local_54._2_2_ != 0) {
      uVar14 = 7;
      goto LAB_00055ad6;
    }
    if ((short)local_54 != 0) {
      uVar14 = 6;
      goto LAB_00055ad6;
    }
    if (local_58._2_2_ != 0) {
      uVar14 = 5;
      goto LAB_00055ad6;
    }
    if ((short)local_58 != 0) {
      uVar14 = 4;
      goto LAB_00055ad6;
    }
    if (local_5c._2_2_ != 0) {
      uVar14 = 3;
      goto LAB_00055ad6;
    }
    if ((short)local_5c != 0) {
      uVar14 = 2;
      goto LAB_00055ad6;
    }
    if (local_60[1] == 0) {
      puVar3 = (undefined1 *)*param_4;
      *(undefined2 *)(puVar3 + 2) = 0;
      *(undefined2 *)(puVar3 + 6) = 0;
      *puVar3 = 0x40;
      puVar3[4] = 0x40;
      puVar3[1] = 1;
      puVar3[5] = 1;
      *param_4 = (int)(puVar3 + 8);
      *param_5 = 1;
      return 0;
    }
    if (uVar9 != 0) {
      uVar9 = 1;
    }
    uVar14 = 1;
  }
  else {
    uVar14 = 0xf;
LAB_00055ad6:
    if (uVar14 < uVar9) {
      uVar9 = uVar14;
    }
    if (local_60[1] == 0) {
      puVar10 = local_60 + 1;
      uVar15 = 1;
      do {
        uVar15 = uVar15 + 1;
        if (uVar15 == uVar14) break;
        puVar10 = puVar10 + 1;
      } while (*puVar10 == 0);
      iVar2 = 2;
      goto LAB_00055706;
    }
  }
  iVar2 = 2 - (uint)local_60[1];
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  uVar15 = 1;
LAB_00055706:
  iVar2 = iVar2 * 2 - (local_5c & 0xffff);
  if ((((((iVar2 < 0) || (iVar2 = iVar2 * 2 - (uint)local_5c._2_2_, iVar2 < 0)) ||
        (iVar2 = iVar2 * 2 - (local_58 & 0xffff), iVar2 < 0)) ||
       ((iVar2 = iVar2 * 2 - (uint)local_58._2_2_, iVar2 < 0 ||
        (iVar2 = iVar2 * 2 - (local_54 & 0xffff), iVar2 < 0)))) ||
      ((iVar2 = iVar2 * 2 - (uint)local_54._2_2_, iVar2 < 0 ||
       ((iVar2 = iVar2 * 2 - (local_50 & 0xffff), iVar2 < 0 ||
        (iVar2 = iVar2 * 2 - (uint)local_50._2_2_, iVar2 < 0)))))) ||
     ((iVar2 = iVar2 * 2 - (local_4c & 0xffff), iVar2 < 0 ||
      ((((iVar2 = iVar2 * 2 - (uint)local_4c._2_2_, iVar2 < 0 ||
         (iVar2 = iVar2 * 2 - (local_48 & 0xffff), iVar2 < 0)) ||
        (iVar2 = iVar2 * 2 - (uint)local_48._2_2_, iVar2 < 0)) ||
       ((iVar2 = iVar2 * 2 - (local_44 & 0xffff), iVar2 < 0 ||
        (iVar2 = iVar2 * 2 - (local_44 >> 0x10), iVar2 < 0)))))))) {
    return 0xffffffff;
  }
  if (iVar2 != 0) {
    uVar4 = 1 - param_1;
    if (1 < param_1) {
      uVar4 = 0;
    }
    if (uVar14 != 1) {
      uVar4 = uVar4 | 1;
    }
    if (uVar4 != 0) {
      return 0xffffffff;
    }
  }
  uVar4 = 0;
  auStack_40[2] = local_60[1];
  auStack_40[1] = 0;
  auStack_40[4] = local_60[1] + (short)local_5c + local_5c._2_2_;
  auStack_40[3] = local_60[1] + (short)local_5c;
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
    puVar10 = (ushort *)(param_2 + -2);
    do {
      puVar10 = puVar10 + 1;
      uVar13 = (uint)*puVar10;
      if (uVar13 != 0) {
        uVar8 = auStack_40[uVar13];
        *(short *)(param_6 + (uint)uVar8 * 2) = (short)uVar4;
        auStack_40[uVar13] = uVar8 + 1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 != param_3);
  }
  if (param_1 == 0) {
    local_68 = param_6;
    local_64 = param_6;
    local_7c = 0x13;
  }
  else if (param_1 == 1) {
    local_7c = 0x100;
    local_68 = "\x06";
    local_64 = "ssion method";
  }
  else {
    local_7c = -1;
    local_68 = dext_6056;
    local_64 = dbase_6055;
  }
  if (uVar9 <= uVar15) {
    uVar9 = uVar15;
  }
  local_84 = 1 << (uVar9 & 0xff);
  local_90 = *param_4;
  if ((0x354 < local_84 && param_1 == 1) || (0x250 < local_84 && param_1 == 2)) {
    return 1;
  }
  uVar11 = local_84 - 1;
  local_78 = 0xffffffff;
  uVar4 = 0;
  uVar13 = 0;
  uVar7 = uVar9;
  uVar16 = uVar15;
  local_94 = (ushort *)(param_6 + -2);
  do {
    while( true ) {
      puVar10 = local_94 + 1;
      uVar8 = *puVar10;
      uVar12 = (uint)uVar8;
      if ((int)uVar12 < local_7c) {
        cVar17 = '\0';
      }
      else if (local_7c < (int)uVar12) {
        cVar17 = local_68[uVar12 * 2];
        uVar8 = *(ushort *)(local_64 + uVar12 * 2);
      }
      else {
        cVar17 = '`';
        uVar8 = 0;
      }
      iVar5 = 1 << (uVar7 & 0xff);
      iVar1 = 1 << (uVar15 & 0xff);
      pcVar6 = (char *)(local_90 + (((uVar4 >> (uVar13 & 0xff)) + iVar5) - iVar1) * 4);
      iVar2 = iVar5;
      do {
        iVar2 = iVar2 - iVar1;
        *pcVar6 = cVar17;
        pcVar6[1] = (char)uVar15;
        *(ushort *)(pcVar6 + 2) = uVar8;
        pcVar6 = pcVar6 + iVar1 * -4;
      } while (iVar2 != 0);
      for (uVar12 = 1 << (uVar16 - 1 & 0xff); (uVar12 & uVar4) != 0; uVar12 = uVar12 >> 1) {
      }
      if (uVar12 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = (uVar4 & uVar12 - 1) + uVar12;
      }
      uVar8 = local_60[uVar16];
      local_60[uVar16] = uVar8 - 1;
      if ((ushort)(uVar8 - 1) == 0) {
        if (uVar16 == uVar14) {
          if (uVar4 != 0) {
            *(undefined1 *)(local_90 + uVar4 * 4) = 0x40;
            local_90 = local_90 + uVar4 * 4;
            *(char *)(local_90 + 1) = (char)uVar15;
            *(undefined2 *)(local_90 + 2) = 0;
          }
          *param_4 = *param_4 + local_84 * 4;
          *param_5 = uVar9;
          return 0;
        }
        uVar16 = (uint)*(ushort *)(param_2 + (uint)local_94[2] * 2);
      }
      local_94 = puVar10;
      if ((uVar9 < uVar16) && (uVar12 = uVar4 & uVar11, uVar12 != local_78)) break;
      uVar15 = uVar16 - uVar13;
    }
    local_90 = local_90 + iVar5 * 4;
    if (uVar13 == 0) {
      uVar13 = uVar9;
    }
    uVar15 = uVar16 - uVar13;
    uVar7 = uVar15;
    if ((uVar16 < uVar14) && (iVar2 = (1 << (uVar15 & 0xff)) - (uint)local_60[uVar16], 0 < iVar2)) {
      puVar10 = local_60 + uVar16;
      do {
        uVar7 = uVar7 + 1;
        if (uVar14 <= uVar13 + uVar7) break;
        puVar10 = puVar10 + 1;
        iVar2 = iVar2 * 2 - (uint)*puVar10;
      } while (0 < iVar2);
    }
    local_84 = local_84 + (1 << (uVar7 & 0xff));
    if (0x354 < local_84 && param_1 == 1) {
      return 1;
    }
    if (0x250 < local_84 && param_1 == 2) {
      return 1;
    }
    *(char *)(*param_4 + uVar12 * 4) = (char)uVar7;
    *(char *)(*param_4 + uVar12 * 4 + 1) = (char)uVar9;
    *(short *)(*param_4 + uVar12 * 4 + 2) = (short)(local_90 - *param_4 >> 2);
    local_78 = uVar12;
  } while( true );
}

