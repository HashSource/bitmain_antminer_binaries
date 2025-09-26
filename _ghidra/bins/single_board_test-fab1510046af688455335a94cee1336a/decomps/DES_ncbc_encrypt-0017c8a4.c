
void DES_ncbc_encrypt(uchar *input,uchar *output,long length,DES_key_schedule *schedule,
                     DES_cblock *ivec,int enc)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte bVar8;
  uchar uVar9;
  uchar uVar10;
  int iVar11;
  uchar uVar12;
  uint uVar13;
  uchar uVar14;
  uint uVar15;
  uchar uVar16;
  byte *pbVar17;
  uchar uVar18;
  uchar *puVar19;
  uchar uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uchar uVar25;
  uchar *local_4c;
  byte *local_44;
  uint local_30;
  uint local_2c;
  
  local_4c = output;
  local_44 = input;
  if (enc == 0) {
    uVar24 = length - 8;
    uVar21 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
             (uint)(*ivec)[3] << 0x18;
    uVar15 = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
             (uint)(*ivec)[7] << 0x18;
    if (-1 < (int)uVar24) {
      pbVar17 = input;
      puVar19 = output;
      uVar22 = uVar24;
      uVar13 = uVar15;
      uVar23 = uVar21;
      do {
        pbVar1 = pbVar17 + 2;
        pbVar4 = pbVar17 + 1;
        pbVar2 = pbVar17 + 6;
        pbVar5 = pbVar17 + 5;
        pbVar3 = pbVar17 + 4;
        bVar8 = *pbVar17;
        pbVar6 = pbVar17 + 3;
        pbVar7 = pbVar17 + 7;
        pbVar17 = pbVar17 + 8;
        uVar21 = (uint)*pbVar1 << 0x10 | (uint)*pbVar4 << 8 | (uint)bVar8 | (uint)*pbVar6 << 0x18;
        uVar15 = (uint)*pbVar2 << 0x10 | (uint)*pbVar5 << 8 | (uint)*pbVar3 | (uint)*pbVar7 << 0x18;
        local_30 = uVar21;
        local_2c = uVar15;
        DES_encrypt1_constprop_3(&local_30,schedule);
        uVar22 = uVar22 - 8;
        uVar23 = uVar23 ^ local_30;
        uVar13 = uVar13 ^ local_2c;
        *puVar19 = (uchar)uVar23;
        puVar19[4] = (uchar)uVar13;
        puVar19[1] = (uchar)(uVar23 >> 8);
        puVar19[2] = (uchar)(uVar23 >> 0x10);
        puVar19[3] = (uchar)(uVar23 >> 0x18);
        puVar19[5] = (uchar)(uVar13 >> 8);
        puVar19[6] = (uchar)(uVar13 >> 0x10);
        puVar19[7] = (uchar)(uVar13 >> 0x18);
        puVar19 = puVar19 + 8;
        uVar13 = uVar15;
        uVar23 = uVar21;
      } while (-1 < (int)uVar22);
      iVar11 = ((uVar24 >> 3) + 1) * 8;
      uVar24 = length + -0x10 + (uVar24 >> 3) * -8;
      local_44 = input + iVar11;
      local_4c = output + iVar11;
    }
    uVar22 = uVar21;
    uVar13 = uVar15;
    if (uVar24 == 0xfffffff8) goto switchD_0017cb6c_default;
    uVar22 = (uint)local_44[2] << 0x10 | (uint)local_44[1] << 8 | (uint)*local_44 |
             (uint)local_44[3] << 0x18;
    uVar13 = (uint)local_44[6] << 0x10 | (uint)local_44[5] << 8 | (uint)local_44[4] |
             (uint)local_44[7] << 0x18;
    local_30 = uVar22;
    local_2c = uVar13;
    DES_encrypt1_constprop_3(&local_30,schedule);
    uVar15 = uVar15 ^ local_2c;
    local_4c = local_4c + uVar24 + 8;
    uVar21 = uVar21 ^ local_30;
    puVar19 = local_4c;
    switch(uVar24) {
    case 0xfffffff9:
      goto LAB_0017cba6;
    case 0xfffffffa:
      goto switchD_0017cb6c_caseD_fffffffa;
    case 0xfffffffb:
      goto LAB_0017cb96;
    case 0xfffffffc:
      goto switchD_0017cb6c_caseD_fffffffc;
    case 0xfffffffd:
      break;
    case 0xffffffff:
      local_4c[-1] = (uchar)(uVar15 >> 0x10);
      puVar19 = local_4c + -1;
    case 0xfffffffe:
      local_4c = puVar19 + -1;
      puVar19[-1] = (uchar)(uVar15 >> 8);
      break;
    default:
      goto switchD_0017cb6c_default;
    }
    puVar19 = local_4c + -1;
    local_4c[-1] = (uchar)uVar15;
switchD_0017cb6c_caseD_fffffffc:
    local_4c = puVar19 + -1;
    puVar19[-1] = (uchar)(uVar21 >> 0x18);
LAB_0017cb96:
    puVar19 = local_4c + -1;
    local_4c[-1] = (uchar)(uVar21 >> 0x10);
switchD_0017cb6c_caseD_fffffffa:
    local_4c = puVar19 + -1;
    puVar19[-1] = (uchar)(uVar21 >> 8);
LAB_0017cba6:
    local_4c[-1] = (uchar)uVar21;
switchD_0017cb6c_default:
    (*ivec)[0] = (uchar)uVar22;
    (*ivec)[4] = (uchar)uVar13;
    (*ivec)[1] = (uchar)(uVar22 >> 8);
    (*ivec)[2] = (uchar)(uVar22 >> 0x10);
    (*ivec)[3] = (uchar)(uVar22 >> 0x18);
    (*ivec)[5] = (uchar)(uVar13 >> 8);
    (*ivec)[6] = (uchar)(uVar13 >> 0x10);
    (*ivec)[7] = (uchar)(uVar13 >> 0x18);
    return;
  }
  uVar15 = length - 8;
  local_30 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
             (uint)(*ivec)[3] << 0x18;
  local_2c = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
             (uint)(*ivec)[7] << 0x18;
  if (-1 < (int)uVar15) {
    pbVar17 = input;
    puVar19 = output;
    uVar21 = uVar15;
    do {
      pbVar7 = pbVar17 + 2;
      pbVar1 = pbVar17 + 1;
      pbVar2 = pbVar17 + 6;
      pbVar3 = pbVar17 + 5;
      pbVar4 = pbVar17 + 4;
      bVar8 = *pbVar17;
      pbVar5 = pbVar17 + 7;
      pbVar6 = pbVar17 + 3;
      pbVar17 = pbVar17 + 8;
      local_2c = local_2c ^
                 ((uint)*pbVar2 << 0x10 | (uint)*pbVar3 << 8 | (uint)*pbVar4 | (uint)*pbVar5 << 0x18
                 );
      local_30 = local_30 ^
                 ((uint)*pbVar7 << 0x10 | (uint)*pbVar1 << 8 | (uint)bVar8 | (uint)*pbVar6 << 0x18);
      DES_encrypt1_constprop_2(&local_30,schedule);
      uVar21 = uVar21 - 8;
      *puVar19 = (uchar)local_30;
      puVar19[1] = (uchar)(local_30 >> 8);
      puVar19[2] = (uchar)(local_30 >> 0x10);
      puVar19[3] = (uchar)(local_30 >> 0x18);
      puVar19[4] = (uchar)local_2c;
      puVar19[5] = (uchar)(local_2c >> 8);
      puVar19[6] = (uchar)(local_2c >> 0x10);
      puVar19[7] = (uchar)(local_2c >> 0x18);
      puVar19 = puVar19 + 8;
    } while (-1 < (int)uVar21);
    uVar21 = uVar15 >> 3;
    uVar15 = length + -0x10 + uVar21 * -8;
    iVar11 = (uVar21 + 1) * 8;
    local_44 = input + iVar11;
    local_4c = output + iVar11;
  }
  if (uVar15 == 0xfffffff8) {
    uVar25 = (uchar)local_30;
    uVar20 = (uchar)(local_30 >> 8);
    uVar18 = (uchar)(local_30 >> 0x10);
    uVar16 = (uchar)local_2c;
    uVar9 = (uchar)(local_2c >> 8);
    uVar12 = (uchar)(local_30 >> 0x18);
    uVar10 = (uchar)(local_2c >> 0x10);
    uVar14 = (uchar)(local_2c >> 0x18);
    goto LAB_0017cbf2;
  }
  puVar19 = local_44 + uVar15 + 8;
  switch(uVar15) {
  case 0xfffffff9:
    uVar21 = 0;
    uVar15 = uVar21;
    goto LAB_0017cc3c;
  case 0xfffffffa:
    uVar21 = 0;
    uVar15 = uVar21;
    goto LAB_0017cc32;
  case 0xfffffffb:
    uVar21 = 0;
    uVar15 = uVar21;
    goto LAB_0017cc28;
  case 0xfffffffc:
    uVar21 = 0;
    goto LAB_0017cc20;
  case 0xfffffffd:
    uVar21 = 0;
    goto LAB_0017cc18;
  case 0xfffffffe:
    uVar21 = 0;
    break;
  case 0xffffffff:
    pbVar17 = puVar19 + -1;
    puVar19 = puVar19 + -1;
    uVar21 = (uint)*pbVar17 << 0x10;
    break;
  default:
    uVar21 = 0;
    uVar15 = uVar21;
    goto LAB_0017cc42;
  }
  pbVar17 = puVar19 + -1;
  puVar19 = puVar19 + -1;
  uVar21 = uVar21 | (uint)*pbVar17 << 8;
