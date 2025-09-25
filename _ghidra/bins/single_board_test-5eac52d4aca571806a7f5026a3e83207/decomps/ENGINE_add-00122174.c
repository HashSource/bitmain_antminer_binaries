
int ENGINE_add(ENGINE *e)

{
  int iVar1;
  int iVar2;
  ENGINE *pEVar3;
  char *__s2;
  bool bVar4;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x69,0x43,"crypto/engine/eng_list.c",299);
    return 0;
  }
  if ((*(int *)e == 0) || (*(int *)(e + 4) == 0)) {
    ERR_put_error(0x26,0x69,0x6c,"crypto/engine/eng_list.c",0x12f);
    return 0;
  }
  CRYPTO_THREAD_write_lock(global_engine_lock);
  if (engine_list_head == (ENGINE *)0x0) {
    if (engine_list_tail == (ENGINE *)0x0) {
      *(undefined4 *)(e + 0x5c) = 0;
      engine_list_head = e;
      engine_cleanup_add_last(0x1223a9);
LAB_00122200:
      DataMemoryBarrier(0x1b);
      DataMemoryBarrier(0x1b);
      pEVar3 = e + 0x50;
      iVar1 = *(int *)(e + 0x50);
      do {
        DataMemoryBarrier(0x1b);
        do {
          ExclusiveAccess(pEVar3);
          iVar2 = *(int *)pEVar3;
          bVar4 = iVar2 == iVar1;
          if (!bVar4) goto LAB_0012222c;
          bVar4 = (bool)hasExclusiveAccess(pEVar3);
        } while (!bVar4);
        *(int *)pEVar3 = iVar1 + 1;
LAB_0012222c:
        DataMemoryBarrier(0x1b);
        iVar1 = iVar2;
      } while (!bVar4);
      iVar1 = 1;
      *(undefined4 *)(e + 0x60) = 0;
      engine_list_tail = e;
      goto LAB_001221f0;
    }
    iVar1 = 0x4b;
LAB_001221ce:
    ERR_put_error(0x26,0x78,0x6e,"crypto/engine/eng_list.c",iVar1);
  }
  else {
    __s2 = *(char **)e;
    pEVar3 = engine_list_head;
    do {
      iVar1 = strcmp(*(char **)pEVar3,__s2);
      pEVar3 = *(ENGINE **)(pEVar3 + 0x60);
    } while (pEVar3 != (ENGINE *)0x0 && iVar1 != 0);
    if (iVar1 != 0) {
      if ((engine_list_tail != (ENGINE *)0x0) && (*(int *)(engine_list_tail + 0x60) == 0)) {
        *(ENGINE **)(engine_list_tail + 0x60) = e;
        *(ENGINE **)(e + 0x5c) = engine_list_tail;
        goto LAB_00122200;
      }
      iVar1 = 0x57;
      goto LAB_001221ce;
    }
    ERR_put_error(0x26,0x78,0x67,"crypto/engine/eng_list.c",0x45);
  }
  iVar1 = 0;
  ERR_put_error(0x26,0x69,0x6e,"crypto/engine/eng_list.c",0x134);
LAB_001221f0:
  CRYPTO_THREAD_unlock(global_engine_lock);
  return iVar1;
}

