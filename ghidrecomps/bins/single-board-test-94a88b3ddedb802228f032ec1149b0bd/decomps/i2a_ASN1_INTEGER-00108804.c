
int i2a_ASN1_INTEGER(BIO *bp,ASN1_INTEGER *a)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined local_24;
  undefined local_23;
  
  if (a == (ASN1_INTEGER *)0x0) {
    return 0;
  }
  if ((a->type & 0x100U) == 0) {
    iVar4 = 2;
    iVar3 = a->length;
    iVar5 = 0;
    iVar2 = DAT_001088e4;
  }
  else {
    iVar5 = BIO_write(bp,DAT_001088ec,1);
    if (iVar5 != 1) {
      return -1;
    }
    iVar4 = 3;
    iVar3 = a->length;
    iVar5 = 1;
    iVar2 = DAT_001088e4;
  }
  DAT_001088e4 = iVar2;
  if (iVar3 == 0) {
    iVar5 = BIO_write(bp,DAT_001088f0,2);
    if (iVar5 == 2) {
      return iVar4;
    }
  }
  else {
    if (iVar3 < 1) {
      return iVar5;
    }
    iVar4 = 0;
    do {
      do {
        iVar6 = iVar5;
        iVar5 = iVar6 + 2;
        local_24 = *(undefined *)((uint)(a->data[iVar4] >> 4) + iVar2);
        pbVar1 = a->data + iVar4;
        iVar4 = iVar4 + 1;
        local_23 = *(undefined *)((*pbVar1 & 0xf) + iVar2);
        iVar3 = BIO_write(bp,&local_24,2);
        if (iVar3 != 2) {
          return -1;
        }
        if (a->length <= iVar4) {
          return iVar5;
        }
      } while ((iVar4 == 0) || (iVar4 != (iVar4 / 0x23) * 0x23));
      iVar3 = BIO_write(bp,DAT_001088e8,2);
      iVar5 = iVar6 + 4;
    } while (iVar3 == 2);
  }
  return -1;
}

