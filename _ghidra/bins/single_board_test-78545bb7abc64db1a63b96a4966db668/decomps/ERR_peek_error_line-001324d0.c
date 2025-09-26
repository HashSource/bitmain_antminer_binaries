
ulong ERR_peek_error_line(char **file,int *line)

{
  ERR_STATE *pEVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  pEVar1 = ERR_get_state();
  if (pEVar1 != (ERR_STATE *)0x0) {
    uVar4 = pEVar1->err_line[0xe];
    uVar5 = pEVar1->err_line[0xf];
    while (uVar4 != uVar5) {
      while (iVar2 = uVar4 * 4, (pEVar1->err_flags[uVar4 - 2] & 2U) != 0) {
        if ((int)pEVar1->err_data[uVar4 + 0xe] << 0x1f < 0) {
          CRYPTO_free((void *)pEVar1->err_buffer[uVar4 + 0xe]);
          uVar4 = pEVar1->err_line[0xe];
          uVar5 = pEVar1->err_line[0xf];
          iVar2 = uVar4 << 2;
          pEVar1->err_buffer[uVar4 + 0xe] = 0;
        }
        if ((int)uVar4 < 1) {
          uVar4 = 0xf;
        }
        else {
          uVar4 = uVar4 - 1;
        }
        *(undefined4 *)((int)pEVar1->err_data + iVar2 + 0x38) = 0;
        *(undefined4 *)((int)pEVar1->err_flags + iVar2 + -8) = 0;
        *(undefined4 *)((int)pEVar1->err_flags + iVar2 + 0x38) = 0;
        *(undefined4 *)((int)pEVar1->err_data_flags + iVar2 + 0x38) = 0;
        *(undefined4 *)((int)pEVar1->err_file + iVar2 + 0x38) = 0xffffffff;
        pEVar1->err_line[0xe] = uVar4;
        if (uVar4 == uVar5) {
          return 0;
        }
      }
      uVar6 = uVar5 + 1;
      uVar5 = uVar6 & 0xf;
      if ((int)uVar6 < 1) {
        uVar5 = -(-uVar6 & 0xf);
      }
      if (-1 < pEVar1->err_flags[uVar5 - 2] << 0x1e) {
        uVar3 = pEVar1->err_flags[uVar5 + 0xe];
        if (file == (char **)0x0 || line == (int *)0x0) {
          return uVar3;
        }
        if ((char *)pEVar1->err_data_flags[uVar5 + 0xe] != (char *)0x0) {
          *file = (char *)pEVar1->err_data_flags[uVar5 + 0xe];
          *line = (int)pEVar1->err_file[uVar5 + 0xe];
          return uVar3;
        }
        *file = "NA";
        *line = 0;
        return uVar3;
      }
      pEVar1->err_line[0xf] = uVar5;
      if ((int)pEVar1->err_data[uVar5 + 0xe] << 0x1f < 0) {
        CRYPTO_free((void *)pEVar1->err_buffer[uVar5 + 0xe]);
        uVar5 = pEVar1->err_line[0xf];
        uVar4 = pEVar1->err_line[0xe];
        pEVar1->err_buffer[uVar5 + 0xe] = 0;
      }
      pEVar1->err_data[uVar5 + 0xe] = (char *)0x0;
      pEVar1->err_flags[uVar5 - 2] = 0;
      pEVar1->err_flags[uVar5 + 0xe] = 0;
      pEVar1->err_data_flags[uVar5 + 0xe] = 0;
      pEVar1->err_file[uVar5 + 0xe] = (char *)0xffffffff;
    }
  }
  return 0;
}

