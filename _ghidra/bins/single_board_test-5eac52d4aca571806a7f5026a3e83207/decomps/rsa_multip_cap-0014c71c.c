
undefined4 rsa_multip_cap(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x400) {
    return 2;
  }
  if (0xfff < param_1) {
    if (param_1 < 0x2000) {
      uVar1 = 4;
    }
    else {
      uVar1 = 5;
    }
    return uVar1;
  }
  return 3;
}

