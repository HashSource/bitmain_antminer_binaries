
void bn_mul_comba8(int *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
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
      goto LAB_00187b42;
    }
  }
  uVar4 = 0;
LAB_00187b42:
  uVar3 = param_3[1] * param_2[1] + uVar1;
  if (CARRY4(param_3[1] * param_2[1],uVar1)) {
    uVar4 = uVar4 + 1;
  }
  if (CARRY4(param_3[2] * *param_2,uVar3)) {
    uVar4 = uVar4 + 1;
  }
  param_1[2] = param_3[2] * *param_2 + uVar3;
  uVar3 = param_3[3] * *param_2 + uVar4;
  uVar1 = (uint)CARRY4(param_3[3] * *param_2,uVar4);
  uVar4 = param_3[2] * param_2[1] + uVar3;
  if (CARRY4(param_3[2] * param_2[1],uVar3)) {
    uVar1 = uVar1 + 1;
  }
  iVar5 = param_2[3];
  uVar3 = param_3[1] * param_2[2] + uVar4;
  iVar2 = *param_3;
  if (CARRY4(param_3[1] * param_2[2],uVar4)) {
    uVar1 = uVar1 + 1;
  }
  param_1[3] = uVar3 + iVar2 * iVar5;
  if (CARRY4(uVar3,iVar2 * iVar5)) {
    uVar1 = uVar1 + 1;
  }
  uVar4 = uVar1 + *param_3 * param_2[4];
  uVar1 = (uint)CARRY4(uVar1,*param_3 * param_2[4]);
  uVar3 = uVar4 + param_3[1] * param_2[3];
  if (CARRY4(uVar4,param_3[1] * param_2[3])) {
    uVar1 = uVar1 + 1;
  }
  uVar4 = uVar3 + param_3[2] * param_2[2];
  if (CARRY4(uVar3,param_3[2] * param_2[2])) {
    uVar1 = uVar1 + 1;
  }
  uVar3 = uVar4 + param_3[3] * param_2[1];
  if (CARRY4(uVar4,param_3[3] * param_2[1])) {
    uVar1 = uVar1 + 1;
  }
  iVar5 = *param_2;
  iVar2 = param_3[4];
  param_1[4] = uVar3 + iVar2 * iVar5;
  if (CARRY4(uVar3,iVar2 * iVar5)) {
    uVar1 = uVar1 + 1;
  }
  uVar4 = uVar1 + param_3[5] * *param_2;
  uVar3 = (uint)CARRY4(uVar1,param_3[5] * *param_2);
  uVar1 = uVar4 + param_3[4] * param_2[1];
  if (CARRY4(uVar4,param_3[4] * param_2[1])) {
    uVar3 = uVar3 + 1;
  }
  uVar4 = uVar1 + param_3[3] * param_2[2];
  if (CARRY4(uVar1,param_3[3] * param_2[2])) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = uVar4 + param_3[2] * param_2[3];
  if (CARRY4(uVar4,param_3[2] * param_2[3])) {
    uVar3 = uVar3 + 1;
  }
  uVar4 = uVar1 + param_3[1] * param_2[4];
  if (CARRY4(uVar1,param_3[1] * param_2[4])) {
    uVar3 = uVar3 + 1;
  }
  iVar5 = param_2[5];
  iVar2 = *param_3;
  param_1[5] = uVar4 + iVar2 * iVar5;
  if (CARRY4(uVar4,iVar2 * iVar5)) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = *param_3 * param_2[6] + uVar3;
  uVar3 = (uint)CARRY4(*param_3 * param_2[6],uVar3);
  uVar4 = uVar1 + param_3[1] * param_2[5];
  if (CARRY4(uVar1,param_3[1] * param_2[5])) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = uVar4 + param_3[2] * param_2[4];
  if (CARRY4(uVar4,param_3[2] * param_2[4])) {
    uVar3 = uVar3 + 1;
  }
  uVar4 = param_3[3] * param_2[3] + uVar1;
  if (CARRY4(param_3[3] * param_2[3],uVar1)) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = uVar4 + param_3[4] * param_2[2];
  if (CARRY4(uVar4,param_3[4] * param_2[2])) {
    uVar3 = uVar3 + 1;
  }
  uVar4 = uVar1 + param_3[5] * param_2[1];
  if (CARRY4(uVar1,param_3[5] * param_2[1])) {
    uVar3 = uVar3 + 1;
  }
  iVar5 = *param_2;
  iVar2 = param_3[6];
  param_1[6] = uVar4 + iVar2 * iVar5;
  if (CARRY4(uVar4,iVar2 * iVar5)) {
    uVar3 = uVar3 + 1;
  }
  uVar6 = uVar3 + param_3[7] * *param_2;
  uVar4 = (uint)CARRY4(uVar3,param_3[7] * *param_2);
  uVar1 = uVar6 + param_3[6] * param_2[1];
  if (CARRY4(uVar6,param_3[6] * param_2[1])) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = uVar1 + param_3[5] * param_2[2];
  if (CARRY4(uVar1,param_3[5] * param_2[2])) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = param_3[4] * param_2[3] + uVar3;
  if (CARRY4(param_3[4] * param_2[3],uVar3)) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = uVar1 + param_3[3] * param_2[4];
  if (CARRY4(uVar1,param_3[3] * param_2[4])) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = uVar3 + param_3[2] * param_2[5];
  if (CARRY4(uVar3,param_3[2] * param_2[5])) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = param_3[1] * param_2[6] + uVar1;
  if (CARRY4(param_3[1] * param_2[6],uVar1)) {
    uVar4 = uVar4 + 1;
  }
  iVar5 = param_2[7];
  iVar2 = *param_3;
  param_1[7] = iVar2 * iVar5 + uVar3;
  if (CARRY4(iVar2 * iVar5,uVar3)) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = uVar4 + param_3[1] * param_2[7];
  uVar4 = (uint)CARRY4(uVar4,param_3[1] * param_2[7]);
  uVar1 = param_3[2] * param_2[6] + uVar3;
  if (CARRY4(param_3[2] * param_2[6],uVar3)) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = uVar1 + param_3[3] * param_2[5];
  if (CARRY4(uVar1,param_3[3] * param_2[5])) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = uVar3 + param_3[4] * param_2[4];
  if (CARRY4(uVar3,param_3[4] * param_2[4])) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = param_3[5] * param_2[3] + uVar1;
  if (CARRY4(param_3[5] * param_2[3],uVar1)) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = uVar3 + param_3[6] * param_2[2];
  if (CARRY4(uVar3,param_3[6] * param_2[2])) {
    uVar4 = uVar4 + 1;
  }
  iVar5 = param_2[1];
  iVar2 = param_3[7];
  param_1[8] = iVar2 * iVar5 + uVar1;
  if (CARRY4(iVar2 * iVar5,uVar1)) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = uVar4 + param_3[7] * param_2[2];
  uVar3 = (uint)CARRY4(uVar4,param_3[7] * param_2[2]);
  uVar4 = param_3[6] * param_2[3] + uVar1;
  if (CARRY4(param_3[6] * param_2[3],uVar1)) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = uVar4 + param_3[5] * param_2[4];
  if (CARRY4(uVar4,param_3[5] * param_2[4])) {
    uVar3 = uVar3 + 1;
  }
  uVar4 = uVar1 + param_3[4] * param_2[5];
  if (CARRY4(uVar1,param_3[4] * param_2[5])) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = param_3[3] * param_2[6] + uVar4;
  if (CARRY4(param_3[3] * param_2[6],uVar4)) {
    uVar3 = uVar3 + 1;
  }
  iVar5 = param_2[7];
  iVar2 = param_3[2];
  param_1[9] = uVar1 + iVar2 * iVar5;
  if (CARRY4(uVar1,iVar2 * iVar5)) {
    uVar3 = uVar3 + 1;
  }
  uVar6 = param_3[3] * param_2[7] + uVar3;
  uVar4 = (uint)CARRY4(param_3[3] * param_2[7],uVar3);
  uVar1 = param_3[4] * param_2[6] + uVar6;
  if (CARRY4(param_3[4] * param_2[6],uVar6)) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = uVar1 + param_3[5] * param_2[5];
  if (CARRY4(uVar1,param_3[5] * param_2[5])) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = uVar3 + param_3[6] * param_2[4];
  if (CARRY4(uVar3,param_3[6] * param_2[4])) {
    uVar4 = uVar4 + 1;
  }
  iVar5 = param_2[3];
  iVar2 = param_3[7];
  param_1[10] = uVar1 + iVar2 * iVar5;
  if (CARRY4(uVar1,iVar2 * iVar5)) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = uVar4 + param_3[7] * param_2[4];
  uVar3 = (uint)CARRY4(uVar4,param_3[7] * param_2[4]);
  uVar4 = param_3[6] * param_2[5] + uVar1;
  if (CARRY4(param_3[6] * param_2[5],uVar1)) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = param_3[5] * param_2[6] + uVar4;
  if (CARRY4(param_3[5] * param_2[6],uVar4)) {
    uVar3 = uVar3 + 1;
  }
  iVar5 = param_2[7];
  iVar2 = param_3[4];
  param_1[0xb] = uVar1 + iVar2 * iVar5;
  if (CARRY4(uVar1,iVar2 * iVar5)) {
    uVar3 = uVar3 + 1;
  }
  uVar6 = uVar3 + param_3[5] * param_2[7];
  iVar2 = param_3[7];
  uVar4 = (uint)CARRY4(uVar3,param_3[5] * param_2[7]);
  uVar1 = param_3[6] * param_2[6] + uVar6;
  iVar5 = param_2[5];
  if (CARRY4(param_3[6] * param_2[6],uVar6)) {
    uVar4 = uVar4 + 1;
  }
  param_1[0xc] = uVar1 + iVar2 * iVar5;
  if (CARRY4(uVar1,iVar2 * iVar5)) {
    uVar4 = uVar4 + 1;
  }
  iVar2 = param_3[6];
  iVar5 = param_2[7];
  uVar1 = uVar4 + param_3[7] * param_2[6];
  uVar4 = (uint)CARRY4(uVar4,param_3[7] * param_2[6]);
  param_1[0xd] = iVar2 * iVar5 + uVar1;
  if (CARRY4(iVar2 * iVar5,uVar1)) {
    uVar4 = uVar4 + 1;
  }
  iVar5 = param_3[7];
  iVar2 = param_2[7];
  param_1[0xe] = iVar5 * iVar2 + uVar4;
  param_1[0xf] = (uint)CARRY4(iVar5 * iVar2,uVar4);
  return;
}

