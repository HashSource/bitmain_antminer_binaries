
int utf8_encode(int32_t codepoint,char *buffer,size_t *size)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  size_t *size_local;
  char *buffer_local;
  int32_t codepoint_local;
  
  if (codepoint < 0) {
    iVar4 = -1;
  }
  else {
    bVar1 = (byte)codepoint;
    if (codepoint < 0x80) {
      *buffer = bVar1;
      *size = 1;
    }
    else {
      bVar2 = (byte)(codepoint >> 6);
      if (codepoint < 0x800) {
        *buffer = (bVar2 & 0x1f) - 0x40;
        buffer[1] = (bVar1 & 0x3f) + 0x80;
        *size = 2;
      }
      else {
        bVar3 = (byte)(codepoint >> 0xc);
        if (codepoint < 0x10000) {
          *buffer = (bVar3 & 0xf) - 0x20;
          buffer[1] = (bVar2 & 0x3f) + 0x80;
          buffer[2] = (bVar1 & 0x3f) + 0x80;
          *size = 3;
        }
        else {
          if (0x10ffff < codepoint) {
            return -1;
          }
          *buffer = ((byte)(codepoint >> 0x12) & 7) - 0x10;
          buffer[1] = (bVar3 & 0x3f) + 0x80;
          buffer[2] = (bVar2 & 0x3f) + 0x80;
          buffer[3] = (bVar1 & 0x3f) + 0x80;
          *size = 4;
        }
      }
    }
    iVar4 = 0;
  }
  return iVar4;
}

