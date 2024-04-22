
uint string_get(int *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(*param_1 + param_1[1]);
  if (uVar1 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    param_1[1] = param_1[1] + 1;
  }
  return uVar1;
}

