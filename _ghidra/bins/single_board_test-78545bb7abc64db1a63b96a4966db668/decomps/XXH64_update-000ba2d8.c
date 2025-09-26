
/* WARNING: Removing unreachable block (ram,0x000bafc2) */
/* WARNING: Removing unreachable block (ram,0x000bb0a4) */
/* WARNING: Removing unreachable block (ram,0x000bb0ba) */
/* WARNING: Removing unreachable block (ram,0x000bb0ae) */
/* WARNING: Removing unreachable block (ram,0x000baf30) */
/* WARNING: Removing unreachable block (ram,0x000baf46) */
/* WARNING: Removing unreachable block (ram,0x000baf3a) */
/* WARNING: Removing unreachable block (ram,0x000bad58) */
/* WARNING: Removing unreachable block (ram,0x000bad26) */
/* WARNING: Removing unreachable block (ram,0x000bac92) */
/* WARNING: Removing unreachable block (ram,0x000baca8) */
/* WARNING: Removing unreachable block (ram,0x000babe0) */
/* WARNING: Removing unreachable block (ram,0x000babae) */
/* WARNING: Removing unreachable block (ram,0x000bab1a) */
/* WARNING: Removing unreachable block (ram,0x000bab30) */
/* WARNING: Removing unreachable block (ram,0x000ba7c2) */
/* WARNING: Removing unreachable block (ram,0x000ba7ca) */
/* WARNING: Removing unreachable block (ram,0x000ba84a) */
/* WARNING: Removing unreachable block (ram,0x000ba7d4) */
/* WARNING: Removing unreachable block (ram,0x000ba724) */
/* WARNING: Removing unreachable block (ram,0x000ba736) */
/* WARNING: Removing unreachable block (ram,0x000ba72c) */
/* WARNING: Removing unreachable block (ram,0x000ba61a) */
/* WARNING: Removing unreachable block (ram,0x000ba62c) */
/* WARNING: Removing unreachable block (ram,0x000ba622) */
/* WARNING: Removing unreachable block (ram,0x000ba57c) */
/* WARNING: Removing unreachable block (ram,0x000ba58e) */
/* WARNING: Removing unreachable block (ram,0x000ba584) */
/* WARNING: Removing unreachable block (ram,0x000ba4de) */
/* WARNING: Removing unreachable block (ram,0x000ba4f0) */
/* WARNING: Removing unreachable block (ram,0x000ba4e6) */
/* WARNING: Removing unreachable block (ram,0x000ba440) */
/* WARNING: Removing unreachable block (ram,0x000ba448) */
/* WARNING: Removing unreachable block (ram,0x000ba452) */
/* WARNING: Removing unreachable block (ram,0x000baaf2) */
/* WARNING: Removing unreachable block (ram,0x000ba42a) */
/* WARNING: Removing unreachable block (ram,0x000ba4c8) */
/* WARNING: Removing unreachable block (ram,0x000ba566) */
/* WARNING: Removing unreachable block (ram,0x000ba604) */
/* WARNING: Removing unreachable block (ram,0x000ba70e) */
/* WARNING: Removing unreachable block (ram,0x000ba7ac) */
/* WARNING: Removing unreachable block (ram,0x000ba8fe) */
/* WARNING: Removing unreachable block (ram,0x000ba910) */
/* WARNING: Removing unreachable block (ram,0x000ba906) */
/* WARNING: Removing unreachable block (ram,0x000ba860) */
/* WARNING: Removing unreachable block (ram,0x000ba872) */
/* WARNING: Removing unreachable block (ram,0x000ba868) */
/* WARNING: Removing unreachable block (ram,0x000bab24) */
/* WARNING: Removing unreachable block (ram,0x000babd6) */
/* WARNING: Removing unreachable block (ram,0x000babec) */
/* WARNING: Removing unreachable block (ram,0x000bac6a) */
/* WARNING: Removing unreachable block (ram,0x000bac9c) */
/* WARNING: Removing unreachable block (ram,0x000bad4e) */
/* WARNING: Removing unreachable block (ram,0x000bad64) */
/* WARNING: Removing unreachable block (ram,0x000bae76) */
/* WARNING: Removing unreachable block (ram,0x000bae8c) */
/* WARNING: Removing unreachable block (ram,0x000bae80) */
/* WARNING: Removing unreachable block (ram,0x000bafea) */
/* WARNING: Removing unreachable block (ram,0x000bb000) */
/* WARNING: Removing unreachable block (ram,0x000baff4) */
/* WARNING: Removing unreachable block (ram,0x000bae4e) */
/* WARNING: Removing unreachable block (ram,0x000baf08) */
/* WARNING: Removing unreachable block (ram,0x000ba8e8) */
/* WARNING: Removing unreachable block (ram,0x000bb07c) */

