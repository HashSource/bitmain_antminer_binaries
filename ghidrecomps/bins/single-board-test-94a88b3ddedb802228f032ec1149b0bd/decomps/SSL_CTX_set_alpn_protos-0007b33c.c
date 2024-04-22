
undefined4 SSL_CTX_set_alpn_protos(int param_1,void *param_2,size_t param_3)

{
  void *__dest;
  
  if (*(void **)(param_1 + 0x1c0) != (void *)0x0) {
    CRYPTO_free(*(void **)(param_1 + 0x1c0));
  }
  __dest = CRYPTO_malloc(param_3,DAT_0007b374,0x6d5);
  *(void **)(param_1 + 0x1c0) = __dest;
  if (__dest != (void *)0x0) {
    memcpy(__dest,param_2,param_3);
    *(size_t *)(param_1 + 0x1c4) = param_3;
    return 0;
  }
  return 1;
}

