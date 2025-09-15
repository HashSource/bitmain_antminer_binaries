
undefined4 Curl_llist_remove(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    return 1;
  }
  if (param_1[3] == 0) {
    return 1;
  }
  if ((undefined4 *)*param_1 == param_2) {
    iVar1 = param_2[2];
    *param_1 = iVar1;
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 4) = 0;
      goto LAB_0004c8fe;
    }
  }
  else {
    iVar1 = param_2[1];
    *(undefined4 *)(iVar1 + 8) = param_2[2];
    if (param_2[2] != 0) {
      *(int *)(param_2[2] + 4) = iVar1;
      goto LAB_0004c8fe;
    }
  }
  param_1[1] = iVar1;
LAB_0004c8fe:
  (*(code *)param_1[2])(param_3,*param_2,param_3,(code *)param_1[2],param_4);
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  (*Curl_cfree)(param_2);
  param_1[3] = param_1[3] + -1;
  return 1;
}

