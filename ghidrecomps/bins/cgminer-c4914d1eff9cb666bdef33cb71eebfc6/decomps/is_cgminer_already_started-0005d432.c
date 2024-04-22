
/* WARNING: Unknown calling convention */

_Bool is_cgminer_already_started(void)

{
  int iVar1;
  undefined uVar2;
  int iVar3;
  
  iVar1 = cnt_of_proc("cgminer");
  iVar3 = iVar1;
  if (1 < iVar1) {
    iVar3 = 1;
  }
  uVar2 = (undefined)iVar3;
  if (iVar1 < 2) {
    uVar2 = 0;
  }
  return (_Bool)uVar2;
}

