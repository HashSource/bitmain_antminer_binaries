
ENGINE * ENGINE_get_prev(ENGINE *e)

{
  ENGINE *pEVar1;
  int iVar2;
  int iVar3;
  ENGINE *pEVar4;
  bool bVar5;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x74,0x43,"crypto/engine/eng_list.c",0x116);
    return (ENGINE *)0x0;
  }
  CRYPTO_THREAD_write_lock(global_engine_lock);
  pEVar4 = *(ENGINE **)(e + 0x5c);
  if (pEVar4 != (ENGINE *)0x0) {
    DataMemoryBarrier(0x1b);
    DataMemoryBarrier(0x1b);
    pEVar1 = pEVar4 + 0x50;
    iVar2 = *(int *)(pEVar4 + 0x50);
    do {
      DataMemoryBarrier(0x1b);
      do {
        ExclusiveAccess(pEVar1);
        iVar3 = *(int *)pEVar1;
        bVar5 = iVar3 == iVar2;
        if (!bVar5) goto LAB_0012ff58;
        bVar5 = (bool)hasExclusiveAccess(pEVar1);
      } while (!bVar5);
      *(int *)pEVar1 = iVar2 + 1;
LAB_0012ff58:
      DataMemoryBarrier(0x1b);
      iVar2 = iVar3;
    } while (!bVar5);
  }
  CRYPTO_THREAD_unlock(global_engine_lock);
  ENGINE_free(e);
  return pEVar4;
}

