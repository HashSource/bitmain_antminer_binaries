
BN_BLINDING * BN_BLINDING_new(BIGNUM *A,BIGNUM *Ai,BIGNUM *mod)

{
  BN_BLINDING *__s;
  BIGNUM *pBVar1;
  uint uVar2;
  bool bVar3;
  
  __s = (BN_BLINDING *)CRYPTO_malloc(0x2c,"bn_blind.c",0x8d);
  if (__s == (BN_BLINDING *)0x0) {
    ERR_put_error(3,0x66,0x41,"bn_blind.c",0x8e);
    return (BN_BLINDING *)0x0;
  }
  memset(__s,0,0x2c);
  if (A != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(A);
    *(BIGNUM **)__s = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_000f2578;
  }
  if (Ai == (BIGNUM *)0x0) {
LAB_000f2544:
    pBVar1 = BN_dup(mod);
    *(BIGNUM **)(__s + 0xc) = pBVar1;
    if (pBVar1 != (BIGNUM *)0x0) {
      uVar2 = mod->flags << 0x1d;
      bVar3 = (int)uVar2 < 0;
      if (bVar3) {
        uVar2 = pBVar1->flags | 4;
      }
      if (bVar3) {
        pBVar1->flags = uVar2;
      }
      *(undefined4 *)(__s + 0x1c) = 0xffffffff;
      CRYPTO_THREADID_current((CRYPTO_THREADID *)(__s + 0x14));
      return __s;
    }
  }
  else {
    pBVar1 = BN_dup(Ai);
    *(BIGNUM **)(__s + 4) = pBVar1;
    if (pBVar1 != (BIGNUM *)0x0) goto LAB_000f2544;
  }
  if (*(BIGNUM **)__s != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)__s);
  }
LAB_000f2578:
  if (*(BIGNUM **)(__s + 4) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(__s + 4));
  }
  if (*(BIGNUM **)(__s + 8) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(__s + 8));
  }
  if (*(BIGNUM **)(__s + 0xc) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(__s + 0xc));
  }
  CRYPTO_free(__s);
  return (BN_BLINDING *)0x0;
}