LAB_0017cc18:
  pbVar17 = puVar19 + -1;
  puVar19 = puVar19 + -1;
  uVar21 = uVar21 | *pbVar17;
LAB_0017cc20:
  pbVar17 = puVar19 + -1;
  puVar19 = puVar19 + -1;
  uVar15 = (uint)*pbVar17 << 0x18;
LAB_0017cc28:
  pbVar17 = puVar19 + -1;
  puVar19 = puVar19 + -1;
  uVar15 = uVar15 | (uint)*pbVar17 << 0x10;
LAB_0017cc32:
  pbVar17 = puVar19 + -1;
  puVar19 = puVar19 + -1;
  uVar15 = uVar15 | (uint)*pbVar17 << 8;
LAB_0017cc3c:
  uVar15 = puVar19[-1] | uVar15;
LAB_0017cc42:
  local_30 = local_30 ^ uVar15;
  local_2c = local_2c ^ uVar21;
  DES_encrypt1_constprop_2(&local_30,schedule);
  uVar25 = (uchar)local_30;
  *local_4c = uVar25;
  uVar12 = (uchar)(local_30 >> 0x18);
  local_4c[3] = uVar12;
  uVar20 = (uchar)(local_30 >> 8);
  local_4c[1] = uVar20;
  uVar18 = (uchar)(local_30 >> 0x10);
  local_4c[2] = uVar18;
  uVar16 = (uchar)local_2c;
  local_4c[4] = uVar16;
  uVar14 = (uchar)(local_2c >> 0x18);
  local_4c[7] = uVar14;
  uVar9 = (uchar)(local_2c >> 8);
  local_4c[5] = uVar9;
  uVar10 = (uchar)(local_2c >> 0x10);
  local_4c[6] = uVar10;
LAB_0017cbf2:
  (*ivec)[0] = uVar25;
  (*ivec)[1] = uVar20;
  (*ivec)[2] = uVar18;
  (*ivec)[3] = uVar12;
  (*ivec)[4] = uVar16;
  (*ivec)[5] = uVar9;
  (*ivec)[6] = uVar10;
  (*ivec)[7] = uVar14;
  return;
}

