
/* WARNING: Unknown calling convention */

int utf8_encode(int32_t codepoint,char *buffer,int *size)

{
  byte bVar1;
  
  if (-1 < codepoint) {
    bVar1 = (byte)codepoint;
    if (codepoint < 0x80) {
      *buffer = bVar1;
      *size = 1;
      return 0;
    }
    if (codepoint < 0x800) {
      buffer[1] = (bVar1 & 0x3f) + 0x80;
      *buffer = (byte)((uint)(codepoint << 0x15) >> 0x1b) - 0x40;
      *size = 2;
      return 0;
    }
    if (codepoint < 0x10000) {
      *buffer = ((byte)((uint)codepoint >> 8) >> 4) - 0x20;
      buffer[1] = (byte)((uint)(codepoint << 0x14) >> 0x1a) + 0x80;
      buffer[2] = (bVar1 & 0x3f) + 0x80;
      *size = 3;
      return 0;
    }
    if (codepoint < 0x110000) {
      *buffer = (byte)((uint)(codepoint << 0xb) >> 0x1d) - 0x10;
      buffer[1] = (byte)((uint)(codepoint << 0xe) >> 0x1a) + 0x80;
      buffer[2] = (byte)((uint)(codepoint << 0x14) >> 0x1a) + 0x80;
      buffer[3] = (bVar1 & 0x3f) + 0x80;
      *size = 4;
      return 0;
    }
  }
  return -1;
}

