
ulong ERR_peek_error_line(char **file,int *line)

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
      if (pEVar1->err_file[iVar3] != (char *)0x0) {
        *file = pEVar1->err_file[iVar3];
        *line = pEVar1->err_line[iVar3];
        return uVar2;
      }
      *file = DAT_000ae27c;
      *line = 0;
      return uVar2;
    }
  }
  return uVar2;
}

