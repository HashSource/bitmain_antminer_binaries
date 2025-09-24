
int ssl_get_ciphers_by_id(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc0);
    if ((iVar1 == 0) && (*(int *)(param_1 + 0x4d0) != 0)) {
      return *(int *)(*(int *)(param_1 + 0x4d0) + 8);
    }
  }
  return iVar1;
}

