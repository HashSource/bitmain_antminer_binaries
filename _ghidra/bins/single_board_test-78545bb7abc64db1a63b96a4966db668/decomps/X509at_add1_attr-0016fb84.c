
stack_st_X509_ATTRIBUTE * X509at_add1_attr(stack_st_X509_ATTRIBUTE **x,X509_ATTRIBUTE *attr)

{
  X509_ATTRIBUTE *a;
  int iVar1;
  stack_st_X509_ATTRIBUTE *psVar2;
  
  if (x == (stack_st_X509_ATTRIBUTE **)0x0) {
    ERR_put_error(0xb,0x87,0x43,"crypto/x509/x509_att.c",0x50);
    psVar2 = (stack_st_X509_ATTRIBUTE *)0x0;
    a = (X509_ATTRIBUTE *)0x0;
    goto LAB_0016fbd0;
  }
  psVar2 = *x;
  if (psVar2 == (stack_st_X509_ATTRIBUTE *)0x0) {
    psVar2 = (stack_st_X509_ATTRIBUTE *)OPENSSL_sk_new_null();
    if (psVar2 != (stack_st_X509_ATTRIBUTE *)0x0) goto LAB_0016fb90;
    a = (X509_ATTRIBUTE *)0x0;
  }
  else {
LAB_0016fb90:
    a = X509_ATTRIBUTE_dup(attr);
    if (a == (X509_ATTRIBUTE *)0x0) goto LAB_0016fbd0;
    iVar1 = OPENSSL_sk_push(psVar2,a);
    if (iVar1 != 0) {
      if (*x != (stack_st_X509_ATTRIBUTE *)0x0) {
        return psVar2;
      }
      *x = psVar2;
      return psVar2;
    }
  }
  ERR_put_error(0xb,0x87,0x41,"crypto/x509/x509_att.c",0x62);
LAB_0016fbd0:
  X509_ATTRIBUTE_free(a);
  OPENSSL_sk_free(psVar2);
  return (stack_st_X509_ATTRIBUTE *)0x0;
}

