
int EC_GROUP_get_order(EC_GROUP *group,BIGNUM *order,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  
  pBVar1 = BN_copy(order,(BIGNUM *)(group + 8));
  if ((pBVar1 != (BIGNUM *)0x0) && (pBVar1 = (BIGNUM *)order->top, pBVar1 != (BIGNUM *)0x0)) {
    pBVar1 = (BIGNUM *)0x1;
  }
  return (int)pBVar1;
}

