
/* WARNING: Unknown calling convention */

char * utf8_iterate(char *buffer,size_t bufsize,int32_t *codepoint)

{
  byte byte;
  uint uVar1;
  size_t size;
  size_t sVar2;
  int32_t value;
  
  if (bufsize != 0) {
    byte = *buffer;
    size = utf8_check_first(byte);
    if ((size == 0) ||
       ((uVar1 = (uint)byte, size != 1 &&
        ((bufsize < size || (sVar2 = utf8_check_full(buffer,size,&value), uVar1 = value, sVar2 == 0)
         ))))) {
      buffer = (char *)0x0;
    }
    else {
      value = uVar1;
      if (codepoint != (int32_t *)0x0) {
        *codepoint = value;
      }
      buffer = buffer + size;
    }
  }
  return buffer;
}

