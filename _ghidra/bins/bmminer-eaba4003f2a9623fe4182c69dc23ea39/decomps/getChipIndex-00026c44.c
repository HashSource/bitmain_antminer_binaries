
int getChipIndex(char *nonce4)

{
  _Bool _Var1;
  uint uVar2;
  char *nonce4_local;
  uchar nonce_bytes [4];
  char nonce [9];
  int chipIndex;
  
  _Var1 = Hex2Bin(nonce,nonce_bytes);
  if (_Var1) {
    uVar2 = (uint)(nonce_bytes[0] >> 2);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

