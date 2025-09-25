
void DES_xcbc_encrypt(uchar *input,uchar *output,long length,DES_key_schedule *schedule,
                     DES_cblock *ivec,const_DES_cblock *inw,const_DES_cblock *outw,int enc)

{
  byte *pbVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  int iVar5;
  uchar *puVar6;
  uchar uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uchar uVar12;
  uchar uVar13;
  uint *puVar14;
  uchar uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uchar uVar19;
  uint uVar20;
  uint uVar21;
  uchar *local_44;
  uchar *local_38;
  uint local_30;
  uint local_2c;
  
  uVar8 = *(uint *)*inw;
  uVar9 = *(uint *)(*inw + 4);
  uVar20 = *(uint *)*outw;
  uVar10 = *(uint *)(*outw + 4);
  local_44 = output;
  if (enc != 0) {
    uVar16 = length - 8;
    local_30 = *(uint *)*ivec;
    local_2c = *(uint *)(*ivec + 4);
    local_38 = input;
    if (-1 < (int)uVar16) {
      puVar6 = output + 8;
      puVar14 = (uint *)input;
      uVar17 = uVar16;
      do {
        local_30 = *puVar14 ^ uVar8 ^ local_30;
        local_2c = uVar9 ^ puVar14[1] ^ local_2c;
        DES_encrypt1(&local_30,schedule,1);
        uVar17 = uVar17 - 8;
        local_30 = uVar20 ^ local_30;
        puVar6[-8] = (uchar)local_30;
        puVar6[-7] = (uchar)(local_30 >> 8);
        puVar6[-6] = (uchar)(local_30 >> 0x10);
        puVar6[-5] = (uchar)(local_30 >> 0x18);
        local_2c = uVar10 ^ local_2c;
        puVar6[-4] = (uchar)local_2c;
        puVar6[-3] = (uchar)(local_2c >> 8);
        puVar6[-2] = (uchar)(local_2c >> 0x10);
        puVar6[-1] = (uchar)(local_2c >> 0x18);
        puVar6 = puVar6 + 8;
        puVar14 = puVar14 + 2;
      } while (-1 < (int)uVar17);
      uVar17 = uVar16 >> 3;
      uVar16 = length + -0x10 + uVar17 * -8;
      iVar5 = (uVar17 + 1) * 8;
      local_38 = input + iVar5;
      local_44 = output + iVar5;
    }
    if (uVar16 == 0xfffffff8) {
      uVar15 = (uchar)local_30;
      uVar13 = (uchar)(local_30 >> 8);
      uVar19 = (uchar)(local_30 >> 0x10);
      uVar12 = (uchar)local_2c;
      uVar2 = (uchar)(local_2c >> 8);
      uVar3 = (uchar)(local_30 >> 0x18);
      uVar4 = (uchar)(local_2c >> 0x10);
      uVar7 = (uchar)(local_2c >> 0x18);
      goto LAB_001cec84;
    }
    local_38 = local_38 + uVar16 + 8;
    switch(uVar16) {
    case 0xfffffff9:
      uVar17 = 0;
      uVar16 = uVar17;
      goto LAB_001cecd4;
    case 0xfffffffa:
      uVar17 = 0;
      uVar16 = uVar17;
      goto LAB_001cecca;
    case 0xfffffffb:
      uVar17 = 0;
      uVar16 = uVar17;
      goto LAB_001cecc0;
    case 0xfffffffc:
      uVar17 = 0;
      goto LAB_001cecb8;
    case 0xfffffffd:
      uVar17 = 0;
      goto LAB_001cecb0;
    case 0xfffffffe:
      uVar17 = 0;
      break;
    case 0xffffffff:
      pbVar1 = local_38 + -1;
      local_38 = local_38 + -1;
      uVar17 = (uint)*pbVar1 << 0x10;
      break;
    default:
      uVar17 = 0;
      uVar16 = uVar17;
      goto LAB_001cecda;
    }
    pbVar1 = local_38 + -1;
    local_38 = local_38 + -1;
    uVar17 = uVar17 | (uint)*pbVar1 << 8;
LAB_001cecb0:
    pbVar1 = local_38 + -1;
    local_38 = local_38 + -1;
    uVar17 = uVar17 | *pbVar1;
LAB_001cecb8:
    pbVar1 = local_38 + -1;
    local_38 = local_38 + -1;
    uVar16 = (uint)*pbVar1 << 0x18;
LAB_001cecc0:
    pbVar1 = local_38 + -1;
    local_38 = local_38 + -1;
    uVar16 = uVar16 | (uint)*pbVar1 << 0x10;
LAB_001cecca:
    pbVar1 = local_38 + -1;
    local_38 = local_38 + -1;
    uVar16 = uVar16 | (uint)*pbVar1 << 8;
LAB_001cecd4:
    uVar16 = uVar16 | local_38[-1];
LAB_001cecda:
    local_30 = uVar16 ^ uVar8 ^ local_30;
    local_2c = uVar9 ^ local_2c ^ uVar17;
    DES_encrypt1(&local_30,schedule,1);
    uVar20 = uVar20 ^ local_30;
    uVar10 = uVar10 ^ local_2c;
    uVar15 = (uchar)uVar20;
    *local_44 = uVar15;
    uVar3 = (uchar)(uVar20 >> 0x18);
    local_44[3] = uVar3;
    uVar13 = (uchar)(uVar20 >> 8);
    local_44[1] = uVar13;
    uVar19 = (uchar)(uVar20 >> 0x10);
    local_44[2] = uVar19;
    uVar12 = (uchar)uVar10;
    local_44[4] = uVar12;
    uVar7 = (uchar)(uVar10 >> 0x18);
    local_44[7] = uVar7;
    uVar2 = (uchar)(uVar10 >> 8);
    local_44[5] = uVar2;
    uVar4 = (uchar)(uVar10 >> 0x10);
    local_44[6] = uVar4;
LAB_001cec84:
    (*ivec)[0] = uVar15;
    (*ivec)[1] = uVar13;
    (*ivec)[2] = uVar19;
    (*ivec)[3] = uVar3;
    (*ivec)[4] = uVar12;
    (*ivec)[5] = uVar2;
    (*ivec)[6] = uVar4;
    (*ivec)[7] = uVar7;
    return;
  }
  iVar5 = length + -8;
  uVar17 = *(uint *)*ivec;
  uVar16 = *(uint *)(*ivec + 4);
  if (iVar5 < 1) {
    uVar18 = uVar16;
    uVar21 = uVar17;
    if (iVar5 == -8) goto switchD_001cebfa_default;
  }
  else {
    puVar6 = output + 8;
    puVar14 = (uint *)input;
    do {
      uVar21 = *puVar14;
      uVar18 = puVar14[1];
      iVar5 = iVar5 + -8;
      puVar14 = puVar14 + 2;
      local_30 = uVar20 ^ uVar21;
      local_2c = uVar10 ^ uVar18;
      DES_encrypt1(&local_30,schedule,0);
      uVar17 = local_30 ^ uVar8 ^ uVar17;
      uVar16 = uVar16 ^ local_2c ^ uVar9;
      puVar6[-7] = (uchar)(uVar17 >> 8);
      puVar6[-4] = (uchar)uVar16;
      puVar6[-8] = (uchar)uVar17;
      puVar6[-6] = (uchar)(uVar17 >> 0x10);
      puVar6[-5] = (uchar)(uVar17 >> 0x18);
      puVar6[-3] = (uchar)(uVar16 >> 8);
      puVar6[-2] = (uchar)(uVar16 >> 0x10);
      puVar6[-1] = (uchar)(uVar16 >> 0x18);
      uVar16 = uVar18;
      puVar6 = puVar6 + 8;
      uVar17 = uVar21;
    } while (0 < iVar5);
    uVar16 = length - 9U >> 3;
    iVar5 = length + -0x10 + uVar16 * -8;
    iVar11 = (uVar16 + 1) * 8;
    input = input + iVar11;
    local_44 = output + iVar11;
  }
  uVar17 = *(uint *)input;
  uVar16 = *(uint *)((int)input + 4);
  local_30 = uVar20 ^ uVar17;
  local_2c = uVar10 ^ uVar16;
  DES_encrypt1(&local_30,schedule,0);
  local_44 = local_44 + iVar5 + 8;
  uVar21 = uVar8 ^ local_30 ^ uVar21;
  uVar18 = uVar9 ^ local_2c ^ uVar18;
  puVar6 = local_44;
  switch(iVar5) {
  case 0:
    local_44 = local_44 + -1;
    *local_44 = (uchar)(uVar18 >> 0x18);
  case -1:
    puVar6 = local_44 + -1;
    *puVar6 = (uchar)(uVar18 >> 0x10);
  case -2:
    local_44 = puVar6 + -1;
    puVar6[-1] = (uchar)(uVar18 >> 8);
    break;
  case -7:
    goto LAB_001cec44;
  case -6:
    goto switchD_001cebfa_caseD_fffffffa;
  case -5:
    goto LAB_001cec30;
  case -4:
    goto switchD_001cebfa_caseD_fffffffc;
  case -3:
    break;
  default:
    goto switchD_001cebfa_default;
  }
  puVar6 = local_44 + -1;
  local_44[-1] = (uchar)uVar18;
switchD_001cebfa_caseD_fffffffc:
  local_44 = puVar6 + -1;
  puVar6[-1] = (uchar)(uVar21 >> 0x18);
LAB_001cec30:
  puVar6 = local_44 + -1;
  local_44[-1] = (uchar)(uVar21 >> 0x10);
switchD_001cebfa_caseD_fffffffa:
  local_44 = puVar6 + -1;
  puVar6[-1] = (uchar)(uVar21 >> 8);
LAB_001cec44:
  local_44[-1] = (uchar)uVar21;
switchD_001cebfa_default:
  (*ivec)[0] = (uchar)uVar17;
  (*ivec)[4] = (uchar)uVar16;
  (*ivec)[1] = (uchar)(uVar17 >> 8);
  (*ivec)[2] = (uchar)(uVar17 >> 0x10);
  (*ivec)[3] = (uchar)(uVar17 >> 0x18);
  (*ivec)[5] = (uchar)(uVar16 >> 8);
  (*ivec)[6] = (uchar)(uVar16 >> 0x10);
  (*ivec)[7] = (uchar)(uVar16 >> 0x18);
  return;
}

