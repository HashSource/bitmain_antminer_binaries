
ASN1_INTEGER * c2i_ASN1_INTEGER(ASN1_INTEGER **a,uchar **pp,long length)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar4;
  byte *pbVar5;
  ASN1_INTEGER *str;
  int iVar6;
  uint uVar7;
  int local_2c [2];
  byte *pbVar3;
  
  if (length == 0) {
    ERR_put_error(0xd,0xe2,0xde,"crypto/asn1/a_int.c",0x9a);
    return (ASN1_INTEGER *)0x0;
  }
  if (length == 1) {
    iVar6 = 1;
  }
  else {
    pbVar5 = *pp;
    bVar1 = *pbVar5;
    if (bVar1 == 0) {
LAB_0017e5ec:
      if ((bVar1 & 0x80) == (pbVar5[1] & 0x80)) {
        ERR_put_error(0xd,0xe2,0xdd,"crypto/asn1/a_int.c",0xbb);
        return (ASN1_INTEGER *)0x0;
      }
      uVar4 = 1;
    }
    else if (bVar1 == 0xff) {
      if ((uint)length < 0x22) {
        uVar4 = 0;
        iVar6 = 1;
      }
      else {
        uVar4 = 0;
        iVar6 = 1;
        pbVar3 = pbVar5 + 0x23;
        do {
          uVar7 = iVar6 + 0x21;
          iVar6 = iVar6 + 0x20;
          HintPreloadData(pbVar3);
          uVar4 = uVar4 | (byte)(pbVar3[-0xf] |
                                 pbVar3[-0x10] |
                                 pbVar3[-0x11] |
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
                                 pbVar3[-0x21] | pbVar3[-0x22] | pbVar3[-0x20] | pbVar3[-0x1f] |
                                 pbVar3[-0x1e] | pbVar3[-0xe] | pbVar3[-0xd] | pbVar3[-0xc] |
                                 pbVar3[-0xb] | pbVar3[-10] | pbVar3[-9] | pbVar3[-8] | pbVar3[-7] |
                                 pbVar3[-6] | pbVar3[-5] | pbVar3[-4] | pbVar3[-3]);
          pbVar3 = pbVar3 + 0x20;
        } while (uVar7 < length - 0x1fU);
      }
      pbVar3 = pbVar5 + iVar6;
      do {
        pbVar2 = pbVar3 + 1;
        uVar4 = uVar4 | *pbVar3;
        pbVar3 = pbVar2;
      } while ((uint)((int)pbVar2 - (int)pbVar5) < (uint)length);
      if (uVar4 != 0) goto LAB_0017e5ec;
    }
    else {
      uVar4 = 0;
    }
    iVar6 = length - uVar4;
  }
  if ((a == (ASN1_INTEGER **)0x0) || (str = *a, str == (ASN1_STRING *)0x0)) {
    str = ASN1_INTEGER_new();
    if (str == (ASN1_INTEGER *)0x0) {
      return (ASN1_INTEGER *)0x0;
    }
    str->type = 2;
    iVar6 = ASN1_STRING_set(str,(void *)0x0,iVar6);
    if (iVar6 != 0) {
      c2i_ibuf(str->data,local_2c,*pp,length);
      if (local_2c[0] != 0) goto LAB_0017e628;
      goto LAB_0017e630;
    }
    ERR_put_error(0xd,0xc2,0x41,"crypto/asn1/a_int.c",0x139);
    if (a == (ASN1_INTEGER **)0x0) goto LAB_0017e5c8;
  }
  else {
    iVar6 = ASN1_STRING_set(str,(void *)0x0,iVar6);
    if (iVar6 != 0) {
      c2i_ibuf(str->data,local_2c,*pp,length);
      if (local_2c[0] == 0) {
        *pp = *pp + length;
        goto LAB_0017e63c;
      }
LAB_0017e628:
      str->type = str->type | 0x100;
LAB_0017e630:
      *pp = *pp + length;
      if (a == (ASN1_INTEGER **)0x0) {
        return str;
      }
LAB_0017e63c:
      *a = str;
      return str;
    }
    ERR_put_error(0xd,0xc2,0x41,"crypto/asn1/a_int.c",0x139);
  }
  if (*a == str) {
    return (ASN1_INTEGER *)0x0;
  }
LAB_0017e5c8:
  ASN1_INTEGER_free(str);
  return (ASN1_INTEGER *)0x0;
}

