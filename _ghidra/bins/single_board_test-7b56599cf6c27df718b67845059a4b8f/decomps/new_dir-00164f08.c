
undefined4 new_dir(int param_1)

{
  undefined4 *ptr;
  BUF_MEM *pBVar1;
  int iVar2;
  
  ptr = (undefined4 *)CRYPTO_malloc(0xc,"crypto/x509/by_dir.c",0x5f);
  if (ptr == (undefined4 *)0x0) {
    ERR_put_error(0xb,0x99,0x41,"crypto/x509/by_dir.c",0x62);
    return 0;
  }
  pBVar1 = BUF_MEM_new();
  iVar2 = 0x67;
  *ptr = pBVar1;
  if (pBVar1 != (BUF_MEM *)0x0) {
    ptr[1] = 0;
    iVar2 = CRYPTO_THREAD_lock_new();
    ptr[2] = iVar2;
    if (iVar2 != 0) {
      *(undefined4 **)(param_1 + 0xc) = ptr;
      return 1;
    }
    BUF_MEM_free((BUF_MEM *)*ptr);
    iVar2 = 0x6e;
  }
  ERR_put_error(0xb,0x99,0x41,"crypto/x509/by_dir.c",iVar2);
  CRYPTO_free(ptr);
  return 0;
}

