
ulong ERR_peek_error_line_data(char **file,int *line,char **data,int *flags)

{
  ERR_STATE *pEVar1;
  ulong uVar2;
  int iVar3;
  
  pEVar1 = ERR_get_state();
  if (pEVar1->bottom == pEVar1->top) {
    uVar2 = 0;
  }
  else {
    iVar3 = (pEVar1->bottom + 1) % 0x10;
    uVar2 = pEVar1->err_buffer[iVar3];
    if (line != (int *)0x0 && file != (char **)0x0) {
      if (pEVar1->err_file[iVar3] == (char *)0x0) {
        *file = DAT_000ae3b8;
        *line = 0;
      }
      else {
        *file = pEVar1->err_file[iVar3];
        *line = pEVar1->err_line[iVar3];
      }
    }
    if (data != (char **)0x0) {
      if (pEVar1->err_data[iVar3] == (char *)0x0) {
        *data = DAT_000ae3b4;
        iVar3 = 0;
        if (flags != (int *)0x0) goto LAB_000ae374;
      }
      else {
        *data = pEVar1->err_data[iVar3];
        if (flags != (int *)0x0) {
          iVar3 = pEVar1->err_data_flags[iVar3];
LAB_000ae374:
          *flags = iVar3;
          return uVar2;
        }
      }
    }
  }
  return uVar2;
}

