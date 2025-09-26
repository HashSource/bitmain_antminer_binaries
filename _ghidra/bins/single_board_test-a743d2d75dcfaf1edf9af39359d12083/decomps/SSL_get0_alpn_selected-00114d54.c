
void SSL_get0_alpn_selected(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  *param_2 = 0;
  if ((*(int *)(param_1 + 0x58) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x424), *param_2 = iVar1, iVar1 != 0)) {
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x428);
    return;
  }
  *param_3 = 0;
  return;
}

