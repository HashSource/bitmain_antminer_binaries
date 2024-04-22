
int dprintf_DollarString(byte *param_1,byte **param_2)

{
  ushort **ppuVar1;
  int iVar2;
  uint uVar3;
  
  ppuVar1 = __ctype_b_loc();
  iVar2 = 0;
  while( true ) {
    uVar3 = (uint)*param_1;
    if (((*ppuVar1)[uVar3] & 0x800) == 0) break;
    iVar2 = (uVar3 - 0x30) + iVar2 * 10;
    param_1 = param_1 + 1;
  }
  if (iVar2 != 0) {
    if (uVar3 == 0x24) {
      *param_2 = param_1 + 1;
      return iVar2;
    }
    iVar2 = 0;
  }
  return iVar2;
}

