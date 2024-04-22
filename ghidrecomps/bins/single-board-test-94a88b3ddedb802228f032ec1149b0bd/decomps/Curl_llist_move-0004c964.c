
undefined4 Curl_llist_move(int *param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = param_1[3];
  if (iVar1 == 0) {
    return 0;
  }
  if (*param_1 == param_2) {
    iVar3 = *(int *)(param_2 + 8);
    *param_1 = iVar3;
    if (iVar3 != 0) {
      *(undefined4 *)(iVar3 + 4) = 0;
      goto LAB_0004c982;
    }
  }
  else {
    iVar3 = *(int *)(param_2 + 4);
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(param_2 + 8);
    if (*(int *)(param_2 + 8) != 0) {
      *(int *)(*(int *)(param_2 + 8) + 4) = iVar3;
      goto LAB_0004c982;
    }
  }
  param_1[1] = iVar3;
LAB_0004c982:
  param_1[3] = iVar1 + -1;
  iVar1 = param_3[3];
  if (iVar1 == 0) {
    *param_3 = param_2;
    *(undefined4 *)(param_2 + 4) = 0;
    *(undefined4 *)(param_2 + 8) = 0;
    param_3[1] = param_2;
  }
  else {
    uVar2 = *(undefined4 *)(param_4 + 8);
    *(int *)(param_2 + 4) = param_4;
    *(undefined4 *)(param_2 + 8) = uVar2;
    if (*(int *)(param_4 + 8) == 0) {
      param_3[1] = param_2;
    }
    else {
      *(int *)(*(int *)(param_4 + 8) + 4) = param_2;
    }
    *(int *)(param_4 + 8) = param_2;
  }
  param_3[3] = iVar1 + 1;
  return 1;
}

