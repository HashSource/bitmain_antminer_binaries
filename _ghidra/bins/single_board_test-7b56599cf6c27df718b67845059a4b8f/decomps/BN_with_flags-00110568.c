
void BN_with_flags(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = param_2[4];
  uVar4 = param_2[1];
  uVar3 = param_2[2];
  uVar1 = param_2[3];
  *param_1 = *param_2;
  param_1[1] = uVar4;
  param_1[2] = uVar3;
  param_1[3] = uVar1;
  param_1[4] = param_3 | uVar2 & 0xfffffffe | param_1[4] & 1 | 2;
  return;
}

