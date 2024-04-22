
undefined4
curl_global_init_mem(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = DAT_0003877c;
  if (((param_2 == 0 || param_3 == 0) || (param_4 == 0 || param_5 == 0)) ||
     (uVar2 = 0, param_6 == 0)) {
    uVar2 = 2;
  }
  else {
    if (*DAT_00038780 == 0) {
      *DAT_0003877c = param_2;
      piVar1[1] = param_3;
      piVar1[3] = param_5;
      piVar1[2] = param_4;
      piVar1[4] = param_6;
      uVar2 = global_init();
      return uVar2;
    }
    *DAT_00038780 = *DAT_00038780 + 1;
  }
  return uVar2;
}

