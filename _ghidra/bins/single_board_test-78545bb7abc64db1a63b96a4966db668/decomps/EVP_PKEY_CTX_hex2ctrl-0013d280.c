
undefined4 EVP_PKEY_CTX_hex2ctrl(int *param_1,undefined4 param_2,undefined4 param_3)

{
  void *ptr;
  undefined4 uVar1;
  undefined4 local_1c [2];
  
  ptr = (void *)OPENSSL_hexstr2buf(param_3,local_1c);
  if (ptr != (void *)0x0) {
    uVar1 = (**(code **)(*param_1 + 100))(param_1,param_2,local_1c[0],ptr);
    CRYPTO_free(ptr);
    return uVar1;
  }
  return 0;
}

