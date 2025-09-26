
/* WARNING: Removing unreachable block (ram,0x000eddc2) */
/* WARNING: Removing unreachable block (ram,0x000ede98) */
/* WARNING: Removing unreachable block (ram,0x000edeae) */
/* WARNING: Removing unreachable block (ram,0x000edea2) */
/* WARNING: Removing unreachable block (ram,0x000edd3c) */
/* WARNING: Removing unreachable block (ram,0x000edd52) */
/* WARNING: Removing unreachable block (ram,0x000edd46) */
/* WARNING: Removing unreachable block (ram,0x000edc8e) */
/* WARNING: Removing unreachable block (ram,0x000edca4) */
/* WARNING: Removing unreachable block (ram,0x000ed390) */
/* WARNING: Removing unreachable block (ram,0x000ed23c) */
/* WARNING: Removing unreachable block (ram,0x000ed252) */
/* WARNING: Removing unreachable block (ram,0x000ed244) */
/* WARNING: Removing unreachable block (ram,0x000ed2d4) */
/* WARNING: Removing unreachable block (ram,0x000ed2cc) */
/* WARNING: Removing unreachable block (ram,0x000ed2e2) */
/* WARNING: Removing unreachable block (ram,0x000ed35c) */
/* WARNING: Removing unreachable block (ram,0x000ed372) */
/* WARNING: Removing unreachable block (ram,0x000ed364) */
/* WARNING: Removing unreachable block (ram,0x000ed3f4) */
/* WARNING: Removing unreachable block (ram,0x000ed40e) */
/* WARNING: Removing unreachable block (ram,0x000ed3fe) */
/* WARNING: Removing unreachable block (ram,0x000ed300) */
/* WARNING: Removing unreachable block (ram,0x000ed270) */
/* WARNING: Removing unreachable block (ram,0x000ed950) */
/* WARNING: Removing unreachable block (ram,0x000ed980) */
/* WARNING: Removing unreachable block (ram,0x000ed95a) */
/* WARNING: Removing unreachable block (ram,0x000ed938) */
/* WARNING: Removing unreachable block (ram,0x000ed8b8) */
/* WARNING: Removing unreachable block (ram,0x000ed7f4) */
/* WARNING: Removing unreachable block (ram,0x000ed80a) */
/* WARNING: Removing unreachable block (ram,0x000ed7fe) */
/* WARNING: Removing unreachable block (ram,0x000ed746) */
/* WARNING: Removing unreachable block (ram,0x000ed750) */
/* WARNING: Removing unreachable block (ram,0x000ed75c) */
/* WARNING: Removing unreachable block (ram,0x000ed7dc) */
/* WARNING: Removing unreachable block (ram,0x000ed88a) */
/* WARNING: Removing unreachable block (ram,0x000ed72e) */
/* WARNING: Removing unreachable block (ram,0x000ecf5a) */
/* WARNING: Removing unreachable block (ram,0x000ecf82) */
/* WARNING: Removing unreachable block (ram,0x000ecdd2) */
/* WARNING: Removing unreachable block (ram,0x000ececa) */
/* WARNING: Removing unreachable block (ram,0x000ece62) */
/* WARNING: Removing unreachable block (ram,0x000ecd94) */
/* WARNING: Removing unreachable block (ram,0x000ecd9c) */
/* WARNING: Removing unreachable block (ram,0x000ecdaa) */
/* WARNING: Removing unreachable block (ram,0x000ece3a) */
/* WARNING: Removing unreachable block (ram,0x000ece24) */
/* WARNING: Removing unreachable block (ram,0x000ece2c) */
/* WARNING: Removing unreachable block (ram,0x000edc98) */
/* WARNING: Removing unreachable block (ram,0x000eddea) */
/* WARNING: Removing unreachable block (ram,0x000ede00) */
/* WARNING: Removing unreachable block (ram,0x000eddf4) */
/* WARNING: Removing unreachable block (ram,0x000edc66) */
/* WARNING: Removing unreachable block (ram,0x000edd14) */
/* WARNING: Removing unreachable block (ram,0x000ecf44) */
/* WARNING: Removing unreachable block (ram,0x000eceb4) */
/* WARNING: Removing unreachable block (ram,0x000ed8a2) */
/* WARNING: Removing unreachable block (ram,0x000ed430) */
/* WARNING: Removing unreachable block (ram,0x000ede70) */
/* WARNING: Removing unreachable block (ram,0x000ecef2) */

