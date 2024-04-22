
int Curl_clone_ssl_config(undefined4 *param_1,undefined4 *param_2)

{
  undefined uVar1;
  undefined uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = *(undefined *)((int)param_1 + 9);
  uVar2 = *(undefined *)(param_1 + 2);
  uVar4 = *param_1;
  iVar3 = param_1[4];
  *(undefined *)(param_2 + 0xd) = *(undefined *)(param_1 + 0xd);
  *(undefined *)((int)param_2 + 9) = uVar1;
  *(undefined *)(param_2 + 2) = uVar2;
  *param_2 = uVar4;
  if (iVar3 == 0) {
    param_2[4] = 0;
    iVar3 = param_1[3];
  }
  else {
    iVar3 = (**DAT_0003c81c)();
    param_2[4] = iVar3;
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = param_1[3];
  }
  if (iVar3 == 0) {
    param_2[3] = 0;
    iVar3 = param_1[9];
  }
  else {
    iVar3 = (**DAT_0003c81c)();
    param_2[3] = iVar3;
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = param_1[9];
  }
  if (iVar3 == 0) {
    param_2[9] = 0;
    iVar3 = param_1[8];
  }
  else {
    iVar3 = (**DAT_0003c81c)();
    param_2[9] = iVar3;
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = param_1[8];
  }
  if (iVar3 == 0) {
    iVar3 = param_1[7];
    param_2[8] = 0;
  }
  else {
    iVar3 = (**DAT_0003c81c)();
    param_2[8] = iVar3;
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = param_1[7];
  }
  if (iVar3 == 0) {
    param_2[7] = 0;
    return 1;
  }
  iVar3 = (**DAT_0003c81c)(iVar3);
  param_2[7] = iVar3;
  if (iVar3 != 0) {
    iVar3 = 1;
  }
  return iVar3;
}

