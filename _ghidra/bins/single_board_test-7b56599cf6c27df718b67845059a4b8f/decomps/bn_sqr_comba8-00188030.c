
void bn_sqr_comba8(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  *param_1 = *param_2 * *param_2;
  uVar2 = *param_2 * param_2[1];
  param_1[1] = uVar2 * 2;
  uVar3 = param_2[1] * param_2[1];
  if ((uVar2 < uVar2 * 2 || uVar2 == 0) || (bVar6 = uVar3 != 0xffffffff, uVar3 = uVar3 + 1, bVar6))
  {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  uVar1 = *param_2 * param_2[2];
  if (CARRY4(uVar1,uVar3)) {
    uVar2 = uVar2 + 1;
  }
  if (CARRY4(uVar1,uVar1 + uVar3)) {
    uVar2 = uVar2 + 1;
  }
  param_1[2] = uVar1 + uVar1 + uVar3;
  uVar3 = *param_2 * param_2[3];
  uVar4 = (uint)CARRY4(uVar3,uVar2);
  uVar1 = uVar3 + uVar3 + uVar2;
  if (CARRY4(uVar3,uVar3 + uVar2)) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = param_2[1] * param_2[2];
  uVar3 = uVar1 + uVar2;
  if (CARRY4(uVar1,uVar2)) {
    uVar4 = uVar4 + 1;
  }
  param_1[3] = uVar3 + uVar2;
  if (CARRY4(uVar3,uVar2)) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = param_2[2] * param_2[2];
  uVar1 = param_2[1] * param_2[3];
  uVar3 = uVar2 + uVar4;
  uVar4 = (uint)CARRY4(uVar2,uVar4);
  uVar2 = uVar3 + uVar1;
  if (CARRY4(uVar3,uVar1)) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = uVar2 + uVar1;
  if (CARRY4(uVar2,uVar1)) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = *param_2 * param_2[4];
  uVar2 = uVar3 + uVar1;
  if (CARRY4(uVar3,uVar1)) {
    uVar4 = uVar4 + 1;
  }
  param_1[4] = uVar1 + uVar2;
  if (CARRY4(uVar1,uVar2)) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = *param_2 * param_2[5];
  uVar2 = (uint)CARRY4(uVar4,uVar3);
  uVar1 = uVar3 + uVar4 + uVar3;
  if (CARRY4(uVar3,uVar4 + uVar3)) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = param_2[1] * param_2[4];
  uVar3 = uVar1 + uVar4;
  if (CARRY4(uVar1,uVar4)) {
    uVar2 = uVar2 + 1;
  }
  uVar1 = uVar3 + uVar4;
  if (CARRY4(uVar3,uVar4)) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = param_2[2] * param_2[3];
  uVar3 = uVar1 + uVar4;
  if (CARRY4(uVar1,uVar4)) {
    uVar2 = uVar2 + 1;
  }
  param_1[5] = uVar4 + uVar3;
  if (CARRY4(uVar4,uVar3)) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = param_2[3] * param_2[3];
  uVar1 = param_2[2] * param_2[4];
  uVar3 = uVar2 + uVar4;
  uVar4 = (uint)CARRY4(uVar2,uVar4);
  uVar2 = uVar3 + uVar1;
  if (CARRY4(uVar3,uVar1)) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = uVar2 + uVar1;
  if (CARRY4(uVar2,uVar1)) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = param_2[1] * param_2[5];
  uVar2 = uVar3 + uVar1;
  if (CARRY4(uVar3,uVar1)) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = uVar1 + uVar2;
  if (CARRY4(uVar1,uVar2)) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = *param_2 * param_2[6];
  uVar2 = uVar1 + uVar3;
  if (CARRY4(uVar1,uVar3)) {
    uVar4 = uVar4 + 1;
  }
  param_1[6] = uVar1 + uVar2;
  if (CARRY4(uVar1,uVar2)) {
    uVar4 = uVar4 + 1;
  }
  uVar3 = *param_2 * param_2[7];
  uVar2 = (uint)CARRY4(uVar3,uVar4);
  uVar1 = uVar3 + uVar3 + uVar4;
  if (CARRY4(uVar3,uVar3 + uVar4)) {
    uVar2 = uVar2 + 1;
  }
  uVar3 = param_2[1] * param_2[6];
  uVar4 = uVar3 + uVar1;
  if (CARRY4(uVar3,uVar1)) {
    uVar2 = uVar2 + 1;
  }
  uVar1 = uVar4 + uVar3;
  if (CARRY4(uVar4,uVar3)) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = param_2[2] * param_2[5];
  uVar3 = uVar4 + uVar1;
  if (CARRY4(uVar4,uVar1)) {
    uVar2 = uVar2 + 1;
  }
  uVar1 = uVar4 + uVar3;
  if (CARRY4(uVar4,uVar3)) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = param_2[3] * param_2[4];
  uVar3 = uVar4 + uVar1;
  if (CARRY4(uVar4,uVar1)) {
    uVar2 = uVar2 + 1;
  }
  param_1[7] = uVar3 + uVar4;
  if (CARRY4(uVar3,uVar4)) {
    uVar2 = uVar2 + 1;
  }
  uVar3 = param_2[4] * param_2[4];
  uVar4 = param_2[3] * param_2[5];
  uVar1 = uVar3 + uVar2;
  uVar2 = (uint)CARRY4(uVar3,uVar2);
  uVar3 = uVar4 + uVar1;
  if (CARRY4(uVar4,uVar1)) {
    uVar2 = uVar2 + 1;
  }
  uVar1 = uVar3 + uVar4;
  if (CARRY4(uVar3,uVar4)) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = param_2[2] * param_2[6];
  uVar3 = uVar1 + uVar4;
  if (CARRY4(uVar1,uVar4)) {
    uVar2 = uVar2 + 1;
  }
  uVar1 = uVar3 + uVar4;
  if (CARRY4(uVar3,uVar4)) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = param_2[1] * param_2[7];
  uVar3 = uVar4 + uVar1;
  if (CARRY4(uVar4,uVar1)) {
    uVar2 = uVar2 + 1;
  }
  param_1[8] = uVar4 + uVar3;
  if (CARRY4(uVar4,uVar3)) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = param_2[2] * param_2[7];
  uVar1 = (uint)CARRY4(uVar4,uVar2);
  uVar3 = uVar4 + uVar2 + uVar4;
  if (CARRY4(uVar4 + uVar2,uVar4)) {
    uVar1 = uVar1 + 1;
  }
  uVar2 = param_2[3] * param_2[6];
  uVar4 = uVar3 + uVar2;
  if (CARRY4(uVar3,uVar2)) {
    uVar1 = uVar1 + 1;
  }
  uVar3 = uVar4 + uVar2;
  if (CARRY4(uVar4,uVar2)) {
    uVar1 = uVar1 + 1;
  }
  uVar4 = param_2[4] * param_2[5];
  uVar2 = uVar4 + uVar3;
  if (CARRY4(uVar4,uVar3)) {
    uVar1 = uVar1 + 1;
  }
  param_1[9] = uVar4 + uVar2;
  if (CARRY4(uVar4,uVar2)) {
    uVar1 = uVar1 + 1;
  }
  uVar2 = param_2[5] * param_2[5];
  uVar3 = param_2[4] * param_2[6];
  uVar4 = uVar2 + uVar1;
  uVar2 = (uint)CARRY4(uVar2,uVar1);
  uVar1 = uVar3 + uVar4;
  if (CARRY4(uVar3,uVar4)) {
    uVar2 = uVar2 + 1;
  }
  uVar4 = uVar3 + uVar1;
  if (CARRY4(uVar3,uVar1)) {
    uVar2 = uVar2 + 1;
  }
  uVar1 = param_2[3] * param_2[7];
  uVar3 = uVar1 + uVar4;
  if (CARRY4(uVar1,uVar4)) {
    uVar2 = uVar2 + 1;
  }
  param_1[10] = uVar3 + uVar1;
  if (CARRY4(uVar3,uVar1)) {
    uVar2 = uVar2 + 1;
  }
  uVar1 = param_2[4] * param_2[7];
  uVar4 = (uint)CARRY4(uVar1,uVar2);
  uVar3 = uVar1 + uVar2 + uVar1;
  if (CARRY4(uVar1 + uVar2,uVar1)) {
    uVar4 = uVar4 + 1;
  }
  uVar1 = param_2[5] * param_2[6];
  uVar2 = uVar1 + uVar3;
  if (CARRY4(uVar1,uVar3)) {
    uVar4 = uVar4 + 1;
  }
  param_1[0xb] = uVar1 + uVar2;
  if (CARRY4(uVar1,uVar2)) {
    uVar4 = uVar4 + 1;
  }
  uVar2 = param_2[6] * param_2[6];
  uVar5 = param_2[5] * param_2[7];
  uVar3 = uVar2 + uVar4;
  uVar2 = (uint)CARRY4(uVar2,uVar4);
  uVar1 = uVar3 + uVar5;
  if (CARRY4(uVar3,uVar5)) {
    uVar2 = uVar2 + 1;
  }
  param_1[0xc] = uVar5 + uVar1;
  if (CARRY4(uVar5,uVar1)) {
    uVar2 = uVar2 + 1;
  }
  uVar3 = param_2[6] * param_2[7];
  uVar1 = (uint)CARRY4(uVar3,uVar2);
  param_1[0xd] = uVar3 + uVar2 + uVar3;
  if (CARRY4(uVar3 + uVar2,uVar3)) {
    uVar1 = uVar1 + 1;
  }
  uVar2 = param_2[7] * param_2[7];
  param_1[0xe] = uVar2 + uVar1;
  param_1[0xf] = (uint)CARRY4(uVar2,uVar1);
  return;
}

