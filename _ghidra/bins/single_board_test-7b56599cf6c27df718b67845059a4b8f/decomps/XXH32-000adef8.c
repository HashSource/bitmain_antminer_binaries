
/* WARNING: Removing unreachable block (ram,0x000aea5a) */
/* WARNING: Removing unreachable block (ram,0x000aeb0c) */
/* WARNING: Removing unreachable block (ram,0x000aeb20) */
/* WARNING: Removing unreachable block (ram,0x000aeb16) */
/* WARNING: Removing unreachable block (ram,0x000ae9e4) */
/* WARNING: Removing unreachable block (ram,0x000ae9f8) */
/* WARNING: Removing unreachable block (ram,0x000ae9ee) */
/* WARNING: Removing unreachable block (ram,0x000ae950) */
/* WARNING: Removing unreachable block (ram,0x000ae964) */
/* WARNING: Removing unreachable block (ram,0x000ae3da) */
/* WARNING: Removing unreachable block (ram,0x000ae2cc) */
/* WARNING: Removing unreachable block (ram,0x000ae2e0) */
/* WARNING: Removing unreachable block (ram,0x000ae2d4) */
/* WARNING: Removing unreachable block (ram,0x000ae346) */
/* WARNING: Removing unreachable block (ram,0x000ae33e) */
/* WARNING: Removing unreachable block (ram,0x000ae352) */
/* WARNING: Removing unreachable block (ram,0x000ae3b0) */
/* WARNING: Removing unreachable block (ram,0x000ae3c4) */
/* WARNING: Removing unreachable block (ram,0x000ae3b8) */
/* WARNING: Removing unreachable block (ram,0x000ae422) */
/* WARNING: Removing unreachable block (ram,0x000ae436) */
/* WARNING: Removing unreachable block (ram,0x000ae42a) */
/* WARNING: Removing unreachable block (ram,0x000ae368) */
/* WARNING: Removing unreachable block (ram,0x000ae2f6) */
/* WARNING: Removing unreachable block (ram,0x000ae778) */
/* WARNING: Removing unreachable block (ram,0x000ae78c) */
/* WARNING: Removing unreachable block (ram,0x000ae782) */
/* WARNING: Removing unreachable block (ram,0x000ae768) */
/* WARNING: Removing unreachable block (ram,0x000ae706) */
/* WARNING: Removing unreachable block (ram,0x000ae66c) */
/* WARNING: Removing unreachable block (ram,0x000ae680) */
/* WARNING: Removing unreachable block (ram,0x000ae676) */
/* WARNING: Removing unreachable block (ram,0x000ae5e6) */
/* WARNING: Removing unreachable block (ram,0x000ae5f0) */
/* WARNING: Removing unreachable block (ram,0x000ae5fa) */
/* WARNING: Removing unreachable block (ram,0x000ae65c) */
/* WARNING: Removing unreachable block (ram,0x000ae6e2) */
/* WARNING: Removing unreachable block (ram,0x000ae5d6) */
/* WARNING: Removing unreachable block (ram,0x000ae156) */
/* WARNING: Removing unreachable block (ram,0x000ae174) */
/* WARNING: Removing unreachable block (ram,0x000ae01e) */
/* WARNING: Removing unreachable block (ram,0x000ae0e4) */
/* WARNING: Removing unreachable block (ram,0x000ae090) */
/* WARNING: Removing unreachable block (ram,0x000adfec) */
/* WARNING: Removing unreachable block (ram,0x000adff4) */
/* WARNING: Removing unreachable block (ram,0x000ae000) */
/* WARNING: Removing unreachable block (ram,0x000ae072) */
/* WARNING: Removing unreachable block (ram,0x000ae05e) */
/* WARNING: Removing unreachable block (ram,0x000ae066) */
/* WARNING: Removing unreachable block (ram,0x000ae95a) */
/* WARNING: Removing unreachable block (ram,0x000aea78) */
/* WARNING: Removing unreachable block (ram,0x000aea8c) */
/* WARNING: Removing unreachable block (ram,0x000aea82) */
/* WARNING: Removing unreachable block (ram,0x000ae932) */
/* WARNING: Removing unreachable block (ram,0x000ae9c6) */
/* WARNING: Removing unreachable block (ram,0x000ae142) */
/* WARNING: Removing unreachable block (ram,0x000ae0d0) */
/* WARNING: Removing unreachable block (ram,0x000ae6f2) */
/* WARNING: Removing unreachable block (ram,0x000ae44c) */
/* WARNING: Removing unreachable block (ram,0x000aeaee) */
/* WARNING: Removing unreachable block (ram,0x000ae102) */

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

