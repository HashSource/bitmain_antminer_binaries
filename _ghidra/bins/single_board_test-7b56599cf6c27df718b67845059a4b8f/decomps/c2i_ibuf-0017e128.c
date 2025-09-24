
uint c2i_ibuf(byte *param_1,uint *param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  
  if (param_4 == 0) {
    ERR_put_error(0xd,0xe2,0xde,"crypto/asn1/a_int.c",0x9a);
    return 0;
  }
  bVar1 = *param_3;
  if (param_2 != (uint *)0x0) {
    *param_2 = bVar1 & 0x80;
  }
  if (param_4 == 1) {
    if (param_1 == (byte *)0x0) {
      return 1;
    }
    if ((bVar1 & 0x80) == 0) {
      *param_1 = *param_3;
      return 1;
    }
    *param_1 = -*param_3;
    return 1;
  }
  if (*param_3 == 0) {
LAB_0017e148:
    if ((bVar1 & 0x80) == (param_3[1] & 0x80)) {
      ERR_put_error(0xd,0xe2,0xdd,"crypto/asn1/a_int.c",0xbb);
      return 0;
    }
    if (param_1 == (byte *)0x0) {
      return param_4 - 1;
    }
    if ((bVar1 & 0x80) == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0xff;
    }
    iVar2 = param_4 - 2;
    uVar6 = param_4 - 1;
  }
  else {
    if (*param_3 == 0xff) {
      if (param_4 < 0x22) {
        iVar2 = 1;
        bVar8 = 0;
      }
      else {
        iVar2 = 1;
        bVar8 = 0;
        pbVar3 = param_3 + 0x23;
        do {
          iVar2 = iVar2 + 0x20;
          HintPreloadData(pbVar3);
          pbVar4 = pbVar3 + 0x20;
          bVar8 = bVar8 | pbVar3[-0x11] |
                          pbVar3[-0x12] |
                          pbVar3[-0x13] |
                          pbVar3[-0x14] |
                          pbVar3[-0x15] |
                          pbVar3[-0x16] |
                          pbVar3[-0x17] |
                          pbVar3[-0x18] |
                          pbVar3[-0x19] |
                          pbVar3[-0x1a] |
                          pbVar3[-0x1b] |
                          pbVar3[-0x1c] |
                          pbVar3[-0x1d] |
                          pbVar3[-0x1e] |
                          pbVar3[-0x1f] | pbVar3[-0x22] | pbVar3[-0x21] | pbVar3[-0x20] |
                          pbVar3[-0x10] | pbVar3[-0xf] | pbVar3[-0xe] | pbVar3[-0xd] | pbVar3[-0xc]
                          | pbVar3[-0xb] | pbVar3[-10] | pbVar3[-9] | pbVar3[-8] | pbVar3[-7] |
                          pbVar3[-6] | pbVar3[-5] | pbVar3[-4] | pbVar3[-3];
          pbVar3 = pbVar4;
        } while (param_3 + (param_4 - 0x22 & 0xffffffe0) + 0x43 != pbVar4);
      }
      pbVar3 = param_3 + iVar2;
      do {
        pbVar4 = pbVar3 + 1;
        bVar8 = bVar8 | *pbVar3;
        pbVar3 = pbVar4;
      } while ((uint)((int)pbVar4 - (int)param_3) < param_4);
      if (bVar8 != 0) goto LAB_0017e148;
    }
    if (param_1 == (byte *)0x0) {
      return param_4;
    }
    if ((bVar1 & 0x80) == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0xff;
    }
    iVar2 = param_4 - 1;
    uVar6 = param_4;
  }
  param_1 = param_1 + uVar6;
  uVar5 = uVar7 & 1;
  pbVar3 = param_3 + (param_4 - 1);
  do {
    pbVar4 = pbVar3 + -1;
    uVar5 = uVar5 + (*pbVar3 ^ uVar7);
    param_1 = param_1 + -1;
    *param_1 = (byte)uVar5;
    uVar5 = uVar5 >> 8;
    pbVar3 = pbVar4;
  } while (param_3 + (param_4 - iVar2) + -2 != pbVar4);
  return uVar6;
}

