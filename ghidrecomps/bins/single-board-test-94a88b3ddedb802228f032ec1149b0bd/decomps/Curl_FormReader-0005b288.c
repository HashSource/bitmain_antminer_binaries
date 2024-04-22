
int Curl_FormReader(int param_1,int param_2,int param_3,int **param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  size_t __n;
  
  piVar4 = *param_4;
  param_2 = param_2 * param_3;
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  if (piVar4[1] - 2U < 2) {
    iVar5 = readfromfile(param_4,param_1,param_2,piVar4[1] - 2U,param_4);
    if (iVar5 != 0) {
      return iVar5;
    }
    piVar4 = *param_4;
  }
  piVar3 = param_4[1];
  iVar5 = 0;
  do {
    __n = param_2 - iVar5;
    if (__n < (uint)(piVar4[3] - (int)piVar3)) {
      memcpy((void *)(param_1 + iVar5),(void *)(piVar4[2] + (int)piVar3),__n);
      param_4[1] = (int *)((int)param_4[1] + __n);
      return param_2;
    }
    memcpy((void *)(param_1 + iVar5),(void *)(piVar4[2] + (int)piVar3),piVar4[3] - (int)piVar3);
    piVar3 = (int *)0x0;
    piVar2 = param_4[1];
    iVar1 = (*param_4)[3];
    piVar4 = (int *)**param_4;
    param_4[1] = (int *)0x0;
    *param_4 = piVar4;
    iVar5 = iVar5 + (iVar1 - (int)piVar2);
  } while ((piVar4 != (int *)0x0) && ((uint)piVar4[1] < 2));
  return iVar5;
}

