
void BN_free(BIGNUM *a)

{
  uint uVar1;
  bool bVar2;
  
  if (a != (BIGNUM *)0x0) {
    uVar1 = a->flags;
    if ((a->d != (ulong *)0x0) && (-1 < (int)(uVar1 << 0x1e))) {
      CRYPTO_free(a->d);
      uVar1 = a->flags;
    }
    bVar2 = (uVar1 & 1) == 0;
    if (bVar2) {
      uVar1 = uVar1 | 0x8000;
      a->d = (ulong *)0x0;
    }
    if (!bVar2) {
      CRYPTO_free(a);
      return;
    }
    a->flags = uVar1;
  }
  return;
}

