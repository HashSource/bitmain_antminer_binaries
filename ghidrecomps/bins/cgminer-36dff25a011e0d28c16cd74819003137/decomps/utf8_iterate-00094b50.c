
char * utf8_iterate(char *buffer,size_t bufsize,int32_t *codepoint)

{
  size_t sVar1;
  int32_t *codepoint_local;
  size_t bufsize_local;
  char *buffer_local;
  int32_t value;
  size_t count;
  
  if (bufsize != 0) {
    count = utf8_check_first(*buffer);
    if (count == 0) {
      buffer = (char *)0x0;
    }
    else {
      if (count == 1) {
        value = (int32_t)(byte)*buffer;
      }
      else if ((bufsize < count) || (sVar1 = utf8_check_full(buffer,count,&value), sVar1 == 0)) {
        return (char *)0x0;
      }
      if (codepoint != (int32_t *)0x0) {
        *codepoint = value;
      }
      buffer = buffer + count;
    }
  }
  return buffer;
}

