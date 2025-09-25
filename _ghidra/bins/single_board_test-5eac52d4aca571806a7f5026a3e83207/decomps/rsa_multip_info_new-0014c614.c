
int * rsa_multip_info_new(void)

{
  int *ptr;
  BIGNUM *a;
  int iVar1;
  
  ptr = (int *)CRYPTO_zalloc(0x14,"crypto/rsa/rsa_mp.c",0x24);
  if (ptr == (int *)0x0) {
    ERR_put_error(4,0xa6,0x41,"crypto/rsa/rsa_mp.c",0x25);
    return (int *)0x0;
  }
  a = (BIGNUM *)BN_secure_new();
  *ptr = (int)a;
  if (a != (BIGNUM *)0x0) {
    iVar1 = BN_secure_new();
    ptr[1] = iVar1;
    if (iVar1 != 0) {
      iVar1 = BN_secure_new();
      ptr[2] = iVar1;
      if (iVar1 != 0) {
        iVar1 = BN_secure_new();
        ptr[3] = iVar1;
        if (iVar1 != 0) {
          return ptr;
        }
      }
    }
    a = (BIGNUM *)*ptr;
  }
  BN_free(a);
  BN_free((BIGNUM *)ptr[1]);
  BN_free((BIGNUM *)ptr[2]);
  BN_free((BIGNUM *)ptr[3]);
  CRYPTO_free(ptr);
  return (int *)0x0;
}

