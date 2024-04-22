
/* WARNING: Type propagation algorithm not settling */

void inflate_fast(int *param_1,int param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  ushort uVar3;
  byte bVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  undefined *puVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint uVar15;
  undefined *puVar16;
  undefined *puVar17;
  undefined *puVar18;
  int iVar19;
  uint uVar20;
  undefined4 uVar21;
  undefined4 *puVar22;
  uint uVar23;
  undefined *puVar24;
  uint uVar25;
  int iVar26;
  int iVar27;
  undefined *puVar28;
  undefined *puVar29;
  undefined *puVar30;
  int iVar31;
  uint uVar32;
  undefined4 *puVar33;
  undefined *puVar34;
  uint uVar35;
  int iVar36;
  undefined *puVar37;
  undefined4 *puVar38;
  undefined *puVar39;
  undefined4 *puVar40;
  bool bVar41;
  uint local_b0;
  undefined *local_ac;
  uint local_a8;
  undefined *local_a4;
  uint local_70;
  undefined4 *local_44;
  undefined4 *local_40;
  
  puVar38 = (undefined4 *)param_1[7];
  puVar5 = (undefined *)puVar38[0xc];
  local_a8 = *param_1 - 1;
  uVar23 = puVar38[0x15];
  uVar14 = local_a8 + param_1[1] + -5;
  iVar19 = puVar38[10];
  uVar15 = (uint)puVar5 >> 2;
  puVar33 = (undefined4 *)puVar38[0xd];
  puVar39 = (undefined *)(param_1[3] + -1);
  param_2 = param_1[4] - param_2;
  puVar16 = puVar39 + param_1[4] + -0x101;
  puVar24 = (undefined *)((uint)puVar5 & 0xfffffffc);
  puVar34 = (undefined *)((int)puVar33 + -1);
  uVar6 = puVar38[0x16];
  puVar30 = (undefined *)puVar38[0xb];
  puVar37 = (undefined *)puVar38[0xe];
  uVar35 = puVar38[0xf];
  uVar25 = 1 - uVar15;
  iVar31 = puVar38[0x13];
  if (1 < uVar15) {
    uVar25 = 0;
  }
  iVar36 = puVar38[0x14];
  iVar26 = param_1[3] + param_2;
  puVar10 = puVar39 + param_2;
LAB_000564a2:
  if (uVar35 < 0xf) {
    pbVar1 = (byte *)(local_a8 + 1);
    uVar11 = uVar35 + 8;
    pbVar2 = (byte *)(local_a8 + 2);
    local_a8 = local_a8 + 2;
    uVar20 = uVar35 & 0xff;
    uVar35 = uVar35 + 0x10;
    puVar37 = puVar37 + ((uint)*pbVar1 << uVar20) + ((uint)*pbVar2 << (uVar11 & 0xff));
  }
  uVar20 = (uint)puVar37 & (1 << (uVar23 & 0xff)) - 1U;
  iVar12 = iVar31 + uVar20 * 4;
  bVar4 = *(byte *)(iVar31 + uVar20 * 4);
  uVar20 = (uint)*(byte *)(iVar12 + 1);
  uVar3 = *(ushort *)(iVar12 + 2);
  uVar35 = uVar35 - uVar20;
  puVar37 = (undefined *)((uint)puVar37 >> uVar20);
  while( true ) {
    uVar20 = (uint)bVar4;
    puVar18 = (undefined *)(uint)uVar3;
    if (uVar20 == 0) break;
    if ((int)(uVar20 << 0x1b) < 0) {
      uVar20 = uVar20 & 0xf;
      uVar11 = uVar35;
      if ((bVar4 & 0xf) != 0) {
        puVar17 = puVar18;
        if (uVar35 < uVar20) {
          pbVar1 = (byte *)(local_a8 + 1);
          local_a8 = local_a8 + 1;
          puVar17 = (undefined *)((uint)*pbVar1 << (uVar35 & 0xff));
          uVar11 = uVar35 + 8;
        }
        uVar11 = uVar11 - uVar20;
        if (uVar35 < uVar20) {
          puVar37 = puVar37 + (int)puVar17;
        }
        uVar35 = (uint)puVar37 & (1 << uVar20) - 1U;
        puVar37 = (undefined *)((uint)puVar37 >> uVar20);
        puVar18 = puVar18 + uVar35;
      }
      if (uVar11 < 0xf) {
        pbVar1 = (byte *)(local_a8 + 1);
        uVar20 = uVar11 + 8;
        pbVar2 = (byte *)(local_a8 + 2);
        local_a8 = local_a8 + 2;
        uVar35 = uVar11 & 0xff;
        uVar11 = uVar11 + 0x10;
        puVar37 = puVar37 + ((uint)*pbVar1 << uVar35) + ((uint)*pbVar2 << (uVar20 & 0xff));
      }
      uVar35 = (uint)puVar37 & (1 << (uVar6 & 0xff)) - 1U;
      iVar12 = iVar36 + uVar35 * 4;
      uVar20 = (uint)*(byte *)(iVar36 + uVar35 * 4);
      uVar7 = (uint)*(byte *)(iVar12 + 1);
      local_b0 = (uint)*(ushort *)(iVar12 + 2);
      uVar35 = uVar11 - uVar7;
      puVar37 = (undefined *)((uint)puVar37 >> uVar7);
      if (-1 < (int)(uVar20 << 0x1b)) goto joined_r0x00056560;
      goto LAB_00056592;
    }
    if ((int)(uVar20 << 0x19) < 0) {
      bVar41 = -1 < (int)(uVar20 << 0x1a);
      if (bVar41) {
        uVar21 = 0x1d;
        iVar19 = DAT_00056900;
      }
      else {
        uVar21 = 0xb;
        iVar19 = uVar20 << 0x19;
      }
      if (bVar41) {
        param_1[6] = iVar19;
      }
      *puVar38 = uVar21;
      goto LAB_0005682e;
    }
    iVar12 = iVar31 + (int)(puVar18 + ((uint)puVar37 & (1 << uVar20) - 1U)) * 4;
    bVar4 = *(byte *)(iVar31 + (int)(puVar18 + ((uint)puVar37 & (1 << uVar20) - 1U)) * 4);
    uVar20 = (uint)*(byte *)(iVar12 + 1);
    uVar3 = *(ushort *)(iVar12 + 2);
    uVar35 = uVar35 - uVar20;
    puVar37 = (undefined *)((uint)puVar37 >> uVar20);
  }
  puVar39[1] = (char)uVar3;
  puVar39 = puVar39 + 1;
  goto LAB_000567f6;
  while( true ) {
    iVar12 = ((uint)puVar37 & (1 << uVar20) - 1U) + local_b0;
    iVar27 = iVar36 + iVar12 * 4;
    uVar20 = (uint)*(byte *)(iVar36 + iVar12 * 4);
    uVar11 = (uint)*(byte *)(iVar27 + 1);
    local_b0 = (uint)*(ushort *)(iVar27 + 2);
    uVar35 = uVar35 - uVar11;
    puVar37 = (undefined *)((uint)puVar37 >> uVar11);
    if ((int)(uVar20 << 0x1b) < 0) break;
joined_r0x00056560:
    if ((int)(uVar20 << 0x19) < 0) {
      param_1[6] = DAT_00056904;
      *puVar38 = 0x1d;
      goto LAB_0005682e;
    }
  }
LAB_00056592:
  uVar20 = uVar20 & 0xf;
  uVar11 = uVar35;
  if (uVar35 < uVar20) {
    pbVar1 = (byte *)(local_a8 + 1);
    uVar7 = uVar35 + 8;
    if (uVar20 <= uVar7) {
      local_a8 = local_a8 + 1;
    }
    uVar11 = uVar7;
    if (uVar7 < uVar20) {
      uVar11 = uVar35 + 0x10;
    }
    puVar37 = puVar37 + ((uint)*pbVar1 << (uVar35 & 0xff));
    if (uVar7 < uVar20) {
      pbVar1 = (byte *)(local_a8 + 2);
      local_a8 = local_a8 + 2;
      puVar37 = puVar37 + ((uint)*pbVar1 << (uVar7 & 0xff));
    }
  }
  uVar35 = uVar11 - uVar20;
  uVar11 = (uint)puVar37 & (1 << uVar20) - 1U;
  puVar37 = (undefined *)((uint)puVar37 >> uVar20);
  uVar20 = uVar11 + local_b0;
  if (uVar20 <= (uint)((int)puVar39 - (int)puVar10)) {
    puVar17 = puVar39 + -uVar20;
    do {
      puVar8 = puVar39;
      puVar29 = puVar17;
      puVar18 = puVar18 + -3;
      puVar39 = puVar8 + 3;
      puVar8[1] = puVar29[1];
      puVar8[2] = puVar29[2];
      puVar8[3] = puVar29[3];
      puVar17 = puVar29 + 3;
    } while ((undefined *)0x2 < puVar18);
    if (puVar18 != (undefined *)0x0) {
      puVar8[4] = puVar29[4];
      if (puVar18 == (undefined *)0x2) {
        puVar8[5] = puVar29[5];
        puVar39 = puVar8 + 5;
      }
      else {
        puVar39 = puVar8 + 4;
      }
    }
    goto LAB_000567f6;
  }
  puVar17 = (undefined *)(uVar20 - ((int)puVar39 - (int)puVar10));
  if ((puVar30 < puVar17) && (puVar38[0x6f0] != 0)) {
    param_1[6] = DAT_00056da4;
    *puVar38 = 0x1d;
    goto LAB_0005682e;
  }
  puVar29 = puVar34;
  local_a4 = puVar17;
  puVar8 = puVar39;
  if (puVar5 == (undefined *)0x0) {
    local_ac = puVar34 + (iVar19 - (int)puVar17);
    if (puVar17 < puVar18) {
      local_40 = (undefined4 *)(puVar39 + 1);
      uVar7 = (uint)puVar17 >> 2;
      iVar12 = ((iVar19 - (iVar26 - (int)puVar39)) - local_b0) - uVar11;
      puVar8 = (undefined *)((int)puVar33 + iVar12 + 1);
      puVar18 = puVar18 + -(int)puVar17;
      puVar28 = (undefined *)((uint)puVar17 & 0xfffffffc);
      puVar29 = puVar39;
      if (uVar7 != 0 &&
          ((((uint)puVar8 | (uint)local_40) & 3) == 0 &&
          ((undefined *)0x3 < puVar17 &&
          (puVar39 + 5 <= puVar8 || (undefined4 *)((int)puVar33 + iVar12 + 5) <= local_40)))) {
        if (uVar7 < 9) {
          uVar11 = 0;
          local_a4 = puVar8;
        }
        else {
          uVar11 = 0;
          puVar13 = (undefined4 *)(puVar39 + 0x21);
          puVar29 = (undefined *)((int)puVar33 + iVar12 + 0x21);
          do {
            local_a4 = puVar29;
            local_40 = puVar13;
            uVar32 = uVar11 + 9;
            uVar11 = uVar11 + 8;
            HintPreloadData(local_a4 + 0x54);
            local_40[-8] = *(undefined4 *)(local_a4 + -0x20);
            local_40[-7] = *(undefined4 *)(local_a4 + -0x1c);
            local_40[-6] = *(undefined4 *)(local_a4 + -0x18);
            local_40[-5] = *(undefined4 *)(local_a4 + -0x14);
            local_40[-4] = *(undefined4 *)(local_a4 + -0x10);
            local_40[-3] = *(undefined4 *)(local_a4 + -0xc);
            local_40[-2] = *(undefined4 *)(local_a4 + -8);
            local_40[-1] = *(undefined4 *)(local_a4 + -4);
            puVar13 = local_40 + 8;
            puVar29 = local_a4 + 0x20;
          } while (uVar32 < uVar7 - 7);
        }
        puVar13 = (undefined4 *)(local_a4 + -4);
        do {
          puVar13 = puVar13 + 1;
          uVar11 = uVar11 + 1;
          *local_40 = *puVar13;
          local_40 = local_40 + 1;
        } while (uVar11 < uVar7);
        local_ac = local_ac + (int)puVar28;
        puVar29 = puVar39 + (int)puVar28;
        local_a4 = puVar17 + -(int)puVar28;
        if (puVar17 == puVar28) goto LAB_0005679c;
      }
      local_a4 = local_ac + (int)local_a4;
      do {
        local_ac = local_ac + 1;
        puVar29 = puVar29 + 1;
        *puVar29 = *local_ac;
      } while (local_ac != local_a4);
LAB_0005679c:
      puVar8 = puVar39 + (int)puVar17;
      local_ac = puVar39 + (int)puVar17 + -uVar20;
      puVar29 = puVar17;
    }
  }
  else if (puVar5 < puVar17) {
    puVar29 = puVar17 + -(int)puVar5;
    local_ac = puVar34 + (int)(puVar5 + (iVar19 - (int)puVar17));
    if (puVar29 < puVar18) {
      local_44 = (undefined4 *)(puVar39 + 1);
      uVar7 = (uint)puVar29 >> 2;
      iVar12 = ((iVar19 - (iVar26 - (int)puVar39)) - local_b0) - uVar11;
      local_40 = (undefined4 *)((int)puVar33 + (int)(puVar5 + iVar12 + 1));
      puVar18 = puVar18 + -(int)puVar29;
      puVar28 = (undefined *)((uint)puVar29 & 0xfffffffc);
      puVar8 = puVar29;
      puVar17 = puVar39;
      if (uVar7 == 0 ||
          ((((uint)local_40 | (uint)local_44) & 3) != 0 ||
          (puVar29 < (undefined *)0x4 ||
          local_40 < puVar39 + 5 &&
          local_44 < (undefined4 *)((int)puVar33 + (int)(puVar5 + iVar12 + 5))))) {
LAB_00056a90:
        puVar8 = local_ac + (int)puVar8;
        do {
          local_ac = local_ac + 1;
          puVar17 = puVar17 + 1;
          *puVar17 = *local_ac;
        } while (local_ac != puVar8);
      }
      else {
        if (uVar7 < 9) {
          local_70 = 0;
        }
        else {
          local_70 = 0;
          puVar17 = (undefined *)((int)puVar33 + (int)(puVar5 + iVar12 + 0x21));
          puVar13 = (undefined4 *)(puVar39 + 0x21);
          do {
            local_44 = puVar13;
            local_40 = (undefined4 *)puVar17;
            uVar32 = local_70 + 9;
            local_70 = local_70 + 8;
            HintPreloadData((undefined *)((int)local_40 + 0x54));
            local_44[-8] = *(undefined4 *)((int)local_40 + -0x20);
            local_44[-7] = *(undefined4 *)((int)local_40 + -0x1c);
            local_44[-6] = *(undefined4 *)((int)local_40 + -0x18);
            local_44[-5] = *(undefined4 *)((int)local_40 + -0x14);
            local_44[-4] = *(undefined4 *)((int)local_40 + -0x10);
            local_44[-3] = *(undefined4 *)((int)local_40 + -0xc);
            local_44[-2] = *(undefined4 *)((int)local_40 + -8);
            local_44[-1] = *(undefined4 *)((int)local_40 + -4);
            puVar17 = (undefined *)((int)local_40 + 0x20);
            puVar13 = local_44 + 8;
          } while (uVar32 < uVar7 - 7);
        }
        local_40 = (undefined4 *)((int)local_40 + -4);
        do {
          local_40 = local_40 + 1;
          local_70 = local_70 + 1;
          *local_44 = *local_40;
          local_44 = local_44 + 1;
        } while (local_70 < uVar7);
        local_ac = local_ac + (int)puVar28;
        puVar8 = puVar29 + -(int)puVar28;
        puVar17 = puVar39 + (int)puVar28;
        if (puVar29 != puVar28) goto LAB_00056a90;
      }
      puVar29 = puVar29 + (int)puVar39;
      puVar8 = puVar29;
      local_ac = puVar34;
      if (puVar5 < puVar18) {
        puVar18 = puVar18 + -(int)puVar5;
        puVar40 = (undefined4 *)
                  (puVar39 + ((iVar26 - (int)puVar39) - (int)puVar5) + local_b0 + uVar11);
        puVar13 = puVar40 + 1;
        uVar11 = (uint)(puVar33 + 1 <= puVar40 || puVar13 <= puVar33);
        if (puVar5 < (undefined *)0x4) {
          uVar11 = 0;
        }
        if ((((uint)puVar40 | (uint)puVar33) & 3) != 0) {
          uVar11 = 0;
        }
        puVar17 = puVar29;
        puVar39 = puVar34;
        puVar8 = puVar5;
        if ((uVar11 ^ 1 | uVar25) == 0) {
          if (uVar15 < 9) {
            uVar11 = 0;
            puVar22 = puVar33;
          }
          else {
            uVar11 = 0;
            puVar9 = puVar33;
            do {
              puVar13 = puVar40;
              puVar40 = puVar13 + 8;
              puVar22 = puVar9 + 8;
              uVar7 = uVar11 + 9;
              uVar11 = uVar11 + 8;
              HintPreloadData(puVar9 + 0x1d);
              *puVar13 = *puVar9;
              puVar13[1] = puVar9[1];
              puVar13[2] = puVar9[2];
              puVar13[3] = puVar9[3];
              puVar13[4] = puVar9[4];
              puVar13[5] = puVar9[5];
              puVar13[6] = puVar9[6];
              puVar13[7] = puVar9[7];
              puVar9 = puVar22;
            } while (uVar7 < uVar15 - 7);
            puVar13 = puVar13 + 9;
          }
          puVar22 = puVar22 + -1;
          do {
            puVar9 = puVar13;
            puVar22 = puVar22 + 1;
            uVar11 = uVar11 + 1;
            *puVar40 = *puVar22;
            puVar13 = puVar9 + 1;
            puVar40 = puVar9;
          } while (uVar11 < uVar15);
          puVar17 = puVar29 + (int)puVar24;
          puVar39 = puVar34 + (int)puVar24;
          puVar8 = puVar5 + uVar15 * -4;
          if (puVar5 != puVar24) goto LAB_00056bc2;
        }
        else {
LAB_00056bc2:
          puVar8 = puVar39 + (int)puVar8;
          do {
            puVar39 = puVar39 + 1;
            puVar17 = puVar17 + 1;
            *puVar17 = *puVar39;
          } while (puVar39 != puVar8);
        }
        puVar8 = puVar29 + (int)puVar5;
        local_ac = puVar29 + (int)puVar5 + -uVar20;
      }
    }
  }
  else {
    local_ac = puVar34 + ((int)puVar5 - (int)puVar17);
    if (puVar17 < puVar18) {
      local_40 = (undefined4 *)(puVar39 + 1);
      uVar7 = (uint)puVar17 >> 2;
      iVar12 = (-local_b0 - (iVar26 - (int)puVar39)) - uVar11;
      local_44 = (undefined4 *)((int)puVar33 + (int)(puVar5 + iVar12 + 1));
      puVar18 = puVar18 + -(int)puVar17;
      puVar8 = (undefined *)((uint)puVar17 & 0xfffffffc);
      puVar29 = puVar39;
      if (uVar7 != 0 &&
          ((((uint)local_44 | (uint)local_40) & 3) == 0 &&
          ((undefined *)0x3 < puVar17 &&
          (puVar39 + 5 <= local_44 ||
          (undefined4 *)((int)puVar33 + (int)(puVar5 + iVar12 + 5)) <= local_40)))) {
        uVar11 = 0;
        if (8 < uVar7) {
          uVar11 = 0;
          puVar13 = (undefined4 *)(puVar39 + 0x21);
          puVar29 = (undefined *)((int)puVar33 + (int)(puVar5 + iVar12 + 0x21));
          do {
            local_44 = (undefined4 *)puVar29;
            local_40 = puVar13;
            uVar32 = uVar11 + 9;
            uVar11 = uVar11 + 8;
            HintPreloadData((undefined *)((int)local_44 + 0x54));
            local_40[-8] = *(undefined4 *)((int)local_44 + -0x20);
            local_40[-7] = *(undefined4 *)((int)local_44 + -0x1c);
            local_40[-6] = *(undefined4 *)((int)local_44 + -0x18);
            local_40[-5] = *(undefined4 *)((int)local_44 + -0x14);
            local_40[-4] = *(undefined4 *)((int)local_44 + -0x10);
            local_40[-3] = *(undefined4 *)((int)local_44 + -0xc);
            local_40[-2] = *(undefined4 *)((int)local_44 + -8);
            local_40[-1] = *(undefined4 *)((int)local_44 + -4);
            puVar13 = local_40 + 8;
            puVar29 = (undefined *)((int)local_44 + 0x20);
          } while (uVar32 < uVar7 - 7);
        }
        local_44 = (undefined4 *)((int)local_44 + -4);
        do {
          local_44 = local_44 + 1;
          uVar11 = uVar11 + 1;
          *local_40 = *local_44;
          local_40 = local_40 + 1;
        } while (uVar11 < uVar7);
        local_ac = local_ac + (int)puVar8;
        puVar29 = puVar39 + (int)puVar8;
        local_a4 = puVar17 + -(int)puVar8;
        if (puVar17 == puVar8) goto LAB_0005679c;
      }
      local_a4 = local_ac + (int)local_a4;
      do {
        local_ac = local_ac + 1;
        puVar29 = puVar29 + 1;
        *puVar29 = *local_ac;
      } while (local_ac != local_a4);
      goto LAB_0005679c;
    }
  }
  for (; puVar39 = puVar8, (undefined *)0x2 < puVar18; puVar18 = puVar18 + -3) {
    puVar39[1] = local_ac[1];
    puVar39[2] = local_ac[2];
    puVar39[3] = local_ac[3];
    puVar8 = puVar39 + 3;
    local_ac = local_ac + 3;
  }
  if (puVar18 != (undefined *)0x0) {
    if (puVar18 == (undefined *)0x2) {
      puVar29 = local_ac;
    }
    puVar39[1] = local_ac[1];
    if (puVar18 == (undefined *)0x2) {
      puVar39[2] = puVar29[2];
      puVar39 = puVar39 + 2;
    }
    else {
      puVar39 = puVar39 + 1;
    }
  }
LAB_000567f6:
  if (puVar16 <= puVar39 || uVar14 <= local_a8) {
LAB_0005682e:
    uVar6 = uVar35 - (uVar35 & 0xfffffff8);
    iVar19 = local_a8 - (uVar35 >> 3);
    param_1[3] = (int)(puVar39 + 1);
    param_1[1] = (uVar14 - iVar19) + 5;
    *param_1 = iVar19 + 1;
    param_1[4] = (int)(puVar16 + (0x101 - (int)puVar39));
    puVar38[0xe] = (1 << (uVar6 & 0xff)) - 1U & (uint)puVar37;
    puVar38[0xf] = uVar6;
    return;
  }
  goto LAB_000564a2;
}

