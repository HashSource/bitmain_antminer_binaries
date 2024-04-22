
size_t utf8_check_first(char byte)

{
  size_t sVar1;
  char byte_local;
  uchar u;
  
  if (byte < '\0') {
    if ((byte < '\0') && ((byte)byte < 0xc0)) {
      sVar1 = 0;
    }
    else if ((byte == -0x40) || (byte == -0x3f)) {
      sVar1 = 0;
    }
    else if (((byte)byte < 0xc2) || (0xdf < (byte)byte)) {
      if (((byte)byte < 0xe0) || (0xef < (byte)byte)) {
        if (((byte)byte < 0xf0) || (0xf4 < (byte)byte)) {
          sVar1 = 0;
        }
        else {
          sVar1 = 4;
        }
      }
      else {
        sVar1 = 3;
      }
    }
    else {
      sVar1 = 2;
    }
  }
  else {
    sVar1 = 1;
  }
  return sVar1;
}

