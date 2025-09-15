
void expandArray(uchar *in,size_t in_len,uchar *out,size_t out_len,size_t bit_len,size_t byte_pad)

{
  size_t sVar1;
  uint uVar2;
  size_t out_len_local;
  uchar *out_local;
  size_t in_len_local;
  uchar *in_local;
  uint32_t bit_len_mask;
  size_t out_width;
  size_t x_1;
  size_t x;
  size_t i;
  size_t j;
  uint32_t acc_value;
  size_t acc_bits;
  
  if (bit_len < 8) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("bit_len >= 8","bm174x/equihash-verify.c",0x3e,"expandArray");
  }
  if (0x20 < bit_len + 7) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("8 * sizeof(uint32_t) >= 7 + bit_len","bm174x/equihash-verify.c",0x3f,
                  "expandArray");
  }
  uVar2 = byte_pad + (bit_len + 7 >> 3);
  sVar1 = __udivsi3(in_len * uVar2 * 8,bit_len);
  if (sVar1 != out_len) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("out_len == 8 * out_width * in_len / bit_len","bm174x/equihash-verify.c",0x42,
                  "expandArray");
  }
  acc_bits = 0;
  acc_value = 0;
  j = 0;
  for (i = 0; i < in_len; i = i + 1) {
    acc_value = acc_value << 8 | (uint)in[i];
    acc_bits = acc_bits + 8;
    if (bit_len <= acc_bits) {
      acc_bits = acc_bits - bit_len;
      for (x = 0; x < byte_pad; x = x + 1) {
        out[x + j] = '\0';
      }
      for (x_1 = byte_pad; x_1 < uVar2; x_1 = x_1 + 1) {
        out[x_1 + j] = (byte)((1 << (bit_len & 0xff)) - 1U >>
                             (((uVar2 - x_1) + 0x1fffffff) * 8 & 0xff)) &
                       (byte)(acc_value >> (acc_bits + ((uVar2 - x_1) + 0x1fffffff) * 8 & 0xff));
      }
      j = uVar2 + j;
    }
  }
  return;
}

