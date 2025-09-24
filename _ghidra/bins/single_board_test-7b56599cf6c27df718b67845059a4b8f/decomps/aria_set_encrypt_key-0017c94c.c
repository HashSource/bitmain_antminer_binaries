
undefined4 aria_set_encrypt_key(byte *param_1,uint param_2,uint *param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  bool bVar32;
  
  iVar9 = param_2 + 0x11f;
  if (-1 < (int)(param_2 + 0x100)) {
    iVar9 = param_2 + 0x100;
  }
  if (param_3 == (uint *)0x0 || param_1 == (byte *)0x0) {
    uVar6 = 0xffffffff;
  }
  else {
    bVar32 = (param_2 & 0xffffffbf) != 0x80;
    uVar5 = (uint)(bVar32 && param_2 != 0x100);
    if (bVar32 && param_2 != 0x100) {
      uVar6 = 0xfffffffe;
    }
    else {
      param_3[0x44] = iVar9 >> 5;
      iVar9 = param_2 - 0x41;
      if (-1 < (int)(param_2 - 0x80)) {
        iVar9 = param_2 - 0x80;
      }
      bVar2 = param_1[4];
      iVar9 = (iVar9 >> 6) * 0x10;
      uVar7 = (uint)param_1[5] << 0x10 | (uint)bVar2 << 0x18;
      bVar1 = *param_1;
      bVar3 = param_1[8];
      uVar14 = (uint)param_1[1] << 0x10 | (uint)bVar1 << 0x18;
      uVar17 = (uint)param_1[9] << 0x10 | (uint)bVar3 << 0x18;
      bVar4 = param_1[0xc];
      uVar21 = (uint)param_1[7];
      uVar29 = (uint)param_1[0xb];
      uVar24 = (uint)param_1[3];
      uVar12 = (uint)param_1[0xd] << 0x10 | (uint)bVar4 << 0x18;
      uVar8 = uVar7 ^ uVar21 | (uint)param_1[6] << 8;
      uVar23 = (uint)param_1[0xf];
      uVar18 = uVar17 ^ uVar29 | (uint)param_1[10] << 8;
      uVar10 = uVar14 ^ uVar24 | (uint)param_1[2] << 8;
      uVar15 = uVar12 ^ uVar23 | (uint)param_1[0xe] << 8;
      uVar16 = uVar8 ^ *(uint *)(Key_RC + iVar9 + 4);
      uVar13 = uVar18 ^ *(uint *)(Key_RC + iVar9 + 8);
      uVar11 = *(uint *)(Key_RC + iVar9) ^ uVar10;
      uVar19 = uVar15 ^ *(uint *)(Key_RC + iVar9 + 0xc);
      uVar13 = *(uint *)(&X1 + ((uVar13 << 0x10) >> 0x18) * 4) ^
               *(uint *)(S1 + (uVar13 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar13 & 0xff) * 4) ^
               *(uint *)(S2 + ((uVar13 << 8) >> 0x18) * 4);
      uVar30 = *(uint *)(&X1 + ((uVar16 << 0x10) >> 0x18) * 4) ^
               *(uint *)(S1 + (uVar16 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar16 & 0xff) * 4) ^
               *(uint *)(S2 + ((uVar16 << 8) >> 0x18) * 4) ^ uVar13;
      uVar27 = *(uint *)(&X1 + ((uVar11 << 0x10) >> 0x18) * 4) ^
               *(uint *)(S1 + (uVar11 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar11 & 0xff) * 4) ^
               *(uint *)(S2 + ((uVar11 << 8) >> 0x18) * 4) ^ uVar30;
      uVar11 = *(uint *)(S1 + (uVar19 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar19 & 0xff) * 4) ^
               *(uint *)(S2 + ((uVar19 << 8) >> 0x18) * 4) ^
               *(uint *)(&X1 + ((uVar19 << 0x10) >> 0x18) * 4);
      uVar16 = uVar11 ^ uVar30;
      uVar13 = uVar13 ^ uVar11 ^ uVar27;
      uVar11 = uVar13 >> 0x10 | uVar13 << 0x10;
      uVar20 = uVar16 >> 0x18 | uVar16 << 0x18 | (uVar16 & 0xff00) << 8 | (uVar16 & 0xff0000) >> 8;
      uVar19 = ((uVar30 ^ uVar13) & 0xff00ff) << 8 ^ (uVar30 ^ uVar13) >> 8 & 0xff00ff ^ uVar11;
      uVar27 = uVar27 ^ uVar19;
      uVar30 = uVar11 ^ uVar20 ^ uVar27;
      uVar11 = uVar5;
      uVar13 = uVar5;
      uVar16 = uVar5;
      if (0x80 < (int)param_2) {
        uVar11 = (uint)param_1[0x13] ^ ((uint)param_1[0x11] << 0x10 | (uint)param_1[0x10] << 0x18) |
                 (uint)param_1[0x12] << 8;
        uVar13 = ((uint)param_1[0x15] << 0x10 | (uint)param_1[0x14] << 0x18) ^ (uint)param_1[0x17] |
                 (uint)param_1[0x16] << 8;
        if (0xc0 < (int)param_2) {
          uVar5 = ((uint)param_1[0x1d] << 0x10 | (uint)param_1[0x1c] << 0x18) ^ (uint)param_1[0x1f]
                  | (uint)param_1[0x1e] << 8;
          uVar16 = ((uint)param_1[0x19] << 0x10 | (uint)param_1[0x18] << 0x18) ^ (uint)param_1[0x1b]
                   | (uint)param_1[0x1a] << 8;
        }
      }
      uVar16 = uVar30 ^ uVar16;
      uVar13 = uVar19 ^ uVar30 ^ uVar13;
      uVar27 = uVar27 ^ uVar11;
      uVar11 = uVar13 ^ *(uint *)(Key_RC + iVar9 + 0x14);
      uVar5 = uVar5 ^ uVar20 ^ uVar19;
      uVar19 = *(uint *)(Key_RC + iVar9 + 0x18) ^ uVar16;
      uVar20 = *(uint *)(Key_RC + iVar9 + 0x10) ^ uVar27;
      uVar30 = *(uint *)(Key_RC + iVar9 + 0x1c) ^ uVar5;
      uVar19 = *(uint *)(&X1 + (uVar19 >> 0x18) * 4) ^ *(uint *)(S2 + (uVar19 & 0xff) * 4) ^
               *(uint *)(X2 + ((uVar19 << 8) >> 0x18) * 4) ^
               *(uint *)(S1 + ((uVar19 << 0x10) >> 0x18) * 4);
      uVar25 = *(uint *)(S1 + ((uVar11 << 0x10) >> 0x18) * 4) ^
               *(uint *)(S2 + (uVar11 & 0xff) * 4) ^ *(uint *)(&X1 + (uVar11 >> 0x18) * 4) ^
               *(uint *)(X2 + ((uVar11 << 8) >> 0x18) * 4) ^ uVar19;
      uVar20 = *(uint *)(S1 + ((uVar20 << 0x10) >> 0x18) * 4) ^
               *(uint *)(&X1 + (uVar20 >> 0x18) * 4) ^ *(uint *)(S2 + (uVar20 & 0xff) * 4) ^
               *(uint *)(X2 + ((uVar20 << 8) >> 0x18) * 4) ^ uVar25;
      uVar11 = *(uint *)(S1 + ((uVar30 << 0x10) >> 0x18) * 4) ^
               *(uint *)(&X1 + (uVar30 >> 0x18) * 4) ^ *(uint *)(S2 + (uVar30 & 0xff) * 4) ^
               *(uint *)(X2 + ((uVar30 << 8) >> 0x18) * 4);
      uVar30 = uVar11 ^ uVar25;
      uVar19 = uVar19 ^ uVar11 ^ uVar20;
      uVar25 = uVar25 ^ uVar19;
      uVar25 = (uVar25 >> 0x18 | uVar25 << 0x18) ^ uVar19 ^ (uVar25 & 0xff00) << 8 ^
               (uVar25 & 0xff0000) >> 8;
      uVar11 = (uVar30 & 0xff00ff) << 8 ^ uVar30 >> 8 & 0xff00ff;
      uVar22 = uVar25 ^ (uVar20 >> 0x10 | uVar20 << 0x10);
      uVar28 = uVar25 ^ uVar11 ^ uVar15;
      uVar30 = uVar19 ^ uVar11 ^ uVar22;
      uVar22 = uVar10 ^ uVar22;
      uVar26 = uVar30 ^ uVar8 ^ uVar25;
      uVar30 = uVar18 ^ uVar30;
      uVar31 = uVar22 ^ *(uint *)(Key_RC + iVar9 + 0x20);
      uVar20 = uVar26 ^ *(uint *)(Key_RC + iVar9 + 0x24);
      uVar19 = *(uint *)(Key_RC + iVar9 + 0x28) ^ uVar30;
      uVar11 = *(uint *)(Key_RC + iVar9 + 0x2c) ^ uVar28;
      uVar25 = *(uint *)(&X1 + ((uVar19 << 0x10) >> 0x18) * 4) ^
               *(uint *)(S1 + (uVar19 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar19 & 0xff) * 4) ^
               *(uint *)(S2 + ((uVar19 << 8) >> 0x18) * 4);
      uVar20 = *(uint *)(X2 + (uVar20 & 0xff) * 4) ^ *(uint *)(S1 + (uVar20 >> 0x18) * 4) ^
               *(uint *)(S2 + ((uVar20 << 8) >> 0x18) * 4) ^
               *(uint *)(&X1 + ((uVar20 << 0x10) >> 0x18) * 4) ^ uVar25;
      uVar19 = *(uint *)(&X1 + ((uVar31 << 0x10) >> 0x18) * 4) ^
               *(uint *)(S1 + (uVar31 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar31 & 0xff) * 4) ^
               *(uint *)(S2 + ((uVar31 << 8) >> 0x18) * 4) ^ uVar20;
      uVar11 = *(uint *)(&X1 + ((uVar11 << 0x10) >> 0x18) * 4) ^
               *(uint *)(S1 + (uVar11 >> 0x18) * 4) ^ *(uint *)(X2 + (uVar11 & 0xff) * 4) ^
               *(uint *)(S2 + ((uVar11 << 8) >> 0x18) * 4);
      uVar31 = uVar11 ^ uVar20;
      uVar25 = uVar25 ^ uVar11 ^ uVar19;
      uVar11 = uVar25 >> 0x10 | uVar25 << 0x10;
      uVar31 = uVar31 >> 0x18 | uVar31 << 0x18 | (uVar31 & 0xff00) << 8 | (uVar31 & 0xff0000) >> 8;
      uVar20 = (uVar20 ^ uVar25) >> 8 & 0xff00ff ^ ((uVar20 ^ uVar25) & 0xff00ff) << 8 ^ uVar11;
      uVar19 = uVar19 ^ uVar20;
      uVar11 = uVar11 ^ uVar31 ^ uVar19;
      uVar25 = uVar13 ^ uVar20 ^ uVar11;
      uVar19 = uVar19 ^ uVar27;
      uVar20 = uVar5 ^ uVar31 ^ uVar20;
      uVar11 = uVar11 ^ uVar16;
      param_3[10] = (uVar25 << 0xd | uVar11 >> 0x13) ^ uVar30;
      param_3[0x1a] = (uVar25 << 1 | uVar11 >> 0x1f) ^ uVar30;
      param_3[0xd] = (uVar10 << 0xd | uVar7 >> 0x13) ^ uVar25;
      param_3[9] = uVar26 ^ uVar19 << 0xd ^ uVar25 >> 0x13;
      param_3[0xe] = (uVar8 << 0xd | uVar17 >> 0x13) ^ uVar11;
      param_3[0xc] = (uVar15 << 0xd | uVar14 >> 0x13) ^ uVar19;
      param_3[0xf] = (uVar18 << 0xd | uVar12 >> 0x13) ^ uVar20;
      param_3[0xb] = uVar28 ^ uVar20 >> 0x13 ^ uVar11 << 0xd;
      param_3[8] = uVar22 ^ uVar20 << 0xd ^ uVar19 >> 0x13;
      *param_3 = (uVar5 << 0xd | uVar27 >> 0x13) ^ uVar10;
      param_3[1] = (uVar27 << 0xd | uVar13 >> 0x13) ^ uVar8;
      param_3[2] = (uVar13 << 0xd | uVar16 >> 0x13) ^ uVar18;
      param_3[3] = (uVar16 << 0xd | uVar5 >> 0x13) ^ uVar15;
      param_3[0x10] = (uVar5 << 1 | uVar27 >> 0x1f) ^ uVar10;
      param_3[5] = uVar13 ^ uVar22 << 0xd ^ uVar26 >> 0x13;
      param_3[0x18] = uVar22 ^ uVar20 << 1 ^ uVar19 >> 0x1f;
      param_3[7] = uVar5 ^ uVar28 >> 0x13 ^ uVar30 << 0xd;
      param_3[0x11] = (uVar27 << 1 | uVar13 >> 0x1f) ^ uVar8;
      param_3[0x12] = (uVar13 << 1 | uVar16 >> 0x1f) ^ uVar18;
      param_3[0x15] = uVar13 ^ uVar22 << 1 ^ uVar26 >> 0x1f;
      param_3[0x13] = (uVar16 << 1 | uVar5 >> 0x1f) ^ uVar15;
      param_3[0x17] = uVar5 ^ uVar28 >> 0x1f ^ uVar30 << 1;
      param_3[4] = uVar27 ^ uVar28 << 0xd ^ uVar22 >> 0x13;
      param_3[6] = (uVar26 << 0xd | uVar30 >> 0x13) ^ uVar16;
      param_3[0x16] = (uVar26 << 1 | uVar30 >> 0x1f) ^ uVar16;
      param_3[0x28] = (uVar25 << 0x1d | uVar11 >> 3) ^ uVar22;
      param_3[0x14] = uVar27 ^ uVar28 << 1 ^ uVar22 >> 0x1f;
      param_3[0x1d] = (uVar10 << 1 | ((uint)bVar2 << 0x18) >> 0x1f) ^ uVar25;
      param_3[0x1e] = (uVar8 << 1 | ((uint)bVar3 << 0x18) >> 0x1f) ^ uVar11;
      param_3[0x2d] = (uVar29 << 0x1d | uVar15 >> 3) ^ uVar25;
      param_3[0x2e] = (uVar23 << 0x1d | uVar10 >> 3) ^ uVar11;
      param_3[0x19] = uVar26 ^ uVar19 << 1 ^ uVar25 >> 0x1f;
      param_3[0x1b] = uVar28 ^ uVar20 >> 0x1f ^ uVar11 << 1;
      param_3[0x1c] = (uVar15 << 1 | ((uint)bVar1 << 0x18) >> 0x1f) ^ uVar19;
      param_3[0x2c] = (uVar21 << 0x1d | uVar18 >> 3) ^ uVar19;
      param_3[0x1f] = (uVar18 << 1 | ((uint)bVar4 << 0x18) >> 0x1f) ^ uVar20;
      param_3[0x2f] = (uVar24 << 0x1d | uVar8 >> 3) ^ uVar20;
      param_3[0x24] = (uVar26 << 0x1d | uVar30 >> 3) ^ uVar27;
      param_3[0x20] = (uVar13 << 0x1d | uVar16 >> 3) ^ uVar10;
      param_3[0x29] = uVar26 ^ uVar20 >> 3 ^ uVar11 << 0x1d;
      param_3[0x2b] = uVar28 ^ uVar19 << 0x1d ^ uVar25 >> 3;
      param_3[0x2a] = uVar30 ^ uVar20 << 0x1d ^ uVar19 >> 3;
      param_3[0x25] = uVar13 ^ uVar28 >> 3 ^ uVar30 << 0x1d;
      param_3[0x22] = (uVar5 << 0x1d | uVar27 >> 3) ^ uVar18;
      param_3[0x23] = (uVar27 << 0x1d | uVar13 >> 3) ^ uVar15;
      param_3[0x21] = (uVar16 << 0x1d | uVar5 >> 3) ^ uVar8;
      param_3[0x30] = (uVar27 << 0x1f | uVar13 >> 1) ^ uVar10;
      param_3[0x31] = (uVar13 << 0x1f | uVar16 >> 1) ^ uVar8;
      param_3[0x27] = uVar5 ^ uVar22 << 0x1d ^ uVar26 >> 3;
      param_3[0x32] = (uVar16 << 0x1f | uVar5 >> 1) ^ uVar18;
      param_3[0x33] = (uVar5 << 0x1f | uVar27 >> 1) ^ uVar15;
      param_3[0x26] = uVar16 ^ uVar28 << 0x1d ^ uVar22 >> 3;
      if (0x80 < (int)param_2) {
        param_3[0x34] = uVar27 ^ uVar22 << 0x1f ^ uVar26 >> 1;
        param_3[0x36] = uVar16 ^ uVar28 >> 1 ^ uVar30 << 0x1f;
        param_3[0x39] = (uVar25 << 0x1f | uVar11 >> 1) ^ uVar26;
        param_3[0x37] = uVar5 ^ uVar28 << 0x1f ^ uVar22 >> 1;
        param_3[0x3a] = uVar30 ^ uVar20 >> 1 ^ uVar11 << 0x1f;
        param_3[0x3b] = uVar28 ^ uVar20 << 0x1f ^ uVar19 >> 1;
        param_3[0x35] = (uVar26 << 0x1f | uVar30 >> 1) ^ uVar13;
        param_3[0x38] = uVar22 ^ uVar19 << 0x1f ^ uVar25 >> 1;
        if (0xc0 < (int)param_2) {
          param_3[0x3e] = uVar11 ^ (uVar29 << 0x1f | uVar15 >> 1);
          param_3[0x40] = (uVar27 << 0x13 | uVar13 >> 0xd) ^ uVar10;
          param_3[0x3c] = uVar19 ^ (uVar24 << 0x1f | uVar8 >> 1);
          param_3[0x3d] = (uVar21 << 0x1f | uVar18 >> 1) ^ uVar25;
          param_3[0x3f] = (uVar23 << 0x1f | uVar10 >> 1) ^ uVar20;
          param_3[0x41] = (uVar13 << 0x13 | uVar16 >> 0xd) ^ uVar8;
          param_3[0x42] = (uVar16 << 0x13 | uVar5 >> 0xd) ^ uVar18;
          param_3[0x43] = (uVar5 << 0x13 | uVar27 >> 0xd) ^ uVar15;
          return 0;
        }
      }
      uVar6 = 0;
    }
  }
  return uVar6;
}

