
/* WARNING: Removing unreachable block (ram,0x0009e0bc) */
/* WARNING: Removing unreachable block (ram,0x00099188) */
/* WARNING: Removing unreachable block (ram,0x000991de) */
/* WARNING: Removing unreachable block (ram,0x000991e0) */
/* WARNING: Removing unreachable block (ram,0x000991f2) */
/* WARNING: Removing unreachable block (ram,0x00099202) */
/* WARNING: Removing unreachable block (ram,0x000991e4) */
/* WARNING: Removing unreachable block (ram,0x0009922a) */
/* WARNING: Removing unreachable block (ram,0x00098a70) */
/* WARNING: Removing unreachable block (ram,0x00098ac6) */
/* WARNING: Removing unreachable block (ram,0x00098ac8) */
/* WARNING: Removing unreachable block (ram,0x00098ada) */
/* WARNING: Removing unreachable block (ram,0x00098aea) */
/* WARNING: Removing unreachable block (ram,0x00098acc) */
/* WARNING: Removing unreachable block (ram,0x00098b12) */
/* WARNING: Removing unreachable block (ram,0x000999b0) */
/* WARNING: Removing unreachable block (ram,0x00099a0c) */
/* WARNING: Removing unreachable block (ram,0x00099a0e) */
/* WARNING: Removing unreachable block (ram,0x00099a20) */
/* WARNING: Removing unreachable block (ram,0x00099a30) */
/* WARNING: Removing unreachable block (ram,0x00099a12) */
/* WARNING: Removing unreachable block (ram,0x00099a58) */
/* WARNING: Removing unreachable block (ram,0x0009e272) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int LZ4HC_compress_generic_dictCtx
              (LZ4HC_CCtx_internal *ctx,char *src,char *dst,int *srcSizePtr,int dstCapacity,
              int cLevel,limitedOutput_directive limit)

{
  short sVar1;
  cParams_t *pcVar2;
  U16 UVar3;
  U16 UVar4;
  int iVar5;
  U32 UVar6;
  U32 UVar7;
  int iVar8;
  reg_t rVar9;
  reg_t rVar10;
  BYTE *pBVar11;
  LZ4_byte *pLVar12;
  int iVar13;
  uint uVar14;
  BYTE *pBVar15;
  LZ4_byte *pLVar16;
  undefined4 uVar17;
  char cVar18;
  char cVar19;
  byte bVar20;
  int iVar21;
  int iVar22;
  BYTE *pBVar23;
  BYTE *iEnd;
  LZ4HC_CCtx_internal *pLVar24;
  BYTE *pBVar25;
  BYTE *pBVar26;
  BYTE *pBVar27;
  BYTE *pBVar28;
  BYTE *pBVar29;
  BYTE *pBVar30;
  LZ4_byte *pLVar31;
  LZ4_u32 LVar32;
  LZ4_byte *pLVar33;
  BYTE *pBVar34;
  BYTE *pBVar35;
  BYTE *pBVar36;
  LZ4_byte *pLVar37;
  bool bVar38;
  int *srcSizePtr_local;
  char *dst_local;
  char *src_local;
  LZ4HC_CCtx_internal *ctx_local;
  BYTE *uselessPtr;
  BYTE *ref3;
  BYTE *start3;
  BYTE *ref2;
  BYTE *start2;
  BYTE *ref;
  BYTE *op;
  BYTE *anchor;
  BYTE *ip;
  cParams_t cParam;
  int result;
  BYTE *e_5;
  BYTE *s_5;
  BYTE *d_5;
  size_t len_5;
  size_t length_5;
  BYTE *token_5;
  size_t maxMlSize;
  size_t bytesLeftForMl;
  BYTE *maxLitPos;
  size_t ll_totalCost;
  size_t ll_addbytes;
  size_t ll;
  size_t accumulator;
  size_t totalSize;
  size_t llAdd;
  size_t lastRunSize;
  BYTE *e_4;
  BYTE *s_4;
  BYTE *d_4;
  size_t len_4;
  size_t length_4;
  BYTE *token_4;
  int correction_2;
  BYTE *e_3;
  BYTE *s_3;
  BYTE *d_3;
  size_t len_3;
  size_t length_3;
  BYTE *token_3;
  int correction_1;
  BYTE *e_2;
  BYTE *s_2;
  BYTE *d_2;
  size_t len_2;
  size_t length_2;
  BYTE *token_2;
  BYTE *e_1;
  BYTE *s_1;
  BYTE *d_1;
  size_t len_1;
  size_t length_1;
  BYTE *token_1;
  int ml3;
  U32 nextOffset_2;
  int min_8;
  int back_17;
  int mlt_2;
  reg_t diff_23;
  reg_t diff_22;
  BYTE *pStart_11;
  LZ4_byte *local_5c8;
  LZ4_byte *local_5c4;
  BYTE *vLimit_5;
  int back_16;
  BYTE *matchPtr_11;
  U32 dictMatchIndex_2;
  size_t dictEndOffset_2;
  U32 distToNextPattern_2;
  size_t maxML_2;
  U32 newMatchIndex_5;
  U32 newMatchIndex_4;
  size_t currentSegmentLength_2;
  U32 rotatedPattern_5;
  size_t backLength_2;
  BYTE *lowestMatchPtr_2;
  U32 rotatedPattern_4;
  size_t forwardPatternLength_2;
  BYTE *iLimit_2;
  BYTE *matchPtr_10;
  int extDict_2;
  U32 matchCandidateIdx_2;
  U32 distNextMatch_2;
  int min_7;
  int back_15;
  reg_t diff_21;
  reg_t diff_20;
  BYTE *pStart_10;
  BYTE *local_548;
  BYTE *local_544;
  reg_t diff_19;
  reg_t diff_18;
  BYTE *pStart_9;
  BYTE *local_530;
  BYTE *local_52c;
  BYTE *vLimit_4;
  int back_14;
  BYTE *matchPtr_9;
  reg_t diff_17;
  reg_t diff_16;
  BYTE *pStart_8;
  BYTE *local_50c;
  BYTE *local_508;
  int back_12;
  int min_6;
  int back_13;
  BYTE *matchPtr_8;
  int matchLength_2;
  U32 matchIndex_2;
  size_t delta_2;
  U32 h_2;
  U32 idx_2;
  U32 target_2;
  U32 prefixIdx_5;
  BYTE *prefixPtr_5;
  U32 *hashTable_2;
  U16 *chainTable_5;
  size_t srcPatternLength_2;
  repeat_state_e repeat_2;
  U32 pattern_2;
  U32 matchChainPos_2;
  int nbAttempts_2;
  int lookBackLength_2;
  BYTE *dictEnd_2;
  U32 dictIdx_2;
  BYTE *dictStart_2;
  U32 lowestMatchIndex_2;
  int withinStartDistance_2;
  U32 ipIndex_2;
  U32 prefixIdx_4;
  BYTE *prefixPtr_4;
  LZ4HC_CCtx_internal *dictCtx_2;
  U32 *HashTable_2;
  U16 *chainTable_4;
  LZ4_byte *local_45c;
  int correction;
  int new_ml;
  BYTE *e;
  BYTE *s;
  BYTE *d;
  size_t len;
  size_t length;
  BYTE *token;
  int ml2;
  U32 nextOffset_1;
  int min_5;
  int back_11;
  int mlt_1;
  reg_t diff_15;
  reg_t diff_14;
  BYTE *pStart_7;
  LZ4_byte *local_3cc;
  LZ4_byte *local_3c8;
  BYTE *vLimit_3;
  int back_10;
  BYTE *matchPtr_7;
  U32 dictMatchIndex_1;
  size_t dictEndOffset_1;
  U32 distToNextPattern_1;
  size_t maxML_1;
  U32 newMatchIndex_3;
  U32 newMatchIndex_2;
  size_t currentSegmentLength_1;
  U32 rotatedPattern_3;
  size_t backLength_1;
  BYTE *lowestMatchPtr_1;
  U32 rotatedPattern_2;
  size_t forwardPatternLength_1;
  BYTE *iLimit_1;
  BYTE *matchPtr_6;
  int extDict_1;
  U32 matchCandidateIdx_1;
  U32 distNextMatch_1;
  int min_4;
  int back_9;
  reg_t diff_13;
  reg_t diff_12;
  BYTE *pStart_6;
  BYTE *local_34c;
  BYTE *local_348;
  reg_t diff_11;
  reg_t diff_10;
  BYTE *pStart_5;
  BYTE *local_334;
  BYTE *local_330;
  BYTE *vLimit_2;
  int back_8;
  BYTE *matchPtr_5;
  reg_t diff_9;
  reg_t diff_8;
  BYTE *pStart_4;
  BYTE *local_310;
  BYTE *local_30c;
  int back_6;
  int min_3;
  int back_7;
  BYTE *matchPtr_4;
  int matchLength_1;
  U32 matchIndex_1;
  size_t delta_1;
  U32 h_1;
  U32 idx_1;
  U32 target_1;
  U32 prefixIdx_3;
  BYTE *prefixPtr_3;
  U32 *hashTable_1;
  U16 *chainTable_3;
  size_t srcPatternLength_1;
  repeat_state_e repeat_1;
  U32 pattern_1;
  U32 matchChainPos_1;
  int nbAttempts_1;
  int lookBackLength_1;
  BYTE *dictEnd_1;
  U32 dictIdx_1;
  BYTE *dictStart_1;
  U32 lowestMatchIndex_1;
  int withinStartDistance_1;
  U32 ipIndex_1;
  U32 prefixIdx_2;
  BYTE *prefixPtr_2;
  LZ4HC_CCtx_internal *dictCtx_1;
  U32 *HashTable_1;
  U16 *chainTable_2;
  LZ4_byte *local_260;
  int ml0;
  BYTE *ref0;
  BYTE *start0;
  int ml;
  U32 nextOffset;
  int min_2;
  int back_5;
  int mlt;
  reg_t diff_7;
  reg_t diff_6;
  BYTE *pStart_3;
  LZ4_byte *local_20c;
  LZ4_byte *local_208;
  BYTE *vLimit_1;
  int back_4;
  BYTE *matchPtr_3;
  U32 dictMatchIndex;
  size_t dictEndOffset;
  U32 distToNextPattern;
  size_t maxML;
  U32 newMatchIndex_1;
  U32 newMatchIndex;
  size_t currentSegmentLength;
  U32 rotatedPattern_1;
  size_t backLength;
  BYTE *lowestMatchPtr;
  U32 rotatedPattern;
  size_t forwardPatternLength;
  BYTE *iLimit;
  BYTE *matchPtr_2;
  int extDict;
  U32 matchCandidateIdx;
  U32 distNextMatch;
  int min_1;
  int back_3;
  reg_t diff_5;
  reg_t diff_4;
  BYTE *pStart_2;
  BYTE *local_18c;
  BYTE *local_188;
  reg_t diff_3;
  reg_t diff_2;
  BYTE *pStart_1;
  BYTE *local_174;
  BYTE *local_170;
  BYTE *vLimit;
  int back_2;
  BYTE *matchPtr_1;
  reg_t diff_1;
  reg_t diff;
  BYTE *pStart;
  BYTE *local_150;
  BYTE *local_14c;
  int back;
  int min;
  int back_1;
  BYTE *matchPtr;
  int matchLength;
  U32 matchIndex;
  size_t delta;
  U32 h;
  U32 idx;
  U32 target;
  U32 prefixIdx_1;
  BYTE *prefixPtr_1;
  U32 *hashTable;
  U16 *chainTable_1;
  size_t srcPatternLength;
  repeat_state_e repeat;
  U32 pattern;
  U32 matchChainPos;
  int nbAttempts;
  int lookBackLength;
  BYTE *dictEnd;
  U32 dictIdx;
  BYTE *dictStart;
  U32 lowestMatchIndex;
  int withinStartDistance;
  U32 ipIndex;
  U32 prefixIdx;
  BYTE *prefixPtr;
  LZ4HC_CCtx_internal *dictCtx;
  U32 *HashTable;
  U16 *chainTable;
  LZ4_byte *local_a0;
  BYTE *oend;
  BYTE *optr;
  BYTE *matchlimit;
  BYTE *mflimit;
  BYTE *iend;
  int patternAnalysis;
  int inputSize;
  HCfavor_e favor;
  int local_2c;
  size_t position;
  
  if ((LZ4_byte *)0xffff < ctx->end + ((ctx->dictLimit - ctx->lowLimit) - (int)ctx->prefixStart)) {
    ctx->dictCtx = (LZ4HC_CCtx_internal *)0x0;
    iVar5 = LZ4HC_compress_generic_noDictCtx(ctx,src,dst,srcSizePtr,dstCapacity,cLevel,limit);
    return iVar5;
  }
  if ((ctx->end + ((ctx->dictLimit - ctx->lowLimit) - (int)ctx->prefixStart) == (LZ4_byte *)0x0) &&
     (0x1000 < *srcSizePtr)) {
    memcpy(ctx,ctx->dictCtx,0x40020);
    LZ4HC_setExternalDict(ctx,(BYTE *)src);
    ctx->compressionLevel = (short)cLevel;
    iVar5 = LZ4HC_compress_generic_noDictCtx(ctx,src,dst,srcSizePtr,dstCapacity,cLevel,limit);
    return iVar5;
  }
  local_2c = cLevel;
  if ((limit == fillOutput) && (dstCapacity < 1)) {
    return 0;
  }
  if (0x7e000000 < (uint)*srcSizePtr) {
    return 0;
  }
  ctx->end = ctx->end + *srcSizePtr;
  if (cLevel < 1) {
    local_2c = 9;
  }
  if (0xb < local_2c) {
    local_2c = 0xc;
  }
  iVar5 = LZ4HC_compress_generic_internal::clTable[local_2c].nbSearches;
  pcVar2 = LZ4HC_compress_generic_internal::clTable + local_2c;
  if (LZ4HC_compress_generic_internal::clTable[local_2c].strat != lz4hc) {
    bVar38 = local_2c == 0xc;
    if (bVar38) {
      local_2c = 1;
    }
    bVar20 = (byte)local_2c;
    if (!bVar38) {
      bVar20 = 0;
    }
    result = LZ4HC_compress_optimal
                       (ctx,src,dst,srcSizePtr,dstCapacity,iVar5,pcVar2->targetLength,limit,
                        (uint)bVar20,usingDictCtxHc,(uint)(ctx->favorDecSpeed != '\0'));
    goto LAB_0009e402;
  }
  iVar21 = *srcSizePtr;
  iVar22 = iVar5;
  if (0x80 < iVar5) {
    iVar22 = 1;
  }
  cVar18 = (char)iVar22;
  if (iVar5 < 0x81) {
    cVar18 = '\0';
  }
  pBVar23 = (BYTE *)(src + iVar21 + -0xc);
  iEnd = (BYTE *)(src + iVar21 + -5);
  oend = (BYTE *)(dst + dstCapacity);
  ref = (BYTE *)0x0;
  start2 = (BYTE *)0x0;
  ref2 = (BYTE *)0x0;
  start3 = (BYTE *)0x0;
  ref3 = (BYTE *)0x0;
  *srcSizePtr = 0;
  if (limit == fillOutput) {
    oend = oend + -5;
  }
  op = (BYTE *)dst;
  anchor = (BYTE *)src;
  ip = (BYTE *)src;
  if (0xc < iVar21) {
LAB_0009dd80:
    if (ip <= pBVar23) {
      local_a0 = (LZ4_byte *)0x3;
      pLVar24 = ctx->dictCtx;
      pBVar25 = ctx->prefixStart;
      pBVar26 = (BYTE *)ctx->dictLimit;
      pBVar27 = ip + ((int)pBVar26 - (int)pBVar25);
      pBVar28 = (BYTE *)(ctx->lowLimit + 0x10000);
      bVar38 = pBVar27 < pBVar28;
      if (bVar38) {
        pBVar28 = (BYTE *)0x1;
      }
      cVar19 = (char)pBVar28;
      if (!bVar38) {
        cVar19 = '\0';
      }
      if (cVar19 == '\0') {
        pBVar28 = pBVar27 + -0xffff;
      }
      else {
        pBVar28 = (BYTE *)ctx->lowLimit;
      }
      pBVar29 = ctx->dictStart;
      pBVar30 = (BYTE *)ctx->lowLimit;
      UVar6 = LZ4_read32(ip);
      repeat = rep_untested;
      srcPatternLength = 0;
      pLVar31 = ctx->prefixStart;
      LVar32 = ctx->dictLimit;
      for (idx = ctx->nextToUpdate; idx < ip + (LVar32 - (int)pLVar31); idx = idx + 1) {
        UVar7 = LZ4HC_hashPtr(pLVar31 + (idx - LVar32));
        delta = idx - ctx->hashTable[UVar7];
        if (0xffff < delta) {
          delta = 0xffff;
        }
        ctx->chainTable[idx & 0xffff] = (LZ4_u16)delta;
        ctx->hashTable[UVar7] = idx;
      }
      ctx->nextToUpdate = (LZ4_u32)(ip + (LVar32 - (int)pLVar31));
      UVar7 = LZ4HC_hashPtr(ip);
      matchIndex = ctx->hashTable[UVar7];
      nbAttempts = iVar5;
LAB_000996c8:
      do {
        if ((matchIndex < pBVar28) || (nbAttempts < 1)) goto LAB_000996e0;
        nbAttempts = nbAttempts + -1;
        if (matchIndex < pBVar26) {
          pBVar35 = pBVar29 + (matchIndex - (int)pBVar30);
          pBVar15 = pBVar26 + -4;
          pBVar34 = pBVar15;
          if (matchIndex <= pBVar15) {
            pBVar34 = (BYTE *)0x1;
          }
          cVar19 = (char)pBVar34;
          if (pBVar15 < matchIndex) {
            cVar19 = '\0';
          }
          if ((cVar19 == '\0') || (UVar7 = LZ4_read32(pBVar35), UVar6 != UVar7)) goto LAB_0009929c;
          vLimit = ip + ((int)pBVar26 - matchIndex);
          if (iEnd < ip + ((int)pBVar26 - matchIndex)) {
            vLimit = iEnd;
          }
          pBVar34 = ip + 4;
          local_174 = pBVar35 + 4;
          pBVar15 = vLimit + -3;
          bVar38 = pBVar34 < pBVar15;
          if (bVar38) {
            pBVar15 = (BYTE *)0x1;
          }
          cVar19 = (char)pBVar15;
          if (!bVar38) {
            cVar19 = '\0';
          }
          local_170 = pBVar34;
          if (cVar19 == '\0') {
LAB_00098ed6:
            while( true ) {
              pBVar35 = vLimit + -3;
              bVar38 = local_170 < pBVar35;
              if (bVar38) {
                pBVar35 = (BYTE *)0x1;
              }
              cVar19 = (char)pBVar35;
              if (!bVar38) {
                cVar19 = '\0';
              }
              if (cVar19 == '\0') {
                if (local_170 < vLimit + -1) {
                  UVar3 = LZ4_read16(local_174);
                  UVar4 = LZ4_read16(local_170);
                  if (UVar3 == UVar4) {
                    local_170 = local_170 + 2;
                    local_174 = local_174 + 2;
                  }
                }
                if ((local_170 < vLimit) && (*local_174 == *local_170)) {
                  local_170 = local_170 + 1;
                }
                local_170 = local_170 + -(int)pBVar34;
                goto LAB_00098f7e;
              }
              rVar9 = LZ4_read_ARCH(local_174);
              rVar10 = LZ4_read_ARCH(local_170);
              if ((rVar10 ^ rVar9) != 0) break;
              local_170 = local_170 + 4;
              local_174 = local_174 + 4;
            }
            uVar14 = LZ4_NbCommonBytes(rVar10 ^ rVar9);
            local_170 = local_170 + (uVar14 - (int)pBVar34);
          }
          else {
            rVar9 = LZ4_read_ARCH(local_174);
            rVar10 = LZ4_read_ARCH(pBVar34);
            if ((rVar10 ^ rVar9) == 0) {
              local_170 = ip + 8;
              local_174 = pBVar35 + 8;
              goto LAB_00098ed6;
            }
            local_170 = (BYTE *)LZ4_NbCommonBytes(rVar10 ^ rVar9);
          }
LAB_00098f7e:
          matchLength = (int)(local_170 + 4);
          if ((vLimit == ip + matchLength) && (vLimit < iEnd)) {
            pBVar34 = ip + matchLength;
            pBVar35 = (BYTE *)(src + iVar21 + -8);
            bVar38 = pBVar34 < pBVar35;
            if (bVar38) {
              pBVar35 = (BYTE *)0x1;
            }
            cVar19 = (char)pBVar35;
            if (!bVar38) {
              cVar19 = '\0';
            }
            local_18c = pBVar25;
            local_188 = pBVar34;
            if (cVar19 == '\0') {
LAB_000990c8:
              while( true ) {
                pBVar35 = (BYTE *)(src + iVar21 + -8);
                bVar38 = local_188 < pBVar35;
                if (bVar38) {
                  pBVar35 = (BYTE *)0x1;
                }
                cVar19 = (char)pBVar35;
                if (!bVar38) {
                  cVar19 = '\0';
                }
                if (cVar19 == '\0') {
                  if (local_188 < src + iVar21 + -6) {
                    UVar3 = LZ4_read16(local_18c);
                    UVar4 = LZ4_read16(local_188);
                    if (UVar3 == UVar4) {
                      local_188 = local_188 + 2;
                      local_18c = local_18c + 2;
                    }
                  }
                  if ((local_188 < iEnd) && (*local_18c == *local_188)) {
                    local_188 = local_188 + 1;
                  }
                  local_188 = local_188 + -(int)pBVar34;
                  goto LAB_00099172;
                }
                rVar9 = LZ4_read_ARCH(local_18c);
                rVar10 = LZ4_read_ARCH(local_188);
                if ((rVar10 ^ rVar9) != 0) break;
                local_188 = local_188 + 4;
                local_18c = local_18c + 4;
              }
              uVar14 = LZ4_NbCommonBytes(rVar10 ^ rVar9);
              local_188 = local_188 + (uVar14 - (int)pBVar34);
            }
            else {
              rVar9 = LZ4_read_ARCH(pBVar25);
              rVar10 = LZ4_read_ARCH(pBVar34);
              if ((rVar10 ^ rVar9) == 0) {
                local_188 = pBVar34 + 4;
                local_18c = pBVar25 + 4;
                goto LAB_000990c8;
              }
              local_188 = (BYTE *)LZ4_NbCommonBytes(rVar10 ^ rVar9);
            }
LAB_00099172:
            matchLength = (int)(local_188 + matchLength);
          }
          if ((int)local_a0 < matchLength) {
            ref = pBVar25 + (matchIndex - (int)pBVar26);
            local_a0 = (LZ4_byte *)matchLength;
          }
        }
        else {
          pBVar34 = pBVar25 + (matchIndex - (int)pBVar26);
          UVar3 = LZ4_read16(ip + (int)(local_a0 + -1));
          UVar4 = LZ4_read16(pBVar34 + (int)(local_a0 + -1));
          if ((UVar3 == UVar4) && (UVar7 = LZ4_read32(pBVar34), UVar6 == UVar7)) {
            pBVar35 = ip + 4;
            local_150 = pBVar34 + 4;
            pBVar15 = (BYTE *)(src + iVar21 + -8);
            bVar38 = pBVar35 < pBVar15;
            if (bVar38) {
              pBVar15 = (BYTE *)0x1;
            }
            cVar19 = (char)pBVar15;
            if (!bVar38) {
              cVar19 = '\0';
            }
            local_14c = pBVar35;
            if (cVar19 == '\0') {
LAB_00098c36:
              while( true ) {
                pBVar15 = (BYTE *)(src + iVar21 + -8);
                bVar38 = local_14c < pBVar15;
                if (bVar38) {
                  pBVar15 = (BYTE *)0x1;
                }
                cVar19 = (char)pBVar15;
                if (!bVar38) {
                  cVar19 = '\0';
                }
                if (cVar19 == '\0') {
                  if (local_14c < src + iVar21 + -6) {
                    UVar3 = LZ4_read16(local_150);
                    UVar4 = LZ4_read16(local_14c);
                    if (UVar3 == UVar4) {
                      local_14c = local_14c + 2;
                      local_150 = local_150 + 2;
                    }
                  }
                  if ((local_14c < iEnd) && (*local_150 == *local_14c)) {
                    local_14c = local_14c + 1;
                  }
                  local_14c = local_14c + -(int)pBVar35;
                  goto LAB_00098cde;
                }
                rVar9 = LZ4_read_ARCH(local_150);
                rVar10 = LZ4_read_ARCH(local_14c);
                if ((rVar10 ^ rVar9) != 0) break;
                local_14c = local_14c + 4;
                local_150 = local_150 + 4;
              }
              uVar14 = LZ4_NbCommonBytes(rVar10 ^ rVar9);
              local_14c = local_14c + (uVar14 - (int)pBVar35);
            }
            else {
              rVar9 = LZ4_read_ARCH(local_150);
              rVar10 = LZ4_read_ARCH(pBVar35);
              if ((rVar10 ^ rVar9) == 0) {
                local_14c = ip + 8;
                local_150 = pBVar34 + 8;
                goto LAB_00098c36;
              }
              local_14c = (BYTE *)LZ4_NbCommonBytes(rVar10 ^ rVar9);
            }
LAB_00098cde:
            if ((int)local_a0 < (int)(local_14c + 4)) {
              ref = pBVar34;
              local_a0 = local_14c + 4;
            }
          }
        }
LAB_0009929c:
        if ((cVar18 != '\0') && (ctx->chainTable[matchIndex & 0xffff] == 1)) {
          pBVar34 = (BYTE *)(matchIndex - 1);
          if (repeat == rep_untested) {
            uVar14 = UVar6 >> 0x10;
            bVar38 = (UVar6 & 0xffff) == uVar14;
            if (bVar38) {
              uVar14 = 1;
            }
            bVar20 = (byte)uVar14;
            if (!bVar38) {
              bVar20 = 0;
            }
            if (((UVar6 & 0xff) == UVar6 >> 0x18 & bVar20) == 0) {
              repeat = rep_not;
            }
            else {
              repeat = rep_confirmed;
              uVar14 = LZ4HC_countPattern(ip + 4,iEnd,UVar6);
              srcPatternLength = uVar14 + 4;
            }
          }
          if (((repeat == rep_confirmed) && (pBVar28 <= pBVar34)) &&
             (iVar22 = LZ4HC_protectDictEnd((U32)pBVar26,(U32)pBVar34), iVar22 != 0)) {
            pBVar35 = pBVar34;
            if (pBVar34 < pBVar26) {
              pBVar35 = (BYTE *)0x1;
            }
            cVar19 = (char)pBVar35;
            if (pBVar26 <= pBVar34) {
              cVar19 = '\0';
            }
            if (cVar19 == '\0') {
              iVar22 = (int)pBVar25 - (int)pBVar26;
            }
            else {
              iVar22 = (int)pBVar29 - (int)pBVar30;
            }
            pBVar35 = pBVar34 + iVar22;
            UVar7 = LZ4_read32(pBVar35);
            if (UVar6 == UVar7) {
              pBVar15 = iEnd;
              if (cVar19 != '\0') {
                pBVar15 = pBVar29 + ((int)pBVar26 - (int)pBVar30);
              }
              uVar14 = LZ4HC_countPattern(pBVar35 + 4,pBVar15,UVar6);
              forwardPatternLength = uVar14 + 4;
              if ((cVar19 != '\0') && (pBVar15 == pBVar35 + forwardPatternLength)) {
                UVar7 = LZ4HC_rotatePattern(forwardPatternLength,UVar6);
                uVar14 = LZ4HC_countPattern(pBVar25,iEnd,UVar7);
                forwardPatternLength = forwardPatternLength + uVar14;
              }
              pBVar15 = pBVar25;
              if (cVar19 != '\0') {
                pBVar15 = pBVar29;
              }
              backLength = LZ4HC_reverseCountPattern(pBVar35,pBVar15,UVar6);
              if (((cVar19 == '\0') && (pBVar25 == pBVar35 + -backLength)) && (pBVar30 < pBVar26)) {
                UVar7 = LZ4HC_rotatePattern(-backLength,UVar6);
                uVar14 = LZ4HC_reverseCountPattern
                                   (pBVar29 + ((int)pBVar26 - (int)pBVar30),pBVar29,UVar7);
                backLength = backLength + uVar14;
              }
              pBVar35 = pBVar34 + -backLength;
              if (pBVar34 + -backLength < pBVar28) {
                pBVar35 = pBVar28;
              }
              pLVar31 = (LZ4_byte *)(forwardPatternLength + ((int)pBVar34 - (int)pBVar35));
              matchIndex = (U32)pBVar26;
              if ((pLVar31 < srcPatternLength) || (srcPatternLength < forwardPatternLength)) {
                uVar14 = (int)pBVar34 - ((int)pBVar34 - (int)pBVar35);
                iVar22 = LZ4HC_protectDictEnd((U32)pBVar26,uVar14);
                if (iVar22 != 0) {
                  pLVar33 = (LZ4_byte *)srcPatternLength;
                  if (pLVar31 <= srcPatternLength) {
                    pLVar33 = pLVar31;
                  }
                  if (local_a0 < pLVar33) {
                    if ((BYTE *)0xffff < ip + (int)(pBVar26 + (-uVar14 - (int)pBVar25)))
                    goto LAB_000996e0;
                    ref = pBVar25 + (uVar14 - (int)pBVar26);
                    local_a0 = pLVar33;
                  }
                  if (uVar14 < ctx->chainTable[uVar14 & 0xffff]) goto LAB_000996e0;
                  matchIndex = uVar14 - ctx->chainTable[uVar14 & 0xffff];
                }
              }
              else {
                iVar22 = LZ4HC_protectDictEnd
                                   ((U32)pBVar26,
                                    (U32)(pBVar34 + (forwardPatternLength - srcPatternLength)));
                if (iVar22 != 0) {
                  matchIndex = (U32)(pBVar34 + (forwardPatternLength - srcPatternLength));
                }
              }
              goto LAB_000996c8;
            }
          }
        }
        matchIndex = matchIndex - ctx->chainTable[matchIndex & 0xffff];
      } while( true );
    }
  }
LAB_0009dd90:
  lastRunSize = (size_t)(src + (iVar21 - (int)anchor));
  if (limit == fillOutput) {
    oend = oend + 5;
  }
  if ((limit != notLimited) &&
     (oend < op + (int)(lastRunSize + (uint)(lastRunSize + 0xf0) / 0xff + 1))) {
    if (limit == limitedOutput) {
      result = 0;
      goto LAB_0009e402;
    }
    lastRunSize = (size_t)(oend + ((-1 - (int)op) - ((uint)(oend + (0xf0 - (int)op)) >> 8)));
  }
  if (lastRunSize < 0xf) {
    *op = (BYTE)((lastRunSize & 0xff) << 4);
    op = op + 1;
  }
  else {
    accumulator = lastRunSize - 0xf;
    *op = 0xf0;
    pBVar23 = op;
    for (; op = pBVar23 + 1, 0xfe < accumulator; accumulator = accumulator - 0xff) {
      *op = 0xff;
      pBVar23 = op;
    }
    *op = (BYTE)accumulator;
    op = pBVar23 + 2;
  }
  memcpy(op,anchor,lastRunSize);
  *srcSizePtr = (int)(anchor + (lastRunSize - (int)src));
  result = (int)(op + (lastRunSize - (int)dst));
LAB_0009e402:
  if (result < 1) {
    ctx->dirty = '\x01';
  }
  return result;
LAB_000996e0:
  if ((0 < nbAttempts) && ((uint)((int)pBVar27 - (int)pBVar28) < 0xffff)) {
    pLVar31 = pLVar24->end;
    pLVar33 = pLVar24->prefixStart;
    LVar32 = pLVar24->dictLimit;
    UVar7 = LZ4HC_hashPtr(ip);
    dictMatchIndex = pLVar24->hashTable[UVar7];
    matchIndex = (U32)(pBVar28 + (dictMatchIndex - (int)(pLVar31 + (LVar32 - (int)pLVar33))));
    while (((int)pBVar27 - matchIndex < 0x10000 && (nbAttempts != 0))) {
      pLVar16 = pLVar24->prefixStart + (dictMatchIndex - pLVar24->dictLimit);
      UVar7 = LZ4_read32(pLVar16);
      if (UVar6 == UVar7) {
        vLimit_1 = ip + ((int)(pLVar31 + (LVar32 - (int)pLVar33)) - dictMatchIndex);
        if (iEnd < ip + ((int)(pLVar31 + (LVar32 - (int)pLVar33)) - dictMatchIndex)) {
          vLimit_1 = iEnd;
        }
        pLVar12 = ip + 4;
        local_20c = pLVar16 + 4;
        pLVar37 = vLimit_1 + -3;
        bVar38 = pLVar12 < pLVar37;
        if (bVar38) {
          pLVar37 = (LZ4_byte *)0x1;
        }
        cVar19 = (char)pLVar37;
        if (!bVar38) {
          cVar19 = '\0';
        }
        local_208 = pLVar12;
        if (cVar19 == '\0') {
LAB_000998f6:
          while( true ) {
            pLVar16 = vLimit_1 + -3;
            bVar38 = local_208 < pLVar16;
            if (bVar38) {
              pLVar16 = (LZ4_byte *)0x1;
            }
            cVar19 = (char)pLVar16;
            if (!bVar38) {
              cVar19 = '\0';
            }
            if (cVar19 == '\0') {
              if (local_208 < vLimit_1 + -1) {
                UVar3 = LZ4_read16(local_20c);
                UVar4 = LZ4_read16(local_208);
                if (UVar3 == UVar4) {
                  local_208 = local_208 + 2;
                  local_20c = local_20c + 2;
                }
              }
              if ((local_208 < vLimit_1) && (*local_20c == *local_208)) {
                local_208 = local_208 + 1;
              }
              local_208 = local_208 + -(int)pLVar12;
              goto LAB_0009999e;
            }
            rVar9 = LZ4_read_ARCH(local_20c);
            rVar10 = LZ4_read_ARCH(local_208);
            if ((rVar10 ^ rVar9) != 0) break;
            local_208 = local_208 + 4;
            local_20c = local_20c + 4;
          }
          uVar14 = LZ4_NbCommonBytes(rVar10 ^ rVar9);
          local_208 = local_208 + (uVar14 - (int)pLVar12);
        }
        else {
          rVar9 = LZ4_read_ARCH(local_20c);
          rVar10 = LZ4_read_ARCH(pLVar12);
          if ((rVar10 ^ rVar9) == 0) {
            local_208 = ip + 8;
            local_20c = pLVar16 + 8;
            goto LAB_000998f6;
          }
          local_208 = (LZ4_byte *)LZ4_NbCommonBytes(rVar10 ^ rVar9);
        }
LAB_0009999e:
        if ((int)local_a0 < (int)(local_208 + 4)) {
          ref = pBVar25 + (matchIndex - (int)pBVar26);
          local_a0 = local_208 + 4;
        }
      }
      uVar14 = dictMatchIndex & 0xffff;
      dictMatchIndex = dictMatchIndex - pLVar24->chainTable[uVar14];
      matchIndex = matchIndex - pLVar24->chainTable[uVar14];
      nbAttempts = nbAttempts + -1;
    }
  }
  ml = (int)local_a0;
  if (3 < (int)local_a0) {
    start0 = ip;
    ref0 = ref;
    ml0 = (int)local_a0;
LAB_00099b76:
    pBVar25 = op;
    if (ip + ml <= pBVar23) {
      pBVar26 = ip + ml + -2;
      local_260 = (LZ4_byte *)ml;
      pLVar24 = ctx->dictCtx;
      pBVar27 = ctx->prefixStart;
      pBVar29 = (BYTE *)ctx->dictLimit;
      pBVar28 = pBVar26 + ((int)pBVar29 - (int)pBVar27);
      pBVar30 = (BYTE *)(ctx->lowLimit + 0x10000);
      bVar38 = pBVar28 < pBVar30;
      if (bVar38) {
        pBVar30 = (BYTE *)0x1;
      }
      cVar19 = (char)pBVar30;
      if (!bVar38) {
        cVar19 = '\0';
      }
      if (cVar19 == '\0') {
        pBVar30 = pBVar28 + -0xffff;
      }
      else {
        pBVar30 = (BYTE *)ctx->lowLimit;
      }
      pBVar34 = ctx->dictStart;
      pBVar35 = (BYTE *)ctx->lowLimit;
      iVar22 = (int)pBVar26 - (int)ip;
      UVar6 = LZ4_read32(pBVar26);
      repeat_1 = rep_untested;
      srcPatternLength_1 = 0;
      pLVar31 = ctx->prefixStart;
      LVar32 = ctx->dictLimit;
      for (idx_1 = ctx->nextToUpdate; idx_1 < pBVar26 + (LVar32 - (int)pLVar31); idx_1 = idx_1 + 1)
      {
        UVar7 = LZ4HC_hashPtr(pLVar31 + (idx_1 - LVar32));
        delta_1 = idx_1 - ctx->hashTable[UVar7];
        if (0xffff < delta_1) {
          delta_1 = 0xffff;
        }
        ctx->chainTable[idx_1 & 0xffff] = (LZ4_u16)delta_1;
        ctx->hashTable[UVar7] = idx_1;
      }
      ctx->nextToUpdate = (LZ4_u32)(pBVar26 + (LVar32 - (int)pLVar31));
      UVar7 = LZ4HC_hashPtr(pBVar26);
      matchIndex_1 = ctx->hashTable[UVar7];
      nbAttempts_1 = iVar5;
LAB_0009ac9a:
      do {
        if ((matchIndex_1 < pBVar30) || (nbAttempts_1 < 1)) goto LAB_0009acb6;
        nbAttempts_1 = nbAttempts_1 + -1;
        if (matchIndex_1 < pBVar29) {
          pBVar11 = pBVar34 + (matchIndex_1 - (int)pBVar35);
          pBVar36 = pBVar29 + -4;
          pBVar15 = pBVar36;
          if (matchIndex_1 <= pBVar36) {
            pBVar15 = (BYTE *)0x1;
          }
          cVar19 = (char)pBVar15;
          if (pBVar36 < matchIndex_1) {
            cVar19 = '\0';
          }
          if ((cVar19 == '\0') || (UVar7 = LZ4_read32(pBVar11), UVar6 != UVar7)) goto LAB_0009a7dc;
          vLimit_2 = pBVar26 + ((int)pBVar29 - matchIndex_1);
          if (iEnd < pBVar26 + ((int)pBVar29 - matchIndex_1)) {
            vLimit_2 = iEnd;
          }
          pBVar15 = pBVar26 + 4;
          local_334 = pBVar11 + 4;
          pBVar36 = vLimit_2 + -3;
          bVar38 = pBVar15 < pBVar36;
          if (bVar38) {
            pBVar36 = (BYTE *)0x1;
          }
          cVar19 = (char)pBVar36;
          if (!bVar38) {
            cVar19 = '\0';
          }
          local_330 = pBVar15;
          if (cVar19 == '\0') {
LAB_0009a3f6:
            while( true ) {
              pBVar36 = vLimit_2 + -3;
              bVar38 = local_330 < pBVar36;
              if (bVar38) {
                pBVar36 = (BYTE *)0x1;
              }
              cVar19 = (char)pBVar36;
              if (!bVar38) {
                cVar19 = '\0';
              }
              if (cVar19 == '\0') {
                if (local_330 < vLimit_2 + -1) {
                  UVar3 = LZ4_read16(local_334);
                  UVar4 = LZ4_read16(local_330);
                  if (UVar3 == UVar4) {
                    local_330 = local_330 + 2;
                    local_334 = local_334 + 2;
                  }
                }
                if ((local_330 < vLimit_2) && (*local_334 == *local_330)) {
                  local_330 = local_330 + 1;
                }
                local_330 = local_330 + -(int)pBVar15;
                goto LAB_0009a49e;
              }
              rVar9 = LZ4_read_ARCH(local_334);
              rVar10 = LZ4_read_ARCH(local_330);
              if ((rVar10 ^ rVar9) != 0) break;
              local_330 = local_330 + 4;
              local_334 = local_334 + 4;
            }
            uVar14 = LZ4_NbCommonBytes(rVar10 ^ rVar9);
            local_330 = local_330 + (uVar14 - (int)pBVar15);
          }
          else {
            rVar9 = LZ4_read_ARCH(local_334);
            rVar10 = LZ4_read_ARCH(pBVar15);
            if ((rVar10 ^ rVar9) == 0) {
              local_330 = pBVar26 + 8;
              local_334 = pBVar11 + 8;
              goto LAB_0009a3f6;
            }
            local_330 = (BYTE *)LZ4_NbCommonBytes(rVar10 ^ rVar9);
          }
LAB_0009a49e:
          matchLength_1 = (int)(local_330 + 4);
          if ((vLimit_2 == pBVar26 + matchLength_1) && (vLimit_2 < iEnd)) {
            pBVar15 = pBVar26 + matchLength_1;
            pBVar36 = (BYTE *)(src + iVar21 + -8);
            bVar38 = pBVar15 < pBVar36;
            if (bVar38) {
              pBVar36 = (BYTE *)0x1;
            }
            cVar19 = (char)pBVar36;
            if (!bVar38) {
              cVar19 = '\0';
            }
            local_34c = pBVar27;
            local_348 = pBVar15;
            if (cVar19 == '\0') {
LAB_0009a5f2:
              while( true ) {
                pBVar36 = (BYTE *)(src + iVar21 + -8);
                bVar38 = local_348 < pBVar36;
                if (bVar38) {
                  pBVar36 = (BYTE *)0x1;
                }
                cVar19 = (char)pBVar36;
                if (!bVar38) {
                  cVar19 = '\0';
                }
                if (cVar19 == '\0') {
                  if (local_348 < src + iVar21 + -6) {
                    UVar3 = LZ4_read16(local_34c);
                    UVar4 = LZ4_read16(local_348);
                    if (UVar3 == UVar4) {
                      local_348 = local_348 + 2;
                      local_34c = local_34c + 2;
                    }
                  }
                  if ((local_348 < iEnd) && (*local_34c == *local_348)) {
                    local_348 = local_348 + 1;
                  }
                  local_348 = local_348 + -(int)pBVar15;
                  goto LAB_0009a69c;
                }
                rVar9 = LZ4_read_ARCH(local_34c);
                rVar10 = LZ4_read_ARCH(local_348);
                if ((rVar10 ^ rVar9) != 0) break;
                local_348 = local_348 + 4;
                local_34c = local_34c + 4;
              }
              uVar14 = LZ4_NbCommonBytes(rVar10 ^ rVar9);
              local_348 = local_348 + (uVar14 - (int)pBVar15);
            }
            else {
              rVar9 = LZ4_read_ARCH(pBVar27);
              rVar10 = LZ4_read_ARCH(pBVar15);
              if ((rVar10 ^ rVar9) == 0) {
                local_348 = pBVar15 + 4;
                local_34c = pBVar27 + 4;
                goto LAB_0009a5f2;
              }
              local_348 = (BYTE *)LZ4_NbCommonBytes(rVar10 ^ rVar9);
            }
LAB_0009a69c:
            matchLength_1 = (int)(local_348 + matchLength_1);
          }
          if (iVar22 == 0) {
            back_9 = 0;
          }
          else {
            back_9 = 0;
            iVar8 = (int)ip - (int)pBVar26;
            if ((int)ip - (int)pBVar26 < (int)pBVar34 - (int)pBVar11) {
              iVar8 = (int)pBVar34 - (int)pBVar11;
            }
            for (; (iVar8 < back_9 && (pBVar26[back_9 + -1] == pBVar11[back_9 + -1]));
                back_9 = back_9 + -1) {
            }
          }
          if ((int)local_260 < matchLength_1 - back_9) {
            ref2 = pBVar27 + back_9 + (matchIndex_1 - (int)pBVar29);
            start2 = pBVar26 + back_9;
            local_260 = (LZ4_byte *)(matchLength_1 - back_9);
          }
        }
        else {
          pBVar15 = pBVar27 + (matchIndex_1 - (int)pBVar29);
          UVar3 = LZ4_read16(ip + (int)(local_260 + -1));
          UVar4 = LZ4_read16(pBVar15 + (int)(local_260 + (-1 - iVar22)));
          if ((UVar3 == UVar4) && (UVar7 = LZ4_read32(pBVar15), UVar6 == UVar7)) {
            if (iVar22 == 0) {
              back_7 = 0;
            }
            else {
              back_7 = 0;
              iVar8 = (int)ip - (int)pBVar26;
              if ((int)ip - (int)pBVar26 < (int)pBVar27 - (int)pBVar15) {
                iVar8 = (int)pBVar27 - (int)pBVar15;
              }
              for (; (iVar8 < back_7 && (pBVar26[back_7 + -1] == pBVar15[back_7 + -1]));
                  back_7 = back_7 + -1) {
              }
            }
            pBVar11 = pBVar26 + 4;
            local_310 = pBVar15 + 4;
            pBVar36 = (BYTE *)(src + iVar21 + -8);
            bVar38 = pBVar11 < pBVar36;
            if (bVar38) {
              pBVar36 = (BYTE *)0x1;
            }
            cVar19 = (char)pBVar36;
            if (!bVar38) {
              cVar19 = '\0';
            }
            local_30c = pBVar11;
            if (cVar19 == '\0') {
LAB_0009a13a:
              while( true ) {
                pBVar36 = (BYTE *)(src + iVar21 + -8);
                bVar38 = local_30c < pBVar36;
                if (bVar38) {
                  pBVar36 = (BYTE *)0x1;
                }
                cVar19 = (char)pBVar36;
                if (!bVar38) {
                  cVar19 = '\0';
                }
                if (cVar19 == '\0') {
                  if (local_30c < src + iVar21 + -6) {
                    UVar3 = LZ4_read16(local_310);
                    UVar4 = LZ4_read16(local_30c);
                    if (UVar3 == UVar4) {
                      local_30c = local_30c + 2;
                      local_310 = local_310 + 2;
                    }
                  }
                  if ((local_30c < iEnd) && (*local_310 == *local_30c)) {
                    local_30c = local_30c + 1;
                  }
                  local_30c = local_30c + -(int)pBVar11;
                  goto LAB_0009a1e2;
                }
                rVar9 = LZ4_read_ARCH(local_310);
                rVar10 = LZ4_read_ARCH(local_30c);
                if ((rVar10 ^ rVar9) != 0) break;
                local_30c = local_30c + 4;
                local_310 = local_310 + 4;
              }
              uVar14 = LZ4_NbCommonBytes(rVar10 ^ rVar9);
              local_30c = local_30c + (uVar14 - (int)pBVar11);
            }
            else {
              rVar9 = LZ4_read_ARCH(local_310);
              rVar10 = LZ4_read_ARCH(pBVar11);
              if ((rVar10 ^ rVar9) == 0) {
                local_30c = pBVar26 + 8;
                local_310 = pBVar15 + 8;
                goto LAB_0009a13a;
              }
              local_30c = (BYTE *)LZ4_NbCommonBytes(rVar10 ^ rVar9);
            }
LAB_0009a1e2:
            if ((int)local_260 < (int)(local_30c + (4 - back_7))) {
              ref2 = pBVar15 + back_7;
              start2 = pBVar26 + back_7;
              local_260 = local_30c + (4 - back_7);
            }
          }
        }
LAB_0009a7dc:
        if ((cVar18 != '\0') && (ctx->chainTable[matchIndex_1 & 0xffff] == 1)) {
          pBVar15 = (BYTE *)(matchIndex_1 - 1);
          if (repeat_1 == rep_untested) {
            uVar14 = UVar6 >> 0x10;
            bVar38 = (UVar6 & 0xffff) == uVar14;
            if (bVar38) {
              uVar14 = 1;
            }
            bVar20 = (byte)uVar14;
            if (!bVar38) {
              bVar20 = 0;
            }
            if (((UVar6 & 0xff) == UVar6 >> 0x18 & bVar20) == 0) {
              repeat_1 = rep_not;
            }
            else {
              repeat_1 = rep_confirmed;
              uVar14 = LZ4HC_countPattern(pBVar26 + 4,iEnd,UVar6);
              srcPatternLength_1 = uVar14 + 4;
            }
          }
          if (((repeat_1 == rep_confirmed) && (pBVar30 <= pBVar15)) &&
             (iVar8 = LZ4HC_protectDictEnd((U32)pBVar29,(U32)pBVar15), iVar8 != 0)) {
            pBVar11 = pBVar15;
            if (pBVar15 < pBVar29) {
              pBVar11 = (BYTE *)0x1;
            }
            cVar19 = (char)pBVar11;
            if (pBVar29 <= pBVar15) {
              cVar19 = '\0';
            }
            if (cVar19 == '\0') {
              iVar8 = (int)pBVar27 - (int)pBVar29;
            }
            else {
              iVar8 = (int)pBVar34 - (int)pBVar35;
            }
            pBVar11 = pBVar15 + iVar8;
            UVar7 = LZ4_read32(pBVar11);
            if (UVar6 == UVar7) {
              pBVar36 = iEnd;
              if (cVar19 != '\0') {
                pBVar36 = pBVar34 + ((int)pBVar29 - (int)pBVar35);
              }
              uVar14 = LZ4HC_countPattern(pBVar11 + 4,pBVar36,UVar6);
              forwardPatternLength_1 = uVar14 + 4;
              if ((cVar19 != '\0') && (pBVar36 == pBVar11 + forwardPatternLength_1)) {
                UVar7 = LZ4HC_rotatePattern(forwardPatternLength_1,UVar6);
                uVar14 = LZ4HC_countPattern(pBVar27,iEnd,UVar7);
                forwardPatternLength_1 = forwardPatternLength_1 + uVar14;
              }
              pBVar36 = pBVar27;
              if (cVar19 != '\0') {
                pBVar36 = pBVar34;
              }
              backLength_1 = LZ4HC_reverseCountPattern(pBVar11,pBVar36,UVar6);
              if (((cVar19 == '\0') && (pBVar27 == pBVar11 + -backLength_1)) && (pBVar35 < pBVar29))
              {
                UVar7 = LZ4HC_rotatePattern(-backLength_1,UVar6);
                uVar14 = LZ4HC_reverseCountPattern
                                   (pBVar34 + ((int)pBVar29 - (int)pBVar35),pBVar34,UVar7);
                backLength_1 = backLength_1 + uVar14;
              }
              pBVar11 = pBVar15 + -backLength_1;
              if (pBVar15 + -backLength_1 < pBVar30) {
                pBVar11 = pBVar30;
              }
              pLVar31 = (LZ4_byte *)(forwardPatternLength_1 + ((int)pBVar15 - (int)pBVar11));
              matchIndex_1 = (U32)pBVar29;
              if ((pLVar31 < srcPatternLength_1) || (srcPatternLength_1 < forwardPatternLength_1)) {
                uVar14 = (int)pBVar15 - ((int)pBVar15 - (int)pBVar11);
                iVar8 = LZ4HC_protectDictEnd((U32)pBVar29,uVar14);
                if ((iVar8 != 0) && (matchIndex_1 = uVar14, iVar22 == 0)) {
                  pLVar33 = (LZ4_byte *)srcPatternLength_1;
                  if (pLVar31 <= srcPatternLength_1) {
                    pLVar33 = pLVar31;
                  }
                  if (local_260 < pLVar33) {
                    if ((BYTE *)0xffff < pBVar26 + (int)(pBVar29 + (-uVar14 - (int)pBVar27)))
                    goto LAB_0009acb6;
                    ref2 = pBVar27 + (uVar14 - (int)pBVar29);
                    start2 = pBVar26;
                    local_260 = pLVar33;
                  }
                  if (uVar14 < ctx->chainTable[uVar14 & 0xffff]) goto LAB_0009acb6;
                  matchIndex_1 = uVar14 - ctx->chainTable[uVar14 & 0xffff];
                }
              }
              else {
                iVar8 = LZ4HC_protectDictEnd
                                  ((U32)pBVar29,
                                   (U32)(pBVar15 + (forwardPatternLength_1 - srcPatternLength_1)));
                if (iVar8 != 0) {
                  matchIndex_1 = (U32)(pBVar15 + (forwardPatternLength_1 - srcPatternLength_1));
                }
              }
              goto LAB_0009ac9a;
            }
          }
        }
        matchIndex_1 = matchIndex_1 - ctx->chainTable[matchIndex_1 & 0xffff];
      } while( true );
    }
    ml2 = ml;
    goto LAB_0009b15c;
  }
  ip = ip + 1;
  goto LAB_0009dd80;
LAB_0009acb6:
  if ((0 < nbAttempts_1) && ((uint)((int)pBVar28 - (int)pBVar30) < 0xffff)) {
    pLVar31 = pLVar24->end;
    pLVar33 = pLVar24->prefixStart;
    LVar32 = pLVar24->dictLimit;
    UVar7 = LZ4HC_hashPtr(pBVar26);
    dictMatchIndex_1 = pLVar24->hashTable[UVar7];
    matchIndex_1 = (U32)(pBVar30 + (dictMatchIndex_1 - (int)(pLVar31 + (LVar32 - (int)pLVar33))));
    while (((int)pBVar28 - matchIndex_1 < 0x10000 && (nbAttempts_1 != 0))) {
      pLVar16 = pLVar24->prefixStart + (dictMatchIndex_1 - pLVar24->dictLimit);
      UVar7 = LZ4_read32(pLVar16);
      if (UVar6 == UVar7) {
        vLimit_3 = pBVar26 + ((int)(pLVar31 + (LVar32 - (int)pLVar33)) - dictMatchIndex_1);
        if (iEnd < pBVar26 + ((int)(pLVar31 + (LVar32 - (int)pLVar33)) - dictMatchIndex_1)) {
          vLimit_3 = iEnd;
        }
        pLVar12 = pBVar26 + 4;
        local_3cc = pLVar16 + 4;
        pLVar37 = vLimit_3 + -3;
        bVar38 = pLVar12 < pLVar37;
        if (bVar38) {
          pLVar37 = (LZ4_byte *)0x1;
        }
        cVar19 = (char)pLVar37;
        if (!bVar38) {
          cVar19 = '\0';
        }
        local_3c8 = pLVar12;
        if (cVar19 == '\0') {
LAB_0009aeee:
          while( true ) {
            pLVar37 = vLimit_3 + -3;
            bVar38 = local_3c8 < pLVar37;
            if (bVar38) {
              pLVar37 = (LZ4_byte *)0x1;
            }
            cVar19 = (char)pLVar37;
            if (!bVar38) {
              cVar19 = '\0';
            }
            if (cVar19 == '\0') {
              if (local_3c8 < vLimit_3 + -1) {
                UVar3 = LZ4_read16(local_3cc);
                UVar4 = LZ4_read16(local_3c8);
                if (UVar3 == UVar4) {
                  local_3c8 = local_3c8 + 2;
                  local_3cc = local_3cc + 2;
                }
              }
              if ((local_3c8 < vLimit_3) && (*local_3cc == *local_3c8)) {
                local_3c8 = local_3c8 + 1;
              }
              local_3c8 = local_3c8 + -(int)pLVar12;
              goto LAB_0009af96;
            }
            rVar9 = LZ4_read_ARCH(local_3cc);
            rVar10 = LZ4_read_ARCH(local_3c8);
            if ((rVar10 ^ rVar9) != 0) break;
            local_3c8 = local_3c8 + 4;
            local_3cc = local_3cc + 4;
          }
          uVar14 = LZ4_NbCommonBytes(rVar10 ^ rVar9);
          local_3c8 = local_3c8 + (uVar14 - (int)pLVar12);
        }
        else {
          rVar9 = LZ4_read_ARCH(local_3cc);
          rVar10 = LZ4_read_ARCH(pLVar12);
          if ((rVar10 ^ rVar9) == 0) {
            local_3c8 = pBVar26 + 8;
            local_3cc = pLVar16 + 8;
            goto LAB_0009aeee;
          }
          local_3c8 = (LZ4_byte *)LZ4_NbCommonBytes(rVar10 ^ rVar9);
        }
LAB_0009af96:
        if (iVar22 == 0) {
          back_11 = 0;
        }
        else {
          back_11 = 0;
          iVar13 = (int)pLVar24->prefixStart - (int)pLVar16;
          iVar8 = (int)ip - (int)pBVar26;
          if ((int)ip - (int)pBVar26 < iVar13) {
            iVar8 = iVar13;
          }
          for (; (iVar8 < back_11 && (pBVar26[back_11 + -1] == pLVar16[back_11 + -1]));
              back_11 = back_11 + -1) {
          }
        }
        if ((int)local_260 < (int)(local_3c8 + (4 - back_11))) {
          ref2 = pBVar27 + back_11 + (matchIndex_1 - (int)pBVar29);
          start2 = pBVar26 + back_11;
          local_260 = local_3c8 + (4 - back_11);
        }
      }
      uVar14 = dictMatchIndex_1 & 0xffff;
      dictMatchIndex_1 = dictMatchIndex_1 - pLVar24->chainTable[uVar14];
      matchIndex_1 = matchIndex_1 - pLVar24->chainTable[uVar14];
      nbAttempts_1 = nbAttempts_1 + -1;
    }
  }
  ml2 = (int)local_260;
LAB_0009b15c:
  if (ml == ml2) goto code_r0x0009b16e;
  if ((start0 < ip) && (start2 < ip + ml0)) {
    ip = start0;
    ref = ref0;
    ml = ml0;
  }
  if (2 < (int)start2 - (int)ip) {
LAB_0009b5a2:
    pBVar25 = op;
    if ((int)start2 - (int)ip < 0x12) {
      new_ml = ml;
      if (0x12 < ml) {
        new_ml = 0x12;
      }
      if (start2 + ml2 + -4 < ip + new_ml) {
        new_ml = (int)(start2 + (ml2 - (int)ip) + -4);
      }
      iVar22 = new_ml - ((int)start2 - (int)ip);
      if (0 < iVar22) {
        start2 = start2 + iVar22;
        ref2 = ref2 + iVar22;
        ml2 = ml2 - iVar22;
      }
    }
    if (start2 + ml2 <= pBVar23) {
      pBVar26 = start2 + ml2 + -3;
      local_45c = (LZ4_byte *)ml2;
      pLVar24 = ctx->dictCtx;
      pBVar27 = ctx->prefixStart;
      pBVar29 = (BYTE *)ctx->dictLimit;
      pBVar28 = pBVar26 + ((int)pBVar29 - (int)pBVar27);
      pBVar30 = (BYTE *)(ctx->lowLimit + 0x10000);
      bVar38 = pBVar28 < pBVar30;
      if (bVar38) {
        pBVar30 = (BYTE *)0x1;
      }
      cVar19 = (char)pBVar30;
      if (!bVar38) {
        cVar19 = '\0';
      }
      if (cVar19 == '\0') {
        pBVar30 = pBVar28 + -0xffff;
      }
      else {
        pBVar30 = (BYTE *)ctx->lowLimit;
      }
      pBVar34 = ctx->dictStart;
      pBVar35 = (BYTE *)ctx->lowLimit;
      iVar22 = (int)pBVar26 - (int)start2;
      UVar6 = LZ4_read32(pBVar26);
      repeat_2 = rep_untested;
      srcPatternLength_2 = 0;
      pLVar31 = ctx->prefixStart;
      LVar32 = ctx->dictLimit;
      for (idx_2 = ctx->nextToUpdate; idx_2 < pBVar26 + (LVar32 - (int)pLVar31); idx_2 = idx_2 + 1)
      {
        UVar7 = LZ4HC_hashPtr(pLVar31 + (idx_2 - LVar32));
        delta_2 = idx_2 - ctx->hashTable[UVar7];
        if (0xffff < delta_2) {
          delta_2 = 0xffff;
        }
        ctx->chainTable[idx_2 & 0xffff] = (LZ4_u16)delta_2;
        ctx->hashTable[UVar7] = idx_2;
      }
      ctx->nextToUpdate = (LZ4_u32)(pBVar26 + (LVar32 - (int)pLVar31));
      UVar7 = LZ4HC_hashPtr(pBVar26);
      matchIndex_2 = ctx->hashTable[UVar7];
      nbAttempts_2 = iVar5;
LAB_0009c79e:
      do {
        if ((matchIndex_2 < pBVar30) || (nbAttempts_2 < 1)) goto LAB_0009c7ba;
        nbAttempts_2 = nbAttempts_2 + -1;
        if (matchIndex_2 < pBVar29) {
          pBVar11 = pBVar34 + (matchIndex_2 - (int)pBVar35);
          pBVar36 = pBVar29 + -4;
          pBVar15 = pBVar36;
          if (matchIndex_2 <= pBVar36) {
            pBVar15 = (BYTE *)0x1;
          }
          cVar19 = (char)pBVar15;
          if (pBVar36 < matchIndex_2) {
            cVar19 = '\0';
          }
          if ((cVar19 == '\0') || (UVar7 = LZ4_read32(pBVar11), UVar6 != UVar7)) goto LAB_0009c2e0;
          vLimit_4 = pBVar26 + ((int)pBVar29 - matchIndex_2);
          if (iEnd < pBVar26 + ((int)pBVar29 - matchIndex_2)) {
            vLimit_4 = iEnd;
          }
          pBVar15 = pBVar26 + 4;
          local_530 = pBVar11 + 4;
          pBVar36 = vLimit_4 + -3;
          bVar38 = pBVar15 < pBVar36;
          if (bVar38) {
            pBVar36 = (BYTE *)0x1;
          }
          cVar19 = (char)pBVar36;
          if (!bVar38) {
            cVar19 = '\0';
          }
          local_52c = pBVar15;
          if (cVar19 == '\0') {
LAB_0009befa:
            while( true ) {
              pBVar36 = vLimit_4 + -3;
              bVar38 = local_52c < pBVar36;
              if (bVar38) {
                pBVar36 = (BYTE *)0x1;
              }
              cVar19 = (char)pBVar36;
              if (!bVar38) {
                cVar19 = '\0';
              }
              if (cVar19 == '\0') {
                if (local_52c < vLimit_4 + -1) {
                  UVar3 = LZ4_read16(local_530);
                  UVar4 = LZ4_read16(local_52c);
                  if (UVar3 == UVar4) {
                    local_52c = local_52c + 2;
                    local_530 = local_530 + 2;
                  }
                }
                if ((local_52c < vLimit_4) && (*local_530 == *local_52c)) {
                  local_52c = local_52c + 1;
                }
                local_52c = local_52c + -(int)pBVar15;
                goto LAB_0009bfa2;
              }
              rVar9 = LZ4_read_ARCH(local_530);
              rVar10 = LZ4_read_ARCH(local_52c);
              if ((rVar10 ^ rVar9) != 0) break;
              local_52c = local_52c + 4;
              local_530 = local_530 + 4;
            }
            uVar14 = LZ4_NbCommonBytes(rVar10 ^ rVar9);
            local_52c = local_52c + (uVar14 - (int)pBVar15);
          }
          else {
            rVar9 = LZ4_read_ARCH(local_530);
            rVar10 = LZ4_read_ARCH(pBVar15);
            if ((rVar10 ^ rVar9) == 0) {
              local_52c = pBVar26 + 8;
              local_530 = pBVar11 + 8;
              goto LAB_0009befa;
            }
            local_52c = (BYTE *)LZ4_NbCommonBytes(rVar10 ^ rVar9);
          }
LAB_0009bfa2:
          matchLength_2 = (int)(local_52c + 4);
          if ((vLimit_4 == pBVar26 + matchLength_2) && (vLimit_4 < iEnd)) {
            pBVar15 = pBVar26 + matchLength_2;
            pBVar36 = (BYTE *)(src + iVar21 + -8);
            bVar38 = pBVar15 < pBVar36;
            if (bVar38) {
              pBVar36 = (BYTE *)0x1;
            }
            cVar19 = (char)pBVar36;
            if (!bVar38) {
              cVar19 = '\0';
            }
            local_548 = pBVar27;
            local_544 = pBVar15;
            if (cVar19 == '\0') {
LAB_0009c0f6:
              while( true ) {
                pBVar36 = (BYTE *)(src + iVar21 + -8);
                bVar38 = local_544 < pBVar36;
                if (bVar38) {
                  pBVar36 = (BYTE *)0x1;
                }
                cVar19 = (char)pBVar36;
                if (!bVar38) {
                  cVar19 = '\0';
                }
                if (cVar19 == '\0') {
                  if (local_544 < src + iVar21 + -6) {
                    UVar3 = LZ4_read16(local_548);
                    UVar4 = LZ4_read16(local_544);
                    if (UVar3 == UVar4) {
                      local_544 = local_544 + 2;
                      local_548 = local_548 + 2;
                    }
                  }
                  if ((local_544 < iEnd) && (*local_548 == *local_544)) {
                    local_544 = local_544 + 1;
                  }
                  local_544 = local_544 + -(int)pBVar15;
                  goto LAB_0009c1a0;
                }
                rVar9 = LZ4_read_ARCH(local_548);
                rVar10 = LZ4_read_ARCH(local_544);
                if ((rVar10 ^ rVar9) != 0) break;
                local_544 = local_544 + 4;
                local_548 = local_548 + 4;
              }
              uVar14 = LZ4_NbCommonBytes(rVar10 ^ rVar9);
              local_544 = local_544 + (uVar14 - (int)pBVar15);
            }
            else {
              rVar9 = LZ4_read_ARCH(pBVar27);
              rVar10 = LZ4_read_ARCH(pBVar15);
              if ((rVar10 ^ rVar9) == 0) {
                local_544 = pBVar15 + 4;
                local_548 = pBVar27 + 4;
                goto LAB_0009c0f6;
              }
              local_544 = (BYTE *)LZ4_NbCommonBytes(rVar10 ^ rVar9);
            }
LAB_0009c1a0:
            matchLength_2 = (int)(local_544 + matchLength_2);
          }
          if (iVar22 == 0) {
            back_15 = 0;
          }
          else {
            back_15 = 0;
            iVar8 = (int)start2 - (int)pBVar26;
            if ((int)start2 - (int)pBVar26 < (int)pBVar34 - (int)pBVar11) {
              iVar8 = (int)pBVar34 - (int)pBVar11;
            }
            for (; (iVar8 < back_15 && (pBVar26[back_15 + -1] == pBVar11[back_15 + -1]));
                back_15 = back_15 + -1) {
            }
          }
          if ((int)local_45c < matchLength_2 - back_15) {
            ref3 = pBVar27 + back_15 + (matchIndex_2 - (int)pBVar29);
            start3 = pBVar26 + back_15;
            local_45c = (LZ4_byte *)(matchLength_2 - back_15);
          }
        }
        else {
          pBVar15 = pBVar27 + (matchIndex_2 - (int)pBVar29);
          UVar3 = LZ4_read16(start2 + (int)(local_45c + -1));
          UVar4 = LZ4_read16(pBVar15 + (int)(local_45c + (-1 - iVar22)));
          if ((UVar3 == UVar4) && (UVar7 = LZ4_read32(pBVar15), UVar6 == UVar7)) {
            if (iVar22 == 0) {
              back_13 = 0;
            }
            else {
              back_13 = 0;
              iVar8 = (int)start2 - (int)pBVar26;
              if ((int)start2 - (int)pBVar26 < (int)pBVar27 - (int)pBVar15) {
                iVar8 = (int)pBVar27 - (int)pBVar15;
              }
              for (; (iVar8 < back_13 && (pBVar26[back_13 + -1] == pBVar15[back_13 + -1]));
                  back_13 = back_13 + -1) {
              }
            }
            pBVar11 = pBVar26 + 4;
            local_50c = pBVar15 + 4;
            pBVar36 = (BYTE *)(src + iVar21 + -8);
            bVar38 = pBVar11 < pBVar36;
            if (bVar38) {
              pBVar36 = (BYTE *)0x1;
            }
            cVar19 = (char)pBVar36;
            if (!bVar38) {
              cVar19 = '\0';
            }
            local_508 = pBVar11;
            if (cVar19 == '\0') {
LAB_0009bc3e:
              while( true ) {
                pBVar36 = (BYTE *)(src + iVar21 + -8);
                bVar38 = local_508 < pBVar36;
                if (bVar38) {
                  pBVar36 = (BYTE *)0x1;
                }
                cVar19 = (char)pBVar36;
                if (!bVar38) {
                  cVar19 = '\0';
                }
                if (cVar19 == '\0') {
                  if (local_508 < src + iVar21 + -6) {
                    UVar3 = LZ4_read16(local_50c);
                    UVar4 = LZ4_read16(local_508);
                    if (UVar3 == UVar4) {
                      local_508 = local_508 + 2;
                      local_50c = local_50c + 2;
                    }
                  }
                  if ((local_508 < iEnd) && (*local_50c == *local_508)) {
                    local_508 = local_508 + 1;
                  }
                  local_508 = local_508 + -(int)pBVar11;
                  goto LAB_0009bce6;
                }
                rVar9 = LZ4_read_ARCH(local_50c);
                rVar10 = LZ4_read_ARCH(local_508);
                if ((rVar10 ^ rVar9) != 0) break;
                local_508 = local_508 + 4;
                local_50c = local_50c + 4;
              }
              uVar14 = LZ4_NbCommonBytes(rVar10 ^ rVar9);
              local_508 = local_508 + (uVar14 - (int)pBVar11);
            }
            else {
              rVar9 = LZ4_read_ARCH(local_50c);
              rVar10 = LZ4_read_ARCH(pBVar11);
              if ((rVar10 ^ rVar9) == 0) {
                local_508 = pBVar26 + 8;
                local_50c = pBVar15 + 8;
                goto LAB_0009bc3e;
              }
              local_508 = (BYTE *)LZ4_NbCommonBytes(rVar10 ^ rVar9);
            }
LAB_0009bce6:
            if ((int)local_45c < (int)(local_508 + (4 - back_13))) {
              ref3 = pBVar15 + back_13;
              start3 = pBVar26 + back_13;
              local_45c = local_508 + (4 - back_13);
            }
          }
        }
LAB_0009c2e0:
        if ((cVar18 != '\0') && (ctx->chainTable[matchIndex_2 & 0xffff] == 1)) {
          pBVar15 = (BYTE *)(matchIndex_2 - 1);
          if (repeat_2 == rep_untested) {
            uVar14 = UVar6 >> 0x10;
            bVar38 = (UVar6 & 0xffff) == uVar14;
            if (bVar38) {
              uVar14 = 1;
            }
            bVar20 = (byte)uVar14;
            if (!bVar38) {
              bVar20 = 0;
            }
            if (((UVar6 & 0xff) == UVar6 >> 0x18 & bVar20) == 0) {
              repeat_2 = rep_not;
            }
            else {
              repeat_2 = rep_confirmed;
              uVar14 = LZ4HC_countPattern(pBVar26 + 4,iEnd,UVar6);
              srcPatternLength_2 = uVar14 + 4;
            }
          }
          if (((repeat_2 == rep_confirmed) && (pBVar30 <= pBVar15)) &&
             (iVar8 = LZ4HC_protectDictEnd((U32)pBVar29,(U32)pBVar15), iVar8 != 0)) {
            pBVar11 = pBVar15;
            if (pBVar15 < pBVar29) {
              pBVar11 = (BYTE *)0x1;
            }
            cVar19 = (char)pBVar11;
            if (pBVar29 <= pBVar15) {
              cVar19 = '\0';
            }
            if (cVar19 == '\0') {
              iVar8 = (int)pBVar27 - (int)pBVar29;
            }
            else {
              iVar8 = (int)pBVar34 - (int)pBVar35;
            }
            pBVar11 = pBVar15 + iVar8;
            UVar7 = LZ4_read32(pBVar11);
            if (UVar6 == UVar7) {
              pBVar36 = iEnd;
              if (cVar19 != '\0') {
                pBVar36 = pBVar34 + ((int)pBVar29 - (int)pBVar35);
              }
              uVar14 = LZ4HC_countPattern(pBVar11 + 4,pBVar36,UVar6);
              forwardPatternLength_2 = uVar14 + 4;
              if ((cVar19 != '\0') && (pBVar36 == pBVar11 + forwardPatternLength_2)) {
                UVar7 = LZ4HC_rotatePattern(forwardPatternLength_2,UVar6);
                uVar14 = LZ4HC_countPattern(pBVar27,iEnd,UVar7);
                forwardPatternLength_2 = forwardPatternLength_2 + uVar14;
              }
              pBVar36 = pBVar27;
              if (cVar19 != '\0') {
                pBVar36 = pBVar34;
              }
              backLength_2 = LZ4HC_reverseCountPattern(pBVar11,pBVar36,UVar6);
              if (((cVar19 == '\0') && (pBVar27 == pBVar11 + -backLength_2)) && (pBVar35 < pBVar29))
              {
                UVar7 = LZ4HC_rotatePattern(-backLength_2,UVar6);
                uVar14 = LZ4HC_reverseCountPattern
                                   (pBVar34 + ((int)pBVar29 - (int)pBVar35),pBVar34,UVar7);
                backLength_2 = backLength_2 + uVar14;
              }
              pBVar11 = pBVar15 + -backLength_2;
              if (pBVar15 + -backLength_2 < pBVar30) {
                pBVar11 = pBVar30;
              }
              pLVar31 = (LZ4_byte *)(forwardPatternLength_2 + ((int)pBVar15 - (int)pBVar11));
              matchIndex_2 = (U32)pBVar29;
              if ((pLVar31 < srcPatternLength_2) || (srcPatternLength_2 < forwardPatternLength_2)) {
                uVar14 = (int)pBVar15 - ((int)pBVar15 - (int)pBVar11);
                iVar8 = LZ4HC_protectDictEnd((U32)pBVar29,uVar14);
                if ((iVar8 != 0) && (matchIndex_2 = uVar14, iVar22 == 0)) {
                  pLVar33 = (LZ4_byte *)srcPatternLength_2;
                  if (pLVar31 <= srcPatternLength_2) {
                    pLVar33 = pLVar31;
                  }
                  if (local_45c < pLVar33) {
                    if ((BYTE *)0xffff < pBVar26 + (int)(pBVar29 + (-uVar14 - (int)pBVar27)))
                    goto LAB_0009c7ba;
                    ref3 = pBVar27 + (uVar14 - (int)pBVar29);
                    start3 = pBVar26;
                    local_45c = pLVar33;
                  }
                  if (uVar14 < ctx->chainTable[uVar14 & 0xffff]) goto LAB_0009c7ba;
                  matchIndex_2 = uVar14 - ctx->chainTable[uVar14 & 0xffff];
                }
              }
              else {
                iVar8 = LZ4HC_protectDictEnd
                                  ((U32)pBVar29,
                                   (U32)(pBVar15 + (forwardPatternLength_2 - srcPatternLength_2)));
                if (iVar8 != 0) {
                  matchIndex_2 = (U32)(pBVar15 + (forwardPatternLength_2 - srcPatternLength_2));
                }
              }
              goto LAB_0009c79e;
            }
          }
        }
        matchIndex_2 = matchIndex_2 - ctx->chainTable[matchIndex_2 & 0xffff];
      } while( true );
    }
    ml3 = ml2;
    goto LAB_0009cc60;
  }
  ml = ml2;
  ip = start2;
  ref = ref2;
  goto LAB_00099b76;
code_r0x0009b16e:
  optr = op;
  pBVar26 = op + 1;
  uVar14 = (int)ip - (int)anchor;
  if ((limit == notLimited) || (pBVar26 + uVar14 + uVar14 / 0xff + 8 <= oend)) {
    if (uVar14 < 0xf) {
      *op = (BYTE)((uVar14 & 0xff) << 4);
      op = pBVar26;
    }
    else {
      *op = 0xf0;
      op = pBVar26;
      for (len = uVar14 - 0xf; 0xfe < len; len = len - 0xff) {
        *op = 0xff;
        op = op + 1;
      }
      *op = (BYTE)len;
      op = op + 1;
    }
    d = op;
    s = anchor;
    do {
      uVar17 = *(undefined4 *)(s + 4);
      *(undefined4 *)d = *(undefined4 *)s;
      *(undefined4 *)(d + 4) = uVar17;
      d = d + 8;
      s = s + 8;
    } while (d < op + uVar14);
    LZ4_writeLE16(op + uVar14,(short)ip - (short)ref);
    op = op + uVar14 + 2;
    uVar14 = ml - 4;
    if ((limit == notLimited) || (op + uVar14 / 0xff + 6 <= oend)) {
      if (uVar14 < 0xf) {
        *pBVar25 = (char)uVar14 + *pBVar25;
      }
      else {
        *pBVar25 = *pBVar25 + '\x0f';
        for (length = ml - 0x13; 0x1fd < length; length = length - 0x1fe) {
          pBVar25 = op + 1;
          *op = 0xff;
          op = op + 2;
          *pBVar25 = 0xff;
        }
        if (0xfe < length) {
          length = length - 0xff;
          *op = 0xff;
          op = op + 1;
        }
        *op = (BYTE)length;
        op = op + 1;
      }
      anchor = ip + ml;
      bVar38 = false;
      ip = anchor;
    }
    else {
      bVar38 = true;
    }
  }
  else {
    bVar38 = true;
    op = pBVar26;
  }
  if (bVar38) goto LAB_0009df42;
  goto LAB_0009dd80;
LAB_0009c7ba:
  if ((0 < nbAttempts_2) && ((uint)((int)pBVar28 - (int)pBVar30) < 0xffff)) {
    pLVar31 = pLVar24->end;
    pLVar33 = pLVar24->prefixStart;
    LVar32 = pLVar24->dictLimit;
    UVar7 = LZ4HC_hashPtr(pBVar26);
    dictMatchIndex_2 = pLVar24->hashTable[UVar7];
    matchIndex_2 = (U32)(pBVar30 + (dictMatchIndex_2 - (int)(pLVar31 + (LVar32 - (int)pLVar33))));
    while (((int)pBVar28 - matchIndex_2 < 0x10000 && (nbAttempts_2 != 0))) {
      pLVar16 = pLVar24->prefixStart + (dictMatchIndex_2 - pLVar24->dictLimit);
      UVar7 = LZ4_read32(pLVar16);
      if (UVar6 == UVar7) {
        vLimit_5 = pBVar26 + ((int)(pLVar31 + (LVar32 - (int)pLVar33)) - dictMatchIndex_2);
        if (iEnd < pBVar26 + ((int)(pLVar31 + (LVar32 - (int)pLVar33)) - dictMatchIndex_2)) {
          vLimit_5 = iEnd;
        }
        pLVar12 = pBVar26 + 4;
        local_5c8 = pLVar16 + 4;
        pLVar37 = vLimit_5 + -3;
        bVar38 = pLVar12 < pLVar37;
        if (bVar38) {
          pLVar37 = (LZ4_byte *)0x1;
        }
        cVar19 = (char)pLVar37;
        if (!bVar38) {
          cVar19 = '\0';
        }
        local_5c4 = pLVar12;
        if (cVar19 == '\0') {
LAB_0009c9f2:
          while( true ) {
            pLVar37 = vLimit_5 + -3;
            bVar38 = local_5c4 < pLVar37;
            if (bVar38) {
              pLVar37 = (LZ4_byte *)0x1;
            }
            cVar19 = (char)pLVar37;
            if (!bVar38) {
              cVar19 = '\0';
            }
            if (cVar19 == '\0') {
              if (local_5c4 < vLimit_5 + -1) {
                UVar3 = LZ4_read16(local_5c8);
                UVar4 = LZ4_read16(local_5c4);
                if (UVar3 == UVar4) {
                  local_5c4 = local_5c4 + 2;
                  local_5c8 = local_5c8 + 2;
                }
              }
              if ((local_5c4 < vLimit_5) && (*local_5c8 == *local_5c4)) {
                local_5c4 = local_5c4 + 1;
              }
              local_5c4 = local_5c4 + -(int)pLVar12;
              goto LAB_0009ca9a;
            }
            rVar9 = LZ4_read_ARCH(local_5c8);
            rVar10 = LZ4_read_ARCH(local_5c4);
            if ((rVar10 ^ rVar9) != 0) break;
            local_5c4 = local_5c4 + 4;
            local_5c8 = local_5c8 + 4;
          }
          uVar14 = LZ4_NbCommonBytes(rVar10 ^ rVar9);
          local_5c4 = local_5c4 + (uVar14 - (int)pLVar12);
        }
        else {
          rVar9 = LZ4_read_ARCH(local_5c8);
          rVar10 = LZ4_read_ARCH(pLVar12);
          if ((rVar10 ^ rVar9) == 0) {
            local_5c4 = pBVar26 + 8;
            local_5c8 = pLVar16 + 8;
            goto LAB_0009c9f2;
          }
          local_5c4 = (LZ4_byte *)LZ4_NbCommonBytes(rVar10 ^ rVar9);
        }
LAB_0009ca9a:
        if (iVar22 == 0) {
          back_17 = 0;
        }
        else {
          back_17 = 0;
          iVar13 = (int)pLVar24->prefixStart - (int)pLVar16;
          iVar8 = (int)start2 - (int)pBVar26;
          if ((int)start2 - (int)pBVar26 < iVar13) {
            iVar8 = iVar13;
          }
          for (; (iVar8 < back_17 && (pBVar26[back_17 + -1] == pLVar16[back_17 + -1]));
              back_17 = back_17 + -1) {
          }
        }
        if ((int)local_45c < (int)(local_5c4 + (4 - back_17))) {
          ref3 = pBVar27 + back_17 + (matchIndex_2 - (int)pBVar29);
          start3 = pBVar26 + back_17;
          local_45c = local_5c4 + (4 - back_17);
        }
      }
      uVar14 = dictMatchIndex_2 & 0xffff;
      dictMatchIndex_2 = dictMatchIndex_2 - pLVar24->chainTable[uVar14];
      matchIndex_2 = matchIndex_2 - pLVar24->chainTable[uVar14];
      nbAttempts_2 = nbAttempts_2 + -1;
    }
  }
  ml3 = (int)local_45c;
LAB_0009cc60:
  sVar1 = (short)ip;
  if (ml2 != ml3) {
    if (ip + ml + 3 <= start3) {
      if (start2 < ip + ml) {
        if ((int)start2 - (int)ip < 0x12) {
          if (0x12 < ml) {
            ml = 0x12;
          }
          if (start2 + ml2 + -4 < ip + ml) {
            ml = (int)(start2 + (ml2 - (int)ip) + -4);
          }
          iVar22 = ml - ((int)start2 - (int)ip);
          if (0 < iVar22) {
            start2 = start2 + iVar22;
            ref2 = ref2 + iVar22;
            ml2 = ml2 - iVar22;
          }
        }
        else {
          ml = (int)start2 - (int)ip;
        }
      }
      optr = op;
      pBVar26 = op + 1;
      uVar14 = (int)ip - (int)anchor;
      if ((limit == notLimited) || (pBVar26 + uVar14 + uVar14 / 0xff + 8 <= oend)) {
        if (uVar14 < 0xf) {
          *op = (BYTE)((uVar14 & 0xff) << 4);
          op = pBVar26;
        }
        else {
          *op = 0xf0;
          op = pBVar26;
          for (len_4 = uVar14 - 0xf; 0xfe < len_4; len_4 = len_4 - 0xff) {
            *op = 0xff;
            op = op + 1;
          }
          *op = (BYTE)len_4;
          op = op + 1;
        }
        d_4 = op;
        s_4 = anchor;
        do {
          uVar17 = *(undefined4 *)(s_4 + 4);
          *(undefined4 *)d_4 = *(undefined4 *)s_4;
          *(undefined4 *)(d_4 + 4) = uVar17;
          d_4 = d_4 + 8;
          s_4 = s_4 + 8;
        } while (d_4 < op + uVar14);
        LZ4_writeLE16(op + uVar14,sVar1 - (short)ref);
        op = op + uVar14 + 2;
        uVar14 = ml - 4;
        if ((limit == notLimited) || (op + uVar14 / 0xff + 6 <= oend)) {
          if (uVar14 < 0xf) {
            *pBVar25 = (char)uVar14 + *pBVar25;
          }
          else {
            *pBVar25 = *pBVar25 + '\x0f';
            for (length_4 = ml - 0x13; 0x1fd < length_4; length_4 = length_4 - 0x1fe) {
              pBVar25 = op + 1;
              *op = 0xff;
              op = op + 2;
              *pBVar25 = 0xff;
            }
            if (0xfe < length_4) {
              length_4 = length_4 - 0xff;
              *op = 0xff;
              op = op + 1;
            }
            *op = (BYTE)length_4;
            op = op + 1;
          }
          anchor = ip + ml;
          bVar38 = false;
          ip = anchor;
        }
        else {
          bVar38 = true;
        }
      }
      else {
        bVar38 = true;
        op = pBVar26;
      }
      if (bVar38) goto LAB_0009df42;
      ip = start2;
      ref = ref2;
      ml = ml2;
      start2 = start3;
      ref2 = ref3;
      ml2 = ml3;
      goto LAB_0009b5a2;
    }
    if (start3 < ip + ml) {
      start2 = start3;
      ref2 = ref3;
      ml2 = ml3;
      goto LAB_0009b5a2;
    }
    if (start2 < ip + ml) {
      pBVar26 = ip + (ml - (int)start2);
      start2 = start2 + (int)pBVar26;
      ref2 = ref2 + (int)pBVar26;
      ml2 = ml2 - (int)pBVar26;
      if (ml2 < 4) {
        start2 = start3;
        ref2 = ref3;
        ml2 = ml3;
      }
    }
    optr = op;
    pBVar26 = op + 1;
    uVar14 = (int)ip - (int)anchor;
    if ((limit == notLimited) || (pBVar26 + uVar14 + uVar14 / 0xff + 8 <= oend)) {
      if (uVar14 < 0xf) {
        *op = (BYTE)((uVar14 & 0xff) << 4);
        op = pBVar26;
      }
      else {
        *op = 0xf0;
        op = pBVar26;
        for (len_3 = uVar14 - 0xf; 0xfe < len_3; len_3 = len_3 - 0xff) {
          *op = 0xff;
          op = op + 1;
        }
        *op = (BYTE)len_3;
        op = op + 1;
      }
      d_3 = op;
      s_3 = anchor;
      do {
        uVar17 = *(undefined4 *)(s_3 + 4);
        *(undefined4 *)d_3 = *(undefined4 *)s_3;
        *(undefined4 *)(d_3 + 4) = uVar17;
        d_3 = d_3 + 8;
        s_3 = s_3 + 8;
      } while (d_3 < op + uVar14);
      LZ4_writeLE16(op + uVar14,sVar1 - (short)ref);
      op = op + uVar14 + 2;
      uVar14 = ml - 4;
      if ((limit == notLimited) || (op + uVar14 / 0xff + 6 <= oend)) {
        if (uVar14 < 0xf) {
          *pBVar25 = (char)uVar14 + *pBVar25;
        }
        else {
          *pBVar25 = *pBVar25 + '\x0f';
          for (length_3 = ml - 0x13; 0x1fd < length_3; length_3 = length_3 - 0x1fe) {
            pBVar25 = op + 1;
            *op = 0xff;
            op = op + 2;
            *pBVar25 = 0xff;
          }
          if (0xfe < length_3) {
            length_3 = length_3 - 0xff;
            *op = 0xff;
            op = op + 1;
          }
          *op = (BYTE)length_3;
          op = op + 1;
        }
        anchor = ip + ml;
        bVar38 = false;
        ip = anchor;
      }
      else {
        bVar38 = true;
      }
    }
    else {
      bVar38 = true;
      op = pBVar26;
    }
    if (bVar38) goto LAB_0009df42;
    ip = start3;
    ref = ref3;
    ml = ml3;
    start0 = start2;
    ref0 = ref2;
    ml0 = ml2;
    goto LAB_00099b76;
  }
  if (start2 < ip + ml) {
    ml = (int)start2 - (int)ip;
  }
  optr = op;
  pBVar26 = op + 1;
  uVar14 = (int)ip - (int)anchor;
  if ((limit == notLimited) || (pBVar26 + uVar14 + uVar14 / 0xff + 8 <= oend)) {
    if (uVar14 < 0xf) {
      *op = (BYTE)((uVar14 & 0xff) << 4);
      op = pBVar26;
    }
    else {
      *op = 0xf0;
      op = pBVar26;
      for (len_1 = uVar14 - 0xf; 0xfe < len_1; len_1 = len_1 - 0xff) {
        *op = 0xff;
        op = op + 1;
      }
      *op = (BYTE)len_1;
      op = op + 1;
    }
    d_1 = op;
    s_1 = anchor;
    do {
      uVar17 = *(undefined4 *)(s_1 + 4);
      *(undefined4 *)d_1 = *(undefined4 *)s_1;
      *(undefined4 *)(d_1 + 4) = uVar17;
      d_1 = d_1 + 8;
      s_1 = s_1 + 8;
    } while (d_1 < op + uVar14);
    LZ4_writeLE16(op + uVar14,sVar1 - (short)ref);
    op = op + uVar14 + 2;
    uVar14 = ml - 4;
    if ((limit == notLimited) || (op + uVar14 / 0xff + 6 <= oend)) {
      if (uVar14 < 0xf) {
        *pBVar25 = (char)uVar14 + *pBVar25;
      }
      else {
        *pBVar25 = *pBVar25 + '\x0f';
        for (length_1 = ml - 0x13; 0x1fd < length_1; length_1 = length_1 - 0x1fe) {
          pBVar25 = op + 1;
          *op = 0xff;
          op = op + 2;
          *pBVar25 = 0xff;
        }
        if (0xfe < length_1) {
          length_1 = length_1 - 0xff;
          *op = 0xff;
          op = op + 1;
        }
        *op = (BYTE)length_1;
        op = op + 1;
      }
      anchor = ip + ml;
      bVar38 = false;
      ip = anchor;
    }
    else {
      bVar38 = true;
    }
  }
  else {
    bVar38 = true;
    op = pBVar26;
  }
  pBVar25 = op;
  if (bVar38) goto LAB_0009df42;
  ip = start2;
  optr = op;
  pBVar26 = op + 1;
  uVar14 = (int)start2 - (int)anchor;
  if ((limit == notLimited) || (pBVar26 + uVar14 + uVar14 / 0xff + 8 <= oend)) {
    if (uVar14 < 0xf) {
      *op = (BYTE)((uVar14 & 0xff) << 4);
      op = pBVar26;
    }
    else {
      *op = 0xf0;
      op = pBVar26;
      for (len_2 = uVar14 - 0xf; 0xfe < len_2; len_2 = len_2 - 0xff) {
        *op = 0xff;
        op = op + 1;
      }
      *op = (BYTE)len_2;
      op = op + 1;
    }
    d_2 = op;
    s_2 = anchor;
    do {
      uVar17 = *(undefined4 *)(s_2 + 4);
      *(undefined4 *)d_2 = *(undefined4 *)s_2;
      *(undefined4 *)(d_2 + 4) = uVar17;
      d_2 = d_2 + 8;
      s_2 = s_2 + 8;
    } while (d_2 < op + uVar14);
    LZ4_writeLE16(op + uVar14,(short)start2 - (short)ref2);
    op = op + uVar14 + 2;
    uVar14 = ml2 - 4;
    if ((limit == notLimited) || (op + uVar14 / 0xff + 6 <= oend)) {
      if (uVar14 < 0xf) {
        *pBVar25 = (char)uVar14 + *pBVar25;
      }
      else {
        *pBVar25 = *pBVar25 + '\x0f';
        for (length_2 = ml2 - 0x13; 0x1fd < length_2; length_2 = length_2 - 0x1fe) {
          pBVar25 = op + 1;
          *op = 0xff;
          op = op + 2;
          *pBVar25 = 0xff;
        }
        if (0xfe < length_2) {
          length_2 = length_2 - 0xff;
          *op = 0xff;
          op = op + 1;
        }
        *op = (BYTE)length_2;
        op = op + 1;
      }
      anchor = start2 + ml2;
      bVar38 = false;
      ip = anchor;
    }
    else {
      bVar38 = true;
    }
  }
  else {
    bVar38 = true;
    op = pBVar26;
  }
  if (bVar38) {
    ml = ml2;
    ref._0_2_ = (short)ref2;
    goto LAB_0009df42;
  }
  goto LAB_0009dd80;
LAB_0009df42:
  if (limit != fillOutput) {
    result = 0;
    goto LAB_0009e402;
  }
  pBVar23 = ip + ((uint)(ip + (0xf0 - (int)anchor)) / 0xff - (int)anchor) + 1;
  op = optr;
  if (optr + (int)pBVar23 <= oend + -3) {
    uVar14 = ((int)(oend + -3) - (int)(optr + (int)pBVar23)) * 0xff + 0x12;
    if (uVar14 < (uint)ml) {
      ml = uVar14;
    }
    if (0xb < (int)(oend + ml + (-(int)pBVar23 - (int)optr) + 2)) {
      op = optr + 1;
      uVar14 = (int)ip - (int)anchor;
      if (uVar14 < 0xf) {
        *optr = (BYTE)((uVar14 & 0xff) << 4);
      }
      else {
        *optr = 0xf0;
        for (len_5 = uVar14 - 0xf; 0xfe < len_5; len_5 = len_5 - 0xff) {
          *op = 0xff;
          op = op + 1;
        }
        *op = (BYTE)len_5;
        op = op + 1;
      }
      d_5 = op;
      s_5 = anchor;
      do {
        uVar17 = *(undefined4 *)(s_5 + 4);
        *(undefined4 *)d_5 = *(undefined4 *)s_5;
        *(undefined4 *)(d_5 + 4) = uVar17;
        d_5 = d_5 + 8;
        s_5 = s_5 + 8;
      } while (d_5 < op + uVar14);
      LZ4_writeLE16(op + uVar14,(short)ip - (short)ref);
      op = op + uVar14 + 2;
      if (ml - 4U < 0xf) {
        *optr = (char)(ml - 4U) + *optr;
      }
      else {
        *optr = *optr + '\x0f';
        for (length_5 = ml - 0x13; 0x1fd < length_5; length_5 = length_5 - 0x1fe) {
          pBVar23 = op + 1;
          *op = 0xff;
          op = op + 2;
          *pBVar23 = 0xff;
        }
        if (0xfe < length_5) {
          length_5 = length_5 - 0xff;
          *op = 0xff;
          op = op + 1;
        }
        *op = (BYTE)length_5;
        op = op + 1;
      }
      anchor = ip + ml;
    }
  }
  goto LAB_0009dd90;
}

