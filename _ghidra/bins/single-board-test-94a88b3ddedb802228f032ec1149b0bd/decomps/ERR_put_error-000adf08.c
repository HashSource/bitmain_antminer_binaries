
void ERR_put_error(int lib,int func,int reason,char *file,int line)

{
  ERR_STATE *pEVar1;
  int iVar2;
  int iVar3;
  
  pEVar1 = ERR_get_state();
  iVar3 = (pEVar1->top + 1) % 0x10;
  pEVar1->top = iVar3;
  if (iVar3 == pEVar1->bottom) {
    pEVar1->bottom = (iVar3 + 1) % 0x10;
  }
  pEVar1->err_file[iVar3] = file;
  pEVar1->err_line[iVar3] = line;
  iVar2 = iVar3 + 0x32;
  pEVar1->err_buffer[iVar3] = reason & 0xfffU | (func & 0xfffU) << 0xc | lib << 0x18;
  pEVar1->err_flags[iVar3] = 0;
  if ((pEVar1->err_data[iVar3] != (char *)0x0) && (pEVar1->err_data_flags[iVar3] << 0x1f < 0)) {
    CRYPTO_free(pEVar1->err_data[iVar3]);
    iVar2 = pEVar1->top + 0x32;
    pEVar1->err_data[pEVar1->top] = (char *)0x0;
  }
  pEVar1->err_flags[iVar2 + -2] = 0;
  return;
}

