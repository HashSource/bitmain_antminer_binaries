
/* WARNING: Removing unreachable block (ram,0x000a92aa) */
/* WARNING: Removing unreachable block (ram,0x000a935c) */
/* WARNING: Removing unreachable block (ram,0x000a9370) */
/* WARNING: Removing unreachable block (ram,0x000a9366) */
/* WARNING: Removing unreachable block (ram,0x000a9234) */
/* WARNING: Removing unreachable block (ram,0x000a9248) */
/* WARNING: Removing unreachable block (ram,0x000a923e) */
/* WARNING: Removing unreachable block (ram,0x000a91a0) */
/* WARNING: Removing unreachable block (ram,0x000a91b4) */
/* WARNING: Removing unreachable block (ram,0x000a8c2a) */
/* WARNING: Removing unreachable block (ram,0x000a8b1c) */
/* WARNING: Removing unreachable block (ram,0x000a8b30) */
/* WARNING: Removing unreachable block (ram,0x000a8b24) */
/* WARNING: Removing unreachable block (ram,0x000a8b96) */
/* WARNING: Removing unreachable block (ram,0x000a8b8e) */
/* WARNING: Removing unreachable block (ram,0x000a8ba2) */
/* WARNING: Removing unreachable block (ram,0x000a8c00) */
/* WARNING: Removing unreachable block (ram,0x000a8c14) */
/* WARNING: Removing unreachable block (ram,0x000a8c08) */
/* WARNING: Removing unreachable block (ram,0x000a8c72) */
/* WARNING: Removing unreachable block (ram,0x000a8c86) */
/* WARNING: Removing unreachable block (ram,0x000a8c7a) */
/* WARNING: Removing unreachable block (ram,0x000a8bb8) */
/* WARNING: Removing unreachable block (ram,0x000a8b46) */
/* WARNING: Removing unreachable block (ram,0x000a8fc8) */
/* WARNING: Removing unreachable block (ram,0x000a8fdc) */
/* WARNING: Removing unreachable block (ram,0x000a8fd2) */
/* WARNING: Removing unreachable block (ram,0x000a8fb8) */
/* WARNING: Removing unreachable block (ram,0x000a8f56) */
/* WARNING: Removing unreachable block (ram,0x000a8ebc) */
/* WARNING: Removing unreachable block (ram,0x000a8ed0) */
/* WARNING: Removing unreachable block (ram,0x000a8ec6) */
/* WARNING: Removing unreachable block (ram,0x000a8e36) */
/* WARNING: Removing unreachable block (ram,0x000a8e40) */
/* WARNING: Removing unreachable block (ram,0x000a8e4a) */
/* WARNING: Removing unreachable block (ram,0x000a8eac) */
/* WARNING: Removing unreachable block (ram,0x000a8f32) */
/* WARNING: Removing unreachable block (ram,0x000a8e26) */
/* WARNING: Removing unreachable block (ram,0x000a89a6) */
/* WARNING: Removing unreachable block (ram,0x000a89c4) */
/* WARNING: Removing unreachable block (ram,0x000a886e) */
/* WARNING: Removing unreachable block (ram,0x000a8934) */
/* WARNING: Removing unreachable block (ram,0x000a88e0) */
/* WARNING: Removing unreachable block (ram,0x000a883c) */
/* WARNING: Removing unreachable block (ram,0x000a8844) */
/* WARNING: Removing unreachable block (ram,0x000a8850) */
/* WARNING: Removing unreachable block (ram,0x000a88c2) */
/* WARNING: Removing unreachable block (ram,0x000a88ae) */
/* WARNING: Removing unreachable block (ram,0x000a88b6) */
/* WARNING: Removing unreachable block (ram,0x000a91aa) */
/* WARNING: Removing unreachable block (ram,0x000a92c8) */
/* WARNING: Removing unreachable block (ram,0x000a92dc) */
/* WARNING: Removing unreachable block (ram,0x000a92d2) */
/* WARNING: Removing unreachable block (ram,0x000a9182) */
/* WARNING: Removing unreachable block (ram,0x000a9216) */
/* WARNING: Removing unreachable block (ram,0x000a8992) */
/* WARNING: Removing unreachable block (ram,0x000a8920) */
/* WARNING: Removing unreachable block (ram,0x000a8f42) */
/* WARNING: Removing unreachable block (ram,0x000a8c9c) */
/* WARNING: Removing unreachable block (ram,0x000a933e) */
/* WARNING: Removing unreachable block (ram,0x000a8952) */

