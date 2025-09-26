
int v2i_issuer_alt(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  GENERAL_NAME *pGVar3;
  CONF_VALUE *cnf;
  int iVar4;
  X509_EXTENSION *ext;
  void *pvVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  iVar1 = OPENSSL_sk_num(param_3);
  iVar2 = OPENSSL_sk_new_reserve(0,iVar1);
  if (iVar2 == 0) {
    ERR_put_error(0x22,0x99,0x41,"crypto/x509v3/v3_alt.c",0xe6);
    OPENSSL_sk_free(0);
  }
  else if (0 < iVar1) {
    iVar8 = 0;
    do {
      cnf = (CONF_VALUE *)OPENSSL_sk_value(param_3,iVar8);
      iVar4 = name_cmp(cnf->name,"issuer");
      if (((iVar4 == 0) && (cnf->value != (char *)0x0)) &&
         (iVar4 = strcmp(cnf->value,"copy"), iVar4 == 0)) {
        if (param_2 == (X509V3_CTX *)0x0) {
LAB_001d1da2:
          ERR_put_error(0x22,0x7b,0x7f,"crypto/x509v3/v3_alt.c",0x10b);
LAB_001d1db6:
          OPENSSL_sk_pop_free(iVar2,0x17f325);
          return 0;
        }
        if (param_2->flags != 1) {
          if (param_2->issuer_cert == (X509 *)0x0) goto LAB_001d1da2;
          iVar4 = X509_get_ext_by_NID(param_2->issuer_cert,0x55,-1);
          if (-1 < iVar4) {
            ext = X509_get_ext(param_2->issuer_cert,iVar4);
            if ((ext == (X509_EXTENSION *)0x0) ||
               (pvVar5 = X509V3_EXT_d2i(ext), pvVar5 == (void *)0x0)) {
              ERR_put_error(0x22,0x7b,0x7e,"crypto/x509v3/v3_alt.c",0x113);
              goto LAB_001d1db6;
            }
            iVar4 = OPENSSL_sk_num();
            iVar6 = OPENSSL_sk_reserve(iVar2,iVar4);
            if (iVar6 == 0) {
              ERR_put_error(0x22,0x7b,0x41,"crypto/x509v3/v3_alt.c",0x119);
              OPENSSL_sk_free(pvVar5);
              goto LAB_001d1db6;
            }
            if (0 < iVar4) {
              iVar6 = 0;
              do {
                uVar7 = OPENSSL_sk_value(pvVar5,iVar6);
                iVar6 = iVar6 + 1;
                OPENSSL_sk_push(iVar2,uVar7);
              } while (iVar4 != iVar6);
            }
            OPENSSL_sk_free(pvVar5);
          }
        }
      }
      else {
        pGVar3 = v2i_GENERAL_NAME(param_1,param_2,cnf);
        if (pGVar3 == (GENERAL_NAME *)0x0) goto LAB_001d1db6;
        OPENSSL_sk_push(iVar2,pGVar3);
      }
      iVar8 = iVar8 + 1;
    } while (iVar1 != iVar8);
  }
  return iVar2;
}

