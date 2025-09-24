
void BN_clear_free(BIGNUM *a)

{
  int iVar1;
  
  if (a == (BIGNUM *)0x0) {
    return;
  }
  if ((a->d != (ulong *)0x0) && (iVar1 = BN_get_flags(a,2), iVar1 == 0)) {
    iVar1 = BN_get_flags(a,8);
    if (iVar1 == 0) {
      CRYPTO_clear_free(a->d,a->dmax << 2,"crypto/bn/bn_lib.c",0xce);
    }
    else {
      CRYPTO_secure_clear_free(a->d,a->dmax << 2,"crypto/bn/bn_lib.c",0xcc);
    }
  }
  iVar1 = BN_get_flags(a,1);
  if (iVar1 == 0) {
    return;
  }
  OPENSSL_cleanse(a,0x14);
  CRYPTO_free(a);
  return;
}

