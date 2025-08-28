
void EC_EX_DATA_free_data(int *param_1,int param_2,code *param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    piVar2 = (int *)*param_1;
    while (piVar1 = piVar2, piVar1 != (int *)0x0) {
      if (((piVar1[2] == param_2) && ((code *)piVar1[3] == param_3)) && (piVar1[4] == param_4)) {
        iVar3 = *piVar1;
        (*param_3)(piVar1[1]);
        CRYPTO_free((void *)*param_1);
        *param_1 = iVar3;
        return;
      }
      param_1 = piVar1;
      piVar2 = (int *)*piVar1;
    }
  }
  return;
}

