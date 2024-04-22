
int utf8_encode(int32_t codepoint,char *buffer,size_t *size)

{
  byte bVar1;
  int iVar2;
  size_t *size_local;
  char *buffer_local;
  int32_t codepoint_local;
  
  if (codepoint < 0) {
    iVar2 = -1;
  }
  else {
    bVar1 = (byte)codepoint;
    if (codepoint < 0x80) {
      *buffer = bVar1;
      *size = 1;
    }
    else if (codepoint < 0x800) {
      *buffer = (char)((int)(codepoint & 0x7c0U) >> 6) + -0x40;
      buffer[1] = (bVar1 & 0x3f) + 0x80;
      *size = 2;
    }
    else if (codepoint < 0x10000) {
      *buffer = (char)((int)(codepoint & 0xf000U) >> 0xc) + -0x20;
      buffer[1] = (char)((int)(codepoint & 0xfc0U) >> 6) + -0x80;
      buffer[2] = (bVar1 & 0x3f) + 0x80;
      *size = 3;
    }
    else {
      if (0x10ffff < codepoint) {
        return -1;
      }
      *buffer = (char)((int)(codepoint & 0x1c0000U) >> 0x12) + -0x10;
      buffer[1] = (char)((int)(codepoint & 0x3f000U) >> 0xc) + -0x80;
      buffer[2] = (char)((int)(codepoint & 0xfc0U) >> 6) + -0x80;
      buffer[3] = (bVar1 & 0x3f) + 0x80;
      *size = 4;
    }
    iVar2 = 0;
  }
  return iVar2;
}

