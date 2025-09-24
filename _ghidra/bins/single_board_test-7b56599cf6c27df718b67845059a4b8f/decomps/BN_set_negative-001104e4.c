
void BN_set_negative(BIGNUM *b,int n)

{
  int iVar1;
  
  if ((n != 0) && (iVar1 = BN_is_zero(), iVar1 == 0)) {
    b->neg = 1;
    return;
  }
  b->neg = 0;
  return;
}

