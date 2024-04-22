
void remove_expired(int **param_1)

{
  int *piVar1;
  int **ppiVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int **ppiVar6;
  int **ppiVar7;
  
  piVar1 = (int *)time((time_t *)0x0);
  iVar5 = (int)piVar1 >> 0x1f;
  if ((int **)*param_1 != (int **)0x0) {
    ppiVar6 = (int **)*param_1;
    ppiVar7 = (int **)0x0;
    do {
      while( true ) {
        ppiVar2 = ppiVar6;
        piVar3 = ppiVar2[6];
        piVar4 = ppiVar2[7];
        ppiVar6 = (int **)*ppiVar2;
        if ((((uint)piVar3 | (uint)piVar4) != 0) &&
           ((int)((int)piVar4 + (-(uint)(piVar3 < piVar1) - iVar5)) < 0 !=
            (SBORROW4((int)piVar4,iVar5) != SBORROW4((int)piVar4 - iVar5,(uint)(piVar3 < piVar1)))))
        break;
        ppiVar7 = ppiVar2;
        if (ppiVar6 == (int **)0x0) {
          return;
        }
      }
      piVar3 = param_1[3];
      if ((int **)*param_1 == ppiVar2) {
        *param_1 = (int *)ppiVar6;
      }
      else {
        *ppiVar7 = (int *)ppiVar6;
      }
      param_1[3] = (int *)((int)piVar3 + -1);
      freecookie(ppiVar2);
    } while (ppiVar6 != (int **)0x0);
  }
  return;
}

