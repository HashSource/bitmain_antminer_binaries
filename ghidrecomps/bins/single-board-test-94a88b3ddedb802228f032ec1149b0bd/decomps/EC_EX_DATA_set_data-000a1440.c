
undefined4 EC_EX_DATA_set_data(int **param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int **ppiVar1;
  int *piVar2;
  
  if (param_1 != (int **)0x0) {
    for (piVar2 = *param_1; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      if ((((int *)piVar2[2] == param_3) && ((int *)piVar2[3] == param_4)) &&
         ((int *)piVar2[4] == param_5)) {
        ERR_put_error(0x10,0xd3,0x6c,DAT_000a14b8,0x239);
        return 0;
      }
    }
    if (param_2 == (int *)0x0) {
      return 1;
    }
    ppiVar1 = (int **)CRYPTO_malloc(0x14,DAT_000a14b8,0x242);
    if (ppiVar1 != (int **)0x0) {
      ppiVar1[1] = param_2;
      ppiVar1[2] = param_3;
      ppiVar1[3] = param_4;
      ppiVar1[4] = param_5;
      *ppiVar1 = *param_1;
      *param_1 = (int *)ppiVar1;
      return 1;
    }
  }
  return 0;
}

