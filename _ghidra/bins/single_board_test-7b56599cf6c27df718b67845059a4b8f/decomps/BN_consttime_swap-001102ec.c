
void BN_consttime_swap(undefined4 param_1,int *param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if (param_2 != param_3) {
    uVar1 = param_3[1];
    uVar8 = param_2[1];
    uVar7 = param_3[3];
    param_2[1] = uVar1;
    uVar10 = param_2[4];
    uVar2 = param_3[4];
    uVar9 = param_2[3];
    param_3[1] = uVar8 ^ uVar1 ^ param_3[1];
    param_2[3] = uVar7;
    uVar1 = (uVar2 ^ uVar10) & 4;
    param_3[3] = uVar7 ^ uVar9 ^ param_3[3];
    param_2[4] = uVar10 ^ uVar1;
    param_3[4] = uVar1 ^ param_3[4];
    if (0 < param_4) {
      puVar4 = (uint *)*param_2;
      puVar3 = (uint *)*param_3;
      puVar5 = puVar4;
      do {
        uVar1 = *puVar3;
        uVar2 = *puVar5;
        puVar6 = puVar5 + 1;
        *puVar5 = uVar1;
        *puVar3 = uVar1 ^ uVar2 ^ *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar6;
      } while (puVar6 != puVar4 + param_4);
    }
  }
  return;
}

