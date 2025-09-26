
void RC2_cbc_encrypt(uchar *in,uchar *out,long length,RC2_KEY *ks,uchar *iv,int enc)

{
  byte *pbVar1;
  uint *puVar2;
  uchar uVar3;
  uchar *puVar4;
  uchar uVar5;
  int iVar6;
  uchar uVar7;
  uint uVar8;
  uint uVar9;
  uchar uVar10;
  uchar uVar11;
  uint *puVar12;
  uint uVar13;
  uchar uVar14;
  uint uVar15;
  uchar uVar16;
  uint uVar17;
  uint uVar18;
  uchar uVar19;
  uchar *local_44;
  uint *local_3c;
  uint local_30;
  uint local_2c;
  
  local_44 = out;
  local_3c = (uint *)in;
  if (enc == 0) {
    uVar15 = length - 8;
    uVar8 = *(uint *)iv;
    uVar17 = *(uint *)(iv + 4);
    if (-1 < (int)uVar15) {
      puVar4 = out + 8;
      uVar13 = uVar17;
      puVar12 = (uint *)in;
      uVar18 = uVar15;
      uVar9 = uVar8;
      do {
        uVar8 = *puVar12;
        uVar17 = puVar12[1];
        puVar12 = puVar12 + 2;
        local_30 = uVar8;
        local_2c = uVar17;
        RC2_decrypt(&local_30,ks);
        uVar18 = uVar18 - 8;
        uVar9 = uVar9 ^ local_30;
        uVar13 = uVar13 ^ local_2c;
        puVar4[-8] = (uchar)uVar9;
        puVar4[-7] = (uchar)(uVar9 >> 8);
        puVar4[-4] = (uchar)uVar13;
        puVar4[-6] = (uchar)(uVar9 >> 0x10);
        puVar4[-5] = (uchar)(uVar9 >> 0x18);
        puVar4[-3] = (uchar)(uVar13 >> 8);
        puVar4[-2] = (uchar)(uVar13 >> 0x10);
        puVar4[-1] = (uchar)(uVar13 >> 0x18);
        puVar4 = puVar4 + 8;
        uVar13 = uVar17;
        uVar9 = uVar8;
      } while (-1 < (int)uVar18);
      uVar13 = uVar15 >> 3;
      uVar15 = length + -0x10 + uVar13 * -8;
      iVar6 = (uVar13 + 1) * 8;
      local_3c = (uint *)(in + iVar6);
      local_44 = out + iVar6;
    }
    uVar13 = uVar17;
    uVar18 = uVar8;
    if (uVar15 == 0xfffffff8) goto switchD_00156e12_default;
    uVar18 = *local_3c;
    uVar13 = local_3c[1];
    local_30 = uVar18;
    local_2c = uVar13;
    RC2_decrypt(&local_30,ks);
    local_44 = local_44 + uVar15 + 8;
    uVar8 = uVar8 ^ local_30;
    uVar17 = uVar17 ^ local_2c;
    puVar4 = local_44;
    switch(uVar15) {
    case 0xfffffff9:
      goto LAB_00156e4a;
    case 0xfffffffa:
      goto switchD_00156e12_caseD_fffffffa;
    case 0xfffffffb:
      goto LAB_00156e3a;
    case 0xfffffffc:
      goto switchD_00156e12_caseD_fffffffc;
    case 0xfffffffd:
      break;
    case 0xffffffff:
      puVar4 = local_44 + -1;
      *puVar4 = (uchar)(uVar17 >> 0x10);
    case 0xfffffffe:
      local_44 = puVar4 + -1;
      puVar4[-1] = (uchar)(uVar17 >> 8);
      break;
    default:
      goto switchD_00156e12_default;
    }
    puVar4 = local_44 + -1;
    local_44[-1] = (uchar)uVar17;
switchD_00156e12_caseD_fffffffc:
    local_44 = puVar4 + -1;
    puVar4[-1] = (uchar)(uVar8 >> 0x18);
LAB_00156e3a:
    puVar4 = local_44 + -1;
    local_44[-1] = (uchar)(uVar8 >> 0x10);
switchD_00156e12_caseD_fffffffa:
    local_44 = puVar4 + -1;
    puVar4[-1] = (uchar)(uVar8 >> 8);
LAB_00156e4a:
    local_44[-1] = (uchar)uVar8;
switchD_00156e12_default:
    *iv = (uchar)uVar18;
    iv[4] = (uchar)uVar13;
    iv[1] = (uchar)(uVar18 >> 8);
    iv[2] = (uchar)(uVar18 >> 0x10);
    iv[3] = (uchar)(uVar18 >> 0x18);
    iv[5] = (uchar)(uVar13 >> 8);
    iv[6] = (uchar)(uVar13 >> 0x10);
    iv[7] = (uchar)(uVar13 >> 0x18);
    return;
  }
  uVar8 = length - 8;
  local_2c = *(uint *)(iv + 4);
  local_30 = *(uint *)iv;
  if (-1 < (int)uVar8) {
    puVar4 = out + 8;
    puVar12 = (uint *)in;
    uVar17 = uVar8;
    do {
      uVar15 = *puVar12;
      puVar2 = puVar12 + 1;
      puVar12 = puVar12 + 2;
      local_30 = local_30 ^ uVar15;
      local_2c = local_2c ^ *puVar2;
      RC2_encrypt(&local_30,ks);
      uVar17 = uVar17 - 8;
      puVar4[-8] = (uchar)local_30;
      puVar4[-4] = (uchar)local_2c;
      puVar4[-7] = (uchar)(local_30 >> 8);
      puVar4[-6] = (uchar)(local_30 >> 0x10);
      puVar4[-5] = (uchar)(local_30 >> 0x18);
      puVar4[-3] = (uchar)(local_2c >> 8);
      puVar4[-2] = (uchar)(local_2c >> 0x10);
      puVar4[-1] = (uchar)(local_2c >> 0x18);
      puVar4 = puVar4 + 8;
    } while (-1 < (int)uVar17);
    uVar17 = uVar8 >> 3;
    uVar8 = length + -0x10 + uVar17 * -8;
    iVar6 = (uVar17 + 1) * 8;
    local_3c = (uint *)(in + iVar6);
    local_44 = out + iVar6;
  }
  if (uVar8 == 0xfffffff8) {
    uVar10 = (uchar)local_2c;
    uVar3 = (uchar)(local_2c >> 8);
    uVar5 = (uchar)(local_2c >> 0x10);
    uVar16 = (uchar)local_30;
    uVar19 = (uchar)(local_30 >> 0x18);
    uVar7 = (uchar)(local_2c >> 0x18);
    uVar14 = (uchar)(local_30 >> 8);
    uVar11 = (uchar)(local_30 >> 0x10);
    goto LAB_00156ea2;
  }
  puVar4 = (uchar *)((int)local_3c + uVar8 + 8);
  switch(uVar8) {
  case 0xfffffff9:
    uVar17 = 0;
    uVar8 = uVar17;
    goto LAB_00156ef2;
  case 0xfffffffa:
    uVar17 = 0;
    uVar8 = uVar17;
    goto LAB_00156ee8;
  case 0xfffffffb:
    uVar17 = 0;
    uVar8 = uVar17;
    goto LAB_00156ede;
  case 0xfffffffc:
    uVar8 = 0;
    goto LAB_00156ed6;
  case 0xfffffffd:
    uVar8 = 0;
    goto LAB_00156ece;
  case 0xfffffffe:
    uVar8 = 0;
    break;
  case 0xffffffff:
    pbVar1 = puVar4 + -1;
    puVar4 = puVar4 + -1;
    uVar8 = (uint)*pbVar1 << 0x10;
    break;
  default:
    uVar17 = 0;
    uVar8 = uVar17;
    goto LAB_00156ef8;
  }
  pbVar1 = puVar4 + -1;
  puVar4 = puVar4 + -1;
  uVar8 = uVar8 | (uint)*pbVar1 << 8;
LAB_00156ece:
  pbVar1 = puVar4 + -1;
  puVar4 = puVar4 + -1;
  uVar8 = uVar8 | *pbVar1;
LAB_00156ed6:
  pbVar1 = puVar4 + -1;
  puVar4 = puVar4 + -1;
  uVar17 = (uint)*pbVar1 << 0x18;
LAB_00156ede:
  pbVar1 = puVar4 + -1;
  puVar4 = puVar4 + -1;
  uVar17 = uVar17 | (uint)*pbVar1 << 0x10;
LAB_00156ee8:
  pbVar1 = puVar4 + -1;
  puVar4 = puVar4 + -1;
  uVar17 = uVar17 | (uint)*pbVar1 << 8;
LAB_00156ef2:
  uVar17 = puVar4[-1] | uVar17;
LAB_00156ef8:
  local_30 = local_30 ^ uVar17;
  local_2c = local_2c ^ uVar8;
  RC2_encrypt(&local_30,ks);
  uVar16 = (uchar)local_30;
  *local_44 = uVar16;
  uVar19 = (uchar)(local_30 >> 0x18);
  local_44[3] = uVar19;
  uVar14 = (uchar)(local_30 >> 8);
  local_44[1] = uVar14;
  uVar11 = (uchar)(local_30 >> 0x10);
  local_44[2] = uVar11;
  uVar10 = (uchar)local_2c;
  local_44[4] = uVar10;
  uVar7 = (uchar)(local_2c >> 0x18);
  local_44[7] = uVar7;
  uVar3 = (uchar)(local_2c >> 8);
  local_44[5] = uVar3;
  uVar5 = (uchar)(local_2c >> 0x10);
  local_44[6] = uVar5;
LAB_00156ea2:
  *iv = uVar16;
  iv[1] = uVar14;
  iv[2] = uVar11;
  iv[3] = uVar19;
  iv[4] = uVar10;
  iv[5] = uVar3;
  iv[6] = uVar5;
  iv[7] = uVar7;
  return;
}

