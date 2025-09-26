
uint ossl_statem_app_data_allowed(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x2c) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x7c) + 0xfc);
    if ((uVar1 != 0) && (uVar1 = *(uint *)(*(int *)(param_1 + 0x7c) + 0xf4), uVar1 != 0)) {
      iVar2 = *(int *)(param_1 + 0x40);
      if (*(int *)(param_1 + 0x1c) == 0) {
        return (uint)(iVar2 == 0xc);
      }
      return (uint)(iVar2 == 0x14 || iVar2 == 0);
    }
  }
  return uVar1;
}

