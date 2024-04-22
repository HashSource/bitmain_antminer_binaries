
int jsonp_dtostr(char *buffer,size_t size,double value,int precision)

{
  char *pcVar1;
  int precision_local;
  double value_local;
  size_t size_local;
  char *buffer_local;
  int ret;
  size_t length;
  char *end;
  char *start;
  
  precision_local = precision;
  if (precision == 0) {
    precision_local = 0x11;
  }
  length = snprintf(buffer,size,"%.*g",precision_local);
  if ((int)length < 0) {
    length = 0xffffffff;
  }
  else if (length < size) {
    from_locale(buffer);
    pcVar1 = strchr(buffer,0x2e);
    if ((pcVar1 == (char *)0x0) && (pcVar1 = strchr(buffer,0x65), pcVar1 == (char *)0x0)) {
      if (size <= length + 3) {
        return -1;
      }
      buffer[length] = '.';
      buffer[length + 1] = '0';
      buffer[length + 2] = '\0';
      length = length + 2;
    }
    pcVar1 = strchr(buffer,0x65);
    if (pcVar1 != (char *)0x0) {
      start = pcVar1 + 1;
      end = pcVar1 + 2;
      if (*start == '-') {
        start = pcVar1 + 2;
      }
      for (; *end == '0'; end = end + 1) {
      }
      if (end != start) {
        memmove(start,end,length - ((int)end - (int)buffer));
        length = length - ((int)end - (int)start);
      }
    }
  }
  else {
    length = 0xffffffff;
  }
  return length;
}

