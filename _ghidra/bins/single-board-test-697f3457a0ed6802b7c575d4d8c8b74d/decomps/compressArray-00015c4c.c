
void compressArray(uchar *in,size_t in_len,uchar *out,size_t out_len,size_t bit_len,size_t byte_pad)

{
  size_t sVar1;
  uint uVar2;
  size_t out_len_local;
  uchar *out_local;
  size_t in_len_local;
  uchar *in_local;
  uint32_t bit_len_mask;
  size_t in_width;
  size_t x;
  size_t i;
  size_t j;
  uint32_t acc_value;
  size_t acc_bits;
  
  if (bit_len < 8) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("bit_len >= 8","bm174x/equihash-verify.c",0x14,"compressArray");
  }
  if (0x20 < bit_len + 7) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("8 * sizeof(uint32_t) >= 7 + bit_len","bm174x/equihash-verify.c",0x15,
                  "compressArray");
  }
  uVar2 = byte_pad + (bit_len + 7 >> 3);
  sVar1 = __udivsi3(in_len * bit_len,uVar2 * 8);
  if (sVar1 != out_len) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("out_len == bit_len * in_len / (8 * in_width)","bm174x/equihash-verify.c",0x18,
                  "compressArray");
  }
  acc_bits = 0;
  acc_value = 0;
  j = 0;
  for (i = 0; i < out_len; i = i + 1) {
    if (acc_bits < 8) {
      acc_value = acc_value << (bit_len & 0xff);
      for (x = byte_pad; x < uVar2; x = x + 1) {
        acc_value = ((1 << (bit_len & 0xff)) - 1U >> (((uVar2 - x) + 0x1fffffff) * 8 & 0xff) &
                    (uint)in[x + j]) << (((uVar2 - x) + 0x1fffffff) * 8 & 0xff) | acc_value;
      }
      j = uVar2 + j;
      acc_bits = bit_len + acc_bits;
    }
    acc_bits = acc_bits - 8;
    out[i] = (uchar)(acc_value >> (acc_bits & 0xff));
  }
  return;
}

