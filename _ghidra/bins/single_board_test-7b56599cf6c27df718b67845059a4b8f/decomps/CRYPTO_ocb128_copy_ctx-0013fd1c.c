
undefined4 CRYPTO_ocb128_copy_ctx(void *param_1,void *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  void *__dest;
  
  memcpy(param_1,param_2,0x98);
  if (param_3 != 0) {
    *(int *)((int)param_1 + 8) = param_3;
  }
  if (param_4 != 0) {
    *(int *)((int)param_1 + 0xc) = param_4;
  }
  uVar1 = 1;
  if (*(int *)((int)param_2 + 0x40) != 0) {
    __dest = CRYPTO_malloc(*(int *)((int)param_2 + 0x18) << 4,"crypto/modes/ocb128.c",0xcd);
    *(void **)((int)param_1 + 0x40) = __dest;
    if (__dest == (void *)0x0) {
      ERR_put_error(0xf,0x79,0x41,"crypto/modes/ocb128.c",0xce);
      uVar1 = 0;
    }
    else {
      memcpy(__dest,*(void **)((int)param_2 + 0x40),(*(int *)((int)param_2 + 0x14) + 1) * 0x10);
      uVar1 = 1;
    }
  }
  return uVar1;
}