XXH_errorcode XXH64_update(XXH64_state_t *state_in,void *input,size_t len)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  XXH_errorcode XVar4;
  BYTE *pBVar5;
  U64 UVar6;
  U64 UVar7;
  size_t len_local;
  void *input_local;
  XXH64_state_t *state_in_local;
  U64 v4_1;
  U64 v3_1;
  U64 v2_1;
  U64 v1_1;
  BYTE *limit_1;
  BYTE *bEnd_1;
  BYTE *p_1;
  U64 v4;
  U64 v3;
  U64 v2;
  U64 v1;
  BYTE *limit;
  BYTE *bEnd;
  BYTE *p;
  XXH_endianess endian_detected;
  
  iVar1 = XXH_isLittleEndian();
  if (iVar1 == 1) {
    if (input == (void *)0x0) {
      XVar4 = XXH_ERROR;
    }
    else {
      pBVar5 = (BYTE *)(len + (int)input);
      uVar2 = (uint)state_in->total_len;
      iVar1 = *(int *)((int)&state_in->total_len + 4);
      *(size_t *)&state_in->total_len = len + uVar2;
      *(uint *)((int)&state_in->total_len + 4) = iVar1 + (uint)CARRY4(len,uVar2);
      if (len + state_in->memsize < 0x20) {
        XXH_memcpy((void *)((int)state_in->mem64 + state_in->memsize),input,len);
        state_in->memsize = state_in->memsize + len;
        XVar4 = XXH_OK;
      }
      else {
        p = (BYTE *)input;
        if (state_in->memsize != 0) {
          XXH_memcpy((void *)((int)state_in->mem64 + state_in->memsize),input,
                     0x20 - state_in->memsize);
          UVar7 = state_in->v1;
          UVar6 = XXH_read64(state_in->mem64);
          UVar7 = XXH64_round(UVar7,UVar6);
          state_in->v1 = UVar7;
          UVar7 = state_in->v2;
          UVar6 = XXH_read64(state_in->mem64 + 1);
          UVar7 = XXH64_round(UVar7,UVar6);
          state_in->v2 = UVar7;
          UVar7 = state_in->v3;
          UVar6 = XXH_read64(state_in->mem64 + 2);
          UVar7 = XXH64_round(UVar7,UVar6);
          state_in->v3 = UVar7;
          UVar7 = state_in->v4;
          UVar6 = XXH_read64(state_in->mem64 + 3);
          UVar7 = XXH64_round(UVar7,UVar6);
          state_in->v4 = UVar7;
          p = (BYTE *)((0x20 - state_in->memsize) + (int)input);
          state_in->memsize = 0;
        }
        if (p + 0x20 <= pBVar5) {
          v1 = state_in->v1;
          v2 = state_in->v2;
          v3 = state_in->v3;
          v4 = state_in->v4;
          do {
            UVar7 = XXH_read64(p);
            v1 = XXH64_round(v1,UVar7);
            UVar7 = XXH_read64(p + 8);
            v2 = XXH64_round(v2,UVar7);
            UVar7 = XXH_read64(p + 0x10);
            v3 = XXH64_round(v3,UVar7);
            UVar7 = XXH_read64(p + 0x18);
            v4 = XXH64_round(v4,UVar7);
            p = p + 0x20;
          } while (p <= pBVar5 + -0x20);
          v1._4_4_ = (undefined4)(v1 >> 0x20);
          *(undefined4 *)&state_in->v1 = (undefined4)v1;
          *(undefined4 *)((int)&state_in->v1 + 4) = v1._4_4_;
          v2._4_4_ = (undefined4)(v2 >> 0x20);
          *(undefined4 *)&state_in->v2 = (undefined4)v2;
          *(undefined4 *)((int)&state_in->v2 + 4) = v2._4_4_;
          v3._4_4_ = (undefined4)(v3 >> 0x20);
          *(undefined4 *)&state_in->v3 = (undefined4)v3;
          *(undefined4 *)((int)&state_in->v3 + 4) = v3._4_4_;
          v4._4_4_ = (undefined4)(v4 >> 0x20);
          *(undefined4 *)&state_in->v4 = (undefined4)v4;
          *(undefined4 *)((int)&state_in->v4 + 4) = v4._4_4_;
        }
        if (p < pBVar5) {
          XXH_memcpy(state_in->mem64,p,(int)pBVar5 - (int)p);
          state_in->memsize = (int)pBVar5 - (int)p;
        }
        XVar4 = XXH_OK;
      }
    }
  }
  else if (input == (void *)0x0) {
    XVar4 = XXH_ERROR;
  }
  else {
    pBVar5 = (BYTE *)(len + (int)input);
    uVar2 = (uint)state_in->total_len;
    iVar1 = *(int *)((int)&state_in->total_len + 4);
    *(size_t *)&state_in->total_len = len + uVar2;
    *(uint *)((int)&state_in->total_len + 4) = iVar1 + (uint)CARRY4(len,uVar2);
    if (len + state_in->memsize < 0x20) {
      XXH_memcpy((void *)((int)state_in->mem64 + state_in->memsize),input,len);
      state_in->memsize = state_in->memsize + len;
      XVar4 = XXH_OK;
    }
    else {
      p_1 = (BYTE *)input;
      if (state_in->memsize != 0) {
        XXH_memcpy((void *)((int)state_in->mem64 + state_in->memsize),input,0x20 - state_in->memsize
                  );
        UVar7 = state_in->v1;
        UVar6 = XXH_read64(state_in->mem64);
        uVar3 = (uint)(UVar6 >> 0x20);
        uVar2 = (uint)UVar6;
        UVar7 = XXH64_round(UVar7,CONCAT44((int)(UVar6 & 0xff000000ff) << 0x18 |
                                           (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8
                                           | uVar2 >> 0x18,
                                           (int)((UVar6 & 0xff000000ff) >> 0x20) << 0x18 |
                                           (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8
                                           | uVar3 >> 0x18));
        state_in->v1 = UVar7;
        UVar7 = state_in->v2;
        UVar6 = XXH_read64(state_in->mem64 + 1);
        uVar3 = (uint)(UVar6 >> 0x20);
        uVar2 = (uint)UVar6;
        UVar7 = XXH64_round(UVar7,CONCAT44((int)(UVar6 & 0xff000000ff) << 0x18 |
                                           (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8
                                           | uVar2 >> 0x18,
                                           (int)((UVar6 & 0xff000000ff) >> 0x20) << 0x18 |
                                           (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8
                                           | uVar3 >> 0x18));
        state_in->v2 = UVar7;
        UVar7 = state_in->v3;
        UVar6 = XXH_read64(state_in->mem64 + 2);
        uVar3 = (uint)(UVar6 >> 0x20);
        uVar2 = (uint)UVar6;
        UVar7 = XXH64_round(UVar7,CONCAT44((int)(UVar6 & 0xff000000ff) << 0x18 |
                                           (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8
                                           | uVar2 >> 0x18,
                                           (int)((UVar6 & 0xff000000ff) >> 0x20) << 0x18 |
                                           (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8
                                           | uVar3 >> 0x18));
        state_in->v3 = UVar7;
        UVar7 = state_in->v4;
        UVar6 = XXH_read64(state_in->mem64 + 3);
        uVar3 = (uint)(UVar6 >> 0x20);
        uVar2 = (uint)UVar6;
        UVar7 = XXH64_round(UVar7,CONCAT44((int)(UVar6 & 0xff000000ff) << 0x18 |
                                           (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8
                                           | uVar2 >> 0x18,
                                           (int)((UVar6 & 0xff000000ff) >> 0x20) << 0x18 |
                                           (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8
                                           | uVar3 >> 0x18));
        state_in->v4 = UVar7;
        p_1 = (BYTE *)((0x20 - state_in->memsize) + (int)input);
        state_in->memsize = 0;
      }
      if (p_1 + 0x20 <= pBVar5) {
        v1_1 = state_in->v1;
        v2_1 = state_in->v2;
        v3_1 = state_in->v3;
        v4_1 = state_in->v4;
        do {
          UVar7 = XXH_read64(p_1);
          uVar3 = (uint)(UVar7 >> 0x20);
          uVar2 = (uint)UVar7;
          v1_1 = XXH64_round(v1_1,CONCAT44((int)(UVar7 & 0xff000000ff) << 0x18 |
                                           (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8
                                           | uVar2 >> 0x18,
                                           (int)((UVar7 & 0xff000000ff) >> 0x20) << 0x18 |
                                           (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8
                                           | uVar3 >> 0x18));
          UVar7 = XXH_read64(p_1 + 8);
          uVar3 = (uint)(UVar7 >> 0x20);
          uVar2 = (uint)UVar7;
          v2_1 = XXH64_round(v2_1,CONCAT44((int)(UVar7 & 0xff000000ff) << 0x18 |
                                           (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8
                                           | uVar2 >> 0x18,
                                           (int)((UVar7 & 0xff000000ff) >> 0x20) << 0x18 |
                                           (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8
                                           | uVar3 >> 0x18));
          UVar7 = XXH_read64(p_1 + 0x10);
          uVar3 = (uint)(UVar7 >> 0x20);
          uVar2 = (uint)UVar7;
          v3_1 = XXH64_round(v3_1,CONCAT44((int)(UVar7 & 0xff000000ff) << 0x18 |
                                           (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8
                                           | uVar2 >> 0x18,
                                           (int)((UVar7 & 0xff000000ff) >> 0x20) << 0x18 |
                                           (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8
                                           | uVar3 >> 0x18));
          UVar7 = XXH_read64(p_1 + 0x18);
          uVar3 = (uint)(UVar7 >> 0x20);
          uVar2 = (uint)UVar7;
          v4_1 = XXH64_round(v4_1,CONCAT44((int)(UVar7 & 0xff000000ff) << 0x18 |
                                           (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8
                                           | uVar2 >> 0x18,
                                           (int)((UVar7 & 0xff000000ff) >> 0x20) << 0x18 |
                                           (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8
                                           | uVar3 >> 0x18));
          p_1 = p_1 + 0x20;
        } while (p_1 <= pBVar5 + -0x20);
        v1_1._4_4_ = (undefined4)(v1_1 >> 0x20);
        *(undefined4 *)&state_in->v1 = (undefined4)v1_1;
        *(undefined4 *)((int)&state_in->v1 + 4) = v1_1._4_4_;
        v2_1._4_4_ = (undefined4)(v2_1 >> 0x20);
        *(undefined4 *)&state_in->v2 = (undefined4)v2_1;
        *(undefined4 *)((int)&state_in->v2 + 4) = v2_1._4_4_;
        v3_1._4_4_ = (undefined4)(v3_1 >> 0x20);
        *(undefined4 *)&state_in->v3 = (undefined4)v3_1;
        *(undefined4 *)((int)&state_in->v3 + 4) = v3_1._4_4_;
        v4_1._4_4_ = (undefined4)(v4_1 >> 0x20);
        *(undefined4 *)&state_in->v4 = (undefined4)v4_1;
        *(undefined4 *)((int)&state_in->v4 + 4) = v4_1._4_4_;
      }
      if (p_1 < pBVar5) {
        XXH_memcpy(state_in->mem64,p_1,(int)pBVar5 - (int)p_1);
        state_in->memsize = (int)pBVar5 - (int)p_1;
      }
      XVar4 = XXH_OK;
    }
  }
  return XVar4;
}

