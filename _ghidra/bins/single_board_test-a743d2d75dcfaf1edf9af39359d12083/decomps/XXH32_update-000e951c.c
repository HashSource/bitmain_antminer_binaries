
/* WARNING: Removing unreachable block (ram,0x000ea0a2) */
/* WARNING: Removing unreachable block (ram,0x000ea160) */
/* WARNING: Removing unreachable block (ram,0x000ea174) */
/* WARNING: Removing unreachable block (ram,0x000ea16a) */
/* WARNING: Removing unreachable block (ram,0x000ea020) */
/* WARNING: Removing unreachable block (ram,0x000ea034) */
/* WARNING: Removing unreachable block (ram,0x000ea02a) */
/* WARNING: Removing unreachable block (ram,0x000e9e8c) */
/* WARNING: Removing unreachable block (ram,0x000e9e64) */
/* WARNING: Removing unreachable block (ram,0x000e9dde) */
/* WARNING: Removing unreachable block (ram,0x000e9df2) */
/* WARNING: Removing unreachable block (ram,0x000e9d44) */
/* WARNING: Removing unreachable block (ram,0x000e9d1c) */
/* WARNING: Removing unreachable block (ram,0x000e9c9a) */
/* WARNING: Removing unreachable block (ram,0x000e9cac) */
/* WARNING: Removing unreachable block (ram,0x000e9994) */
/* WARNING: Removing unreachable block (ram,0x000e999c) */
/* WARNING: Removing unreachable block (ram,0x000e9a06) */
/* WARNING: Removing unreachable block (ram,0x000e99a4) */
/* WARNING: Removing unreachable block (ram,0x000e9914) */
/* WARNING: Removing unreachable block (ram,0x000e9924) */
/* WARNING: Removing unreachable block (ram,0x000e991c) */
/* WARNING: Removing unreachable block (ram,0x000e983c) */
/* WARNING: Removing unreachable block (ram,0x000e984c) */
/* WARNING: Removing unreachable block (ram,0x000e9844) */
/* WARNING: Removing unreachable block (ram,0x000e97b4) */
/* WARNING: Removing unreachable block (ram,0x000e97c4) */
/* WARNING: Removing unreachable block (ram,0x000e97bc) */
/* WARNING: Removing unreachable block (ram,0x000e972c) */
/* WARNING: Removing unreachable block (ram,0x000e973c) */
/* WARNING: Removing unreachable block (ram,0x000e9734) */
/* WARNING: Removing unreachable block (ram,0x000e96a4) */
/* WARNING: Removing unreachable block (ram,0x000e96ac) */
/* WARNING: Removing unreachable block (ram,0x000e96b4) */
/* WARNING: Removing unreachable block (ram,0x000e9c80) */
/* WARNING: Removing unreachable block (ram,0x000e9696) */
/* WARNING: Removing unreachable block (ram,0x000e971e) */
/* WARNING: Removing unreachable block (ram,0x000e97a6) */
/* WARNING: Removing unreachable block (ram,0x000e982e) */
/* WARNING: Removing unreachable block (ram,0x000e9906) */
/* WARNING: Removing unreachable block (ram,0x000e9986) */
/* WARNING: Removing unreachable block (ram,0x000e9a94) */
/* WARNING: Removing unreachable block (ram,0x000e9aa4) */
/* WARNING: Removing unreachable block (ram,0x000e9a9c) */
/* WARNING: Removing unreachable block (ram,0x000e9a14) */
/* WARNING: Removing unreachable block (ram,0x000e9a24) */
/* WARNING: Removing unreachable block (ram,0x000e9a1c) */
/* WARNING: Removing unreachable block (ram,0x000e9ca4) */
/* WARNING: Removing unreachable block (ram,0x000e9d3a) */
/* WARNING: Removing unreachable block (ram,0x000e9d4e) */
/* WARNING: Removing unreachable block (ram,0x000e9dc0) */
/* WARNING: Removing unreachable block (ram,0x000e9de8) */
/* WARNING: Removing unreachable block (ram,0x000e9e82) */
/* WARNING: Removing unreachable block (ram,0x000e9e96) */
/* WARNING: Removing unreachable block (ram,0x000e9f80) */
/* WARNING: Removing unreachable block (ram,0x000e9f94) */
/* WARNING: Removing unreachable block (ram,0x000e9f8a) */
/* WARNING: Removing unreachable block (ram,0x000ea0c0) */
/* WARNING: Removing unreachable block (ram,0x000ea0d4) */
/* WARNING: Removing unreachable block (ram,0x000ea0ca) */
/* WARNING: Removing unreachable block (ram,0x000e9f62) */
/* WARNING: Removing unreachable block (ram,0x000ea002) */
/* WARNING: Removing unreachable block (ram,0x000e9a86) */
/* WARNING: Removing unreachable block (ram,0x000ea142) */

