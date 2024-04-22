
void RC2_decrypt(ulong *data,RC2_KEY *key)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  int local_28;
  
  puVar9 = key->data + 0x3f;
  puVar10 = key->data + 0x33;
  iVar11 = 5;
  uVar7 = data[1] & 0xffff;
  local_28 = 3;
  uVar6 = data[1] >> 0x10;
  uVar3 = *data & 0xffff;
  uVar8 = *data >> 0x10;
  do {
    puVar1 = puVar9 + -2;
    uVar6 = ((((uVar6 & 0x1f) << 0xb | uVar6 >> 5) - (uVar3 & ~uVar7)) - (uVar7 & uVar8)) -
            puVar10[0xc] & 0xffff;
    iVar11 = iVar11 + -1;
    puVar2 = puVar9 + -3;
    uVar5 = ((((uVar7 & 7) << 0xd | uVar7 >> 3) - (uVar6 & ~uVar8)) - (uVar8 & uVar3)) - puVar9[-1];
    HintPreloadData(puVar10);
    uVar7 = uVar5 & 0xffff;
    puVar9 = puVar9 + -4;
    uVar12 = ((((uVar8 & 3) << 0xe | uVar8 >> 2) - (uVar7 & ~uVar3)) - (uVar6 & uVar3)) - *puVar1;
    uVar8 = uVar12 & 0xffff;
    uVar4 = ((((uVar3 & 1) << 0xf | uVar3 >> 1) - (uVar8 & ~uVar6)) - (uVar7 & uVar6)) - *puVar2;
    uVar3 = uVar4 & 0xffff;
    if (iVar11 == 0) {
      local_28 = local_28 + -1;
      if (local_28 == 0) {
        *data = uVar3 | uVar8 << 0x10;
        data[1] = uVar7 | uVar6 << 0x10;
        return;
      }
      if (local_28 == 2) {
        iVar11 = 6;
      }
      else {
        iVar11 = 5;
      }
      uVar5 = uVar6 - key->data[uVar5 & 0x3f];
      uVar7 = uVar7 - key->data[uVar12 & 0x3f] & 0xffff;
      uVar8 = uVar8 - key->data[uVar4 & 0x3f] & 0xffff;
      uVar6 = uVar5 & 0xffff;
      uVar3 = uVar3 - key->data[uVar5 & 0x3f] & 0xffff;
    }
    puVar10 = puVar10 + -4;
  } while( true );
}

