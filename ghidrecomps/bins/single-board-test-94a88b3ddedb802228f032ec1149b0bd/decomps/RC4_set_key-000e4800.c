
void RC4_set_key(RC4_KEY *key,int len,uchar *data)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined *puVar4;
  RC4_KEY *pRVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  uint uVar10;
  
  *(undefined *)&key->x = 0;
  *(undefined *)((int)&key->x + 1) = 0;
  pRVar5 = key;
  iVar3 = 0;
  do {
    iVar8 = iVar3;
    cVar2 = (char)iVar8;
    *(char *)((int)key->data + iVar8 + -6) = cVar2;
    *(char *)((int)&pRVar5->x + 3) = cVar2 + '\x01';
    *(char *)&pRVar5->y = cVar2 + '\x02';
    *(char *)((int)&pRVar5->y + 1) = cVar2 + '\x03';
    *(char *)((int)&pRVar5->y + 2) = cVar2 + '\x04';
    *(char *)((int)pRVar5->data + 1) = cVar2 + '\a';
    *(char *)((int)pRVar5->data + 2) = cVar2 + '\b';
    *(char *)((int)pRVar5->data + 3) = cVar2 + '\t';
    *(char *)(pRVar5->data + 1) = cVar2 + '\n';
    *(char *)((int)pRVar5->data + 6) = cVar2 + '\f';
    HintPreloadData((int)key->data + iVar8 + 0x22);
    *(char *)((int)&pRVar5->y + 3) = cVar2 + '\x05';
    *(char *)pRVar5->data = cVar2 + '\x06';
    *(char *)((int)pRVar5->data + 7) = cVar2 + '\r';
    *(char *)(pRVar5->data + 2) = cVar2 + '\x0e';
    *(char *)((int)pRVar5->data + 9) = cVar2 + '\x0f';
    *(char *)((int)pRVar5->data + 0xb) = cVar2 + '\x11';
    *(char *)(pRVar5->data + 3) = cVar2 + '\x12';
    *(char *)((int)pRVar5->data + 5) = cVar2 + '\v';
    *(char *)((int)pRVar5->data + 10) = cVar2 + '\x10';
    *(char *)((int)pRVar5->data + 0xd) = cVar2 + '\x13';
    *(char *)((int)pRVar5->data + 0xe) = cVar2 + '\x14';
    *(char *)(pRVar5->data + 4) = cVar2 + '\x16';
    *(char *)((int)pRVar5->data + 0x11) = cVar2 + '\x17';
    *(char *)((int)pRVar5->data + 0x12) = cVar2 + '\x18';
    *(char *)((int)pRVar5->data + 0xf) = cVar2 + '\x15';
    *(char *)((int)pRVar5->data + 0x13) = cVar2 + '\x19';
    *(char *)(pRVar5->data + 5) = cVar2 + '\x1a';
    *(char *)((int)pRVar5->data + 0x15) = cVar2 + '\x1b';
    *(char *)((int)pRVar5->data + 0x16) = cVar2 + '\x1c';
    *(char *)((int)pRVar5->data + 0x17) = cVar2 + '\x1d';
    *(char *)(pRVar5->data + 6) = cVar2 + '\x1e';
    *(char *)((int)pRVar5->data + 0x19) = cVar2 + '\x1f';
    pRVar5 = (RC4_KEY *)(pRVar5->data + 6);
    iVar3 = iVar8 + 0x20;
  } while (iVar8 + 0x20 != 0xe0);
  iVar3 = 0xe0;
  do {
    *(char *)((int)key->data + iVar3 + -6) = (char)iVar3;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x1c0 - iVar8);
  uVar10 = 0;
  puVar4 = (undefined *)((int)&key->x + 2);
  iVar3 = 0;
  puVar9 = (undefined *)((int)&key->x + 3);
  do {
    bVar1 = puVar9[-1];
    iVar6 = iVar3 + 1;
    iVar8 = iVar3 + 2;
    if (iVar6 == len) {
      iVar8 = 1;
      iVar6 = 0;
    }
    iVar7 = iVar8 + 1;
    if (len == iVar8) {
      iVar7 = 1;
    }
    uVar10 = uVar10 + (uint)data[iVar3] + (uint)bVar1 & 0xff;
    puVar9[-1] = *(undefined *)((int)key->data + (uVar10 - 6));
    puVar9 = puVar9 + 4;
    *(byte *)((int)key->data + (uVar10 - 6)) = bVar1;
    bVar1 = puVar4[1];
    if (len == iVar8) {
      iVar8 = 0;
    }
    uVar10 = uVar10 + (uint)data[iVar6] + (uint)bVar1 & 0xff;
    iVar3 = iVar7 + 1;
    if (len == iVar7) {
      iVar3 = 1;
    }
    if (len == iVar7) {
      iVar7 = 0;
    }
    if (len == iVar3) {
      iVar3 = 0;
    }
    puVar4[1] = *(undefined *)((int)key->data + (uVar10 - 6));
    *(byte *)((int)key->data + (uVar10 - 6)) = bVar1;
    bVar1 = puVar4[2];
    uVar10 = uVar10 + (uint)data[iVar8] + (uint)bVar1 & 0xff;
    puVar4[2] = *(undefined *)((int)key->data + (uVar10 - 6));
    *(byte *)((int)key->data + (uVar10 - 6)) = bVar1;
    bVar1 = puVar4[3];
    uVar10 = (uint)data[iVar7] + (uint)bVar1 + uVar10 & 0xff;
    puVar4[3] = *(undefined *)((int)key->data + (uVar10 - 6));
    puVar4 = puVar4 + 4;
    *(byte *)((int)key->data + (uVar10 - 6)) = bVar1;
  } while (puVar4 != (undefined *)((int)key->data + 0xfa));
  return;
}

