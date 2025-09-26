
void reverse(uint8_t *in,int32_t in_len)

{
  uint8_t uVar1;
  int32_t in_len_local;
  uint8_t *in_local;
  uint8_t tmp;
  int32_t i;
  
  for (i = 0; i < in_len / 2; i = i + 1) {
    uVar1 = in[(in_len + -1) - i];
    in[(in_len + -1) - i] = in[i];
    in[i] = uVar1;
  }
  return;
}

