
int PKCS12_mac_present(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

