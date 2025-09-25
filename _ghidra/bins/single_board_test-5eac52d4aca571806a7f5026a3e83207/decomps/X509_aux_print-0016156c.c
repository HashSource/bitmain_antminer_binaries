
undefined4 X509_aux_print(BIO *param_1,X509 *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  ASN1_OBJECT *pAVar4;
  int iVar5;
  uchar *puVar6;
  int local_80;
  int local_7c;
  char acStack_78 [84];
  
  iVar2 = X509_trusted(param_2);
  if (iVar2 != 0) {
    iVar2 = X509_get0_trust_objects(param_2);
    iVar3 = X509_get0_reject_objects(param_2);
    if (iVar2 == 0) {
      BIO_printf(param_1,"%*sNo Trusted Uses.\n",param_3,"");
    }
    else {
      bVar1 = true;
      BIO_printf(param_1,"%*sTrusted Uses:\n%*s",param_3,"",param_3 + 2,"");
      local_7c = 0;
      while (iVar5 = OPENSSL_sk_num(iVar2), local_7c < iVar5) {
        if (!bVar1) {
          BIO_puts(param_1,", ");
        }
        bVar1 = false;
        pAVar4 = (ASN1_OBJECT *)OPENSSL_sk_value(iVar2,local_7c);
        OBJ_obj2txt(acStack_78,0x50,pAVar4,0);
        BIO_puts(param_1,acStack_78);
        local_7c = local_7c + 1;
      }
      BIO_puts(param_1,"\n");
    }
    if (iVar3 == 0) {
      BIO_printf(param_1,"%*sNo Rejected Uses.\n",param_3,"");
    }
    else {
      bVar1 = true;
      BIO_printf(param_1,"%*sRejected Uses:\n%*s",param_3,"",param_3 + 2,"");
      local_7c = 0;
      while (iVar2 = OPENSSL_sk_num(iVar3), local_7c < iVar2) {
        if (!bVar1) {
          BIO_puts(param_1,", ");
        }
        bVar1 = false;
        pAVar4 = (ASN1_OBJECT *)OPENSSL_sk_value(iVar3,local_7c);
        OBJ_obj2txt(acStack_78,0x50,pAVar4,0);
        BIO_puts(param_1,acStack_78);
        local_7c = local_7c + 1;
      }
      BIO_puts(param_1,"\n");
    }
    puVar6 = X509_alias_get0(param_2,&local_7c);
    if (puVar6 != (uchar *)0x0) {
      BIO_printf(param_1,"%*sAlias: %.*s\n",param_3,"",local_7c,puVar6);
    }
    puVar6 = X509_keyid_get0(param_2,&local_80);
    if (puVar6 != (uchar *)0x0) {
      BIO_printf(param_1,"%*sKey Id: ",param_3,"");
      local_7c = 0;
      if (0 < local_80) {
        do {
          BIO_printf(param_1,"%s%02X");
          local_7c = local_7c + 1;
        } while (local_7c < local_80);
      }
      BIO_write(param_1,"\n",1);
      return 1;
    }
  }
  return 1;
}

