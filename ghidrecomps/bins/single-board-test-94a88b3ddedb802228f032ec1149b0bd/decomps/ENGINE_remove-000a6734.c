
int ENGINE_remove(ENGINE *e)

{
  ENGINE **ppEVar1;
  ENGINE **ppEVar2;
  int iVar3;
  ENGINE *pEVar4;
  ENGINE *pEVar5;
  bool bVar6;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x7b,0x43,DAT_000a67e4,0x116);
    iVar3 = 0;
  }
  else {
    CRYPTO_lock(9,0x1e,DAT_000a67e4,0x119);
    ppEVar1 = DAT_000a67e8;
    pEVar4 = *DAT_000a67e8;
    pEVar5 = pEVar4;
    if (e != pEVar4 && pEVar4 != (ENGINE *)0x0) {
      do {
        pEVar5 = *(ENGINE **)(pEVar5 + 0x6c);
      } while (e != pEVar5 && pEVar5 != (ENGINE *)0x0);
    }
    if (pEVar5 == (ENGINE *)0x0) {
      ERR_put_error(0x26,0x79,0x69,DAT_000a67e4,0xa6);
      ERR_put_error(0x26,0x7b,0x6e,DAT_000a67e4,0x11b);
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(e + 0x6c);
      if (iVar3 != 0) {
        *(undefined4 *)(iVar3 + 0x68) = *(undefined4 *)(e + 0x68);
      }
      pEVar5 = *(ENGINE **)(e + 0x68);
      if (pEVar5 != (ENGINE *)0x0) {
        *(int *)(pEVar5 + 0x6c) = iVar3;
      }
      ppEVar2 = DAT_000a67e8;
      bVar6 = e == pEVar4;
      if (bVar6) {
        pEVar4 = *(ENGINE **)(e + 0x6c);
      }
      iVar3 = 1;
      if (bVar6) {
        *ppEVar1 = pEVar4;
      }
      if (e == ppEVar1[1]) {
        ppEVar2[1] = pEVar5;
      }
      engine_free_util(e,0);
    }
    CRYPTO_lock(10,0x1e,DAT_000a67e4,0x11e);
  }
  return iVar3;
}

