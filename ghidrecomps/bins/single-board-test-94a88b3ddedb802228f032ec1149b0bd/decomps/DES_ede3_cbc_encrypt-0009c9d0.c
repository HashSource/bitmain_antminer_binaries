
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
  uchar uVar9;
  uchar uVar10;
  uchar uVar11;
  uint uVar12;
  uchar uVar13;
  uint uVar14;
  uchar uVar15;
  byte *pbVar16;
  uchar *puVar17;
  int iVar18;
  uchar *puVar19;
  uchar uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uchar uVar24;
  uint uVar25;
  uchar uVar26;
  uint local_30;
  uint local_2c;
  
  if (enc == 0) {
    uVar22 = length - 8;
    uVar25 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
             (uint)(*ivec)[3] << 0x18;
    uVar21 = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
             (uint)(*ivec)[7] << 0x18;
    if (-1 < (int)uVar22) {
      pbVar16 = input;
      puVar17 = output;
      uVar23 = uVar22;
      uVar14 = uVar21;
      uVar12 = uVar25;
      do {
        pbVar1 = pbVar16 + 2;
        pbVar5 = pbVar16 + 1;
        pbVar6 = pbVar16 + 6;
        pbVar2 = pbVar16 + 5;
        bVar8 = *pbVar16;
        pbVar7 = pbVar16 + 3;
        pbVar3 = pbVar16 + 4;
        pbVar4 = pbVar16 + 7;
        pbVar16 = pbVar16 + 8;
        uVar25 = (uint)*pbVar1 << 0x10 | (uint)*pbVar5 << 8 | (uint)bVar8 | (uint)*pbVar7 << 0x18;
        uVar21 = (uint)*pbVar6 << 0x10 | (uint)*pbVar2 << 8 | (uint)*pbVar3 | (uint)*pbVar4 << 0x18;
        local_30 = uVar25;
        local_2c = uVar21;
        DES_decrypt3(&local_30,ks1,ks2,ks3);
        uVar23 = uVar23 - 8;
        uVar12 = uVar12 ^ local_30;
        uVar14 = uVar14 ^ local_2c;
        *puVar17 = (uchar)uVar12;
        puVar17[4] = (uchar)uVar14;
        puVar17[1] = (uchar)(uVar12 >> 8);
        puVar17[2] = (uchar)(uVar12 >> 0x10);
        puVar17[3] = (uchar)(uVar12 >> 0x18);
        puVar17[5] = (uchar)(uVar14 >> 8);
        puVar17[6] = (uchar)(uVar14 >> 0x10);
        puVar17[7] = (uchar)(uVar14 >> 0x18);
        puVar17 = puVar17 + 8;
        uVar14 = uVar21;
        uVar12 = uVar25;
      } while (-1 < (int)uVar23);
      iVar18 = ((uVar22 >> 3) + 1) * 8;
      uVar22 = length + -0x10 + (uVar22 >> 3) * -8;
      input = input + iVar18;
      output = output + iVar18;
    }
    uVar23 = uVar21;
    uVar14 = uVar25;
    if (uVar22 == 0xfffffff8) goto switchD_0009cca4_default;
    uVar23 = (uint)input[6] << 0x10 | (uint)input[5] << 8 | (uint)input[4] | (uint)input[7] << 0x18;
    uVar14 = (uint)input[2] << 0x10 | (uint)input[1] << 8 | (uint)*input | (uint)input[3] << 0x18;
    local_30 = uVar14;
    local_2c = uVar23;
    DES_decrypt3(&local_30,ks1,ks2,ks3);
    puVar19 = output + uVar22 + 8;
    uVar25 = uVar25 ^ local_30;
    uVar21 = uVar21 ^ local_2c;
    puVar17 = puVar19;
    switch(uVar22) {
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
      puVar19[-1] = (uchar)(uVar21 >> 0x10);
      puVar17 = puVar19 + -1;
    case 0xfffffffe:
      puVar19 = puVar17 + -1;
      puVar17[-1] = (uchar)(uVar21 >> 8);
      break;
    default:
      goto switchD_0009cca4_default;
    }
    puVar17 = puVar19 + -1;
    puVar19[-1] = (uchar)uVar21;
switchD_0009cca4_caseD_fffffffc:
    puVar19 = puVar17 + -1;
    puVar17[-1] = (uchar)(uVar25 >> 0x18);
LAB_0009ccd0:
    puVar17 = puVar19 + -1;
    puVar19[-1] = (uchar)(uVar25 >> 0x10);
switchD_0009cca4_caseD_fffffffa:
    puVar19 = puVar17 + -1;
    puVar17[-1] = (uchar)(uVar25 >> 8);
LAB_0009cce4:
    puVar19[-1] = (uchar)uVar25;
switchD_0009cca4_default:
    (*ivec)[0] = (uchar)uVar14;
    (*ivec)[4] = (uchar)uVar23;
    (*ivec)[1] = (uchar)(uVar14 >> 8);
    (*ivec)[2] = (uchar)(uVar14 >> 0x10);
    (*ivec)[3] = (uchar)(uVar14 >> 0x18);
    (*ivec)[5] = (uchar)(uVar23 >> 8);
    (*ivec)[6] = (uchar)(uVar23 >> 0x10);
    (*ivec)[7] = (uchar)(uVar23 >> 0x18);
    return;
  }
  uVar21 = length - 8;
  local_30 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
             (uint)(*ivec)[3] << 0x18;
  local_2c = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
             (uint)(*ivec)[7] << 0x18;
  if (-1 < (int)uVar21) {
    pbVar16 = input;
    puVar17 = output;
    uVar22 = uVar21;
    do {
      pbVar5 = pbVar16 + 2;
      pbVar6 = pbVar16 + 1;
      pbVar1 = pbVar16 + 6;
      pbVar2 = pbVar16 + 5;
      pbVar3 = pbVar16 + 3;
      bVar8 = *pbVar16;
      pbVar7 = pbVar16 + 7;
      pbVar4 = pbVar16 + 4;
      pbVar16 = pbVar16 + 8;
      local_30 = ((uint)*pbVar5 << 0x10 | (uint)*pbVar6 << 8 | (uint)bVar8 | (uint)*pbVar3 << 0x18)
                 ^ local_30;
      local_2c = local_2c ^
                 ((uint)*pbVar1 << 0x10 | (uint)*pbVar2 << 8 | (uint)*pbVar4 | (uint)*pbVar7 << 0x18
                 );
      DES_encrypt3(&local_30,ks1,ks2,ks3);
      uVar22 = uVar22 - 8;
      *puVar17 = (uchar)local_30;
      puVar17[1] = (uchar)(local_30 >> 8);
      puVar17[2] = (uchar)(local_30 >> 0x10);
      puVar17[3] = (uchar)(local_30 >> 0x18);
      puVar17[4] = (uchar)local_2c;
      puVar17[5] = (uchar)(local_2c >> 8);
      puVar17[6] = (uchar)(local_2c >> 0x10);
      puVar17[7] = (uchar)(local_2c >> 0x18);
      puVar17 = puVar17 + 8;
    } while (-1 < (int)uVar22);
    iVar18 = ((uVar21 >> 3) + 1) * 8;
    uVar21 = length + -0x10 + (uVar21 >> 3) * -8;
    input = input + iVar18;
    output = output + iVar18;
  }
  if (uVar21 == 0xfffffff8) {
    uVar26 = (uchar)local_30;
    uVar24 = (uchar)(local_30 >> 8);
    uVar20 = (uchar)(local_30 >> 0x10);
    uVar15 = (uchar)local_2c;
    uVar9 = (uchar)(local_2c >> 8);
    uVar11 = (uchar)(local_30 >> 0x18);
    uVar10 = (uchar)(local_2c >> 0x10);
    uVar13 = (uchar)(local_2c >> 0x18);
    goto LAB_0009cd44;
  }
  puVar17 = input + uVar21 + 8;
  switch(uVar21) {
  case 0xfffffff9:
    uVar22 = 0;
    uVar21 = uVar22;
    goto LAB_0009cd9c;
  case 0xfffffffa:
    uVar22 = 0;
    uVar21 = uVar22;
    goto LAB_0009cd92;
  case 0xfffffffb:
    uVar22 = 0;
    uVar21 = uVar22;
    goto LAB_0009cd88;
  case 0xfffffffc:
    uVar21 = 0;
    goto LAB_0009cd80;
  case 0xfffffffd:
    uVar21 = 0;
    goto LAB_0009cd78;
  case 0xfffffffe:
    uVar21 = 0;
    break;
  case 0xffffffff:
    pbVar16 = puVar17 + -1;
    puVar17 = puVar17 + -1;
    uVar21 = (uint)*pbVar16 << 0x10;
    break;
  default:
    uVar21 = 0;
    uVar22 = uVar21;
    goto LAB_0009cda2;
  }
  pbVar16 = puVar17 + -1;
  puVar17 = puVar17 + -1;
  uVar21 = uVar21 | (uint)*pbVar16 << 8;
