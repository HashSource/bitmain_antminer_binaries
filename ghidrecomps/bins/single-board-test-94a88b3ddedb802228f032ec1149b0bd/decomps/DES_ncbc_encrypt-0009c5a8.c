
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
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  uchar uVar16;
  uchar uVar17;
  int iVar18;
  uchar uVar19;
  uint uVar20;
  uchar uVar21;
  uint uVar22;
  uchar uVar23;
  byte *pbVar24;
  uchar uVar25;
  uchar *puVar26;
  uchar uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uchar uVar32;
  uchar *local_4c;
  byte *local_44;
  uint local_30;
  uint local_2c;
  
  local_4c = output;
  local_44 = input;
  if (enc != 0) {
    uVar22 = length - 8;
    local_30 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
               (uint)(*ivec)[3] << 0x18;
    local_2c = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
               (uint)(*ivec)[7] << 0x18;
    if (-1 < (int)uVar22) {
      pbVar24 = input;
      puVar26 = output;
      uVar28 = uVar22;
      do {
        pbVar7 = pbVar24 + 2;
        pbVar1 = pbVar24 + 1;
        pbVar2 = pbVar24 + 6;
        pbVar3 = pbVar24 + 5;
        pbVar4 = pbVar24 + 4;
        bVar8 = *pbVar24;
        pbVar5 = pbVar24 + 7;
        pbVar6 = pbVar24 + 3;
        pbVar24 = pbVar24 + 8;
        local_2c = local_2c ^
                   ((uint)*pbVar2 << 0x10 | (uint)*pbVar3 << 8 | (uint)*pbVar4 |
                   (uint)*pbVar5 << 0x18);
        local_30 = local_30 ^
                   ((uint)*pbVar7 << 0x10 | (uint)*pbVar1 << 8 | (uint)bVar8 | (uint)*pbVar6 << 0x18
                   );
        DES_encrypt1_constprop_2(&local_30,schedule);
        uVar28 = uVar28 - 8;
        *puVar26 = (uchar)local_30;
        puVar26[1] = (uchar)(local_30 >> 8);
        puVar26[2] = (uchar)(local_30 >> 0x10);
        puVar26[3] = (uchar)(local_30 >> 0x18);
        puVar26[4] = (uchar)local_2c;
        puVar26[5] = (uchar)(local_2c >> 8);
        puVar26[6] = (uchar)(local_2c >> 0x10);
        puVar26[7] = (uchar)(local_2c >> 0x18);
        puVar26 = puVar26 + 8;
      } while (-1 < (int)uVar28);
      uVar28 = uVar22 >> 3;
      uVar22 = (length + -0x10) - (uVar22 & 0xfffffff8);
      iVar18 = (uVar28 + 1) * 8;
      local_44 = input + iVar18;
      local_4c = output + iVar18;
    }
    if (uVar22 == 0xfffffff8) {
      uVar32 = (uchar)local_30;
      uVar27 = (uchar)(local_30 >> 8);
      uVar25 = (uchar)(local_30 >> 0x10);
      uVar23 = (uchar)local_2c;
      uVar16 = (uchar)(local_2c >> 8);
      uVar19 = (uchar)(local_30 >> 0x18);
      uVar17 = (uchar)(local_2c >> 0x10);
      uVar21 = (uchar)(local_2c >> 0x18);
      goto LAB_0009c8f6;
    }
    puVar26 = local_44 + uVar22 + 8;
    switch(uVar22) {
    default:
      uVar28 = 0;
      uVar22 = uVar28;
      goto LAB_0009c946;
    case 0xfffffff9:
      uVar28 = 0;
      uVar22 = uVar28;
      goto LAB_0009c940;
    case 0xfffffffa:
      uVar28 = 0;
      uVar22 = uVar28;
      goto LAB_0009c936;
    case 0xfffffffb:
      uVar28 = 0;
      uVar22 = uVar28;
      goto LAB_0009c92c;
    case 0xfffffffc:
      uVar28 = 0;
      goto LAB_0009c924;
    case 0xfffffffd:
      uVar28 = 0;
      goto LAB_0009c91c;
    case 0xfffffffe:
      uVar28 = 0;
      break;
    case 0xffffffff:
      pbVar24 = puVar26 + -1;
      puVar26 = puVar26 + -1;
      uVar28 = (uint)*pbVar24 << 0x10;
    }
    pbVar24 = puVar26 + -1;
    puVar26 = puVar26 + -1;
    uVar28 = uVar28 | (uint)*pbVar24 << 8;
LAB_0009c91c:
    pbVar24 = puVar26 + -1;
    puVar26 = puVar26 + -1;
    uVar28 = uVar28 | *pbVar24;
LAB_0009c924:
    pbVar24 = puVar26 + -1;
    puVar26 = puVar26 + -1;
    uVar22 = (uint)*pbVar24 << 0x18;
LAB_0009c92c:
    pbVar24 = puVar26 + -1;
    puVar26 = puVar26 + -1;
    uVar22 = uVar22 | (uint)*pbVar24 << 0x10;
LAB_0009c936:
    pbVar24 = puVar26 + -1;
    puVar26 = puVar26 + -1;
    uVar22 = uVar22 | (uint)*pbVar24 << 8;
LAB_0009c940:
    uVar22 = puVar26[-1] | uVar22;
LAB_0009c946:
    local_30 = local_30 ^ uVar22;
    local_2c = local_2c ^ uVar28;
    DES_encrypt1_constprop_2(&local_30,schedule);
    uVar32 = (uchar)local_30;
    *local_4c = uVar32;
    uVar19 = (uchar)(local_30 >> 0x18);
    local_4c[3] = uVar19;
    uVar27 = (uchar)(local_30 >> 8);
    local_4c[1] = uVar27;
    uVar25 = (uchar)(local_30 >> 0x10);
    local_4c[2] = uVar25;
    uVar23 = (uchar)local_2c;
    local_4c[4] = uVar23;
    uVar21 = (uchar)(local_2c >> 0x18);
    local_4c[7] = uVar21;
    uVar16 = (uchar)(local_2c >> 8);
    local_4c[5] = uVar16;
    uVar17 = (uchar)(local_2c >> 0x10);
    local_4c[6] = uVar17;
LAB_0009c8f6:
    (*ivec)[0] = uVar32;
    (*ivec)[1] = uVar27;
    (*ivec)[2] = uVar25;
    (*ivec)[3] = uVar19;
    (*ivec)[4] = uVar23;
    (*ivec)[5] = uVar16;
    (*ivec)[6] = uVar17;
    (*ivec)[7] = uVar21;
    return;
  }
  uVar31 = length - 8;
  uVar28 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
           (uint)(*ivec)[3] << 0x18;
  uVar22 = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
           (uint)(*ivec)[7] << 0x18;
  if (-1 < (int)uVar31) {
    pbVar24 = input;
    puVar26 = output;
    uVar29 = uVar31;
    uVar20 = uVar22;
    uVar30 = uVar28;
    do {
      pbVar1 = pbVar24 + 2;
      pbVar4 = pbVar24 + 1;
      pbVar2 = pbVar24 + 6;
      pbVar5 = pbVar24 + 5;
      pbVar3 = pbVar24 + 4;
      bVar8 = *pbVar24;
      pbVar6 = pbVar24 + 3;
      pbVar7 = pbVar24 + 7;
      pbVar24 = pbVar24 + 8;
      uVar28 = (uint)*pbVar1 << 0x10 | (uint)*pbVar4 << 8 | (uint)bVar8 | (uint)*pbVar6 << 0x18;
      uVar22 = (uint)*pbVar2 << 0x10 | (uint)*pbVar5 << 8 | (uint)*pbVar3 | (uint)*pbVar7 << 0x18;
      local_30 = uVar28;
      local_2c = uVar22;
      DES_encrypt1_constprop_3(&local_30,schedule);
      uVar29 = uVar29 - 8;
      uVar30 = uVar30 ^ local_30;
      uVar20 = uVar20 ^ local_2c;
      *puVar26 = (uchar)uVar30;
      puVar26[4] = (uchar)uVar20;
      puVar26[1] = (uchar)(uVar30 >> 8);
      puVar26[2] = (uchar)(uVar30 >> 0x10);
      puVar26[3] = (uchar)(uVar30 >> 0x18);
      puVar26[5] = (uchar)(uVar20 >> 8);
      puVar26[6] = (uchar)(uVar20 >> 0x10);
      puVar26[7] = (uchar)(uVar20 >> 0x18);
      puVar26 = puVar26 + 8;
      uVar20 = uVar22;
      uVar30 = uVar28;
    } while (-1 < (int)uVar29);
    iVar18 = ((uVar31 >> 3) + 1) * 8;
    uVar31 = (length + -0x10) - (uVar31 & 0xfffffff8);
    local_44 = input + iVar18;
    local_4c = output + iVar18;
  }
  bVar8 = local_44[2];
  bVar9 = local_44[6];
  bVar10 = local_44[1];
  bVar11 = local_44[5];
  bVar12 = local_44[3];
  bVar13 = *local_44;
  bVar14 = local_44[4];
  bVar15 = local_44[7];
  local_30 = (uint)bVar8 << 0x10 | (uint)bVar10 << 8 | (uint)bVar13 | (uint)bVar12 << 0x18;
  local_2c = (uint)bVar9 << 0x10 | (uint)bVar11 << 8 | (uint)bVar14 | (uint)bVar15 << 0x18;
  DES_encrypt1_constprop_3(&local_30,schedule);
  uVar22 = uVar22 ^ local_2c;
  local_4c = local_4c + uVar31 + 8;
  uVar28 = uVar28 ^ local_30;
  puVar26 = local_4c;
  switch(uVar31) {
  default:
    goto switchD_0009c870_caseD_7;
  case 0xfffffff9:
    goto LAB_0009c8aa;
  case 0xfffffffa:
    goto switchD_0009c870_caseD_fffffffa;
  case 0xfffffffb:
    goto LAB_0009c89a;
  case 0xfffffffc:
    goto switchD_0009c870_caseD_fffffffc;
  case 0xfffffffd:
    break;
  case 0xffffffff:
    local_4c[-1] = (uchar)(uVar22 >> 0x10);
    puVar26 = local_4c + -1;
  case 0xfffffffe:
    local_4c = puVar26 + -1;
    puVar26[-1] = (uchar)(uVar22 >> 8);
  }
  puVar26 = local_4c + -1;
  local_4c[-1] = (uchar)uVar22;
switchD_0009c870_caseD_fffffffc:
  local_4c = puVar26 + -1;
  puVar26[-1] = (uchar)(uVar28 >> 0x18);
LAB_0009c89a:
  puVar26 = local_4c + -1;
  local_4c[-1] = (uchar)(uVar28 >> 0x10);
switchD_0009c870_caseD_fffffffa:
  local_4c = puVar26 + -1;
  puVar26[-1] = (uchar)(uVar28 >> 8);
LAB_0009c8aa:
  local_4c[-1] = (uchar)uVar28;
switchD_0009c870_caseD_7:
  (*ivec)[0] = bVar13;
  (*ivec)[4] = bVar14;
  (*ivec)[1] = bVar10;
  (*ivec)[2] = bVar8;
  (*ivec)[3] = bVar12;
  (*ivec)[5] = bVar11;
  (*ivec)[6] = bVar9;
  (*ivec)[7] = bVar15;
  return;
}

