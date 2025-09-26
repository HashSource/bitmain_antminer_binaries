
size_t LZ4F_decompress(LZ4F_dctx *dctx,void *dstBuffer,size_t *dstSizePtr,void *srcBuffer,
                      size_t *srcSizePtr,LZ4F_decompressOptions_t *decompressOptionsPtr)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  bool bVar9;
  BYTE *pBVar10;
  size_t sVar11;
  LZ4F_errorCode_t LVar12;
  U32 UVar13;
  LZ4F_AllocFunction p_Var30;
  LZ4F_AllocFunction p_Var31;
  LZ4F_AllocFunction p_Var32;
  LZ4F_AllocFunction p_Var33;
  uint uVar14;
  byte bVar15;
  uint uVar16;
  LZ4F_CallocFunction p_Var34;
  LZ4F_CallocFunction p_Var35;
  LZ4F_CallocFunction p_Var36;
  LZ4F_CallocFunction p_Var37;
  BYTE *pBVar17;
  BYTE *pBVar18;
  LZ4F_FreeFunction p_Var19;
  LZ4F_FreeFunction p_Var20;
  LZ4F_FreeFunction p_Var21;
  LZ4F_FreeFunction p_Var22;
  int iVar23;
  size_t __n;
  bool bVar24;
  LZ4F_CustomMem LVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  undefined8 uVar38;
  undefined8 uVar39;
  undefined8 uVar40;
  undefined8 uVar41;
  void *srcBuffer_local;
  size_t *dstSizePtr_local;
  void *dstBuffer_local;
  LZ4F_dctx *dctx_local;
  LZ4F_decompressOptions_t optionsNull;
  size_t newDictSize;
  BYTE *oldDictEnd_1;
  BYTE *oldDictEnd;
  size_t preserveSize;
  size_t hSize;
  size_t skipSize;
  size_t SFrameSize;
  size_t sizeToCopy_7;
  U32 resultCRC;
  U32 readCRC_1;
  size_t sizeToCopy_6;
  size_t wantedData_2;
  size_t remainingInput_1;
  size_t sizeToCopy_5;
  int decodedSize_1;
  size_t reservedDictSpace;
  int decodedSize;
  U32 calcBlockCrc;
  U32 readBlockCrc;
  size_t sizeToCopy_4;
  size_t inputLeft;
  size_t wantedData_1;
  U32 calcCRC;
  U32 readCRC;
  size_t sizeToCopy_3;
  size_t stillToCopy;
  size_t minBuffSize;
  size_t crcSize;
  size_t nextCBlockSize;
  U32 blockHeader;
  size_t sizeToCopy_1;
  size_t wantedData;
  size_t remainingInput;
  size_t bufferNeeded;
  size_t sizeToCopy;
  BYTE *dstEnd;
  BYTE *dstStart;
  BYTE *srcEnd;
  BYTE *srcStart;
  size_t copySize;
  size_t dictSize_1;
  char *dict_1;
  size_t dictSize;
  char *dict;
  void *crcSrc;
  size_t sizeToCopy_2;
  size_t nextSrcSizeHint;
  uint doAnotherStage;
  BYTE *selectedIn;
  BYTE *dstPtr;
  BYTE *srcPtr;
  
  pBVar17 = (BYTE *)(*srcSizePtr + (int)srcBuffer);
  if (dstBuffer == (void *)0x0) {
    pBVar18 = (BYTE *)0x0;
  }
  else {
    pBVar18 = (BYTE *)(*dstSizePtr + (int)dstBuffer);
  }
  selectedIn = (BYTE *)0x0;
  bVar9 = true;
  nextSrcSizeHint = 1;
  memset(&optionsNull,0,0x10);
  if (decompressOptionsPtr == (LZ4F_decompressOptions_t *)0x0) {
    decompressOptionsPtr = &optionsNull;
  }
  *srcSizePtr = 0;
  *dstSizePtr = 0;
  uVar16 = decompressOptionsPtr->skipChecksums;
  bVar24 = uVar16 != 0;
  if (bVar24) {
    uVar16 = 1;
  }
  bVar15 = (byte)uVar16;
  if (!bVar24) {
    bVar15 = 0;
  }
  dctx->skipChecksum = (uint)bVar15 | dctx->skipChecksum;
  dstPtr = (BYTE *)dstBuffer;
  srcPtr = (BYTE *)srcBuffer;
  do {
    if (!bVar9) {
      if (((((dctx->frameInfo).blockMode == LZ4F_blockLinked) && (dctx->dict != dctx->tmpOutBuffer))
          && (dctx->dict != (BYTE *)0x0)) &&
         ((decompressOptionsPtr->stableDst == 0 && (dctx->dStage - dstage_init < 8)))) {
        if (dctx->dStage == dstage_flushOut) {
          uVar16 = (int)dctx->tmpOut - (int)dctx->tmpOutBuffer;
          copySize = 0x10000 - dctx->tmpOutSize;
          if (0x10000 < dctx->tmpOutSize) {
            copySize = 0;
          }
          if (uVar16 < copySize) {
            copySize = uVar16;
          }
          memcpy(dctx->tmpOutBuffer + (uVar16 - copySize),
                 dctx->dict + ((dctx->dictSize - dctx->tmpOutStart) - copySize),copySize);
          dctx->dict = dctx->tmpOutBuffer;
          dctx->dictSize = dctx->tmpOutStart + uVar16;
        }
        else {
          __n = dctx->dictSize;
          if (0xffff < __n) {
            __n = 0x10000;
          }
          memcpy(dctx->tmpOutBuffer,dctx->dict + (dctx->dictSize - __n),__n);
          dctx->dict = dctx->tmpOutBuffer;
          dctx->dictSize = __n;
          dctx->tmpOut = dctx->tmpOutBuffer + __n;
        }
      }
      *srcSizePtr = (int)srcPtr - (int)srcBuffer;
      *dstSizePtr = (int)dstPtr - (int)dstBuffer;
      return nextSrcSizeHint;
    }
    switch(dctx->dStage) {
    case dstage_getFrameHeader:
      if (0x12 < (uint)((int)pBVar17 - (int)srcPtr)) {
        sVar11 = LZ4F_decodeHeader(dctx,srcPtr,(int)pBVar17 - (int)srcPtr);
        uVar16 = LZ4F_isError(sVar11);
        if (uVar16 != 0) {
          return sVar11;
        }
        srcPtr = srcPtr + sVar11;
        break;
      }
      dctx->tmpInSize = 0;
      if (pBVar17 == srcPtr) {
        return 7;
      }
      dctx->tmpInTarget = 7;
      dctx->dStage = dstage_storeFrameHeader;
    case dstage_storeFrameHeader:
      uVar16 = dctx->tmpInTarget - dctx->tmpInSize;
      if ((uint)((int)pBVar17 - (int)srcPtr) <= uVar16) {
        uVar16 = (int)pBVar17 - (int)srcPtr;
      }
      memcpy(dctx->header + dctx->tmpInSize,srcPtr,uVar16);
      dctx->tmpInSize = dctx->tmpInSize + uVar16;
      srcPtr = srcPtr + uVar16;
      if (dctx->tmpInSize < dctx->tmpInTarget) {
        nextSrcSizeHint = (dctx->tmpInTarget - dctx->tmpInSize) + 4;
        bVar9 = false;
      }
      else {
        sVar11 = LZ4F_decodeHeader(dctx,dctx->header,dctx->tmpInTarget);
        uVar16 = LZ4F_isError(sVar11);
        if (uVar16 != 0) {
          sVar11 = LZ4F_decodeHeader(dctx,dctx->header,dctx->tmpInTarget);
          return sVar11;
        }
      }
      break;
    case dstage_init:
      if ((dctx->frameInfo).contentChecksumFlag != LZ4F_noContentChecksum) {
        XXH32_reset(&dctx->xxh,0);
      }
      if ((dctx->frameInfo).blockMode == LZ4F_blockLinked) {
        iVar23 = 0x20000;
      }
      else {
        iVar23 = 0;
      }
      uVar16 = iVar23 + dctx->maxBlockSize;
      if (dctx->maxBufferSize < uVar16) {
        dctx->maxBufferSize = 0;
        uVar1 = (dctx->cmem).customAlloc;
        uVar2 = (dctx->cmem).customCalloc;
        register0x00000028 = (LZ4F_CallocFunction)uVar2;
        p_Var30 = (LZ4F_AllocFunction)uVar1;
        p_Var19 = (dctx->cmem).customFree;
        uVar26 = CONCAT44(srcSizePtr,p_Var19);
        LVar25 = (LZ4F_CustomMem)CONCAT88(uVar26,uVar38);
        LZ4F_free(dctx->tmpIn,LVar25);
        uVar3 = (dctx->cmem).customAlloc;
        uVar4 = (dctx->cmem).customCalloc;
        register0x00000028 = (LZ4F_CallocFunction)uVar4;
        p_Var31 = (LZ4F_AllocFunction)uVar3;
        p_Var20 = (dctx->cmem).customFree;
        uVar27 = CONCAT44(srcSizePtr,p_Var20);
        LVar25 = (LZ4F_CustomMem)CONCAT88(uVar27,uVar39);
        pBVar10 = (BYTE *)LZ4F_malloc(dctx->maxBlockSize + 4,LVar25);
        dctx->tmpIn = pBVar10;
        if (dctx->tmpIn == (BYTE *)0x0) {
          LVar12 = LZ4F_returnErrorCode(LZ4F_ERROR_allocation_failed);
          return LVar12;
        }
        uVar5 = (dctx->cmem).customAlloc;
        uVar6 = (dctx->cmem).customCalloc;
        register0x00000028 = (LZ4F_CallocFunction)uVar6;
        p_Var32 = (LZ4F_AllocFunction)uVar5;
        p_Var21 = (dctx->cmem).customFree;
        uVar28 = CONCAT44(srcSizePtr,p_Var21);
        LVar25 = (LZ4F_CustomMem)CONCAT88(uVar28,uVar40);
        LZ4F_free(dctx->tmpOutBuffer,LVar25);
        uVar7 = (dctx->cmem).customAlloc;
        uVar8 = (dctx->cmem).customCalloc;
        register0x00000028 = (LZ4F_CallocFunction)uVar8;
        p_Var33 = (LZ4F_AllocFunction)uVar7;
        p_Var22 = (dctx->cmem).customFree;
        uVar29 = CONCAT44(srcSizePtr,p_Var22);
        LVar25 = (LZ4F_CustomMem)CONCAT88(uVar29,uVar41);
        pBVar10 = (BYTE *)LZ4F_malloc(uVar16,LVar25);
        dctx->tmpOutBuffer = pBVar10;
        if (dctx->tmpOutBuffer == (BYTE *)0x0) {
          LVar12 = LZ4F_returnErrorCode(LZ4F_ERROR_allocation_failed);
          return LVar12;
        }
        dctx->maxBufferSize = uVar16;
      }
      dctx->tmpInSize = 0;
      dctx->tmpInTarget = 0;
      dctx->tmpOut = dctx->tmpOutBuffer;
      dctx->tmpOutStart = 0;
      dctx->tmpOutSize = 0;
      dctx->dStage = dstage_getBlockHeader;
    case dstage_getBlockHeader:
      if ((uint)((int)pBVar17 - (int)srcPtr) < 4) {
        dctx->tmpInSize = 0;
        dctx->dStage = dstage_storeBlockHeader;
      }
      else {
        selectedIn = srcPtr;
        srcPtr = srcPtr + 4;
      }
      if (dctx->dStage == dstage_storeBlockHeader) {
switchD_000e709c_caseD_4:
        uVar16 = 4 - dctx->tmpInSize;
        if ((uint)((int)pBVar17 - (int)srcPtr) <= uVar16) {
          uVar16 = (int)pBVar17 - (int)srcPtr;
        }
        memcpy(dctx->tmpIn + dctx->tmpInSize,srcPtr,uVar16);
        srcPtr = srcPtr + uVar16;
        dctx->tmpInSize = dctx->tmpInSize + uVar16;
        if (dctx->tmpInSize < 4) {
          nextSrcSizeHint = 4 - dctx->tmpInSize;
          bVar9 = false;
          break;
        }
        selectedIn = dctx->tmpIn;
      }
      UVar13 = LZ4F_readLE32(selectedIn);
      uVar16 = UVar13 & 0x7fffffff;
      iVar23 = (dctx->frameInfo).blockChecksumFlag * 4;
      if (UVar13 == 0) {
        dctx->dStage = dstage_getSuffix;
      }
      else {
        if (dctx->maxBlockSize < uVar16) {
          LVar12 = LZ4F_returnErrorCode(LZ4F_ERROR_maxBlockSize_invalid);
          return LVar12;
        }
        if ((int)UVar13 < 0) {
          dctx->tmpInTarget = uVar16;
          if ((dctx->frameInfo).blockChecksumFlag != LZ4F_noBlockChecksum) {
            XXH32_reset(&dctx->blockChecksum,0);
          }
          dctx->dStage = dstage_copyDirect;
        }
        else {
          dctx->tmpInTarget = uVar16 + iVar23;
          dctx->dStage = dstage_getCBlock;
          if ((dstPtr == pBVar18) || (srcPtr == pBVar17)) {
            nextSrcSizeHint = iVar23 + uVar16 + 4;
            bVar9 = false;
          }
        }
      }
      break;
    case dstage_storeBlockHeader:
      goto switchD_000e709c_caseD_4;
    case dstage_copyDirect:
      if (dstPtr == (BYTE *)0x0) {
        sizeToCopy_2 = 0;
      }
      else {
        sizeToCopy_2 = (int)pBVar17 - (int)srcPtr;
        if ((uint)((int)pBVar18 - (int)dstPtr) <= (uint)((int)pBVar17 - (int)srcPtr)) {
          sizeToCopy_2 = (int)pBVar18 - (int)dstPtr;
        }
        if (dctx->tmpInTarget <= sizeToCopy_2) {
          sizeToCopy_2 = dctx->tmpInTarget;
        }
        memcpy(dstPtr,srcPtr,sizeToCopy_2);
        if (dctx->skipChecksum == 0) {
          if ((dctx->frameInfo).blockChecksumFlag != LZ4F_noBlockChecksum) {
            XXH32_update(&dctx->blockChecksum,srcPtr,sizeToCopy_2);
          }
          if ((dctx->frameInfo).contentChecksumFlag != LZ4F_noContentChecksum) {
            XXH32_update(&dctx->xxh,srcPtr,sizeToCopy_2);
          }
        }
        if ((int)(dctx->frameInfo).contentSize != 0 ||
            *(int *)((int)&(dctx->frameInfo).contentSize + 4) != 0) {
          uVar16 = (uint)dctx->frameRemainingSize;
          iVar23 = *(int *)((int)&dctx->frameRemainingSize + 4);
          *(uint *)&dctx->frameRemainingSize = uVar16 - sizeToCopy_2;
          *(uint *)((int)&dctx->frameRemainingSize + 4) = iVar23 - (uint)(uVar16 < sizeToCopy_2);
        }
        if ((dctx->frameInfo).blockMode == LZ4F_blockLinked) {
          LZ4F_updateDict(dctx,dstPtr,sizeToCopy_2,(BYTE *)dstBuffer,0);
        }
      }
      srcPtr = srcPtr + sizeToCopy_2;
      dstPtr = dstPtr + sizeToCopy_2;
      if (dctx->tmpInTarget == sizeToCopy_2) {
        if ((dctx->frameInfo).blockChecksumFlag == LZ4F_noBlockChecksum) {
          dctx->dStage = dstage_getBlockHeader;
        }
        else {
          dctx->tmpInSize = 0;
          dctx->dStage = dstage_getBlockChecksum;
        }
      }
      else {
        dctx->tmpInTarget = dctx->tmpInTarget - sizeToCopy_2;
        if ((dctx->frameInfo).blockChecksumFlag == LZ4F_noBlockChecksum) {
          iVar23 = 0;
        }
        else {
          iVar23 = 4;
        }
        nextSrcSizeHint = iVar23 + dctx->tmpInTarget + 4;
        bVar9 = false;
      }
      break;
    case dstage_getBlockChecksum:
      if (((int)pBVar17 - (int)srcPtr < 4) || (dctx->tmpInSize != 0)) {
        uVar16 = 4 - dctx->tmpInSize;
        if ((uint)((int)pBVar17 - (int)srcPtr) <= uVar16) {
          uVar16 = (int)pBVar17 - (int)srcPtr;
        }
        memcpy(dctx->header + dctx->tmpInSize,srcPtr,uVar16);
        dctx->tmpInSize = dctx->tmpInSize + uVar16;
        srcPtr = srcPtr + uVar16;
        if (dctx->tmpInSize < 4) {
          bVar9 = false;
          break;
        }
        crcSrc = dctx->header;
      }
      else {
        crcSrc = srcPtr;
        srcPtr = srcPtr + 4;
      }
      if (dctx->skipChecksum == 0) {
        UVar13 = LZ4F_readLE32(crcSrc);
        uVar16 = XXH32_digest(&dctx->blockChecksum);
        if (UVar13 != uVar16) {
          LVar12 = LZ4F_returnErrorCode(LZ4F_ERROR_blockChecksum_invalid);
          return LVar12;
        }
      }
      dctx->dStage = dstage_getBlockHeader;
      break;
    case dstage_getCBlock:
      if (dctx->tmpInTarget <= (uint)((int)pBVar17 - (int)srcPtr)) {
        selectedIn = srcPtr;
        srcPtr = srcPtr + dctx->tmpInTarget;
        goto LAB_000e7766;
      }
      dctx->tmpInSize = 0;
      dctx->dStage = dstage_storeCBlock;
      break;
    case dstage_storeCBlock:
      uVar16 = dctx->tmpInTarget - dctx->tmpInSize;
      if ((uint)((int)pBVar17 - (int)srcPtr) <= uVar16) {
        uVar16 = (int)pBVar17 - (int)srcPtr;
      }
      memcpy(dctx->tmpIn + dctx->tmpInSize,srcPtr,uVar16);
      dctx->tmpInSize = dctx->tmpInSize + uVar16;
      srcPtr = srcPtr + uVar16;
      if (dctx->tmpInSize < dctx->tmpInTarget) {
        if ((dctx->frameInfo).blockChecksumFlag == LZ4F_noBlockChecksum) {
          iVar23 = 0;
        }
        else {
          iVar23 = 4;
        }
        nextSrcSizeHint = iVar23 + (dctx->tmpInTarget - dctx->tmpInSize) + 4;
        bVar9 = false;
      }
      else {
        selectedIn = dctx->tmpIn;
LAB_000e7766:
        if ((dctx->frameInfo).blockChecksumFlag != LZ4F_noBlockChecksum) {
          dctx->tmpInTarget = dctx->tmpInTarget - 4;
          UVar13 = LZ4F_readLE32(selectedIn + dctx->tmpInTarget);
          uVar16 = XXH32(selectedIn,dctx->tmpInTarget,0);
          if (UVar13 != uVar16) {
            LVar12 = LZ4F_returnErrorCode(LZ4F_ERROR_blockChecksum_invalid);
            return LVar12;
          }
        }
        if (((uint)((int)pBVar18 - (int)dstPtr) < dctx->maxBlockSize) ||
           ((dctx->dict != (BYTE *)0x0 && (dctx->dict + dctx->dictSize == dctx->tmpOut)))) {
          if ((dctx->frameInfo).blockMode == LZ4F_blockLinked) {
            if (dctx->dict == dctx->tmpOutBuffer) {
              if (0x20000 < dctx->dictSize) {
                memcpy(dctx->tmpOutBuffer,dctx->dict + (dctx->dictSize - 0x10000),0x10000);
                dctx->dictSize = 0x10000;
              }
              dctx->tmpOut = dctx->tmpOutBuffer + dctx->dictSize;
            }
            else {
              uVar16 = dctx->dictSize;
              if (0xffff < uVar16) {
                uVar16 = 0x10000;
              }
              dctx->tmpOut = dctx->tmpOutBuffer + uVar16;
            }
          }
          dict_1 = (char *)dctx->dict;
          dictSize_1 = dctx->dictSize;
          if (((BYTE *)dict_1 != (BYTE *)0x0) && (0x40000000 < dictSize_1)) {
            dict_1 = (char *)((BYTE *)dict_1 + (dictSize_1 - 0x10000));
            dictSize_1 = 0x10000;
          }
          sVar11 = LZ4_decompress_safe_usingDict
                             ((char *)selectedIn,(char *)dctx->tmpOut,dctx->tmpInTarget,
                              dctx->maxBlockSize,dict_1,dictSize_1);
          if ((int)sVar11 < 0) {
            LVar12 = LZ4F_returnErrorCode(LZ4F_ERROR_decompressionFailed);
            return LVar12;
          }
          if (((dctx->frameInfo).contentChecksumFlag != LZ4F_noContentChecksum) &&
             (dctx->skipChecksum == 0)) {
            XXH32_update(&dctx->xxh,dctx->tmpOut,sVar11);
          }
          if ((int)(dctx->frameInfo).contentSize != 0 ||
              *(int *)((int)&(dctx->frameInfo).contentSize + 4) != 0) {
            uVar16 = (uint)dctx->frameRemainingSize;
            iVar23 = *(int *)((int)&dctx->frameRemainingSize + 4);
            *(uint *)&dctx->frameRemainingSize = uVar16 - sVar11;
            *(uint *)((int)&dctx->frameRemainingSize + 4) = iVar23 - (uint)(uVar16 < sVar11);
          }
          dctx->tmpOutSize = sVar11;
          dctx->tmpOutStart = 0;
          dctx->dStage = dstage_flushOut;
switchD_000e709c_caseD_9:
          if (dstPtr != (BYTE *)0x0) {
            uVar16 = dctx->tmpOutSize - dctx->tmpOutStart;
            if ((uint)((int)pBVar18 - (int)dstPtr) <= uVar16) {
              uVar16 = (int)pBVar18 - (int)dstPtr;
            }
            memcpy(dstPtr,dctx->tmpOut + dctx->tmpOutStart,uVar16);
            if ((dctx->frameInfo).blockMode == LZ4F_blockLinked) {
              LZ4F_updateDict(dctx,dstPtr,uVar16,(BYTE *)dstBuffer,1);
            }
            dctx->tmpOutStart = dctx->tmpOutStart + uVar16;
            dstPtr = dstPtr + uVar16;
          }
          if (dctx->tmpOutStart == dctx->tmpOutSize) {
            dctx->dStage = dstage_getBlockHeader;
          }
          else {
            bVar9 = false;
            nextSrcSizeHint = 4;
          }
        }
        else {
          dict = (char *)dctx->dict;
          dictSize = dctx->dictSize;
          if (((BYTE *)dict != (BYTE *)0x0) && (0x40000000 < dictSize)) {
            dict = (char *)((BYTE *)dict + (dictSize - 0x10000));
            dictSize = 0x10000;
          }
          uVar16 = LZ4_decompress_safe_usingDict
                             ((char *)selectedIn,(char *)dstPtr,dctx->tmpInTarget,dctx->maxBlockSize
                              ,dict,dictSize);
          if ((int)uVar16 < 0) {
            LVar12 = LZ4F_returnErrorCode(LZ4F_ERROR_decompressionFailed);
            return LVar12;
          }
          if (((dctx->frameInfo).contentChecksumFlag != LZ4F_noContentChecksum) &&
             (dctx->skipChecksum == 0)) {
            XXH32_update(&dctx->xxh,dstPtr,uVar16);
          }
          if ((int)(dctx->frameInfo).contentSize != 0 ||
              *(int *)((int)&(dctx->frameInfo).contentSize + 4) != 0) {
            uVar14 = (uint)dctx->frameRemainingSize;
            iVar23 = *(int *)((int)&dctx->frameRemainingSize + 4);
            *(uint *)&dctx->frameRemainingSize = uVar14 - uVar16;
            *(uint *)((int)&dctx->frameRemainingSize + 4) = iVar23 - (uint)(uVar14 < uVar16);
          }
          if ((dctx->frameInfo).blockMode == LZ4F_blockLinked) {
            LZ4F_updateDict(dctx,dstPtr,uVar16,(BYTE *)dstBuffer,0);
          }
          dstPtr = dstPtr + uVar16;
          dctx->dStage = dstage_getBlockHeader;
        }
      }
      break;
    case dstage_flushOut:
      goto switchD_000e709c_caseD_9;
    case dstage_getSuffix:
      if ((int)dctx->frameRemainingSize != 0 || *(int *)((int)&dctx->frameRemainingSize + 4) != 0) {
        LVar12 = LZ4F_returnErrorCode(LZ4F_ERROR_frameSize_wrong);
        return LVar12;
      }
      if ((dctx->frameInfo).contentChecksumFlag != LZ4F_noContentChecksum) {
        if ((int)pBVar17 - (int)srcPtr < 4) {
          dctx->tmpInSize = 0;
          dctx->dStage = dstage_storeSuffix;
        }
        else {
          selectedIn = srcPtr;
          srcPtr = srcPtr + 4;
        }
        if (dctx->dStage == dstage_storeSuffix) goto switchD_000e709c_caseD_b;
        goto LAB_000e7b6c;
      }
      nextSrcSizeHint = 0;
      LZ4F_resetDecompressionContext(dctx);
      bVar9 = false;
      break;
    case dstage_storeSuffix:
switchD_000e709c_caseD_b:
      uVar16 = 4 - dctx->tmpInSize;
      if ((uint)((int)pBVar17 - (int)srcPtr) <= uVar16) {
        uVar16 = (int)pBVar17 - (int)srcPtr;
      }
      memcpy(dctx->tmpIn + dctx->tmpInSize,srcPtr,uVar16);
      srcPtr = srcPtr + uVar16;
      dctx->tmpInSize = dctx->tmpInSize + uVar16;
      if (dctx->tmpInSize < 4) {
        nextSrcSizeHint = 4 - dctx->tmpInSize;
        bVar9 = false;
      }
      else {
        selectedIn = dctx->tmpIn;
LAB_000e7b6c:
        if (dctx->skipChecksum == 0) {
          UVar13 = LZ4F_readLE32(selectedIn);
          uVar16 = XXH32_digest(&dctx->xxh);
          if (UVar13 != uVar16) {
            LVar12 = LZ4F_returnErrorCode(LZ4F_ERROR_contentChecksum_invalid);
            return LVar12;
          }
        }
        nextSrcSizeHint = 0;
        LZ4F_resetDecompressionContext(dctx);
        bVar9 = false;
      }
      break;
    case dstage_getSFrameSize:
      if ((int)pBVar17 - (int)srcPtr < 4) {
        dctx->tmpInSize = 4;
        dctx->tmpInTarget = 8;
        dctx->dStage = dstage_storeSFrameSize;
      }
      else {
        selectedIn = srcPtr;
        srcPtr = srcPtr + 4;
      }
      if (dctx->dStage == dstage_storeSFrameSize) goto switchD_000e709c_caseD_d;
      goto LAB_000e7c68;
    case dstage_storeSFrameSize:
switchD_000e709c_caseD_d:
      uVar16 = dctx->tmpInTarget - dctx->tmpInSize;
      if ((uint)((int)pBVar17 - (int)srcPtr) <= uVar16) {
        uVar16 = (int)pBVar17 - (int)srcPtr;
      }
      memcpy(dctx->header + dctx->tmpInSize,srcPtr,uVar16);
      srcPtr = srcPtr + uVar16;
      dctx->tmpInSize = dctx->tmpInSize + uVar16;
      if (dctx->tmpInSize < dctx->tmpInTarget) {
        nextSrcSizeHint = dctx->tmpInTarget - dctx->tmpInSize;
        bVar9 = false;
      }
      else {
        selectedIn = dctx->header + 4;
LAB_000e7c68:
        UVar13 = LZ4F_readLE32(selectedIn);
        *(U32 *)&(dctx->frameInfo).contentSize = UVar13;
        *(undefined4 *)((int)&(dctx->frameInfo).contentSize + 4) = 0;
        dctx->tmpInTarget = UVar13;
        dctx->dStage = dstage_skipSkippable;
      }
      break;
    case dstage_skipSkippable:
      uVar16 = dctx->tmpInTarget;
      if ((uint)((int)pBVar17 - (int)srcPtr) <= dctx->tmpInTarget) {
        uVar16 = (int)pBVar17 - (int)srcPtr;
      }
      srcPtr = srcPtr + uVar16;
      dctx->tmpInTarget = dctx->tmpInTarget - uVar16;
      bVar9 = false;
      nextSrcSizeHint = dctx->tmpInTarget;
      if (nextSrcSizeHint == 0) {
        LZ4F_resetDecompressionContext(dctx);
      }
      break;
    default:
      break;
    }
  } while( true );
}

