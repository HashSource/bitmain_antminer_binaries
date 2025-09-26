
EVP_PKEY_CTX * EVP_PKEY_CTX_dup(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  EVP_PKEY_CTX *ptr;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  if ((*(int *)ctx != 0) && (*(int *)(*(int *)ctx + 0xc) != 0)) {
    if ((*(ENGINE **)(ctx + 4) != (ENGINE *)0x0) &&
       (iVar1 = ENGINE_init(*(ENGINE **)(ctx + 4)), iVar1 == 0)) {
      ERR_put_error(6,0x9c,0x26,"pmeth_lib.c",0x138);
      return (EVP_PKEY_CTX *)0x0;
    }
    ptr = (EVP_PKEY_CTX *)CRYPTO_malloc(0x28,"pmeth_lib.c",0x13c);
    if (ptr != (EVP_PKEY_CTX *)0x0) {
      uVar4 = *(undefined4 *)(ctx + 4);
      iVar1 = *(int *)(ctx + 8);
      *(undefined4 *)ptr = *(undefined4 *)ctx;
      *(undefined4 *)(ptr + 4) = uVar4;
      if (iVar1 != 0) {
        CRYPTO_add_lock((int *)(iVar1 + 8),1,10,"pmeth_lib.c",0x146);
        iVar1 = *(int *)(ctx + 8);
      }
      iVar2 = *(int *)(ctx + 0xc);
      *(int *)(ptr + 8) = iVar1;
      if (iVar2 != 0) {
        CRYPTO_add_lock((int *)(iVar2 + 8),1,10,"pmeth_lib.c",0x14b);
        iVar2 = *(int *)(ctx + 0xc);
      }
      uVar4 = *(undefined4 *)(ctx + 0x10);
      iVar1 = *(int *)ctx;
      *(int *)(ptr + 0xc) = iVar2;
      *(undefined4 *)(ptr + 0x10) = uVar4;
      pcVar3 = *(code **)(iVar1 + 0xc);
      *(undefined4 *)(ptr + 0x14) = 0;
      *(undefined4 *)(ptr + 0x18) = 0;
      iVar1 = (*pcVar3)(ptr,ctx);
      if (0 < iVar1) {
        return ptr;
      }
      if ((*(int *)ptr != 0) && (pcVar3 = *(code **)(*(int *)ptr + 0x10), pcVar3 != (code *)0x0)) {
        (*pcVar3)(ptr);
      }
      if (*(EVP_PKEY **)(ptr + 8) != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*(EVP_PKEY **)(ptr + 8));
      }
      if (*(EVP_PKEY **)(ptr + 0xc) != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*(EVP_PKEY **)(ptr + 0xc));
      }
      if (*(ENGINE **)(ptr + 4) != (ENGINE *)0x0) {
        ENGINE_finish(*(ENGINE **)(ptr + 4));
      }
      CRYPTO_free(ptr);
      return (EVP_PKEY_CTX *)0x0;
    }
  }
  return (EVP_PKEY_CTX *)0x0;
}

