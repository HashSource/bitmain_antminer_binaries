
int ENGINE_remove(ENGINE *e)

{
  ENGINE *pEVar1;
  int iVar2;
  ENGINE *pEVar3;
  
  if (e != (ENGINE *)0x0) {
    CRYPTO_THREAD_write_lock(global_engine_lock);
    pEVar1 = engine_list_head;
    pEVar3 = engine_list_head;
    if (e != engine_list_head && engine_list_head != (ENGINE *)0x0) {
      do {
        pEVar3 = *(ENGINE **)(pEVar3 + 0x60);
      } while (pEVar3 != (ENGINE *)0x0 && e != pEVar3);
    }
    if (pEVar3 == (ENGINE *)0x0) {
      ERR_put_error(0x26,0x79,0x69,"crypto/engine/eng_list.c",0x76);
      ERR_put_error(0x26,0x7b,0x6e,"crypto/engine/eng_list.c",0x145);
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(e + 0x60);
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x5c) = *(undefined4 *)(e + 0x5c);
      }
      pEVar3 = *(ENGINE **)(e + 0x5c);
      if (pEVar3 != (ENGINE *)0x0) {
        *(int *)(pEVar3 + 0x60) = iVar2;
      }
      if (e == pEVar1) {
        engine_list_head = *(ENGINE **)(e + 0x60);
      }
      iVar2 = 1;
      if (e == engine_list_tail) {
        engine_list_tail = pEVar3;
      }
      engine_free_util(e,0);
    }
    CRYPTO_THREAD_unlock(global_engine_lock);
    return iVar2;
  }
  ERR_put_error(0x26,0x7b,0x43,"crypto/engine/eng_list.c",0x140);
  return 0;
}

