
void remove_expired(int *param_1)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  uVar1 = time((time_t *)0x0);
  iVar5 = (int)uVar1 >> 0x1f;
  if ((int *)*param_1 != (int *)0x0) {
    piVar6 = (int *)*param_1;
    piVar7 = (int *)0x0;
    do {
      while( true ) {
        piVar2 = piVar6;
        uVar3 = piVar2[6];
        iVar4 = piVar2[7];
        piVar6 = (int *)*piVar2;
        if ((uVar3 != 0 || iVar4 != 0) &&
           ((int)((iVar4 - iVar5) - (uint)(uVar3 < uVar1)) < 0 !=
            (SBORROW4(iVar4,iVar5) != SBORROW4(iVar4 - iVar5,(uint)(uVar3 < uVar1))))) break;
        piVar7 = piVar2;
        if (piVar6 == (int *)0x0) {
          return;
        }
      }
      iVar4 = param_1[3];
      if ((int *)*param_1 == piVar2) {
        *param_1 = (int)piVar6;
      }
      else {
        *piVar7 = (int)piVar6;
      }
      param_1[3] = iVar4 + -1;
      freecookie(piVar2);
    } while (piVar6 != (int *)0x0);
  }
  return;
}

