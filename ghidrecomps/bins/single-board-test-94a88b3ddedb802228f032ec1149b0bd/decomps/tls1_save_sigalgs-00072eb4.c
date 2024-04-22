
undefined4 tls1_save_sigalgs(int param_1,void *param_2,size_t param_3)

{
  void *__dest;
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x98);
  if (-1 < *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1e) {
    return 1;
  }
  if (iVar1 != 0) {
    if (*(void **)(iVar1 + 0x124) != (void *)0x0) {
      CRYPTO_free(*(void **)(iVar1 + 0x124));
    }
    __dest = CRYPTO_malloc(param_3,DAT_00072f00,0xe70);
    *(void **)(iVar1 + 0x124) = __dest;
    if (__dest != (void *)0x0) {
      *(size_t *)(iVar1 + 0x128) = param_3;
      memcpy(__dest,param_2,param_3);
      return 1;
    }
  }
  return 0;
}

