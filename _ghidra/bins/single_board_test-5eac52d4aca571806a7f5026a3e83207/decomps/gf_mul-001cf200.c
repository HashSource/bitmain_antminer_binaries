
void gf_mul(uint *param_1,uint *param_2,uint *param_3)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  int iVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint *puVar37;
  undefined8 local_e8;
  uint *local_dc;
  longlong local_d8;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint *local_c0;
  int local_bc;
  int local_b8;
  uint *local_b0;
  uint *local_ac;
  uint local_80 [5];
  uint *local_6c;
  uint local_68 [4];
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48 [9];
  
  uVar12 = param_2[8];
  uVar5 = *param_2;
  uVar4 = param_3[8];
  local_c8 = 0;
  local_c4 = 0;
  uVar6 = param_3[9];
  local_d0 = 0;
  local_cc = 0;
  local_c0 = local_48 + 3;
  uVar27 = param_2[9];
  local_6c = param_1;
  local_dc = param_3 + 1;
  uVar3 = *param_3;
  uVar23 = param_3[1];
  uVar13 = param_2[1];
  uVar21 = uVar4 + uVar3;
  uVar30 = param_3[10];
  uVar7 = param_3[2];
  uVar22 = param_2[10];
  uVar14 = param_2[2];
  uVar31 = param_3[0xb];
  uVar24 = param_2[0xb];
  uVar15 = param_2[3];
  uVar8 = param_3[3];
  uVar16 = param_2[4];
  uVar25 = param_3[0xc];
  uVar9 = param_3[4];
  uVar32 = param_2[0xc];
  uVar33 = param_2[0xd];
  uVar17 = param_2[5];
  local_68[0] = uVar12 + uVar5;
  local_48[0] = uVar4 + uVar3;
  local_68[1] = uVar27 + uVar13;
  local_68[2] = uVar22 + uVar14;
  local_48[2] = uVar30 + uVar7;
  local_48[1] = uVar6 + uVar23;
  local_48[3] = uVar31 + uVar8;
  local_58 = uVar32 + uVar16;
  uVar10 = param_3[0xd];
  uVar18 = param_3[5];
  local_68[3] = uVar24 + uVar15;
  local_54 = uVar33 + uVar17;
  local_48[4] = uVar25 + uVar9;
  uVar19 = param_3[6];
  uVar26 = param_2[6];
  uVar11 = param_2[7];
  uVar34 = param_2[0xe];
  local_bc = 0;
  uVar35 = param_3[0xe];
  uVar36 = param_2[0xf];
  local_48[7] = param_3[7] + param_3[0xf];
  local_48[5] = uVar10 + uVar18;
  local_48[6] = uVar35 + uVar19;
  local_50 = uVar34 + uVar26;
  local_4c = uVar11 + uVar36;
  puVar37 = local_80 + 5;
  local_b0 = param_1 + -1;
  local_ac = param_2 + -1;
  do {
    local_e8 = (ulonglong)local_ac[1] * (ulonglong)uVar3;
    lVar2 = (ulonglong)uVar4 * (ulonglong)local_ac[9] + CONCAT44(local_cc,local_d0);
    local_d8 = (ulonglong)uVar21 * (ulonglong)puVar37[1] + CONCAT44(local_c4,local_c8);
    if (local_bc == 0) {
LAB_001cf5a0:
      local_d8 = local_d8 - local_e8;
      local_e8 = local_e8 + lVar2;
LAB_001cf5c2:
      local_b8 = local_bc + 2;
      iVar20 = local_bc + 1;
      local_d8 = (ulonglong)local_dc[8] * (ulonglong)param_2[0xf] + local_d8;
      uVar3 = (uint)((ulonglong)param_2[7] * (ulonglong)*local_dc);
      uVar4 = (uint)local_e8 - uVar3;
      iVar28 = (local_e8._4_4_ - (int)((ulonglong)param_2[7] * (ulonglong)*local_dc >> 0x20)) -
               (uint)((uint)local_e8 < uVar3);
      local_e8 = CONCAT44(iVar28,uVar4);
      lVar1 = (ulonglong)(uVar11 + uVar36) * (ulonglong)local_48[iVar20];
      if (local_b8 < 8) {
        lVar1 = (ulonglong)local_48[local_b8] * (ulonglong)(uVar34 + uVar26) + lVar1;
        uVar3 = (uint)((ulonglong)param_2[6] * (ulonglong)local_dc[1]);
        uVar29 = uVar4 - uVar3;
        iVar28 = (iVar28 - (int)((ulonglong)param_2[6] * (ulonglong)local_dc[1] >> 0x20)) -
                 (uint)(uVar4 < uVar3);
        local_e8 = CONCAT44(iVar28,uVar29);
        local_d8 = (ulonglong)local_dc[9] * (ulonglong)param_2[0xe] + local_d8;
        if (local_bc + 3U < 8) {
          uVar3 = (uint)((ulonglong)param_2[5] * (ulonglong)local_dc[2]);
          lVar1 = (ulonglong)*local_c0 * (ulonglong)(uVar33 + uVar17) + lVar1;
          uVar4 = uVar29 - uVar3;
          iVar28 = (iVar28 - (int)((ulonglong)param_2[5] * (ulonglong)local_dc[2] >> 0x20)) -
                   (uint)(uVar29 < uVar3);
          local_e8 = CONCAT44(iVar28,uVar4);
          local_d8 = (ulonglong)local_dc[10] * (ulonglong)param_2[0xd] + local_d8;
          if (local_bc + 4U < 8) {
            uVar3 = (uint)((ulonglong)param_2[4] * (ulonglong)local_dc[3]);
            lVar1 = (ulonglong)local_c0[1] * (ulonglong)(uVar32 + uVar16) + lVar1;
            uVar29 = uVar4 - uVar3;
            iVar28 = (iVar28 - (int)((ulonglong)param_2[4] * (ulonglong)local_dc[3] >> 0x20)) -
                     (uint)(uVar4 < uVar3);
            local_e8 = CONCAT44(iVar28,uVar29);
            local_d8 = (ulonglong)local_dc[0xb] * (ulonglong)param_2[0xc] + local_d8;
            if (local_bc + 5U < 8) {
              uVar3 = (uint)((ulonglong)param_2[3] * (ulonglong)local_dc[4]);
              lVar1 = (ulonglong)local_c0[2] * (ulonglong)(uVar24 + uVar15) + lVar1;
              uVar4 = uVar29 - uVar3;
              iVar28 = (iVar28 - (int)((ulonglong)param_2[3] * (ulonglong)local_dc[4] >> 0x20)) -
                       (uint)(uVar29 < uVar3);
              local_e8 = CONCAT44(iVar28,uVar4);
              local_d8 = (ulonglong)local_dc[0xc] * (ulonglong)param_2[0xb] + local_d8;
              if (local_bc + 6U < 8) {
                uVar29 = (uint)((ulonglong)param_2[2] * (ulonglong)local_dc[5]);
                lVar1 = (ulonglong)local_c0[3] * (ulonglong)(uVar22 + uVar14) + lVar1;
                uVar3 = uVar4 - uVar29;
                iVar28 = (iVar28 - (int)((ulonglong)param_2[2] * (ulonglong)local_dc[5] >> 0x20)) -
                         (uint)(uVar4 < uVar29);
                local_e8 = CONCAT44(iVar28,uVar3);
                local_d8 = (ulonglong)local_dc[0xd] * (ulonglong)param_2[10] + local_d8;
                if (local_bc == 0) {
                  lVar1 = (ulonglong)local_48[7] * (ulonglong)(uVar27 + uVar13) + lVar1;
                  uVar4 = (uint)((ulonglong)param_2[1] * (ulonglong)param_3[7]);
                  local_d8 = (ulonglong)local_dc[0xe] * (ulonglong)param_2[9] + local_d8;
                  local_e8 = CONCAT44((iVar28 - (int)((ulonglong)param_2[1] * (ulonglong)param_3[7]
                                                     >> 0x20)) - (uint)(uVar3 < uVar4),uVar3 - uVar4
                                     );
                }
              }
            }
          }
        }
      }
    }
    else {
      local_e8 = (ulonglong)param_3[1] * (ulonglong)*local_ac + local_e8;
      local_d8 = (ulonglong)(uVar6 + uVar23) * (ulonglong)*puVar37 + local_d8;
      lVar2 = (ulonglong)param_3[9] * (ulonglong)local_ac[8] + lVar2;
      if (local_bc == 1) goto LAB_001cf5a0;
      local_e8 = (ulonglong)param_3[2] * (ulonglong)local_ac[-1] + local_e8;
      local_d8 = (ulonglong)(uVar30 + uVar7) * (ulonglong)puVar37[-1] + local_d8;
      lVar2 = (ulonglong)param_3[10] * (ulonglong)local_ac[7] + lVar2;
      if (local_bc == 2) goto LAB_001cf5a0;
      local_e8 = (ulonglong)param_3[3] * (ulonglong)local_ac[-2] + local_e8;
      local_d8 = (ulonglong)(uVar31 + uVar8) * (ulonglong)puVar37[-2] + local_d8;
      lVar2 = (ulonglong)param_3[0xb] * (ulonglong)local_ac[6] + lVar2;
      if (local_bc == 3) goto LAB_001cf5a0;
      local_e8 = (ulonglong)param_3[4] * (ulonglong)local_ac[-3] + local_e8;
      local_d8 = (ulonglong)(uVar25 + uVar9) * (ulonglong)puVar37[-3] + local_d8;
      lVar2 = (ulonglong)param_3[0xc] * (ulonglong)local_ac[5] + lVar2;
      if (local_bc == 4) goto LAB_001cf5a0;
      local_e8 = (ulonglong)param_3[5] * (ulonglong)local_ac[-4] + local_e8;
      local_d8 = (ulonglong)(uVar10 + uVar18) * (ulonglong)puVar37[-4] + local_d8;
      lVar2 = (ulonglong)param_3[0xd] * (ulonglong)local_ac[4] + lVar2;
      if (local_bc == 5) goto LAB_001cf5a0;
      local_e8 = (ulonglong)param_3[6] * (ulonglong)local_ac[-5] + local_e8;
      local_d8 = (ulonglong)(uVar35 + uVar19) * (ulonglong)puVar37[-5] + local_d8;
      lVar2 = (ulonglong)param_3[0xe] * (ulonglong)local_ac[3] + lVar2;
      if (local_bc != 7) {
        local_d8 = local_d8 - local_e8;
        local_e8 = local_e8 + lVar2;
        if (local_bc == 7) {
          lVar1 = 0;
          iVar20 = 8;
          goto LAB_001cf4de;
        }
        goto LAB_001cf5c2;
      }
      local_bc = 8;
      local_e8 = (ulonglong)param_3[7] * (ulonglong)*param_2 + local_e8;
      lVar1 = 0;
      local_d8 = ((ulonglong)local_48[7] * (ulonglong)(uVar12 + uVar5) + local_d8) - local_e8;
      local_e8 = (ulonglong)param_3[0xf] * (ulonglong)param_2[8] + lVar2 + local_e8;
      iVar20 = local_bc;
    }
LAB_001cf4de:
    local_bc = iVar20;
    uVar4 = (uint)(lVar1 + local_d8);
    local_c4 = (uint)((ulonglong)(lVar1 + local_d8) >> 0x20);
    uVar3 = (uint)(lVar1 + local_e8);
    local_cc = (uint)((ulonglong)(lVar1 + local_e8) >> 0x20);
    local_c8 = uVar4 >> 0x1c | local_c4 * 0x10;
    local_d0 = uVar3 >> 0x1c | local_cc * 0x10;
    local_c4 = local_c4 >> 0x1c;
    local_cc = local_cc >> 0x1c;
    local_b0[1] = uVar3 & 0xfffffff;
    local_b0[9] = uVar4 & 0xfffffff;
    local_dc = local_dc + 1;
    local_c0 = local_c0 + 1;
    if (local_bc == 8) {
      uVar3 = param_1[8];
      uVar4 = *param_1;
      uVar6 = local_d0 + local_c8 + uVar3;
      uVar5 = local_c8 + uVar4;
      param_1[8] = uVar6 & 0xfffffff;
      param_1[9] = param_1[9] +
                   (uVar6 >> 0x1c |
                   (local_cc + local_c4 + CARRY4(local_d0,local_c8) +
                   (uint)CARRY4(local_d0 + local_c8,uVar3)) * 0x10);
      *param_1 = uVar5 & 0xfffffff;
      param_1[1] = (uVar5 >> 0x1c | (local_c4 + CARRY4(local_c8,uVar4)) * 0x10) + param_1[1];
      return;
    }
    uVar4 = param_3[8];
    uVar3 = *param_3;
    puVar37 = puVar37 + 1;
    local_b0 = local_b0 + 1;
    local_ac = local_ac + 1;
  } while( true );
}

