
BN_BLINDING * BN_BLINDING_new(BIGNUM *A,BIGNUM *Ai,BIGNUM *mod)

{
  BN_BLINDING *b;
  int iVar1;
  BIGNUM *pBVar2;
  
  b = (BN_BLINDING *)CRYPTO_zalloc(0x28,"crypto/bn/bn_blind.c",0x24);
  if (b == (BN_BLINDING *)0x0) {
    ERR_put_error(3,0x66,0x41,"crypto/bn/bn_blind.c",0x25);
    return (BN_BLINDING *)0x0;
  }
  iVar1 = CRYPTO_THREAD_lock_new();
  *(int *)(b + 0x24) = iVar1;
  if (iVar1 == 0) {
    ERR_put_error(3,0x66,0x41,"crypto/bn/bn_blind.c",0x2b);
    CRYPTO_free(b);
    return (BN_BLINDING *)0x0;
  }
  BN_BLINDING_set_current_thread(b);
  if (A != (BIGNUM *)0x0) {
    pBVar2 = BN_dup(A);
    *(BIGNUM **)b = pBVar2;
    if (pBVar2 == (BIGNUM *)0x0) goto LAB_00188656;
  }
  if (Ai != (BIGNUM *)0x0) {
    pBVar2 = BN_dup(Ai);
    *(BIGNUM **)(b + 4) = pBVar2;
    if (pBVar2 == (BIGNUM *)0x0) goto LAB_00188656;
  }
  pBVar2 = BN_dup(mod);
  *(BIGNUM **)(b + 0xc) = pBVar2;
  if (pBVar2 != (BIGNUM *)0x0) {
    iVar1 = BN_get_flags(mod,4);
    if (iVar1 != 0) {
      BN_set_flags(*(undefined4 *)(b + 0xc),4);
    }
    *(undefined4 *)(b + 0x14) = 0xffffffff;
    return b;
  }
LAB_00188656:
  BN_BLINDING_free(b);
  return (BN_BLINDING *)0x0;
}

