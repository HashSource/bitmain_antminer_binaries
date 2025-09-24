
void RC2_set_key(RC2_KEY *key,int len,uchar *data,int bits)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  char cVar4;
  uchar *puVar5;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  byte *pbVar11;
  uint uVar12;
  uint *puVar13;
  int iVar15;
  char *pcVar16;
  char *pcVar17;
  uint uVar18;
  char *pcVar19;
  uint *puVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  uchar *puVar6;
  uchar *puVar14;
  
  if (0x7f < len) {
    len = 0x80;
  }
  iVar24 = 0;
  *(undefined1 *)key->data = 0;
  if (bits < 1) {
    uVar22 = 0xff;
    iVar7 = -1;
    iVar10 = 0x80;
  }
  else if (bits < 0x401) {
    iVar10 = bits + 7 >> 3;
    iVar24 = 0x80 - iVar10;
    uVar22 = 0xff >> (-bits & 7U);
    iVar7 = 0x7f - iVar10;
  }
  else {
    uVar22 = 0xff;
    iVar10 = 0x80;
    iVar7 = -1;
  }
  if (len < 1) {
    cVar4 = *(char *)((int)key->data + (len - 1U));
  }
  else {
    if ((((uint)key | (uint)data) & 3) == 0 &&
        (9 < (uint)len && (key->data + 1 <= data || (RC2_KEY *)(data + 4) <= key))) {
      uVar12 = len - 4U >> 2;
      iVar23 = uVar12 * 4;
      if (uVar12 - 8 < 0xfffffff7) {
        puVar20 = key->data;
        uVar18 = (uVar12 - 8 & 0xfffffff8) + 8;
        uVar21 = 0;
        puVar6 = data + 0x20;
        do {
          puVar14 = puVar6;
          puVar20 = puVar20 + 8;
          uVar21 = uVar21 + 8;
          HintPreloadData(puVar14 + 0x54);
          puVar20[-8] = *(undefined4 *)(puVar14 + -0x20);
          puVar20[-7] = *(undefined4 *)(puVar14 + -0x1c);
          puVar20[-6] = *(undefined4 *)(puVar14 + -0x18);
          puVar20[-5] = *(undefined4 *)(puVar14 + -0x14);
          puVar20[-4] = *(undefined4 *)(puVar14 + -0x10);
          puVar20[-3] = *(undefined4 *)(puVar14 + -0xc);
          puVar20[-2] = *(undefined4 *)(puVar14 + -8);
          ((RC2_KEY *)(puVar20 + -1))->data[0] = *(uint *)(puVar14 + -4);
          puVar6 = puVar14 + 0x20;
        } while (uVar18 != uVar21);
      }
      else {
        uVar18 = 0;
        puVar14 = data;
        puVar20 = key->data;
      }
      puVar13 = (uint *)(puVar14 + -4);
      do {
        puVar13 = puVar13 + 1;
        uVar18 = uVar18 + 1;
        *puVar20 = *puVar13;
        puVar20 = puVar20 + 1;
      } while (uVar18 < uVar12 + 1);
      if (iVar23 + 4U != len) {
        iVar15 = iVar23 + 5;
        *(uchar *)(key->data + uVar12 + 1) = data[(uVar12 + 1) * 4];
        if (iVar15 < len) {
          iVar23 = iVar23 + 6;
          *(uchar *)((int)key->data + iVar15) = data[iVar15];
          if (iVar23 < len) {
            *(uchar *)((int)key->data + iVar23) = data[iVar23];
          }
        }
      }
    }
    else {
      puVar14 = (uchar *)((int)key[-1].data + 0xff);
      puVar6 = data;
      do {
        puVar5 = puVar6 + 1;
        puVar14 = puVar14 + 1;
        *puVar14 = *puVar6;
        puVar6 = puVar5;
      } while (puVar5 != data + len);
    }
    cVar4 = *(char *)((int)key->data + (len - 1U));
    if (len == 0x80) goto LAB_0014d534;
  }
  pcVar19 = (char *)((int)key[-1].data + 0xff);
  pcVar16 = (char *)((int)key->data + len);
  do {
    pcVar19 = pcVar19 + 1;
    cVar4 = (&key_table)[(byte)(cVar4 + *pcVar19)];
    pcVar17 = pcVar16 + 1;
    *pcVar16 = cVar4;
    pcVar16 = pcVar17;
  } while ((uint *)pcVar17 != key->data + 0x20);
LAB_0014d534:
  bVar1 = (&key_table)[*(byte *)((int)key->data + iVar24) & uVar22];
  *(byte *)((int)key->data + iVar24) = bVar1;
  pbVar8 = (byte *)((int)key->data + iVar7);
  pbVar11 = (byte *)((int)key->data + iVar10 + iVar7);
  if (iVar24 != 0) {
    do {
      bVar1 = (&key_table)[bVar1 ^ *pbVar11];
      pbVar9 = pbVar8 + -1;
      *pbVar8 = bVar1;
      pbVar8 = pbVar9;
      pbVar11 = pbVar11 + -1;
    } while ((byte *)((int)key[-1].data + 0xff) != pbVar9);
  }
  iVar7 = 0x40;
  iVar24 = 0x7f;
  puVar2 = (undefined1 *)((int)key->data + 0x5e);
  puVar20 = key->data + 0x37;
  do {
    puVar13 = puVar20;
    iVar10 = iVar24;
    iVar7 = iVar7 + -8;
    HintPreloadData(puVar2);
    HintPreloadData(puVar13 + -8);
    iVar24 = iVar10 + -0x10;
    puVar13[8] = (uint)*(ushort *)(puVar2 + 0x20);
    puVar13[7] = (uint)(ushort)*(uint *)(puVar2 + 0x1e);
    puVar13[6] = (uint)*(ushort *)(puVar2 + 0x1c);
    puVar13[5] = (uint)(ushort)*(uint *)(puVar2 + 0x1a);
    puVar13[4] = (uint)*(ushort *)(puVar2 + 0x18);
    puVar13[3] = (uint)(ushort)*(uint *)(puVar2 + 0x16);
    puVar13[2] = (uint)*(ushort *)(puVar2 + 0x14);
    puVar13[1] = (uint)(ushort)*(uint *)(puVar2 + 0x12);
    puVar2 = puVar2 + -0x10;
    puVar20 = puVar13 + -8;
  } while (iVar7 != 8);
  puVar13 = puVar13 + 1;
  puVar2 = (undefined1 *)((int)key->data + iVar24);
  do {
    puVar3 = puVar2 + -2;
    puVar13 = puVar13 + -1;
    *puVar13 = (uint)CONCAT11(*puVar2,puVar2[-1]);
    puVar2 = puVar3;
  } while ((undefined1 *)((int)key->data + iVar10 + -0x20) != puVar3);
  return;
}

