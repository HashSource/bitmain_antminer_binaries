
_Bool Hex2Bin(char *hex,uchar *pBytes)

{
  size_t sVar1;
  uchar *pBytes_local;
  char *hex_local;
  uchar tmp;
  int j;
  int i;
  
  j = 0;
  i = 0;
  do {
    sVar1 = strlen(hex);
    if (sVar1 <= (uint)i) {
      return true;
    }
    if (((byte)hex[i] < 0x30) || (0x39 < (byte)hex[i])) {
      if (((byte)hex[i] < 0x61) || (0x66 < (byte)hex[i])) {
        if (((byte)hex[i] < 0x41) || (0x46 < (byte)hex[i])) {
          return false;
        }
        tmp = hex[i] + 0xc9;
      }
      else {
        tmp = hex[i] + 0xa9;
      }
    }
    else {
      tmp = hex[i] + 0xd0;
    }
    if ((i & 1U) == 0) {
      pBytes[j] = tmp << 4;
    }
    else {
      pBytes[j] = pBytes[j] + tmp;
      j = j + 1;
    }
    i = i + 1;
  } while( true );
}