ulonglong XXH64(void *input,size_t len,ulonglong seed)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  U64 UVar8;
  U64 UVar9;
  U64 UVar10;
  U64 UVar11;
  ulonglong seed_local;
  size_t len_local;
  void *input_local;
  U64 h64_3;
  U64 v4_3;
  U64 v3_3;
  U64 v2_3;
  U64 v1_3;
  BYTE *limit_3;
  BYTE *bEnd_3;
  BYTE *p_3;
  U64 h64_2;
  U64 v4_2;
  U64 v3_2;
  U64 v2_2;
  U64 v1_2;
  BYTE *limit_2;
  BYTE *bEnd_2;
  BYTE *p_2;
  U64 h64_1;
  U64 v4_1;
  U64 v3_1;
  U64 v2_1;
  U64 v1_1;
  BYTE *limit_1;
  BYTE *bEnd_1;
  BYTE *p_1;
  U64 h64;
  U64 v4;
  U64 v3;
  U64 v2;
  U64 v1;
  BYTE *limit;
  BYTE *bEnd;
  BYTE *p;
  XXH_endianess endian_detected;
  
  iVar1 = XXH_isLittleEndian();
  seed_local._0_4_ = (uint)seed;
  seed_local._4_4_ = (int)(seed >> 0x20);
  if (((uint)input & 7) == 0) {
    if (iVar1 == 1) {
      p = (BYTE *)input;
      if (len < 0x20) {
        h64 = seed + 0x27d4eb2f165667c5;
      }
      else {
        v1 = CONCAT44(seed_local._4_4_ + (uint)(0x7a143578 < (uint)seed_local) +
                      (0xd82b14b0 < (uint)seed_local + 0x85ebca87) + 0x60ea27ee,
                      (uint)seed_local + 0xadc0b5d6);
        v2 = seed + 0xc2b2ae3d27d4eb4f;
        v4 = CONCAT44((seed_local._4_4_ + 0x61c8864f) - (uint)((uint)seed_local < 0x85ebca87),
                      (uint)seed_local + 0x7a143579);
        v3 = seed;
        do {
          UVar8 = XXH64_round(v1,*(U64 *)p);
          UVar9 = XXH64_round(v2,*(U64 *)(p + 8));
          UVar10 = XXH64_round(v3,*(U64 *)(p + 0x10));
          UVar11 = XXH64_round(v4,*(U64 *)(p + 0x18));
          p = p + 0x20;
          v4 = UVar11;
          v3 = UVar10;
          v2 = UVar9;
          v1 = UVar8;
        } while (p <= (BYTE *)((int)input + (len - 0x20)));
        v1._0_4_ = (uint)UVar8;
        v1._4_4_ = (uint)(UVar8 >> 0x20);
        uVar5 = (uint)v1 << 1 | v1._4_4_ >> 0x1f;
        v2._0_4_ = (uint)UVar9;
        v2._4_4_ = (uint)(UVar9 >> 0x20);
        uVar6 = (uint)v2 << 7 | v2._4_4_ >> 0x19;
        uVar7 = uVar5 + uVar6;
        v3._0_4_ = (uint)UVar10;
        v3._4_4_ = (uint)(UVar10 >> 0x20);
        uVar3 = (uint)v3 << 0xc | v3._4_4_ >> 0x14;
        uVar2 = uVar3 + uVar7;
        v4._0_4_ = (uint)UVar11;
        v4._4_4_ = (uint)(UVar11 >> 0x20);
        uVar4 = (uint)v4 << 0x12 | v4._4_4_ >> 0xe;
        h64 = CONCAT44((v4._4_4_ << 0x12 | (uint)v4 >> 0xe) +
                       (v3._4_4_ << 0xc | (uint)v3 >> 0x14) +
                       (v1._4_4_ << 1 | (uint)v1 >> 0x1f) +
                       (v2._4_4_ << 7 | (uint)v2 >> 0x19) + (uint)CARRY4(uVar5,uVar6) +
                       (uint)CARRY4(uVar3,uVar7) + (uint)CARRY4(uVar4,uVar2),uVar4 + uVar2);
        UVar8 = XXH64_mergeRound(h64,UVar8);
        UVar8 = XXH64_mergeRound(UVar8,UVar9);
        UVar8 = XXH64_mergeRound(UVar8,UVar10);
        h64 = XXH64_mergeRound(UVar8,UVar11);
      }
      h64 = CONCAT44(h64._4_4_ + (uint)CARRY4(len,(uint)h64),len + (uint)h64);
      UVar8 = XXH64_finalize(h64,p,len,XXH_littleEndian,XXH_aligned);
    }
    else {
      p_1 = (BYTE *)input;
      if (len < 0x20) {
        h64_1 = seed + 0x27d4eb2f165667c5;
      }
      else {
        v1_1 = CONCAT44(seed_local._4_4_ + (uint)(0x7a143578 < (uint)seed_local) +
                        (0xd82b14b0 < (uint)seed_local + 0x85ebca87) + 0x60ea27ee,
                        (uint)seed_local + 0xadc0b5d6);
        v2_1 = seed + 0xc2b2ae3d27d4eb4f;
        v4_1 = CONCAT44((seed_local._4_4_ + 0x61c8864f) - (uint)((uint)seed_local < 0x85ebca87),
                        (uint)seed_local + 0x7a143579);
        v3_1 = seed;
        do {
          uVar2 = *(uint *)p_1;
          uVar3 = *(uint *)(p_1 + 4);
          UVar8 = XXH64_round(v1_1,CONCAT44(uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 |
                                            (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18,
                                            uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 |
                                            (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18));
          uVar2 = *(uint *)(p_1 + 8);
          uVar3 = *(uint *)(p_1 + 0xc);
          UVar9 = XXH64_round(v2_1,CONCAT44(uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 |
                                            (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18,
                                            uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 |
                                            (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18));
          uVar2 = *(uint *)(p_1 + 0x10);
          uVar3 = *(uint *)(p_1 + 0x14);
          UVar10 = XXH64_round(v3_1,CONCAT44(uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 |
                                             (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18,
                                             uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 |
                                             (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18));
          uVar2 = *(uint *)(p_1 + 0x18);
          uVar3 = *(uint *)(p_1 + 0x1c);
          UVar11 = XXH64_round(v4_1,CONCAT44(uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 |
                                             (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18,
                                             uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 |
                                             (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18));
          p_1 = p_1 + 0x20;
          v4_1 = UVar11;
          v3_1 = UVar10;
          v2_1 = UVar9;
          v1_1 = UVar8;
        } while (p_1 <= (BYTE *)((int)input + (len - 0x20)));
        v1_1._0_4_ = (uint)UVar8;
        v1_1._4_4_ = (uint)(UVar8 >> 0x20);
        uVar4 = (uint)v1_1 << 1 | v1_1._4_4_ >> 0x1f;
        v2_1._0_4_ = (uint)UVar9;
        v2_1._4_4_ = (uint)(UVar9 >> 0x20);
        uVar5 = (uint)v2_1 << 7 | v2_1._4_4_ >> 0x19;
        uVar6 = uVar4 + uVar5;
        v3_1._0_4_ = (uint)UVar10;
        v3_1._4_4_ = (uint)(UVar10 >> 0x20);
        uVar3 = (uint)v3_1 << 0xc | v3_1._4_4_ >> 0x14;
        uVar2 = uVar3 + uVar6;
        v4_1._0_4_ = (uint)UVar11;
        v4_1._4_4_ = (uint)(UVar11 >> 0x20);
        uVar7 = v4_1._4_4_ >> 0xe | (uint)v4_1 << 0x12;
        h64_1 = CONCAT44((v3_1._4_4_ << 0xc | (uint)v3_1 >> 0x14) +
                         (v1_1._4_4_ << 1 | (uint)v1_1 >> 0x1f) +
                         (v2_1._4_4_ << 7 | (uint)v2_1 >> 0x19) + (uint)CARRY4(uVar4,uVar5) +
                         (uint)CARRY4(uVar3,uVar6) +
                         ((uint)v4_1 >> 0xe | v4_1._4_4_ << 0x12) + (uint)CARRY4(uVar2,uVar7),
                         uVar2 + uVar7);
        UVar8 = XXH64_mergeRound(h64_1,UVar8);
        UVar8 = XXH64_mergeRound(UVar8,UVar9);
        UVar8 = XXH64_mergeRound(UVar8,UVar10);
        h64_1 = XXH64_mergeRound(UVar8,UVar11);
      }
      h64_1 = CONCAT44(h64_1._4_4_ + (uint)CARRY4((uint)h64_1,len),(uint)h64_1 + len);
      UVar8 = XXH64_finalize(h64_1,p_1,len,XXH_bigEndian,XXH_aligned);
    }
  }
  else if (iVar1 == 1) {
    p_2 = (BYTE *)input;
    if (len < 0x20) {
      h64_2 = seed + 0x27d4eb2f165667c5;
    }
    else {
      v1_2 = CONCAT44(seed_local._4_4_ + (uint)(0x7a143578 < (uint)seed_local) +
                      (0xd82b14b0 < (uint)seed_local + 0x85ebca87) + 0x60ea27ee,
                      (uint)seed_local + 0xadc0b5d6);
      v2_2 = seed + 0xc2b2ae3d27d4eb4f;
      v4_2 = CONCAT44((seed_local._4_4_ + 0x61c8864f) - (uint)((uint)seed_local < 0x85ebca87),
                      (uint)seed_local + 0x7a143579);
      v3_2 = seed;
      do {
        UVar8 = XXH_read64(p_2);
        UVar8 = XXH64_round(v1_2,UVar8);
        UVar9 = XXH_read64(p_2 + 8);
        UVar9 = XXH64_round(v2_2,UVar9);
        UVar10 = XXH_read64(p_2 + 0x10);
        UVar10 = XXH64_round(v3_2,UVar10);
        UVar11 = XXH_read64(p_2 + 0x18);
        UVar11 = XXH64_round(v4_2,UVar11);
        p_2 = p_2 + 0x20;
        v4_2 = UVar11;
        v3_2 = UVar10;
        v2_2 = UVar9;
        v1_2 = UVar8;
      } while (p_2 <= (BYTE *)((int)input + (len - 0x20)));
      v1_2._0_4_ = (uint)UVar8;
      v1_2._4_4_ = (uint)(UVar8 >> 0x20);
      uVar3 = (uint)v1_2 << 1 | v1_2._4_4_ >> 0x1f;
      v2_2._0_4_ = (uint)UVar9;
      v2_2._4_4_ = (uint)(UVar9 >> 0x20);
      uVar4 = (uint)v2_2 << 7 | v2_2._4_4_ >> 0x19;
      uVar2 = uVar3 + uVar4;
      v3_2._0_4_ = (uint)UVar10;
      v3_2._4_4_ = (uint)(UVar10 >> 0x20);
      uVar5 = (uint)v3_2 << 0xc | v3_2._4_4_ >> 0x14;
      uVar6 = uVar5 + uVar2;
      v4_2._0_4_ = (uint)UVar11;
      v4_2._4_4_ = (uint)(UVar11 >> 0x20);
      uVar7 = (uint)v4_2 << 0x12 | v4_2._4_4_ >> 0xe;
      h64_2 = CONCAT44((v4_2._4_4_ << 0x12 | (uint)v4_2 >> 0xe) +
                       (v3_2._4_4_ << 0xc | (uint)v3_2 >> 0x14) +
                       (v1_2._4_4_ << 1 | (uint)v1_2 >> 0x1f) +
                       (v2_2._4_4_ << 7 | (uint)v2_2 >> 0x19) + (uint)CARRY4(uVar3,uVar4) +
                       (uint)CARRY4(uVar5,uVar2) + (uint)CARRY4(uVar7,uVar6),uVar7 + uVar6);
      UVar8 = XXH64_mergeRound(h64_2,UVar8);
      UVar8 = XXH64_mergeRound(UVar8,UVar9);
      UVar8 = XXH64_mergeRound(UVar8,UVar10);
      h64_2 = XXH64_mergeRound(UVar8,UVar11);
    }
    h64_2 = CONCAT44(h64_2._4_4_ + (uint)CARRY4((uint)h64_2,len),(uint)h64_2 + len);
    UVar8 = XXH64_finalize(h64_2,p_2,len,XXH_littleEndian,XXH_unaligned);
  }
  else {
    p_3 = (BYTE *)input;
    if (len < 0x20) {
      h64_3 = seed + 0x27d4eb2f165667c5;
    }
    else {
      v1_3 = CONCAT44(seed_local._4_4_ + (uint)(0x7a143578 < (uint)seed_local) +
                      (0xd82b14b0 < (uint)seed_local + 0x85ebca87) + 0x60ea27ee,
                      (uint)seed_local + 0xadc0b5d6);
      v2_3 = seed + 0xc2b2ae3d27d4eb4f;
      v4_3 = CONCAT44((seed_local._4_4_ + 0x61c8864f) - (uint)((uint)seed_local < 0x85ebca87),
                      (uint)seed_local + 0x7a143579);
      v3_3 = seed;
      do {
        UVar8 = XXH_read64(p_3);
        uVar3 = (uint)(UVar8 >> 0x20);
        uVar2 = (uint)UVar8;
        UVar8 = XXH64_round(v1_3,CONCAT44((int)(UVar8 & 0xff000000ff) << 0x18 |
                                          (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8
                                          | uVar2 >> 0x18,
                                          (int)((UVar8 & 0xff000000ff) >> 0x20) << 0x18 |
                                          (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8
                                          | uVar3 >> 0x18));
        UVar9 = XXH_read64(p_3 + 8);
        uVar3 = (uint)(UVar9 >> 0x20);
        uVar2 = (uint)UVar9;
        UVar9 = XXH64_round(v2_3,CONCAT44((int)(UVar9 & 0xff000000ff) << 0x18 |
                                          (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8
                                          | uVar2 >> 0x18,
                                          (int)((UVar9 & 0xff000000ff) >> 0x20) << 0x18 |
                                          (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8
                                          | uVar3 >> 0x18));
        UVar10 = XXH_read64(p_3 + 0x10);
        uVar3 = (uint)(UVar10 >> 0x20);
        uVar2 = (uint)UVar10;
        UVar10 = XXH64_round(v3_3,CONCAT44((int)(UVar10 & 0xff000000ff) << 0x18 |
                                           (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8
                                           | uVar2 >> 0x18,
                                           (int)((UVar10 & 0xff000000ff) >> 0x20) << 0x18 |
                                           (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8
                                           | uVar3 >> 0x18));
        UVar11 = XXH_read64(p_3 + 0x18);
        uVar3 = (uint)(UVar11 >> 0x20);
        uVar2 = (uint)UVar11;
        UVar11 = XXH64_round(v4_3,CONCAT44((int)(UVar11 & 0xff000000ff) << 0x18 |
                                           (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8
                                           | uVar2 >> 0x18,
                                           (int)((UVar11 & 0xff000000ff) >> 0x20) << 0x18 |
                                           (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8
                                           | uVar3 >> 0x18));
        p_3 = p_3 + 0x20;
        v4_3 = UVar11;
        v3_3 = UVar10;
        v2_3 = UVar9;
        v1_3 = UVar8;
      } while (p_3 <= (BYTE *)((int)input + (len - 0x20)));
      v1_3._0_4_ = (uint)UVar8;
      v1_3._4_4_ = (uint)(UVar8 >> 0x20);
      uVar4 = (uint)v1_3 << 1 | v1_3._4_4_ >> 0x1f;
      v2_3._0_4_ = (uint)UVar9;
      v2_3._4_4_ = (uint)(UVar9 >> 0x20);
      uVar5 = (uint)v2_3 << 7 | v2_3._4_4_ >> 0x19;
      uVar2 = uVar4 + uVar5;
      v3_3._0_4_ = (uint)UVar10;
      v3_3._4_4_ = (uint)(UVar10 >> 0x20);
      uVar7 = v3_3._4_4_ >> 0x14 | (uint)v3_3 << 0xc;
      uVar3 = uVar2 + uVar7;
      v4_3._0_4_ = (uint)UVar11;
      v4_3._4_4_ = (uint)(UVar11 >> 0x20);
      uVar6 = v4_3._4_4_ >> 0xe | (uint)v4_3 << 0x12;
      h64_3 = CONCAT44((v1_3._4_4_ << 1 | (uint)v1_3 >> 0x1f) +
                       (v2_3._4_4_ << 7 | (uint)v2_3 >> 0x19) + (uint)CARRY4(uVar4,uVar5) +
                       ((uint)v3_3 >> 0x14 | v3_3._4_4_ << 0xc) + (uint)CARRY4(uVar2,uVar7) +
                       ((uint)v4_3 >> 0xe | v4_3._4_4_ << 0x12) + (uint)CARRY4(uVar3,uVar6),
                       uVar3 + uVar6);
      UVar8 = XXH64_mergeRound(h64_3,UVar8);
      UVar8 = XXH64_mergeRound(UVar8,UVar9);
      UVar8 = XXH64_mergeRound(UVar8,UVar10);
      h64_3 = XXH64_mergeRound(UVar8,UVar11);
    }
    h64_3 = CONCAT44(h64_3._4_4_ + (uint)CARRY4((uint)h64_3,len),(uint)h64_3 + len);
    UVar8 = XXH64_finalize(h64_3,p_3,len,XXH_bigEndian,XXH_unaligned);
  }
  return UVar8;
}

