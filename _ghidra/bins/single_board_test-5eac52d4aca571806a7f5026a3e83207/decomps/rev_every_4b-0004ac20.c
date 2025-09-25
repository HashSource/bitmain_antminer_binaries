
void rev_every_4b(uint8_t *in,int32_t in_len)

{
  int32_t in_len_local;
  uint8_t *in_local;
  int32_t i;
  
  if ((in_len & 3U) == 0) {
    for (i = 0; i < in_len; i = i + 4) {
      reverse(in + i,4);
    }
  }
  return;
}

