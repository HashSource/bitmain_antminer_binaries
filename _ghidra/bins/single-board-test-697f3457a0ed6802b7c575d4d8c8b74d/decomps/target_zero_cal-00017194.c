
uint32_t target_zero_cal(uint8_t *target)

{
  uchar uVar1;
  uint8_t *target_local;
  uint8_t tmphash [32];
  int j;
  int i_1;
  int i;
  uint32_t zero_num;
  
  zero_num = 0;
  memset(tmphash,0,0x20);
  for (i = 0; i < 0x20; i = i + 1) {
    tmphash[i] = target[0x1f - i];
  }
  i_1 = 0;
  do {
    if (0x1f < i_1) {
      return zero_num;
    }
    for (j = 7; -1 < j; j = j + -1) {
      uVar1 = bit_read(tmphash + i_1,j);
      if (uVar1 != '\0') {
        return zero_num;
      }
      zero_num = zero_num + 1;
    }
    i_1 = i_1 + 1;
  } while( true );
}

