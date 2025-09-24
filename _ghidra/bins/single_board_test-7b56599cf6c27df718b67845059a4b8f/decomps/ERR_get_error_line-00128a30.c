
ulong ERR_get_error_line(char **file,int *line)

{
  ERR_STATE *pEVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  
  pEVar1 = ERR_get_state();
  if (pEVar1 != (ERR_STATE *)0x0) {
    uVar3 = pEVar1->err_line[0xe];
    uVar4 = pEVar1->err_line[0xf];
    while (uVar3 != uVar4) {
      while (iVar2 = uVar3 * 4, (pEVar1->err_flags[uVar3 - 2] & 2U) != 0) {
        if ((int)pEVar1->err_data[uVar3 + 0xe] << 0x1f < 0) {
          CRYPTO_free((void *)pEVar1->err_buffer[uVar3 + 0xe]);
          uVar3 = pEVar1->err_line[0xe];
          uVar4 = pEVar1->err_line[0xf];
          iVar2 = uVar3 << 2;
          pEVar1->err_buffer[uVar3 + 0xe] = 0;
        }
        if ((int)uVar3 < 1) {
          uVar3 = 0xf;
        }
        else {
          uVar3 = uVar3 - 1;
        }
        *(undefined4 *)((int)pEVar1->err_data + iVar2 + 0x38) = 0;
        *(undefined4 *)((int)pEVar1->err_flags + iVar2 + -8) = 0;
        *(undefined4 *)((int)pEVar1->err_flags + iVar2 + 0x38) = 0;
        *(undefined4 *)((int)pEVar1->err_data_flags + iVar2 + 0x38) = 0;
        *(undefined4 *)((int)pEVar1->err_file + iVar2 + 0x38) = 0xffffffff;
        pEVar1->err_line[0xe] = uVar3;
        if (uVar3 == uVar4) {
          return 0;
        }
      }
      uVar5 = uVar4 + 1;
      uVar4 = uVar5 & 0xf;
      if ((int)uVar5 < 1) {
        uVar4 = -(-uVar5 & 0xf);
      }
      if ((pEVar1->err_flags[uVar4 - 2] & 2U) == 0) {
        uVar6 = pEVar1->err_flags[uVar4 + 0xe];
        pEVar1->err_line[0xf] = uVar4;
        pEVar1->err_flags[uVar4 + 0xe] = 0;
        if (file != (char **)0x0 && line != (int *)0x0) {
          if ((char *)pEVar1->err_data_flags[uVar4 + 0xe] == (char *)0x0) {
            *file = "NA";
            *line = 0;
          }
          else {
            *file = (char *)pEVar1->err_data_flags[uVar4 + 0xe];
            *line = (int)pEVar1->err_file[uVar4 + 0xe];
          }
        }
        if ((int)pEVar1->err_data[uVar4 + 0xe] << 0x1f < 0) {
          CRYPTO_free((void *)pEVar1->err_buffer[uVar4 + 0xe]);
          pEVar1->err_buffer[uVar4 + 0xe] = 0;
        }
        pEVar1->err_data[uVar4 + 0xe] = (char *)0x0;
        return uVar6;
      }
      pEVar1->err_line[0xf] = uVar4;
      if ((int)pEVar1->err_data[uVar4 + 0xe] << 0x1f < 0) {
        CRYPTO_free((void *)pEVar1->err_buffer[uVar4 + 0xe]);
        uVar4 = pEVar1->err_line[0xf];
        uVar3 = pEVar1->err_line[0xe];
        pEVar1->err_buffer[uVar4 + 0xe] = 0;
      }
      pEVar1->err_data[uVar4 + 0xe] = (char *)0x0;
      pEVar1->err_flags[uVar4 - 2] = 0;
      pEVar1->err_flags[uVar4 + 0xe] = 0;
      pEVar1->err_data_flags[uVar4 + 0xe] = 0;
      pEVar1->err_file[uVar4 + 0xe] = (char *)0xffffffff;
    }
  }
  return 0;
}

