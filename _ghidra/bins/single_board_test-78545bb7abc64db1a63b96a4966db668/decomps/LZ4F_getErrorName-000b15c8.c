
char * LZ4F_getErrorName(LZ4F_errorCode_t code)

{
  uint uVar1;
  char *pcVar2;
  LZ4F_errorCode_t code_local;
  
  uVar1 = LZ4F_isError(code);
  pcVar2 = LZ4F_getErrorName::codeError;
  if (uVar1 != 0) {
    pcVar2 = LZ4F_errorStrings[-code];
  }
  return pcVar2;
}

