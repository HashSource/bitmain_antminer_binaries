
/* WARNING: Type propagation algorithm not settling */

void RC2_set_key(RC2_KEY *key,int len,uchar *data,int bits)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  byte bVar3;
  uchar *puVar4;
  undefined1 *puVar5;
  char cVar6;
  uint *puVar7;
  uint uVar8;
  char *pcVar9;
  uint *puVar10;
  int iVar11;
  undefined1 *puVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  int local_30;
  int local_2c;
  uint local_28;
  uchar *puVar18;
  
  if (0x7f < len) {
    len = 0x80;
  }
  *(undefined1 *)key->data = 0;
  if ((bits < 1) || (0x400 < bits)) {
    iVar13 = -1;
    local_28 = 0xff;
    local_2c = 0;
    local_30 = 0x80;
  }
  else {
    local_30 = bits + 7 >> 3;
    local_28 = 0xff >> (-bits & 7U);
    local_2c = 0x80 - local_30;
    iVar13 = 0x7f - local_30;
  }
  if (len < 1) {
    cVar6 = *(char *)((int)key->data + (len - 1U));
  }
  else {
    uVar15 = (uint)len >> 2;
    uVar8 = uVar15 << 2;
    if (uVar15 == 0 ||
        ((uint)len < 4 ||
        (((uint)data & 3) != 0 || data < key->data + 1 && key < (RC2_KEY *)(data + 4)))) {
      uVar8 = 0;
LAB_000e38a0:
      do {
        *(uchar *)((int)key->data + uVar8) = data[uVar8];
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < len);
    }
    else {
      if (uVar15 < 9) {
        uVar14 = 0;
        puVar7 = key->data;
        puVar18 = data;
      }
      else {
        puVar7 = key->data;
        uVar14 = 0;
        puVar4 = data + 0x20;
        do {
          puVar18 = puVar4;
          puVar7 = puVar7 + 8;
          uVar16 = uVar14 + 9;
          uVar14 = uVar14 + 8;
          HintPreloadData(puVar18 + 0x54);
          puVar7[-8] = *(undefined4 *)(puVar18 + -0x20);
          puVar7[-7] = *(undefined4 *)(puVar18 + -0x1c);
          puVar7[-6] = *(undefined4 *)(puVar18 + -0x18);
          puVar7[-5] = *(undefined4 *)(puVar18 + -0x14);
          puVar7[-4] = *(undefined4 *)(puVar18 + -0x10);
          puVar7[-3] = *(undefined4 *)(puVar18 + -0xc);
          puVar7[-2] = *(undefined4 *)(puVar18 + -8);
          ((RC2_KEY *)(puVar7 + -1))->data[0] = *(uint *)(puVar18 + -4);
          puVar4 = puVar18 + 0x20;
        } while (uVar16 < uVar15 - 7);
      }
      puVar17 = (uint *)(puVar18 + -4);
      do {
        puVar17 = puVar17 + 1;
        uVar14 = uVar14 + 1;
        *puVar7 = *puVar17;
        puVar7 = puVar7 + 1;
      } while (uVar14 < uVar15);
      if (uVar8 != len) goto LAB_000e38a0;
    }
    cVar6 = *(char *)((int)key->data + (len - 1U));
    if (len == 0x80) goto LAB_000e38d4;
  }
  pcVar9 = (char *)((int)key[-1].data + 0xff);
  do {
    pcVar9 = pcVar9 + 1;
    cVar6 = (&key_table)[(byte)(cVar6 + *pcVar9)];
    pcVar9[len] = cVar6;
  } while (pcVar9 != (char *)((int)key + (0x7f - len)));
LAB_000e38d4:
  bVar3 = (&key_table)[*(byte *)((int)key->data + local_2c) & local_28];
  *(byte *)((int)key->data + local_2c) = bVar3;
  while (iVar11 = iVar13, local_2c != 0) {
    bVar3 = (&key_table)[bVar3 ^ *(byte *)((int)key->data + iVar11 + local_30)];
    *(byte *)((int)key->data + iVar11) = bVar3;
    iVar13 = iVar11 + -1;
    local_2c = iVar11;
  }
  iVar11 = 0x40;
  iVar13 = 0x7f;
  puVar7 = key->data;
  puVar17 = key->data + 0x37;
  do {
    puVar10 = puVar17;
    HintPreloadData((int)key->data + iVar13 + -0x1f);
    iVar13 = iVar13 + -0x10;
    HintPreloadData(puVar10 + -7);
    iVar11 = iVar11 + -8;
    puVar10[8] = (uint)*(ushort *)((int)puVar7 + 0x7e);
    puVar10[7] = (uint)(ushort)puVar7[0x1f];
    puVar10[6] = (uint)*(ushort *)((int)puVar7 + 0x7a);
    puVar10[5] = (uint)(ushort)puVar7[0x1e];
    puVar10[4] = (uint)*(ushort *)((int)puVar7 + 0x76);
    puVar10[3] = (uint)(ushort)puVar7[0x1d];
    puVar10[2] = (uint)*(ushort *)((int)puVar7 + 0x72);
    puVar17 = puVar7 + 0x1c;
    puVar7 = puVar7 + -4;
    puVar10[1] = (uint)(ushort)*puVar17;
    puVar17 = puVar10 + -8;
  } while (iVar13 != 0xf);
  puVar5 = (undefined1 *)((int)key->data + 0xf);
  puVar12 = puVar5 + iVar11 * -2;
  do {
    uVar2 = *puVar5;
    puVar1 = puVar5 + -1;
    puVar5 = puVar5 + -2;
    *puVar10 = (uint)CONCAT11(uVar2,*puVar1);
    puVar10 = puVar10 + -1;
  } while (puVar5 != puVar12);
  return;
}

