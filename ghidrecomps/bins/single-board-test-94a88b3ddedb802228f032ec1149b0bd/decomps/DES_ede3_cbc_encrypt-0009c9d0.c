
void DES_ede3_cbc_encrypt
               (uchar *input,uchar *output,long length,DES_key_schedule *ks1,DES_key_schedule *ks2,
               DES_key_schedule *ks3,DES_cblock *ivec,int enc)

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
  uchar uVar18;
  uint uVar19;
  uchar uVar20;
  uint uVar21;
  uchar uVar22;
  byte *pbVar23;
  uchar *puVar24;
  int iVar25;
  uchar *puVar26;
  uchar uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uchar uVar31;
  uint uVar32;
  uchar uVar33;
  uint local_30;
  uint local_2c;
  
  if (enc != 0) {
    uVar28 = length - 8;
    local_30 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
               (uint)(*ivec)[3] << 0x18;
    local_2c = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
               (uint)(*ivec)[7] << 0x18;
    if (-1 < (int)uVar28) {
      pbVar23 = input;
      puVar24 = output;
      uVar29 = uVar28;
      do {
        pbVar5 = pbVar23 + 2;
        pbVar6 = pbVar23 + 1;
        pbVar1 = pbVar23 + 6;
        pbVar2 = pbVar23 + 5;
        pbVar3 = pbVar23 + 3;
        bVar8 = *pbVar23;
        pbVar7 = pbVar23 + 7;
        pbVar4 = pbVar23 + 4;
        pbVar23 = pbVar23 + 8;
        local_30 = ((uint)*pbVar5 << 0x10 | (uint)*pbVar6 << 8 | (uint)bVar8 | (uint)*pbVar3 << 0x18
                   ) ^ local_30;
        local_2c = local_2c ^
                   ((uint)*pbVar1 << 0x10 | (uint)*pbVar2 << 8 | (uint)*pbVar4 |
                   (uint)*pbVar7 << 0x18);
        DES_encrypt3(&local_30,ks1,ks2,ks3);
        uVar29 = uVar29 - 8;
        *puVar24 = (uchar)local_30;
        puVar24[1] = (uchar)(local_30 >> 8);
        puVar24[2] = (uchar)(local_30 >> 0x10);
        puVar24[3] = (uchar)(local_30 >> 0x18);
        puVar24[4] = (uchar)local_2c;
        puVar24[5] = (uchar)(local_2c >> 8);
        puVar24[6] = (uchar)(local_2c >> 0x10);
        puVar24[7] = (uchar)(local_2c >> 0x18);
        puVar24 = puVar24 + 8;
      } while (-1 < (int)uVar29);
      iVar25 = ((uVar28 >> 3) + 1) * 8;
      uVar28 = (length + -0x10) - (uVar28 & 0xfffffff8);
      input = input + iVar25;
      output = output + iVar25;
    }
    if (uVar28 == 0xfffffff8) {
      uVar33 = (uchar)local_30;
      uVar31 = (uchar)(local_30 >> 8);
      uVar27 = (uchar)(local_30 >> 0x10);
      uVar22 = (uchar)local_2c;
      uVar16 = (uchar)(local_2c >> 8);
      uVar18 = (uchar)(local_30 >> 0x18);
      uVar17 = (uchar)(local_2c >> 0x10);
      uVar20 = (uchar)(local_2c >> 0x18);
      goto LAB_0009cd44;
    }
    puVar24 = input + uVar28 + 8;
    switch(uVar28) {
    default:
      uVar28 = 0;
      uVar29 = uVar28;
      goto LAB_0009cda2;
    case 0xfffffff9:
      uVar29 = 0;
      uVar28 = uVar29;
      goto LAB_0009cd9c;
    case 0xfffffffa:
      uVar29 = 0;
      uVar28 = uVar29;
      goto LAB_0009cd92;
    case 0xfffffffb:
      uVar29 = 0;
      uVar28 = uVar29;
      goto LAB_0009cd88;
    case 0xfffffffc:
      uVar28 = 0;
      goto LAB_0009cd80;
    case 0xfffffffd:
      uVar28 = 0;
      goto LAB_0009cd78;
    case 0xfffffffe:
      uVar28 = 0;
      break;
    case 0xffffffff:
      pbVar23 = puVar24 + -1;
      puVar24 = puVar24 + -1;
      uVar28 = (uint)*pbVar23 << 0x10;
    }
    pbVar23 = puVar24 + -1;
    puVar24 = puVar24 + -1;
    uVar28 = uVar28 | (uint)*pbVar23 << 8;
LAB_0009cd78:
    pbVar23 = puVar24 + -1;
    puVar24 = puVar24 + -1;
    uVar28 = uVar28 | *pbVar23;
LAB_0009cd80:
    pbVar23 = puVar24 + -1;
    puVar24 = puVar24 + -1;
    uVar29 = (uint)*pbVar23 << 0x18;
LAB_0009cd88:
    pbVar23 = puVar24 + -1;
    puVar24 = puVar24 + -1;
    uVar29 = uVar29 | (uint)*pbVar23 << 0x10;
LAB_0009cd92:
    pbVar23 = puVar24 + -1;
    puVar24 = puVar24 + -1;
    uVar29 = uVar29 | (uint)*pbVar23 << 8;
LAB_0009cd9c:
    uVar29 = puVar24[-1] | uVar29;
LAB_0009cda2:
    local_2c = uVar28 ^ local_2c;
    local_30 = uVar29 ^ local_30;
    DES_encrypt3(&local_30,ks1,ks2,ks3);
    uVar33 = (uchar)local_30;
    *output = uVar33;
    uVar18 = (uchar)(local_30 >> 0x18);
    output[3] = uVar18;
    uVar31 = (uchar)(local_30 >> 8);
    output[1] = uVar31;
    uVar27 = (uchar)(local_30 >> 0x10);
    output[2] = uVar27;
    uVar22 = (uchar)local_2c;
    output[4] = uVar22;
    uVar20 = (uchar)(local_2c >> 0x18);
    output[7] = uVar20;
    uVar16 = (uchar)(local_2c >> 8);
    output[5] = uVar16;
    uVar17 = (uchar)(local_2c >> 0x10);
    output[6] = uVar17;
LAB_0009cd44:
    (*ivec)[0] = uVar33;
    (*ivec)[1] = uVar31;
    (*ivec)[2] = uVar27;
    (*ivec)[3] = uVar18;
    (*ivec)[4] = uVar22;
    (*ivec)[5] = uVar16;
    (*ivec)[6] = uVar17;
    (*ivec)[7] = uVar20;
    return;
  }
  uVar29 = length - 8;
  uVar32 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
           (uint)(*ivec)[3] << 0x18;
  uVar28 = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
           (uint)(*ivec)[7] << 0x18;
  if (-1 < (int)uVar29) {
    pbVar23 = input;
    puVar24 = output;
    uVar30 = uVar29;
    uVar21 = uVar28;
    uVar19 = uVar32;
    do {
      pbVar1 = pbVar23 + 2;
      pbVar5 = pbVar23 + 1;
      pbVar6 = pbVar23 + 6;
      pbVar2 = pbVar23 + 5;
      bVar8 = *pbVar23;
      pbVar7 = pbVar23 + 3;
      pbVar3 = pbVar23 + 4;
      pbVar4 = pbVar23 + 7;
      pbVar23 = pbVar23 + 8;
      uVar32 = (uint)*pbVar1 << 0x10 | (uint)*pbVar5 << 8 | (uint)bVar8 | (uint)*pbVar7 << 0x18;
      uVar28 = (uint)*pbVar6 << 0x10 | (uint)*pbVar2 << 8 | (uint)*pbVar3 | (uint)*pbVar4 << 0x18;
      local_30 = uVar32;
      local_2c = uVar28;
      DES_decrypt3(&local_30,ks1,ks2,ks3);
      uVar30 = uVar30 - 8;
      uVar19 = uVar19 ^ local_30;
      uVar21 = uVar21 ^ local_2c;
      *puVar24 = (uchar)uVar19;
      puVar24[4] = (uchar)uVar21;
      puVar24[1] = (uchar)(uVar19 >> 8);
      puVar24[2] = (uchar)(uVar19 >> 0x10);
      puVar24[3] = (uchar)(uVar19 >> 0x18);
      puVar24[5] = (uchar)(uVar21 >> 8);
      puVar24[6] = (uchar)(uVar21 >> 0x10);
      puVar24[7] = (uchar)(uVar21 >> 0x18);
      puVar24 = puVar24 + 8;
      uVar21 = uVar28;
      uVar19 = uVar32;
    } while (-1 < (int)uVar30);
    iVar25 = ((uVar29 >> 3) + 1) * 8;
    uVar29 = (length + -0x10) - (uVar29 & 0xfffffff8);
    input = input + iVar25;
    output = output + iVar25;
  }
  bVar8 = input[5];
  bVar11 = input[2];
  bVar12 = input[1];
  bVar9 = *input;
  bVar13 = input[6];
  bVar14 = input[3];
  bVar15 = input[4];
  bVar10 = input[7];
  local_2c = (uint)bVar13 << 0x10 | (uint)bVar8 << 8 | (uint)bVar15 | (uint)bVar10 << 0x18;
  local_30 = (uint)bVar11 << 0x10 | (uint)bVar12 << 8 | (uint)bVar9 | (uint)bVar14 << 0x18;
  DES_decrypt3(&local_30,ks1,ks2,ks3);
  puVar26 = output + uVar29 + 8;
  uVar32 = uVar32 ^ local_30;
  uVar28 = uVar28 ^ local_2c;
  puVar24 = puVar26;
  switch(uVar29) {
  default:
    goto switchD_0009cca4_caseD_7;
  case 0xfffffff9:
    goto LAB_0009cce4;
  case 0xfffffffa:
    goto switchD_0009cca4_caseD_fffffffa;
  case 0xfffffffb:
    goto LAB_0009ccd0;
  case 0xfffffffc:
    goto switchD_0009cca4_caseD_fffffffc;
  case 0xfffffffd:
    break;
  case 0xffffffff:
    puVar26[-1] = (uchar)(uVar28 >> 0x10);
    puVar24 = puVar26 + -1;
  case 0xfffffffe:
    puVar26 = puVar24 + -1;
    puVar24[-1] = (uchar)(uVar28 >> 8);
  }
  puVar24 = puVar26 + -1;
  puVar26[-1] = (uchar)uVar28;
switchD_0009cca4_caseD_fffffffc:
  puVar26 = puVar24 + -1;
  puVar24[-1] = (uchar)(uVar32 >> 0x18);
LAB_0009ccd0:
  puVar24 = puVar26 + -1;
  puVar26[-1] = (uchar)(uVar32 >> 0x10);
switchD_0009cca4_caseD_fffffffa:
  puVar26 = puVar24 + -1;
  puVar24[-1] = (uchar)(uVar32 >> 8);
LAB_0009cce4:
  puVar26[-1] = (uchar)uVar32;
switchD_0009cca4_caseD_7:
  (*ivec)[0] = bVar9;
  (*ivec)[4] = bVar15;
  (*ivec)[1] = bVar12;
  (*ivec)[2] = bVar11;
  (*ivec)[3] = bVar14;
  (*ivec)[5] = bVar8;
  (*ivec)[6] = bVar13;
  (*ivec)[7] = bVar10;
  return;
}

