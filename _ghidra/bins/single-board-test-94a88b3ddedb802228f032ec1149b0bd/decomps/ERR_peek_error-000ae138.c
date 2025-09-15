
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong ERR_peek_error(void)

{
  ERR_STATE *pEVar1;
  
  pEVar1 = ERR_get_state();
  if (pEVar1->bottom != pEVar1->top) {
    return pEVar1->err_buffer[(pEVar1->bottom + 1) % 0x10];
  }
  return 0;
}

