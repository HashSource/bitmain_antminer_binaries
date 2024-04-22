
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ERR_pop_to_mark(void)

{
  ERR_STATE *pEVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  pEVar1 = ERR_get_state();
  iVar5 = pEVar1->bottom;
  iVar4 = pEVar1->top;
  while( true ) {
    iVar2 = iVar4 + 0x32;
    if (iVar4 == iVar5) {
      return 0;
    }
    if ((pEVar1->err_flags[iVar4] & 1U) != 0) break;
    pEVar1->err_flags[iVar4] = 0;
    pEVar1->err_buffer[iVar4] = 0;
    if (pEVar1->err_data[iVar4] == (char *)0x0) {
      iVar2 = iVar4 + 0x32;
    }
    else if (pEVar1->err_data_flags[iVar4] << 0x1f < 0) {
      CRYPTO_free(pEVar1->err_data[iVar4]);
      iVar4 = pEVar1->top;
      iVar5 = pEVar1->bottom;
      iVar2 = iVar4 + 0x32;
      pEVar1->err_data[iVar4] = (char *)0x0;
    }
    iVar3 = iVar4 + -1;
    pEVar1->err_line[iVar4] = -1;
    bVar6 = iVar3 == -1;
    pEVar1->top = iVar3;
    if (bVar6) {
      iVar3 = 0xf;
    }
    pEVar1->err_flags[iVar2 + -2] = 0;
    pEVar1->err_file[iVar4] = (char *)0x0;
    iVar4 = iVar3;
    if (bVar6) {
      pEVar1->top = 0xf;
    }
  }
  pEVar1->err_flags[iVar4] = pEVar1->err_flags[iVar4] & 0xfffffffe;
  return 1;
}

