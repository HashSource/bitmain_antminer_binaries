
BIGNUM * ec_GFp_simple_point_copy(int param_1,int param_2)

{
  BIGNUM *pBVar1;
  
  pBVar1 = BN_copy((BIGNUM *)(param_1 + 4),(BIGNUM *)(param_2 + 4));
  if ((pBVar1 != (BIGNUM *)0x0) &&
     (pBVar1 = BN_copy((BIGNUM *)(param_1 + 0x18),(BIGNUM *)(param_2 + 0x18)),
     pBVar1 != (BIGNUM *)0x0)) {
    pBVar1 = BN_copy((BIGNUM *)(param_1 + 0x2c),(BIGNUM *)(param_2 + 0x2c));
    if (pBVar1 != (BIGNUM *)0x0) {
      pBVar1 = (BIGNUM *)0x1;
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
    }
    return pBVar1;
  }
  return (BIGNUM *)0x0;
}

