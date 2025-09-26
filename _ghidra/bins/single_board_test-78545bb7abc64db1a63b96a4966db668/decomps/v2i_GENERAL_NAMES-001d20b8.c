
GENERAL_NAMES *
v2i_GENERAL_NAMES(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,stack_st_CONF_VALUE *nval)

{
  int iVar1;
  GENERAL_NAMES *pGVar2;
  CONF_VALUE *cnf;
  GENERAL_NAME *pGVar3;
  int iVar4;
  
  iVar1 = OPENSSL_sk_num(nval);
  pGVar2 = (GENERAL_NAMES *)OPENSSL_sk_new_reserve(0,iVar1);
  if (pGVar2 == (GENERAL_NAMES *)0x0) {
    ERR_put_error(0x22,0x76,0x41,"crypto/x509v3/v3_alt.c",0x197);
    OPENSSL_sk_free(0);
  }
  else if (0 < iVar1) {
    iVar4 = 0;
    do {
      cnf = (CONF_VALUE *)OPENSSL_sk_value(nval,iVar4);
      iVar4 = iVar4 + 1;
      pGVar3 = v2i_GENERAL_NAME(method,ctx,cnf);
      if (pGVar3 == (GENERAL_NAME *)0x0) {
        OPENSSL_sk_pop_free(pGVar2,0x17f325);
        return (GENERAL_NAMES *)0x0;
      }
      OPENSSL_sk_push(pGVar2);
    } while (iVar1 != iVar4);
  }
  return pGVar2;
}

