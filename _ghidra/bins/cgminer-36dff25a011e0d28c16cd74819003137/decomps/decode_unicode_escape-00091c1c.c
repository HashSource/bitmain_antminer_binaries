
int32_t decode_unicode_escape(char *str)

{
  int iVar1;
  byte bVar2;
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
    bVar2 = str[i];
    iVar1 = value * 0x10;
    if ((bVar2 < 0x30) || (0x39 < bVar2)) {
      if ((bVar2 < 0x61) || (0x7a < bVar2)) {
        if ((bVar2 < 0x41) || (0x5a < bVar2)) {
          return -1;
        }
        value = iVar1 + (bVar2 - 0x37);
      }
      else {
        value = iVar1 + (bVar2 - 0x57);
      }
    }
    else {
      value = iVar1 + (bVar2 - 0x30);
    }
    i = i + 1;
  } while( true );
}

