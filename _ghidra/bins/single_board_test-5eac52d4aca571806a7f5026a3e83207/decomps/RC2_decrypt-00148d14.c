
void RC2_decrypt(ulong *data,RC2_KEY *key)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  puVar6 = key->data + 0x32;
  iVar8 = 3;
  iVar7 = 5;
  uVar1 = key->data[0x3f];
  uVar4 = *data & 0xffff;
  uVar9 = *data >> 0x10;
  uVar10 = data[1] >> 0x10;
  uVar2 = data[1] & 0xffff;
  do {
    HintPreloadData(puVar6);
    uVar10 = (((uVar10 >> 5 | (uVar10 & 0x1f) << 0xb) - (uVar4 & ~uVar2)) - (uVar9 & uVar2)) - uVar1
             & 0xffff;
    iVar7 = iVar7 + -1;
    uVar1 = (((uVar2 >> 3 | (uVar2 & 7) << 0xd) - (uVar10 & ~uVar9)) - (uVar4 & uVar9)) -
            puVar6[0xc];
    uVar2 = uVar1 & 0xffff;
    uVar3 = (((uVar9 >> 2 | (uVar9 & 3) << 0xe) - (uVar2 & ~uVar4)) - (uVar4 & uVar10)) -
            puVar6[0xb];
    uVar9 = uVar3 & 0xffff;
    uVar5 = (((uVar4 >> 1 | (uVar4 & 1) << 0xf) - (uVar9 & ~uVar10)) - (uVar10 & uVar1)) -
            puVar6[10];
    uVar4 = uVar5 & 0xffff;
    if (iVar7 == 0) {
      iVar8 = iVar8 + -1;
      if (iVar8 == 0) {
        *data = uVar4 | uVar9 << 0x10;
        data[1] = uVar2 | uVar10 << 0x10;
        return;
      }
      if (iVar8 != 2) {
        iVar7 = 5;
      }
      if (iVar8 == 2) {
        iVar7 = 6;
      }
      uVar1 = uVar10 - key->data[uVar1 & 0x3f];
      uVar2 = uVar2 - key->data[uVar3 & 0x3f] & 0xffff;
      uVar9 = uVar9 - key->data[uVar5 & 0x3f] & 0xffff;
      uVar10 = uVar1 & 0xffff;
      uVar4 = uVar4 - key->data[uVar1 & 0x3f] & 0xffff;
    }
    uVar1 = puVar6[9];
    puVar6 = puVar6 + -4;
  } while( true );
}

