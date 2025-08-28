
int * Curl_splaygetbest(int param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_3 == 0) {
    *param_4 = 0;
    return (int *)0x0;
  }
  piVar1 = (int *)Curl_splay(param_1,param_2);
  if ((param_1 < piVar1[3]) || ((param_1 <= piVar1[3] && (param_2 < piVar1[4])))) {
    iVar2 = *piVar1;
    piVar4 = piVar1;
    if (iVar2 != 0) {
      piVar1 = (int *)Curl_splay(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x10),piVar1);
      if ((piVar1[3] <= param_1) && ((piVar1[3] < param_1 || (piVar1[4] <= param_2))))
      goto LAB_0003be50;
      iVar2 = 0;
      piVar4 = piVar1;
    }
    *param_4 = iVar2;
  }
  else {
LAB_0003be50:
    piVar4 = (int *)piVar1[2];
    if (piVar4 == (int *)0x0) {
      if (*piVar1 == 0) {
        piVar4 = (int *)piVar1[1];
      }
      else {
        piVar4 = (int *)Curl_splay(param_1,param_2);
        piVar4[1] = piVar1[1];
      }
      *param_4 = (int)piVar1;
    }
    else {
      iVar2 = piVar1[3];
      iVar3 = piVar1[4];
      iVar5 = *piVar1;
      piVar4[1] = piVar1[1];
      piVar4[3] = iVar2;
      piVar4[4] = iVar3;
      *piVar4 = iVar5;
      *param_4 = (int)piVar1;
    }
  }
  return piVar4;
}

