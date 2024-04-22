
ulong ERR_peek_last_error_line_data(char **file,int *line,char **data,int *flags)

{
  ERR_STATE *pEVar1;
  ulong uVar2;
  int iVar3;
  
  pEVar1 = ERR_get_state();
  iVar3 = pEVar1->top;
  if (pEVar1->bottom == iVar3) {
    uVar2 = 0;
  }
  else {
    uVar2 = pEVar1->err_buffer[iVar3];
    if (line != (int *)0x0 && file != (char **)0x0) {
      if (pEVar1->err_file[iVar3] == (char *)0x0) {
        *file = DAT_000ae118;
        *line = 0;
      }
      else {
        *file = pEVar1->err_file[iVar3];
        *line = pEVar1->err_line[iVar3];
      }
    }
    if (data != (char **)0x0) {
      if (pEVar1->err_data[iVar3] == (char *)0x0) {
        *data = DAT_000ae114;
        iVar3 = 0;
        if (flags != (int *)0x0) goto LAB_000ae0d4;
      }
      else {
        *data = pEVar1->err_data[iVar3];
        if (flags != (int *)0x0) {
          iVar3 = pEVar1->err_data_flags[iVar3];
LAB_000ae0d4:
          *flags = iVar3;
          return uVar2;
        }
      }
    }
  }
  return uVar2;
}

