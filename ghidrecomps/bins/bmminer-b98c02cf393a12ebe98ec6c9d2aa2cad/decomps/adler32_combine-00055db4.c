
uint adler32_combine(uint param_1,uint param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int extraout_r2;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_3 >> 0x1f < 0) {
    return 0xffffffff;
  }
  __aeabi_ldivmod(param_3,param_3 >> 0x1f,0xfff1,0,param_4);
  iVar1 = (param_1 & 0xffff) + (param_2 & 0xffff);
  uVar4 = 0xfff0;
  iVar3 = (((param_1 >> 0x10) + (param_2 >> 0x10)) - extraout_r2) +
          ((param_1 & 0xffff) * extraout_r2) % 0xfff1;
  uVar2 = iVar3 + 0xfff1;
  if ((iVar1 != 0) && (uVar4 = iVar1 - 1, 0xfff0 < uVar4)) {
    uVar4 = iVar1 - 0xfff2;
  }
  if (0x1ffe1 < uVar2) {
    uVar2 = iVar3 - 0xfff1;
  }
  if (0xfff0 < uVar2) {
    uVar2 = uVar2 - 0xfff1;
  }
  return uVar4 | uVar2 << 0x10;
}

