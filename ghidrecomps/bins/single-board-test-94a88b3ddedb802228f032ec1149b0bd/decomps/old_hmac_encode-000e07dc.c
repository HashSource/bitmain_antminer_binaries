
size_t old_hmac_encode(int param_1,void **param_2)

{
  size_t sVar1;
  void *__dest;
  size_t *psVar2;
  
  psVar2 = *(size_t **)(param_1 + 0x14);
  if (param_2 != (void **)0x0) {
    if (*param_2 != (void *)0x0) {
      memcpy(*param_2,(void *)psVar2[2],*psVar2);
      sVar1 = *psVar2;
      *param_2 = (void *)((int)*param_2 + sVar1);
      return sVar1;
    }
    __dest = CRYPTO_malloc(*psVar2,DAT_000e0814,0x7a);
    sVar1 = *psVar2;
    *param_2 = __dest;
    memcpy(__dest,(void *)psVar2[2],sVar1);
  }
  return *psVar2;
}

