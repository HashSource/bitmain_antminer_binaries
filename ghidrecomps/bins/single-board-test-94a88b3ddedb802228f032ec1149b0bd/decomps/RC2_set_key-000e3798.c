
/* WARNING: Type propagation algorithm not settling */

void RC2_set_key(RC2_KEY *key,int len,uchar *data,int bits)

{
  undefined *puVar1;
  undefined uVar2;
  byte bVar3;
  int iVar4;
  uchar *puVar5;
  undefined *puVar6;
  char cVar7;
  uint *puVar8;
  uint uVar9;
  char *pcVar10;
  uint *puVar11;
  int iVar12;
  undefined *puVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint *puVar18;
  int local_30;
  int local_2c;
  uint local_28;
  uchar *puVar19;
  
  if (0x7f < len) {
    len = 0x80;
  }
  *(undefined *)key->data = 0;
  if ((bits < 1) || (0x400 < bits)) {
    iVar14 = -1;
    local_28 = 0xff;
    local_2c = 0;
    local_30 = 0x80;
  }
  else {
    local_30 = bits + 7 >> 3;
    local_28 = 0xff >> (-bits & 7U);
    local_2c = 0x80 - local_30;
    iVar14 = 0x7f - local_30;
  }
  if (len < 1) {
    cVar7 = *(char *)((int)key->data + (len - 1U));
  }
  else {
    uVar16 = (uint)len >> 2;
    uVar9 = len & 0xfffffffc;
    if (uVar16 == 0 ||
        ((uint)len < 4 ||
        (((uint)data & 3) != 0 || data < key->data + 1 && key < (RC2_KEY *)(data + 4)))) {
      uVar9 = 0;
LAB_000e38a0:
      do {
        *(uchar *)((int)key->data + uVar9) = data[uVar9];
        uVar9 = uVar9 + 1;
      } while ((int)uVar9 < len);
    }
    else {
      if (uVar16 < 9) {
        uVar15 = 0;
        puVar8 = key->data;
        puVar19 = data;
      }
      else {
        puVar8 = key->data;
        uVar15 = 0;
        puVar5 = data + 0x20;
        do {
          puVar19 = puVar5;
          puVar8 = puVar8 + 8;
          uVar17 = uVar15 + 9;
          uVar15 = uVar15 + 8;
          HintPreloadData(puVar19 + 0x54);
          puVar8[-8] = *(undefined4 *)(puVar19 + -0x20);
          puVar8[-7] = *(undefined4 *)(puVar19 + -0x1c);
          puVar8[-6] = *(undefined4 *)(puVar19 + -0x18);
          puVar8[-5] = *(undefined4 *)(puVar19 + -0x14);
          puVar8[-4] = *(undefined4 *)(puVar19 + -0x10);
          puVar8[-3] = *(undefined4 *)(puVar19 + -0xc);
          puVar8[-2] = *(undefined4 *)(puVar19 + -8);
          ((RC2_KEY *)(puVar8 + -1))->data[0] = *(uint *)(puVar19 + -4);
          puVar5 = puVar19 + 0x20;
        } while (uVar17 < uVar16 - 7);
      }
      puVar18 = (uint *)(puVar19 + -4);
      do {
        puVar18 = puVar18 + 1;
        uVar15 = uVar15 + 1;
        *puVar8 = *puVar18;
        puVar8 = puVar8 + 1;
      } while (uVar15 < uVar16);
      if (uVar9 != len) goto LAB_000e38a0;
    }
    cVar7 = *(char *)((int)key->data + (len - 1U));
    iVar12 = DAT_000e39ec;
    if (len == 0x80) goto LAB_000e38d4;
  }
  iVar12 = DAT_000e39ec;
  pcVar10 = (char *)((int)key[-1].data + 0xff);
  do {
    pcVar10 = pcVar10 + 1;
    cVar7 = *(char *)(iVar12 + (uint)(byte)(cVar7 + *pcVar10));
    pcVar10[len] = cVar7;
  } while (pcVar10 != (char *)((int)key + (0x7f - len)));
LAB_000e38d4:
  bVar3 = *(byte *)(iVar12 + (*(byte *)((int)key->data + local_2c) & local_28));
  *(byte *)((int)key->data + local_2c) = bVar3;
  while (iVar4 = iVar14, local_2c != 0) {
    bVar3 = *(byte *)(iVar12 + (uint)(bVar3 ^ *(byte *)((int)key->data + iVar4 + local_30)));
    *(byte *)((int)key->data + iVar4) = bVar3;
    iVar14 = iVar4 + -1;
    local_2c = iVar4;
  }
  iVar12 = 0x40;
  iVar14 = 0x7f;
  puVar8 = key->data;
  puVar18 = key->data + 0x37;
  do {
    puVar11 = puVar18;
    HintPreloadData((int)key->data + iVar14 + -0x1f);
    iVar14 = iVar14 + -0x10;
    HintPreloadData(puVar11 + -7);
    iVar12 = iVar12 + -8;
    puVar11[8] = (uint)*(ushort *)((int)puVar8 + 0x7e);
    puVar11[7] = (uint)*(ushort *)(puVar8 + 0x1f);
    puVar11[6] = (uint)*(ushort *)((int)puVar8 + 0x7a);
    puVar11[5] = (uint)*(ushort *)(puVar8 + 0x1e);
    puVar11[4] = (uint)*(ushort *)((int)puVar8 + 0x76);
    puVar11[3] = (uint)*(ushort *)(puVar8 + 0x1d);
    puVar11[2] = (uint)*(ushort *)((int)puVar8 + 0x72);
    puVar18 = puVar8 + 0x1c;
    puVar8 = puVar8 + -4;
    puVar11[1] = (uint)*(ushort *)puVar18;
    puVar18 = puVar11 + -8;
  } while (iVar14 != 0xf);
  puVar6 = (undefined *)((int)key->data + 0xf);
  puVar13 = puVar6 + iVar12 * -2;
  do {
    uVar2 = *puVar6;
    puVar1 = puVar6 + -1;
    puVar6 = puVar6 + -2;
    *puVar11 = (uint)CONCAT11(uVar2,*puVar1);
    puVar11 = puVar11 + -1;
  } while (puVar6 != puVar13);
  return;
}

