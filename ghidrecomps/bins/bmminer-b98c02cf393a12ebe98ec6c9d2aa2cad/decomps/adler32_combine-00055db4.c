
uint adler32_combine(uint param_1,uint param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_3 >> 0x1f < 0) {
    return 0xffffffff;
  }
  iVar2 = 0xfff1;
  __aeabi_ldivmod(param_3,param_3 >> 0x1f,0xfff1,0,param_4);
  iVar1 = (param_1 & 0xffff) + (param_2 & 0xffff);
  uVar4 = 0xfff0;
  iVar2 = (((param_1 >> 0x10) + (param_2 >> 0x10)) - iVar2) + ((param_1 & 0xffff) * iVar2) % 0xfff1;
  uVar3 = iVar2 + 0xfff1;
  if ((iVar1 != 0) && (uVar4 = iVar1 - 1, 0xfff0 < uVar4)) {
    uVar4 = iVar1 - 0xfff2;
  }
  if (0x1ffe1 < uVar3) {
    uVar3 = iVar2 - 0xfff1;
  }
  if (0xfff0 < uVar3) {
    uVar3 = uVar3 - 0xfff1;
  }
  return uVar4 | uVar3 << 0x10;
}

