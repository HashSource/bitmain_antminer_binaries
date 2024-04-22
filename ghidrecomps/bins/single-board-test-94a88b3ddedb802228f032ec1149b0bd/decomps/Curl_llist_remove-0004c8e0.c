
undefined4 Curl_llist_remove(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  code **ppcVar1;
  int iVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    return 1;
  }
  if (param_1[3] == 0) {
    return 1;
  }
  if ((undefined4 *)*param_1 == param_2) {
    iVar2 = param_2[2];
    *param_1 = iVar2;
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 4) = 0;
      goto LAB_0004c8fe;
    }
  }
  else {
    iVar2 = param_2[1];
    *(undefined4 *)(iVar2 + 8) = param_2[2];
    if (param_2[2] != 0) {
      *(int *)(param_2[2] + 4) = iVar2;
      goto LAB_0004c8fe;
    }
  }
  param_1[1] = iVar2;
LAB_0004c8fe:
  (*(code *)param_1[2])(param_3,*param_2,param_3,(code *)param_1[2],param_4);
  ppcVar1 = DAT_0004c930;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  (**ppcVar1)(param_2);
  param_1[3] = param_1[3] + -1;
  return 1;
}

