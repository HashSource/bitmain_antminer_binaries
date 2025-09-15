
uint string_get(int *param_1)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *(byte *)(*param_1 + param_1[1]);
  if (bVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    param_1[1] = param_1[1] + 1;
    uVar2 = (uint)bVar1;
  }
  return uVar2;
}

