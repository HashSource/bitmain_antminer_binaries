
/* WARNING: Type propagation algorithm not settling */

void inflate_fast(int *param_1,int param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  ushort uVar3;
  byte bVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint uVar15;
  undefined1 *puVar16;
  char *pcVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  int iVar20;
  uint uVar21;
  undefined4 uVar22;
  undefined4 *puVar23;
  uint uVar24;
  undefined1 *puVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  undefined1 *puVar29;
  undefined1 *puVar30;
  undefined1 *puVar31;
  int iVar32;
  uint uVar33;
  undefined4 *puVar34;
  undefined1 *puVar35;
  uint uVar36;
  int iVar37;
  undefined1 *puVar38;
  undefined4 *puVar39;
  undefined1 *puVar40;
  undefined4 *puVar41;
  bool bVar42;
  uint local_b0;
  undefined1 *local_ac;
  uint local_a8;
  undefined1 *local_a4;
  uint local_70;
  undefined4 *local_44;
  undefined4 *local_40;
  
  puVar39 = (undefined4 *)param_1[7];
  puVar5 = (undefined1 *)puVar39[0xc];
  local_a8 = *param_1 - 1;
  uVar24 = puVar39[0x15];
  uVar14 = local_a8 + param_1[1] + -5;
  iVar20 = puVar39[10];
  uVar15 = (uint)puVar5 >> 2;
  puVar34 = (undefined4 *)puVar39[0xd];
  puVar40 = (undefined1 *)(param_1[3] + -1);
  param_2 = param_1[4] - param_2;
  puVar16 = puVar40 + param_1[4] + -0x101;
  puVar25 = (undefined1 *)(uVar15 * 4);
  puVar35 = (undefined1 *)((int)puVar34 + -1);
  uVar6 = puVar39[0x16];
  puVar31 = (undefined1 *)puVar39[0xb];
  puVar38 = (undefined1 *)puVar39[0xe];
  uVar36 = puVar39[0xf];
  iVar26 = 1 - uVar15;
  iVar32 = puVar39[0x13];
  if (1 < uVar15) {
    iVar26 = 0;
  }
  iVar37 = puVar39[0x14];
  iVar27 = param_1[3] + param_2;
  puVar10 = puVar40 + param_2;
LAB_000427aa:
  if (uVar36 < 0xf) {
    pbVar1 = (byte *)(local_a8 + 1);
    uVar11 = uVar36 + 8;
    pbVar2 = (byte *)(local_a8 + 2);
    local_a8 = local_a8 + 2;
    uVar21 = uVar36 & 0xff;
    uVar36 = uVar36 + 0x10;
    puVar38 = puVar38 + ((uint)*pbVar1 << uVar21) + ((uint)*pbVar2 << (uVar11 & 0xff));
  }
  uVar21 = (uint)puVar38 & (1 << (uVar24 & 0xff)) - 1U;
  iVar12 = iVar32 + uVar21 * 4;
  bVar4 = *(byte *)(iVar32 + uVar21 * 4);
  uVar21 = (uint)*(byte *)(iVar12 + 1);
  uVar3 = *(ushort *)(iVar12 + 2);
  uVar36 = uVar36 - uVar21;
  puVar38 = (undefined1 *)((uint)puVar38 >> uVar21);
  while( true ) {
    uVar21 = (uint)bVar4;
    puVar19 = (undefined1 *)(uint)uVar3;
    if (uVar21 == 0) break;
    if ((int)(uVar21 << 0x1b) < 0) {
      uVar21 = uVar21 & 0xf;
      uVar11 = uVar36;
      if ((bVar4 & 0xf) != 0) {
        puVar18 = puVar19;
        if (uVar36 < uVar21) {
          pbVar1 = (byte *)(local_a8 + 1);
          local_a8 = local_a8 + 1;
          puVar18 = (undefined1 *)((uint)*pbVar1 << (uVar36 & 0xff));
          uVar11 = uVar36 + 8;
        }
        uVar11 = uVar11 - uVar21;
        if (uVar36 < uVar21) {
          puVar38 = puVar38 + (int)puVar18;
        }
        uVar36 = (uint)puVar38 & (1 << uVar21) - 1U;
        puVar38 = (undefined1 *)((uint)puVar38 >> uVar21);
        puVar19 = puVar19 + uVar36;
      }
      if (uVar11 < 0xf) {
        pbVar1 = (byte *)(local_a8 + 1);
        uVar21 = uVar11 + 8;
        pbVar2 = (byte *)(local_a8 + 2);
        local_a8 = local_a8 + 2;
        uVar36 = uVar11 & 0xff;
        uVar11 = uVar11 + 0x10;
        puVar38 = puVar38 + ((uint)*pbVar1 << uVar36) + ((uint)*pbVar2 << (uVar21 & 0xff));
      }
      uVar36 = (uint)puVar38 & (1 << (uVar6 & 0xff)) - 1U;
      iVar12 = iVar37 + uVar36 * 4;
      uVar21 = (uint)*(byte *)(iVar37 + uVar36 * 4);
      uVar7 = (uint)*(byte *)(iVar12 + 1);
      local_b0 = (uint)*(ushort *)(iVar12 + 2);
      uVar36 = uVar11 - uVar7;
      puVar38 = (undefined1 *)((uint)puVar38 >> uVar7);
      if (-1 < (int)(uVar21 << 0x1b)) goto joined_r0x00042868;
      goto LAB_0004289a;
    }
    pcVar17 = (char *)(uVar21 << 0x19);
    if ((int)pcVar17 < 0) {
      bVar42 = -1 < (int)(uVar21 << 0x1a);
      if (bVar42) {
        pcVar17 = "invalid literal/length code";
        uVar22 = 0x1d;
      }
      else {
        uVar22 = 0xb;
      }
      if (bVar42) {
        param_1[6] = (int)pcVar17;
      }
      *puVar39 = uVar22;
      goto LAB_00042b36;
    }
    iVar12 = iVar32 + (int)(puVar19 + ((uint)puVar38 & (1 << uVar21) - 1U)) * 4;
    bVar4 = *(byte *)(iVar32 + (int)(puVar19 + ((uint)puVar38 & (1 << uVar21) - 1U)) * 4);
    uVar21 = (uint)*(byte *)(iVar12 + 1);
    uVar3 = *(ushort *)(iVar12 + 2);
    uVar36 = uVar36 - uVar21;
    puVar38 = (undefined1 *)((uint)puVar38 >> uVar21);
  }
  puVar40[1] = (char)uVar3;
  puVar40 = puVar40 + 1;
  goto LAB_00042afe;
  while( true ) {
    iVar12 = ((uint)puVar38 & (1 << uVar21) - 1U) + local_b0;
    iVar28 = iVar37 + iVar12 * 4;
    uVar21 = (uint)*(byte *)(iVar37 + iVar12 * 4);
    uVar11 = (uint)*(byte *)(iVar28 + 1);
    local_b0 = (uint)*(ushort *)(iVar28 + 2);
    uVar36 = uVar36 - uVar11;
    puVar38 = (undefined1 *)((uint)puVar38 >> uVar11);
    if ((int)(uVar21 << 0x1b) < 0) break;
joined_r0x00042868:
    if ((int)(uVar21 << 0x19) < 0) {
      param_1[6] = (int)"invalid distance code";
      *puVar39 = 0x1d;
      goto LAB_00042b36;
    }
  }
LAB_0004289a:
  uVar21 = uVar21 & 0xf;
  uVar11 = uVar36;
  if (uVar36 < uVar21) {
    pbVar1 = (byte *)(local_a8 + 1);
    uVar7 = uVar36 + 8;
    if (uVar21 <= uVar7) {
      local_a8 = local_a8 + 1;
    }
    uVar11 = uVar7;
    if (uVar7 < uVar21) {
      uVar11 = uVar36 + 0x10;
    }
    puVar38 = puVar38 + ((uint)*pbVar1 << (uVar36 & 0xff));
    if (uVar7 < uVar21) {
      pbVar1 = (byte *)(local_a8 + 2);
      local_a8 = local_a8 + 2;
      puVar38 = puVar38 + ((uint)*pbVar1 << (uVar7 & 0xff));
    }
  }
  uVar36 = uVar11 - uVar21;
  uVar11 = (uint)puVar38 & (1 << uVar21) - 1U;
  puVar38 = (undefined1 *)((uint)puVar38 >> uVar21);
  uVar21 = uVar11 + local_b0;
  if (uVar21 <= (uint)((int)puVar40 - (int)puVar10)) {
    puVar18 = puVar40 + -uVar21;
    do {
      puVar8 = puVar40;
      puVar30 = puVar18;
      puVar19 = puVar19 + -3;
      puVar40 = puVar8 + 3;
      puVar8[1] = puVar30[1];
      puVar8[2] = puVar30[2];
      puVar8[3] = puVar30[3];
      puVar18 = puVar30 + 3;
    } while ((undefined1 *)0x2 < puVar19);
    if (puVar19 != (undefined1 *)0x0) {
      puVar8[4] = puVar30[4];
      if (puVar19 == (undefined1 *)0x2) {
        puVar8[5] = puVar30[5];
        puVar40 = puVar8 + 5;
      }
      else {
        puVar40 = puVar8 + 4;
      }
    }
    goto LAB_00042afe;
  }
  puVar18 = (undefined1 *)(uVar21 - ((int)puVar40 - (int)puVar10));
  if ((puVar31 < puVar18) && (puVar39[0x6f0] != 0)) {
    param_1[6] = (int)"invalid distance too far back";
    *puVar39 = 0x1d;
    goto LAB_00042b36;
  }
  puVar30 = puVar35;
  local_a4 = puVar18;
  puVar8 = puVar40;
  if (puVar5 == (undefined1 *)0x0) {
    local_ac = puVar35 + (iVar20 - (int)puVar18);
    if (puVar18 < puVar19) {
      local_40 = (undefined4 *)(puVar40 + 1);
      uVar7 = (uint)puVar18 >> 2;
      iVar12 = ((iVar20 - (iVar27 - (int)puVar40)) - local_b0) - uVar11;
      puVar8 = (undefined1 *)((int)puVar34 + iVar12 + 1);
      puVar19 = puVar19 + -(int)puVar18;
      puVar29 = (undefined1 *)(uVar7 * 4);
      puVar30 = puVar40;
      if (uVar7 != 0 &&
          ((((uint)puVar8 | (uint)local_40) & 3) == 0 &&
          ((undefined1 *)0x3 < puVar18 &&
          (puVar40 + 5 <= puVar8 || (undefined4 *)((int)puVar34 + iVar12 + 5) <= local_40)))) {
        if (uVar7 < 9) {
          uVar11 = 0;
          local_a4 = puVar8;
        }
        else {
          uVar11 = 0;
          puVar13 = (undefined4 *)(puVar40 + 0x21);
          puVar30 = (undefined1 *)((int)puVar34 + iVar12 + 0x21);
          do {
            local_a4 = puVar30;
            local_40 = puVar13;
            uVar33 = uVar11 + 9;
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
            puVar30 = local_a4 + 0x20;
          } while (uVar33 < uVar7 - 7);
        }
        puVar13 = (undefined4 *)(local_a4 + -4);
        do {
          puVar13 = puVar13 + 1;
          uVar11 = uVar11 + 1;
          *local_40 = *puVar13;
          local_40 = local_40 + 1;
        } while (uVar11 < uVar7);
        local_ac = local_ac + (int)puVar29;
        puVar30 = puVar40 + (int)puVar29;
        local_a4 = puVar18 + uVar7 * -4;
        if (puVar18 == puVar29) goto LAB_00042aa4;
      }
      local_a4 = local_ac + (int)local_a4;
      do {
        local_ac = local_ac + 1;
        puVar30 = puVar30 + 1;
        *puVar30 = *local_ac;
      } while (local_ac != local_a4);
LAB_00042aa4:
      puVar8 = puVar40 + (int)puVar18;
      local_ac = puVar40 + (int)puVar18 + -uVar21;
      puVar30 = puVar18;
    }
  }
  else if (puVar5 < puVar18) {
    puVar30 = puVar18 + -(int)puVar5;
    local_ac = puVar35 + (int)(puVar5 + (iVar20 - (int)puVar18));
    if (puVar30 < puVar19) {
      local_44 = (undefined4 *)(puVar40 + 1);
      uVar7 = (uint)puVar30 >> 2;
      iVar12 = ((iVar20 - (iVar27 - (int)puVar40)) - local_b0) - uVar11;
      local_40 = (undefined4 *)((int)puVar34 + (int)(puVar5 + iVar12 + 1));
      puVar19 = puVar19 + -(int)puVar30;
      puVar29 = (undefined1 *)(uVar7 * 4);
      puVar8 = puVar30;
      puVar18 = puVar40;
      if (uVar7 == 0 ||
          ((((uint)local_40 | (uint)local_44) & 3) != 0 ||
          (puVar30 < (undefined1 *)0x4 ||
          local_40 < puVar40 + 5 &&
          local_44 < (undefined4 *)((int)puVar34 + (int)(puVar5 + iVar12 + 5))))) {
LAB_00042d98:
        puVar8 = local_ac + (int)puVar8;
        do {
          local_ac = local_ac + 1;
          puVar18 = puVar18 + 1;
          *puVar18 = *local_ac;
        } while (local_ac != puVar8);
      }
      else {
        if (uVar7 < 9) {
          local_70 = 0;
        }
        else {
          local_70 = 0;
          puVar18 = (undefined1 *)((int)puVar34 + (int)(puVar5 + iVar12 + 0x21));
          puVar13 = (undefined4 *)(puVar40 + 0x21);
          do {
            local_44 = puVar13;
            local_40 = (undefined4 *)puVar18;
            uVar33 = local_70 + 9;
            local_70 = local_70 + 8;
            HintPreloadData((undefined1 *)((int)local_40 + 0x54));
            local_44[-8] = *(undefined4 *)((int)local_40 + -0x20);
            local_44[-7] = *(undefined4 *)((int)local_40 + -0x1c);
            local_44[-6] = *(undefined4 *)((int)local_40 + -0x18);
            local_44[-5] = *(undefined4 *)((int)local_40 + -0x14);
            local_44[-4] = *(undefined4 *)((int)local_40 + -0x10);
            local_44[-3] = *(undefined4 *)((int)local_40 + -0xc);
            local_44[-2] = *(undefined4 *)((int)local_40 + -8);
            local_44[-1] = *(undefined4 *)((int)local_40 + -4);
            puVar18 = (undefined1 *)((int)local_40 + 0x20);
            puVar13 = local_44 + 8;
          } while (uVar33 < uVar7 - 7);
        }
        local_40 = (undefined4 *)((int)local_40 + -4);
        do {
          local_40 = local_40 + 1;
          local_70 = local_70 + 1;
          *local_44 = *local_40;
          local_44 = local_44 + 1;
        } while (local_70 < uVar7);
        local_ac = local_ac + (int)puVar29;
        puVar8 = puVar30 + uVar7 * -4;
        puVar18 = puVar40 + (int)puVar29;
        if (puVar30 != puVar29) goto LAB_00042d98;
      }
      puVar30 = puVar30 + (int)puVar40;
      puVar8 = puVar30;
      local_ac = puVar35;
      if (puVar5 < puVar19) {
        puVar19 = puVar19 + -(int)puVar5;
        puVar41 = (undefined4 *)
                  (puVar40 + ((iVar27 - (int)puVar40) - (int)puVar5) + local_b0 + uVar11);
        puVar13 = puVar41 + 1;
        puVar18 = puVar30;
        puVar40 = puVar35;
        puVar8 = puVar5;
        if (((((uint)puVar41 | (uint)puVar34) & 3) == 0 &&
            ((undefined1 *)0x3 < puVar5 && (puVar34 + 1 <= puVar41 || puVar13 <= puVar34))) &&
            iVar26 == 0) {
          if (uVar15 < 9) {
            uVar11 = 0;
            puVar23 = puVar34;
          }
          else {
            uVar11 = 0;
            puVar9 = puVar34;
            do {
              puVar13 = puVar41;
              puVar41 = puVar13 + 8;
              puVar23 = puVar9 + 8;
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
              puVar9 = puVar23;
            } while (uVar7 < uVar15 - 7);
            puVar13 = puVar13 + 9;
          }
          puVar23 = puVar23 + -1;
          do {
            puVar9 = puVar13;
            puVar23 = puVar23 + 1;
            uVar11 = uVar11 + 1;
            *puVar41 = *puVar23;
            puVar13 = puVar9 + 1;
            puVar41 = puVar9;
          } while (uVar11 < uVar15);
          puVar18 = puVar30 + (int)puVar25;
          puVar40 = puVar35 + (int)puVar25;
          puVar8 = puVar5 + uVar15 * -4;
          if (puVar5 != puVar25) goto LAB_00042eca;
        }
        else {
LAB_00042eca:
          puVar8 = puVar40 + (int)puVar8;
          do {
            puVar40 = puVar40 + 1;
            puVar18 = puVar18 + 1;
            *puVar18 = *puVar40;
          } while (puVar40 != puVar8);
        }
        puVar8 = puVar30 + (int)puVar5;
        local_ac = puVar30 + (int)puVar5 + -uVar21;
      }
    }
  }
  else {
    local_ac = puVar35 + ((int)puVar5 - (int)puVar18);
    if (puVar18 < puVar19) {
      local_40 = (undefined4 *)(puVar40 + 1);
      uVar7 = (uint)puVar18 >> 2;
      iVar12 = (-local_b0 - (iVar27 - (int)puVar40)) - uVar11;
      local_44 = (undefined4 *)((int)puVar34 + (int)(puVar5 + iVar12 + 1));
      puVar19 = puVar19 + -(int)puVar18;
      puVar8 = (undefined1 *)(uVar7 * 4);
      puVar30 = puVar40;
      if (uVar7 != 0 &&
          ((((uint)local_44 | (uint)local_40) & 3) == 0 &&
          ((undefined1 *)0x3 < puVar18 &&
          (puVar40 + 5 <= local_44 ||
          (undefined4 *)((int)puVar34 + (int)(puVar5 + iVar12 + 5)) <= local_40)))) {
        uVar11 = 0;
        if (8 < uVar7) {
          uVar11 = 0;
          puVar13 = (undefined4 *)(puVar40 + 0x21);
          puVar30 = (undefined1 *)((int)puVar34 + (int)(puVar5 + iVar12 + 0x21));
          do {
            local_44 = (undefined4 *)puVar30;
            local_40 = puVar13;
            uVar33 = uVar11 + 9;
            uVar11 = uVar11 + 8;
            HintPreloadData((undefined1 *)((int)local_44 + 0x54));
            local_40[-8] = *(undefined4 *)((int)local_44 + -0x20);
            local_40[-7] = *(undefined4 *)((int)local_44 + -0x1c);
            local_40[-6] = *(undefined4 *)((int)local_44 + -0x18);
            local_40[-5] = *(undefined4 *)((int)local_44 + -0x14);
            local_40[-4] = *(undefined4 *)((int)local_44 + -0x10);
            local_40[-3] = *(undefined4 *)((int)local_44 + -0xc);
            local_40[-2] = *(undefined4 *)((int)local_44 + -8);
            local_40[-1] = *(undefined4 *)((int)local_44 + -4);
            puVar13 = local_40 + 8;
            puVar30 = (undefined1 *)((int)local_44 + 0x20);
          } while (uVar33 < uVar7 - 7);
        }
        local_44 = (undefined4 *)((int)local_44 + -4);
        do {
          local_44 = local_44 + 1;
          uVar11 = uVar11 + 1;
          *local_40 = *local_44;
          local_40 = local_40 + 1;
        } while (uVar11 < uVar7);
        local_ac = local_ac + (int)puVar8;
        puVar30 = puVar40 + (int)puVar8;
        local_a4 = puVar18 + uVar7 * -4;
        if (puVar18 == puVar8) goto LAB_00042aa4;
      }
      local_a4 = local_ac + (int)local_a4;
      do {
        local_ac = local_ac + 1;
        puVar30 = puVar30 + 1;
        *puVar30 = *local_ac;
      } while (local_ac != local_a4);
      goto LAB_00042aa4;
    }
  }
  for (; puVar40 = puVar8, (undefined1 *)0x2 < puVar19; puVar19 = puVar19 + -3) {
    puVar40[1] = local_ac[1];
    puVar40[2] = local_ac[2];
    puVar40[3] = local_ac[3];
    puVar8 = puVar40 + 3;
    local_ac = local_ac + 3;
  }
  if (puVar19 != (undefined1 *)0x0) {
    if (puVar19 == (undefined1 *)0x2) {
      puVar30 = local_ac;
    }
    puVar40[1] = local_ac[1];
    if (puVar19 == (undefined1 *)0x2) {
      puVar40[2] = puVar30[2];
      puVar40 = puVar40 + 2;
    }
    else {
      puVar40 = puVar40 + 1;
    }
  }
LAB_00042afe:
  if (puVar16 <= puVar40 || uVar14 <= local_a8) {
LAB_00042b36:
    uVar6 = uVar36 + (uVar36 >> 3) * -8;
    iVar20 = local_a8 - (uVar36 >> 3);
    param_1[3] = (int)(puVar40 + 1);
    param_1[1] = (uVar14 - iVar20) + 5;
    *param_1 = iVar20 + 1;
    param_1[4] = (int)(puVar16 + (0x101 - (int)puVar40));
    puVar39[0xe] = (1 << (uVar6 & 0xff)) - 1U & (uint)puVar38;
    puVar39[0xf] = uVar6;
    return;
  }
  goto LAB_000427aa;
}

