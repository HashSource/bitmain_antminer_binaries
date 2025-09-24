
size_t CRYPTO_128_unwrap(undefined4 param_1,undefined4 *param_2,void *param_3,undefined4 param_4,
                        undefined4 param_5,undefined4 param_6)

{
  size_t len;
  int iVar1;
  undefined1 auStack_20 [12];
  
  len = crypto_128_unwrap_raw(param_1,auStack_20,param_3,param_4,param_5,param_6);
  if (len != 0) {
    if (param_2 == (undefined4 *)0x0) {
      param_2 = &default_iv;
    }
    iVar1 = CRYPTO_memcmp(auStack_20,param_2,8);
    if (iVar1 == 0) {
      return len;
    }
    OPENSSL_cleanse(param_3,len);
  }
  return 0;
}

