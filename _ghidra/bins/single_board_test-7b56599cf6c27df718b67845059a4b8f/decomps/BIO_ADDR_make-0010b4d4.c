
undefined4 BIO_ADDR_make(undefined4 *param_1,short *param_2)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  sVar1 = *param_2;
  if (sVar1 == 2) {
    uVar4 = *(undefined4 *)(param_2 + 2);
    uVar3 = *(undefined4 *)(param_2 + 6);
    uVar2 = *(undefined4 *)(param_2 + 4);
    *param_1 = *(undefined4 *)param_2;
    param_1[1] = uVar4;
    param_1[2] = uVar2;
    param_1[3] = uVar3;
    return 1;
  }
  if (sVar1 != 10) {
    if (sVar1 != 1) {
      return 0;
    }
    memcpy(param_1,param_2,0x6e);
    return 1;
  }
  uVar3 = *(undefined4 *)(param_2 + 2);
  uVar4 = *(undefined4 *)(param_2 + 6);
  uVar2 = *(undefined4 *)(param_2 + 4);
  *param_1 = *(undefined4 *)param_2;
  param_1[1] = uVar3;
  param_1[2] = uVar2;
  param_1[3] = uVar4;
  uVar3 = *(undefined4 *)(param_2 + 10);
  uVar2 = *(undefined4 *)(param_2 + 0xc);
  param_1[4] = *(undefined4 *)(param_2 + 8);
  param_1[5] = uVar3;
  param_1[6] = uVar2;
  return 1;
}

