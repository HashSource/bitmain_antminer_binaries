
undefined4 tls_parse_ctos_etm(int param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)(param_1 + 0x4ec) << 0xc;
  bVar2 = -1 < iVar1;
  if (bVar2) {
    iVar1 = 1;
  }
  if (bVar2) {
    *(int *)(param_1 + 0x5a8) = iVar1;
  }
  return 1;
}

