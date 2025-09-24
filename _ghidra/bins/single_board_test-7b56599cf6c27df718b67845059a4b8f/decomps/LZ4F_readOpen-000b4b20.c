
LZ4F_errorCode_t LZ4F_readOpen(LZ4_readFile_t **lz4fRead,FILE *fp)

{
  LZ4_readFile_t *pLVar1;
  uint uVar2;
  LZ4_byte *pLVar3;
  LZ4F_errorCode_t code;
  FILE *fp_local;
  LZ4_readFile_t **lz4fRead_local;
  LZ4F_frameInfo_t info;
  size_t consumedSize;
  char buf [19];
  LZ4F_errorCode_t ret;
  
  if ((fp == (FILE *)0x0) || (lz4fRead == (LZ4_readFile_t **)0x0)) {
    code = 0xffffffff;
  }
  else {
    pLVar1 = (LZ4_readFile_t *)calloc(1,0x18);
    *lz4fRead = pLVar1;
    if (*lz4fRead == (LZ4_readFile_t *)0x0) {
      code = 0xfffffff7;
    }
    else {
      pLVar1 = *lz4fRead;
      uVar2 = LZ4F_getVersion();
      code = LZ4F_createDecompressionContext(&pLVar1->dctxPtr,uVar2);
      uVar2 = LZ4F_isError(code);
      if (uVar2 == 0) {
        (*lz4fRead)->fp = fp;
        consumedSize = fread(buf,1,0x13,(FILE *)(*lz4fRead)->fp);
        if (consumedSize == 0x13) {
          code = LZ4F_getFrameInfo((*lz4fRead)->dctxPtr,&info,buf,&consumedSize);
          uVar2 = LZ4F_isError(code);
          if (uVar2 == 0) {
            switch(info.blockSizeID) {
            case LZ4F_default:
            case LZ4F_max64KB:
              (*lz4fRead)->srcBufMaxSize = 0x10000;
              break;
            default:
              LZ4F_freeDecompressionContext((*lz4fRead)->dctxPtr);
              free(*lz4fRead);
              return 0xfffffffe;
            case LZ4F_max256KB:
              (*lz4fRead)->srcBufMaxSize = 0x40000;
              break;
            case LZ4F_max1MB:
              (*lz4fRead)->srcBufMaxSize = 0x100000;
              break;
            case LZ4F_max4MB:
              (*lz4fRead)->srcBufMaxSize = 0x400000;
            }
            pLVar1 = *lz4fRead;
            pLVar3 = (LZ4_byte *)malloc((*lz4fRead)->srcBufMaxSize);
            pLVar1->srcBuf = pLVar3;
            if ((*lz4fRead)->srcBuf == (LZ4_byte *)0x0) {
              LZ4F_freeDecompressionContext((*lz4fRead)->dctxPtr);
              free(lz4fRead);
              code = 0xfffffff7;
            }
            else {
              (*lz4fRead)->srcBufSize = 0x13 - consumedSize;
              memcpy((*lz4fRead)->srcBuf,buf + consumedSize,(*lz4fRead)->srcBufSize);
            }
          }
          else {
            LZ4F_freeDecompressionContext((*lz4fRead)->dctxPtr);
            free(*lz4fRead);
          }
        }
        else {
          free(*lz4fRead);
          code = 0xffffffff;
        }
      }
      else {
        free(*lz4fRead);
      }
    }
  }
  return code;
}

