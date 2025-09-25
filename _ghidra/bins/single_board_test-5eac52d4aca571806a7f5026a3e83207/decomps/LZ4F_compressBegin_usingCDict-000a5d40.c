
size_t LZ4F_compressBegin_usingCDict
                 (LZ4F_cctx *cctxPtr,void *dstBuffer,size_t dstCapacity,LZ4F_CDict *cdict,
                 LZ4F_preferences_t *preferencesPtr)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  BYTE BVar11;
  BYTE *pBVar12;
  int iVar13;
  int iVar14;
  void *pvVar15;
  LZ4F_errorCode_t LVar16;
  size_t sVar17;
  char cVar18;
  LZ4F_blockMode_t LVar19;
  undefined4 uVar20;
  LZ4F_AllocFunction p_Var41;
  LZ4F_AllocFunction p_Var42;
  LZ4F_AllocFunction p_Var43;
  LZ4F_AllocFunction p_Var44;
  LZ4F_AllocFunction p_Var45;
  LZ4F_contentChecksum_t LVar21;
  uint uVar22;
  uint uVar23;
  LZ4F_CallocFunction p_Var46;
  LZ4F_CallocFunction p_Var47;
  LZ4F_CallocFunction p_Var48;
  LZ4F_CallocFunction p_Var49;
  LZ4F_CallocFunction p_Var50;
  char cVar24;
  ushort uVar25;
  LZ4F_frameType_t LVar26;
  LZ4F_blockChecksum_t LVar27;
  uint uVar28;
  LZ4F_FreeFunction p_Var29;
  LZ4F_FreeFunction p_Var30;
  LZ4F_FreeFunction p_Var31;
  LZ4F_FreeFunction p_Var32;
  LZ4F_FreeFunction p_Var33;
  char *header;
  bool bVar34;
  LZ4F_CustomMem LVar35;
  undefined8 uVar36;
  undefined8 uVar37;
  undefined8 uVar38;
  undefined8 uVar39;
  undefined8 uVar40;
  undefined8 uVar51;
  undefined8 uVar52;
  undefined8 uVar53;
  undefined8 uVar54;
  undefined8 uVar55;
  LZ4F_CDict *cdict_local;
  size_t dstCapacity_local;
  void *dstBuffer_local;
  LZ4F_cctx *cctxPtr_local;
  LZ4F_preferences_t prefNull;
  BYTE *headerStart;
  size_t requiredBuffSize;
  int allocatedSize;
  int requiredSize;
  U16 ctxTypeID;
  BYTE *dstStart;
  BYTE *dstPtr;
  
  memset(&prefNull,0,0x38);
  if (dstCapacity < 0x13) {
    pBVar12 = (BYTE *)LZ4F_returnErrorCode(LZ4F_ERROR_dstMaxSize_tooSmall);
  }
  else {
    if (preferencesPtr == (LZ4F_preferences_t *)0x0) {
      preferencesPtr = &prefNull;
    }
    LVar19 = (preferencesPtr->frameInfo).blockMode;
    LVar21 = (preferencesPtr->frameInfo).contentChecksumFlag;
    LVar26 = (preferencesPtr->frameInfo).frameType;
    (cctxPtr->prefs).frameInfo.blockSizeID = (preferencesPtr->frameInfo).blockSizeID;
    (cctxPtr->prefs).frameInfo.blockMode = LVar19;
    (cctxPtr->prefs).frameInfo.contentChecksumFlag = LVar21;
    (cctxPtr->prefs).frameInfo.frameType = LVar26;
    uVar20 = *(undefined4 *)((int)&(preferencesPtr->frameInfo).contentSize + 4);
    uVar22 = (preferencesPtr->frameInfo).dictID;
    LVar27 = (preferencesPtr->frameInfo).blockChecksumFlag;
    *(int *)&(cctxPtr->prefs).frameInfo.contentSize = (int)(preferencesPtr->frameInfo).contentSize;
    *(undefined4 *)((int)&(cctxPtr->prefs).frameInfo.contentSize + 4) = uVar20;
    (cctxPtr->prefs).frameInfo.dictID = uVar22;
    (cctxPtr->prefs).frameInfo.blockChecksumFlag = LVar27;
    uVar22 = preferencesPtr->autoFlush;
    uVar23 = preferencesPtr->favorDecSpeed;
    uVar28 = preferencesPtr->reserved[0];
    (cctxPtr->prefs).compressionLevel = preferencesPtr->compressionLevel;
    (cctxPtr->prefs).autoFlush = uVar22;
    (cctxPtr->prefs).favorDecSpeed = uVar23;
    (cctxPtr->prefs).reserved[0] = uVar28;
    uVar22 = preferencesPtr->reserved[2];
    (cctxPtr->prefs).reserved[1] = preferencesPtr->reserved[1];
    (cctxPtr->prefs).reserved[2] = uVar22;
    if ((cctxPtr->prefs).compressionLevel < 3) {
      uVar25 = 1;
    }
    else {
      uVar25 = 2;
    }
    iVar13 = ctxTypeID_to_size((uint)uVar25);
    iVar14 = ctxTypeID_to_size((uint)cctxPtr->lz4CtxAlloc);
    if (iVar14 < iVar13) {
      uVar1 = (cctxPtr->cmem).customAlloc;
      uVar2 = (cctxPtr->cmem).customCalloc;
      register0x00000028 = (LZ4F_CallocFunction)uVar2;
      p_Var41 = (LZ4F_AllocFunction)uVar1;
      p_Var29 = (cctxPtr->cmem).customFree;
      uVar36 = CONCAT44(preferencesPtr,p_Var29);
      LVar35 = (LZ4F_CustomMem)CONCAT88(uVar36,uVar51);
      LZ4F_free(cctxPtr->lz4CtxPtr,LVar35);
      if ((cctxPtr->prefs).compressionLevel < 3) {
        uVar3 = (cctxPtr->cmem).customAlloc;
        uVar4 = (cctxPtr->cmem).customCalloc;
        register0x00000028 = (LZ4F_CallocFunction)uVar4;
        p_Var42 = (LZ4F_AllocFunction)uVar3;
        p_Var30 = (cctxPtr->cmem).customFree;
        uVar37 = CONCAT44(preferencesPtr,p_Var30);
        LVar35 = (LZ4F_CustomMem)CONCAT88(uVar37,uVar52);
        pvVar15 = LZ4F_malloc(0x4020,LVar35);
        cctxPtr->lz4CtxPtr = pvVar15;
        if (cctxPtr->lz4CtxPtr != (void *)0x0) {
          LZ4_initStream(cctxPtr->lz4CtxPtr,0x4020);
        }
      }
      else {
        uVar5 = (cctxPtr->cmem).customAlloc;
        uVar6 = (cctxPtr->cmem).customCalloc;
        register0x00000028 = (LZ4F_CallocFunction)uVar6;
        p_Var43 = (LZ4F_AllocFunction)uVar5;
        p_Var31 = (cctxPtr->cmem).customFree;
        uVar38 = CONCAT44(preferencesPtr,p_Var31);
        LVar35 = (LZ4F_CustomMem)CONCAT88(uVar38,uVar53);
        pvVar15 = LZ4F_malloc(0x40038,LVar35);
        cctxPtr->lz4CtxPtr = pvVar15;
        if (cctxPtr->lz4CtxPtr != (void *)0x0) {
          LZ4_initStreamHC(cctxPtr->lz4CtxPtr,0x40038);
        }
      }
      if (cctxPtr->lz4CtxPtr == (void *)0x0) {
        LVar16 = LZ4F_returnErrorCode(LZ4F_ERROR_allocation_failed);
        return LVar16;
      }
      cctxPtr->lz4CtxAlloc = uVar25;
      cctxPtr->lz4CtxState = uVar25;
    }
    else if (uVar25 != cctxPtr->lz4CtxState) {
      if ((cctxPtr->prefs).compressionLevel < 3) {
        LZ4_initStream(cctxPtr->lz4CtxPtr,0x4020);
      }
      else {
        LZ4_initStreamHC(cctxPtr->lz4CtxPtr,0x40038);
        LZ4_setCompressionLevel
                  ((LZ4_streamHC_t *)cctxPtr->lz4CtxPtr,(cctxPtr->prefs).compressionLevel);
      }
      cctxPtr->lz4CtxState = uVar25;
    }
    if ((cctxPtr->prefs).frameInfo.blockSizeID == LZ4F_default) {
      (cctxPtr->prefs).frameInfo.blockSizeID = LZ4F_max64KB;
    }
    sVar17 = LZ4F_getBlockSize((cctxPtr->prefs).frameInfo.blockSizeID);
    cctxPtr->maxBlockSize = sVar17;
    if (preferencesPtr->autoFlush == 0) {
      if ((cctxPtr->prefs).frameInfo.blockMode == LZ4F_blockLinked) {
        iVar13 = 0x20000;
      }
      else {
        iVar13 = 0;
      }
      uVar22 = iVar13 + cctxPtr->maxBlockSize;
    }
    else if ((cctxPtr->prefs).frameInfo.blockMode == LZ4F_blockLinked) {
      uVar22 = 0x10000;
    }
    else {
      uVar22 = 0;
    }
    if (cctxPtr->maxBufferSize < uVar22) {
      cctxPtr->maxBufferSize = 0;
      uVar7 = (cctxPtr->cmem).customAlloc;
      uVar8 = (cctxPtr->cmem).customCalloc;
      register0x00000028 = (LZ4F_CallocFunction)uVar8;
      p_Var44 = (LZ4F_AllocFunction)uVar7;
      p_Var32 = (cctxPtr->cmem).customFree;
      uVar39 = CONCAT44(preferencesPtr,p_Var32);
      LVar35 = (LZ4F_CustomMem)CONCAT88(uVar39,uVar54);
      LZ4F_free(cctxPtr->tmpBuff,LVar35);
      uVar9 = (cctxPtr->cmem).customAlloc;
      uVar10 = (cctxPtr->cmem).customCalloc;
      register0x00000028 = (LZ4F_CallocFunction)uVar10;
      p_Var45 = (LZ4F_AllocFunction)uVar9;
      p_Var33 = (cctxPtr->cmem).customFree;
      uVar40 = CONCAT44(preferencesPtr,p_Var33);
      LVar35 = (LZ4F_CustomMem)CONCAT88(uVar40,uVar55);
      pBVar12 = (BYTE *)LZ4F_calloc(uVar22,LVar35);
      cctxPtr->tmpBuff = pBVar12;
      if (cctxPtr->tmpBuff == (BYTE *)0x0) {
        LVar16 = LZ4F_returnErrorCode(LZ4F_ERROR_allocation_failed);
        return LVar16;
      }
      cctxPtr->maxBufferSize = uVar22;
    }
    cctxPtr->tmpIn = cctxPtr->tmpBuff;
    cctxPtr->tmpInSize = 0;
    XXH32_reset(&cctxPtr->xxh,0);
    cctxPtr->cdict = cdict;
    if ((cctxPtr->prefs).frameInfo.blockMode == LZ4F_blockLinked) {
      LZ4F_initStream(cctxPtr->lz4CtxPtr,cdict,(cctxPtr->prefs).compressionLevel,LZ4F_blockLinked);
    }
    if (2 < preferencesPtr->compressionLevel) {
      LZ4_favorDecompressionSpeed
                ((LZ4_streamHC_t *)cctxPtr->lz4CtxPtr,preferencesPtr->favorDecSpeed);
    }
    LZ4F_writeLE32(dstBuffer,0x184d2204);
    header = (char *)((int)dstBuffer + 4);
    if ((int)(cctxPtr->prefs).frameInfo.contentSize == 0 &&
        *(int *)((int)&(cctxPtr->prefs).frameInfo.contentSize + 4) == 0) {
      cVar24 = '\0';
    }
    else {
      cVar24 = '\b';
    }
    uVar22 = (cctxPtr->prefs).frameInfo.dictID;
    bVar34 = uVar22 != 0;
    if (bVar34) {
      uVar22 = 1;
    }
    cVar18 = (char)uVar22;
    if (!bVar34) {
      cVar18 = '\0';
    }
    *header = ((byte)(cctxPtr->prefs).frameInfo.contentChecksumFlag & 1) * '\x04' +
              cVar24 + ((byte)(cctxPtr->prefs).frameInfo.blockChecksumFlag & 1) * '\x10' +
                       ((byte)(cctxPtr->prefs).frameInfo.blockMode & 1) * ' ' + cVar18 + '@';
    dstPtr = (BYTE *)((int)dstBuffer + 6);
    *(char *)((int)dstBuffer + 5) =
         (char)(((cctxPtr->prefs).frameInfo.blockSizeID & LZ4F_max4MB) << 4);
    if ((int)(cctxPtr->prefs).frameInfo.contentSize != 0 ||
        *(int *)((int)&(cctxPtr->prefs).frameInfo.contentSize + 4) != 0) {
      LZ4F_writeLE64(dstPtr,(cctxPtr->prefs).frameInfo.contentSize);
      dstPtr = (BYTE *)((int)dstBuffer + 0xe);
      *(undefined4 *)&cctxPtr->totalInSize = 0;
      *(undefined4 *)((int)&cctxPtr->totalInSize + 4) = 0;
    }
    if ((cctxPtr->prefs).frameInfo.dictID != 0) {
      LZ4F_writeLE32(dstPtr,(cctxPtr->prefs).frameInfo.dictID);
      dstPtr = dstPtr + 4;
    }
    BVar11 = LZ4F_headerChecksum(header,(int)dstPtr - (int)header);
    *dstPtr = BVar11;
    cctxPtr->cStage = 1;
    pBVar12 = dstPtr + (1 - (int)dstBuffer);
  }
  return (size_t)pBVar12;
}

