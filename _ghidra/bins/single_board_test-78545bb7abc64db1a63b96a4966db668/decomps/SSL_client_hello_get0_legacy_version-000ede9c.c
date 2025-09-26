
int SSL_client_hello_get0_legacy_version(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x5c8);
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 4);
  }
  return iVar1;
}

