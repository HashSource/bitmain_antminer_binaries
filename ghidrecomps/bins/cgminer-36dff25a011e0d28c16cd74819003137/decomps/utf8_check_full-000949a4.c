
size_t utf8_check_full(char *buffer,size_t size,int32_t *codepoint)

{
  byte bVar1;
  size_t sVar2;
  int32_t *codepoint_local;
  size_t size_local;
  char *buffer_local;
  uchar u;
  int32_t value;
  size_t i;
  
  bVar1 = *buffer;
  if (size == 2) {
    value = bVar1 & 0x1f;
  }
  else if (size == 3) {
    value = bVar1 & 0xf;
  }
  else {
    if (size != 4) {
      return 0;
    }
    value = bVar1 & 7;
  }
  i = 1;
  while( true ) {
    if (size <= i) {
      if (value < 0x110000) {
        if ((value < 0xd800) || (0xdfff < value)) {
          if ((((size == 2) && (value < 0x80)) || ((size == 3 && (value < 0x800)))) ||
             ((size == 4 && (value < 0x10000)))) {
            sVar2 = 0;
          }
          else {
            if (codepoint != (int32_t *)0x0) {
              *codepoint = value;
            }
            sVar2 = 1;
          }
        }
        else {
          sVar2 = 0;
        }
      }
      else {
        sVar2 = 0;
      }
      return sVar2;
    }
    bVar1 = buffer[i];
    if ((-1 < (char)bVar1) || (0xbf < bVar1)) break;
    value = value * 0x40 + (bVar1 & 0x3f);
    i = i + 1;
  }
  return 0;
}

