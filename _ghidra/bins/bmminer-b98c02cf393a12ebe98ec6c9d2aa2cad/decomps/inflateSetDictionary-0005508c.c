
undefined4 inflateSetDictionary(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  if ((param_1 == 0) || (piVar3 = *(int **)(param_1 + 0x1c), piVar3 == (int *)0x0)) {
    return 0xfffffffe;
  }
  if (piVar3[2] == 0) {
    iVar2 = *piVar3;
    if (iVar2 != 10) goto LAB_000550a4;
  }
  else {
    iVar2 = *piVar3;
    if (iVar2 != 10) {
      return 0xfffffffe;
    }
  }
  uVar1 = adler32(0,0,0,iVar2,param_4);
  iVar2 = adler32(uVar1,param_2,param_3);
  if (piVar3[6] != iVar2) {
    return 0xfffffffd;
  }
LAB_000550a4:
  iVar2 = updatewindow(param_1,param_2 + param_3,param_3);
  if (iVar2 != 0) {
    *piVar3 = 0x1e;
    return 0xfffffffc;
  }
  piVar3[3] = 1;
  return 0;
}

