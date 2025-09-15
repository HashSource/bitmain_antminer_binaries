
int ASN1_STRING_print(BIO *bp,ASN1_STRING *v)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  uchar *puVar7;
  byte abStack_70 [84];
  
  if (v == (ASN1_STRING *)0x0) {
LAB_000b83fa:
    iVar6 = 0;
  }
  else {
    iVar6 = v->length;
    puVar7 = v->data;
    if (0 < iVar6) {
      iVar2 = 0;
      iVar3 = iVar2;
      do {
        while( true ) {
          bVar4 = puVar7[iVar2];
          uVar5 = (uint)bVar4;
          if (uVar5 < 0x7f) {
            iVar1 = uVar5 - 10;
            if (iVar1 != 0) {
              iVar1 = 1;
            }
            if (0x1f < uVar5) {
              iVar1 = 0;
            }
            if ((iVar1 != 0) && (uVar5 != 0xd)) {
              bVar4 = 0x2e;
            }
          }
          else {
            bVar4 = 0x2e;
          }
          iVar2 = iVar2 + 1;
          iVar1 = iVar3 + 1;
          abStack_70[iVar3] = bVar4;
          if (iVar1 < 0x50) break;
          iVar6 = BIO_write(bp,abStack_70,iVar1);
          iVar1 = 0;
          if (iVar6 < 1) goto LAB_000b83fa;
          iVar6 = v->length;
          iVar3 = 0;
          if (iVar6 <= iVar2) goto LAB_000b83de;
        }
        iVar3 = iVar1;
      } while (iVar2 < iVar6);
LAB_000b83de:
      if (iVar1 != 0) {
        iVar6 = BIO_write(bp,abStack_70,iVar1);
        if (0 < iVar6) {
          return 1;
        }
        return 0;
      }
    }
    iVar6 = 1;
  }
  return iVar6;
}

