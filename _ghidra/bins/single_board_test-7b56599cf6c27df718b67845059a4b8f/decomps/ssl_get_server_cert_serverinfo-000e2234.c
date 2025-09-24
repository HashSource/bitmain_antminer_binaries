
int ssl_get_server_cert_serverinfo(int param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + 0x264);
  *param_3 = 0;
  if (iVar2 != 0) {
    piVar1 = (int *)(iVar2 + 0xc);
    if (*piVar1 == 0) {
      return 0;
    }
    uVar3 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = 1;
    *param_2 = *piVar1;
    *param_3 = uVar3;
  }
  return iVar2;
}

