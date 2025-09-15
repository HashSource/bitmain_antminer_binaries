
uint32_t real_mask(uint32_t mask,int need_bit)

{
  int need_bit_local;
  uint32_t mask_local;
  int bits;
  int i;
  uint32_t real_mask_bit;
  
  real_mask_bit = 0;
  bits = 0;
  i = 0;
  do {
    if (0x1f < i) {
      return real_mask_bit;
    }
    if ((mask >> (i & 0xffU) & 1) != 0) {
      real_mask_bit = real_mask_bit | 1 << (i & 0xffU);
      bits = bits + 1;
      if (bits == need_bit) {
        return real_mask_bit;
      }
    }
    i = i + 1;
  } while( true );
}

