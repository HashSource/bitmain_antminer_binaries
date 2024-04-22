
BIGNUM * bn_dup_expand(BIGNUM *a,int words)

{
  ulong *ptr;
  BIGNUM *a_00;
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (a->dmax < words) {
    ptr = (ulong *)bn_expand_internal();
    if (ptr == (ulong *)0x0) {
      a_00 = (BIGNUM *)0x0;
    }
    else {
      a_00 = (BIGNUM *)CRYPTO_malloc(0x14,DAT_0009d31c,0x110);
      if (a_00 == (BIGNUM *)0x0) {
        ERR_put_error(3,0x71,0x41,DAT_0009d31c,0x111);
        CRYPTO_free(ptr);
      }
      else {
        a_00->top = 0;
        a_00->neg = 0;
        iVar2 = a->top;
        iVar3 = a->neg;
        a_00->dmax = words;
        a_00->d = ptr;
        a_00->top = iVar2;
        a_00->neg = iVar3;
        a_00->flags = 1;
      }
    }
  }
  else {
    a_00 = (BIGNUM *)CRYPTO_malloc(0x14,DAT_0009d31c,0x110);
    if (a_00 == (BIGNUM *)0x0) {
      ERR_put_error(3,0x71,0x41,DAT_0009d31c,0x111);
    }
    else {
      a_00->flags = 1;
      a_00->top = 0;
      a_00->neg = 0;
      a_00->dmax = 0;
      a_00->d = (ulong *)0x0;
      pBVar1 = BN_copy(a_00,a);
      if (pBVar1 == (BIGNUM *)0x0) {
        uVar4 = a_00->flags;
        if ((a_00->d != (ulong *)0x0) && (-1 < (int)(uVar4 << 0x1e))) {
          CRYPTO_free(a_00->d);
          uVar4 = a_00->flags;
        }
        if ((uVar4 & 1) == 0) {
          a_00->d = (ulong *)0x0;
          a_00->flags = uVar4 | 0x8000;
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

