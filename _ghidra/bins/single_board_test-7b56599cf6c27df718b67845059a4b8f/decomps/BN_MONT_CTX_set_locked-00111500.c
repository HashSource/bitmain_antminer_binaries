
BN_MONT_CTX * BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont,int lock,BIGNUM *mod,BN_CTX *ctx)

{
  int iVar1;
  BN_MONT_CTX *mont;
  
  CRYPTO_THREAD_read_lock(lock);
  mont = *pmont;
  CRYPTO_THREAD_unlock(lock);
  if ((mont == (BN_MONT_CTX *)0x0) && (mont = BN_MONT_CTX_new(), mont != (BN_MONT_CTX *)0x0)) {
    iVar1 = BN_MONT_CTX_set(mont,mod,ctx);
    if (iVar1 != 0) {
      CRYPTO_THREAD_write_lock(lock);
      if (*pmont == (BN_MONT_CTX *)0x0) {
        *pmont = mont;
      }
      else {
        BN_MONT_CTX_free(mont);
        mont = *pmont;
      }
      CRYPTO_THREAD_unlock(lock);
      return mont;
    }
    BN_MONT_CTX_free(mont);
    return (BN_MONT_CTX *)0x0;
  }
  return mont;
}

