
size_t old_hmac_encode(int param_1,int *param_2)

{
  size_t sVar1;
  void *__dest;
  size_t *psVar2;
  
  psVar2 = *(size_t **)(param_1 + 0x14);
  if (param_2 != (int *)0x0) {
    if ((void *)*param_2 != (void *)0x0) {
      memcpy((void *)*param_2,(void *)psVar2[2],*psVar2);
      sVar1 = *psVar2;
      *param_2 = *param_2 + sVar1;
      return sVar1;
    }
    __dest = CRYPTO_malloc(*psVar2,"hm_ameth.c",0x7a);
    sVar1 = *psVar2;
    *param_2 = (int)__dest;
    memcpy(__dest,(void *)psVar2[2],sVar1);
  }
  return *psVar2;
}

