
void LZ4F_updateDict(LZ4F_dctx *dctx,BYTE *dstPtr,size_t dstSize,BYTE *dstBufferStart,uint withinTmp
                    )

{
  uint uVar1;
  size_t __n;
  BYTE *dstBufferStart_local;
  size_t dstSize_local;
  BYTE *dstPtr_local;
  LZ4F_dctx *dctx_local;
  size_t preserveSize_1;
  BYTE *oldDictEnd;
  size_t preserveSize;
  size_t preserveSize_2;
  size_t copySize;
  
  if (dctx->dictSize == 0) {
    dctx->dict = dstPtr;
  }
  if (dctx->dict + dctx->dictSize == dstPtr) {
    dctx->dictSize = dctx->dictSize + dstSize;
  }
  else if (dstPtr + (dstSize - (int)dstBufferStart) < "\x7fELF\x01\x01\x01") {
    if ((withinTmp == 0) || (dctx->dict != dctx->tmpOutBuffer)) {
      if (withinTmp == 0) {
        if (dctx->dict == dctx->tmpOutBuffer) {
          if (dctx->maxBufferSize < dctx->dictSize + dstSize) {
            __n = 0x10000 - dstSize;
            memcpy(dctx->tmpOutBuffer,dctx->dict + (dctx->dictSize - __n),__n);
            dctx->dictSize = __n;
          }
          memcpy(dctx->tmpOutBuffer + dctx->dictSize,dstPtr,dstSize);
          dctx->dictSize = dctx->dictSize + dstSize;
        }
        else {
          preserveSize_2 = 0x10000 - dstSize;
          if (dctx->dictSize < preserveSize_2) {
            preserveSize_2 = dctx->dictSize;
          }
          memcpy(dctx->tmpOutBuffer,dctx->dict + (dctx->dictSize - preserveSize_2),preserveSize_2);
          memcpy(dctx->tmpOutBuffer + preserveSize_2,dstPtr,dstSize);
          dctx->dict = dctx->tmpOutBuffer;
          dctx->dictSize = preserveSize_2 + dstSize;
        }
      }
      else {
        uVar1 = (int)dctx->tmpOut - (int)dctx->tmpOutBuffer;
        copySize = 0x10000 - dctx->tmpOutSize;
        if (0x10000 < dctx->tmpOutSize) {
          copySize = 0;
        }
        if (uVar1 < copySize) {
          copySize = uVar1;
        }
        memcpy(dctx->tmpOutBuffer + (uVar1 - copySize),
               dctx->dict + ((dctx->dictSize - dctx->tmpOutStart) - copySize),copySize);
        dctx->dict = dctx->tmpOutBuffer;
        dctx->dictSize = dctx->tmpOutStart + uVar1 + dstSize;
      }
    }
    else {
      dctx->dictSize = dctx->dictSize + dstSize;
    }
  }
  else {
    dctx->dict = dstBufferStart;
    dctx->dictSize = (size_t)(dstPtr + (dstSize - (int)dstBufferStart));
  }
  return;
}

