
int X509_CERT_AUX_print(BIO *bp,X509_CERT_AUX *x,int indent)

{
  byte *pbVar1;
  bool bVar2;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  char *pcVar5;
  ASN1_OCTET_STRING *pAVar6;
  stack_st_ASN1_OBJECT *psVar7;
  int iVar8;
  char acStack_68 [80];
  
  if (x != (X509_CERT_AUX *)0x0) {
    if (x->trust == (stack_st_ASN1_OBJECT *)0x0) {
      BIO_printf(bp,"%*sNo Trusted Uses.\n",indent,&DAT_0013a6fc);
      psVar7 = x->reject;
    }
    else {
      bVar2 = true;
      BIO_printf(bp,"%*sTrusted Uses:\n%*s",indent,&DAT_0013a6fc,indent + 2,&DAT_0013a6fc);
      for (iVar8 = 0; iVar4 = sk_num(&x->trust->stack), iVar8 < iVar4; iVar8 = iVar8 + 1) {
        if (!bVar2) {
          BIO_puts(bp,", ");
        }
        pAVar3 = (ASN1_OBJECT *)sk_value(&x->trust->stack,iVar8);
        bVar2 = false;
        OBJ_obj2txt(acStack_68,0x50,pAVar3,0);
        BIO_puts(bp,acStack_68);
      }
      BIO_puts(bp,"\n");
      psVar7 = x->reject;
    }
    if (psVar7 == (stack_st_ASN1_OBJECT *)0x0) {
      BIO_printf(bp,"%*sNo Rejected Uses.\n",indent,&DAT_0013a6fc);
    }
    else {
      BIO_printf(bp,"%*sRejected Uses:\n%*s",indent,&DAT_0013a6fc,indent + 2,&DAT_0013a6fc);
      bVar2 = true;
      for (iVar8 = 0; iVar4 = sk_num(&x->reject->stack), iVar8 < iVar4; iVar8 = iVar8 + 1) {
        if (!bVar2) {
          BIO_puts(bp,", ");
        }
        pAVar3 = (ASN1_OBJECT *)sk_value(&x->reject->stack,iVar8);
        bVar2 = false;
        OBJ_obj2txt(acStack_68,0x50,pAVar3,0);
        BIO_puts(bp,acStack_68);
      }
      BIO_puts(bp,"\n");
    }
    if (x->alias != (ASN1_UTF8STRING *)0x0) {
      BIO_printf(bp,"%*sAlias: %s\n",indent,&DAT_0013a6fc,x->alias->data);
    }
    if (x->keyid != (ASN1_OCTET_STRING *)0x0) {
      BIO_printf(bp,"%*sKey Id: ",indent,&DAT_0013a6fc);
      pAVar6 = x->keyid;
      if (0 < pAVar6->length) {
        pcVar5 = "";
        iVar8 = 0;
        while( true ) {
          pbVar1 = pAVar6->data + iVar8;
          iVar8 = iVar8 + 1;
          BIO_printf(bp,"%s%02X",pcVar5,(uint)*pbVar1);
          pAVar6 = x->keyid;
          if (pAVar6->length <= iVar8) break;
          if (iVar8 == 0) {
            pcVar5 = "";
          }
          else {
            pcVar5 = ":";
          }
        }
      }
      BIO_write(bp,"\n",1);
    }
    return 1;
  }
  return 1;
}

