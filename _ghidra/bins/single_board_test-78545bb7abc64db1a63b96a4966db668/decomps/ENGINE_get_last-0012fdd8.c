
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ENGINE * ENGINE_get_last(void)

{
  ENGINE *pEVar1;
  int iVar2;
  ENGINE *pEVar3;
  int iVar4;
  bool bVar5;
  
  iVar2 = CRYPTO_THREAD_run_once(&engine_lock_init,0x12f851);
  if ((iVar2 == 0) || (do_engine_lock_init_ossl_ret_ == 0)) {
    ERR_put_error(0x26,0xc4,0x41,"crypto/engine/eng_list.c",0xef);
    return (ENGINE *)0x0;
  }
  CRYPTO_THREAD_write_lock(global_engine_lock);
  pEVar1 = engine_list_tail;
  if (engine_list_tail != (ENGINE *)0x0) {
    DataMemoryBarrier(0x1b);
    DataMemoryBarrier(0x1b);
    pEVar3 = engine_list_tail + 0x50;
    iVar2 = *(int *)(engine_list_tail + 0x50);
    do {
      DataMemoryBarrier(0x1b);
      do {
        ExclusiveAccess(pEVar3);
        iVar4 = *(int *)pEVar3;
        bVar5 = iVar4 == iVar2;
        if (!bVar5) goto LAB_0012fe36;
        bVar5 = (bool)hasExclusiveAccess(pEVar3);
      } while (!bVar5);
      *(int *)pEVar3 = iVar2 + 1;
LAB_0012fe36:
      DataMemoryBarrier(0x1b);
      iVar2 = iVar4;
    } while (!bVar5);
  }
  CRYPTO_THREAD_unlock(global_engine_lock);
  return pEVar1;
}

