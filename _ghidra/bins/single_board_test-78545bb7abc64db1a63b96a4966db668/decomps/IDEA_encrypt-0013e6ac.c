
void IDEA_encrypt(uint *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  uVar6 = *param_1 >> 0x10;
  uVar2 = *param_2 * uVar6;
  uVar6 = (1 - *param_2) - uVar6;
  if (uVar2 != 0) {
    uVar6 = (uVar2 & 0xffff) - (uVar2 >> 0x10);
    uVar6 = uVar6 - (uVar6 >> 0x10);
  }
  uVar2 = param_1[1] & 0xffff;
  uVar8 = param_2[3] * uVar2;
  uVar10 = *param_1 + param_2[1];
  uVar2 = (1 - param_2[3]) - uVar2;
  uVar9 = (param_1[1] >> 0x10) + param_2[2];
  if (uVar8 != 0) {
    uVar2 = (uVar8 & 0xffff) - (uVar8 >> 0x10);
    uVar2 = uVar2 - (uVar2 >> 0x10);
  }
  uVar4 = (uVar6 ^ uVar9) & 0xffff;
  uVar8 = param_2[4] * uVar4;
  if (uVar8 == 0) {
    iVar3 = (1 - param_2[4]) - uVar4;
  }
  else {
    uVar8 = (uVar8 & 0xffff) - (uVar8 >> 0x10);
    iVar3 = uVar8 - (uVar8 >> 0x10);
  }
  uVar8 = (uVar2 ^ uVar10) + iVar3 & 0xffff;
  uVar4 = param_2[5] * uVar8;
  uVar8 = (1 - param_2[5]) - uVar8;
  if (uVar4 != 0) {
    uVar8 = (uVar4 & 0xffff) - (uVar4 >> 0x10);
    uVar8 = uVar8 - (uVar8 >> 0x10);
  }
  uVar4 = (uVar6 ^ uVar8) & 0xffff;
  uVar6 = param_2[6] * uVar4;
  uVar4 = (1 - param_2[6]) - uVar4;
  if (uVar6 != 0) {
    uVar4 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar4 = uVar4 - (uVar4 >> 0x10);
  }
  uVar2 = (uVar2 ^ iVar3 + uVar8) & 0xffff;
  uVar6 = param_2[9] * uVar2;
  uVar9 = (uVar8 ^ uVar9) + param_2[7];
  uVar2 = (1 - param_2[9]) - uVar2;
  uVar8 = (uVar10 ^ iVar3 + uVar8) + param_2[8];
  if (uVar6 != 0) {
    uVar2 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    uVar2 = uVar2 - (uVar2 >> 0x10);
  }
  uVar10 = (uVar4 ^ uVar8) & 0xffff;
  uVar6 = param_2[10] * uVar10;
  if (uVar6 == 0) {
    iVar3 = (1 - param_2[10]) - uVar10;
  }
  else {
    uVar6 = (uVar6 & 0xffff) - (uVar6 >> 0x10);
    iVar3 = uVar6 - (uVar6 >> 0x10);
  }
  uVar6 = (uVar2 ^ uVar9) + iVar3 & 0xffff;
  uVar10 = param_2[0xb] * uVar6;
  uVar6 = (1 - param_2[0xb]) - uVar6;
  if (uVar10 != 0) {
    uVar6 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar6 = uVar6 - (uVar6 >> 0x10);
  }
  uVar4 = (uVar4 ^ uVar6) & 0xffff;
  uVar10 = param_2[0xc] * uVar4;
  uVar4 = (1 - param_2[0xc]) - uVar4;
  if (uVar10 != 0) {
    uVar4 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar4 = uVar4 - (uVar4 >> 0x10);
  }
  uVar2 = (uVar2 ^ iVar3 + uVar6) & 0xffff;
  uVar10 = param_2[0xf] * uVar2;
  uVar8 = (uVar6 ^ uVar8) + param_2[0xd];
  uVar2 = (1 - param_2[0xf]) - uVar2;
  uVar6 = (uVar9 ^ iVar3 + uVar6) + param_2[0xe];
  if (uVar10 != 0) {
    uVar2 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar2 = uVar2 - (uVar2 >> 0x10);
  }
  uVar10 = (uVar4 ^ uVar6) & 0xffff;
  uVar9 = param_2[0x10] * uVar10;
  if (uVar9 == 0) {
    iVar3 = (1 - param_2[0x10]) - uVar10;
  }
  else {
    uVar9 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    iVar3 = uVar9 - (uVar9 >> 0x10);
  }
  uVar9 = (uVar2 ^ uVar8) + iVar3 & 0xffff;
  uVar10 = param_2[0x11] * uVar9;
  uVar9 = (1 - param_2[0x11]) - uVar9;
  if (uVar10 != 0) {
    uVar9 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar4 = (uVar4 ^ uVar9) & 0xffff;
  uVar10 = param_2[0x12] * uVar4;
  uVar4 = (1 - param_2[0x12]) - uVar4;
  if (uVar10 != 0) {
    uVar4 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar4 = uVar4 - (uVar4 >> 0x10);
  }
  uVar2 = (uVar2 ^ iVar3 + uVar9) & 0xffff;
  uVar10 = param_2[0x15] * uVar2;
  uVar6 = (uVar9 ^ uVar6) + param_2[0x13];
  uVar2 = (1 - param_2[0x15]) - uVar2;
  uVar8 = (uVar8 ^ iVar3 + uVar9) + param_2[0x14];
  if (uVar10 != 0) {
    uVar2 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar2 = uVar2 - (uVar2 >> 0x10);
  }
  uVar10 = (uVar4 ^ uVar8) & 0xffff;
  uVar9 = param_2[0x16] * uVar10;
  if (uVar9 == 0) {
    iVar3 = (1 - param_2[0x16]) - uVar10;
  }
  else {
    uVar9 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    iVar3 = uVar9 - (uVar9 >> 0x10);
  }
  uVar9 = (uVar2 ^ uVar6) + iVar3 & 0xffff;
  uVar10 = param_2[0x17] * uVar9;
  uVar9 = (1 - param_2[0x17]) - uVar9;
  if (uVar10 != 0) {
    uVar9 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar4 = (uVar4 ^ uVar9) & 0xffff;
  uVar10 = param_2[0x18] * uVar4;
  uVar4 = (1 - param_2[0x18]) - uVar4;
  if (uVar10 != 0) {
    uVar4 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar4 = uVar4 - (uVar4 >> 0x10);
  }
  uVar2 = (uVar2 ^ iVar3 + uVar9) & 0xffff;
  uVar10 = param_2[0x1b] * uVar2;
  uVar8 = (uVar9 ^ uVar8) + param_2[0x19];
  uVar2 = (1 - param_2[0x1b]) - uVar2;
  uVar6 = (uVar6 ^ iVar3 + uVar9) + param_2[0x1a];
  if (uVar10 != 0) {
    uVar2 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar2 = uVar2 - (uVar2 >> 0x10);
  }
  uVar10 = (uVar4 ^ uVar6) & 0xffff;
  uVar9 = param_2[0x1c] * uVar10;
  if (uVar9 == 0) {
    iVar3 = (1 - param_2[0x1c]) - uVar10;
  }
  else {
    uVar9 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    iVar3 = uVar9 - (uVar9 >> 0x10);
  }
  uVar9 = (uVar2 ^ uVar8) + iVar3 & 0xffff;
  uVar10 = param_2[0x1d] * uVar9;
  uVar9 = (1 - param_2[0x1d]) - uVar9;
  if (uVar10 != 0) {
    uVar9 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar4 = (uVar4 ^ uVar9) & 0xffff;
  uVar10 = param_2[0x1e] * uVar4;
  uVar4 = (1 - param_2[0x1e]) - uVar4;
  if (uVar10 != 0) {
    uVar4 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar4 = uVar4 - (uVar4 >> 0x10);
  }
  uVar2 = (uVar2 ^ iVar3 + uVar9) & 0xffff;
  uVar10 = param_2[0x21] * uVar2;
  uVar6 = (uVar9 ^ uVar6) + param_2[0x1f];
  uVar2 = (1 - param_2[0x21]) - uVar2;
  uVar8 = (uVar8 ^ iVar3 + uVar9) + param_2[0x20];
  if (uVar10 != 0) {
    uVar2 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar2 = uVar2 - (uVar2 >> 0x10);
  }
  uVar10 = (uVar4 ^ uVar8) & 0xffff;
  uVar9 = param_2[0x22] * uVar10;
  if (uVar9 == 0) {
    iVar3 = (1 - param_2[0x22]) - uVar10;
  }
  else {
    uVar9 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    iVar3 = uVar9 - (uVar9 >> 0x10);
  }
  uVar9 = (uVar2 ^ uVar6) + iVar3 & 0xffff;
  uVar10 = param_2[0x23] * uVar9;
  uVar9 = (1 - param_2[0x23]) - uVar9;
  if (uVar10 != 0) {
    uVar9 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar9 = uVar9 - (uVar9 >> 0x10);
  }
  uVar4 = (uVar4 ^ uVar9) & 0xffff;
  uVar10 = param_2[0x24] * uVar4;
  uVar4 = (1 - param_2[0x24]) - uVar4;
  if (uVar10 != 0) {
    uVar4 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar4 = uVar4 - (uVar4 >> 0x10);
  }
  uVar2 = (uVar2 ^ iVar3 + uVar9) & 0xffff;
  uVar10 = param_2[0x27] * uVar2;
  uVar8 = (uVar9 ^ uVar8) + param_2[0x25];
  uVar2 = (1 - param_2[0x27]) - uVar2;
  uVar6 = (uVar6 ^ iVar3 + uVar9) + param_2[0x26];
  if (uVar10 != 0) {
    uVar2 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar2 = uVar2 - (uVar2 >> 0x10);
  }
  uVar10 = (uVar4 ^ uVar6) & 0xffff;
  uVar9 = param_2[0x28] * uVar10;
  if (uVar9 == 0) {
    iVar3 = (1 - param_2[0x28]) - uVar10;
  }
  else {
    uVar9 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    iVar3 = uVar9 - (uVar9 >> 0x10);
  }
  uVar10 = (uVar2 ^ uVar8) + iVar3 & 0xffff;
  uVar9 = param_2[0x29] * uVar10;
  uVar10 = (1 - param_2[0x29]) - uVar10;
  if (uVar9 != 0) {
    uVar10 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    uVar10 = uVar10 - (uVar10 >> 0x10);
  }
  uVar4 = (uVar4 ^ uVar10) & 0xffff;
  uVar9 = param_2[0x2a] * uVar4;
  uVar4 = (1 - param_2[0x2a]) - uVar4;
  if (uVar9 != 0) {
    uVar4 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    uVar4 = uVar4 - (uVar4 >> 0x10);
  }
  uVar2 = (uVar2 ^ iVar3 + uVar10) & 0xffff;
  uVar9 = param_2[0x2d] * uVar2;
  uVar2 = (1 - param_2[0x2d]) - uVar2;
  uVar6 = (uVar10 ^ uVar6) + param_2[0x2b];
  uVar8 = (uVar8 ^ iVar3 + uVar10) + param_2[0x2c];
  if (uVar9 != 0) {
    uVar2 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    uVar2 = uVar2 - (uVar2 >> 0x10);
  }
  uVar10 = (uVar4 ^ uVar8) & 0xffff;
  uVar9 = param_2[0x2e] * uVar10;
  if (uVar9 == 0) {
    iVar3 = (1 - param_2[0x2e]) - uVar10;
  }
  else {
    uVar9 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    iVar3 = uVar9 - (uVar9 >> 0x10);
  }
  uVar10 = (uVar2 ^ uVar6) + iVar3 & 0xffff;
  uVar9 = param_2[0x2f] * uVar10;
  uVar10 = (1 - param_2[0x2f]) - uVar10;
  if (uVar9 != 0) {
    uVar10 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    uVar10 = uVar10 - (uVar10 >> 0x10);
  }
  uVar4 = (uVar4 ^ uVar10) & 0xffff;
  uVar2 = uVar2 ^ iVar3 + uVar10;
  uVar9 = param_2[0x30] * uVar4;
  if (uVar9 == 0) {
    iVar11 = (1 - param_2[0x30]) - uVar4;
  }
  else {
    uVar9 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    iVar11 = uVar9 - (uVar9 >> 0x10);
  }
  iVar1 = param_2[0x32];
  uVar9 = param_2[0x33] * (uVar2 & 0xffff);
  uVar5 = (1 - (short)param_2[0x33]) - (short)uVar2;
  if (uVar9 != 0) {
    iVar7 = (uVar9 & 0xffff) - (uVar9 >> 0x10);
    uVar5 = (short)iVar7 - (short)((uint)iVar7 >> 0x10);
  }
  *param_1 = param_2[0x31] + (uVar6 ^ iVar3 + uVar10) & 0xffff | iVar11 << 0x10;
  param_1[1] = (uint)uVar5 | ((uVar10 ^ uVar8) + iVar1) * 0x10000;
  return;
}

