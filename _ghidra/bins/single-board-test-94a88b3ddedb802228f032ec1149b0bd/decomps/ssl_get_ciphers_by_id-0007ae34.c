
int ssl_get_ciphers_by_id(int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  if (((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x78), iVar1 == 0)) &&
     (*(int *)(param_1 + 0xe4) != 0)) {
    return *(int *)(*(int *)(param_1 + 0xe4) + 8);
  }
  return iVar1;
}

