
ulonglong XXH64_digest(XXH64_state_t *state_in)

{
  U64 UVar1;
  U64 UVar2;
  int iVar3;
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
  U64 UVar18;
  U64 UVar19;
  XXH64_state_t *state_in_local;
  U64 h64_1;
  U64 v4_1;
  U64 v3_1;
  U64 v2_1;
  U64 v1_1;
  U64 h64;
  U64 v4;
  U64 v3;
  U64 v2;
  U64 v1;
  XXH_endianess endian_detected;
  
  iVar3 = XXH_isLittleEndian();
  if (iVar3 == 1) {
    if (*(int *)((int)&state_in->total_len + 4) == 0 && (uint)state_in->total_len < 0x20) {
      uVar4 = (uint)state_in->v3;
      h64 = CONCAT44(*(int *)((int)&state_in->v3 + 4) + (0xe9a9983a < uVar4) + 0x27d4eb2f,
                     uVar4 + 0x165667c5);
    }
    else {
      uVar7 = (uint)state_in->v1;
      uVar14 = *(uint *)((int)&state_in->v1 + 4);
      uVar11 = (uint)state_in->v2;
      uVar15 = *(uint *)((int)&state_in->v2 + 4);
      UVar19 = state_in->v2;
      uVar12 = (uint)state_in->v3;
      uVar16 = *(uint *)((int)&state_in->v3 + 4);
      UVar1 = state_in->v3;
      uVar13 = (uint)state_in->v4;
      uVar17 = *(uint *)((int)&state_in->v4 + 4);
      UVar2 = state_in->v4;
      uVar8 = uVar7 << 1 | uVar14 >> 0x1f;
      uVar9 = uVar11 << 7 | uVar15 >> 0x19;
      uVar10 = uVar8 + uVar9;
      uVar5 = uVar12 << 0xc | uVar16 >> 0x14;
      uVar4 = uVar5 + uVar10;
      uVar6 = uVar13 << 0x12 | uVar17 >> 0xe;
      h64 = CONCAT44((uVar17 << 0x12 | uVar13 >> 0xe) +
                     (uVar16 << 0xc | uVar12 >> 0x14) +
                     (uVar14 << 1 | uVar7 >> 0x1f) +
                     (uVar15 << 7 | uVar11 >> 0x19) + (uint)CARRY4(uVar8,uVar9) +
                     (uint)CARRY4(uVar5,uVar10) + (uint)CARRY4(uVar6,uVar4),uVar6 + uVar4);
      UVar18 = XXH64_mergeRound(h64,state_in->v1);
      UVar19 = XXH64_mergeRound(UVar18,UVar19);
      UVar19 = XXH64_mergeRound(UVar19,UVar1);
      h64 = XXH64_mergeRound(UVar19,UVar2);
    }
    uVar4 = (uint)state_in->total_len;
    h64 = CONCAT44(*(int *)((int)&state_in->total_len + 4) +
                   h64._4_4_ + (uint)CARRY4(uVar4,(uint)h64),uVar4 + (uint)h64);
    UVar19 = XXH64_finalize(h64,state_in->mem64,(size_t)state_in->total_len,XXH_littleEndian,
                            XXH_aligned);
  }
  else {
    if (*(int *)((int)&state_in->total_len + 4) == 0 && (uint)state_in->total_len < 0x20) {
      uVar4 = (uint)state_in->v3;
      h64_1 = CONCAT44(*(int *)((int)&state_in->v3 + 4) + (0xe9a9983a < uVar4) + 0x27d4eb2f,
                       uVar4 + 0x165667c5);
    }
    else {
      uVar4 = (uint)state_in->v1;
      uVar8 = *(uint *)((int)&state_in->v1 + 4);
      uVar5 = (uint)state_in->v2;
      uVar9 = *(uint *)((int)&state_in->v2 + 4);
      UVar19 = state_in->v2;
      uVar6 = (uint)state_in->v3;
      uVar10 = *(uint *)((int)&state_in->v3 + 4);
      UVar1 = state_in->v3;
      uVar7 = (uint)state_in->v4;
      uVar14 = *(uint *)((int)&state_in->v4 + 4);
      UVar2 = state_in->v4;
      uVar11 = uVar4 << 1 | uVar8 >> 0x1f;
      uVar17 = uVar9 >> 0x19 | uVar5 << 7;
      uVar12 = uVar11 + uVar17;
      uVar16 = uVar10 >> 0x14 | uVar6 << 0xc;
      uVar13 = uVar12 + uVar16;
      uVar15 = uVar14 >> 0xe | uVar7 << 0x12;
      h64_1 = CONCAT44((uVar8 << 1 | uVar4 >> 0x1f) +
                       (uVar5 >> 0x19 | uVar9 << 7) + (uint)CARRY4(uVar11,uVar17) +
                       (uVar6 >> 0x14 | uVar10 << 0xc) + (uint)CARRY4(uVar12,uVar16) +
                       (uVar7 >> 0xe | uVar14 << 0x12) + (uint)CARRY4(uVar13,uVar15),uVar13 + uVar15
                      );
      UVar18 = XXH64_mergeRound(h64_1,state_in->v1);
      UVar19 = XXH64_mergeRound(UVar18,UVar19);
      UVar19 = XXH64_mergeRound(UVar19,UVar1);
      h64_1 = XXH64_mergeRound(UVar19,UVar2);
    }
    uVar4 = (uint)state_in->total_len;
    h64_1 = CONCAT44(*(int *)((int)&state_in->total_len + 4) +
                     h64_1._4_4_ + (uint)CARRY4(uVar4,(uint)h64_1),uVar4 + (uint)h64_1);
    UVar19 = XXH64_finalize(h64_1,state_in->mem64,(size_t)state_in->total_len,XXH_bigEndian,
                            XXH_aligned);
  }
  return UVar19;
}

