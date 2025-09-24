
X509_ATTRIBUTE * X509at_get_attr(stack_st_X509_ATTRIBUTE *x,int loc)

{
  int iVar1;
  X509_ATTRIBUTE *pXVar2;
  undefined4 extraout_r2;
  undefined4 in_r3;
  
  if (x == (stack_st_X509_ATTRIBUTE *)0x0) {
    return (X509_ATTRIBUTE *)0x0;
  }
  iVar1 = OPENSSL_sk_num();
  if (iVar1 <= loc || loc < 0) {
    return (X509_ATTRIBUTE *)0x0;
  }
  pXVar2 = (X509_ATTRIBUTE *)OPENSSL_sk_value(x,loc,extraout_r2,in_r3);
  return pXVar2;
}

