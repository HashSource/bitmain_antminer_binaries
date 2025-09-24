
void SSL_CONF_CTX_set_ssl(int param_1,int param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (param_2 != 0) {
    iVar1 = *(int *)(param_2 + 0x404);
    *(int *)(param_1 + 0x14) = param_2 + 0x4ec;
    *(int *)(param_1 + 0x44) = param_2 + 0x4f4;
    *(int *)(param_1 + 0x3c) = iVar1 + 0x10;
    *(int *)(param_1 + 0x48) = param_2 + 0x4f8;
    *(int *)(param_1 + 0x40) = param_2 + 0x4ac;
    return;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}

