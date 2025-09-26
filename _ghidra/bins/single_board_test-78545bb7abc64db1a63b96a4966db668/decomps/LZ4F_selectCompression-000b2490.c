
compressFunc_t
LZ4F_selectCompression(LZ4F_blockMode_t blockMode,int level,LZ4F_blockCompression_t compressMode)

{
  code *pcVar1;
  LZ4F_blockCompression_t compressMode_local;
  int level_local;
  LZ4F_blockMode_t blockMode_local;
  
  if (compressMode == LZ4B_UNCOMPRESSED) {
    pcVar1 = (code *)0xb2475;
  }
  else if (level < 3) {
    if (blockMode == LZ4F_blockIndependent) {
      pcVar1 = (compressFunc_t)0xb2351;
    }
    else {
      pcVar1 = (compressFunc_t)0xb23b9;
    }
  }
  else if (blockMode == LZ4F_blockIndependent) {
    pcVar1 = (compressFunc_t)0xb23f9;
  }
  else {
    pcVar1 = (compressFunc_t)0xb244d;
  }
  return pcVar1;
}

