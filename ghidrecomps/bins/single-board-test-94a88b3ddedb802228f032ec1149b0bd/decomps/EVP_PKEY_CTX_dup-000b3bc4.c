
EVP_PKEY_CTX * EVP_PKEY_CTX_dup(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  int *ptr;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  if ((*(int *)ctx != 0) && (*(int *)(*(int *)ctx + 0xc) != 0)) {
    if ((*(ENGINE **)(ctx + 4) != (ENGINE *)0x0) &&
       (iVar1 = ENGINE_init(*(ENGINE **)(ctx + 4)), iVar1 == 0)) {
      ERR_put_error(6,0x9c,0x26,DAT_000b3c98,0x138);
      return (EVP_PKEY_CTX *)0x0;
    }
    ptr = (int *)CRYPTO_malloc(0x28,DAT_000b3c98,0x13c);
    if (ptr != (int *)0x0) {
      iVar3 = *(int *)(ctx + 4);
      iVar1 = *(int *)(ctx + 8);
      *ptr = *(int *)ctx;
      ptr[1] = iVar3;
      if (iVar1 != 0) {
        CRYPTO_add_lock((int *)(iVar1 + 8),1,10,DAT_000b3c98,0x146);
        iVar1 = *(int *)(ctx + 8);
      }
      iVar3 = *(int *)(ctx + 0xc);
      ptr[2] = iVar1;
      if (iVar3 != 0) {
        CRYPTO_add_lock((int *)(iVar3 + 8),1,10,DAT_000b3c98,0x14b);
        iVar3 = *(int *)(ctx + 0xc);
      }
      iVar1 = *(int *)(ctx + 0x10);
      iVar4 = *(int *)ctx;
      ptr[3] = iVar3;
      ptr[4] = iVar1;
      pcVar2 = *(code **)(iVar4 + 0xc);
      ptr[5] = 0;
      ptr[6] = 0;
      iVar1 = (*pcVar2)(ptr,ctx);
      if (0 < iVar1) {
        return (EVP_PKEY_CTX *)ptr;
      }
      if ((*ptr != 0) && (pcVar2 = *(code **)(*ptr + 0x10), pcVar2 != (code *)0x0)) {
        (*pcVar2)(ptr);
      }
      if ((EVP_PKEY *)ptr[2] != (EVP_PKEY *)0x0) {
        EVP_PKEY_free((EVP_PKEY *)ptr[2]);
      }
      if ((EVP_PKEY *)ptr[3] != (EVP_PKEY *)0x0) {
        EVP_PKEY_free((EVP_PKEY *)ptr[3]);
      }
      if ((ENGINE *)ptr[1] != (ENGINE *)0x0) {
        ENGINE_finish((ENGINE *)ptr[1]);
      }
      CRYPTO_free(ptr);
      return (EVP_PKEY_CTX *)0x0;
    }
  }
  return (EVP_PKEY_CTX *)0x0;
}

