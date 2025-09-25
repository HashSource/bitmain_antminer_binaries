
void bn_mul_comba4(int *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  *param_1 = *param_2 * *param_3;
  uVar4 = *param_3 * param_2[1];
  uVar1 = param_3[1] * *param_2 + uVar4;
  param_1[1] = uVar1;
  if (uVar4 < uVar1 || uVar4 - uVar1 == 0) {
    uVar1 = *param_3 * param_2[2];
  }
  else {
    iVar2 = *param_3 * param_2[2];
    uVar1 = iVar2 + 1;
    if (iVar2 == -1) {
      uVar4 = 1;
      goto LAB_00183d12;
    }
  }
  uVar4 = 0;
LAB_00183d12:
  uVar3 = param_3[1] * param_2[1] + uVar1;
  if (CARRY4(param_3[1] * param_2[1],uVar1)) {
    uVar4 = uVar4 + 1;
  }
  if (CARRY4(uVar3,param_3[2] * *param_2)) {
    uVar4 = uVar4 + 1;
  }
  param_1[2] = uVar3 + param_3[2] * *param_2;
  uVar1 = param_3[3] * *param_2 + uVar4;
  uVar3 = (uint)CARRY4(param_3[3] * *param_2,uVar4);
  uVar4 = uVar1 + param_3[2] * param_2[1];
  if (CARRY4(uVar1,param_3[2] * param_2[1])) {
    uVar3 = uVar3 + 1;
  }
  iVar5 = param_2[3];
  uVar1 = param_3[1] * param_2[2] + uVar4;
  iVar2 = *param_3;
  if (CARRY4(param_3[1] * param_2[2],uVar4)) {
    uVar3 = uVar3 + 1;
  }
  param_1[3] = iVar2 * iVar5 + uVar1;
  if (CARRY4(iVar2 * iVar5,uVar1)) {
    uVar3 = uVar3 + 1;
  }
  iVar2 = param_2[1];
  uVar4 = param_3[1] * param_2[3] + uVar3;
  uVar3 = (uint)CARRY4(param_3[1] * param_2[3],uVar3);
  uVar1 = param_3[2] * param_2[2] + uVar4;
  iVar5 = param_3[3];
  if (CARRY4(param_3[2] * param_2[2],uVar4)) {
    uVar3 = uVar3 + 1;
  }
  param_1[4] = iVar5 * iVar2 + uVar1;
  if (CARRY4(iVar5 * iVar2,uVar1)) {
    uVar3 = uVar3 + 1;
  }
  iVar2 = param_3[2];
  iVar5 = param_2[3];
  uVar4 = uVar3 + param_3[3] * param_2[2];
  uVar1 = (uint)CARRY4(uVar3,param_3[3] * param_2[2]);
  param_1[5] = iVar2 * iVar5 + uVar4;
  if (CARRY4(iVar2 * iVar5,uVar4)) {
    uVar1 = uVar1 + 1;
  }
  iVar5 = param_3[3];
  iVar2 = param_2[3];
  param_1[6] = iVar5 * iVar2 + uVar1;
  param_1[7] = (uint)CARRY4(iVar5 * iVar2,uVar1);
  return;
}

