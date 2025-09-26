
/* WARNING: Unknown calling convention */

int utf8_check_string(char *string,size_t length)

{
  size_t sVar1;
  size_t size;
  uint uVar2;
  
  if (length != 0) {
    uVar2 = 0;
    do {
      size = utf8_check_first(string[uVar2]);
      if (size == 0) {
        return 0;
      }
      if (1 < size) {
        if (length - uVar2 < size) {
          return 0;
        }
        sVar1 = utf8_check_full(string + uVar2,size,(int32_t *)0x0);
        if (sVar1 == 0) {
          return 0;
        }
        uVar2 = (size + uVar2) - 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < length);
  }
  return 1;
}

