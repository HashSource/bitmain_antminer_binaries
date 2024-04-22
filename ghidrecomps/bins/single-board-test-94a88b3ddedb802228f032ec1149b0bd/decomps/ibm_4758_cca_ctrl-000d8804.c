
char * ibm_4758_cca_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar1 = DAT_000d8898;
  if (param_2 == 200) {
    if (param_4 == (char *)0x0) {
      iVar2 = *(int *)(DAT_000d8898 + 0xc);
      if (iVar2 == 0) {
        iVar2 = ERR_get_next_error_library();
        *(int *)(iVar1 + 0xc) = iVar2;
      }
      ERR_put_error(iVar2,100,0x43,DAT_000d889c,0x178);
      pcVar3 = (char *)0x0;
    }
    else if (*(int *)(DAT_000d8898 + 0x14) == 0) {
      if (*(void **)(DAT_000d8898 + 0x10) != (void *)0x0) {
        CRYPTO_free(*(void **)(DAT_000d8898 + 0x10));
      }
      *(undefined4 *)(iVar1 + 0x10) = 0;
      pcVar3 = BUF_strdup(param_4);
      *(char **)(iVar1 + 0x10) = pcVar3;
      if (pcVar3 != (char *)0x0) {
        pcVar3 = (char *)0x1;
      }
    }
    else {
      iVar2 = *(int *)(DAT_000d8898 + 0xc);
      if (iVar2 == 0) {
        iVar2 = ERR_get_next_error_library();
        *(int *)(iVar1 + 0xc) = iVar2;
      }
      ERR_put_error(iVar2,100,100,DAT_000d889c,0x17c);
      pcVar3 = (char *)0x0;
    }
  }
  else {
    iVar2 = *(int *)(DAT_000d8898 + 0xc);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar1 + 0xc) = iVar2;
    }
    ERR_put_error(iVar2,100,0x66,DAT_000d889c,0x184);
    pcVar3 = (char *)0x0;
  }
  return pcVar3;
}

