
void SSL_CONF_CTX_set_ssl_ctx(int param_1,int param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (param_2 != 0) {
    iVar1 = *(int *)(param_2 + 0xc0);
    *(int *)(param_1 + 0x14) = param_2 + 0xac;
    *(int *)(param_1 + 0x44) = param_2 + 0xb4;
    *(int *)(param_1 + 0x3c) = iVar1 + 0x10;
    *(int *)(param_1 + 0x48) = param_2 + 0xb8;
    *(int *)(param_1 + 0x40) = param_2 + 0xd0;
    return;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}

