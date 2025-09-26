
void CAST_cbc_encrypt(uchar *in,uchar *out,long length,CAST_KEY *ks,uchar *iv,int enc)

{
  byte *pbVar1;
  uchar uVar2;
  uint uVar3;
  uchar uVar4;
  uchar *puVar5;
  uchar uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uchar uVar10;
  uchar uVar11;
  uchar *puVar12;
  uchar uVar13;
  uint uVar14;
  uchar uVar15;
  uint uVar16;
  uint uVar17;
  uchar uVar18;
  uchar *local_44;
  byte *local_3c;
  uint local_30;
  uint local_2c;
  
  local_44 = out;
  local_3c = in;
  if (enc == 0) {
    uVar16 = length - 8;
    uVar14 = (uint)iv[1] << 0x10 | (uint)*iv << 0x18 | (uint)iv[3] | (uint)iv[2] << 8;
    uVar9 = (uint)iv[5] << 0x10 | (uint)iv[4] << 0x18 | (uint)iv[7] | (uint)iv[6] << 8;
    if (-1 < (int)uVar16) {
      puVar12 = in + 8;
      uVar17 = uVar16;
      uVar8 = uVar9;
      uVar3 = uVar14;
      puVar5 = out;
      do {
        uVar14 = (uint)puVar12[-7] << 0x10 | (uint)puVar12[-8] << 0x18 | (uint)puVar12[-5] |
                 (uint)puVar12[-6] << 8;
        uVar9 = (uint)puVar12[-1] | (uint)puVar12[-3] << 0x10 | (uint)puVar12[-4] << 0x18 |
                (uint)puVar12[-2] << 8;
        local_30 = uVar14;
        local_2c = uVar9;
        CAST_decrypt(&local_30,ks);
        uVar17 = uVar17 - 8;
        uVar3 = uVar3 ^ local_30;
        uVar8 = uVar8 ^ local_2c;
        puVar5[3] = (uchar)uVar3;
        puVar5[7] = (uchar)uVar8;
        *puVar5 = (uchar)(uVar3 >> 0x18);
        puVar5[1] = (uchar)(uVar3 >> 0x10);
        puVar5[2] = (uchar)(uVar3 >> 8);
        puVar5[4] = (uchar)(uVar8 >> 0x18);
        puVar5[5] = (uchar)(uVar8 >> 0x10);
        puVar5[6] = (uchar)(uVar8 >> 8);
        puVar12 = puVar12 + 8;
        uVar8 = uVar9;
        uVar3 = uVar14;
        puVar5 = puVar5 + 8;
      } while (-1 < (int)uVar17);
      iVar7 = ((uVar16 >> 3) + 1) * 8;
      uVar16 = length + -0x10 + (uVar16 >> 3) * -8;
      local_3c = in + iVar7;
      local_44 = out + iVar7;
    }
    uVar17 = uVar9;
    uVar8 = uVar14;
    if (uVar16 == 0xfffffff8) goto switchD_001d9c74_default;
    uVar8 = (uint)local_3c[1] << 0x10 | (uint)*local_3c << 0x18 | (uint)local_3c[3] |
            (uint)local_3c[2] << 8;
    uVar17 = (uint)local_3c[5] << 0x10 | (uint)local_3c[4] << 0x18 | (uint)local_3c[7] |
             (uint)local_3c[6] << 8;
    local_30 = uVar8;
    local_2c = uVar17;
    CAST_decrypt(&local_30,ks);
    local_44 = local_44 + uVar16 + 8;
    uVar14 = uVar14 ^ local_30;
    uVar9 = uVar9 ^ local_2c;
    switch(uVar16) {
    case 0xfffffff9:
      goto LAB_001d9cac;
    case 0xfffffffa:
      goto switchD_001d9c74_caseD_fffffffa;
    case 0xfffffffb:
      puVar5 = local_44;
      goto LAB_001d9c9c;
    case 0xfffffffc:
      goto switchD_001d9c74_caseD_fffffffc;
    case 0xfffffffd:
      puVar5 = local_44;
      break;
    case 0xffffffff:
      local_44 = local_44 + -1;
      *local_44 = (uchar)(uVar9 >> 8);
    case 0xfffffffe:
      local_44[-1] = (uchar)(uVar9 >> 0x10);
      puVar5 = local_44 + -1;
      break;
    default:
      goto switchD_001d9c74_default;
    }
    local_44 = puVar5 + -1;
    puVar5[-1] = (uchar)(uVar9 >> 0x18);
switchD_001d9c74_caseD_fffffffc:
    local_44[-1] = (uchar)uVar14;
    puVar5 = local_44 + -1;
LAB_001d9c9c:
    local_44 = puVar5 + -1;
    puVar5[-1] = (uchar)(uVar14 >> 8);
switchD_001d9c74_caseD_fffffffa:
    local_44[-1] = (uchar)(uVar14 >> 0x10);
    local_44 = local_44 + -1;
LAB_001d9cac:
    local_44[-1] = (uchar)(uVar14 >> 0x18);
switchD_001d9c74_default:
    iv[3] = (uchar)uVar8;
    iv[7] = (uchar)uVar17;
    *iv = (uchar)(uVar8 >> 0x18);
    iv[1] = (uchar)(uVar8 >> 0x10);
    iv[2] = (uchar)(uVar8 >> 8);
    iv[4] = (uchar)(uVar17 >> 0x18);
    iv[5] = (uchar)(uVar17 >> 0x10);
    iv[6] = (uchar)(uVar17 >> 8);
    return;
  }
  uVar9 = length - 8;
  local_30 = (uint)iv[3] | (uint)iv[1] << 0x10 | (uint)*iv << 0x18 | (uint)iv[2] << 8;
  local_2c = (uint)iv[5] << 0x10 | (uint)iv[4] << 0x18 | (uint)iv[7] | (uint)iv[6] << 8;
  if (-1 < (int)uVar9) {
    puVar5 = out + 8;
    puVar12 = in + 8;
    uVar14 = uVar9;
    do {
      local_30 = local_30 ^
                 ((uint)puVar12[-7] << 0x10 | (uint)puVar12[-8] << 0x18 | (uint)puVar12[-5] |
                 (uint)puVar12[-6] << 8);
      local_2c = local_2c ^
                 ((uint)puVar12[-3] << 0x10 | (uint)puVar12[-4] << 0x18 | (uint)puVar12[-1] |
                 (uint)puVar12[-2] << 8);
      CAST_encrypt(&local_30,ks);
      uVar14 = uVar14 - 8;
      puVar5[-5] = (uchar)local_30;
      puVar5[-8] = (uchar)(local_30 >> 0x18);
      puVar5[-7] = (uchar)(local_30 >> 0x10);
      puVar5[-6] = (uchar)(local_30 >> 8);
      puVar5[-1] = (uchar)local_2c;
      puVar5[-4] = (uchar)(local_2c >> 0x18);
      puVar5[-3] = (uchar)(local_2c >> 0x10);
      puVar5[-2] = (uchar)(local_2c >> 8);
      puVar5 = puVar5 + 8;
      puVar12 = puVar12 + 8;
    } while (-1 < (int)uVar14);
    uVar14 = uVar9 >> 3;
    uVar9 = length + -0x10 + uVar14 * -8;
    iVar7 = (uVar14 + 1) * 8;
    local_3c = in + iVar7;
    local_44 = out + iVar7;
  }
  if (uVar9 == 0xfffffff8) {
    uVar2 = (uchar)(local_2c >> 0x18);
    uVar4 = (uchar)(local_2c >> 0x10);
    uVar6 = (uchar)(local_2c >> 8);
    uVar13 = (uchar)(local_30 >> 0x18);
    uVar18 = (uchar)local_30;
    uVar15 = (uchar)local_2c;
    uVar11 = (uchar)(local_30 >> 0x10);
    uVar10 = (uchar)(local_30 >> 8);
    goto LAB_001d9d02;
  }
  puVar5 = local_3c + uVar9 + 8;
  switch(uVar9) {
  case 0xfffffff9:
    uVar14 = 0;
    uVar9 = uVar14;
    goto LAB_001d9d5e;
  case 0xfffffffa:
    uVar14 = 0;
    uVar9 = uVar14;
    goto LAB_001d9d54;
  case 0xfffffffb:
    uVar14 = 0;
    uVar9 = uVar14;
    goto LAB_001d9d4a;
  case 0xfffffffc:
    uVar9 = 0;
    goto LAB_001d9d44;
  case 0xfffffffd:
    uVar9 = 0;
    goto LAB_001d9d3a;
  case 0xfffffffe:
    uVar9 = 0;
    break;
  case 0xffffffff:
    pbVar1 = puVar5 + -1;
    puVar5 = puVar5 + -1;
    uVar9 = (uint)*pbVar1 << 8;
    break;
  default:
    uVar14 = 0;
    uVar9 = uVar14;
    goto LAB_001d9d66;
  }
  pbVar1 = puVar5 + -1;
  puVar5 = puVar5 + -1;
  uVar9 = uVar9 | (uint)*pbVar1 << 0x10;
LAB_001d9d3a:
  pbVar1 = puVar5 + -1;
  puVar5 = puVar5 + -1;
  uVar9 = uVar9 | (uint)*pbVar1 << 0x18;
LAB_001d9d44:
  uVar14 = (uint)puVar5[-1];
  puVar5 = puVar5 + -1;
LAB_001d9d4a:
  pbVar1 = puVar5 + -1;
  puVar5 = puVar5 + -1;
  uVar14 = uVar14 | (uint)*pbVar1 << 8;
LAB_001d9d54:
  pbVar1 = puVar5 + -1;
  puVar5 = puVar5 + -1;
  uVar14 = uVar14 | (uint)*pbVar1 << 0x10;
LAB_001d9d5e:
  uVar14 = uVar14 | (uint)puVar5[-1] << 0x18;
LAB_001d9d66:
  local_30 = local_30 ^ uVar14;
  local_2c = local_2c ^ uVar9;
  CAST_encrypt(&local_30,ks);
  uVar13 = (uchar)(local_30 >> 0x18);
  *local_44 = uVar13;
  uVar18 = (uchar)local_30;
  local_44[3] = uVar18;
  uVar11 = (uchar)(local_30 >> 0x10);
  local_44[1] = uVar11;
  uVar10 = (uchar)(local_30 >> 8);
  local_44[2] = uVar10;
  uVar2 = (uchar)(local_2c >> 0x18);
  local_44[4] = uVar2;
  uVar15 = (uchar)local_2c;
  local_44[7] = uVar15;
  uVar4 = (uchar)(local_2c >> 0x10);
  local_44[5] = uVar4;
  uVar6 = (uchar)(local_2c >> 8);
  local_44[6] = uVar6;
LAB_001d9d02:
  *iv = uVar13;
  iv[1] = uVar11;
  iv[2] = uVar10;
  iv[3] = uVar18;
  iv[4] = uVar2;
  iv[5] = uVar4;
  iv[6] = uVar6;
  iv[7] = uVar15;
  return;
}

