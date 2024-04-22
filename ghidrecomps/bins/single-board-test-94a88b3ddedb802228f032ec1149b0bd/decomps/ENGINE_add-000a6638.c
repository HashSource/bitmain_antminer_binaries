
int ENGINE_add(ENGINE *e)

{
  ENGINE **ppEVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  ENGINE *pEVar5;
  char **ppcVar6;
  int iVar7;
  char *__s2;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x69,0x43,DAT_000a672c,0x102);
    return 0;
  }
  if ((*(int *)e == 0) || (*(int *)(e + 4) == 0)) {
    ERR_put_error(0x26,0x69,0x6c,DAT_000a672c,0x106);
  }
  ppEVar1 = DAT_000a6728;
  CRYPTO_lock(9,0x1e,DAT_000a672c,0x108);
  ppcVar6 = (char **)*ppEVar1;
  if (ppcVar6 == (char **)0x0) {
    if (ppEVar1[1] == (ENGINE *)0x0) {
      *(undefined4 *)(e + 0x68) = 0;
      uVar2 = DAT_000a6730;
      *ppEVar1 = e;
      engine_cleanup_add_last(uVar2);
LAB_000a66c8:
      iVar4 = *(int *)(e + 0x58);
      iVar7 = 1;
      ppEVar1[1] = e;
      *(undefined4 *)(e + 0x6c) = 0;
      *(int *)(e + 0x58) = iVar4 + 1;
      goto LAB_000a66b0;
    }
    iVar4 = 0x7b;
LAB_000a668e:
    ERR_put_error(0x26,0x78,0x6e,DAT_000a672c,iVar4);
  }
  else {
    __s2 = *(char **)e;
    do {
      uVar3 = strcmp(*ppcVar6,__s2);
      ppcVar6 = (char **)ppcVar6[0x1b];
      iVar4 = 1 - uVar3;
      if (1 < uVar3) {
        iVar4 = 0;
      }
    } while (uVar3 != 0 && ppcVar6 != (char **)0x0);
    if (iVar4 == 0) {
      pEVar5 = ppEVar1[1];
      if ((pEVar5 != (ENGINE *)0x0) && (*(int *)(pEVar5 + 0x6c) == 0)) {
        *(ENGINE **)(pEVar5 + 0x6c) = e;
        *(ENGINE **)(e + 0x68) = pEVar5;
        goto LAB_000a66c8;
      }
      iVar4 = 0x87;
      goto LAB_000a668e;
    }
    ERR_put_error(0x26,0x78,0x67,DAT_000a672c,0x75);
  }
  iVar7 = 0;
  ERR_put_error(0x26,0x69,0x6e,DAT_000a672c,0x10a);
LAB_000a66b0:
  CRYPTO_lock(10,0x1e,DAT_000a672c,0x10d);
  return iVar7;
}

