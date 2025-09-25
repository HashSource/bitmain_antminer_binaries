
bool cmd_Ciphersuites(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 extraout_r2;
  int iVar2;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = SSL_CTX_set_ciphersuites();
    param_3 = extraout_r2;
  }
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 != 0) {
    iVar1 = SSL_set_ciphersuites(iVar2,param_2,param_3,iVar2,param_4);
  }
  return 0 < iVar1;
}

