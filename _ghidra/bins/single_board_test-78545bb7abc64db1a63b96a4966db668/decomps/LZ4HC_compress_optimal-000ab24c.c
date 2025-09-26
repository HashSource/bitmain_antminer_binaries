
/* WARNING: Removing unreachable block (ram,0x000b056a) */
/* WARNING: Removing unreachable block (ram,0x000b0f40) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffff834 : 0x000acb9c */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int LZ4HC_compress_optimal
              (LZ4HC_CCtx_internal *ctx,char *source,char *dst,int *srcSizePtr,int dstCapacity,
              int nbSearches,size_t sufficient_len,limitedOutput_directive limit,int fullUpdate,
              dictCtx_directive dict,HCfavor_e favorDecSpeed)

{
  U16 UVar1;
  U16 UVar2;
  U32 UVar3;
  reg_t rVar4;
  reg_t rVar5;
  int iVar6;
  undefined4 uVar7;
  byte bVar8;
  char cVar9;
  byte bVar10;
  BYTE *pBVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  int *srcSizePtr_local;
  char *dst_local;
  char *source_local;
  LZ4HC_CCtx_internal *ctx_local;
  BYTE *matchPtr_5;
  LZ4HC_match_t match_1;
  BYTE *local_808;
  BYTE *matchPtr_10;
  LZ4HC_match_t match_2;
  int iStack_7f4;
  BYTE *local_7f0;
  LZ4HC_match_t newMatch;
  BYTE *matchPtr;
  LZ4HC_match_t match;
  BYTE *local_7d8;
  LZ4HC_match_t firstMatch;
  BYTE *op;
  BYTE *anchor;
  BYTE *ip;
  BYTE *e_2;
  BYTE *s_2;
  BYTE *d_2;
  BYTE *local_7b4;
  BYTE *local_7b0;
  BYTE *local_7ac;
  size_t len_2;
  size_t length_2;
  BYTE *token_2;
  BYTE *local_79c;
  int local_798;
  BYTE *local_794;
  int local_790;
  BYTE **local_78c;
  BYTE **local_788;
  BYTE **local_784;
  BYTE *e_1;
  BYTE *s_1;
  BYTE *d_1;
  BYTE *local_774;
  BYTE *local_770;
  BYTE *local_76c;
  size_t len_1;
  size_t length_1;
  BYTE *token_1;
  BYTE *local_75c;
  limitedOutput_directive local_758;
  int local_754;
  int local_750;
  BYTE **local_74c;
  BYTE **local_748;
  BYTE **local_744;
  int price_12;
  int local_73c;
  int price_11;
  undefined4 local_734;
  int price_10;
  int local_72c;
  undefined4 local_728;
  int price_9;
  int local_720;
  int price_8;
  int local_718;
  int local_714;
  int price_6;
  int local_70c;
  int price_5;
  int local_704;
  int matchLength_4;
  U32 nextOffset_2;
  int min_8;
  int back_17;
  LZ4_byte *local_6f0;
  BYTE *local_6ec;
  BYTE *local_6e8;
  BYTE *local_6e4;
  int mlt_2;
  reg_t diff_23;
  reg_t diff_22;
  BYTE *pStart_11;
  BYTE *local_6d0;
  BYTE *local_6cc;
  BYTE *local_6c8;
  BYTE *vLimit_5;
  int back_16;
  BYTE *matchPtr_14;
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
  BYTE *matchPtr_13;
  int extDict_2;
  U32 matchCandidateIdx_2;
  U32 distNextMatch_2;
  U32 candidateDist_2;
  int pos_2;
  int accel_2;
  int step_2;
  int end_2;
  U32 distanceToNextMatch_2;
  int kTrigger_2;
  int min_7;
  int back_15;
  BYTE *local_650;
  BYTE *local_64c;
  BYTE *local_648;
  BYTE *local_644;
  reg_t diff_21;
  reg_t diff_20;
  BYTE *pStart_10;
  BYTE *local_634;
  BYTE *local_630;
  BYTE *local_62c;
  reg_t diff_19;
  reg_t diff_18;
  BYTE *pStart_9;
  BYTE *local_61c;
  BYTE *local_618;
  BYTE *local_614;
  BYTE *vLimit_4;
  int back_14;
  BYTE *matchPtr_12;
  reg_t diff_17;
  reg_t diff_16;
  BYTE *pStart_8;
  BYTE *local_5f8;
  BYTE *local_5f4;
  BYTE *local_5f0;
  int back_12;
  int min_6;
  int back_13;
  BYTE *local_5e0;
  BYTE *local_5dc;
  BYTE *local_5d8;
  BYTE *local_5d4;
  BYTE *matchPtr_11;
  int matchLength_5;
  U32 matchIndex_2;
  size_t delta_2;
  U32 h_2;
  U32 idx_2;
  U32 target_2;
  U32 prefixIdx_5;
  BYTE *prefixPtr_5;
  U32 *hashTable_2;
  U16 *chainTable_5;
  BYTE *local_5a4;
  LZ4HC_CCtx_internal *local_5a0;
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
  HCfavor_e local_558;
  dictCtx_directive local_554;
  int local_550;
  BYTE **local_54c;
  BYTE **local_548;
  uint local_544;
  BYTE *local_540;
  BYTE *local_53c;
  BYTE *local_538;
  LZ4HC_CCtx_internal *local_534;
  HCfavor_e local_530;
  dictCtx_directive local_52c;
  int local_528;
  uint local_524;
  BYTE *local_520;
  LZ4HC_CCtx_internal *local_51c;
  int matchLength_2;
  U32 nextOffset_1;
  int min_5;
  int back_11;
  LZ4_byte *local_508;
  BYTE *local_504;
  BYTE *local_500;
  BYTE *local_4fc;
  int mlt_1;
  reg_t diff_15;
  reg_t diff_14;
  BYTE *pStart_7;
  BYTE *local_4e8;
  BYTE *local_4e4;
  BYTE *local_4e0;
  BYTE *vLimit_3;
  int back_10;
  BYTE *matchPtr_9;
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
  BYTE *matchPtr_8;
  int extDict_1;
  U32 matchCandidateIdx_1;
  U32 distNextMatch_1;
  U32 candidateDist_1;
  int pos_1;
  int accel_1;
  int step_1;
  int end_1;
  U32 distanceToNextMatch_1;
  int kTrigger_1;
  int min_4;
  int back_9;
  BYTE *local_468;
  BYTE *local_464;
  BYTE *local_460;
  BYTE *local_45c;
  reg_t diff_13;
  reg_t diff_12;
  BYTE *pStart_6;
  BYTE *local_44c;
  BYTE *local_448;
  BYTE *local_444;
  reg_t diff_11;
  reg_t diff_10;
  BYTE *pStart_5;
  BYTE *local_434;
  BYTE *local_430;
  BYTE *local_42c;
  BYTE *vLimit_2;
  int back_8;
  BYTE *matchPtr_7;
  reg_t diff_9;
  reg_t diff_8;
  BYTE *pStart_4;
  BYTE *local_410;
  BYTE *local_40c;
  BYTE *local_408;
  int back_6;
  int min_3;
  int back_7;
  BYTE *local_3f8;
  BYTE *local_3f4;
  BYTE *local_3f0;
  BYTE *local_3ec;
  BYTE *matchPtr_6;
  int matchLength_3;
  U32 matchIndex_1;
  size_t delta_1;
  U32 h_1;
  U32 idx_1;
  U32 target_1;
  U32 prefixIdx_3;
  BYTE *prefixPtr_3;
  U32 *hashTable_1;
  U16 *chainTable_3;
  BYTE *local_3bc;
  LZ4HC_CCtx_internal *local_3b8;
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
  HCfavor_e local_370;
  dictCtx_directive local_36c;
  int local_368;
  BYTE **local_364;
  BYTE **local_360;
  uint local_35c;
  BYTE *local_358;
  BYTE *local_354;
  BYTE *local_350;
  LZ4HC_CCtx_internal *local_34c;
  HCfavor_e local_348;
  dictCtx_directive local_344;
  int local_340;
  int local_33c;
  BYTE *local_338;
  LZ4HC_CCtx_internal *local_334;
  int price_3;
  int local_32c;
  int price_2;
  int local_324;
  int price_1;
  int local_31c;
  int local_318;
  int price;
  int local_310;
  BYTE *e;
  BYTE *s;
  BYTE *d;
  BYTE *local_300;
  BYTE *local_2fc;
  BYTE *local_2f8;
  size_t len;
  size_t length;
  BYTE *token;
  BYTE *local_2e8;
  limitedOutput_directive local_2e4;
  BYTE *local_2e0;
  int local_2dc;
  BYTE **local_2d8;
  BYTE **local_2d4;
  BYTE **local_2d0;
  int matchLength;
  U32 nextOffset;
  int min_2;
  int back_5;
  LZ4_byte *local_2bc;
  BYTE *local_2b8;
  BYTE *local_2b4;
  BYTE *local_2b0;
  int mlt;
  reg_t diff_7;
  reg_t diff_6;
  BYTE *pStart_3;
  BYTE *local_29c;
  BYTE *local_298;
  BYTE *local_294;
  BYTE *vLimit_1;
  int back_4;
  BYTE *matchPtr_4;
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
  BYTE *matchPtr_3;
  int extDict;
  U32 matchCandidateIdx;
  U32 distNextMatch;
  U32 candidateDist;
  int pos;
  int accel;
  int step;
  int end;
  U32 distanceToNextMatch;
  int kTrigger;
  int min_1;
  int back_3;
  BYTE *local_21c;
  BYTE *local_218;
  BYTE *local_214;
  BYTE *local_210;
  reg_t diff_5;
  reg_t diff_4;
  BYTE *pStart_2;
  BYTE *local_200;
  BYTE *local_1fc;
  BYTE *local_1f8;
  reg_t diff_3;
  reg_t diff_2;
  BYTE *pStart_1;
  BYTE *local_1e8;
  BYTE *local_1e4;
  BYTE *local_1e0;
  BYTE *vLimit;
  int back_2;
  BYTE *matchPtr_2;
  reg_t diff_1;
  reg_t diff;
  BYTE *pStart;
  BYTE *local_1c4;
  BYTE *local_1c0;
  BYTE *local_1bc;
  int back;
  int min;
  int back_1;
  BYTE *local_1ac;
  BYTE *local_1a8;
  BYTE *local_1a4;
  BYTE *local_1a0;
  BYTE *matchPtr_1;
  int matchLength_1;
  U32 matchIndex;
  size_t delta;
  U32 h;
  U32 idx;
  U32 target;
  U32 prefixIdx_1;
  BYTE *prefixPtr_1;
  U32 *hashTable;
  U16 *chainTable_1;
  BYTE *local_170;
  LZ4HC_CCtx_internal *local_16c;
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
  HCfavor_e local_124;
  dictCtx_directive local_120;
  int local_11c;
  BYTE **local_118;
  BYTE **local_114;
  uint local_110;
  BYTE *local_10c;
  BYTE *local_108;
  BYTE *local_104;
  LZ4HC_CCtx_internal *local_100;
  HCfavor_e local_fc;
  dictCtx_directive local_f8;
  int local_f4;
  int local_f0;
  BYTE *local_ec;
  LZ4HC_CCtx_internal *local_e8;
  size_t totalSize;
  size_t llAdd;
  size_t maxMlSize;
  size_t bytesLeftForMl;
  BYTE *maxLitPos;
  size_t ll_totalCost;
  size_t ll_addbytes;
  size_t ll_1;
  BYTE *matchPos;
  int firstML;
  int offset_2;
  int ml_1;
  int next_offset;
  int next_matchLength;
  int offset_1;
  int pos_4;
  int matchML_1;
  int pos_3;
  int price_4;
  int baseLitlen;
  BYTE *curPtr;
  int cost_1;
  int offset;
  int matchML;
  int cost;
  int llen;
  BYTE *matchlimit;
  BYTE *mflimit;
  BYTE *iend;
  LZ4HC_optimal_t *opt;
  size_t accumulator;
  size_t lastRunSize;
  int rPos_1;
  int selected_offset;
  int selected_matchLength;
  int candidate_pos;
  int addLit_1;
  int ll;
  int price_7;
  int ml;
  int litlen;
  int addLit;
  int mlen;
  int rPos;
  int last_match_pos;
  int cur;
  int best_off;
  int best_mlen;
  BYTE *ovref;
  int ovml;
  BYTE *oend;
  BYTE *opSaved;
  int retval;
  
  retval = 0;
  opt = (LZ4HC_optimal_t *)malloc(0x10030);
  iend = (BYTE *)(source + *srcSizePtr);
  mflimit = iend + -0xc;
  matchlimit = iend + -5;
  oend = (BYTE *)(dst + dstCapacity);
  ovml = 4;
  ovref = (BYTE *)0x0;
  op = (BYTE *)dst;
  anchor = (BYTE *)source;
  ip = (BYTE *)source;
  opSaved = (BYTE *)dst;
  if (opt != (LZ4HC_optimal_t *)0x0) {
    *srcSizePtr = 0;
    if (limit == fillOutput) {
      oend = oend + -5;
    }
    if (0xfff < sufficient_len) {
      sufficient_len = 0xfff;
    }
LAB_000b0c5e:
    if (ip <= mflimit) {
      llen = (int)ip - (int)anchor;
      last_match_pos = 0;
      local_7d8 = ip;
      local_ec = matchlimit;
      local_f0 = 3;
      local_f4 = nbSearches;
      local_f8 = dict;
      local_fc = favorDecSpeed;
      match.off = 0;
      match.len = 0;
      matchPtr = (BYTE *)0x0;
      local_104 = ip;
      local_108 = ip;
      local_10c = matchlimit;
      local_110 = 3;
      local_114 = &matchPtr;
      local_118 = &local_7d8;
      local_11c = nbSearches;
      local_120 = dict;
      local_124 = favorDecSpeed;
      chainTable = ctx->chainTable;
      dictCtx = ctx->dictCtx;
      prefixPtr = ctx->prefixStart;
      prefixIdx = ctx->dictLimit;
      ipIndex = (U32)(ip + (prefixIdx - (int)prefixPtr));
      pBVar11 = (BYTE *)(ctx->lowLimit + 0x10000);
      bVar14 = ipIndex < pBVar11;
      if (bVar14) {
        pBVar11 = (BYTE *)0x1;
      }
      bVar8 = (byte)pBVar11;
      if (!bVar14) {
        bVar8 = 0;
      }
      withinStartDistance = (int)bVar8;
      if (withinStartDistance == 0) {
        lowestMatchIndex = ipIndex + -0xffff;
      }
      else {
        lowestMatchIndex = ctx->lowLimit;
      }
      dictStart = ctx->dictStart;
      dictIdx = ctx->lowLimit;
      dictEnd = dictStart + (prefixIdx - dictIdx);
      lookBackLength = 0;
      nbAttempts = nbSearches;
      matchChainPos = 0;
      HashTable = ctx->hashTable;
      local_100 = ctx;
      local_e8 = ctx;
      pattern = LZ4_read32(ip);
      repeat = rep_untested;
      srcPatternLength = 0;
      local_16c = local_100;
      local_170 = local_104;
      chainTable_1 = local_100->chainTable;
      hashTable = local_100->hashTable;
      prefixPtr_1 = local_100->prefixStart;
      prefixIdx_1 = local_100->dictLimit;
      target = (U32)(local_104 + (prefixIdx_1 - (int)prefixPtr_1));
      for (idx = local_100->nextToUpdate; idx < target; idx = idx + 1) {
        h = LZ4HC_hashPtr(prefixPtr_1 + (idx - prefixIdx_1));
        delta = idx - hashTable[h];
        if (0xffff < delta) {
          delta = 0xffff;
        }
        chainTable_1[idx & 0xffff] = (U16)delta;
        hashTable[h] = idx;
      }
      local_16c->nextToUpdate = target;
      UVar3 = LZ4HC_hashPtr(local_104);
      matchIndex = HashTable[UVar3];
LAB_000ac590:
      do {
        if ((matchIndex < lowestMatchIndex) || (nbAttempts < 1)) goto LAB_000ac5ac;
        matchLength_1 = 0;
        nbAttempts = nbAttempts + -1;
        if ((local_124 == favorCompressionRatio) || (7 < ipIndex - matchIndex)) {
          if (matchIndex < prefixIdx) {
            matchPtr_2 = dictStart + (matchIndex - dictIdx);
            uVar12 = prefixIdx - 4;
            uVar13 = uVar12;
            if (matchIndex <= uVar12) {
              uVar13 = 1;
            }
            cVar9 = (char)uVar13;
            if (uVar12 < matchIndex) {
              cVar9 = '\0';
            }
            if ((cVar9 == '\0') || (UVar3 = LZ4_read32(matchPtr_2), pattern != UVar3))
            goto LAB_000abfaa;
            back_2 = 0;
            vLimit = local_104 + (prefixIdx - matchIndex);
            if (local_10c < vLimit) {
              vLimit = local_10c;
            }
            pStart_1 = local_104 + 4;
            local_1e4 = matchPtr_2 + 4;
            local_1e8 = vLimit;
            pBVar11 = vLimit + -3;
            bVar14 = pStart_1 < pBVar11;
            if (bVar14) {
              pBVar11 = (BYTE *)0x1;
            }
            cVar9 = (char)pBVar11;
            if (!bVar14) {
              cVar9 = '\0';
            }
            local_1e0 = pStart_1;
            if (cVar9 == '\0') {
LAB_000abbd2:
              while( true ) {
                pBVar11 = local_1e8 + -3;
                bVar14 = local_1e0 < pBVar11;
                if (bVar14) {
                  pBVar11 = (BYTE *)0x1;
                }
                cVar9 = (char)pBVar11;
                if (!bVar14) {
                  cVar9 = '\0';
                }
                if (cVar9 == '\0') {
                  if (local_1e0 < local_1e8 + -1) {
                    UVar1 = LZ4_read16(local_1e4);
                    UVar2 = LZ4_read16(local_1e0);
                    if (UVar1 == UVar2) {
                      local_1e0 = local_1e0 + 2;
                      local_1e4 = local_1e4 + 2;
                    }
                  }
                  if ((local_1e0 < local_1e8) && (*local_1e4 == *local_1e0)) {
                    local_1e0 = local_1e0 + 1;
                  }
                  uVar13 = (int)local_1e0 - (int)pStart_1;
                  goto LAB_000abc7a;
                }
                rVar4 = LZ4_read_ARCH(local_1e4);
                rVar5 = LZ4_read_ARCH(local_1e0);
                diff_3 = rVar5 ^ rVar4;
                if (diff_3 != 0) break;
                local_1e0 = local_1e0 + 4;
                local_1e4 = local_1e4 + 4;
              }
              uVar13 = LZ4_NbCommonBytes(diff_3);
              local_1e0 = local_1e0 + uVar13;
              uVar13 = (int)local_1e0 - (int)pStart_1;
            }
            else {
              rVar4 = LZ4_read_ARCH(local_1e4);
              rVar5 = LZ4_read_ARCH(local_1e0);
              diff_2 = rVar5 ^ rVar4;
              if (diff_2 == 0) {
                local_1e0 = local_1e0 + 4;
                local_1e4 = local_1e4 + 4;
                goto LAB_000abbd2;
              }
              uVar13 = LZ4_NbCommonBytes(diff_2);
            }
LAB_000abc7a:
            matchLength_1 = uVar13 + 4;
            if ((vLimit == local_104 + matchLength_1) && (vLimit < local_10c)) {
              pStart_2 = local_104 + matchLength_1;
              local_1fc = prefixPtr;
              local_200 = local_10c;
              pBVar11 = local_10c + -3;
              bVar14 = pStart_2 < pBVar11;
              if (bVar14) {
                pBVar11 = (BYTE *)0x1;
              }
              cVar9 = (char)pBVar11;
              if (!bVar14) {
                cVar9 = '\0';
              }
              local_1f8 = pStart_2;
              if (cVar9 == '\0') {
LAB_000abdc6:
                while( true ) {
                  pBVar11 = local_200 + -3;
                  bVar14 = local_1f8 < pBVar11;
                  if (bVar14) {
                    pBVar11 = (BYTE *)0x1;
                  }
                  cVar9 = (char)pBVar11;
                  if (!bVar14) {
                    cVar9 = '\0';
                  }
                  if (cVar9 == '\0') {
                    if (local_1f8 < local_200 + -1) {
                      UVar1 = LZ4_read16(local_1fc);
                      UVar2 = LZ4_read16(local_1f8);
                      if (UVar1 == UVar2) {
                        local_1f8 = local_1f8 + 2;
                        local_1fc = local_1fc + 2;
                      }
                    }
                    if ((local_1f8 < local_200) && (*local_1fc == *local_1f8)) {
                      local_1f8 = local_1f8 + 1;
                    }
                    uVar13 = (int)local_1f8 - (int)pStart_2;
                    goto LAB_000abe70;
                  }
                  rVar4 = LZ4_read_ARCH(local_1fc);
                  rVar5 = LZ4_read_ARCH(local_1f8);
                  diff_5 = rVar5 ^ rVar4;
                  if (diff_5 != 0) break;
                  local_1f8 = local_1f8 + 4;
                  local_1fc = local_1fc + 4;
                }
                uVar13 = LZ4_NbCommonBytes(diff_5);
                local_1f8 = local_1f8 + uVar13;
                uVar13 = (int)local_1f8 - (int)pStart_2;
              }
              else {
                rVar4 = LZ4_read_ARCH(prefixPtr);
                rVar5 = LZ4_read_ARCH(local_1f8);
                diff_4 = rVar5 ^ rVar4;
                if (diff_4 == 0) {
                  local_1f8 = local_1f8 + 4;
                  local_1fc = local_1fc + 4;
                  goto LAB_000abdc6;
                }
                uVar13 = LZ4_NbCommonBytes(diff_4);
              }
LAB_000abe70:
              matchLength_1 = uVar13 + matchLength_1;
            }
            if (lookBackLength == 0) {
              back_2 = 0;
            }
            else {
              local_210 = local_104;
              local_214 = matchPtr_2;
              local_218 = local_108;
              local_21c = dictStart;
              back_3 = 0;
              min_1 = (int)local_108 - (int)local_104;
              if ((int)local_108 - (int)local_104 < (int)dictStart - (int)matchPtr_2) {
                min_1 = (int)dictStart - (int)matchPtr_2;
              }
              for (; (back_2 = back_3, min_1 < back_3 &&
                     (local_104[back_3 + -1] == matchPtr_2[back_3 + -1])); back_3 = back_3 + -1) {
              }
            }
            matchLength_1 = matchLength_1 - back_2;
            if ((int)local_110 < matchLength_1) {
              local_110 = matchLength_1;
              *local_114 = prefixPtr + back_2 + (matchIndex - prefixIdx);
              *local_118 = local_104 + back_2;
            }
          }
          else {
            matchPtr_1 = prefixPtr + (matchIndex - prefixIdx);
            UVar1 = LZ4_read16(local_108 + (local_110 - 1));
            UVar2 = LZ4_read16(matchPtr_1 + (local_110 - lookBackLength) + -1);
            if ((UVar1 != UVar2) || (UVar3 = LZ4_read32(matchPtr_1), pattern != UVar3))
            goto LAB_000abfaa;
            if (lookBackLength == 0) {
              back = 0;
            }
            else {
              local_1a0 = local_104;
              local_1a4 = matchPtr_1;
              local_1a8 = local_108;
              local_1ac = prefixPtr;
              back_1 = 0;
              min = (int)local_108 - (int)local_104;
              if ((int)local_108 - (int)local_104 < (int)prefixPtr - (int)matchPtr_1) {
                min = (int)prefixPtr - (int)matchPtr_1;
              }
              for (; (back = back_1, min < back_1 &&
                     (local_104[back_1 + -1] == matchPtr_1[back_1 + -1])); back_1 = back_1 + -1) {
              }
            }
            pStart = local_104 + 4;
            local_1c0 = matchPtr_1 + 4;
            local_1c4 = local_10c;
            pBVar11 = local_10c + -3;
            bVar14 = pStart < pBVar11;
            if (bVar14) {
              pBVar11 = (BYTE *)0x1;
            }
            cVar9 = (char)pBVar11;
            if (!bVar14) {
              cVar9 = '\0';
            }
            local_1bc = pStart;
            if (cVar9 == '\0') {
LAB_000ab920:
              while( true ) {
                pBVar11 = local_1c4 + -3;
                bVar14 = local_1bc < pBVar11;
                if (bVar14) {
                  pBVar11 = (BYTE *)0x1;
                }
                cVar9 = (char)pBVar11;
                if (!bVar14) {
                  cVar9 = '\0';
                }
                if (cVar9 == '\0') {
                  if (local_1bc < local_1c4 + -1) {
                    UVar1 = LZ4_read16(local_1c0);
                    UVar2 = LZ4_read16(local_1bc);
                    if (UVar1 == UVar2) {
                      local_1bc = local_1bc + 2;
                      local_1c0 = local_1c0 + 2;
                    }
                  }
                  if ((local_1bc < local_1c4) && (*local_1c0 == *local_1bc)) {
                    local_1bc = local_1bc + 1;
                  }
                  uVar13 = (int)local_1bc - (int)pStart;
                  goto LAB_000ab9c8;
                }
                rVar4 = LZ4_read_ARCH(local_1c0);
                rVar5 = LZ4_read_ARCH(local_1bc);
                diff_1 = rVar5 ^ rVar4;
                if (diff_1 != 0) break;
                local_1bc = local_1bc + 4;
                local_1c0 = local_1c0 + 4;
              }
              uVar13 = LZ4_NbCommonBytes(diff_1);
              local_1bc = local_1bc + uVar13;
              uVar13 = (int)local_1bc - (int)pStart;
            }
            else {
              rVar4 = LZ4_read_ARCH(local_1c0);
              rVar5 = LZ4_read_ARCH(local_1bc);
              diff = rVar5 ^ rVar4;
              if (diff == 0) {
                local_1bc = local_1bc + 4;
                local_1c0 = local_1c0 + 4;
                goto LAB_000ab920;
              }
              uVar13 = LZ4_NbCommonBytes(diff);
            }
LAB_000ab9c8:
            matchLength_1 = (uVar13 + 4) - back;
            if ((int)local_110 < matchLength_1) {
              local_110 = matchLength_1;
              *local_114 = matchPtr_1 + back;
              *local_118 = local_104 + back;
            }
          }
        }
LAB_000abfaa:
        if ((matchLength_1 == local_110) && (matchIndex + local_110 <= ipIndex)) {
          kTrigger = 4;
          distanceToNextMatch = 1;
          end = local_110 - 3;
          step = 1;
          accel = 0x10;
          for (pos = 0; pos < end; pos = step + pos) {
            candidateDist = (U32)chainTable[(pos & 0xffffU) + (matchIndex & 0xffff) & 0xffff];
            step = accel >> 4;
            accel = accel + 1;
            if (distanceToNextMatch < candidateDist) {
              matchChainPos = pos;
              accel = 0x10;
              distanceToNextMatch = candidateDist;
            }
          }
          if (1 < distanceToNextMatch) {
            if (matchIndex < distanceToNextMatch) goto LAB_000ac5ac;
            matchIndex = matchIndex - distanceToNextMatch;
            goto LAB_000ac590;
          }
        }
        distNextMatch = (U32)chainTable[matchIndex & 0xffff];
        if ((distNextMatch == 1) && (matchChainPos == 0)) {
          matchCandidateIdx = matchIndex - 1;
          if (repeat == rep_untested) {
            uVar13 = pattern >> 0x10;
            bVar14 = (pattern & 0xffff) == uVar13;
            if (bVar14) {
              uVar13 = 1;
            }
            bVar8 = (byte)uVar13;
            if (!bVar14) {
              bVar8 = 0;
            }
            if (((pattern & 0xff) == pattern >> 0x18 & bVar8) == 0) {
              repeat = rep_not;
            }
            else {
              repeat = rep_confirmed;
              uVar13 = LZ4HC_countPattern(local_104 + 4,local_10c,pattern);
              srcPatternLength = uVar13 + 4;
            }
          }
          if (((repeat != rep_confirmed) || (matchCandidateIdx < lowestMatchIndex)) ||
             (iVar6 = LZ4HC_protectDictEnd(prefixIdx,matchCandidateIdx), iVar6 == 0))
          goto LAB_000ac560;
          UVar3 = matchCandidateIdx;
          if (matchCandidateIdx < prefixIdx) {
            UVar3 = 1;
          }
          bVar8 = (byte)UVar3;
          if (prefixIdx <= matchCandidateIdx) {
            bVar8 = 0;
          }
          extDict = (int)bVar8;
          if (extDict == 0) {
            iVar6 = (int)prefixPtr - prefixIdx;
          }
          else {
            iVar6 = (int)dictStart - dictIdx;
          }
          matchPtr_3 = (BYTE *)(iVar6 + matchCandidateIdx);
          UVar3 = LZ4_read32(matchPtr_3);
          if (pattern != UVar3) goto LAB_000ac560;
          iLimit = local_10c;
          if (extDict != 0) {
            iLimit = dictEnd;
          }
          uVar13 = LZ4HC_countPattern(matchPtr_3 + 4,iLimit,pattern);
          forwardPatternLength = uVar13 + 4;
          if ((extDict != 0) && (iLimit == matchPtr_3 + forwardPatternLength)) {
            rotatedPattern = LZ4HC_rotatePattern(forwardPatternLength,pattern);
            uVar13 = LZ4HC_countPattern(prefixPtr,local_10c,rotatedPattern);
            forwardPatternLength = forwardPatternLength + uVar13;
          }
          lowestMatchPtr = prefixPtr;
          if (extDict != 0) {
            lowestMatchPtr = dictStart;
          }
          backLength = LZ4HC_reverseCountPattern(matchPtr_3,lowestMatchPtr,pattern);
          if (((extDict == 0) && (prefixPtr == matchPtr_3 + -backLength)) && (dictIdx < prefixIdx))
          {
            rotatedPattern_1 = LZ4HC_rotatePattern(-backLength,pattern);
            uVar13 = LZ4HC_reverseCountPattern(dictEnd,dictStart,rotatedPattern_1);
            backLength = backLength + uVar13;
          }
          uVar13 = matchCandidateIdx - backLength;
          if (matchCandidateIdx - backLength < lowestMatchIndex) {
            uVar13 = lowestMatchIndex;
          }
          backLength = matchCandidateIdx - uVar13;
          currentSegmentLength = forwardPatternLength + backLength;
          if ((currentSegmentLength < srcPatternLength) || (srcPatternLength < forwardPatternLength)
             ) {
            newMatchIndex_1 = matchCandidateIdx - backLength;
            iVar6 = LZ4HC_protectDictEnd(prefixIdx,newMatchIndex_1);
            if (iVar6 == 0) {
              matchIndex = prefixIdx;
            }
            else {
              matchIndex = newMatchIndex_1;
              if (lookBackLength == 0) {
                maxML = srcPatternLength;
                if (currentSegmentLength <= srcPatternLength) {
                  maxML = currentSegmentLength;
                }
                if (local_110 < maxML) {
                  if ((BYTE *)0xffff < local_104 + ((prefixIdx - (int)prefixPtr) - newMatchIndex_1))
                  goto LAB_000ac5ac;
                  local_110 = maxML;
                  *local_114 = prefixPtr + (newMatchIndex_1 - prefixIdx);
                  *local_118 = local_104;
                }
                distToNextPattern = (U32)chainTable[matchIndex & 0xffff];
                if (matchIndex < distToNextPattern) goto LAB_000ac5ac;
                matchIndex = matchIndex - distToNextPattern;
              }
            }
          }
          else {
            newMatchIndex = (matchCandidateIdx + forwardPatternLength) - srcPatternLength;
            iVar6 = LZ4HC_protectDictEnd(prefixIdx,newMatchIndex);
            if (iVar6 == 0) {
              matchIndex = prefixIdx;
            }
            else {
              matchIndex = newMatchIndex;
            }
          }
        }
        else {
LAB_000ac560:
          matchIndex = matchIndex -
                       chainTable[(matchChainPos & 0xffff) + (matchIndex & 0xffff) & 0xffff];
        }
      } while( true );
    }
    goto LAB_000b0c72;
  }
LAB_000b122c:
  free(opt);
  return retval;
LAB_000ac5ac:
  if (((local_120 == usingDictCtxHc) && (0 < nbAttempts)) && (ipIndex - lowestMatchIndex < 0xffff))
  {
    dictEndOffset = (size_t)(dictCtx->end + (dictCtx->dictLimit - (int)dictCtx->prefixStart));
    UVar3 = LZ4HC_hashPtr(local_104);
    dictMatchIndex = dictCtx->hashTable[UVar3];
    matchIndex = (lowestMatchIndex + dictMatchIndex) - dictEndOffset;
    while ((ipIndex - matchIndex < 0x10000 &&
           (iVar6 = nbAttempts + -1, bVar14 = nbAttempts != 0, nbAttempts = iVar6, bVar14))) {
      matchPtr_4 = dictCtx->prefixStart + (dictMatchIndex - dictCtx->dictLimit);
      UVar3 = LZ4_read32(matchPtr_4);
      if (pattern == UVar3) {
        back_4 = 0;
        vLimit_1 = local_104 + (dictEndOffset - dictMatchIndex);
        if (local_10c < vLimit_1) {
          vLimit_1 = local_10c;
        }
        pStart_3 = local_104 + 4;
        local_298 = matchPtr_4 + 4;
        local_29c = vLimit_1;
        pBVar11 = vLimit_1 + -3;
        bVar14 = pStart_3 < pBVar11;
        if (bVar14) {
          pBVar11 = (BYTE *)0x1;
        }
        cVar9 = (char)pBVar11;
        if (!bVar14) {
          cVar9 = '\0';
        }
        local_294 = pStart_3;
        if (cVar9 == '\0') {
LAB_000ac7da:
          while( true ) {
            pBVar11 = local_29c + -3;
            bVar14 = local_294 < pBVar11;
            if (bVar14) {
              pBVar11 = (BYTE *)0x1;
            }
            cVar9 = (char)pBVar11;
            if (!bVar14) {
              cVar9 = '\0';
            }
            if (cVar9 == '\0') {
              if (local_294 < local_29c + -1) {
                UVar1 = LZ4_read16(local_298);
                UVar2 = LZ4_read16(local_294);
                if (UVar1 == UVar2) {
                  local_294 = local_294 + 2;
                  local_298 = local_298 + 2;
                }
              }
              if ((local_294 < local_29c) && (*local_298 == *local_294)) {
                local_294 = local_294 + 1;
              }
              uVar13 = (int)local_294 - (int)pStart_3;
              goto LAB_000ac882;
            }
            rVar4 = LZ4_read_ARCH(local_298);
            rVar5 = LZ4_read_ARCH(local_294);
            diff_7 = rVar5 ^ rVar4;
            if (diff_7 != 0) break;
            local_294 = local_294 + 4;
            local_298 = local_298 + 4;
          }
          uVar13 = LZ4_NbCommonBytes(diff_7);
          local_294 = local_294 + uVar13;
          uVar13 = (int)local_294 - (int)pStart_3;
        }
        else {
          rVar4 = LZ4_read_ARCH(local_298);
          rVar5 = LZ4_read_ARCH(local_294);
          diff_6 = rVar5 ^ rVar4;
          if (diff_6 == 0) {
            local_294 = local_294 + 4;
            local_298 = local_298 + 4;
            goto LAB_000ac7da;
          }
          uVar13 = LZ4_NbCommonBytes(diff_6);
        }
LAB_000ac882:
        if (lookBackLength == 0) {
          back_4 = 0;
        }
        else {
          local_2bc = dictCtx->prefixStart;
          local_2b0 = local_104;
          local_2b4 = matchPtr_4;
          local_2b8 = local_108;
          back_5 = 0;
          min_2 = (int)local_108 - (int)local_104;
          if ((int)local_108 - (int)local_104 < (int)local_2bc - (int)matchPtr_4) {
            min_2 = (int)local_2bc - (int)matchPtr_4;
          }
          for (; (back_4 = back_5, min_2 < back_5 &&
                 (local_104[back_5 + -1] == matchPtr_4[back_5 + -1])); back_5 = back_5 + -1) {
          }
        }
        mlt = (uVar13 + 4) - back_4;
        if ((int)local_110 < mlt) {
          local_110 = mlt;
          *local_114 = prefixPtr + back_4 + (matchIndex - prefixIdx);
          *local_118 = local_104 + back_4;
        }
      }
      nextOffset = (U32)dictCtx->chainTable[dictMatchIndex & 0xffff];
      dictMatchIndex = dictMatchIndex - nextOffset;
      matchIndex = matchIndex - nextOffset;
    }
  }
  matchLength = local_110;
  if (local_f0 < (int)local_110) {
    if (local_fc != favorCompressionRatio) {
      uVar13 = local_110;
      if (0x12 < (int)local_110) {
        uVar13 = 1;
      }
      bVar8 = (byte)uVar13;
      if ((int)local_110 < 0x13) {
        bVar8 = 0;
      }
      uVar13 = local_110;
      if ((int)local_110 < 0x25) {
        uVar13 = 1;
      }
      bVar10 = (byte)uVar13;
      if (0x24 < (int)local_110) {
        bVar10 = 0;
      }
      if ((bVar10 & bVar8) != 0) {
        matchLength = 0x12;
      }
    }
    match.off = (int)local_7d8 - (int)matchPtr;
    firstMatch.len = matchLength;
  }
  else {
    firstMatch.len = match.len;
  }
  match.len = firstMatch.len;
  firstMatch.off = match.off;
  if (firstMatch.len == 0) {
    ip = ip + 1;
    goto LAB_000b0c5e;
  }
  if ((uint)firstMatch.len <= sufficient_len) {
    for (rPos = 0; rPos < 4; rPos = rPos + 1) {
      local_310 = llen + rPos;
      price = local_310;
      if (0xe < local_310) {
        price = (local_310 + -0xf) / 0xff + 1 + local_310;
      }
      cost = price;
      opt[rPos].mlen = 1;
      opt[rPos].off = 0;
      opt[rPos].litlen = rPos + llen;
      opt[rPos].price = price;
    }
    matchML = firstMatch.len;
    offset = match.off;
    for (mlen = 4; mlen <= firstMatch.len; mlen = mlen + 1) {
      local_318 = llen;
      local_31c = mlen;
      local_324 = llen;
      price_2 = llen;
      if (0xe < llen) {
        price_2 = (llen + -0xf) / 0xff + 1 + llen;
      }
      price_1 = price_2 + 3;
      if (0x12 < mlen) {
        price_1 = (mlen + -0x13) / 0xff + 1 + price_1;
      }
      cost_1 = price_1;
      opt[mlen].mlen = mlen;
      opt[mlen].off = match.off;
      opt[mlen].litlen = llen;
      opt[mlen].price = price_1;
    }
    last_match_pos = firstMatch.len;
    for (addLit = 1; addLit < 4; addLit = addLit + 1) {
      opt[addLit + firstMatch.len].mlen = 1;
      opt[addLit + firstMatch.len].off = 0;
      opt[addLit + firstMatch.len].litlen = addLit;
      local_32c = addLit;
      price_3 = addLit;
      if (0xe < addLit) {
        price_3 = (addLit + -0xf) / 0xff + 1 + addLit;
      }
      opt[addLit + firstMatch.len].price = price_3 + opt[firstMatch.len].price;
    }
    cur = 1;
LAB_000b0774:
    if ((cur < last_match_pos) && (curPtr = ip + cur, curPtr <= mflimit)) {
      if (fullUpdate == 0) {
        if (opt[cur].price < opt[cur + 1].price) goto LAB_000ad218;
      }
      else if ((opt[cur].price < opt[cur + 1].price) || (opt[cur].price + 3 <= opt[cur + 4].price))
      {
LAB_000ad218:
        if (fullUpdate == 0) {
          local_544 = last_match_pos - cur;
          local_520 = matchlimit;
          local_528 = nbSearches;
          local_52c = dict;
          local_530 = favorDecSpeed;
          match_2.off = 0;
          match_2.len = 0;
          matchPtr_10 = (BYTE *)0x0;
          local_540 = matchlimit;
          local_548 = &matchPtr_10;
          local_54c = &local_7f0;
          local_550 = nbSearches;
          local_554 = dict;
          local_558 = favorDecSpeed;
          chainTable_4 = ctx->chainTable;
          dictCtx_2 = ctx->dictCtx;
          prefixPtr_4 = ctx->prefixStart;
          prefixIdx_4 = ctx->dictLimit;
          ipIndex_2 = (U32)(curPtr + (prefixIdx_4 - (int)prefixPtr_4));
          pBVar11 = (BYTE *)(ctx->lowLimit + 0x10000);
          bVar14 = ipIndex_2 < pBVar11;
          if (bVar14) {
            pBVar11 = (BYTE *)0x1;
          }
          bVar8 = (byte)pBVar11;
          if (!bVar14) {
            bVar8 = 0;
          }
          withinStartDistance_2 = (int)bVar8;
          if (withinStartDistance_2 == 0) {
            lowestMatchIndex_2 = ipIndex_2 + -0xffff;
          }
          else {
            lowestMatchIndex_2 = ctx->lowLimit;
          }
          dictStart_2 = ctx->dictStart;
          dictIdx_2 = ctx->lowLimit;
          dictEnd_2 = dictStart_2 + (prefixIdx_4 - dictIdx_2);
          lookBackLength_2 = 0;
          nbAttempts_2 = nbSearches;
          matchChainPos_2 = 0;
          local_7f0 = curPtr;
          HashTable_2 = ctx->hashTable;
          local_53c = curPtr;
          local_538 = curPtr;
          local_534 = ctx;
          local_524 = local_544;
          local_51c = ctx;
          pattern_2 = LZ4_read32(curPtr);
          repeat_2 = rep_untested;
          srcPatternLength_2 = 0;
          local_5a0 = local_534;
          local_5a4 = local_538;
          chainTable_5 = local_534->chainTable;
          hashTable_2 = local_534->hashTable;
          prefixPtr_5 = local_534->prefixStart;
          prefixIdx_5 = local_534->dictLimit;
          target_2 = (U32)(local_538 + (prefixIdx_5 - (int)prefixPtr_5));
          for (idx_2 = local_534->nextToUpdate; idx_2 < target_2; idx_2 = idx_2 + 1) {
            h_2 = LZ4HC_hashPtr(prefixPtr_5 + (idx_2 - prefixIdx_5));
            delta_2 = idx_2 - hashTable_2[h_2];
            if (0xffff < delta_2) {
              delta_2 = 0xffff;
            }
            chainTable_5[idx_2 & 0xffff] = (U16)delta_2;
            hashTable_2[h_2] = idx_2;
          }
          local_5a0->nextToUpdate = target_2;
          UVar3 = LZ4HC_hashPtr(local_538);
          matchIndex_2 = HashTable_2[UVar3];
LAB_000afcea:
          do {
            if ((matchIndex_2 < lowestMatchIndex_2) || (nbAttempts_2 < 1)) goto LAB_000afd06;
            matchLength_5 = 0;
            nbAttempts_2 = nbAttempts_2 + -1;
            if ((local_558 == favorCompressionRatio) || (7 < ipIndex_2 - matchIndex_2)) {
              if (matchIndex_2 < prefixIdx_4) {
                matchPtr_12 = dictStart_2 + (matchIndex_2 - dictIdx_2);
                uVar12 = prefixIdx_4 - 4;
                uVar13 = uVar12;
                if (matchIndex_2 <= uVar12) {
                  uVar13 = 1;
                }
                cVar9 = (char)uVar13;
                if (uVar12 < matchIndex_2) {
                  cVar9 = '\0';
                }
                if ((cVar9 == '\0') || (UVar3 = LZ4_read32(matchPtr_12), pattern_2 != UVar3))
                goto LAB_000af6f8;
                back_14 = 0;
                vLimit_4 = local_538 + (prefixIdx_4 - matchIndex_2);
                if (local_540 < vLimit_4) {
                  vLimit_4 = local_540;
                }
                pStart_9 = local_538 + 4;
                local_618 = matchPtr_12 + 4;
                local_61c = vLimit_4;
                pBVar11 = vLimit_4 + -3;
                bVar14 = pStart_9 < pBVar11;
                if (bVar14) {
                  pBVar11 = (BYTE *)0x1;
                }
                cVar9 = (char)pBVar11;
                if (!bVar14) {
                  cVar9 = '\0';
                }
                local_614 = pStart_9;
                if (cVar9 == '\0') {
LAB_000af312:
                  while( true ) {
                    pBVar11 = local_61c + -3;
                    bVar14 = local_614 < pBVar11;
                    if (bVar14) {
                      pBVar11 = (BYTE *)0x1;
                    }
                    cVar9 = (char)pBVar11;
                    if (!bVar14) {
                      cVar9 = '\0';
                    }
                    if (cVar9 == '\0') {
                      if (local_614 < local_61c + -1) {
                        UVar1 = LZ4_read16(local_618);
                        UVar2 = LZ4_read16(local_614);
                        if (UVar1 == UVar2) {
                          local_614 = local_614 + 2;
                          local_618 = local_618 + 2;
                        }
                      }
                      if ((local_614 < local_61c) && (*local_618 == *local_614)) {
                        local_614 = local_614 + 1;
                      }
                      uVar13 = (int)local_614 - (int)pStart_9;
                      goto LAB_000af3ba;
                    }
                    rVar4 = LZ4_read_ARCH(local_618);
                    rVar5 = LZ4_read_ARCH(local_614);
                    diff_19 = rVar5 ^ rVar4;
                    if (diff_19 != 0) break;
                    local_614 = local_614 + 4;
                    local_618 = local_618 + 4;
                  }
                  uVar13 = LZ4_NbCommonBytes(diff_19);
                  local_614 = local_614 + uVar13;
                  uVar13 = (int)local_614 - (int)pStart_9;
                }
                else {
                  rVar4 = LZ4_read_ARCH(local_618);
                  rVar5 = LZ4_read_ARCH(local_614);
                  diff_18 = rVar5 ^ rVar4;
                  if (diff_18 == 0) {
                    local_614 = local_614 + 4;
                    local_618 = local_618 + 4;
                    goto LAB_000af312;
                  }
                  uVar13 = LZ4_NbCommonBytes(diff_18);
                }
LAB_000af3ba:
                matchLength_5 = uVar13 + 4;
                if ((vLimit_4 == local_538 + matchLength_5) && (vLimit_4 < local_540)) {
                  pStart_10 = local_538 + matchLength_5;
                  local_630 = prefixPtr_4;
                  local_634 = local_540;
                  pBVar11 = local_540 + -3;
                  bVar14 = pStart_10 < pBVar11;
                  if (bVar14) {
                    pBVar11 = (BYTE *)0x1;
                  }
                  cVar9 = (char)pBVar11;
                  if (!bVar14) {
                    cVar9 = '\0';
                  }
                  local_62c = pStart_10;
                  if (cVar9 == '\0') {
LAB_000af50e:
                    while( true ) {
                      pBVar11 = local_634 + -3;
                      bVar14 = local_62c < pBVar11;
                      if (bVar14) {
                        pBVar11 = (BYTE *)0x1;
                      }
                      cVar9 = (char)pBVar11;
                      if (!bVar14) {
                        cVar9 = '\0';
                      }
                      if (cVar9 == '\0') {
                        if (local_62c < local_634 + -1) {
                          UVar1 = LZ4_read16(local_630);
                          UVar2 = LZ4_read16(local_62c);
                          if (UVar1 == UVar2) {
                            local_62c = local_62c + 2;
                            local_630 = local_630 + 2;
                          }
                        }
                        if ((local_62c < local_634) && (*local_630 == *local_62c)) {
                          local_62c = local_62c + 1;
                        }
                        uVar13 = (int)local_62c - (int)pStart_10;
                        goto LAB_000af5b8;
                      }
                      rVar4 = LZ4_read_ARCH(local_630);
                      rVar5 = LZ4_read_ARCH(local_62c);
                      diff_21 = rVar5 ^ rVar4;
                      if (diff_21 != 0) break;
                      local_62c = local_62c + 4;
                      local_630 = local_630 + 4;
                    }
                    uVar13 = LZ4_NbCommonBytes(diff_21);
                    local_62c = local_62c + uVar13;
                    uVar13 = (int)local_62c - (int)pStart_10;
                  }
                  else {
                    rVar4 = LZ4_read_ARCH(prefixPtr_4);
                    rVar5 = LZ4_read_ARCH(local_62c);
                    diff_20 = rVar5 ^ rVar4;
                    if (diff_20 == 0) {
                      local_62c = local_62c + 4;
                      local_630 = local_630 + 4;
                      goto LAB_000af50e;
                    }
                    uVar13 = LZ4_NbCommonBytes(diff_20);
                  }
LAB_000af5b8:
                  matchLength_5 = uVar13 + matchLength_5;
                }
                if (lookBackLength_2 == 0) {
                  back_14 = 0;
                }
                else {
                  local_644 = local_538;
                  local_648 = matchPtr_12;
                  local_64c = local_53c;
                  local_650 = dictStart_2;
                  back_15 = 0;
                  min_7 = (int)local_53c - (int)local_538;
                  if ((int)local_53c - (int)local_538 < (int)dictStart_2 - (int)matchPtr_12) {
                    min_7 = (int)dictStart_2 - (int)matchPtr_12;
                  }
                  for (; (back_14 = back_15, min_7 < back_15 &&
                         (local_538[back_15 + -1] == matchPtr_12[back_15 + -1]));
                      back_15 = back_15 + -1) {
                  }
                }
                matchLength_5 = matchLength_5 - back_14;
                if ((int)local_544 < matchLength_5) {
                  local_544 = matchLength_5;
                  *local_548 = prefixPtr_4 + back_14 + (matchIndex_2 - prefixIdx_4);
                  *local_54c = local_538 + back_14;
                }
              }
              else {
                matchPtr_11 = prefixPtr_4 + (matchIndex_2 - prefixIdx_4);
                UVar1 = LZ4_read16(local_53c + (local_544 - 1));
                UVar2 = LZ4_read16(matchPtr_11 + (local_544 - lookBackLength_2) + -1);
                if ((UVar1 != UVar2) || (UVar3 = LZ4_read32(matchPtr_11), pattern_2 != UVar3))
                goto LAB_000af6f8;
                if (lookBackLength_2 == 0) {
                  back_12 = 0;
                }
                else {
                  local_5d4 = local_538;
                  local_5d8 = matchPtr_11;
                  local_5dc = local_53c;
                  local_5e0 = prefixPtr_4;
                  back_13 = 0;
                  min_6 = (int)local_53c - (int)local_538;
                  if ((int)local_53c - (int)local_538 < (int)prefixPtr_4 - (int)matchPtr_11) {
                    min_6 = (int)prefixPtr_4 - (int)matchPtr_11;
                  }
                  for (; (back_12 = back_13, min_6 < back_13 &&
                         (local_538[back_13 + -1] == matchPtr_11[back_13 + -1]));
                      back_13 = back_13 + -1) {
                  }
                }
                pStart_8 = local_538 + 4;
                local_5f4 = matchPtr_11 + 4;
                local_5f8 = local_540;
                pBVar11 = local_540 + -3;
                bVar14 = pStart_8 < pBVar11;
                if (bVar14) {
                  pBVar11 = (BYTE *)0x1;
                }
                cVar9 = (char)pBVar11;
                if (!bVar14) {
                  cVar9 = '\0';
                }
                local_5f0 = pStart_8;
                if (cVar9 == '\0') {
LAB_000af056:
                  while( true ) {
                    pBVar11 = local_5f8 + -3;
                    bVar14 = local_5f0 < pBVar11;
                    if (bVar14) {
                      pBVar11 = (BYTE *)0x1;
                    }
                    cVar9 = (char)pBVar11;
                    if (!bVar14) {
                      cVar9 = '\0';
                    }
                    if (cVar9 == '\0') {
                      if (local_5f0 < local_5f8 + -1) {
                        UVar1 = LZ4_read16(local_5f4);
                        UVar2 = LZ4_read16(local_5f0);
                        if (UVar1 == UVar2) {
                          local_5f0 = local_5f0 + 2;
                          local_5f4 = local_5f4 + 2;
                        }
                      }
                      if ((local_5f0 < local_5f8) && (*local_5f4 == *local_5f0)) {
                        local_5f0 = local_5f0 + 1;
                      }
                      uVar13 = (int)local_5f0 - (int)pStart_8;
                      goto LAB_000af0fe;
                    }
                    rVar4 = LZ4_read_ARCH(local_5f4);
                    rVar5 = LZ4_read_ARCH(local_5f0);
                    diff_17 = rVar5 ^ rVar4;
                    if (diff_17 != 0) break;
                    local_5f0 = local_5f0 + 4;
                    local_5f4 = local_5f4 + 4;
                  }
                  uVar13 = LZ4_NbCommonBytes(diff_17);
                  local_5f0 = local_5f0 + uVar13;
                  uVar13 = (int)local_5f0 - (int)pStart_8;
                }
                else {
                  rVar4 = LZ4_read_ARCH(local_5f4);
                  rVar5 = LZ4_read_ARCH(local_5f0);
                  diff_16 = rVar5 ^ rVar4;
                  if (diff_16 == 0) {
                    local_5f0 = local_5f0 + 4;
                    local_5f4 = local_5f4 + 4;
                    goto LAB_000af056;
                  }
                  uVar13 = LZ4_NbCommonBytes(diff_16);
                }
LAB_000af0fe:
                matchLength_5 = (uVar13 + 4) - back_12;
                if ((int)local_544 < matchLength_5) {
                  local_544 = matchLength_5;
                  *local_548 = matchPtr_11 + back_12;
                  *local_54c = local_538 + back_12;
                }
              }
            }
LAB_000af6f8:
            if ((matchLength_5 == local_544) && (matchIndex_2 + local_544 <= ipIndex_2)) {
              kTrigger_2 = 4;
              distanceToNextMatch_2 = 1;
              end_2 = local_544 - 3;
              step_2 = 1;
              accel_2 = 0x10;
              for (pos_2 = 0; pos_2 < end_2; pos_2 = step_2 + pos_2) {
                candidateDist_2 =
                     (U32)chainTable_4[(pos_2 & 0xffffU) + (matchIndex_2 & 0xffff) & 0xffff];
                step_2 = accel_2 >> 4;
                accel_2 = accel_2 + 1;
                if (distanceToNextMatch_2 < candidateDist_2) {
                  matchChainPos_2 = pos_2;
                  accel_2 = 0x10;
                  distanceToNextMatch_2 = candidateDist_2;
                }
              }
              if (1 < distanceToNextMatch_2) {
                if (matchIndex_2 < distanceToNextMatch_2) goto LAB_000afd06;
                matchIndex_2 = matchIndex_2 - distanceToNextMatch_2;
                goto LAB_000afcea;
              }
            }
            distNextMatch_2 = (U32)chainTable_4[matchIndex_2 & 0xffff];
            if ((distNextMatch_2 == 1) && (matchChainPos_2 == 0)) {
              matchCandidateIdx_2 = matchIndex_2 - 1;
              if (repeat_2 == rep_untested) {
                uVar13 = pattern_2 >> 0x10;
                bVar14 = (pattern_2 & 0xffff) == uVar13;
                if (bVar14) {
                  uVar13 = 1;
                }
                bVar8 = (byte)uVar13;
                if (!bVar14) {
                  bVar8 = 0;
                }
                if (((pattern_2 & 0xff) == pattern_2 >> 0x18 & bVar8) == 0) {
                  repeat_2 = rep_not;
                }
                else {
                  repeat_2 = rep_confirmed;
                  uVar13 = LZ4HC_countPattern(local_538 + 4,local_540,pattern_2);
                  srcPatternLength_2 = uVar13 + 4;
                }
              }
              if (((repeat_2 != rep_confirmed) || (matchCandidateIdx_2 < lowestMatchIndex_2)) ||
                 (iVar6 = LZ4HC_protectDictEnd(prefixIdx_4,matchCandidateIdx_2), iVar6 == 0))
              goto LAB_000afcba;
              UVar3 = matchCandidateIdx_2;
              if (matchCandidateIdx_2 < prefixIdx_4) {
                UVar3 = 1;
              }
              bVar8 = (byte)UVar3;
              if (prefixIdx_4 <= matchCandidateIdx_2) {
                bVar8 = 0;
              }
              extDict_2 = (int)bVar8;
              if (extDict_2 == 0) {
                iVar6 = (int)prefixPtr_4 - prefixIdx_4;
              }
              else {
                iVar6 = (int)dictStart_2 - dictIdx_2;
              }
              matchPtr_13 = (BYTE *)(iVar6 + matchCandidateIdx_2);
              UVar3 = LZ4_read32(matchPtr_13);
              if (pattern_2 != UVar3) goto LAB_000afcba;
              iLimit_2 = local_540;
              if (extDict_2 != 0) {
                iLimit_2 = dictEnd_2;
              }
              uVar13 = LZ4HC_countPattern(matchPtr_13 + 4,iLimit_2,pattern_2);
              forwardPatternLength_2 = uVar13 + 4;
              if ((extDict_2 != 0) && (iLimit_2 == matchPtr_13 + forwardPatternLength_2)) {
                rotatedPattern_4 = LZ4HC_rotatePattern(forwardPatternLength_2,pattern_2);
                uVar13 = LZ4HC_countPattern(prefixPtr_4,local_540,rotatedPattern_4);
                forwardPatternLength_2 = forwardPatternLength_2 + uVar13;
              }
              lowestMatchPtr_2 = prefixPtr_4;
              if (extDict_2 != 0) {
                lowestMatchPtr_2 = dictStart_2;
              }
              backLength_2 = LZ4HC_reverseCountPattern(matchPtr_13,lowestMatchPtr_2,pattern_2);
              if (((extDict_2 == 0) && (prefixPtr_4 == matchPtr_13 + -backLength_2)) &&
                 (dictIdx_2 < prefixIdx_4)) {
                rotatedPattern_5 = LZ4HC_rotatePattern(-backLength_2,pattern_2);
                uVar13 = LZ4HC_reverseCountPattern(dictEnd_2,dictStart_2,rotatedPattern_5);
                backLength_2 = backLength_2 + uVar13;
              }
              uVar13 = matchCandidateIdx_2 - backLength_2;
              if (matchCandidateIdx_2 - backLength_2 < lowestMatchIndex_2) {
                uVar13 = lowestMatchIndex_2;
              }
              backLength_2 = matchCandidateIdx_2 - uVar13;
              currentSegmentLength_2 = forwardPatternLength_2 + backLength_2;
              if ((currentSegmentLength_2 < srcPatternLength_2) ||
                 (srcPatternLength_2 < forwardPatternLength_2)) {
                newMatchIndex_5 = matchCandidateIdx_2 - backLength_2;
                iVar6 = LZ4HC_protectDictEnd(prefixIdx_4,newMatchIndex_5);
                if (iVar6 == 0) {
                  matchIndex_2 = prefixIdx_4;
                }
                else {
                  matchIndex_2 = newMatchIndex_5;
                  if (lookBackLength_2 == 0) {
                    maxML_2 = srcPatternLength_2;
                    if (currentSegmentLength_2 <= srcPatternLength_2) {
                      maxML_2 = currentSegmentLength_2;
                    }
                    if (local_544 < maxML_2) {
                      if ((BYTE *)0xffff <
                          local_538 + ((prefixIdx_4 - (int)prefixPtr_4) - newMatchIndex_5))
                      goto LAB_000afd06;
                      local_544 = maxML_2;
                      *local_548 = prefixPtr_4 + (newMatchIndex_5 - prefixIdx_4);
                      *local_54c = local_538;
                    }
                    distToNextPattern_2 = (U32)chainTable_4[matchIndex_2 & 0xffff];
                    if (matchIndex_2 < distToNextPattern_2) goto LAB_000afd06;
                    matchIndex_2 = matchIndex_2 - distToNextPattern_2;
                  }
                }
              }
              else {
                newMatchIndex_4 =
                     (matchCandidateIdx_2 + forwardPatternLength_2) - srcPatternLength_2;
                iVar6 = LZ4HC_protectDictEnd(prefixIdx_4,newMatchIndex_4);
                if (iVar6 == 0) {
                  matchIndex_2 = prefixIdx_4;
                }
                else {
                  matchIndex_2 = newMatchIndex_4;
                }
              }
            }
            else {
LAB_000afcba:
              matchIndex_2 = matchIndex_2 -
                             chainTable_4
                             [(matchChainPos_2 & 0xffff) + (matchIndex_2 & 0xffff) & 0xffff];
            }
          } while( true );
        }
        local_338 = matchlimit;
        local_33c = 3;
        local_340 = nbSearches;
        local_344 = dict;
        local_348 = favorDecSpeed;
        match_1.off = 0;
        match_1.len = 0;
        matchPtr_5 = (BYTE *)0x0;
        local_358 = matchlimit;
        local_35c = 3;
        local_360 = &matchPtr_5;
        local_364 = &local_808;
        local_368 = nbSearches;
        local_36c = dict;
        local_370 = favorDecSpeed;
        chainTable_2 = ctx->chainTable;
        dictCtx_1 = ctx->dictCtx;
        prefixPtr_2 = ctx->prefixStart;
        prefixIdx_2 = ctx->dictLimit;
        ipIndex_1 = (U32)(curPtr + (prefixIdx_2 - (int)prefixPtr_2));
        pBVar11 = (BYTE *)(ctx->lowLimit + 0x10000);
        bVar14 = ipIndex_1 < pBVar11;
        if (bVar14) {
          pBVar11 = (BYTE *)0x1;
        }
        bVar8 = (byte)pBVar11;
        if (!bVar14) {
          bVar8 = 0;
        }
        withinStartDistance_1 = (int)bVar8;
        if (withinStartDistance_1 == 0) {
          lowestMatchIndex_1 = ipIndex_1 + -0xffff;
        }
        else {
          lowestMatchIndex_1 = ctx->lowLimit;
        }
        dictStart_1 = ctx->dictStart;
        dictIdx_1 = ctx->lowLimit;
        dictEnd_1 = dictStart_1 + (prefixIdx_2 - dictIdx_1);
        lookBackLength_1 = 0;
        nbAttempts_1 = nbSearches;
        matchChainPos_1 = 0;
        local_808 = curPtr;
        HashTable_1 = ctx->hashTable;
        local_354 = curPtr;
        local_350 = curPtr;
        local_34c = ctx;
        local_334 = ctx;
        pattern_1 = LZ4_read32(curPtr);
        repeat_1 = rep_untested;
        srcPatternLength_1 = 0;
        local_3b8 = local_34c;
        local_3bc = local_350;
        chainTable_3 = local_34c->chainTable;
        hashTable_1 = local_34c->hashTable;
        prefixPtr_3 = local_34c->prefixStart;
        prefixIdx_3 = local_34c->dictLimit;
        target_1 = (U32)(local_350 + (prefixIdx_3 - (int)prefixPtr_3));
        for (idx_1 = local_34c->nextToUpdate; idx_1 < target_1; idx_1 = idx_1 + 1) {
          h_1 = LZ4HC_hashPtr(prefixPtr_3 + (idx_1 - prefixIdx_3));
          delta_1 = idx_1 - hashTable_1[h_1];
          if (0xffff < delta_1) {
            delta_1 = 0xffff;
          }
          chainTable_3[idx_1 & 0xffff] = (U16)delta_1;
          hashTable_1[h_1] = idx_1;
        }
        local_3b8->nextToUpdate = target_1;
        UVar3 = LZ4HC_hashPtr(local_350);
        matchIndex_1 = HashTable_1[UVar3];
LAB_000ae4de:
        do {
          if ((matchIndex_1 < lowestMatchIndex_1) || (nbAttempts_1 < 1)) goto LAB_000ae4fa;
          matchLength_3 = 0;
          nbAttempts_1 = nbAttempts_1 + -1;
          if ((local_370 == favorCompressionRatio) || (7 < ipIndex_1 - matchIndex_1)) {
            if (matchIndex_1 < prefixIdx_2) {
              matchPtr_7 = dictStart_1 + (matchIndex_1 - dictIdx_1);
              uVar12 = prefixIdx_2 - 4;
              uVar13 = uVar12;
              if (matchIndex_1 <= uVar12) {
                uVar13 = 1;
              }
              cVar9 = (char)uVar13;
              if (uVar12 < matchIndex_1) {
                cVar9 = '\0';
              }
              if ((cVar9 == '\0') || (UVar3 = LZ4_read32(matchPtr_7), pattern_1 != UVar3))
              goto LAB_000adeec;
              back_8 = 0;
              vLimit_2 = local_350 + (prefixIdx_2 - matchIndex_1);
              if (local_358 < vLimit_2) {
                vLimit_2 = local_358;
              }
              pStart_5 = local_350 + 4;
              local_430 = matchPtr_7 + 4;
              local_434 = vLimit_2;
              pBVar11 = vLimit_2 + -3;
              bVar14 = pStart_5 < pBVar11;
              if (bVar14) {
                pBVar11 = (BYTE *)0x1;
              }
              cVar9 = (char)pBVar11;
              if (!bVar14) {
                cVar9 = '\0';
              }
              local_42c = pStart_5;
              if (cVar9 == '\0') {
LAB_000adb06:
                while( true ) {
                  pBVar11 = local_434 + -3;
                  bVar14 = local_42c < pBVar11;
                  if (bVar14) {
                    pBVar11 = (BYTE *)0x1;
                  }
                  cVar9 = (char)pBVar11;
                  if (!bVar14) {
                    cVar9 = '\0';
                  }
                  if (cVar9 == '\0') {
                    if (local_42c < local_434 + -1) {
                      UVar1 = LZ4_read16(local_430);
                      UVar2 = LZ4_read16(local_42c);
                      if (UVar1 == UVar2) {
                        local_42c = local_42c + 2;
                        local_430 = local_430 + 2;
                      }
                    }
                    if ((local_42c < local_434) && (*local_430 == *local_42c)) {
                      local_42c = local_42c + 1;
                    }
                    uVar13 = (int)local_42c - (int)pStart_5;
                    goto LAB_000adbae;
                  }
                  rVar4 = LZ4_read_ARCH(local_430);
                  rVar5 = LZ4_read_ARCH(local_42c);
                  diff_11 = rVar5 ^ rVar4;
                  if (diff_11 != 0) break;
                  local_42c = local_42c + 4;
                  local_430 = local_430 + 4;
                }
                uVar13 = LZ4_NbCommonBytes(diff_11);
                local_42c = local_42c + uVar13;
                uVar13 = (int)local_42c - (int)pStart_5;
              }
              else {
                rVar4 = LZ4_read_ARCH(local_430);
                rVar5 = LZ4_read_ARCH(local_42c);
                diff_10 = rVar5 ^ rVar4;
                if (diff_10 == 0) {
                  local_42c = local_42c + 4;
                  local_430 = local_430 + 4;
                  goto LAB_000adb06;
                }
                uVar13 = LZ4_NbCommonBytes(diff_10);
              }
LAB_000adbae:
              matchLength_3 = uVar13 + 4;
              if ((vLimit_2 == local_350 + matchLength_3) && (vLimit_2 < local_358)) {
                pStart_6 = local_350 + matchLength_3;
                local_448 = prefixPtr_2;
                local_44c = local_358;
                pBVar11 = local_358 + -3;
                bVar14 = pStart_6 < pBVar11;
                if (bVar14) {
                  pBVar11 = (BYTE *)0x1;
                }
                cVar9 = (char)pBVar11;
                if (!bVar14) {
                  cVar9 = '\0';
                }
                local_444 = pStart_6;
                if (cVar9 == '\0') {
LAB_000add02:
                  while( true ) {
                    pBVar11 = local_44c + -3;
                    bVar14 = local_444 < pBVar11;
                    if (bVar14) {
                      pBVar11 = (BYTE *)0x1;
                    }
                    cVar9 = (char)pBVar11;
                    if (!bVar14) {
                      cVar9 = '\0';
                    }
                    if (cVar9 == '\0') {
                      if (local_444 < local_44c + -1) {
                        UVar1 = LZ4_read16(local_448);
                        UVar2 = LZ4_read16(local_444);
                        if (UVar1 == UVar2) {
                          local_444 = local_444 + 2;
                          local_448 = local_448 + 2;
                        }
                      }
                      if ((local_444 < local_44c) && (*local_448 == *local_444)) {
                        local_444 = local_444 + 1;
                      }
                      uVar13 = (int)local_444 - (int)pStart_6;
                      goto LAB_000addac;
                    }
                    rVar4 = LZ4_read_ARCH(local_448);
                    rVar5 = LZ4_read_ARCH(local_444);
                    diff_13 = rVar5 ^ rVar4;
                    if (diff_13 != 0) break;
                    local_444 = local_444 + 4;
                    local_448 = local_448 + 4;
                  }
                  uVar13 = LZ4_NbCommonBytes(diff_13);
                  local_444 = local_444 + uVar13;
                  uVar13 = (int)local_444 - (int)pStart_6;
                }
                else {
                  rVar4 = LZ4_read_ARCH(prefixPtr_2);
                  rVar5 = LZ4_read_ARCH(local_444);
                  diff_12 = rVar5 ^ rVar4;
                  if (diff_12 == 0) {
                    local_444 = local_444 + 4;
                    local_448 = local_448 + 4;
                    goto LAB_000add02;
                  }
                  uVar13 = LZ4_NbCommonBytes(diff_12);
                }
LAB_000addac:
                matchLength_3 = uVar13 + matchLength_3;
              }
              if (lookBackLength_1 == 0) {
                back_8 = 0;
              }
              else {
                local_45c = local_350;
                local_460 = matchPtr_7;
                local_464 = local_354;
                local_468 = dictStart_1;
                back_9 = 0;
                min_4 = (int)local_354 - (int)local_350;
                if ((int)local_354 - (int)local_350 < (int)dictStart_1 - (int)matchPtr_7) {
                  min_4 = (int)dictStart_1 - (int)matchPtr_7;
                }
                for (; (back_8 = back_9, min_4 < back_9 &&
                       (local_350[back_9 + -1] == matchPtr_7[back_9 + -1])); back_9 = back_9 + -1) {
                }
              }
              matchLength_3 = matchLength_3 - back_8;
              if ((int)local_35c < matchLength_3) {
                local_35c = matchLength_3;
                *local_360 = prefixPtr_2 + back_8 + (matchIndex_1 - prefixIdx_2);
                *local_364 = local_350 + back_8;
              }
            }
            else {
              matchPtr_6 = prefixPtr_2 + (matchIndex_1 - prefixIdx_2);
              UVar1 = LZ4_read16(local_354 + (local_35c - 1));
              UVar2 = LZ4_read16(matchPtr_6 + (local_35c - lookBackLength_1) + -1);
              if ((UVar1 != UVar2) || (UVar3 = LZ4_read32(matchPtr_6), pattern_1 != UVar3))
              goto LAB_000adeec;
              if (lookBackLength_1 == 0) {
                back_6 = 0;
              }
              else {
                local_3ec = local_350;
                local_3f0 = matchPtr_6;
                local_3f4 = local_354;
                local_3f8 = prefixPtr_2;
                back_7 = 0;
                min_3 = (int)local_354 - (int)local_350;
                if ((int)local_354 - (int)local_350 < (int)prefixPtr_2 - (int)matchPtr_6) {
                  min_3 = (int)prefixPtr_2 - (int)matchPtr_6;
                }
                for (; (back_6 = back_7, min_3 < back_7 &&
                       (local_350[back_7 + -1] == matchPtr_6[back_7 + -1])); back_7 = back_7 + -1) {
                }
              }
              pStart_4 = local_350 + 4;
              local_40c = matchPtr_6 + 4;
              local_410 = local_358;
              pBVar11 = local_358 + -3;
              bVar14 = pStart_4 < pBVar11;
              if (bVar14) {
                pBVar11 = (BYTE *)0x1;
              }
              cVar9 = (char)pBVar11;
              if (!bVar14) {
                cVar9 = '\0';
              }
              local_408 = pStart_4;
              if (cVar9 == '\0') {
LAB_000ad84a:
                while( true ) {
                  pBVar11 = local_410 + -3;
                  bVar14 = local_408 < pBVar11;
                  if (bVar14) {
                    pBVar11 = (BYTE *)0x1;
                  }
                  cVar9 = (char)pBVar11;
                  if (!bVar14) {
                    cVar9 = '\0';
                  }
                  if (cVar9 == '\0') {
                    if (local_408 < local_410 + -1) {
                      UVar1 = LZ4_read16(local_40c);
                      UVar2 = LZ4_read16(local_408);
                      if (UVar1 == UVar2) {
                        local_408 = local_408 + 2;
                        local_40c = local_40c + 2;
                      }
                    }
                    if ((local_408 < local_410) && (*local_40c == *local_408)) {
                      local_408 = local_408 + 1;
                    }
                    uVar13 = (int)local_408 - (int)pStart_4;
                    goto LAB_000ad8f2;
                  }
                  rVar4 = LZ4_read_ARCH(local_40c);
                  rVar5 = LZ4_read_ARCH(local_408);
                  diff_9 = rVar5 ^ rVar4;
                  if (diff_9 != 0) break;
                  local_408 = local_408 + 4;
                  local_40c = local_40c + 4;
                }
                uVar13 = LZ4_NbCommonBytes(diff_9);
                local_408 = local_408 + uVar13;
                uVar13 = (int)local_408 - (int)pStart_4;
              }
              else {
                rVar4 = LZ4_read_ARCH(local_40c);
                rVar5 = LZ4_read_ARCH(local_408);
                diff_8 = rVar5 ^ rVar4;
                if (diff_8 == 0) {
                  local_408 = local_408 + 4;
                  local_40c = local_40c + 4;
                  goto LAB_000ad84a;
                }
                uVar13 = LZ4_NbCommonBytes(diff_8);
              }
LAB_000ad8f2:
              matchLength_3 = (uVar13 + 4) - back_6;
              if ((int)local_35c < matchLength_3) {
                local_35c = matchLength_3;
                *local_360 = matchPtr_6 + back_6;
                *local_364 = local_350 + back_6;
              }
            }
          }
LAB_000adeec:
          if ((matchLength_3 == local_35c) && (matchIndex_1 + local_35c <= ipIndex_1)) {
            kTrigger_1 = 4;
            distanceToNextMatch_1 = 1;
            end_1 = local_35c - 3;
            step_1 = 1;
            accel_1 = 0x10;
            for (pos_1 = 0; pos_1 < end_1; pos_1 = step_1 + pos_1) {
              candidateDist_1 =
                   (U32)chainTable_2[(pos_1 & 0xffffU) + (matchIndex_1 & 0xffff) & 0xffff];
              step_1 = accel_1 >> 4;
              accel_1 = accel_1 + 1;
              if (distanceToNextMatch_1 < candidateDist_1) {
                matchChainPos_1 = pos_1;
                accel_1 = 0x10;
                distanceToNextMatch_1 = candidateDist_1;
              }
            }
            if (1 < distanceToNextMatch_1) {
              if (matchIndex_1 < distanceToNextMatch_1) goto LAB_000ae4fa;
              matchIndex_1 = matchIndex_1 - distanceToNextMatch_1;
              goto LAB_000ae4de;
            }
          }
          distNextMatch_1 = (U32)chainTable_2[matchIndex_1 & 0xffff];
          if ((distNextMatch_1 == 1) && (matchChainPos_1 == 0)) {
            matchCandidateIdx_1 = matchIndex_1 - 1;
            if (repeat_1 == rep_untested) {
              uVar13 = pattern_1 >> 0x10;
              bVar14 = (pattern_1 & 0xffff) == uVar13;
              if (bVar14) {
                uVar13 = 1;
              }
              bVar8 = (byte)uVar13;
              if (!bVar14) {
                bVar8 = 0;
              }
              if (((pattern_1 & 0xff) == pattern_1 >> 0x18 & bVar8) == 0) {
                repeat_1 = rep_not;
              }
              else {
                repeat_1 = rep_confirmed;
                uVar13 = LZ4HC_countPattern(local_350 + 4,local_358,pattern_1);
                srcPatternLength_1 = uVar13 + 4;
              }
            }
            if (((repeat_1 != rep_confirmed) || (matchCandidateIdx_1 < lowestMatchIndex_1)) ||
               (iVar6 = LZ4HC_protectDictEnd(prefixIdx_2,matchCandidateIdx_1), iVar6 == 0))
            goto LAB_000ae4ae;
            UVar3 = matchCandidateIdx_1;
            if (matchCandidateIdx_1 < prefixIdx_2) {
              UVar3 = 1;
            }
            bVar8 = (byte)UVar3;
            if (prefixIdx_2 <= matchCandidateIdx_1) {
              bVar8 = 0;
            }
            extDict_1 = (int)bVar8;
            if (extDict_1 == 0) {
              iVar6 = (int)prefixPtr_2 - prefixIdx_2;
            }
            else {
              iVar6 = (int)dictStart_1 - dictIdx_1;
            }
            matchPtr_8 = (BYTE *)(iVar6 + matchCandidateIdx_1);
            UVar3 = LZ4_read32(matchPtr_8);
            if (pattern_1 != UVar3) goto LAB_000ae4ae;
            iLimit_1 = local_358;
            if (extDict_1 != 0) {
              iLimit_1 = dictEnd_1;
            }
            uVar13 = LZ4HC_countPattern(matchPtr_8 + 4,iLimit_1,pattern_1);
            forwardPatternLength_1 = uVar13 + 4;
            if ((extDict_1 != 0) && (iLimit_1 == matchPtr_8 + forwardPatternLength_1)) {
              rotatedPattern_2 = LZ4HC_rotatePattern(forwardPatternLength_1,pattern_1);
              uVar13 = LZ4HC_countPattern(prefixPtr_2,local_358,rotatedPattern_2);
              forwardPatternLength_1 = forwardPatternLength_1 + uVar13;
            }
            lowestMatchPtr_1 = prefixPtr_2;
            if (extDict_1 != 0) {
              lowestMatchPtr_1 = dictStart_1;
            }
            backLength_1 = LZ4HC_reverseCountPattern(matchPtr_8,lowestMatchPtr_1,pattern_1);
            if (((extDict_1 == 0) && (prefixPtr_2 == matchPtr_8 + -backLength_1)) &&
               (dictIdx_1 < prefixIdx_2)) {
              rotatedPattern_3 = LZ4HC_rotatePattern(-backLength_1,pattern_1);
              uVar13 = LZ4HC_reverseCountPattern(dictEnd_1,dictStart_1,rotatedPattern_3);
              backLength_1 = backLength_1 + uVar13;
            }
            uVar13 = matchCandidateIdx_1 - backLength_1;
            if (matchCandidateIdx_1 - backLength_1 < lowestMatchIndex_1) {
              uVar13 = lowestMatchIndex_1;
            }
            backLength_1 = matchCandidateIdx_1 - uVar13;
            currentSegmentLength_1 = forwardPatternLength_1 + backLength_1;
            if ((currentSegmentLength_1 < srcPatternLength_1) ||
               (srcPatternLength_1 < forwardPatternLength_1)) {
              newMatchIndex_3 = matchCandidateIdx_1 - backLength_1;
              iVar6 = LZ4HC_protectDictEnd(prefixIdx_2,newMatchIndex_3);
              if (iVar6 == 0) {
                matchIndex_1 = prefixIdx_2;
              }
              else {
                matchIndex_1 = newMatchIndex_3;
                if (lookBackLength_1 == 0) {
                  maxML_1 = srcPatternLength_1;
                  if (currentSegmentLength_1 <= srcPatternLength_1) {
                    maxML_1 = currentSegmentLength_1;
                  }
                  if (local_35c < maxML_1) {
                    if ((BYTE *)0xffff <
                        local_350 + ((prefixIdx_2 - (int)prefixPtr_2) - newMatchIndex_3))
                    goto LAB_000ae4fa;
                    local_35c = maxML_1;
                    *local_360 = prefixPtr_2 + (newMatchIndex_3 - prefixIdx_2);
                    *local_364 = local_350;
                  }
                  distToNextPattern_1 = (U32)chainTable_2[matchIndex_1 & 0xffff];
                  if (matchIndex_1 < distToNextPattern_1) goto LAB_000ae4fa;
                  matchIndex_1 = matchIndex_1 - distToNextPattern_1;
                }
              }
            }
            else {
              newMatchIndex_2 = (matchCandidateIdx_1 + forwardPatternLength_1) - srcPatternLength_1;
              iVar6 = LZ4HC_protectDictEnd(prefixIdx_2,newMatchIndex_2);
              if (iVar6 == 0) {
                matchIndex_1 = prefixIdx_2;
              }
              else {
                matchIndex_1 = newMatchIndex_2;
              }
            }
          }
          else {
LAB_000ae4ae:
            matchIndex_1 = matchIndex_1 -
                           chainTable_2
                           [(matchChainPos_1 & 0xffff) + (matchIndex_1 & 0xffff) & 0xffff];
          }
        } while( true );
      }
      goto LAB_000b076a;
    }
    best_mlen = opt[last_match_pos].mlen;
    best_off = opt[last_match_pos].off;
    cur = last_match_pos - best_mlen;
LAB_000b07b4:
    candidate_pos = cur;
    selected_matchLength = best_mlen;
    selected_offset = best_off;
    while( true ) {
      next_matchLength = opt[candidate_pos].mlen;
      next_offset = opt[candidate_pos].off;
      opt[candidate_pos].mlen = selected_matchLength;
      opt[candidate_pos].off = selected_offset;
      selected_offset = next_offset;
      selected_matchLength = next_matchLength;
      if (candidate_pos < next_matchLength) break;
      candidate_pos = candidate_pos - next_matchLength;
    }
    rPos_1 = 0;
    while (rPos_1 < last_match_pos) {
      ml_1 = opt[rPos_1].mlen;
      offset_2 = opt[rPos_1].off;
      if (ml_1 == 1) {
        ip = ip + 1;
        rPos_1 = rPos_1 + 1;
      }
      else {
        rPos_1 = ml_1 + rPos_1;
        opSaved = op;
        local_754 = (int)ip - offset_2;
        local_744 = &ip;
        local_748 = &op;
        local_74c = &anchor;
        local_758 = limit;
        local_75c = oend;
        token_1 = op;
        pBVar11 = op + 1;
        length_1 = (int)ip - (int)anchor;
        local_750 = ml_1;
        if ((limit == notLimited) || (pBVar11 + length_1 + length_1 / 0xff + 8 <= oend)) {
          if (length_1 < 0xf) {
            *op = (BYTE)((length_1 & 0xff) << 4);
            op = pBVar11;
          }
          else {
            *op = 0xf0;
            op = pBVar11;
            for (len_1 = length_1 - 0xf; 0xfe < len_1; len_1 = len_1 - 0xff) {
              pBVar11 = *local_748;
              *local_748 = pBVar11 + 1;
              *pBVar11 = 0xff;
            }
            pBVar11 = *local_748;
            *local_748 = pBVar11 + 1;
            *pBVar11 = (BYTE)len_1;
          }
          local_76c = *local_748;
          local_770 = *local_74c;
          e_1 = *local_748 + length_1;
          s_1 = local_770;
          d_1 = local_76c;
          do {
            uVar7 = *(undefined4 *)(s_1 + 4);
            *(undefined4 *)d_1 = *(undefined4 *)s_1;
            *(undefined4 *)(d_1 + 4) = uVar7;
            d_1 = d_1 + 8;
            s_1 = s_1 + 8;
          } while (d_1 < e_1);
          local_774 = e_1;
          *local_748 = *local_748 + length_1;
          LZ4_writeLE16(*local_748,(short)*local_744 - (short)local_754);
          *local_748 = *local_748 + 2;
          length_1 = local_750 - 4;
          if ((local_758 == notLimited) || (*local_748 + length_1 / 0xff + 6 <= local_75c)) {
            if (length_1 < 0xf) {
              *token_1 = (char)length_1 + *token_1;
            }
            else {
              *token_1 = *token_1 + '\x0f';
              for (length_1 = local_750 - 0x13; 0x1fd < length_1; length_1 = length_1 - 0x1fe) {
                pBVar11 = *local_748;
                *local_748 = pBVar11 + 1;
                *pBVar11 = 0xff;
                pBVar11 = *local_748;
                *local_748 = pBVar11 + 1;
                *pBVar11 = 0xff;
              }
              if (0xfe < length_1) {
                length_1 = length_1 - 0xff;
                pBVar11 = *local_748;
                *local_748 = pBVar11 + 1;
                *pBVar11 = 0xff;
              }
              pBVar11 = *local_748;
              *local_748 = pBVar11 + 1;
              *pBVar11 = (BYTE)length_1;
            }
            *local_744 = *local_744 + local_750;
            *local_74c = *local_744;
            bVar14 = false;
          }
          else {
            bVar14 = true;
          }
        }
        else {
          bVar14 = true;
          op = pBVar11;
        }
        if (bVar14) {
          ovml = ml_1;
          ovref = ip + -offset_2;
          goto LAB_000b0c52;
        }
      }
    }
    goto LAB_000b0c5e;
  }
  firstML = firstMatch.len;
  local_2e0 = ip + -match.off;
  opSaved = op;
  local_2d0 = &ip;
  local_2d4 = &op;
  local_2d8 = &anchor;
  local_2dc = firstMatch.len;
  local_2e4 = limit;
  local_2e8 = oend;
  token = op;
  pBVar11 = op + 1;
  length = (int)ip - (int)anchor;
  matchPos = local_2e0;
  if ((limit == notLimited) || (pBVar11 + length + length / 0xff + 8 <= oend)) {
    if (length < 0xf) {
      *op = (BYTE)((length & 0xff) << 4);
      op = pBVar11;
    }
    else {
      *op = 0xf0;
      op = pBVar11;
      for (len = length - 0xf; 0xfe < len; len = len - 0xff) {
        pBVar11 = *local_2d4;
        *local_2d4 = pBVar11 + 1;
        *pBVar11 = 0xff;
      }
      pBVar11 = *local_2d4;
      *local_2d4 = pBVar11 + 1;
      *pBVar11 = (BYTE)len;
    }
    local_2f8 = *local_2d4;
    local_2fc = *local_2d8;
    e = *local_2d4 + length;
    s = local_2fc;
    d = local_2f8;
    do {
      uVar7 = *(undefined4 *)(s + 4);
      *(undefined4 *)d = *(undefined4 *)s;
      *(undefined4 *)(d + 4) = uVar7;
      d = d + 8;
      s = s + 8;
    } while (d < e);
    local_300 = e;
    *local_2d4 = *local_2d4 + length;
    LZ4_writeLE16(*local_2d4,(short)*local_2d0 - (short)local_2e0);
    *local_2d4 = *local_2d4 + 2;
    length = local_2dc - 4;
    if ((local_2e4 == notLimited) || (*local_2d4 + length / 0xff + 6 <= local_2e8)) {
      if (length < 0xf) {
        *token = (char)length + *token;
      }
      else {
        *token = *token + '\x0f';
        for (length = local_2dc - 0x13; 0x1fd < length; length = length - 0x1fe) {
          pBVar11 = *local_2d4;
          *local_2d4 = pBVar11 + 1;
          *pBVar11 = 0xff;
          pBVar11 = *local_2d4;
          *local_2d4 = pBVar11 + 1;
          *pBVar11 = 0xff;
        }
        if (0xfe < length) {
          length = length - 0xff;
          pBVar11 = *local_2d4;
          *local_2d4 = pBVar11 + 1;
          *pBVar11 = 0xff;
        }
        pBVar11 = *local_2d4;
        *local_2d4 = pBVar11 + 1;
        *pBVar11 = (BYTE)length;
      }
      *local_2d0 = *local_2d0 + local_2dc;
      *local_2d8 = *local_2d0;
      bVar14 = false;
    }
    else {
      bVar14 = true;
    }
  }
  else {
    bVar14 = true;
    op = pBVar11;
  }
  if (bVar14) goto code_r0x000ace88;
  goto LAB_000b0c5e;
LAB_000afd06:
  if (((local_554 == usingDictCtxHc) && (0 < nbAttempts_2)) &&
     (ipIndex_2 - lowestMatchIndex_2 < 0xffff)) {
    dictEndOffset_2 =
         (size_t)(dictCtx_2->end + (dictCtx_2->dictLimit - (int)dictCtx_2->prefixStart));
    UVar3 = LZ4HC_hashPtr(local_538);
    dictMatchIndex_2 = dictCtx_2->hashTable[UVar3];
    matchIndex_2 = (lowestMatchIndex_2 + dictMatchIndex_2) - dictEndOffset_2;
    while ((ipIndex_2 - matchIndex_2 < 0x10000 &&
           (iVar6 = nbAttempts_2 + -1, bVar14 = nbAttempts_2 != 0, nbAttempts_2 = iVar6, bVar14))) {
      matchPtr_14 = dictCtx_2->prefixStart + (dictMatchIndex_2 - dictCtx_2->dictLimit);
      UVar3 = LZ4_read32(matchPtr_14);
      if (pattern_2 == UVar3) {
        back_16 = 0;
        vLimit_5 = local_538 + (dictEndOffset_2 - dictMatchIndex_2);
        if (local_540 < vLimit_5) {
          vLimit_5 = local_540;
        }
        pStart_11 = local_538 + 4;
        local_6cc = matchPtr_14 + 4;
        local_6d0 = vLimit_5;
        pBVar11 = vLimit_5 + -3;
        bVar14 = pStart_11 < pBVar11;
        if (bVar14) {
          pBVar11 = (BYTE *)0x1;
        }
        cVar9 = (char)pBVar11;
        if (!bVar14) {
          cVar9 = '\0';
        }
        local_6c8 = pStart_11;
        if (cVar9 == '\0') {
LAB_000aff3e:
          while( true ) {
            pBVar11 = local_6d0 + -3;
            bVar14 = local_6c8 < pBVar11;
            if (bVar14) {
              pBVar11 = (BYTE *)0x1;
            }
            cVar9 = (char)pBVar11;
            if (!bVar14) {
              cVar9 = '\0';
            }
            if (cVar9 == '\0') {
              if (local_6c8 < local_6d0 + -1) {
                UVar1 = LZ4_read16(local_6cc);
                UVar2 = LZ4_read16(local_6c8);
                if (UVar1 == UVar2) {
                  local_6c8 = local_6c8 + 2;
                  local_6cc = local_6cc + 2;
                }
              }
              if ((local_6c8 < local_6d0) && (*local_6cc == *local_6c8)) {
                local_6c8 = local_6c8 + 1;
              }
              uVar13 = (int)local_6c8 - (int)pStart_11;
              goto LAB_000affe6;
            }
            rVar4 = LZ4_read_ARCH(local_6cc);
            rVar5 = LZ4_read_ARCH(local_6c8);
            diff_23 = rVar5 ^ rVar4;
            if (diff_23 != 0) break;
            local_6c8 = local_6c8 + 4;
            local_6cc = local_6cc + 4;
          }
          uVar13 = LZ4_NbCommonBytes(diff_23);
          local_6c8 = local_6c8 + uVar13;
          uVar13 = (int)local_6c8 - (int)pStart_11;
        }
        else {
          rVar4 = LZ4_read_ARCH(local_6cc);
          rVar5 = LZ4_read_ARCH(local_6c8);
          diff_22 = rVar5 ^ rVar4;
          if (diff_22 == 0) {
            local_6c8 = local_6c8 + 4;
            local_6cc = local_6cc + 4;
            goto LAB_000aff3e;
          }
          uVar13 = LZ4_NbCommonBytes(diff_22);
        }
LAB_000affe6:
        if (lookBackLength_2 == 0) {
          back_16 = 0;
        }
        else {
          local_6f0 = dictCtx_2->prefixStart;
          local_6e4 = local_538;
          local_6e8 = matchPtr_14;
          local_6ec = local_53c;
          back_17 = 0;
          min_8 = (int)local_53c - (int)local_538;
          if ((int)local_53c - (int)local_538 < (int)local_6f0 - (int)matchPtr_14) {
            min_8 = (int)local_6f0 - (int)matchPtr_14;
          }
          for (; (back_16 = back_17, min_8 < back_17 &&
                 (local_538[back_17 + -1] == matchPtr_14[back_17 + -1])); back_17 = back_17 + -1) {
          }
        }
        mlt_2 = (uVar13 + 4) - back_16;
        if ((int)local_544 < mlt_2) {
          local_544 = mlt_2;
          *local_548 = prefixPtr_4 + back_16 + (matchIndex_2 - prefixIdx_4);
          *local_54c = local_538 + back_16;
        }
      }
      nextOffset_2 = (U32)dictCtx_2->chainTable[dictMatchIndex_2 & 0xffff];
      dictMatchIndex_2 = dictMatchIndex_2 - nextOffset_2;
      matchIndex_2 = matchIndex_2 - nextOffset_2;
    }
  }
  matchLength_4 = local_544;
  if ((int)local_524 < (int)local_544) {
    if (local_530 != favorCompressionRatio) {
      uVar13 = local_544;
      if (0x12 < (int)local_544) {
        uVar13 = 1;
      }
      bVar8 = (byte)uVar13;
      if ((int)local_544 < 0x13) {
        bVar8 = 0;
      }
      uVar13 = local_544;
      if ((int)local_544 < 0x25) {
        uVar13 = 1;
      }
      bVar10 = (byte)uVar13;
      if (0x24 < (int)local_544) {
        bVar10 = 0;
      }
      if ((bVar10 & bVar8) != 0) {
        matchLength_4 = 0x12;
      }
    }
    match_2.off = (int)local_7f0 - (int)matchPtr_10;
    iStack_7f4 = matchLength_4;
  }
  else {
    iStack_7f4 = match_2.len;
  }
  newMatch.off = match_2.off;
  newMatch.len = iStack_7f4;
  match_2.len = iStack_7f4;
  goto LAB_000b023c;
LAB_000ae4fa:
  if (((local_36c == usingDictCtxHc) && (0 < nbAttempts_1)) &&
     (ipIndex_1 - lowestMatchIndex_1 < 0xffff)) {
    dictEndOffset_1 =
         (size_t)(dictCtx_1->end + (dictCtx_1->dictLimit - (int)dictCtx_1->prefixStart));
    UVar3 = LZ4HC_hashPtr(local_350);
    dictMatchIndex_1 = dictCtx_1->hashTable[UVar3];
    matchIndex_1 = (lowestMatchIndex_1 + dictMatchIndex_1) - dictEndOffset_1;
    while ((ipIndex_1 - matchIndex_1 < 0x10000 &&
           (iVar6 = nbAttempts_1 + -1, bVar14 = nbAttempts_1 != 0, nbAttempts_1 = iVar6, bVar14))) {
      matchPtr_9 = dictCtx_1->prefixStart + (dictMatchIndex_1 - dictCtx_1->dictLimit);
      UVar3 = LZ4_read32(matchPtr_9);
      if (pattern_1 == UVar3) {
        back_10 = 0;
        vLimit_3 = local_350 + (dictEndOffset_1 - dictMatchIndex_1);
        if (local_358 < vLimit_3) {
          vLimit_3 = local_358;
        }
        pStart_7 = local_350 + 4;
        local_4e4 = matchPtr_9 + 4;
        local_4e8 = vLimit_3;
        pBVar11 = vLimit_3 + -3;
        bVar14 = pStart_7 < pBVar11;
        if (bVar14) {
          pBVar11 = (BYTE *)0x1;
        }
        cVar9 = (char)pBVar11;
        if (!bVar14) {
          cVar9 = '\0';
        }
        local_4e0 = pStart_7;
        if (cVar9 == '\0') {
LAB_000ae732:
          while( true ) {
            pBVar11 = local_4e8 + -3;
            bVar14 = local_4e0 < pBVar11;
            if (bVar14) {
              pBVar11 = (BYTE *)0x1;
            }
            cVar9 = (char)pBVar11;
            if (!bVar14) {
              cVar9 = '\0';
            }
            if (cVar9 == '\0') {
              if (local_4e0 < local_4e8 + -1) {
                UVar1 = LZ4_read16(local_4e4);
                UVar2 = LZ4_read16(local_4e0);
                if (UVar1 == UVar2) {
                  local_4e0 = local_4e0 + 2;
                  local_4e4 = local_4e4 + 2;
                }
              }
              if ((local_4e0 < local_4e8) && (*local_4e4 == *local_4e0)) {
                local_4e0 = local_4e0 + 1;
              }
              uVar13 = (int)local_4e0 - (int)pStart_7;
              goto LAB_000ae7da;
            }
            rVar4 = LZ4_read_ARCH(local_4e4);
            rVar5 = LZ4_read_ARCH(local_4e0);
            diff_15 = rVar5 ^ rVar4;
            if (diff_15 != 0) break;
            local_4e0 = local_4e0 + 4;
            local_4e4 = local_4e4 + 4;
          }
          uVar13 = LZ4_NbCommonBytes(diff_15);
          local_4e0 = local_4e0 + uVar13;
          uVar13 = (int)local_4e0 - (int)pStart_7;
        }
        else {
          rVar4 = LZ4_read_ARCH(local_4e4);
          rVar5 = LZ4_read_ARCH(local_4e0);
          diff_14 = rVar5 ^ rVar4;
          if (diff_14 == 0) {
            local_4e0 = local_4e0 + 4;
            local_4e4 = local_4e4 + 4;
            goto LAB_000ae732;
          }
          uVar13 = LZ4_NbCommonBytes(diff_14);
        }
LAB_000ae7da:
        if (lookBackLength_1 == 0) {
          back_10 = 0;
        }
        else {
          local_508 = dictCtx_1->prefixStart;
          local_4fc = local_350;
          local_500 = matchPtr_9;
          local_504 = local_354;
          back_11 = 0;
          min_5 = (int)local_354 - (int)local_350;
          if ((int)local_354 - (int)local_350 < (int)local_508 - (int)matchPtr_9) {
            min_5 = (int)local_508 - (int)matchPtr_9;
          }
          for (; (back_10 = back_11, min_5 < back_11 &&
                 (local_350[back_11 + -1] == matchPtr_9[back_11 + -1])); back_11 = back_11 + -1) {
          }
        }
        mlt_1 = (uVar13 + 4) - back_10;
        if ((int)local_35c < mlt_1) {
          local_35c = mlt_1;
          *local_360 = prefixPtr_2 + back_10 + (matchIndex_1 - prefixIdx_2);
          *local_364 = local_350 + back_10;
        }
      }
      nextOffset_1 = (U32)dictCtx_1->chainTable[dictMatchIndex_1 & 0xffff];
      dictMatchIndex_1 = dictMatchIndex_1 - nextOffset_1;
      matchIndex_1 = matchIndex_1 - nextOffset_1;
    }
  }
  matchLength_2 = local_35c;
  if (local_33c < (int)local_35c) {
    if (local_348 != favorCompressionRatio) {
      uVar13 = local_35c;
      if (0x12 < (int)local_35c) {
        uVar13 = 1;
      }
      bVar8 = (byte)uVar13;
      if ((int)local_35c < 0x13) {
        bVar8 = 0;
      }
      uVar13 = local_35c;
      if ((int)local_35c < 0x25) {
        uVar13 = 1;
      }
      bVar10 = (byte)uVar13;
      if (0x24 < (int)local_35c) {
        bVar10 = 0;
      }
      if ((bVar10 & bVar8) != 0) {
        matchLength_2 = 0x12;
      }
    }
    match_1.len = matchLength_2;
    match_1.off = (int)local_808 - (int)matchPtr_5;
    newMatch.len = matchLength_2;
    newMatch.off = match_1.off;
  }
  else {
    newMatch.off = match_1.off;
    newMatch.len = match_1.len;
  }
LAB_000b023c:
  if (newMatch.len != 0) {
    if ((sufficient_len < (uint)newMatch.len) || (0xfff < cur + newMatch.len)) {
      best_mlen = newMatch.len;
      best_off = newMatch.off;
      last_match_pos = cur + 1;
      goto LAB_000b07b4;
    }
    baseLitlen = opt[cur].litlen;
    for (litlen = 1; litlen < 4; litlen = litlen + 1) {
      price_5 = baseLitlen;
      if (0xe < baseLitlen) {
        price_5 = (baseLitlen + -0xf) / 0xff + 1 + baseLitlen;
      }
      local_70c = baseLitlen + litlen;
      price_6 = local_70c;
      if (0xe < local_70c) {
        price_6 = (local_70c + -0xf) / 0xff + 1 + local_70c;
      }
      price_4 = price_6 + (opt[cur].price - price_5);
      pos_3 = litlen + cur;
      if (price_4 < opt[pos_3].price) {
        opt[pos_3].mlen = 1;
        opt[pos_3].off = 0;
        opt[pos_3].litlen = litlen + baseLitlen;
        opt[pos_3].price = price_4;
      }
      local_704 = baseLitlen;
    }
    matchML_1 = newMatch.len;
    for (ml = 4; ml <= newMatch.len; ml = ml + 1) {
      pos_4 = ml + cur;
      offset_1 = newMatch.off;
      if (opt[cur].mlen == 1) {
        local_720 = opt[cur].litlen;
        if (local_720 < cur) {
          iVar6 = opt[cur - local_720].price;
        }
        else {
          iVar6 = 0;
        }
        local_718 = ml;
        price_9 = local_720;
        if (0xe < local_720) {
          price_9 = (local_720 + -0xf) / 0xff + 1 + local_720;
        }
        price_8 = price_9 + 3;
        if (0x12 < ml) {
          price_8 = (ml + -0x13) / 0xff + 1 + price_8;
        }
        price_7 = price_8 + iVar6;
        local_714 = local_720;
        ll = local_720;
      }
      else {
        ll = 0;
        local_728 = 0;
        local_72c = ml;
        local_734 = 0;
        price_11 = 0;
        price_10 = 3;
        if (0x12 < ml) {
          price_10 = (ml + -0x13) / 0xff + 4;
        }
        price_7 = price_10 + opt[cur].price;
      }
      if ((last_match_pos + 3 < pos_4) || (price_7 <= (int)(opt[pos_4].price - favorDecSpeed))) {
        if ((ml == newMatch.len) && (last_match_pos < pos_4)) {
          last_match_pos = pos_4;
        }
        opt[pos_4].mlen = ml;
        opt[pos_4].off = newMatch.off;
        opt[pos_4].litlen = ll;
        opt[pos_4].price = price_7;
      }
    }
    for (addLit_1 = 1; addLit_1 < 4; addLit_1 = addLit_1 + 1) {
      opt[addLit_1 + last_match_pos].mlen = 1;
      opt[addLit_1 + last_match_pos].off = 0;
      opt[addLit_1 + last_match_pos].litlen = addLit_1;
      local_73c = addLit_1;
      price_12 = addLit_1;
      if (0xe < addLit_1) {
        price_12 = (addLit_1 + -0xf) / 0xff + 1 + addLit_1;
      }
      opt[addLit_1 + last_match_pos].price = price_12 + opt[last_match_pos].price;
    }
  }
LAB_000b076a:
  cur = cur + 1;
  goto LAB_000b0774;
code_r0x000ace88:
  ovml = firstML;
  ovref = matchPos;
LAB_000b0c52:
  if (limit == fillOutput) {
    ll_1 = (int)ip - (int)anchor;
    ll_addbytes = (ll_1 + 0xf0) / 0xff;
    ll_totalCost = ll_1 + ll_addbytes + 1;
    maxLitPos = oend + -3;
    op = opSaved;
    if (opSaved + ll_totalCost <= maxLitPos) {
      bytesLeftForMl = (int)maxLitPos - (int)(opSaved + ll_totalCost);
      maxMlSize = bytesLeftForMl * 0xff + 0x12;
      if (maxMlSize < (uint)ovml) {
        ovml = maxMlSize;
      }
      if (0xb < (int)(oend + ovml + (-ll_totalCost - (int)opSaved) + 2)) {
        local_784 = &ip;
        local_788 = &op;
        local_78c = &anchor;
        local_790 = ovml;
        local_794 = ovref;
        local_798 = 0;
        local_79c = oend;
        token_2 = opSaved;
        op = opSaved + 1;
        length_2 = (int)ip - (int)anchor;
        if (length_2 < 0xf) {
          *opSaved = (BYTE)((length_2 & 0xff) << 4);
        }
        else {
          *opSaved = 0xf0;
          for (len_2 = length_2 - 0xf; 0xfe < len_2; len_2 = len_2 - 0xff) {
            pBVar11 = *local_788;
            *local_788 = pBVar11 + 1;
            *pBVar11 = 0xff;
          }
          pBVar11 = *local_788;
          *local_788 = pBVar11 + 1;
          *pBVar11 = (BYTE)len_2;
        }
        local_7ac = *local_788;
        local_7b0 = *local_78c;
        e_2 = *local_788 + length_2;
        s_2 = local_7b0;
        d_2 = local_7ac;
        do {
          uVar7 = *(undefined4 *)(s_2 + 4);
          *(undefined4 *)d_2 = *(undefined4 *)s_2;
          *(undefined4 *)(d_2 + 4) = uVar7;
          d_2 = d_2 + 8;
          s_2 = s_2 + 8;
        } while (d_2 < e_2);
        local_7b4 = e_2;
        *local_788 = *local_788 + length_2;
        LZ4_writeLE16(*local_788,(short)*local_784 - (short)local_794);
        *local_788 = *local_788 + 2;
        length_2 = local_790 - 4;
        if ((local_798 == 0) || (*local_788 + length_2 / 0xff + 6 <= local_79c)) {
          if (length_2 < 0xf) {
            *token_2 = (char)length_2 + *token_2;
          }
          else {
            *token_2 = *token_2 + '\x0f';
            for (length_2 = local_790 - 0x13; 0x1fd < length_2; length_2 = length_2 - 0x1fe) {
              pBVar11 = *local_788;
              *local_788 = pBVar11 + 1;
              *pBVar11 = 0xff;
              pBVar11 = *local_788;
              *local_788 = pBVar11 + 1;
              *pBVar11 = 0xff;
            }
            if (0xfe < length_2) {
              length_2 = length_2 - 0xff;
              pBVar11 = *local_788;
              *local_788 = pBVar11 + 1;
              *pBVar11 = 0xff;
            }
            pBVar11 = *local_788;
            *local_788 = pBVar11 + 1;
            *pBVar11 = (BYTE)length_2;
          }
          *local_784 = *local_784 + local_790;
          *local_78c = *local_784;
        }
      }
    }
LAB_000b0c72:
    lastRunSize = (int)iend - (int)anchor;
    llAdd = (lastRunSize + 0xf0) / 0xff;
    totalSize = lastRunSize + llAdd + 1;
    if (limit == fillOutput) {
      oend = oend + 5;
    }
    if ((limit != notLimited) && (oend < op + totalSize)) {
      if (limit == limitedOutput) {
        retval = 0;
        goto LAB_000b122c;
      }
      llAdd = (uint)(oend + (0xf0 - (int)op)) >> 8;
      lastRunSize = (size_t)(oend + ((-1 - (int)op) - llAdd));
    }
    ip = anchor + lastRunSize;
    if (lastRunSize < 0xf) {
      *op = (BYTE)((lastRunSize & 0xff) << 4);
      op = op + 1;
    }
    else {
      accumulator = lastRunSize - 0xf;
      *op = 0xf0;
      pBVar11 = op;
      for (; op = pBVar11 + 1, 0xfe < accumulator; accumulator = accumulator - 0xff) {
        *op = 0xff;
        pBVar11 = op;
      }
      *op = (BYTE)accumulator;
      op = pBVar11 + 2;
    }
    memcpy(op,anchor,lastRunSize);
    op = op + lastRunSize;
    *srcSizePtr = (int)ip - (int)source;
    retval = (int)op - (int)dst;
  }
  goto LAB_000b122c;
}

