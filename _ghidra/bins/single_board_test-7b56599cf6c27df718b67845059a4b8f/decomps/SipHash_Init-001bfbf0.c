
undefined4 SipHash_Init(undefined4 *param_1,uint *param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = *param_2;
  uVar4 = param_2[2];
  iVar1 = param_1[0xb];
  uVar3 = param_2[1];
  uVar5 = param_2[3];
  if (iVar1 == 0) {
    iVar1 = 0x10;
  }
  if (param_3 == 0) {
    param_3 = 2;
  }
  if (param_4 == 0) {
    param_4 = 4;
  }
  param_1[0xc] = param_3;
  param_1[0xd] = param_4;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = uVar2 ^ 0x70736575;
  param_1[3] = uVar3 ^ 0x736f6d65;
  param_1[0xb] = iVar1;
  param_1[10] = 0;
  param_1[6] = uVar2 ^ 0x6e657261;
  param_1[7] = uVar3 ^ 0x6c796765;
  param_1[4] = uVar4 ^ 0x6e646f6d;
  param_1[5] = uVar5 ^ 0x646f7261;
  param_1[8] = uVar4 ^ 0x79746573;
  param_1[9] = uVar5 ^ 0x74656462;
  if (iVar1 == 0x10) {
    param_1[4] = uVar4 ^ 0x6e646f83;
    param_1[5] = uVar5 ^ 0x646f7261;
  }
  return 1;
}

