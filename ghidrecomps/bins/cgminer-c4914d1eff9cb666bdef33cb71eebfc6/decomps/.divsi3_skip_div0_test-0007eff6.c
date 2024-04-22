
uint _divsi3_skip_div0_test(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char in_NG;
  
  uVar3 = param_1 ^ param_2;
  uVar1 = param_2;
  if (in_NG != '\0') {
    uVar1 = -param_2;
  }
  if (uVar1 - 1 == 0) {
    if ((int)param_2 < 0) {
      param_1 = -param_1;
    }
    return param_1;
  }
  uVar2 = param_1;
  if ((int)param_1 < 0) {
    uVar2 = -param_1;
  }
  if (uVar2 <= uVar1) {
    if (uVar2 < uVar1) {
      param_1 = 0;
    }
    if (uVar2 == uVar1) {
      param_1 = (int)uVar3 >> 0x1f | 1;
    }
    return param_1;
  }
  if ((uVar1 & uVar1 - 1) == 0) {
    uVar2 = uVar2 >> (0x1fU - LZCOUNT(uVar1) & 0xff);
    if ((int)uVar3 < 0) {
      uVar2 = -uVar2;
    }
    return uVar2;
  }
                    /* WARNING: Could not recover jumptable at 0x0007f030. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(&UNK_0007f038 + (0x1f - (LZCOUNT(uVar1) - LZCOUNT(uVar2))) * 0x10))(0);
  return uVar1;
}

