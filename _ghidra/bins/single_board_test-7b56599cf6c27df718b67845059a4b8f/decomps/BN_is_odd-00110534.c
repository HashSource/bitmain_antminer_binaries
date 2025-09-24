
uint BN_is_odd(undefined4 *param_1)

{
  uint uVar1;
  
  if ((int)param_1[1] < 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)*param_1 & 1;
  }
  return uVar1;
}

