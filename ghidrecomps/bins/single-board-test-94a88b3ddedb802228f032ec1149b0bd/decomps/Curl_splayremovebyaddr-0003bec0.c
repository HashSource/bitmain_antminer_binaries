
undefined4 Curl_splayremovebyaddr(int *param_1,int *param_2,int **param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_1 == (int *)0x0 || param_2 == (int *)0x0) {
    return 1;
  }
  if ((param_2[3] == -1) && (param_2[4] == -1)) {
    iVar2 = *param_2;
    if (iVar2 != 0) {
      *(int *)(iVar2 + 8) = param_2[2];
      if ((int *)param_2[2] != (int *)0x0) {
        *(int *)param_2[2] = iVar2;
      }
      *param_2 = 0;
      *param_3 = param_1;
      return 0;
    }
    return 3;
  }
  piVar4 = param_2 + 3;
  piVar1 = (int *)Curl_splay(*piVar4,param_2[4],param_1);
  if (param_2 != piVar1) {
    return 2;
  }
  piVar1 = (int *)param_2[2];
  if (piVar1 == (int *)0x0) {
    if (*param_2 == 0) {
      piVar1 = (int *)param_2[1];
    }
    else {
      piVar1 = (int *)Curl_splay(*piVar4,param_2[4]);
      piVar1[1] = param_2[1];
    }
  }
  else {
    iVar2 = param_2[4];
    iVar3 = *param_2;
    iVar5 = param_2[1];
    piVar1[3] = *piVar4;
    piVar1[4] = iVar2;
    *piVar1 = iVar3;
    piVar1[1] = iVar5;
  }
  *param_3 = piVar1;
  return 0;
}

