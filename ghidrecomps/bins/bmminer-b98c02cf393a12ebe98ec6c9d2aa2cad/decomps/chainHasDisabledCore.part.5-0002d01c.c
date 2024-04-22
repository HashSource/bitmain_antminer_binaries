
undefined4 chainHasDisabledCore_part_5(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 0x10 + DAT_0002d044;
  while ((0x53 < *(byte *)(iVar1 + 2) || (0x71 < *(byte *)(iVar1 + 3)))) {
    iVar1 = iVar1 + 2;
    if (iVar1 == param_1 * 0x10 + 0xe + DAT_0002d044) {
      return 0;
    }
  }
  return 1;
}

