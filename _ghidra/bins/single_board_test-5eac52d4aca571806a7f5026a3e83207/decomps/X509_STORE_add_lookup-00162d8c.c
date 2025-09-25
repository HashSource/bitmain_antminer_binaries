
X509_LOOKUP * X509_STORE_add_lookup(X509_STORE *v,X509_LOOKUP_METHOD *m)

{
  int iVar1;
  X509_LOOKUP *pXVar2;
  int iVar3;
  stack_st_X509_LOOKUP *psVar4;
  
  psVar4 = v->get_cert_methods;
  iVar3 = 0;
  while( true ) {
    iVar1 = OPENSSL_sk_num(psVar4);
    if (iVar1 <= iVar3) break;
    pXVar2 = (X509_LOOKUP *)OPENSSL_sk_value(psVar4,iVar3);
    iVar3 = iVar3 + 1;
    if (pXVar2->method == m) {
      return pXVar2;
    }
  }
  pXVar2 = X509_LOOKUP_new(m);
  if (pXVar2 == (X509_LOOKUP *)0x0) {
    ERR_put_error(0xb,0x9d,0x41,"crypto/x509/x509_lu.c",0x105);
    return (X509_LOOKUP *)0x0;
  }
  pXVar2->store_ctx = v;
  iVar3 = OPENSSL_sk_push(v->get_cert_methods,pXVar2);
  if (iVar3 != 0) {
    return pXVar2;
  }
  ERR_put_error(0xb,0x9d,0x41,"crypto/x509/x509_lu.c",0x10d);
  X509_LOOKUP_free(pXVar2);
  return (X509_LOOKUP *)0x0;
}

