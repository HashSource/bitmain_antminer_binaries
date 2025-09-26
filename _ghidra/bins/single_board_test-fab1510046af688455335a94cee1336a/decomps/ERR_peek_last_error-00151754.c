
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong ERR_peek_last_error(void)

{
  ERR_STATE *pEVar1;
  ulong uVar2;
  
  pEVar1 = ERR_get_state();
  if (pEVar1->bottom == pEVar1->top) {
    uVar2 = 0;
  }
  else {
    uVar2 = pEVar1->err_buffer[pEVar1->top];
  }
  return uVar2;
}

