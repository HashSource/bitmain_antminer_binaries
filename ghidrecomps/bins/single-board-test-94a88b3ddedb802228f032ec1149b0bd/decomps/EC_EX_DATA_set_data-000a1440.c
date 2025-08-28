
undefined4 EC_EX_DATA_set_data(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    for (piVar1 = (int *)*param_1; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      if (((piVar1[2] == param_3) && (piVar1[3] == param_4)) && (piVar1[4] == param_5)) {
        ERR_put_error(0x10,0xd3,0x6c,"ec_lib.c",0x239);
        return 0;
      }
    }
    if (param_2 == 0) {
      return 1;
    }
    piVar1 = (int *)CRYPTO_malloc(0x14,"ec_lib.c",0x242);
    if (piVar1 != (int *)0x0) {
      piVar1[1] = param_2;
      piVar1[2] = param_3;
      piVar1[3] = param_4;
      piVar1[4] = param_5;
      *piVar1 = *param_1;
      *param_1 = (int)piVar1;
      return 1;
    }
  }
  return 0;
}

