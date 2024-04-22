
/* WARNING: Unknown calling convention */

int utf8_check_string(char *string,int length)

{
  int iVar1;
  int size;
  int count;
  int iVar2;
  
  if (length == -1) {
    length = strlen(string);
  }
  if (0 < length) {
    iVar2 = 0;
    do {
      size = utf8_check_first(string[iVar2]);
      if (size == 0) {
        return 0;
      }
      if (1 < size) {
        if (length < iVar2 + size) {
          return 0;
        }
        iVar1 = utf8_check_full(string + iVar2,size,(int32_t *)0x0);
        if (iVar1 == 0) {
          return 0;
        }
        iVar2 = iVar2 + size + -1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < length);
  }
  return 1;
}

