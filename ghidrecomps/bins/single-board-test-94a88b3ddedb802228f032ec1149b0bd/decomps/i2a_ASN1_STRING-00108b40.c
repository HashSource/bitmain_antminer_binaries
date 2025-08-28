
int i2a_ASN1_STRING(BIO *bp,ASN1_STRING *a,int type)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char local_24;
  char local_23;
  
  if (a == (ASN1_STRING *)0x0) {
LAB_00108bf2:
    iVar5 = 0;
  }
  else {
    if (a->length == 0) {
      iVar5 = BIO_write(bp,"0",1);
      if (iVar5 == 1) {
        return 1;
      }
    }
    else {
      if (a->length < 1) goto LAB_00108bf2;
      iVar3 = 0;
      iVar5 = 0;
      do {
        do {
          iVar4 = iVar5;
          local_24 = "0123456789ABCDEF"[a->data[iVar3] >> 4];
          pbVar1 = a->data + iVar3;
          iVar3 = iVar3 + 1;
          local_23 = "0123456789ABCDEF"[*pbVar1 & 0xf];
          iVar2 = BIO_write(bp,&local_24,2);
          iVar5 = iVar4 + 2;
          if (iVar2 != 2) goto LAB_00108bd4;
          if (a->length <= iVar3) {
            return iVar5;
          }
        } while ((iVar3 == 0) || (iVar3 != (iVar3 / 0x23) * 0x23));
        iVar2 = BIO_write(bp,&DAT_001767d0,2);
        iVar5 = iVar4 + 4;
      } while (iVar2 == 2);
    }
LAB_00108bd4:
    iVar5 = -1;
  }
  return iVar5;
}

