
int SSL_get0_peer_CA_list(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x7c);
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 0x224);
  }
  return iVar1;
}

