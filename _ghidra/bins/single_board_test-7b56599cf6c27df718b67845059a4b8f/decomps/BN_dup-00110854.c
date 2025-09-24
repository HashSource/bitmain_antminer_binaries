
BIGNUM * BN_dup(BIGNUM *a)

{
  int iVar1;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  
  if (a != (BIGNUM *)0x0) {
    iVar1 = BN_get_flags(a,8);
    if (iVar1 == 0) {
      a_00 = BN_new();
    }
    else {
      a_00 = (BIGNUM *)BN_secure_new();
    }
    if (a_00 != (BIGNUM *)0x0) {
      pBVar2 = BN_copy(a_00,a);
      if (pBVar2 != (BIGNUM *)0x0) {
        return a_00;
      }
      BN_free(a_00);
      return (BIGNUM *)0x0;
    }
  }
  return (BIGNUM *)0x0;
}

