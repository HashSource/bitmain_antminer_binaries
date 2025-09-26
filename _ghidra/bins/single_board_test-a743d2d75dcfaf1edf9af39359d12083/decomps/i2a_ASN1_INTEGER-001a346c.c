
int i2a_ASN1_INTEGER(BIO *bp,ASN1_INTEGER *a)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char local_24;
  char local_23;
  
  if (a == (ASN1_INTEGER *)0x0) {
    return 0;
  }
  if ((a->type & 0x100U) == 0) {
    iVar3 = 2;
    iVar2 = a->length;
    iVar4 = 0;
  }
  else {
    iVar4 = BIO_write(bp,&DAT_002075c8,1);
    if (iVar4 != 1) {
      return -1;
    }
    iVar3 = 3;
    iVar2 = a->length;
    iVar4 = 1;
  }
  if (iVar2 == 0) {
    iVar4 = BIO_write(bp,"00",2);
    if (iVar4 == 2) {
      return iVar3;
    }
  }
  else {
    if (iVar2 < 1) {
      return iVar4;
    }
    iVar3 = 0;
    do {
      do {
        iVar5 = iVar4;
        iVar4 = iVar5 + 2;
        local_24 = "0123456789ABCDEF"[a->data[iVar3] >> 4];
        pbVar1 = a->data + iVar3;
        iVar3 = iVar3 + 1;
        local_23 = "0123456789ABCDEF"[*pbVar1 & 0xf];
        iVar2 = BIO_write(bp,&local_24,2);
        if (iVar2 != 2) {
          return -1;
        }
        if (a->length <= iVar3) {
          return iVar4;
        }
      } while ((iVar3 == 0) || (iVar3 != (iVar3 / 0x23) * 0x23));
      iVar2 = BIO_write(bp,&DAT_00224858,2);
      iVar4 = iVar5 + 4;
    } while (iVar2 == 2);
  }
  return -1;
}

