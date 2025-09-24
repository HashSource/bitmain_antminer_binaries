
int utf8_check_string_x(char *string,int length,int *p_err_pos)

{
  size_t size;
  size_t sVar1;
  int *p_err_pos_local;
  int length_local;
  char *string_local;
  int count;
  int i;
  
  length_local = length;
  if (length == -1) {
    length_local = strlen(string);
  }
  i = 0;
  do {
    if (length_local <= i) {
      return 1;
    }
    size = utf8_check_first(string[i]);
    if (size == 0) {
      *p_err_pos = -1;
      return 0;
    }
    if (1 < (int)size) {
      if (length_local < (int)(i + size)) {
        *p_err_pos = -1;
        return 0;
      }
      sVar1 = utf8_check_full(string + i,size,(int32_t *)0x0);
      if (sVar1 == 0) {
        *p_err_pos = i;
        return 0;
      }
      i = (size - 1) + i;
    }
    i = i + 1;
  } while( true );
}

