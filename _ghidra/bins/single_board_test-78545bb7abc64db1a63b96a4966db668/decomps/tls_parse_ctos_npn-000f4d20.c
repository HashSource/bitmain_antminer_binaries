
undefined4 tls_parse_ctos_npn(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x7c);
  if ((*(int *)(iVar1 + 0x180) == 0) || (*(int *)(iVar1 + 0x204) == 0)) {
    *(undefined4 *)(iVar1 + 0x33c) = 1;
  }
  return 1;
}

