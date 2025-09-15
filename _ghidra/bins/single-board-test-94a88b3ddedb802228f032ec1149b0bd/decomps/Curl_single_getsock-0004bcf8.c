
uint Curl_single_getsock(int *param_1,int *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = *param_1;
  if (*(code **)(param_1[0x86] + 0x2c) != (code *)0x0) {
    uVar2 = (**(code **)(param_1[0x86] + 0x2c))();
    return uVar2;
  }
  if (param_3 < 2) {
    return 0;
  }
  uVar2 = *(uint *)(iVar3 + 0x130);
  bVar4 = (uVar2 & 0x15) == 1;
  if (bVar4) {
    *param_2 = param_1[0x89];
    uVar2 = *(uint *)(iVar3 + 0x130);
  }
  uVar1 = (uint)bVar4;
  if ((uVar2 & 0x2a) != 2) {
    return uVar1;
  }
  if (param_1[0x89] == param_1[0x8a]) {
    uVar2 = 0x10000;
    if (uVar1 != 0) goto LAB_0004bd54;
    iVar3 = 0;
  }
  else if (uVar1 == 0) {
    uVar2 = 0x10000;
    iVar3 = 0;
  }
  else {
    uVar2 = 0x20000;
    iVar3 = 4;
  }
  *(int *)((int)param_2 + iVar3) = param_1[0x8a];
LAB_0004bd54:
  return uVar1 | uVar2;
}

