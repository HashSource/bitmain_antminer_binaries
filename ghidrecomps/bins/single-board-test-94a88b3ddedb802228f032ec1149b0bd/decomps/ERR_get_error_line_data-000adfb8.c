
ulong ERR_get_error_line_data(char **file,int *line,char **data,int *flags)

{
  ERR_STATE *pEVar1;
  int iVar2;
  ulong uVar3;
  
  pEVar1 = ERR_get_state();
  if (pEVar1->bottom == pEVar1->top) {
    uVar3 = 0;
  }
  else {
    iVar2 = (pEVar1->bottom + 1) % 0x10;
    pEVar1->bottom = iVar2;
    uVar3 = pEVar1->err_buffer[iVar2];
    pEVar1->err_buffer[iVar2] = 0;
    if (line != (int *)0x0 && file != (char **)0x0) {
      if (pEVar1->err_file[iVar2] == (char *)0x0) {
        *file = DAT_000ae088;
        *line = 0;
      }
      else {
        *file = pEVar1->err_file[iVar2];
        *line = pEVar1->err_line[iVar2];
      }
    }
    if (data == (char **)0x0) {
      if ((pEVar1->err_data[iVar2] != (char *)0x0) && (pEVar1->err_data_flags[iVar2] << 0x1f < 0)) {
        CRYPTO_free(pEVar1->err_data[iVar2]);
        pEVar1->err_data[iVar2] = (char *)0x0;
      }
      pEVar1->err_data_flags[iVar2] = 0;
    }
    else {
      if (pEVar1->err_data[iVar2] == (char *)0x0) {
        *data = DAT_000ae084;
        iVar2 = 0;
        if (flags == (int *)0x0) {
          return uVar3;
        }
      }
      else {
        *data = pEVar1->err_data[iVar2];
        if (flags == (int *)0x0) {
          return uVar3;
        }
        iVar2 = pEVar1->err_data_flags[iVar2];
      }
      *flags = iVar2;
    }
  }
  return uVar3;
}

