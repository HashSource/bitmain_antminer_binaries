
/* WARNING: Unknown calling convention */

_Bool isChainEnough(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    iVar4 = iVar3 + 4;
    if (*(int *)((int)dev->chain_exist + iVar3) == 1) {
      iVar2 = iVar2 + 1;
    }
    iVar3 = iVar4;
  } while (iVar4 != 0x40);
  iVar3 = iVar2;
  if (iVar2 < 9) {
    iVar3 = 0;
  }
  uVar1 = (undefined1)iVar3;
  if (8 < iVar2) {
    uVar1 = 1;
  }
  return (_Bool)uVar1;
}

