
int ASN1_STRING_print(BIO *bp,ASN1_STRING *v)

{
  int iVar1;
  int len;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte abStack_70 [84];
  
  if (v == (ASN1_STRING *)0x0) {
    return 0;
  }
  iVar3 = v->length;
  if (0 < iVar3) {
    pbVar5 = v->data + -1;
    iVar4 = 0;
    iVar1 = 0;
    do {
      while( true ) {
        pbVar5 = pbVar5 + 1;
        bVar2 = *pbVar5;
        if (bVar2 < 0x7f) {
          if (bVar2 != 0xd && (bVar2 != 10 && bVar2 < 0x20)) {
            bVar2 = 0x2e;
          }
        }
        else {
          bVar2 = 0x2e;
        }
        iVar4 = iVar4 + 1;
        len = iVar1 + 1;
        abStack_70[iVar1] = bVar2;
        if (len < 0x50) break;
        iVar3 = BIO_write(bp,abStack_70,len);
        len = 0;
        if (iVar3 < 1) {
          return 0;
        }
        iVar3 = v->length;
        iVar1 = 0;
        if (iVar3 <= iVar4) goto LAB_00189c06;
      }
      iVar1 = len;
    } while (iVar4 < iVar3);
LAB_00189c06:
    if (len != 0) {
      iVar3 = BIO_write(bp,abStack_70,len);
      return (uint)(0 < iVar3);
    }
  }
  return 1;
}

