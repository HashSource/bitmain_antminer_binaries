
bool pkey_hmac_init(int param_1)

{
  void *ptr;
  int iVar1;
  
  ptr = (void *)CRYPTO_zalloc(0x18,"crypto/hmac/hm_pmeth.c",0x1f);
  if (ptr != (void *)0x0) {
    *(undefined4 *)((int)ptr + 8) = 4;
    iVar1 = HMAC_CTX_new();
    *(int *)((int)ptr + 0x14) = iVar1;
    if (iVar1 == 0) {
      CRYPTO_free(ptr);
    }
    else {
      *(void **)(param_1 + 0x14) = ptr;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    return iVar1 != 0;
  }
  ERR_put_error(0xf,0x7b,0x41,"crypto/hmac/hm_pmeth.c",0x20);
  return false;
}

