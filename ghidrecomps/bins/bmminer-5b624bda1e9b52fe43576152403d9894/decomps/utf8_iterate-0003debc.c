
/* WARNING: Unknown calling convention */

char * utf8_iterate(char *buffer,int32_t *codepoint)

{
  byte byte;
  uint uVar1;
  int size;
  int count;
  int iVar2;
  int32_t value;
  
  byte = *buffer;
  if (byte != 0) {
    size = utf8_check_first(byte);
    if ((size < 1) ||
       ((uVar1 = (uint)byte, size != 1 &&
        (iVar2 = utf8_check_full(buffer,size,&value), uVar1 = value, iVar2 == 0)))) {
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

