
uchar swap_bit(uchar chr)

{
  uchar chr_local;
  int i;
  uchar ret;
  
  ret = '\0';
  for (i = 0; i < 8; i = i + 1) {
    if (((int)(uint)chr >> (i & 0xffU) & 1U) != 0) {
      ret = ret | (byte)(1 << (7U - i & 0xff));
    }
  }
  return ret;
}

