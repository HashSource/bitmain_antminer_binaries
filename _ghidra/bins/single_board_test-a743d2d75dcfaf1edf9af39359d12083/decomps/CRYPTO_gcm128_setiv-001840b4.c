
void CRYPTO_gcm128_setiv(byte *param_1,byte *param_2,uint param_3)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  undefined4 uVar11;
  byte bVar12;
  undefined4 uVar13;
  byte bVar14;
  byte *pbVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  byte bVar19;
  byte bVar20;
  byte bVar21;
  byte bVar22;
  byte bVar23;
  byte bVar24;
  byte *local_38;
  uint local_34;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x16c] = 0;
  param_1[0x16d] = 0;
  param_1[0x16e] = 0;
  param_1[0x16f] = 0;
  param_1[0x168] = 0;
  param_1[0x169] = 0;
  param_1[0x16a] = 0;
  param_1[0x16b] = 0;
  if (param_3 == 0xc) {
    uVar11 = *(undefined4 *)(param_2 + 4);
    iVar10 = 2;
    uVar13 = *(undefined4 *)(param_2 + 8);
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    *(undefined4 *)(param_1 + 4) = uVar11;
    *(undefined4 *)(param_1 + 8) = uVar13;
    param_1[0xf] = 1;
    goto LAB_001842da;
  }
  if (param_3 < 0x10) {
    local_34 = param_3;
    if (param_3 != 0) goto LAB_00184208;
  }
  else {
    bVar14 = 0;
    bVar9 = 0;
    bVar21 = 0;
    bVar8 = 0;
    bVar20 = 0;
    bVar7 = 0;
    bVar19 = 0;
    bVar6 = 0;
    bVar23 = 0;
    bVar5 = 0;
    bVar24 = 0;
    bVar4 = 0;
    bVar22 = 0;
    bVar3 = 0;
    bVar12 = 0;
    bVar2 = 0;
    pbVar15 = param_2;
    uVar17 = param_3;
    while( true ) {
      uVar17 = uVar17 - 0x10;
      *param_1 = bVar12 ^ *pbVar15;
      param_1[1] = bVar22 ^ pbVar15[1];
      param_1[2] = bVar24 ^ pbVar15[2];
      param_1[3] = bVar23 ^ pbVar15[3];
      param_1[4] = bVar19 ^ pbVar15[4];
      param_1[5] = bVar20 ^ pbVar15[5];
      param_1[6] = pbVar15[6] ^ bVar2;
      param_1[7] = bVar21 ^ pbVar15[7];
      param_1[8] = pbVar15[8] ^ bVar3;
      param_1[9] = pbVar15[9] ^ bVar4;
      param_1[10] = pbVar15[10] ^ bVar5;
      param_1[0xb] = pbVar15[0xb] ^ bVar6;
      param_1[0xc] = pbVar15[0xc] ^ bVar7;
      param_1[0xd] = pbVar15[0xd] ^ bVar8;
      param_1[0xe] = pbVar15[0xe] ^ bVar9;
      pbVar1 = pbVar15 + 0xf;
      pbVar15 = pbVar15 + 0x10;
      param_1[0xf] = bVar14 ^ *pbVar1;
      gcm_gmult_4bit(param_1,param_1 + 0x60);
      if (uVar17 < 0x10) break;
      bVar2 = param_1[6];
      bVar3 = param_1[8];
      bVar12 = *param_1;
      bVar4 = param_1[9];
      bVar5 = param_1[10];
      bVar6 = param_1[0xb];
      bVar7 = param_1[0xc];
      bVar8 = param_1[0xd];
      bVar22 = param_1[1];
      bVar24 = param_1[2];
      bVar23 = param_1[3];
      bVar19 = param_1[4];
      bVar20 = param_1[5];
      bVar21 = param_1[7];
      bVar14 = param_1[0xf];
      bVar9 = param_1[0xe];
    }
    local_34 = param_3 & 0xf;
    param_2 = param_2 + (param_3 - 0x10 & 0xfffffff0) + 0x10;
    if (local_34 != 0) {
LAB_00184208:
      local_38 = param_1 + 0x60;
      uVar18 = local_34 >> 2;
      uVar17 = uVar18 * 4;
      if (uVar18 == 0 ||
          (local_34 < 4 ||
          (((uint)param_2 & 3) != 0 || param_2 < param_1 + 4 && param_1 < param_2 + 4))) {
        uVar17 = 0;
LAB_00184264:
        do {
          param_1[uVar17] = param_1[uVar17] ^ param_2[uVar17];
          uVar17 = uVar17 + 1;
        } while (uVar17 < local_34);
      }
      else {
        iVar10 = 0;
        uVar16 = 0;
        do {
          uVar16 = uVar16 + 1;
          *(uint *)(param_1 + iVar10) = *(uint *)(param_2 + iVar10) ^ *(uint *)(param_1 + iVar10);
          iVar10 = iVar10 + 4;
        } while (uVar16 < uVar18);
        if (local_34 != uVar17) goto LAB_00184264;
      }
      gcm_gmult_4bit(param_1,local_38);
    }
  }
  local_38 = param_1 + 0x60;
  iVar10 = param_3 << 3;
  param_1[0xc] = (byte)((uint)iVar10 >> 0x18) ^ param_1[0xc];
  param_1[0xd] = (byte)((uint)iVar10 >> 0x10) ^ param_1[0xd];
  param_1[0xb] = (byte)(param_3 >> 0x1d) ^ param_1[0xb];
  param_1[0xf] = (byte)iVar10 ^ param_1[0xf];
  param_1[0xe] = param_1[0xe] ^ (byte)((uint)iVar10 >> 8);
  gcm_gmult_4bit(param_1,local_38);
  iVar10 = ((uint)param_1[0xf] | (uint)param_1[0xd] << 0x10 | (uint)param_1[0xc] << 0x18 |
           (uint)param_1[0xe] << 8) + 1;
LAB_001842da:
  (**(code **)(param_1 + 0x170))(param_1,param_1 + 0x20,*(undefined4 *)(param_1 + 0x174));
  param_1[0xf] = (byte)iVar10;
  param_1[0xc] = (byte)((uint)iVar10 >> 0x18);
  param_1[0xd] = (byte)((uint)iVar10 >> 0x10);
  param_1[0xe] = (byte)((uint)iVar10 >> 8);
  return;
}

