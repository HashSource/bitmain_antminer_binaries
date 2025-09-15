
undefined4 inflateGetHeader(int param_1,int param_2)

{
  int iVar1;
  
  if (((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x1c), iVar1 != 0)) &&
     (*(int *)(iVar1 + 8) << 0x1e < 0)) {
    *(int *)(iVar1 + 0x20) = param_2;
    *(undefined4 *)(param_2 + 0x30) = 0;
    return 0;
  }
  return 0xfffffffe;
}

