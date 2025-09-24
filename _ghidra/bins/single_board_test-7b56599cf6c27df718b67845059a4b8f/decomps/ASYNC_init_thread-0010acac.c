
undefined4 ASYNC_init_thread(uint param_1,uint param_2)

{
  int iVar1;
  int *ptr;
  void *pvVar2;
  
  if (param_1 < param_2) {
    ERR_put_error(0x33,0x65,0x67,"crypto/async/async.c",0x142);
    return 0;
  }
  iVar1 = OPENSSL_init_crypto(0x100,0,0);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = ossl_init_thread_start(1,0);
  if (iVar1 == 0) {
    return 0;
  }
  ptr = (int *)CRYPTO_zalloc(0xc,"crypto/async/async.c",0x14c);
  if (ptr == (int *)0x0) {
    ERR_put_error(0x33,0x65,0x41,"crypto/async/async.c",0x14e);
    return 0;
  }
  iVar1 = OPENSSL_sk_new_reserve(0,param_2);
  *ptr = iVar1;
  if (iVar1 == 0) {
    ERR_put_error(0x33,0x65,0x41,"crypto/async/async.c",0x154);
    CRYPTO_free(ptr);
    return 0;
  }
  ptr[2] = param_1;
  if (param_2 != 0) {
    pvVar2 = (void *)CRYPTO_zalloc(0x18,"crypto/async/async.c",0x52);
    if (pvVar2 == (void *)0x0) {
      ERR_put_error(0x33,0x66,0x41,"crypto/async/async.c",0x54);
      ptr[1] = 0;
      iVar1 = CRYPTO_THREAD_set_local(&poolkey,ptr);
      goto joined_r0x0010ad5a;
    }
    *(undefined4 *)((int)pvVar2 + 0x10) = 0;
    CRYPTO_free(*(void **)((int)pvVar2 + 8));
    CRYPTO_free(pvVar2);
  }
  ptr[1] = 0;
  iVar1 = CRYPTO_THREAD_set_local(&poolkey,ptr);
joined_r0x0010ad5a:
  if (iVar1 == 0) {
    ERR_put_error(0x33,0x65,0x65,"crypto/async/async.c",0x16d);
    iVar1 = *ptr;
    if (iVar1 != 0) {
      pvVar2 = (void *)OPENSSL_sk_pop();
      while (pvVar2 != (void *)0x0) {
        CRYPTO_free(*(void **)((int)pvVar2 + 8));
        CRYPTO_free(pvVar2);
        pvVar2 = (void *)OPENSSL_sk_pop(*ptr);
      }
      iVar1 = *ptr;
    }
    OPENSSL_sk_free(iVar1);
    CRYPTO_free(ptr);
    return 0;
  }
  return 1;
}

