
size_t LZ4F_decodeHeader(LZ4F_dctx *dctx,void *src,size_t srcSize)

{
  byte bVar1;
  byte bVar2;
  BYTE BVar3;
  LZ4F_errorCode_t LVar4;
  U32 UVar5;
  size_t sVar6;
  int iVar7;
  int iVar8;
  LZ4F_blockSizeID_t blockSizeID_00;
  undefined4 uVar9;
  U64 UVar10;
  size_t srcSize_local;
  void *src_local;
  LZ4F_dctx *dctx_local;
  BYTE HC;
  uint blockSizeID;
  U32 BD;
  size_t frameHeaderSize;
  uint dictIDFlag;
  uint contentChecksumFlag;
  uint contentSizeFlag;
  uint blockMode;
  uint blockChecksumFlag;
  U32 version;
  U32 FLG;
  BYTE *srcPtr;
  
  if (srcSize < 7) {
    LVar4 = LZ4F_returnErrorCode(LZ4F_ERROR_frameHeader_incomplete);
  }
  else {
    memset(&dctx->frameInfo,0,0x20);
    UVar5 = LZ4F_readLE32(src);
    if ((UVar5 & 0xfffffff0) == 0x184d2a50) {
      (dctx->frameInfo).frameType = LZ4F_skippableFrame;
      if (dctx->header == (BYTE *)src) {
        dctx->tmpInSize = srcSize;
        dctx->tmpInTarget = 8;
        dctx->dStage = dstage_storeSFrameSize;
        LVar4 = srcSize;
      }
      else {
        dctx->dStage = dstage_getSFrameSize;
        LVar4 = 4;
      }
    }
    else {
      UVar5 = LZ4F_readLE32(src);
      if (UVar5 == 0x184d2204) {
        (dctx->frameInfo).frameType = LZ4F_frame;
        bVar1 = *(byte *)((int)src + 4);
        if ((bVar1 >> 1 & 1) == 0) {
          if (bVar1 >> 6 == 1) {
            if ((bVar1 >> 3 & 1) == 0) {
              iVar7 = 0;
            }
            else {
              iVar7 = 8;
            }
            if ((bVar1 & 1) == 0) {
              iVar8 = 0;
            }
            else {
              iVar8 = 4;
            }
            LVar4 = iVar8 + iVar7 + 7;
            if (srcSize < LVar4) {
              if (dctx->header != (BYTE *)src) {
                memcpy(dctx->header,src,srcSize);
              }
              dctx->tmpInSize = srcSize;
              dctx->tmpInTarget = LVar4;
              dctx->dStage = dstage_storeFrameHeader;
              LVar4 = srcSize;
            }
            else {
              bVar2 = *(byte *)((int)src + 5);
              blockSizeID_00 = bVar2 >> 4 & LZ4F_max4MB;
              if ((char)bVar2 < '\0') {
                LVar4 = LZ4F_returnErrorCode(LZ4F_ERROR_reservedFlag_set);
              }
              else if (blockSizeID_00 < LZ4F_max64KB) {
                LVar4 = LZ4F_returnErrorCode(LZ4F_ERROR_maxBlockSize_invalid);
              }
              else if ((bVar2 & 0xf) == 0) {
                BVar3 = LZ4F_headerChecksum((void *)((int)src + 4),LVar4 - 5);
                if (BVar3 == *(BYTE *)((LVar4 - 1) + (int)src)) {
                  (dctx->frameInfo).blockMode = bVar1 >> 5 & LZ4F_blockIndependent;
                  (dctx->frameInfo).blockChecksumFlag = bVar1 >> 4 & LZ4F_blockChecksumEnabled;
                  (dctx->frameInfo).contentChecksumFlag = bVar1 >> 2 & LZ4F_contentChecksumEnabled;
                  (dctx->frameInfo).blockSizeID = blockSizeID_00;
                  sVar6 = LZ4F_getBlockSize(blockSizeID_00);
                  dctx->maxBlockSize = sVar6;
                  if ((bVar1 >> 3 & 1) != 0) {
                    UVar10 = LZ4F_readLE64((void *)((int)src + 6));
                    (dctx->frameInfo).contentSize = UVar10;
                    uVar9 = *(undefined4 *)((int)&(dctx->frameInfo).contentSize + 4);
                    *(int *)&dctx->frameRemainingSize = (int)(dctx->frameInfo).contentSize;
                    *(undefined4 *)((int)&dctx->frameRemainingSize + 4) = uVar9;
                  }
                  if ((bVar1 & 1) != 0) {
                    UVar5 = LZ4F_readLE32((void *)((LVar4 - 5) + (int)src));
                    (dctx->frameInfo).dictID = UVar5;
                  }
                  dctx->dStage = dstage_init;
                }
                else {
                  LVar4 = LZ4F_returnErrorCode(LZ4F_ERROR_headerChecksum_invalid);
                }
              }
              else {
                LVar4 = LZ4F_returnErrorCode(LZ4F_ERROR_reservedFlag_set);
              }
            }
          }
          else {
            LVar4 = LZ4F_returnErrorCode(LZ4F_ERROR_headerVersion_wrong);
          }
        }
        else {
          LVar4 = LZ4F_returnErrorCode(LZ4F_ERROR_reservedFlag_set);
        }
      }
      else {
        LVar4 = LZ4F_returnErrorCode(LZ4F_ERROR_frameType_unknown);
      }
    }
  }
  return LVar4;
}

