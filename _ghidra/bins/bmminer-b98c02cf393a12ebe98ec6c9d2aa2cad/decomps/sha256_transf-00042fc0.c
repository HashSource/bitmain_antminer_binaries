
void sha256_transf(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  int local_164;
  undefined4 local_14c;
  uint local_148 [5];
  uint local_134;
  uint local_130;
  uint local_12c;
  uint local_128 [65];
  
  if (0 < param_3) {
    local_164 = 0;
    do {
      puVar9 = &local_12c;
      iVar7 = 0;
      iVar10 = param_2 + local_164 * 0x40;
      do {
        iVar4 = iVar10 + iVar7 * 4;
        iVar2 = iVar7 * 4;
        iVar7 = iVar7 + 1;
        puVar9 = puVar9 + 1;
        *puVar9 = (uint)*(byte *)(iVar4 + 3) | (uint)*(byte *)(iVar10 + iVar2) << 0x18 |
                  (uint)*(byte *)(iVar4 + 2) << 8 | (uint)*(byte *)(iVar4 + 1) << 0x10;
      } while (iVar7 != 0x10);
      puVar9 = local_128;
      do {
        uVar8 = puVar9[0xe];
        puVar1 = puVar9 + 1;
        uVar3 = *puVar1;
        puVar9[0x10] = ((uVar3 >> 0x12 | uVar3 << 0xe) ^ (uVar3 >> 7 | uVar3 << 0x19) ^ uVar3 >> 3)
                       + *puVar9 + puVar9[9] +
                         ((uVar8 >> 0x13 | uVar8 << 0xd) ^ (uVar8 >> 0x11 | uVar8 << 0xf) ^
                         uVar8 >> 10);
        puVar9 = puVar1;
      } while (local_128 + 0x30 != puVar1);
      puVar5 = &local_14c;
      puVar6 = (undefined4 *)(param_1 + 0x84);
      do {
        puVar6 = puVar6 + 1;
        puVar5 = puVar5 + 1;
        *puVar5 = *puVar6;
      } while ((undefined4 *)(param_1 + 0xa4) != puVar6);
      iVar7 = 0;
      do {
        uVar11 = local_148[2];
        uVar8 = local_134;
        uVar3 = local_130;
        local_148[2] = local_148[1];
        local_148[1] = local_148[0];
        local_134 = local_148[4];
        puVar9 = local_128 + iVar7;
        piVar12 = &sha256_k + iVar7;
        iVar7 = iVar7 + 1;
        iVar10 = local_12c +
                 (uVar3 & ~local_134 ^ local_134 & uVar8) +
                 ((local_134 >> 0xb | local_134 << 0x15) ^ (local_134 >> 6 | local_134 << 0x1a) ^
                 (local_134 >> 0x19 | local_134 << 7)) + *puVar9 + *piVar12;
        local_148[4] = iVar10 + local_148[3];
        local_148[0] = ((local_148[1] >> 0xd | local_148[1] << 0x13) ^
                        (local_148[1] >> 2 | local_148[1] << 0x1e) ^
                       (local_148[1] >> 0x16 | local_148[1] << 10)) +
                       ((uVar11 ^ local_148[2]) & local_148[1] ^ local_148[2] & uVar11) + iVar10;
        local_12c = uVar3;
        local_130 = uVar8;
        local_148[3] = uVar11;
      } while (iVar7 != 0x40);
      puVar9 = local_148;
      uVar3 = local_148[0];
      piVar12 = (int *)(param_1 + 0x88);
      while( true ) {
        *piVar12 = *piVar12 + uVar3;
        if (piVar12 + 1 == (int *)(param_1 + 0xa8)) break;
        puVar9 = puVar9 + 1;
        uVar3 = *puVar9;
        piVar12 = piVar12 + 1;
      }
      local_164 = local_164 + 1;
    } while (local_164 != param_3);
  }
  return;
}

