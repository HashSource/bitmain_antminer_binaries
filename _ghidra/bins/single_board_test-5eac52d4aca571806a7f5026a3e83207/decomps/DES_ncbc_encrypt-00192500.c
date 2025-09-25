
void DES_ncbc_encrypt(uchar *input,uchar *output,long length,DES_key_schedule *schedule,
                     DES_cblock *ivec,int enc)

{
  byte *pbVar1;
  uint *puVar2;
  uchar uVar3;
  uint uVar4;
  uchar *puVar5;
  uchar uVar6;
  uint uVar7;
  uchar uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uchar uVar12;
  uchar uVar13;
  uint *puVar14;
  uchar uVar15;
  uint uVar16;
  uint uVar17;
  uchar uVar18;
  uchar uVar19;
  uchar *local_44;
  uint *local_3c;
  uint local_30;
  uint local_2c;
  
  local_44 = output;
  local_3c = (uint *)input;
  if (enc == 0) {
    uVar16 = length - 8;
    uVar4 = *(uint *)*ivec;
    uVar11 = *(uint *)(*ivec + 4);
    if (-1 < (int)uVar16) {
      puVar5 = output + 8;
      puVar14 = (uint *)input;
      uVar17 = uVar16;
      uVar10 = uVar11;
      uVar7 = uVar4;
      do {
        uVar4 = *puVar14;
        uVar11 = puVar14[1];
        puVar14 = puVar14 + 2;
        local_30 = uVar4;
        local_2c = uVar11;
        DES_encrypt1(&local_30,schedule,0);
        uVar17 = uVar17 - 8;
        uVar7 = uVar7 ^ local_30;
        uVar10 = uVar10 ^ local_2c;
        puVar5[-8] = (uchar)uVar7;
        puVar5[-7] = (uchar)(uVar7 >> 8);
        puVar5[-6] = (uchar)(uVar7 >> 0x10);
        puVar5[-5] = (uchar)(uVar7 >> 0x18);
        puVar5[-4] = (uchar)uVar10;
        puVar5[-3] = (uchar)(uVar10 >> 8);
        puVar5[-2] = (uchar)(uVar10 >> 0x10);
        puVar5[-1] = (uchar)(uVar10 >> 0x18);
        puVar5 = puVar5 + 8;
        uVar10 = uVar11;
        uVar7 = uVar4;
      } while (-1 < (int)uVar17);
      uVar17 = uVar16 >> 3;
      uVar16 = length + -0x10 + uVar17 * -8;
      iVar9 = (uVar17 + 1) * 8;
      local_3c = (uint *)(input + iVar9);
      local_44 = output + iVar9;
    }
    uVar17 = uVar11;
    uVar10 = uVar4;
    if (uVar16 == 0xfffffff8) goto switchD_001926ba_default;
    uVar10 = *local_3c;
    uVar17 = local_3c[1];
    local_30 = uVar10;
    local_2c = uVar17;
    DES_encrypt1(&local_30,schedule,0);
    local_44 = local_44 + uVar16 + 8;
    uVar4 = uVar4 ^ local_30;
    uVar11 = uVar11 ^ local_2c;
    puVar5 = local_44;
    switch(uVar16) {
    case 0xfffffff9:
      goto LAB_001926fa;
    case 0xfffffffa:
      goto switchD_001926ba_caseD_fffffffa;
    case 0xfffffffb:
      goto LAB_001926e6;
    case 0xfffffffc:
      goto switchD_001926ba_caseD_fffffffc;
    case 0xfffffffd:
      break;
    case 0xffffffff:
      puVar5 = local_44 + -1;
      local_44[-1] = (uchar)(uVar11 >> 0x10);
    case 0xfffffffe:
      puVar5[-1] = (uchar)(uVar11 >> 8);
      puVar5 = puVar5 + -1;
      break;
    default:
      goto switchD_001926ba_default;
    }
    local_44 = puVar5 + -1;
    puVar5[-1] = (uchar)uVar11;
switchD_001926ba_caseD_fffffffc:
    local_44[-1] = (uchar)(uVar4 >> 0x18);
    puVar5 = local_44 + -1;
LAB_001926e6:
    local_44 = puVar5 + -1;
    puVar5[-1] = (uchar)(uVar4 >> 0x10);
switchD_001926ba_caseD_fffffffa:
    local_44[-1] = (uchar)(uVar4 >> 8);
    local_44 = local_44 + -1;
LAB_001926fa:
    local_44[-1] = (uchar)uVar4;
switchD_001926ba_default:
    (*ivec)[0] = (uchar)uVar10;
    (*ivec)[4] = (uchar)uVar17;
    (*ivec)[1] = (uchar)(uVar10 >> 8);
    (*ivec)[2] = (uchar)(uVar10 >> 0x10);
    (*ivec)[3] = (uchar)(uVar10 >> 0x18);
    (*ivec)[5] = (uchar)(uVar17 >> 8);
    (*ivec)[6] = (uchar)(uVar17 >> 0x10);
    (*ivec)[7] = (uchar)(uVar17 >> 0x18);
    return;
  }
  uVar11 = length - 8;
  local_2c = *(uint *)(*ivec + 4);
  local_30 = *(uint *)*ivec;
  if (-1 < (int)uVar11) {
    puVar5 = output + 8;
    puVar14 = (uint *)input;
    uVar16 = uVar11;
    do {
      uVar4 = *puVar14;
      puVar2 = puVar14 + 1;
      puVar14 = puVar14 + 2;
      local_30 = local_30 ^ uVar4;
      local_2c = *puVar2 ^ local_2c;
      DES_encrypt1(&local_30,schedule,1);
      uVar16 = uVar16 - 8;
      puVar5[-8] = (uchar)local_30;
      puVar5[-4] = (uchar)local_2c;
      puVar5[-7] = (uchar)(local_30 >> 8);
      puVar5[-6] = (uchar)(local_30 >> 0x10);
      puVar5[-5] = (uchar)(local_30 >> 0x18);
      puVar5[-3] = (uchar)(local_2c >> 8);
      puVar5[-2] = (uchar)(local_2c >> 0x10);
      puVar5[-1] = (uchar)(local_2c >> 0x18);
      puVar5 = puVar5 + 8;
    } while (-1 < (int)uVar16);
    uVar16 = uVar11 >> 3;
    uVar11 = length + -0x10 + uVar16 * -8;
    iVar9 = (uVar16 + 1) * 8;
    local_3c = (uint *)(input + iVar9);
    local_44 = output + iVar9;
  }
  if (uVar11 == 0xfffffff8) {
    uVar12 = (uchar)local_2c;
    uVar3 = (uchar)(local_2c >> 8);
    uVar8 = (uchar)(local_2c >> 0x10);
    uVar18 = (uchar)local_30;
    uVar19 = (uchar)(local_30 >> 0x18);
    uVar6 = (uchar)(local_2c >> 0x18);
    uVar15 = (uchar)(local_30 >> 8);
    uVar13 = (uchar)(local_30 >> 0x10);
    goto LAB_0019274a;
  }
  puVar5 = (uchar *)((int)local_3c + uVar11 + 8);
  switch(uVar11) {
  case 0xfffffff9:
    uVar16 = 0;
    uVar11 = uVar16;
    goto LAB_0019279a;
  case 0xfffffffa:
    uVar16 = 0;
    uVar11 = uVar16;
    goto LAB_00192790;
  case 0xfffffffb:
    uVar16 = 0;
    uVar11 = uVar16;
    goto LAB_00192786;
  case 0xfffffffc:
    uVar11 = 0;
    goto LAB_0019277e;
  case 0xfffffffd:
    uVar11 = 0;
    goto LAB_00192776;
  case 0xfffffffe:
    uVar11 = 0;
    break;
  case 0xffffffff:
    pbVar1 = puVar5 + -1;
    puVar5 = puVar5 + -1;
    uVar11 = (uint)*pbVar1 << 0x10;
    break;
  default:
    uVar16 = 0;
    uVar11 = uVar16;
    goto LAB_001927a0;
  }
  pbVar1 = puVar5 + -1;
  puVar5 = puVar5 + -1;
  uVar11 = uVar11 | (uint)*pbVar1 << 8;
LAB_00192776:
  pbVar1 = puVar5 + -1;
  puVar5 = puVar5 + -1;
  uVar11 = uVar11 | *pbVar1;
LAB_0019277e:
  pbVar1 = puVar5 + -1;
  puVar5 = puVar5 + -1;
  uVar16 = (uint)*pbVar1 << 0x18;
LAB_00192786:
  pbVar1 = puVar5 + -1;
  puVar5 = puVar5 + -1;
  uVar16 = uVar16 | (uint)*pbVar1 << 0x10;
LAB_00192790:
  pbVar1 = puVar5 + -1;
  puVar5 = puVar5 + -1;
  uVar16 = uVar16 | (uint)*pbVar1 << 8;
LAB_0019279a:
  uVar16 = puVar5[-1] | uVar16;
LAB_001927a0:
  local_30 = local_30 ^ uVar16;
  local_2c = uVar11 ^ local_2c;
  DES_encrypt1(&local_30,schedule,1);
  uVar18 = (uchar)local_30;
  *local_44 = uVar18;
  uVar19 = (uchar)(local_30 >> 0x18);
  local_44[3] = uVar19;
  uVar15 = (uchar)(local_30 >> 8);
  local_44[1] = uVar15;
  uVar13 = (uchar)(local_30 >> 0x10);
  local_44[2] = uVar13;
  uVar12 = (uchar)local_2c;
  local_44[4] = uVar12;
  uVar6 = (uchar)(local_2c >> 0x18);
  local_44[7] = uVar6;
  uVar3 = (uchar)(local_2c >> 8);
  local_44[5] = uVar3;
  uVar8 = (uchar)(local_2c >> 0x10);
  local_44[6] = uVar8;
LAB_0019274a:
  (*ivec)[0] = uVar18;
  (*ivec)[1] = uVar15;
  (*ivec)[2] = uVar13;
  (*ivec)[3] = uVar19;
  (*ivec)[4] = uVar12;
  (*ivec)[5] = uVar3;
  (*ivec)[6] = uVar8;
  (*ivec)[7] = uVar6;
  return;
}

