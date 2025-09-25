
void BN_CTX_free(BN_CTX *c)

{
  BIGNUM *pBVar1;
  BIGNUM *a;
  BIGNUM *pBVar2;
  
  if (c == (BN_CTX *)0x0) {
    return;
  }
  CRYPTO_free(*(void **)(c + 0x14));
  pBVar1 = *(BIGNUM **)c;
  *(undefined4 *)(c + 0x14) = 0;
  while (pBVar1 != (BIGNUM *)0x0) {
    a = pBVar1;
    do {
      pBVar2 = a + 1;
      if (a->d != (ulong *)0x0) {
        BN_clear_free(a);
      }
      a = pBVar2;
    } while (pBVar2 != pBVar1 + 0x10);
    *(undefined4 *)(c + 4) = *(undefined4 *)((int)*(void **)c + 0x144);
    CRYPTO_free(*(void **)c);
    pBVar1 = *(BIGNUM **)(c + 4);
    *(BIGNUM **)c = pBVar1;
  }
  CRYPTO_free(c);
  return;
}

