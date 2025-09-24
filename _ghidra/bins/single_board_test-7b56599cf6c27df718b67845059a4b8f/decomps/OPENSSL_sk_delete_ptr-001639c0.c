
int OPENSSL_sk_delete_ptr(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = *param_1;
  if (iVar4 < 1) {
    return 0;
  }
  piVar5 = (int *)param_1[1];
  piVar3 = piVar5;
  if (param_2 == *piVar5) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    do {
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + 1;
      if (iVar2 == iVar4) {
        return 0;
      }
    } while (*piVar3 != param_2);
  }
  iVar1 = iVar4 + -1;
  if (iVar1 != iVar2) {
    memmove(piVar3,piVar5 + iVar2 + 1,((iVar4 - iVar2) + -1) * 4);
    iVar1 = *param_1 + -1;
  }
  *param_1 = iVar1;
  return param_2;
}

