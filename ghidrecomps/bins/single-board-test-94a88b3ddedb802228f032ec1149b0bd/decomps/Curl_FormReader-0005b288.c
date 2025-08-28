
int Curl_FormReader(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint __n;
  
  iVar5 = *param_4;
  param_2 = param_2 * param_3;
  if (iVar5 == 0) {
    return 0;
  }
  uVar3 = *(int *)(iVar5 + 4) - 2;
  if (uVar3 < 2) {
    iVar5 = readfromfile(param_4,param_1,param_2,uVar3,param_4);
    if (iVar5 != 0) {
      return iVar5;
    }
    iVar5 = *param_4;
  }
  iVar4 = param_4[1];
  iVar6 = 0;
  do {
    __n = param_2 - iVar6;
    uVar3 = *(int *)(iVar5 + 0xc) - iVar4;
    if (__n < uVar3) {
      memcpy((void *)(param_1 + iVar6),(void *)(*(int *)(iVar5 + 8) + iVar4),__n);
      param_4[1] = param_4[1] + __n;
      return param_2;
    }
    memcpy((void *)(param_1 + iVar6),(void *)(*(int *)(iVar5 + 8) + iVar4),uVar3);
    iVar4 = 0;
    iVar2 = param_4[1];
    iVar1 = ((int *)*param_4)[3];
    iVar5 = *(int *)*param_4;
    param_4[1] = 0;
    *param_4 = iVar5;
    iVar6 = iVar6 + (iVar1 - iVar2);
  } while ((iVar5 != 0) && (*(uint *)(iVar5 + 4) < 2));
  return iVar6;
}

