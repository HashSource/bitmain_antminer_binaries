
int32_t decode_unicode_escape(char *str)

{
  byte bVar1;
  int iVar2;
  char *str_local;
  char c;
  int32_t value;
  int i;
  
  value = 0;
  if (*str != 'u') {
                    /* WARNING: Subroutine does not return */
    __assert_fail("str[0] == \'u\'","compat/jansson-2.9/src/load.c",0x138,"decode_unicode_escape");
  }
  i = 1;
  do {
    if (4 < i) {
      return value;
    }
    bVar1 = str[i];
    iVar2 = value * 0x10;
    if ((bVar1 < 0x30) || (0x39 < bVar1)) {
      if ((bVar1 < 0x61) || (0x7a < bVar1)) {
        if ((bVar1 < 0x41) || (0x5a < bVar1)) {
          return -1;
        }
        value = iVar2 + (bVar1 - 0x37);
      }
      else {
        value = iVar2 + (bVar1 - 0x57);
      }
    }
    else {
      value = iVar2 + (bVar1 - 0x30);
    }
    i = i + 1;
  } while( true );
}

