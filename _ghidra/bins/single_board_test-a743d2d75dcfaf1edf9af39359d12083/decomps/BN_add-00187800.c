
int BN_add(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  BIGNUM *a_00;
  int iVar1;
  int iVar2;
  
  iVar2 = b->neg;
  if (iVar2 == a->neg) {
    iVar1 = BN_uadd(r,a,b);
    r->neg = iVar2;
    return iVar1;
  }
  if (a->neg == 0) {
    iVar2 = BN_ucmp(a,b);
    a_00 = b;
    b = a;
  }
  else {
    iVar2 = BN_ucmp(b,a);
    a_00 = a;
  }
  if (iVar2 < 0) {
    iVar2 = BN_usub(r,a_00,b);
    if (iVar2 != 0) {
      r->neg = 1;
      return 1;
    }
  }
  else {
    iVar2 = BN_usub(r,b,a_00);
    if (iVar2 != 0) {
      r->neg = 0;
      return 1;
    }
  }
  return 0;
}

