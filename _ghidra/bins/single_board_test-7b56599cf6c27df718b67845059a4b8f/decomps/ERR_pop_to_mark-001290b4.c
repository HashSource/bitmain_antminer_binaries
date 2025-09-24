
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ERR_pop_to_mark(void)

{
  ERR_STATE *pEVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  pEVar1 = ERR_get_state();
  if (pEVar1 != (ERR_STATE *)0x0) {
    iVar6 = pEVar1->err_line[0xf];
    iVar4 = pEVar1->err_line[0xe];
    if (iVar4 != iVar6) {
      uVar3 = pEVar1->err_flags[iVar4 + -2];
      if ((uVar3 & 1) == 0) {
        do {
          iVar2 = iVar4 * 4;
          iVar5 = iVar4;
          if ((int)pEVar1->err_data[iVar4 + 0xe] << 0x1f < 0) {
            CRYPTO_free((void *)pEVar1->err_buffer[iVar4 + 0xe]);
            iVar5 = pEVar1->err_line[0xe];
            iVar6 = pEVar1->err_line[0xf];
            iVar2 = iVar5 << 2;
            pEVar1->err_buffer[iVar5 + 0xe] = 0;
          }
          iVar4 = iVar5 + -1;
          if (iVar5 < 1) {
            iVar4 = 0xf;
          }
          *(undefined4 *)((int)pEVar1->err_data + iVar2 + 0x38) = 0;
          *(undefined4 *)((int)pEVar1->err_flags + iVar2 + -8) = 0;
          *(undefined4 *)((int)pEVar1->err_flags + iVar2 + 0x38) = 0;
          *(undefined4 *)((int)pEVar1->err_data_flags + iVar2 + 0x38) = 0;
          *(undefined4 *)((int)pEVar1->err_file + iVar2 + 0x38) = 0xffffffff;
          pEVar1->err_line[0xe] = iVar4;
          if (iVar4 == iVar6) {
            return 0;
          }
          uVar3 = pEVar1->err_flags[iVar4 + -2];
        } while (-1 < (int)(uVar3 << 0x1f));
      }
      pEVar1->err_flags[iVar4 + -2] = uVar3 & 0xfffffffe;
      return 1;
    }
  }
  return 0;
}

