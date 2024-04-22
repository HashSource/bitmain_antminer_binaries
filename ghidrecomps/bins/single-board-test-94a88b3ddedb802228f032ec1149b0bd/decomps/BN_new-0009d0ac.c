
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BIGNUM * BN_new(void)

{
  BIGNUM *pBVar1;
  
  pBVar1 = (BIGNUM *)CRYPTO_malloc(0x14,DAT_0009d0e8,0x110);
  if (pBVar1 == (BIGNUM *)0x0) {
    ERR_put_error(3,0x71,0x41,DAT_0009d0e8,0x111);
  }
  else {
    pBVar1->flags = 1;
    pBVar1->top = 0;
    pBVar1->neg = 0;
    pBVar1->dmax = 0;
    pBVar1->d = (ulong *)0x0;
  }
  return pBVar1;
}

