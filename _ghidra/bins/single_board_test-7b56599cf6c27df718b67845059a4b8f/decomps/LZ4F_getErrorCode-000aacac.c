
LZ4F_errorCodes LZ4F_getErrorCode(size_t functionResult)

{
  uint uVar1;
  LZ4F_errorCodes LVar2;
  size_t functionResult_local;
  
  uVar1 = LZ4F_isError(functionResult);
  if (uVar1 == 0) {
    LVar2 = LZ4F_OK_NoError;
  }
  else {
    LVar2 = -functionResult;
  }
  return LVar2;
}

