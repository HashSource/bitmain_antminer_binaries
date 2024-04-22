
void Sha256_Transform(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint auStack_80 [8];
  uint auStack_60 [16];
  uint local_20;
  uint local_1c;
  
  for (local_1c = 0; local_1c < 8; local_1c = local_1c + 1) {
    auStack_80[local_1c] = *(uint *)(param_1 + local_1c * 4);
  }
  for (local_1c = 0; local_1c < 0x40; local_1c = local_1c + 0x10) {
    for (local_20 = 0; local_20 < 0x10; local_20 = local_20 + 1) {
      uVar3 = 7 - local_20;
      uVar1 = auStack_80[7 - local_20 & 7];
      uVar4 = auStack_80[4 - local_20 & 7];
      uVar5 = auStack_80[4 - local_20 & 7];
      uVar6 = auStack_80[4 - local_20 & 7];
      uVar9 = auStack_80[6 - local_20 & 7];
      uVar10 = auStack_80[4 - local_20 & 7];
      uVar11 = auStack_80[5 - local_20 & 7];
      uVar7 = auStack_80[6 - local_20 & 7];
      iVar8 = *(int *)(&K + (local_20 + local_1c) * 4);
      if (local_1c == 0) {
        auStack_60[local_20] = *(uint *)(param_2 + local_20 * 4);
        uVar2 = auStack_60[local_20];
      }
      else {
        uVar2 = local_20 & 0xf;
        auStack_60[uVar2] =
             auStack_60[local_20 & 0xf] +
             ((auStack_60[local_20 - 2 & 0xf] >> 0x11 | auStack_60[local_20 - 2 & 0xf] << 0xf) ^
              (auStack_60[local_20 - 2 & 0xf] >> 0x13 | auStack_60[local_20 - 2 & 0xf] << 0xd) ^
             auStack_60[local_20 - 2 & 0xf] >> 10) + auStack_60[local_20 - 7 & 0xf] +
             ((auStack_60[local_20 - 0xf & 0xf] >> 7 | auStack_60[local_20 - 0xf & 0xf] << 0x19) ^
              (auStack_60[local_20 - 0xf & 0xf] >> 0x12 | auStack_60[local_20 - 0xf & 0xf] << 0xe) ^
             auStack_60[local_20 - 0xf & 0xf] >> 3);
        uVar2 = auStack_60[uVar2];
      }
      auStack_80[uVar3 & 7] =
           uVar1 + ((uVar4 >> 6 | uVar4 << 0x1a) ^ (uVar5 >> 0xb | uVar5 << 0x15) ^
                   (uVar6 >> 0x19 | uVar6 << 7)) + ((uVar7 ^ uVar11) & uVar10 ^ uVar9) + iVar8 +
                   uVar2;
      auStack_80[3 - local_20 & 7] = auStack_80[3 - local_20 & 7] + auStack_80[7 - local_20 & 7];
      auStack_80[7 - local_20 & 7] =
           auStack_80[7 - local_20 & 7] +
           ((auStack_80[-local_20 & 7] >> 2 | auStack_80[-local_20 & 7] << 0x1e) ^
            (auStack_80[-local_20 & 7] >> 0xd | auStack_80[-local_20 & 7] << 0x13) ^
           (auStack_80[-local_20 & 7] >> 0x16 | auStack_80[-local_20 & 7] << 10)) +
           ((auStack_80[1 - local_20 & 7] | auStack_80[-local_20 & 7]) &
            auStack_80[2 - local_20 & 7] | auStack_80[-local_20 & 7] & auStack_80[1 - local_20 & 7])
      ;
    }
  }
  for (local_1c = 0; local_1c < 8; local_1c = local_1c + 1) {
    *(uint *)(param_1 + local_1c * 4) = *(int *)(param_1 + local_1c * 4) + auStack_80[local_1c];
  }
  return;
}

