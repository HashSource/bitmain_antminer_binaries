
int BN_add(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  int iVar2;
  
  iVar2 = a->neg;
  if (iVar2 == b->neg) {
    iVar1 = BN_uadd(r,a,b);
    r->neg = iVar2;
    return iVar1;
  }
  iVar2 = BN_ucmp(a,b);
  if (iVar2 < 1) {
    if (iVar2 == 0) {
      BN_set_word(r,0);
      iVar1 = 1;
      iVar2 = 0;
    }
    else {
      iVar2 = b->neg;
      iVar1 = BN_usub(r,b,a);
    }
    r->neg = iVar2;
    return iVar1;
  }
  iVar1 = a->neg;
  iVar2 = BN_usub(r,a,b);
  r->neg = iVar1;
  return iVar2;
}

