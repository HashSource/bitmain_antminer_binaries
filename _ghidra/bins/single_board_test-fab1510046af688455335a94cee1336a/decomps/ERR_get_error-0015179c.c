
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong ERR_get_error(void)

{
  ERR_STATE *pEVar1;
  char *ptr;
  int iVar2;
  ulong uVar3;
  
  pEVar1 = ERR_get_state();
  if (pEVar1->bottom == pEVar1->top) {
    uVar3 = 0;
  }
  else {
    iVar2 = (pEVar1->bottom + 1) % 0x10;
    ptr = pEVar1->err_data[iVar2];
    uVar3 = pEVar1->err_buffer[iVar2];
    pEVar1->bottom = iVar2;
    pEVar1->err_buffer[iVar2] = 0;
    if ((ptr != (char *)0x0) && (pEVar1->err_data_flags[iVar2] << 0x1f < 0)) {
      CRYPTO_free(ptr);
      pEVar1->err_data[iVar2] = (char *)0x0;
    }
    pEVar1->err_data_flags[iVar2] = 0;
  }
  return uVar3;
}

