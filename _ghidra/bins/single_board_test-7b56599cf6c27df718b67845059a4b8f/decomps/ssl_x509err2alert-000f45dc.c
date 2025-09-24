
int ssl_x509err2alert(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 != 0x32) {
    piVar1 = (int *)&x509table;
    do {
      piVar3 = piVar1;
      piVar1 = piVar3 + 2;
      iVar2 = *piVar1;
    } while (iVar2 != 0 && iVar2 != param_1);
    return piVar3[3];
  }
  return 0x28;
}

