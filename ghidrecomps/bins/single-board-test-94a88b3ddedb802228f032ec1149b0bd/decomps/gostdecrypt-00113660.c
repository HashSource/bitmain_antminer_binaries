
void gostdecrypt(int *param_1,byte *param_2,undefined *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar10 = (uint)param_2[2] << 0x10 | (uint)param_2[1] << 8 | (uint)*param_2 |
           (uint)param_2[3] << 0x18;
  uVar2 = uVar10 + *param_1;
  iVar1 = param_1[4];
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  iVar3 = param_1[5];
  uVar8 = ((uint)param_2[4] | (uint)param_2[6] << 0x10 | (uint)param_2[5] << 8 |
          (uint)param_2[7] << 0x18) ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  iVar4 = param_1[6];
  iVar5 = param_1[7];
  uVar2 = uVar8 + param_1[1];
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + param_1[2];
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar8 + param_1[3];
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar1;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar8 + iVar3;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar4;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar8 + iVar5;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar5;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar8 + iVar4;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar3;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar8 + iVar1;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + param_1[3];
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar8 + param_1[2];
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + param_1[1];
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar8 + *param_1;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar5;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar8 + iVar4;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar3;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar8 + iVar1;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + param_1[3];
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar8 + param_1[2];
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + param_1[1];
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar8 + *param_1;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = iVar5 + uVar10;
  uVar2 = param_1[(uVar2 * 0x10000 >> 0x18) + 0x208] |
          param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = iVar4 + uVar8;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = iVar3 + uVar10;
  uVar2 = param_1[(uVar2 * 0x100 >> 0x18) + 0x108] |
          param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = iVar1 + uVar8;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + param_1[3];
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar8 + param_1[2];
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + param_1[1];
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar8 = uVar8 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar8 + *param_1;
  uVar9 = param_1[(uVar2 & 0xff) + 0x308];
  uVar7 = param_1[(uVar2 >> 0x18) + 8];
  uVar6 = param_1[(uVar2 * 0x100 >> 0x18) + 0x108];
  uVar2 = param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  *param_3 = (char)uVar8;
  param_3[3] = (char)(uVar8 >> 0x18);
  uVar2 = uVar9 | uVar7 | uVar6 | uVar2;
  param_3[1] = (char)(uVar8 >> 8);
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  param_3[2] = (char)(uVar8 >> 0x10);
  param_3[4] = (char)uVar10;
  param_3[5] = (char)(uVar10 >> 8);
  param_3[6] = (char)(uVar10 >> 0x10);
  param_3[7] = (char)(uVar10 >> 0x18);
  return;
}

