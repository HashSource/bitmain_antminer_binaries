
void IDEA_cbc_encrypt(byte *param_1,byte *param_2,int param_3,undefined4 param_4,byte *param_5,
                     int param_6)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  byte bVar9;
  byte bVar10;
  byte *pbVar11;
  byte bVar12;
  uint uVar13;
  byte bVar14;
  uint uVar15;
  uint uVar16;
  byte bVar17;
  byte *local_40;
  byte *local_3c;
  uint local_30;
  uint local_2c;
  
  local_40 = param_2;
  local_3c = param_1;
  if (param_6 == 0) {
    uVar15 = param_3 - 8;
    uVar13 = (uint)param_5[1] << 0x10 | (uint)*param_5 << 0x18 | (uint)param_5[3] |
             (uint)param_5[2] << 8;
    uVar8 = (uint)param_5[5] << 0x10 | (uint)param_5[4] << 0x18 | (uint)param_5[7] |
            (uint)param_5[6] << 8;
    if (-1 < (int)uVar15) {
      uVar6 = uVar8;
      uVar16 = uVar15;
      uVar2 = uVar13;
      pbVar7 = param_2;
      pbVar11 = param_1;
      do {
        uVar13 = (uint)pbVar11[1] << 0x10 | (uint)*pbVar11 << 0x18 | (uint)pbVar11[3] |
                 (uint)pbVar11[2] << 8;
        uVar8 = (uint)pbVar11[7] | (uint)pbVar11[5] << 0x10 | (uint)pbVar11[4] << 0x18 |
                (uint)pbVar11[6] << 8;
        local_30 = uVar13;
        local_2c = uVar8;
        IDEA_encrypt(&local_30,param_4);
        uVar16 = uVar16 - 8;
        uVar2 = uVar2 ^ local_30;
        uVar6 = uVar6 ^ local_2c;
        pbVar7[3] = (byte)uVar2;
        pbVar7[7] = (byte)uVar6;
        *pbVar7 = (byte)(uVar2 >> 0x18);
        pbVar7[1] = (byte)(uVar2 >> 0x10);
        pbVar7[2] = (byte)(uVar2 >> 8);
        pbVar7[4] = (byte)(uVar6 >> 0x18);
        pbVar7[5] = (byte)(uVar6 >> 0x10);
        pbVar7[6] = (byte)(uVar6 >> 8);
        uVar6 = uVar8;
        uVar2 = uVar13;
        pbVar7 = pbVar7 + 8;
        pbVar11 = pbVar11 + 8;
      } while (-1 < (int)uVar16);
      iVar5 = ((uVar15 >> 3) + 1) * 8;
      uVar15 = param_3 + -0x10 + (uVar15 >> 3) * -8;
      local_3c = param_1 + iVar5;
      local_40 = param_2 + iVar5;
    }
    uVar6 = uVar8;
    uVar16 = uVar13;
    if (uVar15 == 0xfffffff8) goto switchD_001310a0_default;
    uVar16 = (uint)local_3c[1] << 0x10 | (uint)*local_3c << 0x18 | (uint)local_3c[3] |
             (uint)local_3c[2] << 8;
    uVar6 = (uint)local_3c[5] << 0x10 | (uint)local_3c[4] << 0x18 | (uint)local_3c[7] |
            (uint)local_3c[6] << 8;
    local_30 = uVar16;
    local_2c = uVar6;
    IDEA_encrypt(&local_30,param_4);
    local_40 = local_40 + uVar15 + 8;
    uVar13 = uVar13 ^ local_30;
    uVar8 = uVar8 ^ local_2c;
    switch(uVar15) {
    case 0xfffffff9:
      goto LAB_001310d8;
    case 0xfffffffa:
      goto switchD_001310a0_caseD_fffffffa;
    case 0xfffffffb:
      pbVar7 = local_40;
      goto LAB_001310c8;
    case 0xfffffffc:
      goto switchD_001310a0_caseD_fffffffc;
    case 0xfffffffd:
      pbVar7 = local_40;
      break;
    case 0xffffffff:
      local_40 = local_40 + -1;
      *local_40 = (byte)(uVar8 >> 8);
    case 0xfffffffe:
      local_40[-1] = (byte)(uVar8 >> 0x10);
      pbVar7 = local_40 + -1;
      break;
    default:
      goto switchD_001310a0_default;
    }
    local_40 = pbVar7 + -1;
    pbVar7[-1] = (byte)(uVar8 >> 0x18);
switchD_001310a0_caseD_fffffffc:
    local_40[-1] = (byte)uVar13;
    pbVar7 = local_40 + -1;
LAB_001310c8:
    local_40 = pbVar7 + -1;
    pbVar7[-1] = (byte)(uVar13 >> 8);
switchD_001310a0_caseD_fffffffa:
    local_40[-1] = (byte)(uVar13 >> 0x10);
    local_40 = local_40 + -1;
LAB_001310d8:
    local_40[-1] = (byte)(uVar13 >> 0x18);
switchD_001310a0_default:
    param_5[3] = (byte)uVar16;
    param_5[7] = (byte)uVar6;
    *param_5 = (byte)(uVar16 >> 0x18);
    param_5[1] = (byte)(uVar16 >> 0x10);
    param_5[2] = (byte)(uVar16 >> 8);
    param_5[4] = (byte)(uVar6 >> 0x18);
    param_5[5] = (byte)(uVar6 >> 0x10);
    param_5[6] = (byte)(uVar6 >> 8);
    return;
  }
  uVar8 = param_3 - 8;
  local_30 = (uint)param_5[3] | (uint)param_5[1] << 0x10 | (uint)*param_5 << 0x18 |
             (uint)param_5[2] << 8;
  local_2c = (uint)param_5[5] << 0x10 | (uint)param_5[4] << 0x18 | (uint)param_5[7] |
             (uint)param_5[6] << 8;
  if (-1 < (int)uVar8) {
    pbVar7 = param_2 + 8;
    pbVar11 = param_1 + 8;
    uVar13 = uVar8;
    do {
      local_30 = local_30 ^
                 ((uint)pbVar11[-7] << 0x10 | (uint)pbVar11[-8] << 0x18 | (uint)pbVar11[-5] |
                 (uint)pbVar11[-6] << 8);
      local_2c = local_2c ^
                 ((uint)pbVar11[-3] << 0x10 | (uint)pbVar11[-4] << 0x18 | (uint)pbVar11[-1] |
                 (uint)pbVar11[-2] << 8);
      IDEA_encrypt(&local_30,param_4);
      uVar13 = uVar13 - 8;
      pbVar7[-5] = (byte)local_30;
      pbVar7[-8] = (byte)(local_30 >> 0x18);
      pbVar7[-7] = (byte)(local_30 >> 0x10);
      pbVar7[-6] = (byte)(local_30 >> 8);
      pbVar7[-1] = (byte)local_2c;
      pbVar7[-4] = (byte)(local_2c >> 0x18);
      pbVar7[-3] = (byte)(local_2c >> 0x10);
      pbVar7[-2] = (byte)(local_2c >> 8);
      pbVar7 = pbVar7 + 8;
      pbVar11 = pbVar11 + 8;
    } while (-1 < (int)uVar13);
    uVar13 = uVar8 >> 3;
    uVar8 = param_3 + -0x10 + uVar13 * -8;
    iVar5 = (uVar13 + 1) * 8;
    local_3c = param_1 + iVar5;
    local_40 = param_2 + iVar5;
  }
  if (uVar8 == 0xfffffff8) {
    bVar1 = (byte)(local_2c >> 0x18);
    bVar3 = (byte)(local_2c >> 0x10);
    bVar4 = (byte)(local_2c >> 8);
    bVar12 = (byte)(local_30 >> 0x18);
    bVar17 = (byte)local_30;
    bVar14 = (byte)local_2c;
    bVar10 = (byte)(local_30 >> 0x10);
    bVar9 = (byte)(local_30 >> 8);
    goto LAB_0013112e;
  }
  local_3c = local_3c + uVar8 + 8;
  switch(uVar8) {
  case 0xfffffff9:
    uVar13 = 0;
    uVar8 = uVar13;
    goto LAB_0013118a;
  case 0xfffffffa:
    uVar13 = 0;
    uVar8 = uVar13;
    goto LAB_00131180;
  case 0xfffffffb:
    uVar13 = 0;
    uVar8 = uVar13;
    goto LAB_00131176;
  case 0xfffffffc:
    uVar8 = 0;
    goto LAB_00131170;
  case 0xfffffffd:
    uVar8 = 0;
    goto LAB_00131166;
  case 0xfffffffe:
    uVar8 = 0;
    break;
  case 0xffffffff:
    pbVar7 = local_3c + -1;
    local_3c = local_3c + -1;
    uVar8 = (uint)*pbVar7 << 8;
    break;
  default:
    uVar13 = 0;
    uVar8 = uVar13;
    goto LAB_00131192;
  }
  pbVar7 = local_3c + -1;
  local_3c = local_3c + -1;
  uVar8 = uVar8 | (uint)*pbVar7 << 0x10;
