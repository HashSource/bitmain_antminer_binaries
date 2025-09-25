
int BN_sub(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = a->neg;
  if (uVar2 == b->neg) {
    iVar1 = BN_ucmp(a,b);
    if (0 < iVar1) {
      iVar3 = a->neg;
      iVar1 = BN_usub(r,a,b);
      r->neg = iVar3;
      return iVar1;
    }
    if (iVar1 == 0) {
      BN_set_word(r,0);
      r->neg = 0;
      return 1;
    }
    uVar2 = (uint)(b->neg == 0);
    iVar1 = BN_usub(r,b,a);
  }
  else {
    iVar1 = BN_uadd(r,a,b);
  }
  r->neg = uVar2;
  return iVar1;
}

