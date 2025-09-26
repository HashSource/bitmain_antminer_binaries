
uint XXH32_digest(XXH32_state_t *state_in)

{
  int iVar1;
  U32 UVar2;
  XXH32_state_t *state_in_local;
  U32 h32_1;
  U32 h32;
  XXH_endianess endian_detected;
  
  iVar1 = XXH_isLittleEndian();
  if (iVar1 == 1) {
    if (state_in->large_len == 0) {
      h32 = state_in->v3 + 0x165667b1;
    }
    else {
      h32 = (state_in->v4 >> 0xe | state_in->v4 << 0x12) +
            (state_in->v1 >> 0x1f | state_in->v1 << 1) + (state_in->v2 >> 0x19 | state_in->v2 << 7)
            + (state_in->v3 >> 0x14 | state_in->v3 << 0xc);
    }
    UVar2 = XXH32_finalize(state_in->total_len_32 + h32,state_in->mem32,state_in->memsize,
                           XXH_littleEndian,XXH_aligned);
  }
  else {
    if (state_in->large_len == 0) {
      h32_1 = state_in->v3 + 0x165667b1;
    }
    else {
      h32_1 = (state_in->v4 >> 0xe | state_in->v4 << 0x12) +
              (state_in->v1 >> 0x1f | state_in->v1 << 1) +
              (state_in->v2 >> 0x19 | state_in->v2 << 7) +
              (state_in->v3 >> 0x14 | state_in->v3 << 0xc);
    }
    UVar2 = XXH32_finalize(state_in->total_len_32 + h32_1,state_in->mem32,state_in->memsize,
                           XXH_bigEndian,XXH_aligned);
  }
  return UVar2;
}

