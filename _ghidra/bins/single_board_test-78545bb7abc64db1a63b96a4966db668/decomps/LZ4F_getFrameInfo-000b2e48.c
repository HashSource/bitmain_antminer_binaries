
LZ4F_errorCode_t
LZ4F_getFrameInfo(LZ4F_dctx *dctx,LZ4F_frameInfo_t *frameInfoPtr,void *srcBuffer,size_t *srcSizePtr)

{
  LZ4F_blockMode_t LVar1;
  undefined4 uVar2;
  LZ4F_contentChecksum_t LVar3;
  uint uVar4;
  LZ4F_frameType_t LVar5;
  LZ4F_blockChecksum_t LVar6;
  size_t *srcSizePtr_local;
  void *srcBuffer_local;
  LZ4F_frameInfo_t *frameInfoPtr_local;
  LZ4F_dctx *dctx_local;
  size_t i;
  size_t o;
  size_t hSize;
  size_t decodeResult;
  
  if (dctx->dStage < dstage_init) {
    if (dctx->dStage == dstage_storeFrameHeader) {
      *srcSizePtr = 0;
      hSize = LZ4F_returnErrorCode(LZ4F_ERROR_frameDecoding_alreadyStarted);
    }
    else {
      hSize = LZ4F_headerSize(srcBuffer,*srcSizePtr);
      uVar4 = LZ4F_isError(hSize);
      if (uVar4 == 0) {
        if (*srcSizePtr < hSize) {
          *srcSizePtr = 0;
          hSize = LZ4F_returnErrorCode(LZ4F_ERROR_frameHeader_incomplete);
        }
        else {
          decodeResult = LZ4F_decodeHeader(dctx,srcBuffer,hSize);
          uVar4 = LZ4F_isError(decodeResult);
          if (uVar4 == 0) {
            *srcSizePtr = decodeResult;
            decodeResult = 4;
          }
          else {
            *srcSizePtr = 0;
          }
          LVar1 = (dctx->frameInfo).blockMode;
          LVar3 = (dctx->frameInfo).contentChecksumFlag;
          LVar5 = (dctx->frameInfo).frameType;
          frameInfoPtr->blockSizeID = (dctx->frameInfo).blockSizeID;
          frameInfoPtr->blockMode = LVar1;
          frameInfoPtr->contentChecksumFlag = LVar3;
          frameInfoPtr->frameType = LVar5;
          uVar2 = *(undefined4 *)((int)&(dctx->frameInfo).contentSize + 4);
          uVar4 = (dctx->frameInfo).dictID;
          LVar6 = (dctx->frameInfo).blockChecksumFlag;
          *(int *)&frameInfoPtr->contentSize = (int)(dctx->frameInfo).contentSize;
          *(undefined4 *)((int)&frameInfoPtr->contentSize + 4) = uVar2;
          frameInfoPtr->dictID = uVar4;
          frameInfoPtr->blockChecksumFlag = LVar6;
          hSize = decodeResult;
        }
      }
      else {
        *srcSizePtr = 0;
      }
    }
  }
  else {
    o = 0;
    i = 0;
    *srcSizePtr = 0;
    LVar1 = (dctx->frameInfo).blockMode;
    LVar3 = (dctx->frameInfo).contentChecksumFlag;
    LVar5 = (dctx->frameInfo).frameType;
    frameInfoPtr->blockSizeID = (dctx->frameInfo).blockSizeID;
    frameInfoPtr->blockMode = LVar1;
    frameInfoPtr->contentChecksumFlag = LVar3;
    frameInfoPtr->frameType = LVar5;
    uVar2 = *(undefined4 *)((int)&(dctx->frameInfo).contentSize + 4);
    uVar4 = (dctx->frameInfo).dictID;
    LVar6 = (dctx->frameInfo).blockChecksumFlag;
    *(int *)&frameInfoPtr->contentSize = (int)(dctx->frameInfo).contentSize;
    *(undefined4 *)((int)&frameInfoPtr->contentSize + 4) = uVar2;
    frameInfoPtr->dictID = uVar4;
    frameInfoPtr->blockChecksumFlag = LVar6;
    hSize = LZ4F_decompress(dctx,(void *)0x0,&o,(void *)0x0,&i,(LZ4F_decompressOptions_t *)0x0);
  }
  return hSize;
}

