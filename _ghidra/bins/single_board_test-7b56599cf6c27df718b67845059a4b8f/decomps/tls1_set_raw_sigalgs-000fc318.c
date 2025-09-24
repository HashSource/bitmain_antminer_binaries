
undefined4 tls1_set_raw_sigalgs(int param_1,void *param_2,int param_3,int param_4)

{
  void *__dest;
  
  __dest = CRYPTO_malloc(param_3 << 1,"ssl/t1_lib.c",0x7f9);
  if (__dest == (void *)0x0) {
    ERR_put_error(0x14,0x276,0x41,"ssl/t1_lib.c",0x7fa);
    return 0;
  }
  memcpy(__dest,param_2,param_3 << 1);
  if (param_4 == 0) {
    CRYPTO_free(*(void **)(param_1 + 0xd0));
    *(void **)(param_1 + 0xd0) = __dest;
    *(int *)(param_1 + 0xd4) = param_3;
    return 1;
  }
  CRYPTO_free(*(void **)(param_1 + 0xd8));
  *(void **)(param_1 + 0xd8) = __dest;
  *(int *)(param_1 + 0xdc) = param_3;
  return 1;
}

