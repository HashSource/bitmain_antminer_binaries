
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
  uchar uVar9;
  uchar uVar10;
  int iVar11;
  uchar uVar12;
  uint uVar13;
  uint uVar14;
  uchar uVar15;
  uint uVar16;
  int iVar17;
  uchar uVar18;
  uint uVar19;
  byte *pbVar20;
  uchar uVar21;
  uchar *puVar22;
  uchar uVar23;
  uint uVar24;
  uchar uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uchar *local_48;
  byte *local_40;
  uint local_30;
  uint local_2c;
  
  uVar13 = (uint)(*inw)[2] << 0x10 | (uint)(*inw)[1] << 8 | (uint)(*inw)[0] |
           (uint)(*inw)[3] << 0x18;
  uVar26 = (uint)(*inw)[6] << 0x10 | (uint)(*inw)[5] << 8 | (uint)(*inw)[4] |
           (uint)(*inw)[7] << 0x18;
  uVar19 = (uint)(*outw)[2] << 0x10 | (uint)(*outw)[1] << 8 | (uint)(*outw)[0] |
           (uint)(*outw)[3] << 0x18;
  uVar14 = (uint)(*outw)[4] | (uint)(*outw)[6] << 0x10 | (uint)(*outw)[5] << 8 |
           (uint)(*outw)[7] << 0x18;
  local_48 = output;
  local_40 = input;
  if (enc == 0) {
    iVar11 = length + -8;
    uVar24 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
             (uint)(*ivec)[3] << 0x18;
    uVar27 = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
             (uint)(*ivec)[7] << 0x18;
    if (0 < iVar11) {
      pbVar20 = input;
      puVar22 = output;
      uVar16 = uVar27;
      uVar28 = uVar24;
      do {
        pbVar1 = pbVar20 + 2;
        iVar11 = iVar11 + -8;
        pbVar4 = pbVar20 + 1;
        pbVar5 = pbVar20 + 6;
        pbVar2 = pbVar20 + 5;
        bVar8 = *pbVar20;
        pbVar6 = pbVar20 + 3;
        pbVar3 = pbVar20 + 4;
        pbVar7 = pbVar20 + 7;
        pbVar20 = pbVar20 + 8;
        uVar24 = (uint)*pbVar1 << 0x10 | (uint)*pbVar4 << 8 | (uint)bVar8 | (uint)*pbVar6 << 0x18;
        uVar27 = (uint)*pbVar5 << 0x10 | (uint)*pbVar2 << 8 | (uint)*pbVar3 | (uint)*pbVar7 << 0x18;
        local_30 = uVar24 ^ uVar19;
        local_2c = uVar27 ^ uVar14;
        DES_encrypt1(&local_30,schedule,0);
        uVar28 = uVar13 ^ local_30 ^ uVar28;
        *puVar22 = (uchar)uVar28;
        uVar16 = uVar26 ^ local_2c ^ uVar16;
        puVar22[1] = (uchar)(uVar28 >> 8);
        puVar22[4] = (uchar)uVar16;
        puVar22[2] = (uchar)(uVar28 >> 0x10);
        puVar22[3] = (uchar)(uVar28 >> 0x18);
        puVar22[5] = (uchar)(uVar16 >> 8);
        puVar22[6] = (uchar)(uVar16 >> 0x10);
        puVar22[7] = (uchar)(uVar16 >> 0x18);
        puVar22 = puVar22 + 8;
        uVar16 = uVar27;
        uVar28 = uVar24;
      } while (0 < iVar11);
      uVar16 = length - 9U >> 3;
      iVar11 = length + -0x10 + uVar16 * -8;
      iVar17 = (uVar16 + 1) * 8;
      local_40 = input + iVar17;
      local_48 = output + iVar17;
    }
    uVar16 = uVar27;
    uVar28 = uVar24;
    if (iVar11 == -8) goto switchD_0011db96_default;
    uVar28 = (uint)*local_40 | (uint)local_40[2] << 0x10 | (uint)local_40[1] << 8 |
             (uint)local_40[3] << 0x18;
    uVar16 = (uint)local_40[4] | (uint)local_40[6] << 0x10 | (uint)local_40[5] << 8 |
             (uint)local_40[7] << 0x18;
    local_30 = uVar28 ^ uVar19;
    local_2c = uVar16 ^ uVar14;
    DES_encrypt1(&local_30,schedule,0);
    local_48 = local_48 + iVar11 + 8;
    uVar24 = uVar13 ^ local_30 ^ uVar24;
    uVar27 = local_2c ^ uVar26 ^ uVar27;
    puVar22 = local_48;
    switch(iVar11) {
    case 0:
      local_48[-1] = (uchar)(uVar27 >> 0x18);
      local_48 = local_48 + -1;
    case -1:
      local_48[-1] = (uchar)(uVar27 >> 0x10);
      puVar22 = local_48 + -1;
    case -2:
      local_48 = puVar22 + -1;
      puVar22[-1] = (uchar)(uVar27 >> 8);
      break;
    case -7:
      goto LAB_0011dbe4;
    case -6:
      goto switchD_0011db96_caseD_fffffffa;
    case -5:
      goto LAB_0011dbd0;
    case -4:
      goto switchD_0011db96_caseD_fffffffc;
    case -3:
      break;
    default:
      goto switchD_0011db96_default;
    }
    puVar22 = local_48 + -1;
    local_48[-1] = (uchar)uVar27;
switchD_0011db96_caseD_fffffffc:
    local_48 = puVar22 + -1;
    puVar22[-1] = (uchar)(uVar24 >> 0x18);
LAB_0011dbd0:
    puVar22 = local_48 + -1;
    local_48[-1] = (uchar)(uVar24 >> 0x10);
switchD_0011db96_caseD_fffffffa:
    local_48 = puVar22 + -1;
    puVar22[-1] = (uchar)(uVar24 >> 8);
LAB_0011dbe4:
    local_48[-1] = (uchar)uVar24;
switchD_0011db96_default:
    (*ivec)[0] = (uchar)uVar28;
    (*ivec)[4] = (uchar)uVar16;
    (*ivec)[1] = (uchar)(uVar28 >> 8);
    (*ivec)[2] = (uchar)(uVar28 >> 0x10);
    (*ivec)[3] = (uchar)(uVar28 >> 0x18);
    (*ivec)[5] = (uchar)(uVar16 >> 8);
    (*ivec)[6] = (uchar)(uVar16 >> 0x10);
    (*ivec)[7] = (uchar)(uVar16 >> 0x18);
    return;
  }
  uVar27 = length - 8;
  local_30 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] |
             (uint)(*ivec)[3] << 0x18;
  local_2c = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] |
             (uint)(*ivec)[7] << 0x18;
  if (-1 < (int)uVar27) {
    pbVar20 = input;
    puVar22 = output;
    uVar24 = uVar27;
    do {
      pbVar1 = pbVar20 + 2;
      pbVar6 = pbVar20 + 1;
      pbVar2 = pbVar20 + 6;
      pbVar3 = pbVar20 + 5;
      pbVar4 = pbVar20 + 3;
      bVar8 = *pbVar20;
      pbVar7 = pbVar20 + 7;
      pbVar5 = pbVar20 + 4;
      pbVar20 = pbVar20 + 8;
      local_30 = ((uint)*pbVar1 << 0x10 | (uint)*pbVar6 << 8 | (uint)bVar8 | (uint)*pbVar4 << 0x18)
                 ^ uVar13 ^ local_30;
      local_2c = ((uint)*pbVar2 << 0x10 | (uint)*pbVar3 << 8 | (uint)*pbVar5 | (uint)*pbVar7 << 0x18
                 ) ^ uVar26 ^ local_2c;
      DES_encrypt1(&local_30,schedule,1);
      uVar24 = uVar24 - 8;
      local_30 = uVar19 ^ local_30;
      *puVar22 = (uchar)local_30;
      local_2c = uVar14 ^ local_2c;
      puVar22[1] = (uchar)(local_30 >> 8);
      puVar22[2] = (uchar)(local_30 >> 0x10);
      puVar22[3] = (uchar)(local_30 >> 0x18);
      puVar22[4] = (uchar)local_2c;
      puVar22[5] = (uchar)(local_2c >> 8);
      puVar22[6] = (uchar)(local_2c >> 0x10);
      puVar22[7] = (uchar)(local_2c >> 0x18);
      puVar22 = puVar22 + 8;
    } while (-1 < (int)uVar24);
    uVar24 = uVar27 >> 3;
    uVar27 = length + -0x10 + uVar24 * -8;
    iVar11 = (uVar24 + 1) * 8;
    local_40 = input + iVar11;
    local_48 = output + iVar11;
  }
  if (uVar27 == 0xfffffff8) {
    uVar25 = (uchar)local_30;
    uVar23 = (uchar)(local_30 >> 8);
    uVar9 = (uchar)(local_30 >> 0x10);
    uVar21 = (uchar)local_2c;
    uVar18 = (uchar)(local_2c >> 8);
    uVar12 = (uchar)(local_30 >> 0x18);
    uVar10 = (uchar)(local_2c >> 0x10);
    uVar15 = (uchar)(local_2c >> 0x18);
    goto LAB_0011dc42;
  }
  puVar22 = local_40 + uVar27 + 8;
  switch(uVar27) {
  case 0xfffffff9:
    uVar24 = 0;
    uVar27 = uVar24;
    goto LAB_0011dc9a;
  case 0xfffffffa:
    uVar24 = 0;
    uVar27 = uVar24;
    goto LAB_0011dc90;
  case 0xfffffffb:
    uVar24 = 0;
    uVar27 = uVar24;
    goto LAB_0011dc86;
  case 0xfffffffc:
    uVar24 = 0;
    goto LAB_0011dc7e;
  case 0xfffffffd:
    uVar24 = 0;
    goto LAB_0011dc76;
  case 0xfffffffe:
    uVar24 = 0;
    break;
  case 0xffffffff:
    pbVar20 = puVar22 + -1;
    puVar22 = puVar22 + -1;
    uVar24 = (uint)*pbVar20 << 0x10;
    break;
  default:
    uVar24 = 0;
    uVar27 = uVar24;
    goto LAB_0011dca0;
  }
  pbVar20 = puVar22 + -1;
  puVar22 = puVar22 + -1;
  uVar24 = uVar24 | (uint)*pbVar20 << 8;
