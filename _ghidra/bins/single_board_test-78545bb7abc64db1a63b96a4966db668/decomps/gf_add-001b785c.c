
void gf_add(uint *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  
  uVar12 = *param_3 + *param_2;
  *param_1 = uVar12;
  uVar5 = param_3[1] + param_2[1];
  param_1[1] = uVar5;
  uVar13 = param_2[2] + param_3[2];
  param_1[2] = uVar13;
  uVar6 = param_2[3] + param_3[3];
  param_1[3] = uVar6;
  uVar14 = param_2[4] + param_3[4];
  param_1[4] = uVar14;
  uVar7 = param_2[5] + param_3[5];
  param_1[5] = uVar7;
  uVar15 = param_2[6] + param_3[6];
  param_1[6] = uVar15;
  uVar4 = param_3[7] + param_2[7];
  param_1[7] = uVar4;
  iVar8 = param_2[8];
  iVar3 = param_3[8];
  param_1[8] = iVar3 + iVar8;
  uVar16 = param_3[9] + param_2[9];
  param_1[9] = uVar16;
  uVar9 = param_3[10] + param_2[10];
  param_1[10] = uVar9;
  uVar18 = param_2[0xb] + param_3[0xb];
  param_1[0xb] = uVar18;
  uVar10 = param_2[0xc] + param_3[0xc];
  param_1[0xc] = uVar10;
  uVar19 = param_2[0xd] + param_3[0xd];
  param_1[0xd] = uVar19;
  uVar11 = param_2[0xe] + param_3[0xe];
  param_1[0xe] = uVar11;
  iVar2 = param_3[0xf];
  iVar1 = param_2[0xf];
  param_1[10] = (uVar9 & 0xfffffff) + (uVar16 >> 0x1c);
  param_1[0xd] = (uVar19 & 0xfffffff) + (uVar10 >> 0x1c);
  uVar17 = (uint)(iVar1 + iVar2) >> 0x1c;
  param_1[0xe] = (uVar11 & 0xfffffff) + (uVar19 >> 0x1c);
  uVar19 = iVar3 + iVar8 + uVar17;
  param_1[0xc] = (uVar10 & 0xfffffff) + (uVar18 >> 0x1c);
  param_1[0xb] = (uVar18 & 0xfffffff) + (uVar9 >> 0x1c);
  param_1[0xf] = (iVar1 + iVar2 & 0xfffffffU) + (uVar11 >> 0x1c);
  param_1[9] = (uVar16 & 0xfffffff) + (uVar19 >> 0x1c);
  param_1[8] = (uVar19 & 0xfffffff) + (uVar4 >> 0x1c);
  param_1[7] = (uVar4 & 0xfffffff) + (uVar15 >> 0x1c);
  param_1[6] = (uVar15 & 0xfffffff) + (uVar7 >> 0x1c);
  param_1[5] = (uVar7 & 0xfffffff) + (uVar14 >> 0x1c);
  param_1[4] = (uVar14 & 0xfffffff) + (uVar6 >> 0x1c);
  param_1[3] = (uVar6 & 0xfffffff) + (uVar13 >> 0x1c);
  param_1[2] = (uVar13 & 0xfffffff) + (uVar5 >> 0x1c);
  param_1[1] = (uVar5 & 0xfffffff) + (uVar12 >> 0x1c);
  *param_1 = uVar17 + (uVar12 & 0xfffffff);
  return;
}

