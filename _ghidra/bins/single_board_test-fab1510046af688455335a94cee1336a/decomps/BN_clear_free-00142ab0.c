
void BN_clear_free(BIGNUM *a)

{
  int iVar1;
  
  if (a == (BIGNUM *)0x0) {
    return;
  }
  if (a->d != (ulong *)0x0) {
    OPENSSL_cleanse(a->d,a->dmax << 2);
    iVar1 = a->flags;
    if (iVar1 << 0x1e < 0) goto LAB_00142ac8;
    CRYPTO_free(a->d);
  }
  iVar1 = a->flags;
LAB_00142ac8:
  OPENSSL_cleanse(a,0x14);
  if (-1 < iVar1 << 0x1f) {
    return;
  }
  CRYPTO_free(a);
  return;
}

