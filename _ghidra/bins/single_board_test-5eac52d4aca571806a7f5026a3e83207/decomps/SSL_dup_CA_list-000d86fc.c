
stack_st_X509_NAME * SSL_dup_CA_list(stack_st_X509_NAME *sk)

{
  int iVar1;
  stack_st_X509_NAME *psVar2;
  X509_NAME *pXVar3;
  int iVar4;
  
  iVar1 = OPENSSL_sk_num();
  psVar2 = (stack_st_X509_NAME *)OPENSSL_sk_new_reserve(0,iVar1);
  if (psVar2 == (stack_st_X509_NAME *)0x0) {
    ERR_put_error(0x14,0x198,0x41,"ssl/ssl_cert.c",0x1d0);
  }
  else if (0 < iVar1) {
    iVar4 = 0;
    do {
      pXVar3 = (X509_NAME *)OPENSSL_sk_value(sk,iVar4);
      pXVar3 = X509_NAME_dup(pXVar3);
      iVar4 = iVar4 + 1;
      if (pXVar3 == (X509_NAME *)0x0) {
        ERR_put_error(0x14,0x198,0x41,"ssl/ssl_cert.c",0x1d6);
        OPENSSL_sk_pop_free(psVar2,0x169841);
        return (stack_st_X509_NAME *)0x0;
      }
      OPENSSL_sk_push(psVar2,pXVar3);
    } while (iVar1 != iVar4);
  }
  return psVar2;
}

