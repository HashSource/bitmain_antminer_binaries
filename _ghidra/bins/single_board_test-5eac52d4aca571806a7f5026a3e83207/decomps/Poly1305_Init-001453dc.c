
void Poly1305_Init(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  
  param_1[0x30] = param_2[4];
  param_1[0x31] = param_2[5];
  param_1[0x32] = param_2[6];
  uVar1 = param_2[7];
  *param_1 = 0;
  param_1[1] = 0;
  param_1[0x33] = uVar1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = *param_2 & 0xfffffff;
  param_1[6] = param_2[1] & 0xffffffc;
  param_1[7] = param_2[2] & 0xffffffc;
  uVar1 = param_2[3];
  param_1[0x38] = 0;
  param_1[8] = uVar1 & 0xffffffc;
  return;
}

