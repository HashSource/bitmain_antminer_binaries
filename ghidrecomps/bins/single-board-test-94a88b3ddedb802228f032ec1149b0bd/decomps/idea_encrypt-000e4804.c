
void idea_encrypt(ulong *in,IDEA_KEY_SCHEDULE *ks)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  
  uVar5 = ks->data[0][0];
  uVar1 = *in >> 0x10;
  uVar2 = uVar5 * uVar1;
  if (uVar2 == 0) {
    uVar1 = (1 - uVar5) - uVar1;
  }
  else {
    uVar1 = (uVar2 & 0xffff) - (uVar2 >> 0x10);
    uVar1 = uVar1 - (uVar1 >> 0x10);
  }
  uVar10 = ks->data[0][3];
  uVar7 = in[1] & 0xffff;
  uVar3 = uVar7 * uVar10;
  uVar2 = *in + ks->data[0][1];
  uVar5 = (in[1] >> 0x10) + ks->data[0][2];
  if (uVar3 == 0) {
    uVar7 = (1 - uVar10) - uVar7;
  }
  else {
    uVar7 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar7 = uVar7 - (uVar7 >> 0x10);
  }
  uVar10 = ks->data[0][4];
  uVar11 = (uVar1 ^ uVar5) & 0xffff;
  uVar3 = uVar10 * uVar11;
  if (uVar3 == 0) {
    iVar4 = (1 - uVar10) - uVar11;
  }
  else {
    uVar3 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    iVar4 = uVar3 - (uVar3 >> 0x10);
  }
  uVar11 = ks->data[0][5];
  uVar10 = (uVar7 ^ uVar2) + iVar4 & 0xffff;
  uVar3 = uVar11 * uVar10;
  if (uVar3 == 0) {
    uVar10 = (1 - uVar11) - uVar10;
  }
  else {
    uVar10 = (uVar3 & 0xffff) - (uVar3 >> 0x10);
    uVar10 = uVar10 - (uVar10 >> 0x10);
  }
  uVar11 = ks->data[1][0];
  uVar3 = (uVar1 ^ uVar10) & 0xffff;
  uVar1 = uVar11 * uVar3;
  if (uVar1 == 0) {
    uVar3 = (1 - uVar11) - uVar3;
  }
  else {
    uVar3 = (uVar1 & 0xffff) - (uVar1 >> 0x10);
    uVar3 = uVar3 - (uVar3 >> 0x10);
  }
  uVar11 = ks->data[1][3];
  uVar8 = (uVar7 ^ uVar10 + iVar4) & 0xffff;
  uVar7 = uVar11 * uVar8;
  uVar1 = (uVar10 ^ uVar5) + ks->data[1][1];
  uVar2 = (uVar10 + iVar4 ^ uVar2) + ks->data[1][2];
  if (uVar7 == 0) {
    uVar8 = (1 - uVar11) - uVar8;
  }
  else {
    uVar8 = (uVar7 & 0xffff) - (uVar7 >> 0x10);
    uVar8 = uVar8 - (uVar8 >> 0x10);
  }
  uVar7 = ks->data[1][4];
  uVar10 = (uVar3 ^ uVar2) & 0xffff;
  uVar5 = uVar7 * uVar10;
  if (uVar5 == 0) {
    iVar4 = (1 - uVar7) - uVar10;
  }
  else {
    uVar5 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    iVar4 = uVar5 - (uVar5 >> 0x10);
  }
  uVar5 = ks->data[1][5];
  uVar7 = (uVar8 ^ uVar1) + iVar4 & 0xffff;
  uVar10 = uVar5 * uVar7;
  if (uVar10 == 0) {
    uVar7 = (1 - uVar5) - uVar7;
  }
  else {
    uVar7 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar7 = uVar7 - (uVar7 >> 0x10);
  }
  uVar10 = ks->data[2][0];
  uVar3 = (uVar7 ^ uVar3) & 0xffff;
  uVar5 = uVar10 * uVar3;
  if (uVar5 == 0) {
    uVar3 = (1 - uVar10) - uVar3;
  }
  else {
    uVar3 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    uVar3 = uVar3 - (uVar3 >> 0x10);
  }
  uVar11 = ks->data[2][3];
  uVar10 = (uVar8 ^ uVar7 + iVar4) & 0xffff;
  uVar5 = uVar11 * uVar10;
  uVar2 = (uVar7 ^ uVar2) + ks->data[2][1];
  uVar1 = (uVar7 + iVar4 ^ uVar1) + ks->data[2][2];
  if (uVar5 == 0) {
    uVar10 = (1 - uVar11) - uVar10;
  }
  else {
    uVar10 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    uVar10 = uVar10 - (uVar10 >> 0x10);
  }
  uVar7 = ks->data[2][4];
  uVar11 = (uVar3 ^ uVar1) & 0xffff;
  uVar5 = uVar7 * uVar11;
  if (uVar5 == 0) {
    iVar4 = (1 - uVar7) - uVar11;
  }
  else {
    uVar5 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    iVar4 = uVar5 - (uVar5 >> 0x10);
  }
  uVar11 = ks->data[2][5];
  uVar7 = (uVar10 ^ uVar2) + iVar4 & 0xffff;
  uVar5 = uVar11 * uVar7;
  if (uVar5 == 0) {
    uVar7 = (1 - uVar11) - uVar7;
  }
  else {
    uVar7 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    uVar7 = uVar7 - (uVar7 >> 0x10);
  }
  uVar11 = ks->data[3][0];
  uVar3 = (uVar3 ^ uVar7) & 0xffff;
  uVar5 = uVar11 * uVar3;
  if (uVar5 == 0) {
    uVar3 = (1 - uVar11) - uVar3;
  }
  else {
    uVar3 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    uVar3 = uVar3 - (uVar3 >> 0x10);
  }
  uVar5 = ks->data[3][3];
  uVar11 = (uVar10 ^ uVar7 + iVar4) & 0xffff;
  uVar10 = uVar5 * uVar11;
  uVar1 = (uVar7 ^ uVar1) + ks->data[3][1];
  uVar2 = (uVar7 + iVar4 ^ uVar2) + ks->data[3][2];
  if (uVar10 == 0) {
    uVar11 = (1 - uVar5) - uVar11;
  }
  else {
    uVar11 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar11 = uVar11 - (uVar11 >> 0x10);
  }
  uVar7 = ks->data[3][4];
  uVar10 = (uVar3 ^ uVar2) & 0xffff;
  uVar5 = uVar7 * uVar10;
  if (uVar5 == 0) {
    iVar4 = (1 - uVar7) - uVar10;
  }
  else {
    uVar5 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    iVar4 = uVar5 - (uVar5 >> 0x10);
  }
  uVar5 = ks->data[3][5];
  uVar7 = (uVar11 ^ uVar1) + iVar4 & 0xffff;
  uVar10 = uVar5 * uVar7;
  if (uVar10 == 0) {
    uVar7 = (1 - uVar5) - uVar7;
  }
  else {
    uVar7 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar7 = uVar7 - (uVar7 >> 0x10);
  }
  uVar10 = ks->data[4][0];
  uVar3 = (uVar7 ^ uVar3) & 0xffff;
  uVar5 = uVar10 * uVar3;
  if (uVar5 == 0) {
    uVar3 = (1 - uVar10) - uVar3;
  }
  else {
    uVar3 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    uVar3 = uVar3 - (uVar3 >> 0x10);
  }
  uVar8 = ks->data[4][3];
  uVar10 = (uVar11 ^ uVar7 + iVar4) & 0xffff;
  uVar5 = uVar8 * uVar10;
  uVar2 = (uVar7 ^ uVar2) + ks->data[4][1];
  uVar1 = (uVar7 + iVar4 ^ uVar1) + ks->data[4][2];
  if (uVar5 == 0) {
    uVar10 = (1 - uVar8) - uVar10;
  }
  else {
    uVar10 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    uVar10 = uVar10 - (uVar10 >> 0x10);
  }
  uVar7 = ks->data[4][4];
  uVar11 = (uVar3 ^ uVar1) & 0xffff;
  uVar5 = uVar7 * uVar11;
  if (uVar5 == 0) {
    iVar4 = (1 - uVar7) - uVar11;
  }
  else {
    uVar5 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    iVar4 = uVar5 - (uVar5 >> 0x10);
  }
  uVar11 = ks->data[4][5];
  uVar7 = (uVar10 ^ uVar2) + iVar4 & 0xffff;
  uVar5 = uVar11 * uVar7;
  if (uVar5 == 0) {
    uVar7 = (1 - uVar11) - uVar7;
  }
  else {
    uVar7 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    uVar7 = uVar7 - (uVar7 >> 0x10);
  }
  uVar11 = ks->data[5][0];
  uVar3 = (uVar3 ^ uVar7) & 0xffff;
  uVar5 = uVar11 * uVar3;
  if (uVar5 == 0) {
    uVar3 = (1 - uVar11) - uVar3;
  }
  else {
    uVar3 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    uVar3 = uVar3 - (uVar3 >> 0x10);
  }
  uVar5 = ks->data[5][3];
  uVar11 = (uVar10 ^ uVar7 + iVar4) & 0xffff;
  uVar10 = uVar5 * uVar11;
  uVar1 = (uVar7 ^ uVar1) + ks->data[5][1];
  uVar2 = (uVar7 + iVar4 ^ uVar2) + ks->data[5][2];
  if (uVar10 == 0) {
    uVar11 = (1 - uVar5) - uVar11;
  }
  else {
    uVar11 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar11 = uVar11 - (uVar11 >> 0x10);
  }
  uVar7 = ks->data[5][4];
  uVar10 = (uVar3 ^ uVar2) & 0xffff;
  uVar5 = uVar7 * uVar10;
  if (uVar5 == 0) {
    iVar4 = (1 - uVar7) - uVar10;
  }
  else {
    uVar5 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    iVar4 = uVar5 - (uVar5 >> 0x10);
  }
  uVar5 = ks->data[5][5];
  uVar7 = (uVar11 ^ uVar1) + iVar4 & 0xffff;
  uVar10 = uVar5 * uVar7;
  if (uVar10 == 0) {
    uVar7 = (1 - uVar5) - uVar7;
  }
  else {
    uVar7 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar7 = uVar7 - (uVar7 >> 0x10);
  }
  uVar10 = ks->data[6][0];
  uVar3 = (uVar7 ^ uVar3) & 0xffff;
  uVar5 = uVar10 * uVar3;
  if (uVar5 == 0) {
    uVar3 = (1 - uVar10) - uVar3;
  }
  else {
    uVar3 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    uVar3 = uVar3 - (uVar3 >> 0x10);
  }
  uVar8 = ks->data[6][3];
  uVar10 = (uVar11 ^ uVar7 + iVar4) & 0xffff;
  uVar5 = uVar8 * uVar10;
  uVar2 = (uVar7 ^ uVar2) + ks->data[6][1];
  uVar1 = (uVar7 + iVar4 ^ uVar1) + ks->data[6][2];
  if (uVar5 == 0) {
    uVar10 = (1 - uVar8) - uVar10;
  }
  else {
    uVar10 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    uVar10 = uVar10 - (uVar10 >> 0x10);
  }
  uVar7 = ks->data[6][4];
  uVar11 = (uVar3 ^ uVar1) & 0xffff;
  uVar5 = uVar7 * uVar11;
  if (uVar5 == 0) {
    iVar4 = (1 - uVar7) - uVar11;
  }
  else {
    uVar5 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    iVar4 = uVar5 - (uVar5 >> 0x10);
  }
  uVar11 = ks->data[6][5];
  uVar7 = (uVar10 ^ uVar2) + iVar4 & 0xffff;
  uVar5 = uVar11 * uVar7;
  if (uVar5 == 0) {
    uVar7 = (1 - uVar11) - uVar7;
  }
  else {
    uVar7 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    uVar7 = uVar7 - (uVar7 >> 0x10);
  }
  uVar11 = ks->data[7][0];
  uVar3 = (uVar3 ^ uVar7) & 0xffff;
  uVar5 = uVar11 * uVar3;
  if (uVar5 == 0) {
    uVar3 = (1 - uVar11) - uVar3;
  }
  else {
    uVar3 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    uVar3 = uVar3 - (uVar3 >> 0x10);
  }
  uVar5 = ks->data[7][3];
  uVar11 = (uVar10 ^ uVar7 + iVar4) & 0xffff;
  uVar10 = uVar5 * uVar11;
  uVar1 = (uVar7 ^ uVar1) + ks->data[7][1];
  uVar2 = (uVar7 + iVar4 ^ uVar2) + ks->data[7][2];
  if (uVar10 == 0) {
    uVar11 = (1 - uVar5) - uVar11;
  }
  else {
    uVar11 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar11 = uVar11 - (uVar11 >> 0x10);
  }
  uVar10 = ks->data[7][4];
  uVar7 = (uVar3 ^ uVar2) & 0xffff;
  uVar5 = uVar10 * uVar7;
  if (uVar5 == 0) {
    iVar4 = (1 - uVar10) - uVar7;
  }
  else {
    uVar5 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    iVar4 = uVar5 - (uVar5 >> 0x10);
  }
  uVar5 = ks->data[7][5];
  uVar7 = (uVar11 ^ uVar1) + iVar4 & 0xffff;
  uVar10 = uVar5 * uVar7;
  if (uVar10 == 0) {
    uVar7 = (1 - uVar5) - uVar7;
  }
  else {
    uVar7 = (uVar10 & 0xffff) - (uVar10 >> 0x10);
    uVar7 = uVar7 - (uVar7 >> 0x10);
  }
  uVar10 = ks->data[8][0];
  uVar3 = (uVar7 ^ uVar3) & 0xffff;
  uVar11 = uVar11 ^ uVar7 + iVar4;
  uVar5 = uVar10 * uVar3;
  if (uVar5 == 0) {
    iVar12 = (1 - uVar10) - uVar3;
  }
  else {
    uVar5 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    iVar12 = uVar5 - (uVar5 >> 0x10);
  }
  uVar3 = ks->data[8][3];
  uVar10 = ks->data[8][2];
  uVar5 = uVar3 * (uVar11 & 0xffff);
  if (uVar5 == 0) {
    uVar6 = (1 - (short)uVar3) - (short)uVar11;
  }
  else {
    iVar9 = (uVar5 & 0xffff) - (uVar5 >> 0x10);
    uVar6 = (short)iVar9 - (short)((uint)iVar9 >> 0x10);
  }
  *in = (uVar7 + iVar4 ^ uVar1) + ks->data[8][1] & 0xffff | iVar12 << 0x10;
  in[1] = (uint)uVar6 | ((uVar7 ^ uVar2) + uVar10) * 0x10000;
  return;
}

