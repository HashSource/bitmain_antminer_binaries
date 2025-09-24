
undefined4 SSL_client_hello_get0_compression_methods(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x5c8);
  if (iVar1 != 0) {
    if (param_2 != (int *)0x0) {
      *param_2 = iVar1 + 0x15c;
      iVar1 = *(int *)(param_1 + 0x5c8);
    }
    return *(undefined4 *)(iVar1 + 0x158);
  }
  return 0;
}

