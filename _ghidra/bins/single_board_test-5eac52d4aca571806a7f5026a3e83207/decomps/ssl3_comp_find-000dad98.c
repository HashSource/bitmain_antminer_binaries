
int * ssl3_comp_find(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != 0 && param_2 != 0) {
    iVar3 = 0;
    iVar1 = OPENSSL_sk_num();
    if (0 < iVar1) {
      do {
        piVar2 = (int *)OPENSSL_sk_value(param_1,iVar3);
        iVar3 = iVar3 + 1;
        if (param_2 == *piVar2) {
          return piVar2;
        }
      } while (iVar3 != iVar1);
    }
  }
  return (int *)0x0;
}

