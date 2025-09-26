
uint LZ4F_isError(LZ4F_errorCode_t code)

{
  byte bVar1;
  LZ4F_errorCode_t LVar2;
  LZ4F_errorCode_t code_local;
  
  LVar2 = code;
  if (0xffffffea < code) {
    LVar2 = 1;
  }
  bVar1 = (byte)LVar2;
  if (code < 0xffffffeb) {
    bVar1 = 0;
  }
  return (uint)bVar1;
}

