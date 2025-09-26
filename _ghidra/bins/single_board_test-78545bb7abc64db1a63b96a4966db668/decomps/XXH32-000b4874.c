
/* WARNING: Removing unreachable block (ram,0x000b53d2) */
/* WARNING: Removing unreachable block (ram,0x000b5484) */
/* WARNING: Removing unreachable block (ram,0x000b5498) */
/* WARNING: Removing unreachable block (ram,0x000b548e) */
/* WARNING: Removing unreachable block (ram,0x000b535c) */
/* WARNING: Removing unreachable block (ram,0x000b5370) */
/* WARNING: Removing unreachable block (ram,0x000b5366) */
/* WARNING: Removing unreachable block (ram,0x000b52c8) */
/* WARNING: Removing unreachable block (ram,0x000b52dc) */
/* WARNING: Removing unreachable block (ram,0x000b4d56) */
/* WARNING: Removing unreachable block (ram,0x000b4c48) */
/* WARNING: Removing unreachable block (ram,0x000b4c5c) */
/* WARNING: Removing unreachable block (ram,0x000b4c50) */
/* WARNING: Removing unreachable block (ram,0x000b4cc2) */
/* WARNING: Removing unreachable block (ram,0x000b4cba) */
/* WARNING: Removing unreachable block (ram,0x000b4cce) */
/* WARNING: Removing unreachable block (ram,0x000b4d2c) */
/* WARNING: Removing unreachable block (ram,0x000b4d40) */
/* WARNING: Removing unreachable block (ram,0x000b4d34) */
/* WARNING: Removing unreachable block (ram,0x000b4d9e) */
/* WARNING: Removing unreachable block (ram,0x000b4db2) */
/* WARNING: Removing unreachable block (ram,0x000b4da6) */
/* WARNING: Removing unreachable block (ram,0x000b4ce4) */
/* WARNING: Removing unreachable block (ram,0x000b4c72) */
/* WARNING: Removing unreachable block (ram,0x000b50f2) */
/* WARNING: Removing unreachable block (ram,0x000b5106) */
/* WARNING: Removing unreachable block (ram,0x000b50fc) */
/* WARNING: Removing unreachable block (ram,0x000b50e2) */
/* WARNING: Removing unreachable block (ram,0x000b5080) */
/* WARNING: Removing unreachable block (ram,0x000b4fe6) */
/* WARNING: Removing unreachable block (ram,0x000b4ffa) */
/* WARNING: Removing unreachable block (ram,0x000b4ff0) */
/* WARNING: Removing unreachable block (ram,0x000b4f60) */
/* WARNING: Removing unreachable block (ram,0x000b4f6a) */
/* WARNING: Removing unreachable block (ram,0x000b4f74) */
/* WARNING: Removing unreachable block (ram,0x000b4fd6) */
/* WARNING: Removing unreachable block (ram,0x000b505c) */
/* WARNING: Removing unreachable block (ram,0x000b4f50) */
/* WARNING: Removing unreachable block (ram,0x000b4ad2) */
/* WARNING: Removing unreachable block (ram,0x000b4af0) */
/* WARNING: Removing unreachable block (ram,0x000b499a) */
/* WARNING: Removing unreachable block (ram,0x000b4a60) */
/* WARNING: Removing unreachable block (ram,0x000b4a0c) */
/* WARNING: Removing unreachable block (ram,0x000b4968) */
/* WARNING: Removing unreachable block (ram,0x000b4970) */
/* WARNING: Removing unreachable block (ram,0x000b497c) */
/* WARNING: Removing unreachable block (ram,0x000b49ee) */
/* WARNING: Removing unreachable block (ram,0x000b49da) */
/* WARNING: Removing unreachable block (ram,0x000b49e2) */
/* WARNING: Removing unreachable block (ram,0x000b52d2) */
/* WARNING: Removing unreachable block (ram,0x000b53f0) */
/* WARNING: Removing unreachable block (ram,0x000b5404) */
/* WARNING: Removing unreachable block (ram,0x000b53fa) */
/* WARNING: Removing unreachable block (ram,0x000b52aa) */
/* WARNING: Removing unreachable block (ram,0x000b533e) */
/* WARNING: Removing unreachable block (ram,0x000b4abe) */
/* WARNING: Removing unreachable block (ram,0x000b4a4c) */
/* WARNING: Removing unreachable block (ram,0x000b506c) */
/* WARNING: Removing unreachable block (ram,0x000b4dc8) */
/* WARNING: Removing unreachable block (ram,0x000b5466) */
/* WARNING: Removing unreachable block (ram,0x000b4a7e) */

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

