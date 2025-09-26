
undefined4 SSL_client_hello_get0_ciphers(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x5c8);
  if (iVar1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(iVar1 + 0x150);
      iVar1 = *(int *)(param_1 + 0x5c8);
    }
    return *(undefined4 *)(iVar1 + 0x154);
  }
  return 0;
}

