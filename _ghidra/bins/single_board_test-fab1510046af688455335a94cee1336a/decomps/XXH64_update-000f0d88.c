
/* WARNING: Removing unreachable block (ram,0x000f1a84) */
/* WARNING: Removing unreachable block (ram,0x000f1b66) */
/* WARNING: Removing unreachable block (ram,0x000f1b7c) */
/* WARNING: Removing unreachable block (ram,0x000f1b70) */
/* WARNING: Removing unreachable block (ram,0x000f19f2) */
/* WARNING: Removing unreachable block (ram,0x000f1a08) */
/* WARNING: Removing unreachable block (ram,0x000f19fc) */
/* WARNING: Removing unreachable block (ram,0x000f181a) */
/* WARNING: Removing unreachable block (ram,0x000f17e8) */
/* WARNING: Removing unreachable block (ram,0x000f1752) */
/* WARNING: Removing unreachable block (ram,0x000f1768) */
/* WARNING: Removing unreachable block (ram,0x000f169e) */
/* WARNING: Removing unreachable block (ram,0x000f166c) */
/* WARNING: Removing unreachable block (ram,0x000f15d6) */
/* WARNING: Removing unreachable block (ram,0x000f15ec) */
/* WARNING: Removing unreachable block (ram,0x000f1278) */
/* WARNING: Removing unreachable block (ram,0x000f1280) */
/* WARNING: Removing unreachable block (ram,0x000f1300) */
/* WARNING: Removing unreachable block (ram,0x000f128a) */
/* WARNING: Removing unreachable block (ram,0x000f11da) */
/* WARNING: Removing unreachable block (ram,0x000f11ec) */
/* WARNING: Removing unreachable block (ram,0x000f11e2) */
/* WARNING: Removing unreachable block (ram,0x000f10d0) */
/* WARNING: Removing unreachable block (ram,0x000f10e2) */
/* WARNING: Removing unreachable block (ram,0x000f10d8) */
/* WARNING: Removing unreachable block (ram,0x000f1030) */
/* WARNING: Removing unreachable block (ram,0x000f1042) */
/* WARNING: Removing unreachable block (ram,0x000f1038) */
/* WARNING: Removing unreachable block (ram,0x000f0f90) */
/* WARNING: Removing unreachable block (ram,0x000f0fa2) */
/* WARNING: Removing unreachable block (ram,0x000f0f98) */
/* WARNING: Removing unreachable block (ram,0x000f0ef0) */
/* WARNING: Removing unreachable block (ram,0x000f0ef8) */
/* WARNING: Removing unreachable block (ram,0x000f0f02) */
/* WARNING: Removing unreachable block (ram,0x000f15ae) */
/* WARNING: Removing unreachable block (ram,0x000f0eda) */
/* WARNING: Removing unreachable block (ram,0x000f0f7a) */
/* WARNING: Removing unreachable block (ram,0x000f101a) */
/* WARNING: Removing unreachable block (ram,0x000f10ba) */
/* WARNING: Removing unreachable block (ram,0x000f11c4) */
/* WARNING: Removing unreachable block (ram,0x000f1262) */
/* WARNING: Removing unreachable block (ram,0x000f13b4) */
/* WARNING: Removing unreachable block (ram,0x000f13c6) */
/* WARNING: Removing unreachable block (ram,0x000f13bc) */
/* WARNING: Removing unreachable block (ram,0x000f1316) */
/* WARNING: Removing unreachable block (ram,0x000f1328) */
/* WARNING: Removing unreachable block (ram,0x000f131e) */
/* WARNING: Removing unreachable block (ram,0x000f15e0) */
/* WARNING: Removing unreachable block (ram,0x000f1694) */
/* WARNING: Removing unreachable block (ram,0x000f16aa) */
/* WARNING: Removing unreachable block (ram,0x000f172a) */
/* WARNING: Removing unreachable block (ram,0x000f175c) */
/* WARNING: Removing unreachable block (ram,0x000f1810) */
/* WARNING: Removing unreachable block (ram,0x000f1826) */
/* WARNING: Removing unreachable block (ram,0x000f1938) */
/* WARNING: Removing unreachable block (ram,0x000f194e) */
/* WARNING: Removing unreachable block (ram,0x000f1942) */
/* WARNING: Removing unreachable block (ram,0x000f1aac) */
/* WARNING: Removing unreachable block (ram,0x000f1ac2) */
/* WARNING: Removing unreachable block (ram,0x000f1ab6) */
/* WARNING: Removing unreachable block (ram,0x000f1910) */
/* WARNING: Removing unreachable block (ram,0x000f19ca) */
/* WARNING: Removing unreachable block (ram,0x000f139e) */
/* WARNING: Removing unreachable block (ram,0x000f1b3e) */

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

