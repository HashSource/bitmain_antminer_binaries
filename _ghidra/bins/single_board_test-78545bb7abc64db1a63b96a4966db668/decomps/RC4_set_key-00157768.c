
void RC4_set_key(RC4_KEY *key,int len,uchar *data)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  
  uVar7 = 0;
  key->x = 0;
  key->y = 0;
  puVar1 = key->data + 0x1d;
  do {
    puVar1[-0x1d] = uVar7;
    uVar20 = uVar7 + 1;
    uVar8 = uVar7 + 2;
    uVar5 = uVar7 + 3;
    uVar6 = uVar7 + 4;
    uVar12 = uVar7 + 5;
    uVar10 = uVar7 + 6;
    uVar9 = uVar7 + 7;
    uVar7 = uVar7 + 8;
    HintPreloadData(puVar1);
    puVar1[-0x1c] = uVar20;
    puVar1[-0x1b] = uVar8;
    puVar1[-0x1a] = uVar5;
    puVar1[-0x19] = uVar6;
    puVar1[-0x18] = uVar12;
    puVar1[-0x17] = uVar10;
    puVar1[-0x16] = uVar9;
    puVar1 = puVar1 + 8;
  } while (uVar7 != 0xf8);
  puVar1 = key->data + 0xf7;
  uVar7 = 0xf8;
  do {
    puVar1 = puVar1 + 1;
    *puVar1 = uVar7;
    uVar7 = uVar7 + 1;
  } while (uVar7 != 0x100);
  iVar14 = 0;
  uVar7 = 0;
  iVar2 = 0;
  puVar1 = key->data + 0xf;
  iVar4 = 0x40;
  do {
    iVar19 = iVar4;
    uVar5 = puVar1[-0xf];
    iVar16 = iVar2 + 1;
    iVar15 = iVar2 + 2;
    iVar4 = iVar16;
    if (iVar16 == len) {
      iVar4 = 0;
    }
    HintPreloadData(puVar1);
    if (iVar16 == len) {
      iVar15 = 1;
    }
    iVar16 = iVar15 + 1;
    uVar7 = uVar7 + uVar5 + (uint)data[iVar2] & 0xff;
    if (len == iVar15) {
      iVar16 = 1;
    }
    iVar11 = iVar16 + 1;
    if (len == iVar16) {
      iVar11 = 1;
    }
    if (len == iVar11) {
      iVar11 = 0;
    }
    if (len == iVar15) {
      iVar15 = 0;
    }
    if (len == iVar16) {
      iVar16 = 0;
    }
    iVar14 = iVar14 + 8;
    puVar1[-0xf] = key->data[uVar7];
    key->data[uVar7] = uVar5;
    iVar2 = iVar11 + 1;
    iVar18 = iVar2;
    if (len == iVar2) {
      iVar18 = 0;
    }
    uVar5 = puVar1[-0xe];
    iVar3 = iVar11 + 2;
    uVar7 = uVar7 + data[iVar4] + uVar5 & 0xff;
    if (len == iVar2) {
      iVar3 = 1;
    }
    puVar1[-0xe] = key->data[uVar7];
    key->data[uVar7] = uVar5;
    iVar4 = iVar3;
    if (len == iVar3) {
      iVar4 = 0;
    }
    uVar5 = puVar1[-0xd];
    iVar17 = iVar3 + 1;
    uVar7 = uVar7 + data[iVar15] + uVar5 & 0xff;
    if (len == iVar3) {
      iVar17 = 1;
    }
    puVar1[-0xd] = key->data[uVar7];
    key->data[uVar7] = uVar5;
    iVar15 = iVar17;
    if (len == iVar17) {
      iVar15 = 0;
    }
    uVar5 = puVar1[-0xc];
    iVar2 = iVar17 + 1;
    uVar7 = uVar7 + data[iVar16] + uVar5 & 0xff;
    if (len == iVar17) {
      iVar2 = 1;
    }
    if (len == iVar2) {
      iVar2 = 0;
    }
    puVar1[-0xc] = key->data[uVar7];
    key->data[uVar7] = uVar5;
    uVar5 = puVar1[-0xb];
    uVar7 = uVar7 + data[iVar11] + uVar5 & 0xff;
    puVar1[-0xb] = key->data[uVar7];
    key->data[uVar7] = uVar5;
    uVar5 = puVar1[-10];
    uVar7 = uVar7 + data[iVar18] + uVar5 & 0xff;
    puVar1[-10] = key->data[uVar7];
    key->data[uVar7] = uVar5;
    uVar5 = puVar1[-9];
    uVar7 = data[iVar4] + uVar5 + uVar7 & 0xff;
    puVar1[-9] = key->data[uVar7];
    key->data[uVar7] = uVar5;
    uVar5 = puVar1[-8];
    uVar7 = uVar7 + data[iVar15] + uVar5 & 0xff;
    puVar1[-8] = key->data[uVar7];
    key->data[uVar7] = uVar5;
    puVar1 = puVar1 + 8;
    iVar4 = iVar19 + -2;
  } while (iVar14 != 0xf8);
  puVar1 = key->data + 0xf8;
  do {
    uVar5 = *puVar1;
    iVar14 = iVar2 + 1;
    iVar4 = iVar2 + 2;
    if (len == iVar14) {
      iVar4 = 1;
      iVar14 = 0;
    }
    iVar15 = iVar4;
    if (len == iVar4) {
      iVar15 = 0;
    }
    iVar16 = iVar4 + 1;
    uVar7 = uVar7 + uVar5 + (uint)data[iVar2] & 0xff;
    if (len == iVar4) {
      iVar16 = 1;
    }
    iVar4 = iVar16;
    if (len == iVar16) {
      iVar4 = 0;
    }
    iVar2 = iVar16 + 1;
    if (len == iVar16) {
      iVar2 = 1;
    }
    puVar13 = puVar1 + 4;
    if (len == iVar2) {
      iVar2 = 0;
    }
    *puVar1 = key->data[uVar7];
    key->data[uVar7] = uVar5;
    uVar5 = puVar1[1];
    uVar7 = uVar7 + data[iVar14] + uVar5 & 0xff;
    puVar1[1] = key->data[uVar7];
    key->data[uVar7] = uVar5;
    uVar5 = puVar1[2];
    uVar7 = uVar7 + data[iVar15] + uVar5 & 0xff;
    puVar1[2] = key->data[uVar7];
    key->data[uVar7] = uVar5;
    uVar5 = puVar1[3];
    uVar7 = uVar7 + data[iVar4] + uVar5 & 0xff;
    puVar1[3] = key->data[uVar7];
    key->data[uVar7] = uVar5;
    puVar1 = puVar13;
  } while (puVar13 != key->data + iVar19 * 4 + 0xf0);
  return;
}

