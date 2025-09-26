
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ERR_set_mark(void)

{
  ERR_STATE *pEVar1;
  int iVar2;
  bool bVar3;
  
  pEVar1 = ERR_get_state();
  iVar2 = pEVar1->top;
  bVar3 = pEVar1->bottom != iVar2;
  if (bVar3) {
    pEVar1->err_flags[iVar2] = pEVar1->err_flags[iVar2] | 1;
  }
  return (uint)bVar3;
}

