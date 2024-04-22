
int X509_CERT_AUX_print(BIO *bp,X509_CERT_AUX *x,int indent)

{
  byte *pbVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ASN1_OBJECT *pAVar5;
  int iVar6;
  undefined4 uVar7;
  ASN1_OCTET_STRING *pAVar8;
  stack_st_ASN1_OBJECT *psVar9;
  int iVar10;
  char acStack_68 [80];
  
  if (x != (X509_CERT_AUX *)0x0) {
    if (x->trust == (stack_st_ASN1_OBJECT *)0x0) {
      BIO_printf(bp,DAT_000b8f74,indent,DAT_000b8f54);
      psVar9 = x->reject;
    }
    else {
      bVar2 = true;
      BIO_printf(bp,DAT_000b8f58,indent,DAT_000b8f54,indent + 2,DAT_000b8f54);
      for (iVar10 = 0; iVar6 = sk_num(&x->trust->stack), iVar10 < iVar6; iVar10 = iVar10 + 1) {
        if (!bVar2) {
          BIO_puts(bp,DAT_000b8f5c);
        }
        pAVar5 = (ASN1_OBJECT *)sk_value(&x->trust->stack,iVar10);
        bVar2 = false;
        OBJ_obj2txt(acStack_68,0x50,pAVar5,0);
        BIO_puts(bp,acStack_68);
      }
      BIO_puts(bp,DAT_000b8f60);
      psVar9 = x->reject;
    }
    if (psVar9 == (stack_st_ASN1_OBJECT *)0x0) {
      BIO_printf(bp,DAT_000b8f78,indent,DAT_000b8f54);
    }
    else {
      BIO_printf(bp,DAT_000b8f70,indent,DAT_000b8f54,indent + 2,DAT_000b8f54);
      bVar2 = true;
      for (iVar10 = 0; iVar6 = sk_num(&x->reject->stack), iVar10 < iVar6; iVar10 = iVar10 + 1) {
        if (!bVar2) {
          BIO_puts(bp,DAT_000b8f5c);
        }
        pAVar5 = (ASN1_OBJECT *)sk_value(&x->reject->stack,iVar10);
        bVar2 = false;
        OBJ_obj2txt(acStack_68,0x50,pAVar5,0);
        BIO_puts(bp,acStack_68);
      }
      BIO_puts(bp,DAT_000b8f60);
    }
    if (x->alias != (ASN1_UTF8STRING *)0x0) {
      BIO_printf(bp,DAT_000b8f64,indent,DAT_000b8f54,x->alias->data);
    }
    if (x->keyid != (ASN1_OCTET_STRING *)0x0) {
      BIO_printf(bp,DAT_000b8f68,indent,DAT_000b8f54);
      uVar4 = DAT_000b8f7c;
      uVar3 = DAT_000b8f54;
      pAVar8 = x->keyid;
      if (0 < pAVar8->length) {
        iVar10 = 0;
        uVar7 = uVar3;
        while( true ) {
          pbVar1 = pAVar8->data + iVar10;
          iVar10 = iVar10 + 1;
          BIO_printf(bp,DAT_000b8f6c,uVar7,(uint)*pbVar1);
          pAVar8 = x->keyid;
          if (pAVar8->length <= iVar10) break;
          uVar7 = uVar4;
          if (iVar10 == 0) {
            uVar7 = uVar3;
          }
        }
      }
      BIO_write(bp,DAT_000b8f60,1);
    }
    return 1;
  }
  return 1;
}

