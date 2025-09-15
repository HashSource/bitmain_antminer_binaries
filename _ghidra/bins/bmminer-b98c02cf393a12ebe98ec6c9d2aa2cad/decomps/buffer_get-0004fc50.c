
uint buffer_get(int *param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = param_1[2];
  uVar1 = param_1[1];
  bVar3 = uVar2 < uVar1;
  if (bVar3) {
    uVar1 = uVar2 + 1;
    uVar2 = (uint)*(byte *)(*param_1 + uVar2);
  }
  if (bVar3) {
    param_1[2] = uVar1;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

