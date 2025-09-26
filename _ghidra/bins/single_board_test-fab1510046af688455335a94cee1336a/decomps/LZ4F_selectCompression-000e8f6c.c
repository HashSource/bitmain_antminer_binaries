
compressFunc_t
LZ4F_selectCompression(LZ4F_blockMode_t blockMode,int level,LZ4F_blockCompression_t compressMode)

{
  code *pcVar1;
  LZ4F_blockCompression_t compressMode_local;
  int level_local;
  LZ4F_blockMode_t blockMode_local;
  
  if (compressMode == LZ4B_UNCOMPRESSED) {
    pcVar1 = (code *)0xe8f51;
  }
  else if (level < 3) {
    if (blockMode == LZ4F_blockIndependent) {
      pcVar1 = (compressFunc_t)0xe8e2d;
    }
    else {
      pcVar1 = (compressFunc_t)0xe8e95;
    }
  }
  else if (blockMode == LZ4F_blockIndependent) {
    pcVar1 = (compressFunc_t)0xe8ed5;
  }
  else {
    pcVar1 = (compressFunc_t)0xe8f29;
  }
  return pcVar1;
}

