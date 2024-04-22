
BN_BLINDING * BN_BLINDING_new(BIGNUM *A,BIGNUM *Ai,BIGNUM *mod)

{
  BIGNUM **__s;
  BIGNUM *pBVar1;
  uint uVar2;
  bool bVar3;
  
  __s = (BIGNUM **)CRYPTO_malloc(0x2c,DAT_000f25ac,0x8d);
  if (__s == (BIGNUM **)0x0) {
    ERR_put_error(3,0x66,0x41,DAT_000f25ac,0x8e);
    return (BN_BLINDING *)0x0;
  }
  memset(__s,0,0x2c);
  if (A != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(A);
    *__s = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_000f2578;
  }
  if (Ai == (BIGNUM *)0x0) {
LAB_000f2544:
    pBVar1 = BN_dup(mod);
    __s[3] = pBVar1;
    if (pBVar1 != (BIGNUM *)0x0) {
      uVar2 = mod->flags << 0x1d;
      bVar3 = (int)uVar2 < 0;
      if (bVar3) {
        uVar2 = pBVar1->flags | 4;
      }
      if (bVar3) {
        pBVar1->flags = uVar2;
      }
      __s[7] = (BIGNUM *)0xffffffff;
      CRYPTO_THREADID_current((CRYPTO_THREADID *)(__s + 5));
      return (BN_BLINDING *)__s;
    }
  }
  else {
    pBVar1 = BN_dup(Ai);
    __s[1] = pBVar1;
    if (pBVar1 != (BIGNUM *)0x0) goto LAB_000f2544;
  }
  if (*__s != (BIGNUM *)0x0) {
    BN_free(*__s);
  }
LAB_000f2578:
  if (__s[1] != (BIGNUM *)0x0) {
    BN_free(__s[1]);
  }
  if (__s[2] != (BIGNUM *)0x0) {
    BN_free(__s[2]);
  }
  if (__s[3] != (BIGNUM *)0x0) {
    BN_free(__s[3]);
  }
  CRYPTO_free(__s);
  return (BN_BLINDING *)0x0;
}

