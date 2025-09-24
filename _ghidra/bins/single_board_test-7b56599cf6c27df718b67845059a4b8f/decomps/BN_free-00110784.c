
void BN_free(BIGNUM *a)

{
  int iVar1;
  
  if (a == (BIGNUM *)0x0) {
    return;
  }
  iVar1 = BN_get_flags(a,2);
  if (iVar1 == 0) {
    iVar1 = BN_get_flags(a,8);
    if (iVar1 == 0) {
      CRYPTO_free(a->d);
    }
    else {
      CRYPTO_secure_clear_free(a->d,a->dmax << 2,"crypto/bn/bn_lib.c",0xcc);
    }
  }
  if (-1 < a->flags << 0x1f) {
    return;
  }
  CRYPTO_free(a);
  return;
}