uint XXH32(void *input,size_t len,uint seed)

{
  int iVar1;
  U32 UVar2;
  uint uVar3;
  uint seed_local;
  size_t len_local;
  void *input_local;
  U32 h32_3;
  U32 v4_3;
  U32 v3_3;
  U32 v2_3;
  U32 v1_3;
  BYTE *limit_3;
  BYTE *bEnd_3;
  BYTE *p_3;
  U32 h32_2;
  U32 v4_2;
  U32 v3_2;
  U32 v2_2;
  U32 v1_2;
  BYTE *limit_2;
  BYTE *bEnd_2;
  BYTE *p_2;
  U32 h32_1;
  U32 v4_1;
  U32 v3_1;
  U32 v2_1;
  U32 v1_1;
  BYTE *limit_1;
  BYTE *bEnd_1;
  BYTE *p_1;
  U32 h32;
  U32 v4;
  U32 v3;
  U32 v2;
  U32 v1;
  BYTE *limit;
  BYTE *bEnd;
  BYTE *p;
  XXH_endianess endian_detected;
  
  iVar1 = XXH_isLittleEndian();
  if (((uint)input & 3) == 0) {
    if (iVar1 == 1) {
      p = (BYTE *)input;
      if (len < 0x10) {
        h32 = seed + 0x165667b1;
      }
      else {
        v1 = seed + 0x24234428;
        v2 = seed + 0x85ebca77;
        v4 = seed + 0x61c8864f;
        v3 = seed;
        do {
          v1 = XXH32_round(v1,*(U32 *)p);
          v2 = XXH32_round(v2,*(U32 *)(p + 4));
          v3 = XXH32_round(v3,*(U32 *)(p + 8));
          v4 = XXH32_round(v4,*(U32 *)(p + 0xc));
          p = p + 0x10;
        } while (p < (BYTE *)((int)input + (len - 0xf)));
        h32 = (v4 >> 0xe | v4 << 0x12) +
              (v1 >> 0x1f | v1 << 1) + (v2 >> 0x19 | v2 << 7) + (v3 >> 0x14 | v3 << 0xc);
      }
      UVar2 = XXH32_finalize(len + h32,p,len & 0xf,XXH_littleEndian,XXH_aligned);
    }
    else {
      p_1 = (BYTE *)input;
      if (len < 0x10) {
        h32_1 = seed + 0x165667b1;
      }
      else {
        v1_1 = seed + 0x24234428;
        v2_1 = seed + 0x85ebca77;
        v4_1 = seed + 0x61c8864f;
        v3_1 = seed;
        do {
          uVar3 = *(uint *)p_1;
          v1_1 = XXH32_round(v1_1,uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 |
                                  (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18);
          uVar3 = *(uint *)(p_1 + 4);
          v2_1 = XXH32_round(v2_1,uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 |
                                  (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18);
          uVar3 = *(uint *)(p_1 + 8);
          v3_1 = XXH32_round(v3_1,uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 |
                                  (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18);
          uVar3 = *(uint *)(p_1 + 0xc);
          v4_1 = XXH32_round(v4_1,uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 |
                                  (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18);
          p_1 = p_1 + 0x10;
        } while (p_1 < (BYTE *)((int)input + (len - 0xf)));
        h32_1 = (v4_1 >> 0xe | v4_1 << 0x12) +
                (v1_1 >> 0x1f | v1_1 << 1) + (v2_1 >> 0x19 | v2_1 << 7) +
                (v3_1 >> 0x14 | v3_1 << 0xc);
      }
      UVar2 = XXH32_finalize(len + h32_1,p_1,len & 0xf,XXH_bigEndian,XXH_aligned);
    }
  }
  else if (iVar1 == 1) {
    p_2 = (BYTE *)input;
    if (len < 0x10) {
      h32_2 = seed + 0x165667b1;
    }
    else {
      v1_2 = seed + 0x24234428;
      v2_2 = seed + 0x85ebca77;
      v4_2 = seed + 0x61c8864f;
      v3_2 = seed;
      do {
        UVar2 = XXH_read32(p_2);
        v1_2 = XXH32_round(v1_2,UVar2);
        UVar2 = XXH_read32(p_2 + 4);
        v2_2 = XXH32_round(v2_2,UVar2);
        UVar2 = XXH_read32(p_2 + 8);
        v3_2 = XXH32_round(v3_2,UVar2);
        UVar2 = XXH_read32(p_2 + 0xc);
        v4_2 = XXH32_round(v4_2,UVar2);
        p_2 = p_2 + 0x10;
      } while (p_2 < (BYTE *)((int)input + (len - 0xf)));
      h32_2 = (v4_2 >> 0xe | v4_2 << 0x12) +
              (v1_2 >> 0x1f | v1_2 << 1) + (v2_2 >> 0x19 | v2_2 << 7) + (v3_2 >> 0x14 | v3_2 << 0xc)
      ;
    }
    UVar2 = XXH32_finalize(h32_2 + len,p_2,len & 0xf,XXH_littleEndian,XXH_unaligned);
  }
  else {
    p_3 = (BYTE *)input;
    if (len < 0x10) {
      h32_3 = seed + 0x165667b1;
    }
    else {
      v1_3 = seed + 0x24234428;
      v2_3 = seed + 0x85ebca77;
      v4_3 = seed + 0x61c8864f;
      v3_3 = seed;
      do {
        UVar2 = XXH_read32(p_3);
        v1_3 = XXH32_round(v1_3,UVar2 << 0x18 | (UVar2 >> 8 & 0xff) << 0x10 |
                                (UVar2 >> 0x10 & 0xff) << 8 | UVar2 >> 0x18);
        UVar2 = XXH_read32(p_3 + 4);
        v2_3 = XXH32_round(v2_3,UVar2 << 0x18 | (UVar2 >> 8 & 0xff) << 0x10 |
                                (UVar2 >> 0x10 & 0xff) << 8 | UVar2 >> 0x18);
        UVar2 = XXH_read32(p_3 + 8);
        v3_3 = XXH32_round(v3_3,UVar2 << 0x18 | (UVar2 >> 8 & 0xff) << 0x10 |
                                (UVar2 >> 0x10 & 0xff) << 8 | UVar2 >> 0x18);
        UVar2 = XXH_read32(p_3 + 0xc);
        v4_3 = XXH32_round(v4_3,UVar2 << 0x18 | (UVar2 >> 8 & 0xff) << 0x10 |
                                (UVar2 >> 0x10 & 0xff) << 8 | UVar2 >> 0x18);
        p_3 = p_3 + 0x10;
      } while (p_3 < (BYTE *)((int)input + (len - 0xf)));
      h32_3 = (v4_3 >> 0xe | v4_3 << 0x12) +
              (v1_3 >> 0x1f | v1_3 << 1) + (v2_3 >> 0x19 | v2_3 << 7) + (v3_3 >> 0x14 | v3_3 << 0xc)
      ;
    }
    UVar2 = XXH32_finalize(h32_3 + len,p_3,len & 0xf,XXH_bigEndian,XXH_unaligned);
  }
  return UVar2;
}

