
int * ssl3_comp_find(_STACK *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != (_STACK *)0x0 && param_2 != 0) {
    iVar3 = 0;
    iVar1 = sk_num(param_1);
    if (0 < iVar1) {
      do {
        piVar2 = (int *)sk_value(param_1,iVar3);
        iVar3 = iVar3 + 1;
        if (*piVar2 == param_2) {
          return piVar2;
        }
      } while (iVar3 != iVar1);
    }
  }
  return (int *)0x0;
}

