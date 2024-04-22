
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_is_mem_check_on(void)

{
  int iVar1;
  CRYPTO_THREADID CStack_10;
  
  iVar1 = DAT_0008a598;
  if ((*(uint *)(DAT_0008a598 + 4) & 1) == 0) {
    iVar1 = 0;
  }
  else {
    CRYPTO_THREADID_current(&CStack_10);
    CRYPTO_lock(5,0x14,DAT_0008a59c,0x11d);
    if (*(int *)(iVar1 + 4) << 0x1e < 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)(iVar1 + 0xc),&CStack_10);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
    }
    CRYPTO_lock(6,0x14,DAT_0008a59c,0x122);
  }
  return iVar1;
}

