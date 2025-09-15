
void sha2_process(sha2_context *ctx,uchar *data)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
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
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  int iVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uchar *data_local;
  sha2_context *ctx_local;
  uint32_t W [64];
  uint32_t temp2;
  uint32_t temp1;
  uint32_t H;
  uint32_t G;
  uint32_t F;
  uint32_t E;
  uint32_t D;
  uint32_t C;
  uint32_t B;
  uint32_t A;
  
  uVar16 = (uint)*data << 0x18 | (uint)data[1] << 0x10 | (uint)data[2] << 8 | (uint)data[3];
  uVar1 = (uint)data[4] << 0x18 | (uint)data[5] << 0x10;
  uVar17 = uVar1 | (uint)data[6] << 8 | (uint)data[7];
  uVar2 = (uint)data[8] << 0x18 | (uint)data[9] << 0x10;
  uVar18 = uVar2 | (uint)data[10] << 8 | (uint)data[0xb];
  uVar3 = (uint)data[0xc] << 0x18 | (uint)data[0xd] << 0x10;
  uVar19 = uVar3 | (uint)data[0xe] << 8 | (uint)data[0xf];
  uVar4 = (uint)data[0x10] << 0x18 | (uint)data[0x11] << 0x10;
  uVar20 = uVar4 | (uint)data[0x12] << 8 | (uint)data[0x13];
  uVar5 = (uint)data[0x14] << 0x18 | (uint)data[0x15] << 0x10;
  uVar21 = uVar5 | (uint)data[0x16] << 8 | (uint)data[0x17];
  uVar6 = (uint)data[0x18] << 0x18 | (uint)data[0x19] << 0x10;
  uVar22 = uVar6 | (uint)data[0x1a] << 8 | (uint)data[0x1b];
  uVar7 = (uint)data[0x1c] << 0x18 | (uint)data[0x1d] << 0x10;
  uVar23 = uVar7 | (uint)data[0x1e] << 8 | (uint)data[0x1f];
  uVar8 = (uint)data[0x20] << 0x18 | (uint)data[0x21] << 0x10;
  uVar24 = uVar8 | (uint)data[0x22] << 8 | (uint)data[0x23];
  uVar9 = (uint)data[0x24] << 0x18 | (uint)data[0x25] << 0x10;
  uVar25 = uVar9 | (uint)data[0x26] << 8 | (uint)data[0x27];
  uVar10 = (uint)data[0x28] << 0x18 | (uint)data[0x29] << 0x10;
  uVar26 = uVar10 | (uint)data[0x2a] << 8 | (uint)data[0x2b];
  uVar11 = (uint)data[0x2c] << 0x18 | (uint)data[0x2d] << 0x10;
  uVar27 = uVar11 | (uint)data[0x2e] << 8 | (uint)data[0x2f];
  uVar12 = (uint)data[0x30] << 0x18 | (uint)data[0x31] << 0x10;
  uVar28 = uVar12 | (uint)data[0x32] << 8 | (uint)data[0x33];
  uVar13 = (uint)data[0x34] << 0x18 | (uint)data[0x35] << 0x10;
  uVar29 = uVar13 | (uint)data[0x36] << 8 | (uint)data[0x37];
  uVar14 = (uint)data[0x38] << 0x18 | (uint)data[0x39] << 0x10;
  uVar30 = uVar14 | (uint)data[0x3a] << 8;
  uVar31 = uVar30 | data[0x3b];
  uVar15 = (uint)data[0x3c] << 0x18 | (uint)data[0x3d] << 0x10;
  uVar32 = uVar15 | (uint)data[0x3e] << 8;
  uVar33 = uVar32 | data[0x3f];
  uVar34 = ctx->state[0];
  uVar35 = ctx->state[1];
  uVar36 = ctx->state[4];
  uVar37 = ctx->state[5];
  uVar38 = ctx->state[6];
  iVar39 = ((uVar36 >> 6 | uVar36 << 0x1a) ^ (uVar36 >> 0xb | uVar36 << 0x15) ^
           (uVar36 >> 0x19 | uVar36 << 7)) + ctx->state[7] + (uVar38 ^ (uVar37 ^ uVar38) & uVar36) +
           uVar16 + 0x428a2f98;
  uVar40 = ctx->state[3] + iVar39;
  uVar41 = iVar39 + ((uVar34 >> 2 | uVar34 << 0x1e) ^ (uVar34 >> 0xd | uVar34 << 0x13) ^
                    (uVar34 >> 0x16 | uVar34 << 10)) +
                    (uVar34 & uVar35 | ctx->state[2] & (uVar34 | uVar35));
  iVar39 = ((uVar40 >> 6 | uVar40 * 0x4000000) ^ (uVar40 >> 0xb | uVar40 * 0x200000) ^
           (uVar40 >> 0x19 | uVar40 * 0x80)) + uVar38 + (uVar37 ^ (uVar36 ^ uVar37) & uVar40) +
           uVar17 + 0x71374491;
  uVar38 = ctx->state[2] + iVar39;
  uVar42 = iVar39 + ((uVar41 >> 2 | uVar41 * 0x40000000) ^ (uVar41 >> 0xd | uVar41 * 0x80000) ^
                    (uVar41 >> 0x16 | uVar41 * 0x400)) +
                    (uVar41 & uVar34 | uVar35 & (uVar41 | uVar34));
  iVar39 = ((uVar38 >> 6 | uVar38 * 0x4000000) ^ (uVar38 >> 0xb | uVar38 * 0x200000) ^
           (uVar38 >> 0x19 | uVar38 * 0x80)) + uVar37 + (uVar36 ^ (uVar40 ^ uVar36) & uVar38) +
           uVar18 + -0x4a3f0431;
  uVar35 = uVar35 + iVar39;
  uVar37 = iVar39 + ((uVar42 >> 2 | uVar42 * 0x40000000) ^ (uVar42 >> 0xd | uVar42 * 0x80000) ^
                    (uVar42 >> 0x16 | uVar42 * 0x400)) +
                    (uVar42 & uVar41 | uVar34 & (uVar42 | uVar41));
  iVar39 = ((uVar35 >> 6 | uVar35 * 0x4000000) ^ (uVar35 >> 0xb | uVar35 * 0x200000) ^
           (uVar35 >> 0x19 | uVar35 * 0x80)) + uVar36 + (uVar40 ^ (uVar38 ^ uVar40) & uVar35) +
           uVar19 + -0x164a245b;
  uVar34 = uVar34 + iVar39;
  uVar36 = iVar39 + ((uVar37 >> 2 | uVar37 * 0x40000000) ^ (uVar37 >> 0xd | uVar37 * 0x80000) ^
                    (uVar37 >> 0x16 | uVar37 * 0x400)) +
                    (uVar37 & uVar42 | uVar41 & (uVar37 | uVar42));
  iVar39 = ((uVar34 >> 6 | uVar34 * 0x4000000) ^ (uVar34 >> 0xb | uVar34 * 0x200000) ^
           (uVar34 >> 0x19 | uVar34 * 0x80)) + uVar40 + (uVar38 ^ (uVar35 ^ uVar38) & uVar34) +
           uVar20 + 0x3956c25b;
  uVar41 = uVar41 + iVar39;
  uVar40 = iVar39 + ((uVar36 >> 2 | uVar36 * 0x40000000) ^ (uVar36 >> 0xd | uVar36 * 0x80000) ^
                    (uVar36 >> 0x16 | uVar36 * 0x400)) +
                    (uVar36 & uVar37 | uVar42 & (uVar36 | uVar37));
  iVar39 = ((uVar41 >> 6 | uVar41 * 0x4000000) ^ (uVar41 >> 0xb | uVar41 * 0x200000) ^
           (uVar41 >> 0x19 | uVar41 * 0x80)) + uVar38 + (uVar35 ^ (uVar34 ^ uVar35) & uVar41) +
           uVar21 + 0x59f111f1;
  uVar42 = uVar42 + iVar39;
  uVar38 = iVar39 + ((uVar40 >> 2 | uVar40 * 0x40000000) ^ (uVar40 >> 0xd | uVar40 * 0x80000) ^
                    (uVar40 >> 0x16 | uVar40 * 0x400)) +
                    (uVar40 & uVar36 | uVar37 & (uVar40 | uVar36));
  iVar39 = ((uVar42 >> 6 | uVar42 * 0x4000000) ^ (uVar42 >> 0xb | uVar42 * 0x200000) ^
           (uVar42 >> 0x19 | uVar42 * 0x80)) + uVar35 + (uVar34 ^ (uVar41 ^ uVar34) & uVar42) +
           uVar22 + -0x6dc07d5c;
  uVar37 = uVar37 + iVar39;
  uVar35 = iVar39 + ((uVar38 >> 2 | uVar38 * 0x40000000) ^ (uVar38 >> 0xd | uVar38 * 0x80000) ^
                    (uVar38 >> 0x16 | uVar38 * 0x400)) +
                    (uVar38 & uVar40 | uVar36 & (uVar38 | uVar40));
  iVar39 = ((uVar37 >> 6 | uVar37 * 0x4000000) ^ (uVar37 >> 0xb | uVar37 * 0x200000) ^
           (uVar37 >> 0x19 | uVar37 * 0x80)) + uVar34 + (uVar41 ^ (uVar42 ^ uVar41) & uVar37) +
           uVar23 + -0x54e3a12b;
  uVar36 = uVar36 + iVar39;
  uVar34 = iVar39 + ((uVar35 >> 2 | uVar35 * 0x40000000) ^ (uVar35 >> 0xd | uVar35 * 0x80000) ^
                    (uVar35 >> 0x16 | uVar35 * 0x400)) +
                    (uVar35 & uVar38 | uVar40 & (uVar35 | uVar38));
  iVar39 = ((uVar36 >> 6 | uVar36 * 0x4000000) ^ (uVar36 >> 0xb | uVar36 * 0x200000) ^
           (uVar36 >> 0x19 | uVar36 * 0x80)) + uVar41 + (uVar42 ^ (uVar37 ^ uVar42) & uVar36) +
           uVar24 + -0x27f85568;
  uVar40 = uVar40 + iVar39;
  uVar41 = iVar39 + ((uVar34 >> 2 | uVar34 * 0x40000000) ^ (uVar34 >> 0xd | uVar34 * 0x80000) ^
                    (uVar34 >> 0x16 | uVar34 * 0x400)) +
                    (uVar34 & uVar35 | uVar38 & (uVar34 | uVar35));
  iVar39 = ((uVar40 >> 6 | uVar40 * 0x4000000) ^ (uVar40 >> 0xb | uVar40 * 0x200000) ^
           (uVar40 >> 0x19 | uVar40 * 0x80)) + uVar42 + (uVar37 ^ (uVar36 ^ uVar37) & uVar40) +
           uVar25 + 0x12835b01;
  uVar38 = uVar38 + iVar39;
  uVar42 = iVar39 + ((uVar41 >> 2 | uVar41 * 0x40000000) ^ (uVar41 >> 0xd | uVar41 * 0x80000) ^
                    (uVar41 >> 0x16 | uVar41 * 0x400)) +
                    (uVar41 & uVar34 | uVar35 & (uVar41 | uVar34));
  iVar39 = ((uVar38 >> 6 | uVar38 * 0x4000000) ^ (uVar38 >> 0xb | uVar38 * 0x200000) ^
           (uVar38 >> 0x19 | uVar38 * 0x80)) + uVar37 + (uVar36 ^ (uVar40 ^ uVar36) & uVar38) +
           uVar26 + 0x243185be;
  uVar35 = uVar35 + iVar39;
  uVar37 = iVar39 + ((uVar42 >> 2 | uVar42 * 0x40000000) ^ (uVar42 >> 0xd | uVar42 * 0x80000) ^
                    (uVar42 >> 0x16 | uVar42 * 0x400)) +
                    (uVar42 & uVar41 | uVar34 & (uVar42 | uVar41));
  iVar39 = ((uVar35 >> 6 | uVar35 * 0x4000000) ^ (uVar35 >> 0xb | uVar35 * 0x200000) ^
           (uVar35 >> 0x19 | uVar35 * 0x80)) + uVar36 + (uVar40 ^ (uVar38 ^ uVar40) & uVar35) +
           uVar27 + 0x550c7dc3;
  uVar34 = uVar34 + iVar39;
  uVar36 = iVar39 + ((uVar37 >> 2 | uVar37 * 0x40000000) ^ (uVar37 >> 0xd | uVar37 * 0x80000) ^
                    (uVar37 >> 0x16 | uVar37 * 0x400)) +
                    (uVar37 & uVar42 | uVar41 & (uVar37 | uVar42));
  iVar39 = ((uVar34 >> 6 | uVar34 * 0x4000000) ^ (uVar34 >> 0xb | uVar34 * 0x200000) ^
           (uVar34 >> 0x19 | uVar34 * 0x80)) + uVar40 + (uVar38 ^ (uVar35 ^ uVar38) & uVar34) +
           uVar28 + 0x72be5d74;
  uVar41 = uVar41 + iVar39;
  uVar40 = iVar39 + ((uVar36 >> 2 | uVar36 * 0x40000000) ^ (uVar36 >> 0xd | uVar36 * 0x80000) ^
                    (uVar36 >> 0x16 | uVar36 * 0x400)) +
                    (uVar36 & uVar37 | uVar42 & (uVar36 | uVar37));
  iVar39 = ((uVar41 >> 6 | uVar41 * 0x4000000) ^ (uVar41 >> 0xb | uVar41 * 0x200000) ^
           (uVar41 >> 0x19 | uVar41 * 0x80)) + uVar38 + (uVar35 ^ (uVar34 ^ uVar35) & uVar41) +
           uVar29 + -0x7f214e02;
  uVar42 = uVar42 + iVar39;
  uVar38 = iVar39 + ((uVar40 >> 2 | uVar40 * 0x40000000) ^ (uVar40 >> 0xd | uVar40 * 0x80000) ^
                    (uVar40 >> 0x16 | uVar40 * 0x400)) +
                    (uVar40 & uVar36 | uVar37 & (uVar40 | uVar36));
  iVar39 = ((uVar42 >> 6 | uVar42 * 0x4000000) ^ (uVar42 >> 0xb | uVar42 * 0x200000) ^
           (uVar42 >> 0x19 | uVar42 * 0x80)) + uVar35 + (uVar34 ^ (uVar41 ^ uVar34) & uVar42) +
           uVar31 + -0x6423f959;
  uVar37 = uVar37 + iVar39;
  uVar35 = iVar39 + ((uVar38 >> 2 | uVar38 * 0x40000000) ^ (uVar38 >> 0xd | uVar38 * 0x80000) ^
                    (uVar38 >> 0x16 | uVar38 * 0x400)) +
                    (uVar38 & uVar40 | uVar36 & (uVar38 | uVar40));
  iVar39 = ((uVar37 >> 6 | uVar37 * 0x4000000) ^ (uVar37 >> 0xb | uVar37 * 0x200000) ^
           (uVar37 >> 0x19 | uVar37 * 0x80)) + uVar34 + (uVar41 ^ (uVar42 ^ uVar41) & uVar37) +
           uVar33 + -0x3e640e8c;
  uVar36 = uVar36 + iVar39;
  uVar34 = iVar39 + ((uVar35 >> 2 | uVar35 * 0x40000000) ^ (uVar35 >> 0xd | uVar35 * 0x80000) ^
                    (uVar35 >> 0x16 | uVar35 * 0x400)) +
                    (uVar35 & uVar38 | uVar40 & (uVar35 | uVar38));
  uVar16 = ((uVar14 >> 0x11 | uVar31 << 0xf) ^ (uVar14 >> 0x13 | uVar31 << 0xd) ^ uVar30 >> 10) +
           uVar25 + (uVar17 >> 3 ^
                    (uVar17 >> 7 | (uint)data[7] << 0x19) ^ (uVar1 >> 0x12 | uVar17 << 0xe)) +
           uVar16;
  iVar39 = ((uVar36 >> 6 | uVar36 * 0x4000000) ^ (uVar36 >> 0xb | uVar36 * 0x200000) ^
           (uVar36 >> 0x19 | uVar36 * 0x80)) + uVar41 + (uVar42 ^ (uVar37 ^ uVar42) & uVar36) +
           uVar16 + -0x1b64963f;
  uVar40 = uVar40 + iVar39;
  uVar1 = iVar39 + ((uVar34 >> 2 | uVar34 * 0x40000000) ^ (uVar34 >> 0xd | uVar34 * 0x80000) ^
                   (uVar34 >> 0x16 | uVar34 * 0x400)) +
                   (uVar34 & uVar35 | uVar38 & (uVar34 | uVar35));
  uVar17 = ((uVar15 >> 0x11 | uVar33 << 0xf) ^ (uVar15 >> 0x13 | uVar33 << 0xd) ^ uVar32 >> 10) +
           uVar26 + (uVar18 >> 3 ^
                    (uVar18 >> 7 | (uint)data[0xb] << 0x19) ^ (uVar2 >> 0x12 | uVar18 << 0xe)) +
           uVar17;
  iVar39 = ((uVar40 >> 6 | uVar40 * 0x4000000) ^ (uVar40 >> 0xb | uVar40 * 0x200000) ^
           (uVar40 >> 0x19 | uVar40 * 0x80)) + uVar42 + (uVar37 ^ (uVar36 ^ uVar37) & uVar40) +
           uVar17 + -0x1041b87a;
  uVar38 = uVar38 + iVar39;
  uVar2 = iVar39 + ((uVar1 >> 2 | uVar1 * 0x40000000) ^ (uVar1 >> 0xd | uVar1 * 0x80000) ^
                   (uVar1 >> 0x16 | uVar1 * 0x400)) + (uVar1 & uVar34 | uVar35 & (uVar1 | uVar34));
  uVar18 = ((uVar16 >> 0x11 | uVar16 * 0x8000) ^ (uVar16 >> 0x13 | uVar16 * 0x2000) ^ uVar16 >> 10)
           + uVar27 +
           (uVar19 >> 3 ^ (uVar19 >> 7 | (uint)data[0xf] << 0x19) ^ (uVar3 >> 0x12 | uVar19 << 0xe))
           + uVar18;
  iVar39 = ((uVar38 >> 6 | uVar38 * 0x4000000) ^ (uVar38 >> 0xb | uVar38 * 0x200000) ^
           (uVar38 >> 0x19 | uVar38 * 0x80)) + uVar37 + (uVar36 ^ (uVar40 ^ uVar36) & uVar38) +
           uVar18 + 0xfc19dc6;
  uVar35 = uVar35 + iVar39;
  uVar3 = iVar39 + ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
                   (uVar2 >> 0x16 | uVar2 * 0x400)) + (uVar2 & uVar1 | uVar34 & (uVar2 | uVar1));
  uVar19 = ((uVar17 >> 0x11 | uVar17 * 0x8000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000) ^ uVar17 >> 10)
           + uVar28 +
           (uVar20 >> 3 ^ (uVar20 >> 7 | (uint)data[0x13] << 0x19) ^ (uVar4 >> 0x12 | uVar20 << 0xe)
           ) + uVar19;
  iVar39 = ((uVar35 >> 6 | uVar35 * 0x4000000) ^ (uVar35 >> 0xb | uVar35 * 0x200000) ^
           (uVar35 >> 0x19 | uVar35 * 0x80)) + uVar36 + (uVar40 ^ (uVar38 ^ uVar40) & uVar35) +
           uVar19 + 0x240ca1cc;
  uVar34 = uVar34 + iVar39;
  uVar4 = iVar39 + ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
                   (uVar3 >> 0x16 | uVar3 * 0x400)) + (uVar3 & uVar2 | uVar1 & (uVar3 | uVar2));
  uVar20 = ((uVar18 >> 0x11 | uVar18 * 0x8000) ^ (uVar18 >> 0x13 | uVar18 * 0x2000) ^ uVar18 >> 10)
           + uVar29 +
           (uVar21 >> 3 ^ (uVar21 >> 7 | (uint)data[0x17] << 0x19) ^ (uVar5 >> 0x12 | uVar21 << 0xe)
           ) + uVar20;
  iVar39 = ((uVar34 >> 6 | uVar34 * 0x4000000) ^ (uVar34 >> 0xb | uVar34 * 0x200000) ^
           (uVar34 >> 0x19 | uVar34 * 0x80)) + uVar40 + (uVar38 ^ (uVar35 ^ uVar38) & uVar34) +
           uVar20 + 0x2de92c6f;
  uVar1 = uVar1 + iVar39;
  uVar5 = iVar39 + ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
                   (uVar4 >> 0x16 | uVar4 * 0x400)) + (uVar4 & uVar3 | uVar2 & (uVar4 | uVar3));
  uVar21 = ((uVar19 >> 0x11 | uVar19 * 0x8000) ^ (uVar19 >> 0x13 | uVar19 * 0x2000) ^ uVar19 >> 10)
           + uVar31 +
           (uVar22 >> 3 ^ (uVar22 >> 7 | (uint)data[0x1b] << 0x19) ^ (uVar6 >> 0x12 | uVar22 << 0xe)
           ) + uVar21;
  iVar39 = ((uVar1 >> 6 | uVar1 * 0x4000000) ^ (uVar1 >> 0xb | uVar1 * 0x200000) ^
           (uVar1 >> 0x19 | uVar1 * 0x80)) + uVar38 + (uVar35 ^ (uVar34 ^ uVar35) & uVar1) + uVar21
           + 0x4a7484aa;
  uVar2 = uVar2 + iVar39;
  uVar6 = iVar39 + ((uVar5 >> 2 | uVar5 * 0x40000000) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
                   (uVar5 >> 0x16 | uVar5 * 0x400)) + (uVar5 & uVar4 | uVar3 & (uVar5 | uVar4));
  uVar22 = ((uVar20 >> 0x11 | uVar20 * 0x8000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000) ^ uVar20 >> 10)
           + uVar33 +
           (uVar23 >> 3 ^ (uVar23 >> 7 | (uint)data[0x1f] << 0x19) ^ (uVar7 >> 0x12 | uVar23 << 0xe)
           ) + uVar22;
  iVar39 = ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
           (uVar2 >> 0x19 | uVar2 * 0x80)) + uVar35 + (uVar34 ^ (uVar1 ^ uVar34) & uVar2) + uVar22 +
           0x5cb0a9dc;
  uVar3 = uVar3 + iVar39;
  uVar7 = iVar39 + ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
                   (uVar6 >> 0x16 | uVar6 * 0x400)) + (uVar6 & uVar5 | uVar4 & (uVar6 | uVar5));
  uVar23 = ((uVar21 >> 0x11 | uVar21 * 0x8000) ^ (uVar21 >> 0x13 | uVar21 * 0x2000) ^ uVar21 >> 10)
           + uVar16 +
           (uVar24 >> 3 ^ (uVar24 >> 7 | (uint)data[0x23] << 0x19) ^ (uVar8 >> 0x12 | uVar24 << 0xe)
           ) + uVar23;
  iVar39 = ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
           (uVar3 >> 0x19 | uVar3 * 0x80)) + uVar34 + (uVar1 ^ (uVar2 ^ uVar1) & uVar3) + uVar23 +
           0x76f988da;
  uVar4 = uVar4 + iVar39;
  uVar8 = iVar39 + ((uVar7 >> 2 | uVar7 * 0x40000000) ^ (uVar7 >> 0xd | uVar7 * 0x80000) ^
                   (uVar7 >> 0x16 | uVar7 * 0x400)) + (uVar7 & uVar6 | uVar5 & (uVar7 | uVar6));
  uVar24 = ((uVar22 >> 0x11 | uVar22 * 0x8000) ^ (uVar22 >> 0x13 | uVar22 * 0x2000) ^ uVar22 >> 10)
           + uVar17 +
           (uVar25 >> 3 ^ (uVar25 >> 7 | (uint)data[0x27] << 0x19) ^ (uVar9 >> 0x12 | uVar25 << 0xe)
           ) + uVar24;
  iVar39 = ((uVar4 >> 6 | uVar4 * 0x4000000) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
           (uVar4 >> 0x19 | uVar4 * 0x80)) + uVar1 + (uVar2 ^ (uVar3 ^ uVar2) & uVar4) + uVar24 +
           -0x67c1aeae;
  uVar5 = uVar5 + iVar39;
  uVar1 = iVar39 + ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^
                   (uVar8 >> 0x16 | uVar8 * 0x400)) + (uVar8 & uVar7 | uVar6 & (uVar8 | uVar7));
  uVar25 = ((uVar23 >> 0x11 | uVar23 * 0x8000) ^ (uVar23 >> 0x13 | uVar23 * 0x2000) ^ uVar23 >> 10)
           + uVar18 +
           (uVar26 >> 3 ^
           (uVar26 >> 7 | (uint)data[0x2b] << 0x19) ^ (uVar10 >> 0x12 | uVar26 << 0xe)) + uVar25;
  iVar39 = ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
           (uVar5 >> 0x19 | uVar5 * 0x80)) + uVar2 + (uVar3 ^ (uVar4 ^ uVar3) & uVar5) + uVar25 +
           -0x57ce3993;
  uVar6 = uVar6 + iVar39;
  uVar2 = iVar39 + ((uVar1 >> 2 | uVar1 * 0x40000000) ^ (uVar1 >> 0xd | uVar1 * 0x80000) ^
                   (uVar1 >> 0x16 | uVar1 * 0x400)) + (uVar1 & uVar8 | uVar7 & (uVar1 | uVar8));
  uVar26 = ((uVar24 >> 0x11 | uVar24 * 0x8000) ^ (uVar24 >> 0x13 | uVar24 * 0x2000) ^ uVar24 >> 10)
           + uVar19 +
           (uVar27 >> 3 ^
           (uVar27 >> 7 | (uint)data[0x2f] << 0x19) ^ (uVar11 >> 0x12 | uVar27 << 0xe)) + uVar26;
  iVar39 = ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
           (uVar6 >> 0x19 | uVar6 * 0x80)) + uVar3 + (uVar4 ^ (uVar5 ^ uVar4) & uVar6) + uVar26 +
           -0x4ffcd838;
  uVar7 = uVar7 + iVar39;
  uVar3 = iVar39 + ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
                   (uVar2 >> 0x16 | uVar2 * 0x400)) + (uVar2 & uVar1 | uVar8 & (uVar2 | uVar1));
  uVar27 = ((uVar25 >> 0x11 | uVar25 * 0x8000) ^ (uVar25 >> 0x13 | uVar25 * 0x2000) ^ uVar25 >> 10)
           + uVar20 +
           (uVar28 >> 3 ^
           (uVar28 >> 7 | (uint)data[0x33] << 0x19) ^ (uVar12 >> 0x12 | uVar28 << 0xe)) + uVar27;
  iVar39 = ((uVar7 >> 6 | uVar7 * 0x4000000) ^ (uVar7 >> 0xb | uVar7 * 0x200000) ^
           (uVar7 >> 0x19 | uVar7 * 0x80)) + uVar4 + (uVar5 ^ (uVar6 ^ uVar5) & uVar7) + uVar27 +
           -0x40a68039;
  uVar8 = uVar8 + iVar39;
  uVar4 = iVar39 + ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
                   (uVar3 >> 0x16 | uVar3 * 0x400)) + (uVar3 & uVar2 | uVar1 & (uVar3 | uVar2));
  uVar28 = ((uVar26 >> 0x11 | uVar26 * 0x8000) ^ (uVar26 >> 0x13 | uVar26 * 0x2000) ^ uVar26 >> 10)
           + uVar21 +
           (uVar29 >> 3 ^
           (uVar29 >> 7 | (uint)data[0x37] << 0x19) ^ (uVar13 >> 0x12 | uVar29 << 0xe)) + uVar28;
  iVar39 = ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^
           (uVar8 >> 0x19 | uVar8 * 0x80)) + uVar5 + (uVar6 ^ (uVar7 ^ uVar6) & uVar8) + uVar28 +
           -0x391ff40d;
  uVar1 = uVar1 + iVar39;
  uVar5 = iVar39 + ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
                   (uVar4 >> 0x16 | uVar4 * 0x400)) + (uVar4 & uVar3 | uVar2 & (uVar4 | uVar3));
  uVar29 = ((uVar27 >> 0x11 | uVar27 * 0x8000) ^ (uVar27 >> 0x13 | uVar27 * 0x2000) ^ uVar27 >> 10)
           + uVar22 +
           (uVar31 >> 3 ^
           (uVar31 >> 7 | (uint)data[0x3b] << 0x19) ^ (uVar14 >> 0x12 | uVar31 << 0xe)) + uVar29;
  iVar39 = ((uVar1 >> 6 | uVar1 * 0x4000000) ^ (uVar1 >> 0xb | uVar1 * 0x200000) ^
           (uVar1 >> 0x19 | uVar1 * 0x80)) + uVar6 + (uVar7 ^ (uVar8 ^ uVar7) & uVar1) + uVar29 +
           -0x2a586eb9;
  uVar2 = uVar2 + iVar39;
  uVar6 = iVar39 + ((uVar5 >> 2 | uVar5 * 0x40000000) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
                   (uVar5 >> 0x16 | uVar5 * 0x400)) + (uVar5 & uVar4 | uVar3 & (uVar5 | uVar4));
  uVar31 = ((uVar28 >> 0x11 | uVar28 * 0x8000) ^ (uVar28 >> 0x13 | uVar28 * 0x2000) ^ uVar28 >> 10)
           + uVar23 +
           (uVar33 >> 3 ^
           (uVar33 >> 7 | (uint)data[0x3f] << 0x19) ^ (uVar15 >> 0x12 | uVar33 << 0xe)) + uVar31;
  iVar39 = ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
           (uVar2 >> 0x19 | uVar2 * 0x80)) + uVar7 + (uVar8 ^ (uVar1 ^ uVar8) & uVar2) + uVar31 +
           0x6ca6351;
  uVar3 = uVar3 + iVar39;
  uVar7 = iVar39 + ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
                   (uVar6 >> 0x16 | uVar6 * 0x400)) + (uVar6 & uVar5 | uVar4 & (uVar6 | uVar5));
  uVar33 = ((uVar29 >> 0x11 | uVar29 * 0x8000) ^ (uVar29 >> 0x13 | uVar29 * 0x2000) ^ uVar29 >> 10)
           + uVar24 +
           (uVar16 >> 3 ^ (uVar16 >> 7 | uVar16 * 0x2000000) ^ (uVar16 >> 0x12 | uVar16 * 0x4000)) +
           uVar33;
  iVar39 = ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
           (uVar3 >> 0x19 | uVar3 * 0x80)) + uVar8 + (uVar1 ^ (uVar2 ^ uVar1) & uVar3) + uVar33 +
           0x14292967;
  uVar4 = uVar4 + iVar39;
  uVar8 = iVar39 + ((uVar7 >> 2 | uVar7 * 0x40000000) ^ (uVar7 >> 0xd | uVar7 * 0x80000) ^
                   (uVar7 >> 0x16 | uVar7 * 0x400)) + (uVar7 & uVar6 | uVar5 & (uVar7 | uVar6));
  uVar16 = ((uVar31 >> 0x11 | uVar31 * 0x8000) ^ (uVar31 >> 0x13 | uVar31 * 0x2000) ^ uVar31 >> 10)
           + uVar25 +
           (uVar17 >> 3 ^ (uVar17 >> 7 | uVar17 * 0x2000000) ^ (uVar17 >> 0x12 | uVar17 * 0x4000)) +
           uVar16;
  iVar39 = ((uVar4 >> 6 | uVar4 * 0x4000000) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
           (uVar4 >> 0x19 | uVar4 * 0x80)) + uVar1 + (uVar2 ^ (uVar3 ^ uVar2) & uVar4) + uVar16 +
           0x27b70a85;
  uVar5 = uVar5 + iVar39;
  uVar1 = iVar39 + ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^
                   (uVar8 >> 0x16 | uVar8 * 0x400)) + (uVar8 & uVar7 | uVar6 & (uVar8 | uVar7));
  uVar17 = ((uVar33 >> 0x11 | uVar33 * 0x8000) ^ (uVar33 >> 0x13 | uVar33 * 0x2000) ^ uVar33 >> 10)
           + uVar26 +
           (uVar18 >> 3 ^ (uVar18 >> 7 | uVar18 * 0x2000000) ^ (uVar18 >> 0x12 | uVar18 * 0x4000)) +
           uVar17;
  iVar39 = ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
           (uVar5 >> 0x19 | uVar5 * 0x80)) + uVar2 + (uVar3 ^ (uVar4 ^ uVar3) & uVar5) + uVar17 +
           0x2e1b2138;
  uVar6 = uVar6 + iVar39;
  uVar2 = iVar39 + ((uVar1 >> 2 | uVar1 * 0x40000000) ^ (uVar1 >> 0xd | uVar1 * 0x80000) ^
                   (uVar1 >> 0x16 | uVar1 * 0x400)) + (uVar1 & uVar8 | uVar7 & (uVar1 | uVar8));
  uVar18 = ((uVar16 >> 0x11 | uVar16 * 0x8000) ^ (uVar16 >> 0x13 | uVar16 * 0x2000) ^ uVar16 >> 10)
           + uVar27 +
           (uVar19 >> 3 ^ (uVar19 >> 7 | uVar19 * 0x2000000) ^ (uVar19 >> 0x12 | uVar19 * 0x4000)) +
           uVar18;
  iVar39 = ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
           (uVar6 >> 0x19 | uVar6 * 0x80)) + uVar3 + (uVar4 ^ (uVar5 ^ uVar4) & uVar6) + uVar18 +
           0x4d2c6dfc;
  uVar7 = uVar7 + iVar39;
  uVar3 = iVar39 + ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
                   (uVar2 >> 0x16 | uVar2 * 0x400)) + (uVar2 & uVar1 | uVar8 & (uVar2 | uVar1));
  uVar19 = ((uVar17 >> 0x11 | uVar17 * 0x8000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000) ^ uVar17 >> 10)
           + uVar28 +
           (uVar20 >> 3 ^ (uVar20 >> 7 | uVar20 * 0x2000000) ^ (uVar20 >> 0x12 | uVar20 * 0x4000)) +
           uVar19;
  iVar39 = ((uVar7 >> 6 | uVar7 * 0x4000000) ^ (uVar7 >> 0xb | uVar7 * 0x200000) ^
           (uVar7 >> 0x19 | uVar7 * 0x80)) + uVar4 + (uVar5 ^ (uVar6 ^ uVar5) & uVar7) + uVar19 +
           0x53380d13;
  uVar8 = uVar8 + iVar39;
  uVar4 = iVar39 + ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
                   (uVar3 >> 0x16 | uVar3 * 0x400)) + (uVar3 & uVar2 | uVar1 & (uVar3 | uVar2));
  uVar20 = ((uVar18 >> 0x11 | uVar18 * 0x8000) ^ (uVar18 >> 0x13 | uVar18 * 0x2000) ^ uVar18 >> 10)
           + uVar29 +
           (uVar21 >> 3 ^ (uVar21 >> 7 | uVar21 * 0x2000000) ^ (uVar21 >> 0x12 | uVar21 * 0x4000)) +
           uVar20;
  iVar39 = ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^
           (uVar8 >> 0x19 | uVar8 * 0x80)) + uVar5 + (uVar6 ^ (uVar7 ^ uVar6) & uVar8) + uVar20 +
           0x650a7354;
  uVar1 = uVar1 + iVar39;
  uVar5 = iVar39 + ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
                   (uVar4 >> 0x16 | uVar4 * 0x400)) + (uVar4 & uVar3 | uVar2 & (uVar4 | uVar3));
  uVar21 = ((uVar19 >> 0x11 | uVar19 * 0x8000) ^ (uVar19 >> 0x13 | uVar19 * 0x2000) ^ uVar19 >> 10)
           + uVar31 +
           (uVar22 >> 3 ^ (uVar22 >> 7 | uVar22 * 0x2000000) ^ (uVar22 >> 0x12 | uVar22 * 0x4000)) +
           uVar21;
  iVar39 = ((uVar1 >> 6 | uVar1 * 0x4000000) ^ (uVar1 >> 0xb | uVar1 * 0x200000) ^
           (uVar1 >> 0x19 | uVar1 * 0x80)) + uVar6 + (uVar7 ^ (uVar8 ^ uVar7) & uVar1) + uVar21 +
           0x766a0abb;
  uVar2 = uVar2 + iVar39;
  uVar6 = iVar39 + ((uVar5 >> 2 | uVar5 * 0x40000000) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
                   (uVar5 >> 0x16 | uVar5 * 0x400)) + (uVar5 & uVar4 | uVar3 & (uVar5 | uVar4));
  uVar22 = ((uVar20 >> 0x11 | uVar20 * 0x8000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000) ^ uVar20 >> 10)
           + uVar33 +
           (uVar23 >> 3 ^ (uVar23 >> 7 | uVar23 * 0x2000000) ^ (uVar23 >> 0x12 | uVar23 * 0x4000)) +
           uVar22;
  iVar39 = ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
           (uVar2 >> 0x19 | uVar2 * 0x80)) + uVar7 + (uVar8 ^ (uVar1 ^ uVar8) & uVar2) + uVar22 +
           -0x7e3d36d2;
  uVar3 = uVar3 + iVar39;
  uVar7 = iVar39 + ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
                   (uVar6 >> 0x16 | uVar6 * 0x400)) + (uVar6 & uVar5 | uVar4 & (uVar6 | uVar5));
  uVar23 = ((uVar21 >> 0x11 | uVar21 * 0x8000) ^ (uVar21 >> 0x13 | uVar21 * 0x2000) ^ uVar21 >> 10)
           + uVar16 +
           (uVar24 >> 3 ^ (uVar24 >> 7 | uVar24 * 0x2000000) ^ (uVar24 >> 0x12 | uVar24 * 0x4000)) +
           uVar23;
  iVar39 = ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
           (uVar3 >> 0x19 | uVar3 * 0x80)) + uVar8 + (uVar1 ^ (uVar2 ^ uVar1) & uVar3) + uVar23 +
           -0x6d8dd37b;
  uVar4 = uVar4 + iVar39;
  uVar8 = iVar39 + ((uVar7 >> 2 | uVar7 * 0x40000000) ^ (uVar7 >> 0xd | uVar7 * 0x80000) ^
                   (uVar7 >> 0x16 | uVar7 * 0x400)) + (uVar7 & uVar6 | uVar5 & (uVar7 | uVar6));
  uVar24 = ((uVar22 >> 0x11 | uVar22 * 0x8000) ^ (uVar22 >> 0x13 | uVar22 * 0x2000) ^ uVar22 >> 10)
           + uVar17 +
           (uVar25 >> 3 ^ (uVar25 >> 7 | uVar25 * 0x2000000) ^ (uVar25 >> 0x12 | uVar25 * 0x4000)) +
           uVar24;
  iVar39 = ((uVar4 >> 6 | uVar4 * 0x4000000) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
           (uVar4 >> 0x19 | uVar4 * 0x80)) + uVar1 + (uVar2 ^ (uVar3 ^ uVar2) & uVar4) + uVar24 +
           -0x5d40175f;
  uVar5 = uVar5 + iVar39;
  uVar1 = iVar39 + ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^
                   (uVar8 >> 0x16 | uVar8 * 0x400)) + (uVar8 & uVar7 | uVar6 & (uVar8 | uVar7));
  uVar25 = ((uVar23 >> 0x11 | uVar23 * 0x8000) ^ (uVar23 >> 0x13 | uVar23 * 0x2000) ^ uVar23 >> 10)
           + uVar18 +
           (uVar26 >> 3 ^ (uVar26 >> 7 | uVar26 * 0x2000000) ^ (uVar26 >> 0x12 | uVar26 * 0x4000)) +
           uVar25;
  iVar39 = ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
           (uVar5 >> 0x19 | uVar5 * 0x80)) + uVar2 + (uVar3 ^ (uVar4 ^ uVar3) & uVar5) + uVar25 +
           -0x57e599b5;
  uVar6 = uVar6 + iVar39;
  uVar2 = iVar39 + ((uVar1 >> 2 | uVar1 * 0x40000000) ^ (uVar1 >> 0xd | uVar1 * 0x80000) ^
                   (uVar1 >> 0x16 | uVar1 * 0x400)) + (uVar1 & uVar8 | uVar7 & (uVar1 | uVar8));
  uVar26 = ((uVar24 >> 0x11 | uVar24 * 0x8000) ^ (uVar24 >> 0x13 | uVar24 * 0x2000) ^ uVar24 >> 10)
           + uVar19 +
           (uVar27 >> 3 ^ (uVar27 >> 7 | uVar27 * 0x2000000) ^ (uVar27 >> 0x12 | uVar27 * 0x4000)) +
           uVar26;
  iVar39 = ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
           (uVar6 >> 0x19 | uVar6 * 0x80)) + uVar3 + (uVar4 ^ (uVar5 ^ uVar4) & uVar6) + uVar26 +
           -0x3db47490;
  uVar7 = uVar7 + iVar39;
  uVar3 = iVar39 + ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
                   (uVar2 >> 0x16 | uVar2 * 0x400)) + (uVar2 & uVar1 | uVar8 & (uVar2 | uVar1));
  uVar27 = ((uVar25 >> 0x11 | uVar25 * 0x8000) ^ (uVar25 >> 0x13 | uVar25 * 0x2000) ^ uVar25 >> 10)
           + uVar20 +
           (uVar28 >> 3 ^ (uVar28 >> 7 | uVar28 * 0x2000000) ^ (uVar28 >> 0x12 | uVar28 * 0x4000)) +
           uVar27;
  iVar39 = ((uVar7 >> 6 | uVar7 * 0x4000000) ^ (uVar7 >> 0xb | uVar7 * 0x200000) ^
           (uVar7 >> 0x19 | uVar7 * 0x80)) + uVar4 + (uVar5 ^ (uVar6 ^ uVar5) & uVar7) + uVar27 +
           -0x3893ae5d;
  uVar8 = uVar8 + iVar39;
  uVar4 = iVar39 + ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
                   (uVar3 >> 0x16 | uVar3 * 0x400)) + (uVar3 & uVar2 | uVar1 & (uVar3 | uVar2));
  uVar28 = ((uVar26 >> 0x11 | uVar26 * 0x8000) ^ (uVar26 >> 0x13 | uVar26 * 0x2000) ^ uVar26 >> 10)
           + uVar21 +
           (uVar29 >> 3 ^ (uVar29 >> 7 | uVar29 * 0x2000000) ^ (uVar29 >> 0x12 | uVar29 * 0x4000)) +
           uVar28;
  iVar39 = ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^
           (uVar8 >> 0x19 | uVar8 * 0x80)) + uVar5 + (uVar6 ^ (uVar7 ^ uVar6) & uVar8) + uVar28 +
           -0x2e6d17e7;
  uVar1 = uVar1 + iVar39;
  uVar5 = iVar39 + ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
                   (uVar4 >> 0x16 | uVar4 * 0x400)) + (uVar4 & uVar3 | uVar2 & (uVar4 | uVar3));
  uVar29 = ((uVar27 >> 0x11 | uVar27 * 0x8000) ^ (uVar27 >> 0x13 | uVar27 * 0x2000) ^ uVar27 >> 10)
           + uVar22 +
           (uVar31 >> 3 ^ (uVar31 >> 7 | uVar31 * 0x2000000) ^ (uVar31 >> 0x12 | uVar31 * 0x4000)) +
           uVar29;
  iVar39 = ((uVar1 >> 6 | uVar1 * 0x4000000) ^ (uVar1 >> 0xb | uVar1 * 0x200000) ^
           (uVar1 >> 0x19 | uVar1 * 0x80)) + uVar6 + (uVar7 ^ (uVar8 ^ uVar7) & uVar1) + uVar29 +
           -0x2966f9dc;
  uVar2 = uVar2 + iVar39;
  uVar6 = iVar39 + ((uVar5 >> 2 | uVar5 * 0x40000000) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
                   (uVar5 >> 0x16 | uVar5 * 0x400)) + (uVar5 & uVar4 | uVar3 & (uVar5 | uVar4));
  uVar31 = ((uVar28 >> 0x11 | uVar28 * 0x8000) ^ (uVar28 >> 0x13 | uVar28 * 0x2000) ^ uVar28 >> 10)
           + uVar23 +
           (uVar33 >> 3 ^ (uVar33 >> 7 | uVar33 * 0x2000000) ^ (uVar33 >> 0x12 | uVar33 * 0x4000)) +
           uVar31;
  iVar39 = ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
           (uVar2 >> 0x19 | uVar2 * 0x80)) + uVar7 + (uVar8 ^ (uVar1 ^ uVar8) & uVar2) + uVar31 +
           -0xbf1ca7b;
  uVar3 = uVar3 + iVar39;
  uVar7 = iVar39 + ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
                   (uVar6 >> 0x16 | uVar6 * 0x400)) + (uVar6 & uVar5 | uVar4 & (uVar6 | uVar5));
  uVar33 = ((uVar29 >> 0x11 | uVar29 * 0x8000) ^ (uVar29 >> 0x13 | uVar29 * 0x2000) ^ uVar29 >> 10)
           + uVar24 +
           (uVar16 >> 3 ^ (uVar16 >> 7 | uVar16 * 0x2000000) ^ (uVar16 >> 0x12 | uVar16 * 0x4000)) +
           uVar33;
  iVar39 = ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
           (uVar3 >> 0x19 | uVar3 * 0x80)) + uVar8 + (uVar1 ^ (uVar2 ^ uVar1) & uVar3) + uVar33 +
           0x106aa070;
  uVar4 = uVar4 + iVar39;
  uVar8 = iVar39 + ((uVar7 >> 2 | uVar7 * 0x40000000) ^ (uVar7 >> 0xd | uVar7 * 0x80000) ^
                   (uVar7 >> 0x16 | uVar7 * 0x400)) + (uVar7 & uVar6 | uVar5 & (uVar7 | uVar6));
  uVar16 = ((uVar31 >> 0x11 | uVar31 * 0x8000) ^ (uVar31 >> 0x13 | uVar31 * 0x2000) ^ uVar31 >> 10)
           + uVar25 +
           (uVar17 >> 3 ^ (uVar17 >> 7 | uVar17 * 0x2000000) ^ (uVar17 >> 0x12 | uVar17 * 0x4000)) +
           uVar16;
  iVar39 = ((uVar4 >> 6 | uVar4 * 0x4000000) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
           (uVar4 >> 0x19 | uVar4 * 0x80)) + uVar1 + (uVar2 ^ (uVar3 ^ uVar2) & uVar4) + uVar16 +
           0x19a4c116;
  uVar5 = uVar5 + iVar39;
  uVar1 = iVar39 + ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^
                   (uVar8 >> 0x16 | uVar8 * 0x400)) + (uVar8 & uVar7 | uVar6 & (uVar8 | uVar7));
  uVar17 = ((uVar33 >> 0x11 | uVar33 * 0x8000) ^ (uVar33 >> 0x13 | uVar33 * 0x2000) ^ uVar33 >> 10)
           + uVar26 +
           (uVar18 >> 3 ^ (uVar18 >> 7 | uVar18 * 0x2000000) ^ (uVar18 >> 0x12 | uVar18 * 0x4000)) +
           uVar17;
  iVar39 = ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
           (uVar5 >> 0x19 | uVar5 * 0x80)) + uVar2 + (uVar3 ^ (uVar4 ^ uVar3) & uVar5) + uVar17 +
           0x1e376c08;
  uVar6 = uVar6 + iVar39;
  uVar2 = iVar39 + ((uVar1 >> 2 | uVar1 * 0x40000000) ^ (uVar1 >> 0xd | uVar1 * 0x80000) ^
                   (uVar1 >> 0x16 | uVar1 * 0x400)) + (uVar1 & uVar8 | uVar7 & (uVar1 | uVar8));
  uVar18 = ((uVar16 >> 0x11 | uVar16 * 0x8000) ^ (uVar16 >> 0x13 | uVar16 * 0x2000) ^ uVar16 >> 10)
           + uVar27 +
           (uVar19 >> 3 ^ (uVar19 >> 7 | uVar19 * 0x2000000) ^ (uVar19 >> 0x12 | uVar19 * 0x4000)) +
           uVar18;
  iVar39 = ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
           (uVar6 >> 0x19 | uVar6 * 0x80)) + uVar3 + (uVar4 ^ (uVar5 ^ uVar4) & uVar6) + uVar18 +
           0x2748774c;
  uVar7 = uVar7 + iVar39;
  uVar3 = iVar39 + ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
                   (uVar2 >> 0x16 | uVar2 * 0x400)) + (uVar2 & uVar1 | uVar8 & (uVar2 | uVar1));
  uVar19 = ((uVar17 >> 0x11 | uVar17 * 0x8000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000) ^ uVar17 >> 10)
           + uVar28 +
           (uVar20 >> 3 ^ (uVar20 >> 7 | uVar20 * 0x2000000) ^ (uVar20 >> 0x12 | uVar20 * 0x4000)) +
           uVar19;
  iVar39 = ((uVar7 >> 6 | uVar7 * 0x4000000) ^ (uVar7 >> 0xb | uVar7 * 0x200000) ^
           (uVar7 >> 0x19 | uVar7 * 0x80)) + uVar4 + (uVar5 ^ (uVar6 ^ uVar5) & uVar7) + uVar19 +
           0x34b0bcb5;
  uVar8 = uVar8 + iVar39;
  uVar4 = iVar39 + ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
                   (uVar3 >> 0x16 | uVar3 * 0x400)) + (uVar3 & uVar2 | uVar1 & (uVar3 | uVar2));
  uVar20 = ((uVar18 >> 0x11 | uVar18 * 0x8000) ^ (uVar18 >> 0x13 | uVar18 * 0x2000) ^ uVar18 >> 10)
           + uVar29 +
           (uVar21 >> 3 ^ (uVar21 >> 7 | uVar21 * 0x2000000) ^ (uVar21 >> 0x12 | uVar21 * 0x4000)) +
           uVar20;
  iVar39 = ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^
           (uVar8 >> 0x19 | uVar8 * 0x80)) + uVar5 + (uVar6 ^ (uVar7 ^ uVar6) & uVar8) + uVar20 +
           0x391c0cb3;
  uVar1 = uVar1 + iVar39;
  uVar5 = iVar39 + ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
                   (uVar4 >> 0x16 | uVar4 * 0x400)) + (uVar4 & uVar3 | uVar2 & (uVar4 | uVar3));
  uVar21 = ((uVar19 >> 0x11 | uVar19 * 0x8000) ^ (uVar19 >> 0x13 | uVar19 * 0x2000) ^ uVar19 >> 10)
           + uVar31 +
           (uVar22 >> 3 ^ (uVar22 >> 7 | uVar22 * 0x2000000) ^ (uVar22 >> 0x12 | uVar22 * 0x4000)) +
           uVar21;
  iVar39 = ((uVar1 >> 6 | uVar1 * 0x4000000) ^ (uVar1 >> 0xb | uVar1 * 0x200000) ^
           (uVar1 >> 0x19 | uVar1 * 0x80)) + uVar6 + (uVar7 ^ (uVar8 ^ uVar7) & uVar1) + uVar21 +
           0x4ed8aa4a;
  uVar2 = uVar2 + iVar39;
  uVar6 = iVar39 + ((uVar5 >> 2 | uVar5 * 0x40000000) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
                   (uVar5 >> 0x16 | uVar5 * 0x400)) + (uVar5 & uVar4 | uVar3 & (uVar5 | uVar4));
  uVar22 = ((uVar20 >> 0x11 | uVar20 * 0x8000) ^ (uVar20 >> 0x13 | uVar20 * 0x2000) ^ uVar20 >> 10)
           + uVar33 +
           (uVar23 >> 3 ^ (uVar23 >> 7 | uVar23 * 0x2000000) ^ (uVar23 >> 0x12 | uVar23 * 0x4000)) +
           uVar22;
  iVar39 = ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
           (uVar2 >> 0x19 | uVar2 * 0x80)) + uVar7 + (uVar8 ^ (uVar1 ^ uVar8) & uVar2) + uVar22 +
           0x5b9cca4f;
  uVar3 = uVar3 + iVar39;
  uVar7 = iVar39 + ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
                   (uVar6 >> 0x16 | uVar6 * 0x400)) + (uVar6 & uVar5 | uVar4 & (uVar6 | uVar5));
  uVar23 = ((uVar21 >> 0x11 | uVar21 * 0x8000) ^ (uVar21 >> 0x13 | uVar21 * 0x2000) ^ uVar21 >> 10)
           + uVar16 +
           (uVar24 >> 3 ^ (uVar24 >> 7 | uVar24 * 0x2000000) ^ (uVar24 >> 0x12 | uVar24 * 0x4000)) +
           uVar23;
  iVar39 = ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
           (uVar3 >> 0x19 | uVar3 * 0x80)) + uVar8 + (uVar1 ^ (uVar2 ^ uVar1) & uVar3) + uVar23 +
           0x682e6ff3;
  uVar4 = uVar4 + iVar39;
  uVar8 = iVar39 + ((uVar7 >> 2 | uVar7 * 0x40000000) ^ (uVar7 >> 0xd | uVar7 * 0x80000) ^
                   (uVar7 >> 0x16 | uVar7 * 0x400)) + (uVar7 & uVar6 | uVar5 & (uVar7 | uVar6));
  uVar24 = ((uVar22 >> 0x11 | uVar22 * 0x8000) ^ (uVar22 >> 0x13 | uVar22 * 0x2000) ^ uVar22 >> 10)
           + uVar17 +
           (uVar25 >> 3 ^ (uVar25 >> 7 | uVar25 * 0x2000000) ^ (uVar25 >> 0x12 | uVar25 * 0x4000)) +
           uVar24;
  iVar39 = ((uVar4 >> 6 | uVar4 * 0x4000000) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
           (uVar4 >> 0x19 | uVar4 * 0x80)) + uVar1 + (uVar2 ^ (uVar3 ^ uVar2) & uVar4) + uVar24 +
           0x748f82ee;
  uVar5 = uVar5 + iVar39;
  uVar9 = iVar39 + ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^
                   (uVar8 >> 0x16 | uVar8 * 0x400)) + (uVar8 & uVar7 | uVar6 & (uVar8 | uVar7));
  uVar25 = ((uVar23 >> 0x11 | uVar23 * 0x8000) ^ (uVar23 >> 0x13 | uVar23 * 0x2000) ^ uVar23 >> 10)
           + uVar18 +
           (uVar26 >> 3 ^ (uVar26 >> 7 | uVar26 * 0x2000000) ^ (uVar26 >> 0x12 | uVar26 * 0x4000)) +
           uVar25;
  iVar39 = ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
           (uVar5 >> 0x19 | uVar5 * 0x80)) + uVar2 + (uVar3 ^ (uVar4 ^ uVar3) & uVar5) + uVar25 +
           0x78a5636f;
  uVar6 = uVar6 + iVar39;
  uVar10 = iVar39 + ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
                    (uVar9 >> 0x16 | uVar9 * 0x400)) + (uVar9 & uVar8 | uVar7 & (uVar9 | uVar8));
  uVar26 = ((uVar24 >> 0x11 | uVar24 * 0x8000) ^ (uVar24 >> 0x13 | uVar24 * 0x2000) ^ uVar24 >> 10)
           + uVar19 +
           (uVar27 >> 3 ^ (uVar27 >> 7 | uVar27 * 0x2000000) ^ (uVar27 >> 0x12 | uVar27 * 0x4000)) +
           uVar26;
  iVar39 = ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
           (uVar6 >> 0x19 | uVar6 * 0x80)) + uVar3 + (uVar4 ^ (uVar5 ^ uVar4) & uVar6) + uVar26 +
           -0x7b3787ec;
  uVar7 = uVar7 + iVar39;
  uVar11 = iVar39 + ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
                    (uVar10 >> 0x16 | uVar10 * 0x400)) + (uVar10 & uVar9 | uVar8 & (uVar10 | uVar9))
  ;
  uVar27 = ((uVar25 >> 0x11 | uVar25 * 0x8000) ^ (uVar25 >> 0x13 | uVar25 * 0x2000) ^ uVar25 >> 10)
           + uVar20 +
           (uVar28 >> 3 ^ (uVar28 >> 7 | uVar28 * 0x2000000) ^ (uVar28 >> 0x12 | uVar28 * 0x4000)) +
           uVar27;
  iVar39 = ((uVar7 >> 6 | uVar7 * 0x4000000) ^ (uVar7 >> 0xb | uVar7 * 0x200000) ^
           (uVar7 >> 0x19 | uVar7 * 0x80)) + uVar4 + (uVar5 ^ (uVar6 ^ uVar5) & uVar7) + uVar27 +
           -0x7338fdf8;
  uVar8 = uVar8 + iVar39;
  uVar1 = iVar39 + ((uVar11 >> 2 | uVar11 * 0x40000000) ^ (uVar11 >> 0xd | uVar11 * 0x80000) ^
                   (uVar11 >> 0x16 | uVar11 * 0x400)) +
                   (uVar11 & uVar10 | uVar9 & (uVar11 | uVar10));
  uVar28 = ((uVar26 >> 0x11 | uVar26 * 0x8000) ^ (uVar26 >> 0x13 | uVar26 * 0x2000) ^ uVar26 >> 10)
           + uVar21 +
           (uVar29 >> 3 ^ (uVar29 >> 7 | uVar29 * 0x2000000) ^ (uVar29 >> 0x12 | uVar29 * 0x4000)) +
           uVar28;
  iVar39 = ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^
           (uVar8 >> 0x19 | uVar8 * 0x80)) + uVar5 + (uVar6 ^ (uVar7 ^ uVar6) & uVar8) + uVar28 +
           -0x6f410006;
  uVar9 = uVar9 + iVar39;
  uVar2 = iVar39 + ((uVar1 >> 2 | uVar1 * 0x40000000) ^ (uVar1 >> 0xd | uVar1 * 0x80000) ^
                   (uVar1 >> 0x16 | uVar1 * 0x400)) + (uVar1 & uVar11 | uVar10 & (uVar1 | uVar11));
  uVar29 = ((uVar27 >> 0x11 | uVar27 * 0x8000) ^ (uVar27 >> 0x13 | uVar27 * 0x2000) ^ uVar27 >> 10)
           + uVar22 +
           (uVar31 >> 3 ^ (uVar31 >> 7 | uVar31 * 0x2000000) ^ (uVar31 >> 0x12 | uVar31 * 0x4000)) +
           uVar29;
  iVar39 = ((uVar9 >> 6 | uVar9 * 0x4000000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
           (uVar9 >> 0x19 | uVar9 * 0x80)) + uVar6 + (uVar7 ^ (uVar8 ^ uVar7) & uVar9) + uVar29 +
           -0x5baf9315;
  uVar10 = uVar10 + iVar39;
  uVar3 = iVar39 + ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
                   (uVar2 >> 0x16 | uVar2 * 0x400)) + (uVar2 & uVar1 | uVar11 & (uVar2 | uVar1));
  iVar39 = ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
           (uVar10 >> 0x19 | uVar10 * 0x80)) + uVar7 + (uVar8 ^ (uVar9 ^ uVar8) & uVar10) +
           ((uVar28 >> 0x11 | uVar28 * 0x8000) ^ (uVar28 >> 0x13 | uVar28 * 0x2000) ^ uVar28 >> 10)
           + uVar23 +
           (uVar33 >> 3 ^ (uVar33 >> 7 | uVar33 * 0x2000000) ^ (uVar33 >> 0x12 | uVar33 * 0x4000)) +
           uVar31 + -0x41065c09;
  uVar11 = uVar11 + iVar39;
  uVar4 = iVar39 + ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
                   (uVar3 >> 0x16 | uVar3 * 0x400)) + (uVar3 & uVar2 | uVar1 & (uVar3 | uVar2));
  iVar39 = ((uVar11 >> 6 | uVar11 * 0x4000000) ^ (uVar11 >> 0xb | uVar11 * 0x200000) ^
           (uVar11 >> 0x19 | uVar11 * 0x80)) + uVar8 + (uVar9 ^ (uVar10 ^ uVar9) & uVar11) +
           ((uVar29 >> 0x11 | uVar29 * 0x8000) ^ (uVar29 >> 0x13 | uVar29 * 0x2000) ^ uVar29 >> 10)
           + uVar24 +
           (uVar16 >> 3 ^ (uVar16 >> 7 | uVar16 * 0x2000000) ^ (uVar16 >> 0x12 | uVar16 * 0x4000)) +
           uVar33 + -0x398e870e;
  ctx->state[0] =
       ctx->state[0] +
       iVar39 + ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
                (uVar4 >> 0x16 | uVar4 * 0x400)) + (uVar4 & uVar3 | uVar2 & (uVar4 | uVar3));
  ctx->state[1] = ctx->state[1] + uVar4;
  ctx->state[2] = ctx->state[2] + uVar3;
  ctx->state[3] = ctx->state[3] + uVar2;
  ctx->state[4] = ctx->state[4] + uVar1 + iVar39;
  ctx->state[5] = ctx->state[5] + uVar11;
  ctx->state[6] = ctx->state[6] + uVar10;
  ctx->state[7] = ctx->state[7] + uVar9;
  return;
}

