
BIGNUM * BN_dup(BIGNUM *a)

{
  BIGNUM *a_00;
  BIGNUM *pBVar1;
  uint uVar2;
  
  if (a == (BIGNUM *)0x0) {
    a_00 = (BIGNUM *)0x0;
  }
  else {
    a_00 = (BIGNUM *)CRYPTO_malloc(0x14,DAT_0009d248,0x110);
    if (a_00 == (BIGNUM *)0x0) {
      ERR_put_error(3,0x71,0x41,DAT_0009d248,0x111);
    }
    else {
      a_00->flags = 1;
      a_00->top = 0;
      a_00->neg = 0;
      a_00->dmax = 0;
      a_00->d = (ulong *)0x0;
      pBVar1 = BN_copy(a_00,a);
      if (pBVar1 == (BIGNUM *)0x0) {
        uVar2 = a_00->flags;
        if ((a_00->d != (ulong *)0x0) && (-1 < (int)(uVar2 << 0x1e))) {
          CRYPTO_free(a_00->d);
          uVar2 = a_00->flags;
        }
        if ((uVar2 & 1) == 0) {
          a_00->d = (ulong *)0x0;
          a_00->flags = uVar2 | 0x8000;
          a_00 = (BIGNUM *)0x0;
        }
        else {
          CRYPTO_free(a_00);
          a_00 = (BIGNUM *)0x0;
        }
      }
    }
  }
  return a_00;
}