LAB_0009cd78:
  pbVar16 = puVar17 + -1;
  puVar17 = puVar17 + -1;
  uVar21 = uVar21 | *pbVar16;
LAB_0009cd80:
  pbVar16 = puVar17 + -1;
  puVar17 = puVar17 + -1;
  uVar22 = (uint)*pbVar16 << 0x18;
LAB_0009cd88:
  pbVar16 = puVar17 + -1;
  puVar17 = puVar17 + -1;
  uVar22 = uVar22 | (uint)*pbVar16 << 0x10;
LAB_0009cd92:
  pbVar16 = puVar17 + -1;
  puVar17 = puVar17 + -1;
  uVar22 = uVar22 | (uint)*pbVar16 << 8;
LAB_0009cd9c:
  uVar22 = puVar17[-1] | uVar22;
LAB_0009cda2:
  local_2c = uVar21 ^ local_2c;
  local_30 = uVar22 ^ local_30;
  DES_encrypt3(&local_30,ks1,ks2,ks3);
  uVar26 = (uchar)local_30;
  *output = uVar26;
  uVar11 = (uchar)(local_30 >> 0x18);
  output[3] = uVar11;
  uVar24 = (uchar)(local_30 >> 8);
  output[1] = uVar24;
  uVar20 = (uchar)(local_30 >> 0x10);
  output[2] = uVar20;
  uVar15 = (uchar)local_2c;
  output[4] = uVar15;
  uVar13 = (uchar)(local_2c >> 0x18);
  output[7] = uVar13;
  uVar9 = (uchar)(local_2c >> 8);
  output[5] = uVar9;
  uVar10 = (uchar)(local_2c >> 0x10);
  output[6] = uVar10;
LAB_0009cd44:
  (*ivec)[0] = uVar26;
  (*ivec)[1] = uVar24;
  (*ivec)[2] = uVar20;
  (*ivec)[3] = uVar11;
  (*ivec)[4] = uVar15;
  (*ivec)[5] = uVar9;
  (*ivec)[6] = uVar10;
  (*ivec)[7] = uVar13;
  return;
}

