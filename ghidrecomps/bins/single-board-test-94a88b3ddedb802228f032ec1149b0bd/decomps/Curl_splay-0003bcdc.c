
int * Curl_splay(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int local_28;
  int local_24;
  
  if (param_3 == (int *)0x0) {
    return (int *)0x0;
  }
  piVar7 = &local_28;
  local_28 = 0;
  local_24 = 0;
  piVar8 = piVar7;
  do {
    iVar5 = param_3[3];
    iVar1 = iVar5 - param_1;
    piVar4 = param_3;
    while (iVar5 <= param_1) {
      if (iVar1 < 0 == SBORROW4(iVar5,param_1)) {
        if (piVar4[4] <= param_2) {
          if (piVar4[4] < param_2) goto LAB_0003bd06;
LAB_0003bd76:
          piVar3 = (int *)*piVar4;
          piVar6 = piVar4;
          goto LAB_0003bd60;
        }
        break;
      }
LAB_0003bd06:
      piVar6 = (int *)piVar4[1];
      if (piVar6 == (int *)0x0) goto LAB_0003bd76;
      piVar2 = piVar4;
      if ((piVar6[3] <= param_1) && ((piVar6[3] < param_1 || (piVar6[4] < param_2)))) {
        iVar1 = *piVar6;
        *piVar6 = (int)piVar4;
        piVar4[1] = iVar1;
        piVar3 = piVar4;
        piVar2 = piVar6;
        if (piVar6[1] == 0) goto LAB_0003bd60;
      }
      piVar7[1] = (int)piVar2;
      piVar4 = (int *)piVar2[1];
      iVar5 = piVar4[3];
      iVar1 = iVar5 - param_1;
      piVar7 = piVar2;
    }
    piVar2 = (int *)*piVar4;
    piVar3 = piVar2;
    piVar6 = piVar4;
    if (piVar2 == (int *)0x0) goto LAB_0003bd60;
    if ((param_1 < piVar2[3]) || ((param_1 <= piVar2[3] && (param_2 < piVar2[4])))) {
      iVar1 = piVar2[1];
      piVar2[1] = (int)piVar4;
      *piVar4 = iVar1;
      piVar4 = piVar2;
      if (*piVar2 == 0) {
        piVar3 = (int *)0x0;
        piVar6 = piVar2;
LAB_0003bd60:
        piVar7[1] = (int)piVar3;
        *piVar8 = piVar6[1];
        *piVar6 = local_24;
        piVar6[1] = local_28;
        return piVar6;
      }
    }
    *piVar8 = (int)piVar4;
    param_3 = (int *)*piVar4;
    piVar8 = piVar4;
  } while( true );
}

