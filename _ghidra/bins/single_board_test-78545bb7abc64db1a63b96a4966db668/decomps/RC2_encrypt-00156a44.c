
void RC2_encrypt(ulong *data,RC2_KEY *key)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  
  iVar9 = 3;
  iVar12 = 5;
  puVar13 = key->data + 0xd;
  uVar8 = key->data[0];
  uVar10 = *data & 0xffff;
  uVar5 = *data >> 0x10;
  uVar1 = data[1] & 0xffff;
  uVar3 = data[1] >> 0x10;
  do {
    iVar12 = iVar12 + -1;
    uVar8 = (uVar1 & uVar3) + (uVar5 & ~uVar3) + uVar10 + uVar8 & 0xffff;
    HintPreloadData(puVar13);
    uVar11 = uVar8 >> 0xf;
    uVar8 = uVar8 << 1;
    uVar10 = uVar11 | uVar8;
    uVar5 = (uVar1 & ~uVar10) + puVar13[-0xc] + uVar5 + (uVar3 & uVar10) & 0xffff;
    uVar5 = uVar5 >> 0xe | uVar5 << 2;
    uVar7 = puVar13[-0xb] + uVar1 + (uVar10 & uVar5) + (uVar3 & ~uVar5) & 0xffff;
    uVar2 = uVar7 >> 0xd;
    uVar7 = uVar7 << 3;
    uVar1 = uVar2 | uVar7;
    uVar4 = (uVar10 & ~uVar1) + uVar3 + puVar13[-10] + (uVar5 & uVar1) & 0xffff;
    uVar6 = uVar4 >> 0xb;
    uVar4 = uVar4 << 5;
    uVar3 = uVar6 | uVar4;
    if (iVar12 == 0) {
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) {
        *data = uVar11 | uVar8 & 0xffff | uVar5 << 0x10;
        data[1] = uVar2 | uVar7 & 0xffff | uVar3 << 0x10;
        return;
      }
      if (iVar9 == 2) {
        iVar12 = 6;
      }
      else {
        iVar12 = 5;
      }
      uVar10 = uVar10 + key->data[uVar6 | uVar4 & 0x3f];
      uVar5 = uVar5 + key->data[uVar10 & 0x3f];
      uVar1 = uVar1 + key->data[uVar5 & 0x3f];
      uVar3 = uVar3 + key->data[uVar1 & 0x3f];
    }
    uVar8 = puVar13[-9];
    puVar13 = puVar13 + 4;
  } while( true );
}

