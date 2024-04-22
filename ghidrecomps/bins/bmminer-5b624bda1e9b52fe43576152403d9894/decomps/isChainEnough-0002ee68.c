
/* WARNING: Unknown calling convention */

_Bool isChainEnough(void)

{
  undefined uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = 0;
  do {
    iVar3 = *DAT_0002ee8c + iVar4;
    iVar4 = iVar4 + 4;
    if (*(int *)(iVar3 + 8) == 1) {
      iVar2 = iVar2 + 1;
    }
  } while (iVar4 != 0x40);
  iVar4 = iVar2;
  if (iVar2 < 9) {
    iVar4 = 0;
  }
  uVar1 = (undefined)iVar4;
  if (8 < iVar2) {
    uVar1 = 1;
  }
  return (_Bool)uVar1;
}

