
void RC2_encrypt(ulong *data,RC2_KEY *key)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  uint *puVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  
  iVar17 = 5;
  puVar13 = key->data + 0x10;
  uVar10 = *data & 0xffff;
  uVar8 = data[1] & 0xffff;
  iVar14 = 3;
  uVar4 = *data >> 0x10;
  uVar5 = data[1] >> 0x10;
  puVar12 = key->data;
  do {
    iVar17 = iVar17 + -1;
    HintPreloadData(puVar13);
    puVar2 = puVar12 + 1;
    puVar1 = puVar12 + 3;
    uVar11 = uVar10 + (uVar4 & ~uVar5) + ((RC2_KEY *)(puVar13 + -0x10))->data[0] + (uVar5 & uVar8) &
             0xffff;
    puVar3 = puVar12 + 2;
    uVar16 = uVar11 << 1;
    puVar12 = puVar12 + 4;
    uVar11 = uVar11 >> 0xf;
    uVar10 = uVar16 | uVar11;
    uVar4 = uVar4 + *puVar2 + (uVar10 & uVar5) + (uVar8 & ~uVar10) & 0xffff;
    uVar4 = uVar4 << 2 | uVar4 >> 0xe;
    uVar6 = (uVar5 & ~uVar4) + uVar8 + *puVar3 + (uVar4 & uVar10) & 0xffff;
    uVar9 = uVar6 << 3;
    uVar6 = uVar6 >> 0xd;
    uVar8 = uVar9 | uVar6;
    uVar7 = (uVar8 & uVar4) + *puVar1 + uVar5 + (uVar10 & ~uVar8) & 0xffff;
    uVar15 = uVar7 << 5;
    uVar7 = uVar7 >> 0xb;
    uVar5 = uVar15 | uVar7;
    if (iVar17 == 0) {
      iVar14 = iVar14 + -1;
      if (iVar14 == 0) {
        *data = uVar16 & 0xffff | uVar11 | uVar4 << 0x10;
        data[1] = uVar9 & 0xffff | uVar6 | uVar5 << 0x10;
        return;
      }
      if (iVar14 == 2) {
        iVar17 = 6;
      }
      else {
        iVar17 = 5;
      }
      uVar10 = uVar10 + key->data[uVar15 & 0x3f | uVar7];
      uVar4 = uVar4 + key->data[uVar10 & 0x3f];
      uVar8 = uVar8 + key->data[uVar4 & 0x3f];
      uVar5 = uVar5 + key->data[uVar8 & 0x3f];
    }
    puVar13 = puVar13 + 4;
  } while( true );
}

