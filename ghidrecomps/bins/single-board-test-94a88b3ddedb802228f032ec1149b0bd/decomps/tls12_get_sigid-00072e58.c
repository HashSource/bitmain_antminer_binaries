
undefined4 tls12_get_sigid(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == *(int *)(DAT_00072e84 + 0x30)) {
    iVar1 = DAT_00072e84 + 0x30;
  }
  else if (iVar1 == *(int *)(DAT_00072e84 + 0x38)) {
    iVar1 = DAT_00072e84 + 0x38;
  }
  else {
    if (iVar1 != *(int *)(DAT_00072e84 + 0x40)) {
      return 0xffffffff;
    }
    iVar1 = DAT_00072e84 + 0x40;
  }
  return *(undefined4 *)(iVar1 + 4);
}

