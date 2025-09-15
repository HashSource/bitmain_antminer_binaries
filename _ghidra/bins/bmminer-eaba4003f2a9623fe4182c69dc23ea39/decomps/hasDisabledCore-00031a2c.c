
/* WARNING: Unknown calling convention */

_Bool hasDisabledCore(void)

{
  int j;
  int i;
  
  i = 0;
  do {
    if (0xf < i) {
      return false;
    }
    if ((disabledcore_pos_buf[i][0] == ',') && (disabledcore_pos_buf[i][1] == 'e')) {
      for (j = 1; j < 8; j = j + 1) {
        if ((disabledcore_pos_buf[i][j * 2] < 0x6c) && (disabledcore_pos_buf[i][j * 2 + 1] < 0xd0))
        {
          return true;
        }
      }
    }
    i = i + 1;
  } while( true );
}

