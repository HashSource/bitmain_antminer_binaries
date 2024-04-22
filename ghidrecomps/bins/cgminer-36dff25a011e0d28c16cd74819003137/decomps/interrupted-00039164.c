
/* WARNING: Unknown calling convention */

_Bool interrupted(void)

{
  int *piVar1;
  undefined uVar2;
  int iVar3;
  bool bVar4;
  
  piVar1 = __errno_location();
  iVar3 = *piVar1;
  bVar4 = iVar3 == 4;
  if (bVar4) {
    iVar3 = 1;
  }
  uVar2 = (undefined)iVar3;
  if (!bVar4) {
    uVar2 = 0;
  }
  return (_Bool)uVar2;
}

