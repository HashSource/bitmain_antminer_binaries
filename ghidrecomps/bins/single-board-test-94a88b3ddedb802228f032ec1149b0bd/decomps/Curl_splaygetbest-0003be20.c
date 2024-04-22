
int ** Curl_splaygetbest(int param_1,int param_2,int param_3,int **param_4)

{
  int **ppiVar1;
  int *piVar2;
  int *piVar3;
  int **ppiVar4;
  int *piVar5;
  
  if (param_3 == 0) {
    *param_4 = (int *)0x0;
    return (int **)0x0;
  }
  ppiVar1 = (int **)Curl_splay(param_1,param_2);
  if ((param_1 < (int)ppiVar1[3]) || ((param_1 <= (int)ppiVar1[3] && (param_2 < (int)ppiVar1[4]))))
  {
    piVar2 = *ppiVar1;
    ppiVar4 = ppiVar1;
    if (piVar2 != (int *)0x0) {
      ppiVar1 = (int **)Curl_splay(piVar2[3],piVar2[4],ppiVar1);
      if (((int)ppiVar1[3] <= param_1) &&
         (((int)ppiVar1[3] < param_1 || ((int)ppiVar1[4] <= param_2)))) goto LAB_0003be50;
      piVar2 = (int *)0x0;
      ppiVar4 = ppiVar1;
    }
    *param_4 = piVar2;
  }
  else {
LAB_0003be50:
    ppiVar4 = (int **)ppiVar1[2];
    if (ppiVar4 == (int **)0x0) {
      if (*ppiVar1 == (int *)0x0) {
        ppiVar4 = (int **)ppiVar1[1];
      }
      else {
        ppiVar4 = (int **)Curl_splay(param_1,param_2);
        ppiVar4[1] = ppiVar1[1];
      }
      *param_4 = (int *)ppiVar1;
    }
    else {
      piVar2 = ppiVar1[3];
      piVar3 = ppiVar1[4];
      piVar5 = *ppiVar1;
      ppiVar4[1] = ppiVar1[1];
      ppiVar4[3] = piVar2;
      ppiVar4[4] = piVar3;
      *ppiVar4 = piVar5;
      *param_4 = (int *)ppiVar1;
    }
  }
  return ppiVar4;
}

