
LZ4F_errorCode_t LZ4F_writeOpen(LZ4_writeFile_t **lz4fWrite,FILE *fp,LZ4F_preferences_t *prefsPtr)

{
  LZ4_writeFile_t *pLVar1;
  size_t sVar2;
  LZ4_byte *pLVar3;
  uint uVar4;
  size_t sVar5;
  LZ4F_errorCode_t code;
  LZ4F_preferences_t *prefsPtr_local;
  FILE *fp_local;
  LZ4_writeFile_t **lz4fWrite_local;
  LZ4_byte buf [19];
  size_t ret;
  
  if ((fp == (FILE *)0x0) || (lz4fWrite == (LZ4_writeFile_t **)0x0)) {
    code = 0xffffffff;
  }
  else {
    pLVar1 = (LZ4_writeFile_t *)malloc(0x18);
    *lz4fWrite = pLVar1;
    if (*lz4fWrite == (LZ4_writeFile_t *)0x0) {
      code = 0xfffffff7;
    }
    else {
      if (prefsPtr == (LZ4F_preferences_t *)0x0) {
        (*lz4fWrite)->maxWriteSize = 0x10000;
      }
      else {
        switch((prefsPtr->frameInfo).blockSizeID) {
        case LZ4F_default:
        case LZ4F_max64KB:
          (*lz4fWrite)->maxWriteSize = 0x10000;
          break;
        default:
          free(lz4fWrite);
          return 0xfffffffe;
        case LZ4F_max256KB:
          (*lz4fWrite)->maxWriteSize = 0x40000;
          break;
        case LZ4F_max1MB:
          (*lz4fWrite)->maxWriteSize = 0x100000;
          break;
        case LZ4F_max4MB:
          (*lz4fWrite)->maxWriteSize = 0x400000;
        }
      }
      pLVar1 = *lz4fWrite;
      sVar2 = LZ4F_compressBound((*lz4fWrite)->maxWriteSize,prefsPtr);
      pLVar1->dstBufMaxSize = sVar2;
      pLVar1 = *lz4fWrite;
      pLVar3 = (LZ4_byte *)malloc((*lz4fWrite)->dstBufMaxSize);
      pLVar1->dstBuf = pLVar3;
      if ((*lz4fWrite)->dstBuf == (LZ4_byte *)0x0) {
        free(*lz4fWrite);
        code = 0xfffffff7;
      }
      else {
        pLVar1 = *lz4fWrite;
        uVar4 = LZ4F_getVersion();
        code = LZ4F_createCompressionContext(&pLVar1->cctxPtr,uVar4);
        uVar4 = LZ4F_isError(code);
        if (uVar4 == 0) {
          code = LZ4F_compressBegin((*lz4fWrite)->cctxPtr,buf,0x13,prefsPtr);
          uVar4 = LZ4F_isError(code);
          if (uVar4 == 0) {
            sVar5 = fwrite(buf,1,code,(FILE *)fp);
            if (sVar5 == code) {
              (*lz4fWrite)->fp = fp;
              (*lz4fWrite)->errCode = 0;
              code = 0;
            }
            else {
              LZ4F_freeCompressionContext((*lz4fWrite)->cctxPtr);
              free((*lz4fWrite)->dstBuf);
              free(*lz4fWrite);
              code = 0xffffffff;
            }
          }
          else {
            LZ4F_freeCompressionContext((*lz4fWrite)->cctxPtr);
            free((*lz4fWrite)->dstBuf);
            free(*lz4fWrite);
          }
        }
        else {
          free((*lz4fWrite)->dstBuf);
          free(*lz4fWrite);
        }
      }
    }
  }
  return code;
}

