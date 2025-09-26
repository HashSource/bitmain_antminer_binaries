
int ENGINE_remove(ENGINE *e)

{
  int iVar1;
  ENGINE *pEVar2;
  ENGINE *pEVar3;
  bool bVar4;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x7b,0x43,"eng_list.c",0x116);
    iVar1 = 0;
  }
  else {
    CRYPTO_lock(9,0x1e,"eng_list.c",0x119);
    pEVar2 = engine_list_head;
    pEVar3 = engine_list_head;
    if (e != engine_list_head && engine_list_head != (ENGINE *)0x0) {
      do {
        pEVar3 = *(ENGINE **)(pEVar3 + 0x6c);
      } while (e != pEVar3 && pEVar3 != (ENGINE *)0x0);
    }
    if (pEVar3 == (ENGINE *)0x0) {
      ERR_put_error(0x26,0x79,0x69,"eng_list.c",0xa6);
      ERR_put_error(0x26,0x7b,0x6e,"eng_list.c",0x11b);
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(e + 0x6c);
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x68) = *(undefined4 *)(e + 0x68);
      }
      pEVar3 = *(ENGINE **)(e + 0x68);
      if (pEVar3 != (ENGINE *)0x0) {
        *(int *)(pEVar3 + 0x6c) = iVar1;
      }
      bVar4 = e == pEVar2;
      if (bVar4) {
        pEVar2 = *(ENGINE **)(e + 0x6c);
      }
      iVar1 = 1;
      if (bVar4) {
        engine_list_head = pEVar2;
      }
      if (e == engine_list_tail) {
        engine_list_tail = pEVar3;
      }
      engine_free_util(e,0);
    }
    CRYPTO_lock(10,0x1e,"eng_list.c",0x11e);
  }
  return iVar1;
}

