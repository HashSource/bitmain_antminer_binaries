
stack_st_X509_EXTENSION * X509v3_add_ext(stack_st_X509_EXTENSION **x,X509_EXTENSION *ex,int loc)

{
  int iVar1;
  X509_EXTENSION *a;
  stack_st_X509_EXTENSION *psVar2;
  
  if (x == (stack_st_X509_EXTENSION **)0x0) {
    ERR_put_error(0xb,0x68,0x43,"crypto/x509/x509_v3.c",0x68);
    X509_EXTENSION_free((X509_EXTENSION *)0x0);
    return (stack_st_X509_EXTENSION *)0x0;
  }
  psVar2 = *x;
  if ((psVar2 == (stack_st_X509_EXTENSION *)0x0) &&
     (psVar2 = (stack_st_X509_EXTENSION *)OPENSSL_sk_new_null(),
     psVar2 == (stack_st_X509_EXTENSION *)0x0)) {
    a = (X509_EXTENSION *)0x0;
  }
  else {
    iVar1 = OPENSSL_sk_num(psVar2);
    if (iVar1 < loc || loc < 0) {
      loc = iVar1;
    }
    a = X509_EXTENSION_dup(ex);
    if (a == (X509_EXTENSION *)0x0) goto LAB_00163f9a;
    iVar1 = OPENSSL_sk_insert(psVar2,a,loc);
    if (iVar1 != 0) {
      if (*x != (stack_st_X509_EXTENSION *)0x0) {
        return psVar2;
      }
      *x = psVar2;
      return psVar2;
    }
  }
  ERR_put_error(0xb,0x68,0x41,"crypto/x509/x509_v3.c",0x80);
LAB_00163f9a:
  X509_EXTENSION_free(a);
  if (*x == (stack_st_X509_EXTENSION *)0x0) {
    OPENSSL_sk_free(psVar2);
  }
  return (stack_st_X509_EXTENSION *)0x0;
}

