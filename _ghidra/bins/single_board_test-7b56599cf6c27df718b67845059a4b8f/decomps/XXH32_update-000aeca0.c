
/* WARNING: Removing unreachable block (ram,0x000af826) */
/* WARNING: Removing unreachable block (ram,0x000af8e4) */
/* WARNING: Removing unreachable block (ram,0x000af8f8) */
/* WARNING: Removing unreachable block (ram,0x000af8ee) */
/* WARNING: Removing unreachable block (ram,0x000af7a4) */
/* WARNING: Removing unreachable block (ram,0x000af7b8) */
/* WARNING: Removing unreachable block (ram,0x000af7ae) */
/* WARNING: Removing unreachable block (ram,0x000af610) */
/* WARNING: Removing unreachable block (ram,0x000af5e8) */
/* WARNING: Removing unreachable block (ram,0x000af562) */
/* WARNING: Removing unreachable block (ram,0x000af576) */
/* WARNING: Removing unreachable block (ram,0x000af4c8) */
/* WARNING: Removing unreachable block (ram,0x000af4a0) */
/* WARNING: Removing unreachable block (ram,0x000af41e) */
/* WARNING: Removing unreachable block (ram,0x000af430) */
/* WARNING: Removing unreachable block (ram,0x000af118) */
/* WARNING: Removing unreachable block (ram,0x000af120) */
/* WARNING: Removing unreachable block (ram,0x000af18a) */
/* WARNING: Removing unreachable block (ram,0x000af128) */
/* WARNING: Removing unreachable block (ram,0x000af098) */
/* WARNING: Removing unreachable block (ram,0x000af0a8) */
/* WARNING: Removing unreachable block (ram,0x000af0a0) */
/* WARNING: Removing unreachable block (ram,0x000aefc0) */
/* WARNING: Removing unreachable block (ram,0x000aefd0) */
/* WARNING: Removing unreachable block (ram,0x000aefc8) */
/* WARNING: Removing unreachable block (ram,0x000aef38) */
/* WARNING: Removing unreachable block (ram,0x000aef48) */
/* WARNING: Removing unreachable block (ram,0x000aef40) */
/* WARNING: Removing unreachable block (ram,0x000aeeb0) */
/* WARNING: Removing unreachable block (ram,0x000aeec0) */
/* WARNING: Removing unreachable block (ram,0x000aeeb8) */
/* WARNING: Removing unreachable block (ram,0x000aee28) */
/* WARNING: Removing unreachable block (ram,0x000aee30) */
/* WARNING: Removing unreachable block (ram,0x000aee38) */
/* WARNING: Removing unreachable block (ram,0x000af404) */
/* WARNING: Removing unreachable block (ram,0x000aee1a) */
/* WARNING: Removing unreachable block (ram,0x000aeea2) */
/* WARNING: Removing unreachable block (ram,0x000aef2a) */
/* WARNING: Removing unreachable block (ram,0x000aefb2) */
/* WARNING: Removing unreachable block (ram,0x000af08a) */
/* WARNING: Removing unreachable block (ram,0x000af10a) */
/* WARNING: Removing unreachable block (ram,0x000af218) */
/* WARNING: Removing unreachable block (ram,0x000af228) */
/* WARNING: Removing unreachable block (ram,0x000af220) */
/* WARNING: Removing unreachable block (ram,0x000af198) */
/* WARNING: Removing unreachable block (ram,0x000af1a8) */
/* WARNING: Removing unreachable block (ram,0x000af1a0) */
/* WARNING: Removing unreachable block (ram,0x000af428) */
/* WARNING: Removing unreachable block (ram,0x000af4be) */
/* WARNING: Removing unreachable block (ram,0x000af4d2) */
/* WARNING: Removing unreachable block (ram,0x000af544) */
/* WARNING: Removing unreachable block (ram,0x000af56c) */
/* WARNING: Removing unreachable block (ram,0x000af606) */
/* WARNING: Removing unreachable block (ram,0x000af61a) */
/* WARNING: Removing unreachable block (ram,0x000af704) */
/* WARNING: Removing unreachable block (ram,0x000af718) */
/* WARNING: Removing unreachable block (ram,0x000af70e) */
/* WARNING: Removing unreachable block (ram,0x000af844) */
/* WARNING: Removing unreachable block (ram,0x000af858) */
/* WARNING: Removing unreachable block (ram,0x000af84e) */
/* WARNING: Removing unreachable block (ram,0x000af6e6) */
/* WARNING: Removing unreachable block (ram,0x000af786) */
/* WARNING: Removing unreachable block (ram,0x000af20a) */
/* WARNING: Removing unreachable block (ram,0x000af8c6) */

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

