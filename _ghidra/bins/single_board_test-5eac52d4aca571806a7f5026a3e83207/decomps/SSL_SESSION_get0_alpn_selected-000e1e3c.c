
void SSL_SESSION_get0_alpn_selected(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x1e8);
  *param_2 = *(undefined4 *)(param_1 + 0x1e4);
  *param_3 = uVar1;
  return;
}

