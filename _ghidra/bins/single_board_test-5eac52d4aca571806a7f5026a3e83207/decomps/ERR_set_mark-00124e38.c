
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ERR_set_mark(void)

{
  ERR_STATE *pEVar1;
  int iVar2;
  
  pEVar1 = ERR_get_state();
  if (pEVar1 == (ERR_STATE *)0x0) {
    return 0;
  }
  iVar2 = pEVar1->err_line[0xe];
  if (pEVar1->err_line[0xf] != iVar2) {
    pEVar1->err_flags[iVar2 + -2] = pEVar1->err_flags[iVar2 + -2] | 1;
    return 1;
  }
  return 0;
}

