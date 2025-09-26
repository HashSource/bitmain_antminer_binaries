
void ERR_set_error_data(char *data,int flags)

{
  ERR_STATE *pEVar1;
  int iVar2;
  
  pEVar1 = ERR_get_state();
  if (pEVar1 != (ERR_STATE *)0x0) {
    iVar2 = pEVar1->err_line[0xe];
    if ((int)pEVar1->err_data[iVar2 + 0xe] << 0x1f < 0) {
      CRYPTO_free((void *)pEVar1->err_buffer[iVar2 + 0xe]);
    }
    pEVar1->err_buffer[iVar2 + 0xe] = (ulong)data;
    pEVar1->err_data[iVar2 + 0xe] = (char *)flags;
  }
  return;
}

