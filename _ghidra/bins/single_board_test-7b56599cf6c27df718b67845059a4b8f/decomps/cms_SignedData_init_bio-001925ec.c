
BIO * cms_SignedData_init_bio(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  BIO *append;
  int *piVar3;
  BIO_METHOD *pBVar4;
  BIO *pBVar5;
  int iVar6;
  BIO *a;
  
  iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*param_1);
  if (iVar1 == 0x16) {
    pBVar5 = (BIO *)param_1[1];
    if (pBVar5 != (BIO *)0x0) {
      if (*(int *)(pBVar5->cb_arg + 8) != 0) {
        for (iVar1 = 0; iVar2 = OPENSSL_sk_num(pBVar5->init), iVar1 < iVar2; iVar1 = iVar1 + 1) {
          piVar3 = (int *)OPENSSL_sk_value(pBVar5->init,iVar1);
          iVar2 = *piVar3;
          if (iVar2 == 4) {
            if ((int)pBVar5->method < 5) {
              pBVar5->method = (BIO_METHOD *)0x5;
            }
          }
          else if (iVar2 == 3) {
            if ((int)pBVar5->method < 4) {
              pBVar5->method = (BIO_METHOD *)0x4;
            }
          }
          else if ((iVar2 == 2) && ((int)pBVar5->method < 3)) {
            pBVar5->method = (BIO_METHOD *)0x3;
          }
        }
        iVar1 = 0;
        while( true ) {
          iVar2 = OPENSSL_sk_num(pBVar5->shutdown);
          iVar6 = iVar1 + 1;
          if (iVar2 <= iVar1) break;
          piVar3 = (int *)OPENSSL_sk_value(pBVar5->shutdown,iVar1);
          iVar1 = iVar6;
          if ((*piVar3 == 1) && ((int)pBVar5->method < 5)) {
            pBVar5->method = (BIO_METHOD *)0x5;
          }
        }
        iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)pBVar5->cb_arg);
        if ((iVar1 != 0x15) && ((int)pBVar5->method < 3)) {
          pBVar5->method = (BIO_METHOD *)0x3;
        }
        for (iVar1 = 0; iVar2 = OPENSSL_sk_num(pBVar5->flags), iVar1 < iVar2; iVar1 = iVar1 + 1) {
          piVar3 = (int *)OPENSSL_sk_value(pBVar5->flags,iVar1);
          if (*(int *)piVar3[1] == 1) {
            pBVar4 = pBVar5->method;
            if (*piVar3 < 3) {
              *piVar3 = 3;
            }
            if ((int)pBVar4 < 3) {
              pBVar5->method = (BIO_METHOD *)0x3;
            }
          }
          else if (*piVar3 < 1) {
            *piVar3 = 1;
          }
        }
        if ((int)pBVar5->method < 1) {
          pBVar5->method = (BIO_METHOD *)0x1;
        }
      }
      iVar1 = 0;
      a = (BIO *)0x0;
      while( true ) {
        iVar2 = OPENSSL_sk_num(pBVar5->callback);
        if (iVar2 <= iVar1) {
          return a;
        }
        OPENSSL_sk_value(pBVar5->callback,iVar1);
        append = (BIO *)cms_DigestAlgorithm_init_bio();
        if (append == (BIO *)0x0) break;
        if (a != (BIO *)0x0) {
          BIO_push(a,append);
          append = a;
        }
        iVar1 = iVar1 + 1;
        a = append;
      }
      BIO_free_all(a);
      return (BIO *)0x0;
    }
  }
  else {
    ERR_put_error(0x2e,0x85,0x6c,"crypto/cms/cms_sd.c",0x1a);
    pBVar5 = (BIO *)0x0;
  }
  return pBVar5;
}