LAB_0011dc76:
  pbVar20 = puVar22 + -1;
  puVar22 = puVar22 + -1;
  uVar24 = uVar24 | *pbVar20;
LAB_0011dc7e:
  pbVar20 = puVar22 + -1;
  puVar22 = puVar22 + -1;
  uVar27 = (uint)*pbVar20 << 0x18;
LAB_0011dc86:
  pbVar20 = puVar22 + -1;
  puVar22 = puVar22 + -1;
  uVar27 = uVar27 | (uint)*pbVar20 << 0x10;
LAB_0011dc90:
  pbVar20 = puVar22 + -1;
  puVar22 = puVar22 + -1;
  uVar27 = uVar27 | (uint)*pbVar20 << 8;
LAB_0011dc9a:
  uVar27 = uVar27 | puVar22[-1];
LAB_0011dca0:
  local_30 = uVar27 ^ local_30 ^ uVar13;
  local_2c = local_2c ^ uVar26 ^ uVar24;
  DES_encrypt1(&local_30,schedule,1);
  uVar19 = uVar19 ^ local_30;
  uVar25 = (uchar)uVar19;
  local_2c = local_2c ^ uVar14;
  *local_48 = uVar25;
  uVar12 = (uchar)(uVar19 >> 0x18);
  local_48[3] = uVar12;
  uVar23 = (uchar)(uVar19 >> 8);
  local_48[1] = uVar23;
  uVar9 = (uchar)(uVar19 >> 0x10);
  local_48[2] = uVar9;
  uVar21 = (uchar)local_2c;
  local_48[4] = uVar21;
  uVar15 = (uchar)(local_2c >> 0x18);
  local_48[7] = uVar15;
  uVar18 = (uchar)(local_2c >> 8);
  local_48[5] = uVar18;
  uVar10 = (uchar)(local_2c >> 0x10);
  local_48[6] = uVar10;
LAB_0011dc42:
  (*ivec)[0] = uVar25;
  (*ivec)[1] = uVar23;
  (*ivec)[2] = uVar9;
  (*ivec)[3] = uVar12;
  (*ivec)[4] = uVar21;
  (*ivec)[5] = uVar18;
  (*ivec)[6] = uVar10;
  (*ivec)[7] = uVar15;
  return;
}

