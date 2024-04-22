
uint __aeabi_uidiv(uint param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 - 1 == 0) {
    return param_1;
  }
  if (param_2 == 0) {
    if (param_1 != 0) {
      param_1 = 0xffffffff;
    }
    uVar1 = __aeabi_ldiv0(param_1);
    return uVar1;
  }
  if (param_1 <= param_2) {
    return (uint)(param_1 == param_2);
  }
  if ((param_2 & param_2 - 1) == 0) {
    return param_1 >> (0x1fU - LZCOUNT(param_2) & 0xff);
  }
                    /* WARNING: Could not recover jumptable at 0x0006b770. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(&UNK_0006b778 + (0x1f - (LZCOUNT(param_2) - LZCOUNT(param_1))) * 0x10))
                    (param_1,param_2,0);
  return uVar1;
}

