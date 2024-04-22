
int GetBandValue(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = calculate_core_number(0x72);
  iVar2 = __aeabi_idiv(0x1000000,uVar1);
  iVar2 = __aeabi_idiv(iVar2 << 1,param_1);
  conf._20_4_ = (iVar2 * 0x5f) / 100;
  iVar2 = __aeabi_idiv(&DAT_00196e6a,conf._20_4_);
  iVar2 = __aeabi_uidiv(0x2faf08,iVar2 << 9);
  return iVar2 + -1;
}

