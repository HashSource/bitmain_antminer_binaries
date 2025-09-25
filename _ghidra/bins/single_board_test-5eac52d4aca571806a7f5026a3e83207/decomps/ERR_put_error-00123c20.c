
void ERR_put_error(int lib,int func,int reason,char *file,int line)

{
  ERR_STATE *pEVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  pEVar1 = ERR_get_state();
  if (pEVar1 != (ERR_STATE *)0x0) {
    uVar3 = pEVar1->err_line[0xe] + 1;
    uVar4 = uVar3 & 0xf;
    if ((int)uVar3 < 1) {
      uVar4 = -(-uVar3 & 0xf);
    }
    pEVar1->err_line[0xe] = uVar4;
    if (uVar4 == pEVar1->err_line[0xf]) {
      uVar2 = uVar4 + 1;
      uVar3 = uVar2 & 0xf;
      if ((int)uVar2 < 1) {
        uVar3 = -(-uVar2 & 0xf);
      }
      pEVar1->err_line[0xf] = uVar3;
    }
    pEVar1->err_flags[uVar4 - 2] = 0;
    pEVar1->err_data_flags[uVar4 + 0xe] = (int)file;
    pEVar1->err_flags[uVar4 + 0xe] = reason & 0xfffU | lib << 0x18 | (func & 0xfffU) << 0xc;
    pEVar1->err_file[uVar4 + 0xe] = (char *)line;
    if ((int)pEVar1->err_data[uVar4 + 0xe] << 0x1f < 0) {
      CRYPTO_free((void *)pEVar1->err_buffer[uVar4 + 0xe]);
      uVar4 = pEVar1->err_line[0xe];
      pEVar1->err_buffer[uVar4 + 0xe] = 0;
    }
    pEVar1->err_data[uVar4 + 0xe] = (char *)0x0;
  }
  return;
}

