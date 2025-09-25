
size_t EC_GROUP_set_seed(EC_GROUP *param_1,uchar *param_2,size_t len)

{
  size_t sVar1;
  void *__dest;
  
  CRYPTO_free(*(void **)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (param_2 == (uchar *)0x0 || len == 0) {
    sVar1 = 1;
  }
  else {
    __dest = CRYPTO_malloc(len,"crypto/ec/ec_lib.c",0x1e8);
    *(void **)(param_1 + 0x20) = __dest;
    if (__dest != (void *)0x0) {
      memcpy(__dest,param_2,len);
      *(size_t *)(param_1 + 0x24) = len;
      return len;
    }
    ERR_put_error(0x10,0x11e,0x41,"crypto/ec/ec_lib.c",0x1e9);
    sVar1 = 0;
  }
  return sVar1;
}

