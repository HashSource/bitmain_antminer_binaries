
int utf8_check_string(char *string,size_t length)

{
  size_t size;
  size_t sVar1;
  size_t length_local;
  char *string_local;
  size_t count;
  size_t i;
  
  i = 0;
  do {
    if (length <= i) {
      return 1;
    }
    size = utf8_check_first(string[i]);
    if (size == 0) {
      return 0;
    }
    if (1 < size) {
      if (length - i < size) {
        return 0;
      }
      sVar1 = utf8_check_full(string + i,size,(int32_t *)0x0);
      if (sVar1 == 0) {
        return 0;
      }
      i = (size + i) - 1;
    }
    i = i + 1;
  } while( true );
}

