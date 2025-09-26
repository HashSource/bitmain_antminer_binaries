
void DES_ede3_cbc_encrypt
               (uchar *input,uchar *output,long length,DES_key_schedule *ks1,DES_key_schedule *ks2,
               DES_key_schedule *ks3,DES_cblock *ivec,int enc)

{
  uint *puVar1;
  byte *pbVar2;
  uchar uVar3;
  uint uVar4;
  uchar *puVar5;
  uchar uVar6;
  uint uVar7;
  uchar uVar8;
  uint uVar9;
  int iVar10;
  uchar uVar11;
  uchar uVar12;
  uint *puVar13;
  uchar uVar14;
  uint uVar15;
  uint uVar16;
  uchar uVar17;
  uint uVar18;
  uchar uVar19;
  uchar *local_44;
  uint *local_3c;
  uint local_30;
  uint local_2c;
  
  local_44 = output;
  local_3c = (uint *)input;
  if (enc == 0) {
    uVar15 = length - 8;
    uVar9 = *(uint *)*ivec;
    uVar4 = *(uint *)(*ivec + 4);
    if (-1 < (int)uVar15) {
      puVar5 = output + 8;
      puVar13 = (uint *)input;
      uVar16 = uVar15;
      uVar7 = uVar9;
      uVar18 = uVar4;
      do {
        uVar9 = *puVar13;
        uVar4 = puVar13[1];
        puVar13 = puVar13 + 2;
        local_30 = uVar9;
        local_2c = uVar4;
        DES_decrypt3(&local_30,ks1,ks2,ks3);
        uVar16 = uVar16 - 8;
        uVar7 = uVar7 ^ local_30;
        local_2c = local_2c ^ uVar18;
        puVar5[-8] = (uchar)uVar7;
        puVar5[-7] = (uchar)(uVar7 >> 8);
        puVar5[-6] = (uchar)(uVar7 >> 0x10);
        puVar5[-5] = (uchar)(uVar7 >> 0x18);
        puVar5[-4] = (uchar)local_2c;
        puVar5[-3] = (uchar)(local_2c >> 8);
        puVar5[-2] = (uchar)(local_2c >> 0x10);
        puVar5[-1] = (uchar)(local_2c >> 0x18);
        puVar5 = puVar5 + 8;
        uVar7 = uVar9;
        uVar18 = uVar4;
      } while (-1 < (int)uVar16);
      uVar16 = uVar15 >> 3;
      uVar15 = length + -0x10 + uVar16 * -8;
      iVar10 = (uVar16 + 1) * 8;
      local_3c = (uint *)(input + iVar10);
      local_44 = output + iVar10;
    }
    uVar16 = uVar4;
    uVar7 = uVar9;
    if (uVar15 == 0xfffffff8) goto switchD_001a0818_default;
    uVar7 = *local_3c;
    uVar16 = local_3c[1];
    local_30 = uVar7;
    local_2c = uVar16;
    DES_decrypt3(&local_30,ks1,ks2,ks3);
    local_44 = local_44 + uVar15 + 8;
    uVar9 = uVar9 ^ local_30;
    uVar4 = uVar4 ^ local_2c;
    puVar5 = local_44;
    switch(uVar15) {
    case 0xfffffff9:
      goto LAB_001a0858;
    case 0xfffffffa:
      goto switchD_001a0818_caseD_fffffffa;
    case 0xfffffffb:
      goto LAB_001a0844;
    case 0xfffffffc:
      goto switchD_001a0818_caseD_fffffffc;
    case 0xfffffffd:
      break;
    case 0xffffffff:
      puVar5 = local_44 + -1;
      local_44[-1] = (uchar)(uVar4 >> 0x10);
    case 0xfffffffe:
      local_44 = puVar5 + -1;
      puVar5[-1] = (uchar)(uVar4 >> 8);
      break;
    default:
      goto switchD_001a0818_default;
    }
    puVar5 = local_44 + -1;
    local_44[-1] = (uchar)uVar4;
switchD_001a0818_caseD_fffffffc:
    local_44 = puVar5 + -1;
    puVar5[-1] = (uchar)(uVar9 >> 0x18);
LAB_001a0844:
    puVar5 = local_44 + -1;
    local_44[-1] = (uchar)(uVar9 >> 0x10);
switchD_001a0818_caseD_fffffffa:
    local_44 = puVar5 + -1;
    puVar5[-1] = (uchar)(uVar9 >> 8);
LAB_001a0858:
    local_44[-1] = (uchar)uVar9;
switchD_001a0818_default:
    (*ivec)[0] = (uchar)uVar7;
    (*ivec)[4] = (uchar)uVar16;
    (*ivec)[1] = (uchar)(uVar7 >> 8);
    (*ivec)[2] = (uchar)(uVar7 >> 0x10);
    (*ivec)[3] = (uchar)(uVar7 >> 0x18);
    (*ivec)[5] = (uchar)(uVar16 >> 8);
    (*ivec)[6] = (uchar)(uVar16 >> 0x10);
    (*ivec)[7] = (uchar)(uVar16 >> 0x18);
    return;
  }
  uVar9 = length - 8;
  local_2c = *(uint *)(*ivec + 4);
  local_30 = *(uint *)*ivec;
  if (-1 < (int)uVar9) {
    puVar5 = output + 8;
    puVar13 = (uint *)input;
    uVar15 = uVar9;
    do {
      uVar4 = *puVar13;
      puVar1 = puVar13 + 1;
      puVar13 = puVar13 + 2;
      local_30 = uVar4 ^ local_30;
      local_2c = *puVar1 ^ local_2c;
      DES_encrypt3(&local_30,ks1,ks2,ks3);
      uVar15 = uVar15 - 8;
      puVar5[-8] = (uchar)local_30;
      puVar5[-7] = (uchar)(local_30 >> 8);
      puVar5[-6] = (uchar)(local_30 >> 0x10);
      puVar5[-5] = (uchar)(local_30 >> 0x18);
      puVar5[-4] = (uchar)local_2c;
      puVar5[-3] = (uchar)(local_2c >> 8);
      puVar5[-2] = (uchar)(local_2c >> 0x10);
      puVar5[-1] = (uchar)(local_2c >> 0x18);
      puVar5 = puVar5 + 8;
    } while (-1 < (int)uVar15);
    uVar15 = uVar9 >> 3;
    uVar9 = length + -0x10 + uVar15 * -8;
    iVar10 = (uVar15 + 1) * 8;
    local_3c = (uint *)(input + iVar10);
    local_44 = output + iVar10;
  }
  if (uVar9 == 0xfffffff8) {
    uVar11 = (uchar)local_2c;
    uVar3 = (uchar)(local_2c >> 8);
    uVar8 = (uchar)(local_2c >> 0x10);
    uVar17 = (uchar)local_30;
    uVar19 = (uchar)(local_30 >> 0x18);
    uVar6 = (uchar)(local_2c >> 0x18);
    uVar14 = (uchar)(local_30 >> 8);
    uVar12 = (uchar)(local_30 >> 0x10);
    goto LAB_001a08a8;
  }
  puVar5 = (uchar *)((int)local_3c + uVar9 + 8);
  switch(uVar9) {
  case 0xfffffff9:
    uVar15 = 0;
    uVar9 = uVar15;
    goto LAB_001a08f8;
  case 0xfffffffa:
    uVar15 = 0;
    uVar9 = uVar15;
    goto LAB_001a08ee;
  case 0xfffffffb:
    uVar15 = 0;
    uVar9 = uVar15;
    goto LAB_001a08e4;
  case 0xfffffffc:
    uVar9 = 0;
    goto LAB_001a08dc;
  case 0xfffffffd:
    uVar9 = 0;
    goto LAB_001a08d4;
  case 0xfffffffe:
    uVar9 = 0;
    break;
  case 0xffffffff:
    pbVar2 = puVar5 + -1;
    puVar5 = puVar5 + -1;
    uVar9 = (uint)*pbVar2 << 0x10;
    break;
  default:
    uVar15 = 0;
    uVar9 = uVar15;
    goto LAB_001a08fe;
  }
  pbVar2 = puVar5 + -1;
  puVar5 = puVar5 + -1;
  uVar9 = uVar9 | (uint)*pbVar2 << 8;
LAB_001a08d4:
  pbVar2 = puVar5 + -1;
  puVar5 = puVar5 + -1;
  uVar9 = uVar9 | *pbVar2;
LAB_001a08dc:
  pbVar2 = puVar5 + -1;
  puVar5 = puVar5 + -1;
  uVar15 = (uint)*pbVar2 << 0x18;
LAB_001a08e4:
  pbVar2 = puVar5 + -1;
  puVar5 = puVar5 + -1;
  uVar15 = uVar15 | (uint)*pbVar2 << 0x10;
LAB_001a08ee:
  pbVar2 = puVar5 + -1;
  puVar5 = puVar5 + -1;
  uVar15 = uVar15 | (uint)*pbVar2 << 8;
LAB_001a08f8:
  uVar15 = uVar15 | puVar5[-1];
LAB_001a08fe:
  local_30 = uVar15 ^ local_30;
  local_2c = uVar9 ^ local_2c;
  DES_encrypt3(&local_30,ks1,ks2,ks3);
  uVar17 = (uchar)local_30;
  *local_44 = uVar17;
  uVar19 = (uchar)(local_30 >> 0x18);
  local_44[3] = uVar19;
  uVar14 = (uchar)(local_30 >> 8);
  local_44[1] = uVar14;
  uVar12 = (uchar)(local_30 >> 0x10);
  local_44[2] = uVar12;
  uVar11 = (uchar)local_2c;
  local_44[4] = uVar11;
  uVar6 = (uchar)(local_2c >> 0x18);
  local_44[7] = uVar6;
  uVar3 = (uchar)(local_2c >> 8);
  local_44[5] = uVar3;
  uVar8 = (uchar)(local_2c >> 0x10);
  local_44[6] = uVar8;
LAB_001a08a8:
  (*ivec)[0] = uVar17;
  (*ivec)[1] = uVar14;
  (*ivec)[2] = uVar12;
  (*ivec)[3] = uVar19;
  (*ivec)[4] = uVar11;
  (*ivec)[5] = uVar3;
  (*ivec)[6] = uVar8;
  (*ivec)[7] = uVar6;
  return;
}