LAB_00131166:
  pbVar7 = local_3c + -1;
  local_3c = local_3c + -1;
  uVar8 = uVar8 | (uint)*pbVar7 << 0x18;
LAB_00131170:
  uVar13 = (uint)local_3c[-1];
  local_3c = local_3c + -1;
LAB_00131176:
  pbVar7 = local_3c + -1;
  local_3c = local_3c + -1;
  uVar13 = uVar13 | (uint)*pbVar7 << 8;
LAB_00131180:
  pbVar7 = local_3c + -1;
  local_3c = local_3c + -1;
  uVar13 = uVar13 | (uint)*pbVar7 << 0x10;
LAB_0013118a:
  uVar13 = uVar13 | (uint)local_3c[-1] << 0x18;
LAB_00131192:
  local_30 = local_30 ^ uVar13;
  local_2c = local_2c ^ uVar8;
  IDEA_encrypt(&local_30,param_4);
  bVar12 = (byte)(local_30 >> 0x18);
  *local_40 = bVar12;
  bVar17 = (byte)local_30;
  local_40[3] = bVar17;
  bVar10 = (byte)(local_30 >> 0x10);
  local_40[1] = bVar10;
  bVar9 = (byte)(local_30 >> 8);
  local_40[2] = bVar9;
  bVar1 = (byte)(local_2c >> 0x18);
  local_40[4] = bVar1;
  bVar14 = (byte)local_2c;
  local_40[7] = bVar14;
  bVar3 = (byte)(local_2c >> 0x10);
  local_40[5] = bVar3;
  bVar4 = (byte)(local_2c >> 8);
  local_40[6] = bVar4;
LAB_0013112e:
  *param_5 = bVar12;
  param_5[1] = bVar10;
  param_5[2] = bVar9;
  param_5[3] = bVar17;
  param_5[4] = bVar1;
  param_5[5] = bVar3;
  param_5[6] = bVar4;
  param_5[7] = bVar14;
  return;
}

