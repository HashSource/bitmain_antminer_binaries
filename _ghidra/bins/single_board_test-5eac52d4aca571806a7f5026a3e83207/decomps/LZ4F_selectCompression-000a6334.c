
compressFunc_t
LZ4F_selectCompression(LZ4F_blockMode_t blockMode,int level,LZ4F_blockCompression_t compressMode)

{
  code *pcVar1;
  LZ4F_blockCompression_t compressMode_local;
  int level_local;
  LZ4F_blockMode_t blockMode_local;
  
  if (compressMode == LZ4B_UNCOMPRESSED) {
    pcVar1 = (code *)0xa6319;
  }
  else if (level < 3) {
    if (blockMode == LZ4F_blockIndependent) {
      pcVar1 = (compressFunc_t)0xa61f5;
    }
    else {
      pcVar1 = (compressFunc_t)0xa625d;
    }
  }
  else if (blockMode == LZ4F_blockIndependent) {
    pcVar1 = (compressFunc_t)0xa629d;
  }
  else {
    pcVar1 = (compressFunc_t)0xa62f1;
  }
  return pcVar1;
}

