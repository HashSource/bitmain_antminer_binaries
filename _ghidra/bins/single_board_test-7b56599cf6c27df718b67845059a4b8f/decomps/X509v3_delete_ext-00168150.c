
X509_EXTENSION * X509v3_delete_ext(stack_st_X509_EXTENSION *x,int loc)

{
  int iVar1;
  X509_EXTENSION *pXVar2;
  undefined4 extraout_r2;
  undefined4 in_r3;
  
  if (x == (stack_st_X509_EXTENSION *)0x0) {
    return (X509_EXTENSION *)0x0;
  }
  iVar1 = OPENSSL_sk_num();
  if (iVar1 <= loc || loc < 0) {
    return (X509_EXTENSION *)0x0;
  }
  pXVar2 = (X509_EXTENSION *)OPENSSL_sk_delete(x,loc,extraout_r2,in_r3);
  return pXVar2;
}

