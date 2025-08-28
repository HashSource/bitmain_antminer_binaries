
void RC4_set_key(RC4_KEY *key,int len,uchar *data)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  RC4_KEY *pRVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  uint uVar11;
  
  *(undefined1 *)&key->x = 0;
  *(undefined1 *)((int)&key->x + 1) = 0;
  pRVar6 = key;
  iVar4 = 0;
  do {
    iVar9 = iVar4;
    cVar2 = (char)iVar9;
    *(char *)((int)key->data + iVar9 + -6) = cVar2;
    *(char *)((int)&pRVar6->x + 3) = cVar2 + '\x01';
    *(char *)&pRVar6->y = cVar2 + '\x02';
    *(char *)((int)&pRVar6->y + 1) = cVar2 + '\x03';
    *(char *)((int)&pRVar6->y + 2) = cVar2 + '\x04';
    *(char *)((int)pRVar6->data + 1) = cVar2 + '\a';
    *(char *)((int)pRVar6->data + 2) = cVar2 + '\b';
    *(char *)((int)pRVar6->data + 3) = cVar2 + '\t';
    *(char *)(pRVar6->data + 1) = cVar2 + '\n';
    *(char *)((int)pRVar6->data + 6) = cVar2 + '\f';
    HintPreloadData((int)key->data + iVar9 + 0x22);
    *(char *)((int)&pRVar6->y + 3) = cVar2 + '\x05';
    *(char *)pRVar6->data = cVar2 + '\x06';
    *(char *)((int)pRVar6->data + 7) = cVar2 + '\r';
    *(char *)(pRVar6->data + 2) = cVar2 + '\x0e';
    *(char *)((int)pRVar6->data + 9) = cVar2 + '\x0f';
    *(char *)((int)pRVar6->data + 0xb) = cVar2 + '\x11';
    *(char *)(pRVar6->data + 3) = cVar2 + '\x12';
    *(char *)((int)pRVar6->data + 5) = cVar2 + '\v';
    *(char *)((int)pRVar6->data + 10) = cVar2 + '\x10';
    *(char *)((int)pRVar6->data + 0xd) = cVar2 + '\x13';
    *(char *)((int)pRVar6->data + 0xe) = cVar2 + '\x14';
    *(char *)(pRVar6->data + 4) = cVar2 + '\x16';
    *(char *)((int)pRVar6->data + 0x11) = cVar2 + '\x17';
    *(char *)((int)pRVar6->data + 0x12) = cVar2 + '\x18';
    *(char *)((int)pRVar6->data + 0xf) = cVar2 + '\x15';
    *(char *)((int)pRVar6->data + 0x13) = cVar2 + '\x19';
    *(char *)(pRVar6->data + 5) = cVar2 + '\x1a';
    *(char *)((int)pRVar6->data + 0x15) = cVar2 + '\x1b';
    *(char *)((int)pRVar6->data + 0x16) = cVar2 + '\x1c';
    *(char *)((int)pRVar6->data + 0x17) = cVar2 + '\x1d';
    *(char *)(pRVar6->data + 6) = cVar2 + '\x1e';
    *(char *)((int)pRVar6->data + 0x19) = cVar2 + '\x1f';
    pRVar6 = (RC4_KEY *)(pRVar6->data + 6);
    iVar4 = iVar9 + 0x20;
  } while (iVar9 + 0x20 != 0xe0);
  iVar4 = 0xe0;
  do {
    *(char *)((int)key->data + iVar4 + -6) = (char)iVar4;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x1c0 - iVar9);
  uVar11 = 0;
  puVar5 = (undefined1 *)((int)&key->x + 2);
  iVar4 = 0;
  puVar10 = (undefined1 *)((int)&key->x + 3);
  do {
    bVar1 = puVar10[-1];
    iVar7 = iVar4 + 1;
    iVar9 = iVar4 + 2;
    if (iVar7 == len) {
      iVar9 = 1;
      iVar7 = 0;
    }
    iVar8 = iVar9 + 1;
    if (len == iVar9) {
      iVar8 = 1;
    }
    uVar11 = uVar11 + (uint)data[iVar4] + (uint)bVar1 & 0xff;
    puVar10[-1] = *(undefined1 *)((int)key->data + (uVar11 - 6));
    puVar10 = puVar10 + 4;
    *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
    bVar1 = puVar5[1];
    if (len == iVar9) {
      iVar9 = 0;
    }
    uVar11 = uVar11 + (uint)data[iVar7] + (uint)bVar1 & 0xff;
    iVar4 = iVar8 + 1;
    if (len == iVar8) {
      iVar4 = 1;
    }
    if (len == iVar8) {
      iVar8 = 0;
    }
    if (len == iVar4) {
      iVar4 = 0;
    }
    puVar5[1] = *(undefined1 *)((int)key->data + (uVar11 - 6));
    *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
    uVar3 = *(uint *)(puVar5 + 2);
    uVar11 = uVar11 + (uint)data[iVar9] + (uint)(byte)uVar3 & 0xff;
    puVar5[2] = *(undefined1 *)((int)key->data + (uVar11 - 6));
    *(byte *)((int)key->data + (uVar11 - 6)) = (byte)uVar3;
    bVar1 = puVar5[3];
    uVar11 = (uint)data[iVar8] + (uint)bVar1 + uVar11 & 0xff;
    puVar5[3] = *(undefined1 *)((int)key->data + (uVar11 - 6));
    puVar5 = puVar5 + 4;
    *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
  } while (puVar5 != (undefined1 *)((int)key->data + 0xfa));
  return;
}

