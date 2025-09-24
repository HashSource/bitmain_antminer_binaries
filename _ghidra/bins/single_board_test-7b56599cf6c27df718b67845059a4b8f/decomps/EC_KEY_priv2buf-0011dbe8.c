
int EC_KEY_priv2buf(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  void *ptr;
  
  iVar1 = EC_KEY_priv2oct(param_1,0);
  if (iVar1 != 0) {
    ptr = CRYPTO_malloc(iVar1,"crypto/ec/ec_key.c",0x2ad);
    if (ptr == (void *)0x0) {
      ERR_put_error(0x10,0x117,0x41,"crypto/ec/ec_key.c",0x2ae);
      iVar1 = 0;
    }
    else {
      iVar1 = EC_KEY_priv2oct(param_1,ptr,iVar1);
      if (iVar1 != 0) {
        *param_2 = ptr;
        return iVar1;
      }
      CRYPTO_free(ptr);
      iVar1 = 0;
    }
  }
  return iVar1;
}

