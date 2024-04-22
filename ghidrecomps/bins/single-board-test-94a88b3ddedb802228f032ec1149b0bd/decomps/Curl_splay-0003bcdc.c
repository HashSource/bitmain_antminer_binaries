
int ** Curl_splay(int param_1,int param_2,int **param_3)

{
  int iVar1;
  int **ppiVar2;
  int **ppiVar3;
  int **ppiVar4;
  int *piVar5;
  int **ppiVar6;
  int **ppiVar7;
  int **ppiVar8;
  int *local_28;
  int *local_24;
  
  if (param_3 == (int **)0x0) {
    return (int **)0x0;
  }
  ppiVar7 = &local_28;
  local_28 = (int *)0x0;
  local_24 = (int *)0x0;
  ppiVar8 = ppiVar7;
  do {
    piVar5 = param_3[3];
    iVar1 = (int)piVar5 - param_1;
    ppiVar4 = param_3;
    while ((int)piVar5 <= param_1) {
      if (iVar1 < 0 == SBORROW4((int)piVar5,param_1)) {
        if ((int)ppiVar4[4] <= param_2) {
          if ((int)ppiVar4[4] < param_2) goto LAB_0003bd06;
LAB_0003bd76:
          ppiVar3 = (int **)*ppiVar4;
          ppiVar6 = ppiVar4;
          goto LAB_0003bd60;
        }
        break;
      }
LAB_0003bd06:
      ppiVar6 = (int **)ppiVar4[1];
      if (ppiVar6 == (int **)0x0) goto LAB_0003bd76;
      ppiVar2 = ppiVar4;
      if (((int)ppiVar6[3] <= param_1) &&
         (((int)ppiVar6[3] < param_1 || ((int)ppiVar6[4] < param_2)))) {
        piVar5 = *ppiVar6;
        *ppiVar6 = (int *)ppiVar4;
        ppiVar4[1] = piVar5;
        ppiVar3 = ppiVar4;
        ppiVar2 = ppiVar6;
        if (ppiVar6[1] == (int *)0x0) goto LAB_0003bd60;
      }
      ppiVar7[1] = (int *)ppiVar2;
      ppiVar4 = (int **)ppiVar2[1];
      piVar5 = ppiVar4[3];
      iVar1 = (int)piVar5 - param_1;
      ppiVar7 = ppiVar2;
    }
    ppiVar2 = (int **)*ppiVar4;
    ppiVar3 = ppiVar2;
    ppiVar6 = ppiVar4;
    if (ppiVar2 == (int **)0x0) goto LAB_0003bd60;
    if ((param_1 < (int)ppiVar2[3]) || ((param_1 <= (int)ppiVar2[3] && (param_2 < (int)ppiVar2[4])))
       ) {
      piVar5 = ppiVar2[1];
      ppiVar2[1] = (int *)ppiVar4;
      *ppiVar4 = piVar5;
      ppiVar4 = ppiVar2;
      if (*ppiVar2 == (int *)0x0) {
        ppiVar3 = (int **)0x0;
        ppiVar6 = ppiVar2;
LAB_0003bd60:
        ppiVar7[1] = (int *)ppiVar3;
        *ppiVar8 = ppiVar6[1];
        *ppiVar6 = local_24;
        ppiVar6[1] = local_28;
        return ppiVar6;
      }
    }
    *ppiVar8 = (int *)ppiVar4;
    param_3 = (int **)*ppiVar4;
    ppiVar8 = ppiVar4;
  } while( true );
}

