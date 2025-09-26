
undefined4 tls_parse_stoc_ems(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x8c);
  **(uint **)(param_1 + 0x7c) = **(uint **)(param_1 + 0x7c) | 0x200;
  if (iVar1 == 0) {
    *(uint *)(*(int *)(param_1 + 0x474) + 0x1fc) = *(uint *)(*(int *)(param_1 + 0x474) + 0x1fc) | 1;
  }
  return 1;
}

