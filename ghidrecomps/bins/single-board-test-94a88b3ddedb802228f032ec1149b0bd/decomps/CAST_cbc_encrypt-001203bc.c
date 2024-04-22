
void CAST_cbc_encrypt(uchar *in,uchar *out,long length,CAST_KEY *ks,uchar *iv,int enc)

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
  
  local_4c = out;
  local_44 = in;
  if (enc != 0) {
    uVar22 = length - 8;
    local_30 = (uint)iv[1] << 0x10 | (uint)*iv << 0x18 | (uint)iv[3] | (uint)iv[2] << 8;
    local_2c = (uint)iv[5] << 0x10 | (uint)iv[4] << 0x18 | (uint)iv[7] | (uint)iv[6] << 8;
    if (-1 < (int)uVar22) {
      pbVar24 = in;
      puVar26 = out;
      uVar28 = uVar22;
      do {
        pbVar7 = pbVar24 + 1;
        bVar8 = *pbVar24;
        pbVar1 = pbVar24 + 5;
        pbVar2 = pbVar24 + 4;
        pbVar3 = pbVar24 + 7;
        pbVar4 = pbVar24 + 3;
        pbVar5 = pbVar24 + 6;
        pbVar6 = pbVar24 + 2;
        pbVar24 = pbVar24 + 8;
        local_2c = local_2c ^
                   ((uint)*pbVar1 << 0x10 | (uint)*pbVar2 << 0x18 | (uint)*pbVar3 |
                   (uint)*pbVar5 << 8);
        local_30 = local_30 ^
                   ((uint)*pbVar7 << 0x10 | (uint)bVar8 << 0x18 | (uint)*pbVar4 | (uint)*pbVar6 << 8
                   );
        CAST_encrypt(&local_30,ks);
        uVar28 = uVar28 - 8;
        puVar26[3] = (uchar)local_30;
        *puVar26 = (uchar)(local_30 >> 0x18);
        puVar26[1] = (uchar)(local_30 >> 0x10);
        puVar26[2] = (uchar)(local_30 >> 8);
        puVar26[7] = (uchar)local_2c;
        puVar26[4] = (uchar)(local_2c >> 0x18);
        puVar26[5] = (uchar)(local_2c >> 0x10);
        puVar26[6] = (uchar)(local_2c >> 8);
        puVar26 = puVar26 + 8;
      } while (-1 < (int)uVar28);
      uVar28 = uVar22 >> 3;
      uVar22 = (length + -0x10) - (uVar22 & 0xfffffff8);
      iVar18 = (uVar28 + 1) * 8;
      local_44 = in + iVar18;
      local_4c = out + iVar18;
    }
    if (uVar22 == 0xfffffff8) {
      uVar32 = (uchar)(local_30 >> 0x18);
      uVar27 = (uchar)(local_30 >> 0x10);
      uVar25 = (uchar)(local_30 >> 8);
      uVar23 = (uchar)(local_2c >> 0x18);
      uVar16 = (uchar)(local_2c >> 0x10);
      uVar19 = (uchar)local_30;
      uVar17 = (uchar)(local_2c >> 8);
      uVar21 = (uchar)local_2c;
      goto LAB_0012070c;
    }
    puVar26 = local_44 + uVar22 + 8;
    switch(uVar22) {
    default:
      uVar28 = 0;
      uVar22 = uVar28;
      goto LAB_0012075e;
    case 0xfffffff9:
      uVar28 = 0;
      uVar22 = uVar28;
      goto LAB_00120756;
    case 0xfffffffa:
      uVar28 = 0;
      uVar22 = uVar28;
      goto LAB_0012074c;
    case 0xfffffffb:
      uVar28 = 0;
      uVar22 = uVar28;
      goto LAB_00120742;
    case 0xfffffffc:
      uVar28 = 0;
      goto LAB_0012073c;
    case 0xfffffffd:
      uVar28 = 0;
      goto LAB_00120732;
    case 0xfffffffe:
      uVar28 = 0;
      break;
    case 0xffffffff:
      pbVar24 = puVar26 + -1;
      puVar26 = puVar26 + -1;
      uVar28 = (uint)*pbVar24 << 8;
    }
    pbVar24 = puVar26 + -1;
    puVar26 = puVar26 + -1;
    uVar28 = uVar28 | (uint)*pbVar24 << 0x10;
LAB_00120732:
    pbVar24 = puVar26 + -1;
    puVar26 = puVar26 + -1;
    uVar28 = uVar28 | (uint)*pbVar24 << 0x18;
LAB_0012073c:
    pbVar24 = puVar26 + -1;
    puVar26 = puVar26 + -1;
    uVar22 = (uint)*pbVar24;
LAB_00120742:
    pbVar24 = puVar26 + -1;
    puVar26 = puVar26 + -1;
    uVar22 = uVar22 | (uint)*pbVar24 << 8;
LAB_0012074c:
    pbVar24 = puVar26 + -1;
    puVar26 = puVar26 + -1;
    uVar22 = uVar22 | (uint)*pbVar24 << 0x10;
LAB_00120756:
    uVar22 = uVar22 | (uint)puVar26[-1] << 0x18;
LAB_0012075e:
    local_30 = local_30 ^ uVar22;
    local_2c = local_2c ^ uVar28;
    CAST_encrypt(&local_30,ks);
    uVar32 = (uchar)(local_30 >> 0x18);
    *local_4c = uVar32;
    uVar19 = (uchar)local_30;
    local_4c[3] = uVar19;
    uVar27 = (uchar)(local_30 >> 0x10);
    local_4c[1] = uVar27;
    uVar25 = (uchar)(local_30 >> 8);
    local_4c[2] = uVar25;
    uVar23 = (uchar)(local_2c >> 0x18);
    local_4c[4] = uVar23;
    uVar21 = (uchar)local_2c;
    local_4c[7] = uVar21;
    uVar16 = (uchar)(local_2c >> 0x10);
    local_4c[5] = uVar16;
    uVar17 = (uchar)(local_2c >> 8);
    local_4c[6] = uVar17;
LAB_0012070c:
    *iv = uVar32;
    iv[1] = uVar27;
    iv[2] = uVar25;
    iv[3] = uVar19;
    iv[4] = uVar23;
    iv[5] = uVar16;
    iv[6] = uVar17;
    iv[7] = uVar21;
    return;
  }
  uVar31 = length - 8;
  uVar28 = (uint)iv[1] << 0x10 | (uint)*iv << 0x18 | (uint)iv[3] | (uint)iv[2] << 8;
  uVar22 = (uint)iv[5] << 0x10 | (uint)iv[4] << 0x18 | (uint)iv[7] | (uint)iv[6] << 8;
  if (-1 < (int)uVar31) {
    pbVar24 = in;
    puVar26 = out;
    uVar29 = uVar31;
    uVar30 = uVar28;
    uVar20 = uVar22;
    do {
      pbVar1 = pbVar24 + 1;
      bVar8 = *pbVar24;
      pbVar2 = pbVar24 + 5;
      pbVar4 = pbVar24 + 4;
      pbVar3 = pbVar24 + 7;
      pbVar5 = pbVar24 + 3;
      pbVar6 = pbVar24 + 2;
      pbVar7 = pbVar24 + 6;
      pbVar24 = pbVar24 + 8;
      uVar28 = (uint)*pbVar1 << 0x10 | (uint)bVar8 << 0x18 | (uint)*pbVar5 | (uint)*pbVar6 << 8;
      uVar22 = (uint)*pbVar2 << 0x10 | (uint)*pbVar4 << 0x18 | (uint)*pbVar3 | (uint)*pbVar7 << 8;
      local_30 = uVar28;
      local_2c = uVar22;
      CAST_decrypt(&local_30,ks);
      uVar29 = uVar29 - 8;
      uVar30 = uVar30 ^ local_30;
      uVar20 = uVar20 ^ local_2c;
      puVar26[3] = (uchar)uVar30;
      puVar26[7] = (uchar)uVar20;
      *puVar26 = (uchar)(uVar30 >> 0x18);
      puVar26[1] = (uchar)(uVar30 >> 0x10);
      puVar26[2] = (uchar)(uVar30 >> 8);
      puVar26[4] = (uchar)(uVar20 >> 0x18);
      puVar26[5] = (uchar)(uVar20 >> 0x10);
      puVar26[6] = (uchar)(uVar20 >> 8);
      puVar26 = puVar26 + 8;
      uVar30 = uVar28;
      uVar20 = uVar22;
    } while (-1 < (int)uVar29);
    iVar18 = ((uVar31 >> 3) + 1) * 8;
    uVar31 = (length + -0x10) - (uVar31 & 0xfffffff8);
    local_44 = in + iVar18;
    local_4c = out + iVar18;
  }
  bVar8 = local_44[1];
  bVar9 = local_44[5];
  bVar10 = *local_44;
  bVar11 = local_44[4];
  bVar12 = local_44[2];
  bVar13 = local_44[3];
  bVar14 = local_44[7];
  bVar15 = local_44[6];
  local_30 = (uint)bVar8 << 0x10 | (uint)bVar10 << 0x18 | (uint)bVar13 | (uint)bVar12 << 8;
  local_2c = (uint)bVar9 << 0x10 | (uint)bVar11 << 0x18 | (uint)bVar14 | (uint)bVar15 << 8;
  CAST_decrypt(&local_30,ks);
  uVar22 = uVar22 ^ local_2c;
  local_4c = local_4c + uVar31 + 8;
  uVar28 = uVar28 ^ local_30;
  puVar26 = local_4c;
  switch(uVar31) {
  default:
    goto switchD_00120684_caseD_7;
  case 0xfffffff9:
    goto LAB_001206be;
  case 0xfffffffa:
    goto switchD_00120684_caseD_fffffffa;
  case 0xfffffffb:
    goto LAB_001206ae;
  case 0xfffffffc:
    goto switchD_00120684_caseD_fffffffc;
  case 0xfffffffd:
    break;
  case 0xffffffff:
    local_4c[-1] = (uchar)(uVar22 >> 8);
    puVar26 = local_4c + -1;
  case 0xfffffffe:
    local_4c = puVar26 + -1;
    puVar26[-1] = (uchar)(uVar22 >> 0x10);
  }
  puVar26 = local_4c + -1;
  local_4c[-1] = (uchar)(uVar22 >> 0x18);
switchD_00120684_caseD_fffffffc:
  local_4c = puVar26 + -1;
  puVar26[-1] = (uchar)uVar28;
LAB_001206ae:
  puVar26 = local_4c + -1;
  local_4c[-1] = (uchar)(uVar28 >> 8);
switchD_00120684_caseD_fffffffa:
  local_4c = puVar26 + -1;
  puVar26[-1] = (uchar)(uVar28 >> 0x10);
LAB_001206be:
  local_4c[-1] = (uchar)(uVar28 >> 0x18);
switchD_00120684_caseD_7:
  iv[3] = bVar13;
  iv[7] = bVar14;
  *iv = bVar10;
  iv[1] = bVar8;
  iv[2] = bVar12;
  iv[4] = bVar11;
  iv[5] = bVar9;
  iv[6] = bVar15;
  return;
}

