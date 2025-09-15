
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_is_mem_check_on(void)

{
  int iVar1;
  CRYPTO_THREADID CStack_10;
  
  if ((mh_mode & 1) == 0) {
    iVar1 = 0;
  }
  else {
    CRYPTO_THREADID_current(&CStack_10);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
    if ((int)(mh_mode << 0x1e) < 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_10);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
    }
    CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
  }
  return iVar1;
}

