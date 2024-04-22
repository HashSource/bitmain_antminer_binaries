
void DES_xcbc_encrypt(uchar *input,uchar *output,long length,DES_key_schedule *schedule,
                     DES_cblock *ivec,const_DES_cblock *inw,const_DES_cblock *outw,int enc)

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
  uint uVar21;
  uchar uVar22;
  uint uVar23;
  int iVar24;
  uchar uVar25;
  uint uVar26;
  byte *pbVar27;
  uchar uVar28;
  uchar *puVar29;
  uchar uVar30;
  uint uVar31;
  uchar uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uchar *local_48;
  byte *local_40;
  uint local_30;
  uint local_2c;
  
  uVar20 = (uint)(*inw)[2] << 0x10 | (uint)(*inw)[1] << 8 | (uint)(*inw)[0] |
           (uint)(*inw)[3] << 0x18;
  uVar33 = (uint)(*inw)[6] << 0x10 | (uint)(*inw)[5] << 8 | (uint)(*inw)[4] |
           (uint)(*inw)[7] << 0x18;
  uVar26 = (uint)(*outw)[2] << 0x10 | (uint)(*outw)[1] << 8 | (uint)(*outw)[0] |
           (uint)(*outw)[3] << 0x18;
  uVar21 = (uint)(*outw)[4] | (uint)(*outw)[6] << 0x10 | (uint)(*outw)[5] << 8 |
           (uint)(*outw)[7] << 0x18;
  local_48 = output;
  local_40 = input;
  if (enc != 0) {
    uVar34 = length - 8;
    local_30 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
               (uint)(*ivec)[3] << 0x18;
    local_2c = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
               (uint)(*ivec)[7] << 0x18;
    if (-1 < (int)uVar34) {
      pbVar27 = input;
      puVar29 = output;
      uVar31 = uVar34;
      do {
        pbVar1 = pbVar27 + 2;
        pbVar6 = pbVar27 + 1;
        pbVar2 = pbVar27 + 6;
        pbVar3 = pbVar27 + 5;
        pbVar4 = pbVar27 + 3;
        bVar8 = *pbVar27;
        pbVar7 = pbVar27 + 7;
        pbVar5 = pbVar27 + 4;
        pbVar27 = pbVar27 + 8;
        local_30 = ((uint)*pbVar1 << 0x10 | (uint)*pbVar6 << 8 | (uint)bVar8 | (uint)*pbVar4 << 0x18
                   ) ^ uVar20 ^ local_30;
        local_2c = ((uint)*pbVar2 << 0x10 | (uint)*pbVar3 << 8 | (uint)*pbVar5 |
                   (uint)*pbVar7 << 0x18) ^ uVar33 ^ local_2c;
        DES_encrypt1(&local_30,schedule,1);
        uVar31 = uVar31 - 8;
        local_30 = uVar26 ^ local_30;
        *puVar29 = (uchar)local_30;
        local_2c = uVar21 ^ local_2c;
        puVar29[1] = (uchar)(local_30 >> 8);
        puVar29[2] = (uchar)(local_30 >> 0x10);
        puVar29[3] = (uchar)(local_30 >> 0x18);
        puVar29[4] = (uchar)local_2c;
        puVar29[5] = (uchar)(local_2c >> 8);
        puVar29[6] = (uchar)(local_2c >> 0x10);
        puVar29[7] = (uchar)(local_2c >> 0x18);
        puVar29 = puVar29 + 8;
      } while (-1 < (int)uVar31);
      uVar31 = uVar34 >> 3;
      uVar34 = (length + -0x10) - (uVar34 & 0xfffffff8);
      iVar18 = (uVar31 + 1) * 8;
      local_40 = input + iVar18;
      local_48 = output + iVar18;
    }
    if (uVar34 == 0xfffffff8) {
      uVar32 = (uchar)local_30;
      uVar30 = (uchar)(local_30 >> 8);
      uVar16 = (uchar)(local_30 >> 0x10);
      uVar28 = (uchar)local_2c;
      uVar25 = (uchar)(local_2c >> 8);
      uVar19 = (uchar)(local_30 >> 0x18);
      uVar17 = (uchar)(local_2c >> 0x10);
      uVar22 = (uchar)(local_2c >> 0x18);
      goto LAB_0011dc42;
    }
    puVar29 = local_40 + uVar34 + 8;
    switch(uVar34) {
    default:
      uVar31 = 0;
      uVar34 = uVar31;
      goto LAB_0011dca0;
    case 0xfffffff9:
      uVar31 = 0;
      uVar34 = uVar31;
      goto LAB_0011dc9a;
    case 0xfffffffa:
      uVar31 = 0;
      uVar34 = uVar31;
      goto LAB_0011dc90;
    case 0xfffffffb:
      uVar31 = 0;
      uVar34 = uVar31;
      goto LAB_0011dc86;
    case 0xfffffffc:
      uVar31 = 0;
      goto LAB_0011dc7e;
    case 0xfffffffd:
      uVar31 = 0;
      goto LAB_0011dc76;
    case 0xfffffffe:
      uVar31 = 0;
      break;
    case 0xffffffff:
      pbVar27 = puVar29 + -1;
      puVar29 = puVar29 + -1;
      uVar31 = (uint)*pbVar27 << 0x10;
    }
    pbVar27 = puVar29 + -1;
    puVar29 = puVar29 + -1;
    uVar31 = uVar31 | (uint)*pbVar27 << 8;
LAB_0011dc76:
    pbVar27 = puVar29 + -1;
    puVar29 = puVar29 + -1;
    uVar31 = uVar31 | *pbVar27;
LAB_0011dc7e:
    pbVar27 = puVar29 + -1;
    puVar29 = puVar29 + -1;
    uVar34 = (uint)*pbVar27 << 0x18;
LAB_0011dc86:
    pbVar27 = puVar29 + -1;
    puVar29 = puVar29 + -1;
    uVar34 = uVar34 | (uint)*pbVar27 << 0x10;
LAB_0011dc90:
    pbVar27 = puVar29 + -1;
    puVar29 = puVar29 + -1;
    uVar34 = uVar34 | (uint)*pbVar27 << 8;
LAB_0011dc9a:
    uVar34 = uVar34 | puVar29[-1];
LAB_0011dca0:
    local_30 = uVar34 ^ local_30 ^ uVar20;
    local_2c = local_2c ^ uVar33 ^ uVar31;
    DES_encrypt1(&local_30,schedule,1);
    uVar26 = uVar26 ^ local_30;
    uVar32 = (uchar)uVar26;
    local_2c = local_2c ^ uVar21;
    *local_48 = uVar32;
    uVar19 = (uchar)(uVar26 >> 0x18);
    local_48[3] = uVar19;
    uVar30 = (uchar)(uVar26 >> 8);
    local_48[1] = uVar30;
    uVar16 = (uchar)(uVar26 >> 0x10);
    local_48[2] = uVar16;
    uVar28 = (uchar)local_2c;
    local_48[4] = uVar28;
    uVar22 = (uchar)(local_2c >> 0x18);
    local_48[7] = uVar22;
    uVar25 = (uchar)(local_2c >> 8);
    local_48[5] = uVar25;
    uVar17 = (uchar)(local_2c >> 0x10);
    local_48[6] = uVar17;
LAB_0011dc42:
    (*ivec)[0] = uVar32;
    (*ivec)[1] = uVar30;
    (*ivec)[2] = uVar16;
    (*ivec)[3] = uVar19;
    (*ivec)[4] = uVar28;
    (*ivec)[5] = uVar25;
    (*ivec)[6] = uVar17;
    (*ivec)[7] = uVar22;
    return;
  }
  iVar18 = length + -8;
  uVar31 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
           (uint)(*ivec)[3] << 0x18;
  uVar34 = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
           (uint)(*ivec)[7] << 0x18;
  if (0 < iVar18) {
    pbVar27 = input;
    puVar29 = output;
    uVar23 = uVar34;
    uVar35 = uVar31;
    do {
      pbVar1 = pbVar27 + 2;
      iVar18 = iVar18 + -8;
      pbVar4 = pbVar27 + 1;
      pbVar5 = pbVar27 + 6;
      pbVar2 = pbVar27 + 5;
      bVar8 = *pbVar27;
      pbVar6 = pbVar27 + 3;
      pbVar3 = pbVar27 + 4;
      pbVar7 = pbVar27 + 7;
      pbVar27 = pbVar27 + 8;
      uVar31 = (uint)*pbVar1 << 0x10 | (uint)*pbVar4 << 8 | (uint)bVar8 | (uint)*pbVar6 << 0x18;
      uVar34 = (uint)*pbVar5 << 0x10 | (uint)*pbVar2 << 8 | (uint)*pbVar3 | (uint)*pbVar7 << 0x18;
      local_30 = uVar31 ^ uVar26;
      local_2c = uVar34 ^ uVar21;
      DES_encrypt1(&local_30,schedule,0);
      uVar35 = uVar20 ^ local_30 ^ uVar35;
      *puVar29 = (uchar)uVar35;
      uVar23 = uVar33 ^ local_2c ^ uVar23;
      puVar29[1] = (uchar)(uVar35 >> 8);
      puVar29[4] = (uchar)uVar23;
      puVar29[2] = (uchar)(uVar35 >> 0x10);
      puVar29[3] = (uchar)(uVar35 >> 0x18);
      puVar29[5] = (uchar)(uVar23 >> 8);
      puVar29[6] = (uchar)(uVar23 >> 0x10);
      puVar29[7] = (uchar)(uVar23 >> 0x18);
      puVar29 = puVar29 + 8;
      uVar23 = uVar34;
      uVar35 = uVar31;
    } while (0 < iVar18);
    iVar18 = (length + -0x10) - (length - 9U & 0xfffffff8);
    iVar24 = ((length - 9U >> 3) + 1) * 8;
    local_40 = input + iVar24;
    local_48 = output + iVar24;
  }
  bVar8 = local_40[2];
  bVar9 = local_40[6];
  bVar10 = local_40[1];
  bVar11 = local_40[5];
  bVar12 = *local_40;
  bVar13 = local_40[3];
  bVar14 = local_40[7];
  bVar15 = local_40[4];
  local_30 = ((uint)bVar12 | (uint)bVar8 << 0x10 | (uint)bVar10 << 8 | (uint)bVar13 << 0x18) ^
             uVar26;
  local_2c = ((uint)bVar15 | (uint)bVar9 << 0x10 | (uint)bVar11 << 8 | (uint)bVar14 << 0x18) ^
             uVar21;
  DES_encrypt1(&local_30,schedule,0);
  local_48 = local_48 + iVar18 + 8;
  uVar31 = uVar20 ^ local_30 ^ uVar31;
  uVar34 = local_2c ^ uVar33 ^ uVar34;
  puVar29 = local_48;
  switch(iVar18) {
  case 0:
    local_48[-1] = (uchar)(uVar34 >> 0x18);
    local_48 = local_48 + -1;
  case -1:
    local_48[-1] = (uchar)(uVar34 >> 0x10);
    puVar29 = local_48 + -1;
  case -2:
    local_48 = puVar29 + -1;
    puVar29[-1] = (uchar)(uVar34 >> 8);
    break;
  default:
    goto switchD_0011db96_caseD_8;
  case -7:
    goto LAB_0011dbe4;
  case -6:
    goto switchD_0011db96_caseD_fffffffa;
  case -5:
    goto LAB_0011dbd0;
  case -4:
    goto switchD_0011db96_caseD_fffffffc;
  case -3:
  }
  puVar29 = local_48 + -1;
  local_48[-1] = (uchar)uVar34;
switchD_0011db96_caseD_fffffffc:
  local_48 = puVar29 + -1;
  puVar29[-1] = (uchar)(uVar31 >> 0x18);
LAB_0011dbd0:
  puVar29 = local_48 + -1;
  local_48[-1] = (uchar)(uVar31 >> 0x10);
switchD_0011db96_caseD_fffffffa:
  local_48 = puVar29 + -1;
  puVar29[-1] = (uchar)(uVar31 >> 8);
LAB_0011dbe4:
  local_48[-1] = (uchar)uVar31;
switchD_0011db96_caseD_8:
  (*ivec)[0] = bVar12;
  (*ivec)[4] = bVar15;
  (*ivec)[1] = bVar10;
  (*ivec)[2] = bVar8;
  (*ivec)[3] = bVar13;
  (*ivec)[5] = bVar11;
  (*ivec)[6] = bVar9;
  (*ivec)[7] = bVar14;
  return;
}

