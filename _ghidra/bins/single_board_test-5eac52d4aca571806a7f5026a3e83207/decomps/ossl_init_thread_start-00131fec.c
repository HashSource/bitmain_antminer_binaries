
undefined4 ossl_init_thread_start(uint param_1)

{
  int iVar1;
  uint *ptr;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  iVar1 = OPENSSL_init_crypto(0,0,0);
  if (iVar1 != 0) {
    ptr = (uint *)CRYPTO_THREAD_get_local(&destructor_key);
    if (ptr != (uint *)0x0) {
LAB_00132012:
      uVar2 = param_1 & 1;
      bVar4 = uVar2 != 0;
      uVar3 = param_1 & 2;
      if (bVar4) {
        uVar2 = 1;
      }
      if (bVar4) {
        *ptr = uVar2;
      }
      bVar4 = uVar3 != 0;
      if (bVar4) {
        uVar3 = 1;
      }
      if (bVar4) {
        ptr[1] = uVar3;
      }
      if ((param_1 & 4) != 0) {
        ptr[2] = 1;
      }
      return 1;
    }
    ptr = (uint *)CRYPTO_zalloc(0xc,"crypto/init.c",0x42);
    if (ptr != (uint *)0x0) {
      iVar1 = CRYPTO_THREAD_set_local(&destructor_key,ptr);
      if (iVar1 != 0) goto LAB_00132012;
      CRYPTO_free(ptr);
    }
  }
  return 0;
}

