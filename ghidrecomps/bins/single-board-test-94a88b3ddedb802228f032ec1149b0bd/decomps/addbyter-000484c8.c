
uint addbyter(byte param_1,byte **param_2)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (param_2[1] < param_2[2]) {
    **param_2 = param_1;
    *param_2 = *param_2 + 1;
    param_2[1] = param_2[1] + 1;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

