
uint buffer_get(int *param_1)

{
  byte bVar1;
  uint uVar2;
  
  if ((uint)param_1[2] < (uint)param_1[1]) {
    bVar1 = *(byte *)(*param_1 + param_1[2]);
    param_1[2] = param_1[2] + 1;
    uVar2 = (uint)bVar1;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

