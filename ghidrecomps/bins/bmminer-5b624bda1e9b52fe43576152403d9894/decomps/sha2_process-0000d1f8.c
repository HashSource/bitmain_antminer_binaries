
/* WARNING: Unknown calling convention */

void sha2_process(sha2_context *ctx,uchar *data)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint G;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint F;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint E;
  uint uVar14;
  uint H;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint A;
  uint temp1;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint B;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint C;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  uint uVar46;
  uint uVar47;
  uint uVar48;
  uint uVar49;
  uint uVar50;
  uint D;
  
  uVar1 = ctx->state[4];
  uVar8 = ctx->state[0];
  uVar23 = ctx->state[5];
  uVar15 = ctx->state[6];
  uVar2 = ctx->state[7];
  uVar24 = ctx->state[2];
  uVar3 = ctx->state[1];
  uVar32 = (uint)data[1] << 0x10 | (uint)*data << 0x18 | (uint)data[3] | (uint)data[2] << 8;
  uVar4 = (uint)data[5] << 0x10 | (uint)data[4] << 0x18;
  iVar11 = uVar2 + 0x428a2f98 +
           ((uVar1 >> 6 | uVar1 << 0x1a) ^ (uVar1 >> 0xb | uVar1 << 0x15) ^
           (uVar1 >> 0x19 | uVar1 << 7)) + ((uVar15 ^ uVar23) & uVar1 ^ uVar15) + uVar32;
  uVar14 = ((uVar3 | uVar8) & uVar24 | uVar8 & uVar3) +
           ((uVar8 >> 2 | uVar8 << 0x1e) ^ (uVar8 >> 0xd | uVar8 << 0x13) ^
           (uVar8 >> 0x16 | uVar8 << 10)) + iVar11;
  uVar16 = uVar4 | data[7] | (uint)data[6] << 8;
  uVar33 = iVar11 + ctx->state[3];
  iVar11 = (uVar33 & (uVar23 ^ uVar1) ^ uVar23) + uVar15 + 0x71374491 + uVar16 +
           ((uVar33 >> 6 | uVar33 * 0x4000000) ^ (uVar33 >> 0xb | uVar33 * 0x200000) ^
           (uVar33 >> 0x19 | uVar33 * 0x80));
  uVar17 = (uint)data[9] << 0x10 | (uint)data[8] << 0x18;
  uVar5 = iVar11 + uVar24;
  uVar43 = ((uVar14 | uVar8) & uVar3 | uVar14 & uVar8) +
           ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^
           (uVar14 >> 0x16 | uVar14 * 0x400)) + iVar11;
  uVar9 = data[0xb] | uVar17 | (uint)data[10] << 8;
  uVar12 = (uint)data[0xd] << 0x10 | (uint)data[0xc] << 0x18;
  iVar11 = ((uVar33 ^ uVar1) & uVar5 ^ uVar1) + uVar23 + 0xb5c0fbcf + uVar9 +
           ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
           (uVar5 >> 0x19 | uVar5 * 0x80));
  uVar44 = ((uVar43 | uVar14) & uVar8 | uVar43 & uVar14) +
           ((uVar43 >> 2 | uVar43 * 0x40000000) ^ (uVar43 >> 0xd | uVar43 * 0x80000) ^
           (uVar43 >> 0x16 | uVar43 * 0x400)) + iVar11;
  uVar10 = iVar11 + uVar3;
  uVar6 = data[0xf] | uVar12 | (uint)data[0xe] << 8;
  uVar45 = (uint)data[0x11] << 0x10 | (uint)data[0x10] << 0x18;
  iVar11 = uVar1 + 0xe9b5dba5 + uVar6 + ((uVar5 ^ uVar33) & uVar10 ^ uVar33) +
           ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
           (uVar10 >> 0x19 | uVar10 * 0x80));
  uVar7 = uVar45 | data[0x13] | (uint)data[0x12] << 8;
  uVar13 = ((uVar44 | uVar43) & uVar14 | uVar44 & uVar43) +
           ((uVar44 >> 2 | uVar44 * 0x40000000) ^ (uVar44 >> 0xd | uVar44 * 0x80000) ^
           (uVar44 >> 0x16 | uVar44 * 0x400)) + iVar11;
  uVar18 = iVar11 + uVar8;
  iVar11 = ((uVar18 >> 6 | uVar18 * 0x4000000) ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^
           (uVar18 >> 0x19 | uVar18 * 0x80)) +
           uVar7 + 0x3956c25b + uVar33 + (uVar18 & (uVar10 ^ uVar5) ^ uVar5);
  uVar34 = ((uVar44 | uVar13) & uVar43 | uVar13 & uVar44) +
           ((uVar13 >> 2 | uVar13 * 0x40000000) ^ (uVar13 >> 0xd | uVar13 * 0x80000) ^
           (uVar13 >> 0x16 | uVar13 * 0x400)) + iVar11;
  uVar14 = uVar14 + iVar11;
  uVar20 = (uint)data[0x15] << 0x10 | (uint)data[0x14] << 0x18;
  uVar33 = uVar20 | data[0x17] | (uint)data[0x16] << 8;
  uVar21 = (uint)data[0x19] << 0x10 | (uint)data[0x18] << 0x18;
  iVar11 = ((uVar14 >> 6 | uVar14 * 0x4000000) ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^
           (uVar14 >> 0x19 | uVar14 * 0x80)) +
           uVar33 + 0x59f111f1 + uVar5 + (uVar14 & (uVar18 ^ uVar10) ^ uVar10);
  uVar43 = iVar11 + uVar43;
  uVar35 = ((uVar34 | uVar13) & uVar44 | uVar34 & uVar13) +
           ((uVar34 >> 2 | uVar34 * 0x40000000) ^ (uVar34 >> 0xd | uVar34 * 0x80000) ^
           (uVar34 >> 0x16 | uVar34 * 0x400)) + iVar11;
  uVar25 = uVar21 | data[0x1b] | (uint)data[0x1a] << 8;
  iVar11 = uVar25 + 0x923f82a4 + uVar10 + (uVar43 & (uVar14 ^ uVar18) ^ uVar18) +
           ((uVar43 >> 6 | uVar43 * 0x4000000) ^ (uVar43 >> 0xb | uVar43 * 0x200000) ^
           (uVar43 >> 0x19 | uVar43 * 0x80));
  uVar10 = ((uVar35 >> 2 | uVar35 * 0x40000000) ^ (uVar35 >> 0xd | uVar35 * 0x80000) ^
           (uVar35 >> 0x16 | uVar35 * 0x400)) + ((uVar35 | uVar34) & uVar13 | uVar34 & uVar35) +
           iVar11;
  uVar46 = (uint)data[0x1d] << 0x10 | (uint)data[0x1c] << 0x18;
  uVar44 = iVar11 + uVar44;
  uVar26 = uVar46 | data[0x1f] | (uint)data[0x1e] << 8;
  iVar11 = uVar26 + 0xab1c5ed5 + uVar18 + (uVar44 & (uVar43 ^ uVar14) ^ uVar14) +
           ((uVar44 >> 6 | uVar44 * 0x4000000) ^ (uVar44 >> 0xb | uVar44 * 0x200000) ^
           (uVar44 >> 0x19 | uVar44 * 0x80));
  uVar36 = ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
           (uVar10 >> 0x16 | uVar10 * 0x400)) + ((uVar10 | uVar35) & uVar34 | uVar10 & uVar35) +
           iVar11;
  uVar13 = iVar11 + uVar13;
  uVar27 = (uint)data[0x21] << 0x10 | (uint)data[0x20] << 0x18;
  uVar22 = uVar27 | data[0x23] | (uint)data[0x22] << 8;
  iVar11 = uVar22 + 0xd807aa98 + uVar14 + (uVar13 & (uVar44 ^ uVar43) ^ uVar43) +
           ((uVar13 >> 6 | uVar13 * 0x4000000) ^ (uVar13 >> 0xb | uVar13 * 0x200000) ^
           (uVar13 >> 0x19 | uVar13 * 0x80));
  uVar47 = (uint)data[0x25] << 0x10 | (uint)data[0x24] << 0x18;
  uVar18 = ((uVar36 >> 2 | uVar36 * 0x40000000) ^ (uVar36 >> 0xd | uVar36 * 0x80000) ^
           (uVar36 >> 0x16 | uVar36 * 0x400)) + ((uVar36 | uVar10) & uVar35 | uVar36 & uVar10) +
           iVar11;
  uVar37 = uVar47 | data[0x27] | (uint)data[0x26] << 8;
  uVar34 = iVar11 + uVar34;
  iVar11 = uVar37 + 0x12835b01 + uVar43 + (uVar34 & (uVar13 ^ uVar44) ^ uVar44) +
           ((uVar34 >> 6 | uVar34 * 0x4000000) ^ (uVar34 >> 0xb | uVar34 * 0x200000) ^
           (uVar34 >> 0x19 | uVar34 * 0x80));
  uVar19 = (uint)data[0x29] << 0x10 | (uint)data[0x28] << 0x18;
  uVar43 = ((uVar18 >> 2 | uVar18 * 0x40000000) ^ (uVar18 >> 0xd | uVar18 * 0x80000) ^
           (uVar18 >> 0x16 | uVar18 * 0x400)) + ((uVar18 | uVar36) & uVar10 | uVar18 & uVar36) +
           iVar11;
  uVar38 = uVar19 | data[0x2b] | (uint)data[0x2a] << 8;
  uVar35 = iVar11 + uVar35;
  uVar14 = (uint)data[0x2d] << 0x10 | (uint)data[0x2c] << 0x18;
  iVar11 = uVar38 + 0x243185be + uVar44 + (uVar35 & (uVar34 ^ uVar13) ^ uVar13) +
           ((uVar35 >> 6 | uVar35 * 0x4000000) ^ (uVar35 >> 0xb | uVar35 * 0x200000) ^
           (uVar35 >> 0x19 | uVar35 * 0x80));
  uVar29 = uVar14 | data[0x2f] | (uint)data[0x2e] << 8;
  uVar10 = iVar11 + uVar10;
  uVar44 = iVar11 + ((uVar43 | uVar18) & uVar36 | uVar43 & uVar18) +
                    ((uVar43 >> 2 | uVar43 * 0x40000000) ^ (uVar43 >> 0xd | uVar43 * 0x80000) ^
                    (uVar43 >> 0x16 | uVar43 * 0x400));
  uVar48 = (uint)data[0x31] << 0x10 | (uint)data[0x30] << 0x18;
  iVar11 = uVar13 + uVar29 + 0x550c7dc3 + (uVar10 & (uVar35 ^ uVar34) ^ uVar34) +
           ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
           (uVar10 >> 0x19 | uVar10 * 0x80));
  uVar36 = iVar11 + uVar36;
  uVar28 = uVar48 | data[0x33] | (uint)data[0x32] << 8;
  uVar13 = ((uVar44 >> 2 | uVar44 * 0x40000000) ^ (uVar44 >> 0xd | uVar44 * 0x80000) ^
           (uVar44 >> 0x16 | uVar44 * 0x400)) + ((uVar44 | uVar43) & uVar18 | uVar44 & uVar43) +
           iVar11;
  iVar11 = ((uVar36 >> 6 | uVar36 * 0x4000000) ^ (uVar36 >> 0xb | uVar36 * 0x200000) ^
           (uVar36 >> 0x19 | uVar36 * 0x80)) +
           uVar28 + 0x72be5d74 + uVar34 + ((uVar10 ^ uVar35) & uVar36 ^ uVar35);
  uVar49 = ((uVar13 >> 2 | uVar13 * 0x40000000) ^ (uVar13 >> 0xd | uVar13 * 0x80000) ^
           (uVar13 >> 0x16 | uVar13 * 0x400)) + ((uVar13 | uVar44) & uVar43 | uVar13 & uVar44) +
           iVar11;
  uVar30 = (uint)data[0x35] << 0x10 | (uint)data[0x34] << 0x18;
  uVar5 = uVar30 | data[0x37] | (uint)data[0x36] << 8;
  uVar18 = iVar11 + uVar18;
  iVar11 = ((uVar18 >> 6 | uVar18 * 0x4000000) ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^
           (uVar18 >> 0x19 | uVar18 * 0x80)) +
           ((uVar36 ^ uVar10) & uVar18 ^ uVar10) + uVar35 + uVar5 + 0x80deb1fe;
  uVar35 = (uint)data[0x39] << 0x10 | (uint)data[0x38] << 0x18;
  uVar39 = ((uVar49 >> 2 | uVar49 * 0x40000000) ^ (uVar49 >> 0xd | uVar49 * 0x80000) ^
           (uVar49 >> 0x16 | uVar49 * 0x400)) + ((uVar49 | uVar13) & uVar44 | uVar49 & uVar13) +
           iVar11;
  uVar43 = iVar11 + uVar43;
  uVar40 = uVar35 | data[0x3b] | (uint)data[0x3a] << 8;
  uVar41 = (uint)data[0x3d] << 0x10 | (uint)data[0x3c] << 0x18;
  iVar11 = ((uVar43 >> 6 | uVar43 * 0x4000000) ^ (uVar43 >> 0xb | uVar43 * 0x200000) ^
           (uVar43 >> 0x19 | uVar43 * 0x80)) +
           uVar10 + uVar40 + 0x9bdc06a7 + (uVar43 & (uVar18 ^ uVar36) ^ uVar36);
  uVar44 = uVar44 + iVar11;
  uVar34 = ((uVar39 | uVar49) & uVar13 | uVar39 & uVar49) +
           ((uVar39 >> 2 | uVar39 * 0x40000000) ^ (uVar39 >> 0xd | uVar39 * 0x80000) ^
           (uVar39 >> 0x16 | uVar39 * 0x400)) + iVar11;
  uVar10 = uVar41 | data[0x3f] | (uint)data[0x3e] << 8;
  A = uVar43 ^ uVar18;
  iVar11 = (A & uVar44 ^ uVar18) + uVar10 + 0xc19bf174 + uVar36 +
           ((uVar44 >> 6 | uVar44 * 0x4000000) ^ (uVar44 >> 0xb | uVar44 * 0x200000) ^
           (uVar44 >> 0x19 | uVar44 * 0x80));
  uVar13 = iVar11 + uVar13;
  uVar36 = ((uVar34 | uVar39) & uVar49 | uVar34 & uVar39) +
           ((uVar34 >> 2 | uVar34 * 0x40000000) ^ (uVar34 >> 0xd | uVar34 * 0x80000) ^
           (uVar34 >> 0x16 | uVar34 * 0x400)) + iVar11;
  uVar32 = ((uVar16 >> 7 | (uint)data[7] << 0x19) ^ (uVar4 >> 0x12 | uVar16 << 0xe) ^ uVar16 >> 3) +
           ((uVar35 >> 0x11 | uVar40 << 0xf) ^ (uVar35 >> 0x13 | uVar40 << 0xd) ^ uVar40 >> 10) +
           uVar37 + uVar32;
  iVar11 = ((uVar44 ^ uVar43) & uVar13 ^ uVar43) + uVar32 + 0xe49b69c1 + uVar18 +
           ((uVar13 >> 6 | uVar13 * 0x4000000) ^ (uVar13 >> 0xb | uVar13 * 0x200000) ^
           (uVar13 >> 0x19 | uVar13 * 0x80));
  uVar42 = ((uVar36 | uVar34) & uVar39 | uVar36 & uVar34) +
           ((uVar36 >> 2 | uVar36 * 0x40000000) ^ (uVar36 >> 0xd | uVar36 * 0x80000) ^
           (uVar36 >> 0x16 | uVar36 * 0x400)) + iVar11;
  uVar49 = iVar11 + uVar49;
  uVar31 = ((uVar9 >> 7 | (uint)data[0xb] << 0x19) ^ (uVar17 >> 0x12 | uVar9 << 0xe) ^ uVar9 >> 3) +
           uVar38 + uVar16 +
           ((uVar41 >> 0x11 | uVar10 << 0xf) ^ (uVar41 >> 0x13 | uVar10 << 0xd) ^ uVar10 >> 10);
  iVar11 = uVar43 + uVar31 + 0xefbe4786 + (uVar49 & (uVar13 ^ uVar44) ^ uVar44) +
           ((uVar49 >> 6 | uVar49 * 0x4000000) ^ (uVar49 >> 0xb | uVar49 * 0x200000) ^
           (uVar49 >> 0x19 | uVar49 * 0x80));
  uVar43 = ((uVar42 | uVar36) & uVar34 | uVar42 & uVar36) +
           ((uVar42 >> 2 | uVar42 * 0x40000000) ^ (uVar42 >> 0xd | uVar42 * 0x80000) ^
           (uVar42 >> 0x16 | uVar42 * 0x400)) + iVar11;
  uVar39 = iVar11 + uVar39;
  uVar50 = ((uVar32 >> 0x11 | uVar32 * 0x8000) ^ (uVar32 >> 0x13 | uVar32 * 0x2000) ^ uVar32 >> 10)
           + uVar9 + uVar29 +
             ((uVar6 >> 7 | (uint)data[0xf] << 0x19) ^ (uVar12 >> 0x12 | uVar6 << 0xe) ^ uVar6 >> 3)
  ;
  iVar11 = uVar50 + 0xfc19dc6 + uVar44 + (uVar39 & (uVar49 ^ uVar13) ^ uVar13) +
           ((uVar39 >> 6 | uVar39 * 0x4000000) ^ (uVar39 >> 0xb | uVar39 * 0x200000) ^
           (uVar39 >> 0x19 | uVar39 * 0x80));
  uVar34 = iVar11 + uVar34;
  uVar16 = ((uVar43 | uVar42) & uVar36 | uVar43 & uVar42) +
           ((uVar43 >> 2 | uVar43 * 0x40000000) ^ (uVar43 >> 0xd | uVar43 * 0x80000) ^
           (uVar43 >> 0x16 | uVar43 * 0x400)) + iVar11;
  uVar18 = uVar28 + uVar6 +
           ((uVar7 >> 7 | (uint)data[0x13] << 0x19) ^ (uVar45 >> 0x12 | uVar7 << 0xe) ^ uVar7 >> 3)
           + ((uVar31 >> 0x11 | uVar31 * 0x8000) ^ (uVar31 >> 0x13 | uVar31 * 0x2000) ^ uVar31 >> 10
             );
  iVar11 = uVar18 + 0x240ca1cc + uVar13 + ((uVar39 ^ uVar49) & uVar34 ^ uVar49) +
           ((uVar34 >> 6 | uVar34 * 0x4000000) ^ (uVar34 >> 0xb | uVar34 * 0x200000) ^
           (uVar34 >> 0x19 | uVar34 * 0x80));
  uVar36 = iVar11 + uVar36;
  uVar12 = ((uVar16 | uVar43) & uVar42 | uVar16 & uVar43) +
           ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^
           (uVar16 >> 0x16 | uVar16 * 0x400)) + iVar11;
  uVar45 = ((uVar50 >> 0x11 | uVar50 * 0x8000) ^ (uVar50 >> 0x13 | uVar50 * 0x2000) ^ uVar50 >> 10)
           + uVar5 + uVar7 +
             ((uVar33 >> 7 | (uint)data[0x17] << 0x19) ^ (uVar20 >> 0x12 | uVar33 << 0xe) ^
             uVar33 >> 3);
  iVar11 = ((uVar36 >> 6 | uVar36 * 0x4000000) ^ (uVar36 >> 0xb | uVar36 * 0x200000) ^
           (uVar36 >> 0x19 | uVar36 * 0x80)) +
           (uVar36 & (uVar34 ^ uVar39) ^ uVar39) + uVar49 + uVar45 + 0x2de92c6f;
  uVar9 = ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
          (uVar12 >> 0x16 | uVar12 * 0x400)) + ((uVar12 | uVar16) & uVar43 | uVar12 & uVar16) +
          iVar11;
  uVar42 = uVar42 + iVar11;
  uVar44 = uVar40 + uVar33 +
           ((uVar25 >> 7 | (uint)data[0x1b] << 0x19) ^ (uVar21 >> 0x12 | uVar25 << 0xe) ^
           uVar25 >> 3) +
           ((uVar18 >> 0x11 | uVar18 * 0x8000) ^ (uVar18 >> 0x13 | uVar18 * 0x2000) ^ uVar18 >> 10);
  iVar11 = (uVar42 & (uVar36 ^ uVar34) ^ uVar34) + uVar44 + 0x4a7484aa + uVar39 +
           ((uVar42 >> 6 | uVar42 * 0x4000000) ^ (uVar42 >> 0xb | uVar42 * 0x200000) ^
           (uVar42 >> 0x19 | uVar42 * 0x80));
  uVar4 = ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
          (uVar9 >> 0x16 | uVar9 * 0x400)) + ((uVar9 | uVar12) & uVar16 | uVar9 & uVar12) + iVar11;
  uVar43 = iVar11 + uVar43;
  uVar49 = ((uVar45 >> 0x11 | uVar45 * 0x8000) ^ (uVar45 >> 0x13 | uVar45 * 0x2000) ^ uVar45 >> 10)
           + ((uVar26 >> 7 | (uint)data[0x1f] << 0x19) ^ (uVar46 >> 0x12 | uVar26 << 0xe) ^
             uVar26 >> 3) + uVar10 + uVar25;
  iVar11 = uVar49 + 0x5cb0a9dc + uVar34 + (uVar43 & (uVar42 ^ uVar36) ^ uVar36) +
           ((uVar43 >> 6 | uVar43 * 0x4000000) ^ (uVar43 >> 0xb | uVar43 * 0x200000) ^
           (uVar43 >> 0x19 | uVar43 * 0x80));
  uVar6 = ((uVar4 | uVar9) & uVar12 | uVar4 & uVar9) +
          ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
          (uVar4 >> 0x16 | uVar4 * 0x400)) + iVar11;
  uVar16 = uVar16 + iVar11;
  uVar20 = ((uVar44 >> 0x11 | uVar44 * 0x8000) ^ (uVar44 >> 0x13 | uVar44 * 0x2000) ^ uVar44 >> 10)
           + ((uVar22 >> 7 | (uint)data[0x23] << 0x19) ^ (uVar27 >> 0x12 | uVar22 << 0xe) ^
             uVar22 >> 3) + uVar26 + uVar32;
  iVar11 = uVar20 + 0x76f988da + uVar36 + (uVar16 & (uVar43 ^ uVar42) ^ uVar42) +
           ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^
           (uVar16 >> 0x19 | uVar16 * 0x80));
  uVar7 = ((uVar6 | uVar4) & uVar9 | uVar6 & uVar4) +
          ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
          (uVar6 >> 0x16 | uVar6 * 0x400)) + iVar11;
  uVar12 = iVar11 + uVar12;
  uVar34 = ((uVar49 >> 0x11 | uVar49 * 0x8000) ^ (uVar49 >> 0x13 | uVar49 * 0x2000) ^ uVar49 >> 10)
           + ((uVar37 >> 7 | (uint)data[0x27] << 0x19) ^ (uVar47 >> 0x12 | uVar37 << 0xe) ^
             uVar37 >> 3) + uVar22 + uVar31;
  iVar11 = ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^
           (uVar12 >> 0x19 | uVar12 * 0x80)) +
           uVar42 + uVar34 + 0x983e5152 + (uVar12 & (uVar16 ^ uVar43) ^ uVar43);
  uVar9 = iVar11 + uVar9;
  uVar13 = ((uVar7 | uVar6) & uVar4 | uVar7 & uVar6) +
           ((uVar7 >> 2 | uVar7 * 0x40000000) ^ (uVar7 >> 0xd | uVar7 * 0x80000) ^
           (uVar7 >> 0x16 | uVar7 * 0x400)) + iVar11;
  uVar36 = ((uVar20 >> 0x11 | uVar20 * 0x8000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000) ^ uVar20 >> 10)
           + ((uVar38 >> 7 | (uint)data[0x2b] << 0x19) ^ (uVar19 >> 0x12 | uVar38 << 0xe) ^
             uVar38 >> 3) + uVar37 + uVar50;
  iVar11 = ((uVar9 >> 6 | uVar9 * 0x4000000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
           (uVar9 >> 0x19 | uVar9 * 0x80)) +
           ((uVar12 ^ uVar16) & uVar9 ^ uVar16) + uVar43 + uVar36 + 0xa831c66d;
  uVar4 = uVar4 + iVar11;
  uVar43 = ((uVar13 | uVar7) & uVar6 | uVar13 & uVar7) +
           ((uVar13 >> 2 | uVar13 * 0x40000000) ^ (uVar13 >> 0xd | uVar13 * 0x80000) ^
           (uVar13 >> 0x16 | uVar13 * 0x400)) + iVar11;
  uVar26 = ((uVar34 >> 0x11 | uVar34 * 0x8000) ^ (uVar34 >> 0x13 | uVar34 * 0x2000) ^ uVar34 >> 10)
           + ((uVar29 >> 7 | (uint)data[0x2f] << 0x19) ^ (uVar14 >> 0x12 | uVar29 << 0xe) ^
             uVar29 >> 3) + uVar38 + uVar18;
  iVar11 = ((uVar4 >> 6 | uVar4 * 0x4000000) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
           (uVar4 >> 0x19 | uVar4 * 0x80)) +
           ((uVar9 ^ uVar12) & uVar4 ^ uVar12) + uVar16 + uVar26 + 0xb00327c8;
  uVar6 = iVar11 + uVar6;
  uVar16 = ((uVar43 | uVar13) & uVar7 | uVar43 & uVar13) +
           ((uVar43 >> 2 | uVar43 * 0x40000000) ^ (uVar43 >> 0xd | uVar43 * 0x80000) ^
           (uVar43 >> 0x16 | uVar43 * 0x400)) + iVar11;
  uVar25 = ((uVar36 >> 0x11 | uVar36 * 0x8000) ^ (uVar36 >> 0x13 | uVar36 * 0x2000) ^ uVar36 >> 10)
           + ((uVar28 >> 7 | (uint)data[0x33] << 0x19) ^ (uVar48 >> 0x12 | uVar28 << 0xe) ^
             uVar28 >> 3) + uVar29 + uVar45;
  iVar11 = uVar12 + uVar25 + 0xbf597fc7 + (uVar6 & (uVar4 ^ uVar9) ^ uVar9) +
           ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
           (uVar6 >> 0x19 | uVar6 * 0x80));
  uVar14 = ((uVar16 | uVar43) & uVar13 | uVar16 & uVar43) +
           ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^
           (uVar16 >> 0x16 | uVar16 * 0x400)) + iVar11;
  uVar7 = iVar11 + uVar7;
  uVar21 = ((uVar26 >> 0x11 | uVar26 * 0x8000) ^ (uVar26 >> 0x13 | uVar26 * 0x2000) ^ uVar26 >> 10)
           + ((uVar5 >> 7 | (uint)data[0x37] << 0x19) ^ (uVar30 >> 0x12 | uVar5 << 0xe) ^ uVar5 >> 3
             ) + uVar28 + uVar44;
  iVar11 = uVar21 + 0xc6e00bf3 + uVar9 + (uVar7 & (uVar6 ^ uVar4) ^ uVar4) +
           ((uVar7 >> 6 | uVar7 * 0x4000000) ^ (uVar7 >> 0xb | uVar7 * 0x200000) ^
           (uVar7 >> 0x19 | uVar7 * 0x80));
  uVar13 = uVar13 + iVar11;
  uVar9 = ((uVar14 | uVar16) & uVar43 | uVar14 & uVar16) +
          ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^
          (uVar14 >> 0x16 | uVar14 * 0x400)) + iVar11;
  uVar22 = ((uVar25 >> 0x11 | uVar25 * 0x8000) ^ (uVar25 >> 0x13 | uVar25 * 0x2000) ^ uVar25 >> 10)
           + ((uVar40 >> 7 | (uint)data[0x3b] << 0x19) ^ (uVar35 >> 0x12 | uVar40 << 0xe) ^
             uVar40 >> 3) + uVar5 + uVar49;
  iVar11 = uVar22 + 0xd5a79147 + uVar4 + (uVar13 & (uVar7 ^ uVar6) ^ uVar6) +
           ((uVar13 >> 6 | uVar13 * 0x4000000) ^ (uVar13 >> 0xb | uVar13 * 0x200000) ^
           (uVar13 >> 0x19 | uVar13 * 0x80));
  uVar33 = ((uVar9 | uVar14) & uVar16 | uVar9 & uVar14) +
           ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
           (uVar9 >> 0x16 | uVar9 * 0x400)) + iVar11;
  uVar43 = iVar11 + uVar43;
  uVar4 = ((uVar21 >> 0x11 | uVar21 * 0x8000) ^ (uVar21 >> 0x13 | uVar21 * 0x2000) ^ uVar21 >> 10) +
          ((uVar10 >> 7 | (uint)data[0x3f] << 0x19) ^ (uVar41 >> 0x12 | uVar10 << 0xe) ^ uVar10 >> 3
          ) + uVar40 + uVar20;
  iVar11 = (uVar43 & (uVar13 ^ uVar7) ^ uVar7) + uVar6 + uVar4 + 0x6ca6351 +
           ((uVar43 >> 6 | uVar43 * 0x4000000) ^ (uVar43 >> 0xb | uVar43 * 0x200000) ^
           (uVar43 >> 0x19 | uVar43 * 0x80));
  uVar12 = ((uVar33 | uVar9) & uVar14 | uVar33 & uVar9) +
           ((uVar33 >> 2 | uVar33 * 0x40000000) ^ (uVar33 >> 0xd | uVar33 * 0x80000) ^
           (uVar33 >> 0x16 | uVar33 * 0x400)) + iVar11;
  uVar16 = iVar11 + uVar16;
  uVar5 = ((uVar22 >> 0x11 | uVar22 * 0x8000) ^ (uVar22 >> 0x13 | uVar22 * 0x2000) ^ uVar22 >> 10) +
          ((uVar32 >> 7 | uVar32 * 0x2000000) ^ (uVar32 >> 0x12 | uVar32 * 0x4000) ^ uVar32 >> 3) +
          uVar10 + uVar34;
  iVar11 = uVar7 + uVar5 + 0x14292967 + (uVar16 & (uVar43 ^ uVar13) ^ uVar13) +
           ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^
           (uVar16 >> 0x19 | uVar16 * 0x80));
  uVar19 = ((uVar12 | uVar33) & uVar9 | uVar12 & uVar33) +
           ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
           (uVar12 >> 0x16 | uVar12 * 0x400)) + iVar11;
  uVar14 = iVar11 + uVar14;
  uVar6 = ((uVar31 >> 7 | uVar31 * 0x2000000) ^ (uVar31 >> 0x12 | uVar31 * 0x4000) ^ uVar31 >> 3) +
          uVar32 + uVar36 +
          ((uVar4 >> 0x11 | uVar4 * 0x8000) ^ (uVar4 >> 0x13 | uVar4 * 0x2000) ^ uVar4 >> 10);
  iVar11 = ((uVar14 >> 6 | uVar14 * 0x4000000) ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^
           (uVar14 >> 0x19 | uVar14 * 0x80)) +
           (uVar14 & (uVar16 ^ uVar43) ^ uVar43) + uVar13 + uVar6 + 0x27b70a85;
  uVar9 = uVar9 + iVar11;
  uVar17 = ((uVar19 | uVar12) & uVar33 | uVar19 & uVar12) +
           ((uVar19 >> 2 | uVar19 * 0x40000000) ^ (uVar19 >> 0xd | uVar19 * 0x80000) ^
           (uVar19 >> 0x16 | uVar19 * 0x400)) + iVar11;
  uVar7 = ((uVar50 >> 7 | uVar50 * 0x2000000) ^ (uVar50 >> 0x12 | uVar50 * 0x4000) ^ uVar50 >> 3) +
          uVar31 + uVar26 +
          ((uVar5 >> 0x11 | uVar5 * 0x8000) ^ (uVar5 >> 0x13 | uVar5 * 0x2000) ^ uVar5 >> 10);
  iVar11 = ((uVar9 >> 6 | uVar9 * 0x4000000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
           (uVar9 >> 0x19 | uVar9 * 0x80)) +
           ((uVar14 ^ uVar16) & uVar9 ^ uVar16) + uVar43 + uVar7 + 0x2e1b2138;
  uVar33 = uVar33 + iVar11;
  uVar13 = ((uVar17 | uVar19) & uVar12 | uVar17 & uVar19) +
           ((uVar17 >> 2 | uVar17 * 0x40000000) ^ (uVar17 >> 0xd | uVar17 * 0x80000) ^
           (uVar17 >> 0x16 | uVar17 * 0x400)) + iVar11;
  uVar43 = ((uVar18 >> 7 | uVar18 * 0x2000000) ^ (uVar18 >> 0x12 | uVar18 * 0x4000) ^ uVar18 >> 3) +
           uVar50 + uVar25 +
           ((uVar6 >> 0x11 | uVar6 * 0x8000) ^ (uVar6 >> 0x13 | uVar6 * 0x2000) ^ uVar6 >> 10);
  iVar11 = ((uVar33 >> 6 | uVar33 * 0x4000000) ^ (uVar33 >> 0xb | uVar33 * 0x200000) ^
           (uVar33 >> 0x19 | uVar33 * 0x80)) +
           ((uVar9 ^ uVar14) & uVar33 ^ uVar14) + uVar16 + uVar43 + 0x4d2c6dfc;
  uVar12 = uVar12 + iVar11;
  uVar16 = ((uVar13 | uVar17) & uVar19 | uVar13 & uVar17) +
           ((uVar13 >> 2 | uVar13 * 0x40000000) ^ (uVar13 >> 0xd | uVar13 * 0x80000) ^
           (uVar13 >> 0x16 | uVar13 * 0x400)) + iVar11;
  uVar35 = ((uVar7 >> 0x11 | uVar7 * 0x8000) ^ (uVar7 >> 0x13 | uVar7 * 0x2000) ^ uVar7 >> 10) +
           ((uVar45 >> 7 | uVar45 * 0x2000000) ^ (uVar45 >> 0x12 | uVar45 * 0x4000) ^ uVar45 >> 3) +
           uVar18 + uVar21;
  iVar11 = ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^
           (uVar12 >> 0x19 | uVar12 * 0x80)) +
           ((uVar33 ^ uVar9) & uVar12 ^ uVar9) + uVar14 + uVar35 + 0x53380d13;
  uVar19 = uVar19 + iVar11;
  uVar10 = ((uVar16 | uVar13) & uVar17 | uVar16 & uVar13) +
           ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^
           (uVar16 >> 0x16 | uVar16 * 0x400)) + iVar11;
  uVar32 = ((uVar43 >> 0x11 | uVar43 * 0x8000) ^ (uVar43 >> 0x13 | uVar43 * 0x2000) ^ uVar43 >> 10)
           + ((uVar44 >> 7 | uVar44 * 0x2000000) ^ (uVar44 >> 0x12 | uVar44 * 0x4000) ^ uVar44 >> 3)
             + uVar45 + uVar22;
  iVar11 = ((uVar19 >> 6 | uVar19 * 0x4000000) ^ (uVar19 >> 0xb | uVar19 * 0x200000) ^
           (uVar19 >> 0x19 | uVar19 * 0x80)) +
           uVar9 + uVar32 + 0x650a7354 + (uVar19 & (uVar12 ^ uVar33) ^ uVar33);
  uVar17 = uVar17 + iVar11;
  uVar9 = ((uVar10 | uVar16) & uVar13 | uVar10 & uVar16) +
          ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
          (uVar10 >> 0x16 | uVar10 * 0x400)) + iVar11;
  uVar29 = ((uVar35 >> 0x11 | uVar35 * 0x8000) ^ (uVar35 >> 0x13 | uVar35 * 0x2000) ^ uVar35 >> 10)
           + ((uVar49 >> 7 | uVar49 * 0x2000000) ^ (uVar49 >> 0x12 | uVar49 * 0x4000) ^ uVar49 >> 3)
             + uVar44 + uVar4;
  iVar11 = ((uVar17 >> 6 | uVar17 * 0x4000000) ^ (uVar17 >> 0xb | uVar17 * 0x200000) ^
           (uVar17 >> 0x19 | uVar17 * 0x80)) +
           uVar33 + uVar29 + 0x766a0abb + (uVar17 & (uVar19 ^ uVar12) ^ uVar12);
  uVar13 = uVar13 + iVar11;
  uVar33 = ((uVar9 | uVar10) & uVar16 | uVar9 & uVar10) +
           ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
           (uVar9 >> 0x16 | uVar9 * 0x400)) + iVar11;
  uVar49 = ((uVar32 >> 0x11 | uVar32 * 0x8000) ^ (uVar32 >> 0x13 | uVar32 * 0x2000) ^ uVar32 >> 10)
           + ((uVar20 >> 7 | uVar20 * 0x2000000) ^ (uVar20 >> 0x12 | uVar20 * 0x4000) ^ uVar20 >> 3)
             + uVar49 + uVar5;
  iVar11 = ((uVar13 >> 6 | uVar13 * 0x4000000) ^ (uVar13 >> 0xb | uVar13 * 0x200000) ^
           (uVar13 >> 0x19 | uVar13 * 0x80)) +
           uVar12 + uVar49 + 0x81c2c92e + (uVar13 & (uVar17 ^ uVar19) ^ uVar19);
  uVar16 = uVar16 + iVar11;
  uVar44 = ((uVar33 | uVar9) & uVar10 | uVar33 & uVar9) +
           ((uVar33 >> 2 | uVar33 * 0x40000000) ^ (uVar33 >> 0xd | uVar33 * 0x80000) ^
           (uVar33 >> 0x16 | uVar33 * 0x400)) + iVar11;
  uVar20 = ((uVar29 >> 0x11 | uVar29 * 0x8000) ^ (uVar29 >> 0x13 | uVar29 * 0x2000) ^ uVar29 >> 10)
           + ((uVar34 >> 7 | uVar34 * 0x2000000) ^ (uVar34 >> 0x12 | uVar34 * 0x4000) ^ uVar34 >> 3)
             + uVar20 + uVar6;
  iVar11 = ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^
           (uVar16 >> 0x19 | uVar16 * 0x80)) +
           uVar19 + uVar20 + 0x92722c85 + (uVar16 & (uVar13 ^ uVar17) ^ uVar17);
  uVar10 = uVar10 + iVar11;
  uVar27 = ((uVar44 | uVar33) & uVar9 | uVar44 & uVar33) +
           ((uVar44 >> 2 | uVar44 * 0x40000000) ^ (uVar44 >> 0xd | uVar44 * 0x80000) ^
           (uVar44 >> 0x16 | uVar44 * 0x400)) + iVar11;
  uVar19 = ((uVar49 >> 0x11 | uVar49 * 0x8000) ^ (uVar49 >> 0x13 | uVar49 * 0x2000) ^ uVar49 >> 10)
           + ((uVar36 >> 7 | uVar36 * 0x2000000) ^ (uVar36 >> 0x12 | uVar36 * 0x4000) ^ uVar36 >> 3)
             + uVar34 + uVar7;
  iVar11 = ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
           (uVar10 >> 0x19 | uVar10 * 0x80)) +
           uVar17 + uVar19 + 0xa2bfe8a1 + ((uVar16 ^ uVar13) & uVar10 ^ uVar13);
  uVar18 = ((uVar27 | uVar44) & uVar33 | uVar27 & uVar44) +
           ((uVar27 >> 2 | uVar27 * 0x40000000) ^ (uVar27 >> 0xd | uVar27 * 0x80000) ^
           (uVar27 >> 0x16 | uVar27 * 0x400)) + iVar11;
  uVar9 = uVar9 + iVar11;
  uVar17 = ((uVar20 >> 0x11 | uVar20 * 0x8000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000) ^ uVar20 >> 10)
           + ((uVar26 >> 7 | uVar26 * 0x2000000) ^ (uVar26 >> 0x12 | uVar26 * 0x4000) ^ uVar26 >> 3)
             + uVar36 + uVar43;
  iVar11 = uVar13 + uVar17 + 0xa81a664b + (uVar9 & (uVar10 ^ uVar16) ^ uVar16) +
           ((uVar9 >> 6 | uVar9 * 0x4000000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
           (uVar9 >> 0x19 | uVar9 * 0x80));
  uVar33 = iVar11 + uVar33;
  uVar12 = ((uVar18 | uVar27) & uVar44 | uVar18 & uVar27) +
           ((uVar18 >> 2 | uVar18 * 0x40000000) ^ (uVar18 >> 0xd | uVar18 * 0x80000) ^
           (uVar18 >> 0x16 | uVar18 * 0x400)) + iVar11;
  uVar26 = ((uVar19 >> 0x11 | uVar19 * 0x8000) ^ (uVar19 >> 0x13 | uVar19 * 0x2000) ^ uVar19 >> 10)
           + ((uVar25 >> 7 | uVar25 * 0x2000000) ^ (uVar25 >> 0x12 | uVar25 * 0x4000) ^ uVar25 >> 3)
             + uVar26 + uVar35;
  iVar11 = ((uVar33 >> 6 | uVar33 * 0x4000000) ^ (uVar33 >> 0xb | uVar33 * 0x200000) ^
           (uVar33 >> 0x19 | uVar33 * 0x80)) +
           uVar16 + uVar26 + 0xc24b8b70 + (uVar33 & (uVar9 ^ uVar10) ^ uVar10);
  uVar44 = uVar44 + iVar11;
  uVar13 = ((uVar12 | uVar18) & uVar27 | uVar12 & uVar18) +
           ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
           (uVar12 >> 0x16 | uVar12 * 0x400)) + iVar11;
  uVar25 = ((uVar17 >> 0x11 | uVar17 * 0x8000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000) ^ uVar17 >> 10)
           + ((uVar21 >> 7 | uVar21 * 0x2000000) ^ (uVar21 >> 0x12 | uVar21 * 0x4000) ^ uVar21 >> 3)
             + uVar25 + uVar32;
  iVar11 = ((uVar44 >> 6 | uVar44 * 0x4000000) ^ (uVar44 >> 0xb | uVar44 * 0x200000) ^
           (uVar44 >> 0x19 | uVar44 * 0x80)) +
           uVar25 + 0xc76c51a3 + uVar10 + ((uVar33 ^ uVar9) & uVar44 ^ uVar9);
  uVar27 = uVar27 + iVar11;
  uVar14 = ((uVar13 | uVar12) & uVar18 | uVar13 & uVar12) +
           ((uVar13 >> 2 | uVar13 * 0x40000000) ^ (uVar13 >> 0xd | uVar13 * 0x80000) ^
           (uVar13 >> 0x16 | uVar13 * 0x400)) + iVar11;
  uVar21 = ((uVar26 >> 0x11 | uVar26 * 0x8000) ^ (uVar26 >> 0x13 | uVar26 * 0x2000) ^ uVar26 >> 10)
           + ((uVar22 >> 7 | uVar22 * 0x2000000) ^ (uVar22 >> 0x12 | uVar22 * 0x4000) ^ uVar22 >> 3)
             + uVar21 + uVar29;
  iVar11 = ((uVar27 >> 6 | uVar27 * 0x4000000) ^ (uVar27 >> 0xb | uVar27 * 0x200000) ^
           (uVar27 >> 0x19 | uVar27 * 0x80)) +
           uVar21 + 0xd192e819 + uVar9 + (uVar27 & (uVar44 ^ uVar33) ^ uVar33);
  uVar18 = uVar18 + iVar11;
  uVar10 = ((uVar14 | uVar13) & uVar12 | uVar14 & uVar13) +
           ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^
           (uVar14 >> 0x16 | uVar14 * 0x400)) + iVar11;
  uVar22 = ((uVar25 >> 0x11 | uVar25 * 0x8000) ^ (uVar25 >> 0x13 | uVar25 * 0x2000) ^ uVar25 >> 10)
           + ((uVar4 >> 7 | uVar4 * 0x2000000) ^ (uVar4 >> 0x12 | uVar4 * 0x4000) ^ uVar4 >> 3) +
             uVar22 + uVar49;
  iVar11 = ((uVar18 >> 6 | uVar18 * 0x4000000) ^ (uVar18 >> 0xb | uVar18 * 0x200000) ^
           (uVar18 >> 0x19 | uVar18 * 0x80)) +
           uVar33 + uVar22 + 0xd6990624 + (uVar18 & (uVar27 ^ uVar44) ^ uVar44);
  uVar12 = uVar12 + iVar11;
  uVar9 = ((uVar10 | uVar14) & uVar13 | uVar10 & uVar14) +
          ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
          (uVar10 >> 0x16 | uVar10 * 0x400)) + iVar11;
  uVar36 = ((uVar21 >> 0x11 | uVar21 * 0x8000) ^ (uVar21 >> 0x13 | uVar21 * 0x2000) ^ uVar21 >> 10)
           + ((uVar5 >> 7 | uVar5 * 0x2000000) ^ (uVar5 >> 0x12 | uVar5 * 0x4000) ^ uVar5 >> 3) +
             uVar4 + uVar20;
  iVar11 = ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^
           (uVar12 >> 0x19 | uVar12 * 0x80)) +
           uVar44 + uVar36 + 0xf40e3585 + (uVar12 & (uVar18 ^ uVar27) ^ uVar27);
  uVar13 = uVar13 + iVar11;
  uVar33 = ((uVar9 | uVar10) & uVar14 | uVar9 & uVar10) +
           ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
           (uVar9 >> 0x16 | uVar9 * 0x400)) + iVar11;
  uVar34 = ((uVar22 >> 0x11 | uVar22 * 0x8000) ^ (uVar22 >> 0x13 | uVar22 * 0x2000) ^ uVar22 >> 10)
           + ((uVar6 >> 7 | uVar6 * 0x2000000) ^ (uVar6 >> 0x12 | uVar6 * 0x4000) ^ uVar6 >> 3) +
             uVar5 + uVar19;
  iVar11 = ((uVar13 >> 6 | uVar13 * 0x4000000) ^ (uVar13 >> 0xb | uVar13 * 0x200000) ^
           (uVar13 >> 0x19 | uVar13 * 0x80)) +
           uVar27 + uVar34 + 0x106aa070 + (uVar13 & (uVar12 ^ uVar18) ^ uVar18);
  uVar14 = uVar14 + iVar11;
  uVar16 = ((uVar33 | uVar9) & uVar10 | uVar33 & uVar9) +
           ((uVar33 >> 2 | uVar33 * 0x40000000) ^ (uVar33 >> 0xd | uVar33 * 0x80000) ^
           (uVar33 >> 0x16 | uVar33 * 0x400)) + iVar11;
  uVar27 = ((uVar36 >> 0x11 | uVar36 * 0x8000) ^ (uVar36 >> 0x13 | uVar36 * 0x2000) ^ uVar36 >> 10)
           + ((uVar7 >> 7 | uVar7 * 0x2000000) ^ (uVar7 >> 0x12 | uVar7 * 0x4000) ^ uVar7 >> 3) +
             uVar6 + uVar17;
  iVar11 = ((uVar14 >> 6 | uVar14 * 0x4000000) ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^
           (uVar14 >> 0x19 | uVar14 * 0x80)) +
           uVar27 + 0x19a4c116 + uVar18 + ((uVar13 ^ uVar12) & uVar14 ^ uVar12);
  uVar10 = uVar10 + iVar11;
  uVar5 = ((uVar16 | uVar33) & uVar9 | uVar16 & uVar33) +
          ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^
          (uVar16 >> 0x16 | uVar16 * 0x400)) + iVar11;
  uVar7 = ((uVar34 >> 0x11 | uVar34 * 0x8000) ^ (uVar34 >> 0x13 | uVar34 * 0x2000) ^ uVar34 >> 10) +
          ((uVar43 >> 7 | uVar43 * 0x2000000) ^ (uVar43 >> 0x12 | uVar43 * 0x4000) ^ uVar43 >> 3) +
          uVar7 + uVar26;
  iVar11 = ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
           (uVar10 >> 0x19 | uVar10 * 0x80)) +
           uVar12 + uVar7 + 0x1e376c08 + (uVar10 & (uVar14 ^ uVar13) ^ uVar13);
  uVar9 = uVar9 + iVar11;
  uVar44 = ((uVar5 | uVar16) & uVar33 | uVar5 & uVar16) +
           ((uVar5 >> 2 | uVar5 * 0x40000000) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
           (uVar5 >> 0x16 | uVar5 * 0x400)) + iVar11;
  uVar28 = ((uVar27 >> 0x11 | uVar27 * 0x8000) ^ (uVar27 >> 0x13 | uVar27 * 0x2000) ^ uVar27 >> 10)
           + ((uVar35 >> 7 | uVar35 * 0x2000000) ^ (uVar35 >> 0x12 | uVar35 * 0x4000) ^ uVar35 >> 3)
             + uVar43 + uVar25;
  iVar11 = ((uVar9 >> 6 | uVar9 * 0x4000000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
           (uVar9 >> 0x19 | uVar9 * 0x80)) +
           uVar13 + uVar28 + 0x2748774c + (uVar9 & (uVar10 ^ uVar14) ^ uVar14);
  uVar33 = uVar33 + iVar11;
  uVar12 = ((uVar44 | uVar5) & uVar16 | uVar44 & uVar5) +
           ((uVar44 >> 2 | uVar44 * 0x40000000) ^ (uVar44 >> 0xd | uVar44 * 0x80000) ^
           (uVar44 >> 0x16 | uVar44 * 0x400)) + iVar11;
  uVar35 = ((uVar7 >> 0x11 | uVar7 * 0x8000) ^ (uVar7 >> 0x13 | uVar7 * 0x2000) ^ uVar7 >> 10) +
           ((uVar32 >> 7 | uVar32 * 0x2000000) ^ (uVar32 >> 0x12 | uVar32 * 0x4000) ^ uVar32 >> 3) +
           uVar35 + uVar21;
  iVar11 = ((uVar33 >> 6 | uVar33 * 0x4000000) ^ (uVar33 >> 0xb | uVar33 * 0x200000) ^
           (uVar33 >> 0x19 | uVar33 * 0x80)) +
           (uVar33 & (uVar9 ^ uVar10) ^ uVar10) + uVar14 + uVar35 + 0x34b0bcb5;
  uVar16 = iVar11 + uVar16;
  uVar30 = ((uVar12 | uVar44) & uVar5 | uVar12 & uVar44) +
           ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
           (uVar12 >> 0x16 | uVar12 * 0x400)) + iVar11;
  uVar32 = ((uVar28 >> 0x11 | uVar28 * 0x8000) ^ (uVar28 >> 0x13 | uVar28 * 0x2000) ^ uVar28 >> 10)
           + ((uVar29 >> 7 | uVar29 * 0x2000000) ^ (uVar29 >> 0x12 | uVar29 * 0x4000) ^ uVar29 >> 3)
             + uVar32 + uVar22;
  iVar11 = uVar10 + uVar32 + 0x391c0cb3 + (uVar16 & (uVar33 ^ uVar9) ^ uVar9) +
           ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^
           (uVar16 >> 0x19 | uVar16 * 0x80));
  uVar5 = iVar11 + uVar5;
  uVar4 = ((uVar30 | uVar12) & uVar44 | uVar30 & uVar12) +
          ((uVar30 >> 2 | uVar30 * 0x40000000) ^ (uVar30 >> 0xd | uVar30 * 0x80000) ^
          (uVar30 >> 0x16 | uVar30 * 0x400)) + iVar11;
  uVar18 = ((uVar35 >> 0x11 | uVar35 * 0x8000) ^ (uVar35 >> 0x13 | uVar35 * 0x2000) ^ uVar35 >> 10)
           + ((uVar49 >> 7 | uVar49 * 0x2000000) ^ (uVar49 >> 0x12 | uVar49 * 0x4000) ^ uVar49 >> 3)
             + uVar29 + uVar36;
  iVar11 = ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
           (uVar5 >> 0x19 | uVar5 * 0x80)) +
           uVar9 + uVar18 + 0x4ed8aa4a + (uVar5 & (uVar16 ^ uVar33) ^ uVar33);
  uVar44 = uVar44 + iVar11;
  uVar43 = ((uVar4 | uVar30) & uVar12 | uVar4 & uVar30) +
           ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
           (uVar4 >> 0x16 | uVar4 * 0x400)) + iVar11;
  uVar13 = ((uVar20 >> 7 | uVar20 * 0x2000000) ^ (uVar20 >> 0x12 | uVar20 * 0x4000) ^ uVar20 >> 3) +
           uVar49 + uVar34 +
           ((uVar32 >> 0x11 | uVar32 * 0x8000) ^ (uVar32 >> 0x13 | uVar32 * 0x2000) ^ uVar32 >> 10);
  iVar11 = ((uVar44 >> 6 | uVar44 * 0x4000000) ^ (uVar44 >> 0xb | uVar44 * 0x200000) ^
           (uVar44 >> 0x19 | uVar44 * 0x80)) +
           uVar13 + 0x5b9cca4f + uVar33 + ((uVar5 ^ uVar16) & uVar44 ^ uVar16);
  uVar12 = uVar12 + iVar11;
  uVar14 = ((uVar43 | uVar4) & uVar30 | uVar43 & uVar4) +
           ((uVar43 >> 2 | uVar43 * 0x40000000) ^ (uVar43 >> 0xd | uVar43 * 0x80000) ^
           (uVar43 >> 0x16 | uVar43 * 0x400)) + iVar11;
  uVar20 = ((uVar18 >> 0x11 | uVar18 * 0x8000) ^ (uVar18 >> 0x13 | uVar18 * 0x2000) ^ uVar18 >> 10)
           + ((uVar19 >> 7 | uVar19 * 0x2000000) ^ (uVar19 >> 0x12 | uVar19 * 0x4000) ^ uVar19 >> 3)
             + uVar20 + uVar27;
  iVar11 = ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^
           (uVar12 >> 0x19 | uVar12 * 0x80)) +
           uVar16 + uVar20 + 0x682e6ff3 + (uVar12 & (uVar44 ^ uVar5) ^ uVar5);
  uVar30 = uVar30 + iVar11;
  uVar6 = ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^
          (uVar14 >> 0x16 | uVar14 * 0x400)) + ((uVar14 | uVar43) & uVar4 | uVar14 & uVar43) +
          iVar11;
  uVar16 = ((uVar13 >> 0x11 | uVar13 * 0x8000) ^ (uVar13 >> 0x13 | uVar13 * 0x2000) ^ uVar13 >> 10)
           + ((uVar17 >> 7 | uVar17 * 0x2000000) ^ (uVar17 >> 0x12 | uVar17 * 0x4000) ^ uVar17 >> 3)
             + uVar19 + uVar7;
  iVar11 = uVar5 + uVar16 + 0x748f82ee + (uVar30 & (uVar12 ^ uVar44) ^ uVar44) +
           ((uVar30 >> 6 | uVar30 * 0x4000000) ^ (uVar30 >> 0xb | uVar30 * 0x200000) ^
           (uVar30 >> 0x19 | uVar30 * 0x80));
  uVar4 = iVar11 + uVar4;
  uVar7 = ((uVar6 | uVar14) & uVar43 | uVar6 & uVar14) +
          ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
          (uVar6 >> 0x16 | uVar6 * 0x400)) + iVar11;
  uVar5 = ((uVar26 >> 7 | uVar26 * 0x2000000) ^ (uVar26 >> 0x12 | uVar26 * 0x4000) ^ uVar26 >> 3) +
          uVar17 + uVar28 +
          ((uVar20 >> 0x11 | uVar20 * 0x8000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000) ^ uVar20 >> 10);
  iVar11 = uVar44 + uVar5 + 0x78a5636f + (uVar4 & (uVar30 ^ uVar12) ^ uVar12) +
           ((uVar4 >> 6 | uVar4 * 0x4000000) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
           (uVar4 >> 0x19 | uVar4 * 0x80));
  uVar43 = iVar11 + uVar43;
  uVar33 = ((uVar7 | uVar6) & uVar14 | uVar7 & uVar6) +
           ((uVar7 >> 2 | uVar7 * 0x40000000) ^ (uVar7 >> 0xd | uVar7 * 0x80000) ^
           (uVar7 >> 0x16 | uVar7 * 0x400)) + iVar11;
  uVar9 = ((uVar25 >> 7 | uVar25 * 0x2000000) ^ (uVar25 >> 0x12 | uVar25 * 0x4000) ^ uVar25 >> 3) +
          uVar26 + uVar35 +
          ((uVar16 >> 0x11 | uVar16 * 0x8000) ^ (uVar16 >> 0x13 | uVar16 * 0x2000) ^ uVar16 >> 10);
  iVar11 = uVar12 + uVar9 + 0x84c87814 + (uVar43 & (uVar4 ^ uVar30) ^ uVar30) +
           ((uVar43 >> 6 | uVar43 * 0x4000000) ^ (uVar43 >> 0xb | uVar43 * 0x200000) ^
           (uVar43 >> 0x19 | uVar43 * 0x80));
  uVar14 = iVar11 + uVar14;
  uVar44 = ((uVar33 | uVar7) & uVar6 | uVar33 & uVar7) +
           ((uVar33 >> 2 | uVar33 * 0x40000000) ^ (uVar33 >> 0xd | uVar33 * 0x80000) ^
           (uVar33 >> 0x16 | uVar33 * 0x400)) + iVar11;
  uVar10 = ((uVar21 >> 7 | uVar21 * 0x2000000) ^ (uVar21 >> 0x12 | uVar21 * 0x4000) ^ uVar21 >> 3) +
           uVar25 + uVar32 +
           ((uVar5 >> 0x11 | uVar5 * 0x8000) ^ (uVar5 >> 0x13 | uVar5 * 0x2000) ^ uVar5 >> 10);
  iVar11 = (uVar14 & (uVar43 ^ uVar4) ^ uVar4) + uVar10 + 0x8cc70208 + uVar30 +
           ((uVar14 >> 6 | uVar14 * 0x4000000) ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^
           (uVar14 >> 0x19 | uVar14 * 0x80));
  uVar12 = (uVar44 & uVar33 | (uVar44 | uVar33) & uVar7) +
           ((uVar44 >> 2 | uVar44 * 0x40000000) ^ (uVar44 >> 0xd | uVar44 * 0x80000) ^
           (uVar44 >> 0x16 | uVar44 * 0x400)) + iVar11;
  uVar6 = uVar6 + iVar11;
  uVar5 = ((uVar22 >> 7 | uVar22 * 0x2000000) ^ (uVar22 >> 0x12 | uVar22 * 0x4000) ^ uVar22 >> 3) +
          uVar21 + uVar18 +
          ((uVar9 >> 0x11 | uVar9 * 0x8000) ^ (uVar9 >> 0x13 | uVar9 * 0x2000) ^ uVar9 >> 10);
  iVar11 = uVar5 + 0x90befffa + uVar4 + (uVar6 & (uVar14 ^ uVar43) ^ uVar43) +
           ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
           (uVar6 >> 0x19 | uVar6 * 0x80));
  uVar9 = ((uVar12 | uVar44) & uVar33 | uVar12 & uVar44) +
          ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
          (uVar12 >> 0x16 | uVar12 * 0x400)) + iVar11;
  uVar7 = iVar11 + uVar7;
  uVar10 = ((uVar36 >> 7 | uVar36 * 0x2000000) ^ (uVar36 >> 0x12 | uVar36 * 0x4000) ^ uVar36 >> 3) +
           uVar22 + uVar13 +
           ((uVar10 >> 0x11 | uVar10 * 0x8000) ^ (uVar10 >> 0x13 | uVar10 * 0x2000) ^ uVar10 >> 10);
  iVar11 = ((uVar7 >> 6 | uVar7 * 0x4000000) ^ (uVar7 >> 0xb | uVar7 * 0x200000) ^
           (uVar7 >> 0x19 | uVar7 * 0x80)) +
           (uVar7 & (uVar6 ^ uVar14) ^ uVar14) + uVar10 + 0xa4506ceb + uVar43;
  uVar43 = (uVar9 & uVar12 | (uVar9 | uVar12) & uVar44) +
           ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
           (uVar9 >> 0x16 | uVar9 * 0x400)) + iVar11;
  uVar33 = iVar11 + uVar33;
  iVar11 = ((uVar7 ^ uVar6) & uVar33 ^ uVar6) +
           uVar36 + 0xbef9a3f7 +
           ((uVar34 >> 7 | uVar34 * 0x2000000) ^ (uVar34 >> 0x12 | uVar34 * 0x4000) ^ uVar34 >> 3) +
           uVar20 + ((uVar5 >> 0x11 | uVar5 * 0x8000) ^ (uVar5 >> 0x13 | uVar5 * 0x2000) ^
                    uVar5 >> 10) + uVar14 +
           ((uVar33 >> 6 | uVar33 * 0x4000000) ^ (uVar33 >> 0xb | uVar33 * 0x200000) ^
           (uVar33 >> 0x19 | uVar33 * 0x80));
  uVar4 = ((uVar43 | uVar9) & uVar12 | uVar43 & uVar9) +
          ((uVar43 >> 2 | uVar43 * 0x40000000) ^ (uVar43 >> 0xd | uVar43 * 0x80000) ^
          (uVar43 >> 0x16 | uVar43 * 0x400)) + iVar11;
  uVar44 = iVar11 + uVar44;
  iVar11 = (uVar44 & (uVar33 ^ uVar7) ^ uVar7) +
           ((uVar10 >> 0x11 | uVar10 * 0x8000) ^ (uVar10 >> 0x13 | uVar10 * 0x2000) ^ uVar10 >> 10)
           + uVar34 + 0xc67178f2 +
             ((uVar27 >> 7 | uVar27 * 0x2000000) ^ (uVar27 >> 0x12 | uVar27 * 0x4000) ^ uVar27 >> 3)
             + uVar16 + uVar6 +
           ((uVar44 >> 6 | uVar44 * 0x4000000) ^ (uVar44 >> 0xb | uVar44 * 0x200000) ^
           (uVar44 >> 0x19 | uVar44 * 0x80));
  ctx->state[3] = uVar9 + ctx->state[3];
  ctx->state[0] =
       ((uVar4 | uVar43) & uVar9 | uVar4 & uVar43) +
       ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
       (uVar4 >> 0x16 | uVar4 * 0x400)) + uVar8 + iVar11;
  ctx->state[4] = uVar12 + uVar1 + iVar11;
  ctx->state[1] = uVar4 + uVar3;
  ctx->state[5] = uVar44 + uVar23;
  ctx->state[2] = uVar43 + uVar24;
  ctx->state[6] = uVar33 + uVar15;
  ctx->state[7] = uVar7 + uVar2;
  return;
}

