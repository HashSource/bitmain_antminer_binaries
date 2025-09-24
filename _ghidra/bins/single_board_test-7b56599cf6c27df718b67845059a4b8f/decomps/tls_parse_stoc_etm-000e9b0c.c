
undefined4 tls_parse_stoc_etm(int param_1)

{
  int iVar1;
  
  if (((-1 < *(int *)(param_1 + 0x4ec) << 0xc) &&
      (iVar1 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210), *(int *)(iVar1 + 0x1c) != 0x40)) &&
     (iVar1 = *(int *)(iVar1 + 0x18), iVar1 != 0x40000 && (iVar1 != 0x400 && iVar1 != 4))) {
    *(undefined4 *)(param_1 + 0x5a8) = 1;
  }
  return 1;
}