XXH_errorcode XXH32_update(XXH32_state_t *state_in,void *input,size_t len)

{
  int iVar1;
  U32 UVar2;
  byte bVar3;
  byte bVar4;
  size_t sVar5;
  uint uVar6;
  uint uVar7;
  XXH_errorcode XVar8;
  BYTE *pBVar9;
  U32 UVar10;
  size_t len_local;
  void *input_local;
  XXH32_state_t *state_in_local;
  U32 v4_1;
  U32 v3_1;
  U32 v2_1;
  U32 v1_1;
  BYTE *limit_1;
  U32 *p32_1;
  BYTE *bEnd_1;
  BYTE *p_1;
  U32 v4;
  U32 v3;
  U32 v2;
  U32 v1;
  BYTE *limit;
  U32 *p32;
  BYTE *bEnd;
  BYTE *p;
  XXH_endianess endian_detected;
  
  iVar1 = XXH_isLittleEndian();
  if (iVar1 == 1) {
    if (input == (void *)0x0) {
      XVar8 = XXH_ERROR;
    }
    else {
      pBVar9 = (BYTE *)(len + (int)input);
      state_in->total_len_32 = state_in->total_len_32 + len;
      sVar5 = len;
      if (0xf < len) {
        sVar5 = 1;
      }
      bVar3 = (byte)sVar5;
      if (len < 0x10) {
        bVar3 = 0;
      }
      uVar6 = state_in->total_len_32;
      uVar7 = uVar6;
      if (0xf < uVar6) {
        uVar7 = 1;
      }
      bVar4 = (byte)uVar7;
      if (uVar6 < 0x10) {
        bVar4 = 0;
      }
      state_in->large_len = (uint)(bVar4 | bVar3) | state_in->large_len;
      if (len + state_in->memsize < 0x10) {
        XXH_memcpy((void *)((int)state_in->mem32 + state_in->memsize),input,len);
        state_in->memsize = state_in->memsize + len;
        XVar8 = XXH_OK;
      }
      else {
        p = (BYTE *)input;
        if (state_in->memsize != 0) {
          XXH_memcpy((void *)((int)state_in->mem32 + state_in->memsize),input,
                     0x10 - state_in->memsize);
          UVar10 = state_in->v1;
          UVar2 = XXH_read32(state_in->mem32);
          UVar2 = XXH32_round(UVar10,UVar2);
          state_in->v1 = UVar2;
          UVar10 = state_in->v2;
          UVar2 = XXH_read32(state_in->mem32 + 1);
          UVar2 = XXH32_round(UVar10,UVar2);
          state_in->v2 = UVar2;
          UVar10 = state_in->v3;
          UVar2 = XXH_read32(state_in->mem32 + 2);
          UVar2 = XXH32_round(UVar10,UVar2);
          state_in->v3 = UVar2;
          UVar10 = state_in->v4;
          UVar2 = XXH_read32(state_in->mem32 + 3);
          UVar2 = XXH32_round(UVar10,UVar2);
          state_in->v4 = UVar2;
          p = (BYTE *)((0x10 - state_in->memsize) + (int)input);
          state_in->memsize = 0;
        }
        if (p <= pBVar9 + -0x10) {
          v1 = state_in->v1;
          v2 = state_in->v2;
          v3 = state_in->v3;
          v4 = state_in->v4;
          do {
            UVar2 = XXH_read32(p);
            v1 = XXH32_round(v1,UVar2);
            UVar2 = XXH_read32(p + 4);
            v2 = XXH32_round(v2,UVar2);
            UVar2 = XXH_read32(p + 8);
            v3 = XXH32_round(v3,UVar2);
            UVar2 = XXH_read32(p + 0xc);
            v4 = XXH32_round(v4,UVar2);
            p = p + 0x10;
          } while (p <= pBVar9 + -0x10);
          state_in->v1 = v1;
          state_in->v2 = v2;
          state_in->v3 = v3;
          state_in->v4 = v4;
        }
        if (p < pBVar9) {
          XXH_memcpy(state_in->mem32,p,(int)pBVar9 - (int)p);
          state_in->memsize = (int)pBVar9 - (int)p;
        }
        XVar8 = XXH_OK;
      }
    }
  }
  else if (input == (void *)0x0) {
    XVar8 = XXH_ERROR;
  }
  else {
    pBVar9 = (BYTE *)(len + (int)input);
    state_in->total_len_32 = state_in->total_len_32 + len;
    sVar5 = len;
    if (0xf < len) {
      sVar5 = 1;
    }
    bVar3 = (byte)sVar5;
    if (len < 0x10) {
      bVar3 = 0;
    }
    uVar6 = state_in->total_len_32;
    uVar7 = uVar6;
    if (0xf < uVar6) {
      uVar7 = 1;
    }
    bVar4 = (byte)uVar7;
    if (uVar6 < 0x10) {
      bVar4 = 0;
    }
    state_in->large_len = (uint)(bVar4 | bVar3) | state_in->large_len;
    if (len + state_in->memsize < 0x10) {
      XXH_memcpy((void *)((int)state_in->mem32 + state_in->memsize),input,len);
      state_in->memsize = state_in->memsize + len;
      XVar8 = XXH_OK;
    }
    else {
      p_1 = (BYTE *)input;
      if (state_in->memsize != 0) {
        XXH_memcpy((void *)((int)state_in->mem32 + state_in->memsize),input,0x10 - state_in->memsize
                  );
        UVar10 = state_in->v1;
        UVar2 = XXH_read32(state_in->mem32);
        UVar2 = XXH32_round(UVar10,UVar2 << 0x18 | (UVar2 >> 8 & 0xff) << 0x10 |
                                   (UVar2 >> 0x10 & 0xff) << 8 | UVar2 >> 0x18);
        state_in->v1 = UVar2;
        UVar10 = state_in->v2;
        UVar2 = XXH_read32(state_in->mem32 + 1);
        UVar2 = XXH32_round(UVar10,UVar2 << 0x18 | (UVar2 >> 8 & 0xff) << 0x10 |
                                   (UVar2 >> 0x10 & 0xff) << 8 | UVar2 >> 0x18);
        state_in->v2 = UVar2;
        UVar10 = state_in->v3;
        UVar2 = XXH_read32(state_in->mem32 + 2);
        UVar2 = XXH32_round(UVar10,UVar2 << 0x18 | (UVar2 >> 8 & 0xff) << 0x10 |
                                   (UVar2 >> 0x10 & 0xff) << 8 | UVar2 >> 0x18);
        state_in->v3 = UVar2;
        UVar10 = state_in->v4;
        UVar2 = XXH_read32(state_in->mem32 + 3);
        UVar2 = XXH32_round(UVar10,UVar2 << 0x18 | (UVar2 >> 8 & 0xff) << 0x10 |
                                   (UVar2 >> 0x10 & 0xff) << 8 | UVar2 >> 0x18);
        state_in->v4 = UVar2;
        p_1 = (BYTE *)((0x10 - state_in->memsize) + (int)input);
        state_in->memsize = 0;
      }
      if (p_1 <= pBVar9 + -0x10) {
        v1_1 = state_in->v1;
        v2_1 = state_in->v2;
        v3_1 = state_in->v3;
        v4_1 = state_in->v4;
        do {
          UVar2 = XXH_read32(p_1);
          v1_1 = XXH32_round(v1_1,UVar2 << 0x18 | (UVar2 >> 8 & 0xff) << 0x10 |
                                  (UVar2 >> 0x10 & 0xff) << 8 | UVar2 >> 0x18);
          UVar2 = XXH_read32(p_1 + 4);
          v2_1 = XXH32_round(v2_1,UVar2 << 0x18 | (UVar2 >> 8 & 0xff) << 0x10 |
                                  (UVar2 >> 0x10 & 0xff) << 8 | UVar2 >> 0x18);
          UVar2 = XXH_read32(p_1 + 8);
          v3_1 = XXH32_round(v3_1,UVar2 << 0x18 | (UVar2 >> 8 & 0xff) << 0x10 |
                                  (UVar2 >> 0x10 & 0xff) << 8 | UVar2 >> 0x18);
          UVar2 = XXH_read32(p_1 + 0xc);
          v4_1 = XXH32_round(v4_1,UVar2 << 0x18 | (UVar2 >> 8 & 0xff) << 0x10 |
                                  (UVar2 >> 0x10 & 0xff) << 8 | UVar2 >> 0x18);
          p_1 = p_1 + 0x10;
        } while (p_1 <= pBVar9 + -0x10);
        state_in->v1 = v1_1;
        state_in->v2 = v2_1;
        state_in->v3 = v3_1;
        state_in->v4 = v4_1;
      }
      if (p_1 < pBVar9) {
        XXH_memcpy(state_in->mem32,p_1,(int)pBVar9 - (int)p_1);
        state_in->memsize = (int)pBVar9 - (int)p_1;
      }
      XVar8 = XXH_OK;
    }
  }
  return XVar8;
}

