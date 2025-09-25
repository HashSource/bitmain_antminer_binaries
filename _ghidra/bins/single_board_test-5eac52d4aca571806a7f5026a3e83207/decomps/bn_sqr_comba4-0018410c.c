
void bn_sqr_comba4(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  *param_1 = *param_2 * *param_2;
  uVar2 = *param_2 * param_2[1];
  param_1[1] = uVar2 * 2;
  uVar4 = param_2[1] * param_2[1];
  if ((uVar2 < uVar2 * 2 || uVar2 == 0) || (bVar5 = uVar4 != 0xffffffff, uVar4 = uVar4 + 1, bVar5))
  {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  uVar1 = *param_2 * param_2[2];
  if (CARRY4(uVar1,uVar4)) {
    uVar2 = uVar2 + 1;
  }
  if (CARRY4(uVar1,uVar1 + uVar4)) {
    uVar2 = uVar2 + 1;
  }
  param_1[2] = uVar1 + uVar1 + uVar4;
  uVar1 = *param_2 * param_2[3];
  uVar4 = (uint)CARRY4(uVar1,uVar2);
  uVar3 = uVar1 + uVar1 + uVar2;
  if (CARRY4(uVar1,uVar1 + uVar2)) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = param_2[1] * param_2[2];
  uVar2 = uVar3 + uVar1;
  if (CARRY4(uVar3,uVar1)) {
    uVar4 = uVar4 + 1;
  }
  param_1[3] = uVar2 + uVar1;
  if (CARRY4(uVar2,uVar1)) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = param_2[2] * param_2[2];
  uVar3 = param_2[1] * param_2[3];
  uVar1 = uVar2 + uVar4;
  uVar4 = (uint)CARRY4(uVar2,uVar4);
  uVar2 = uVar1 + uVar3;
  if (CARRY4(uVar1,uVar3)) {
    uVar4 = uVar4 + 1;
  }
  param_1[4] = uVar2 + uVar3;
  if (CARRY4(uVar2,uVar3)) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = param_2[2] * param_2[3];
  uVar1 = (uint)CARRY4(uVar2,uVar4);
  param_1[5] = uVar2 + uVar2 + uVar4;
  if (CARRY4(uVar2,uVar2 + uVar4)) {
    uVar1 = uVar1 + 1;
  }
  uVar2 = param_2[3] * param_2[3];
  param_1[6] = uVar2 + uVar1;
  param_1[7] = (uint)CARRY4(uVar2,uVar1);
  return;
}

