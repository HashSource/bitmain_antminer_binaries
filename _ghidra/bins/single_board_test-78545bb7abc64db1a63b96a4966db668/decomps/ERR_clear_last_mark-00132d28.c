
undefined4 ERR_clear_last_mark(void)

{
  ERR_STATE *pEVar1;
  int iVar2;
  
  pEVar1 = ERR_get_state();
  if (pEVar1 != (ERR_STATE *)0x0) {
    iVar2 = pEVar1->err_line[0xe];
    while (iVar2 != pEVar1->err_line[0xf]) {
      if ((pEVar1->err_flags[iVar2 + -2] & 1U) != 0) {
        pEVar1->err_flags[iVar2 + -2] = pEVar1->err_flags[iVar2 + -2] & 0xfffffffe;
        return 1;
      }
      if (iVar2 < 1) {
        iVar2 = 0xf;
      }
      else {
        iVar2 = iVar2 + -1;
      }
    }
  }
  return 0;
}

