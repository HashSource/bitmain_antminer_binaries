
void DES_ecb_encrypt(const_DES_cblock *input,DES_cblock *output,DES_key_schedule *ks,int enc)

{
  uint local_28;
  uint local_24;
  
  local_28 = (uint)(*input)[2] << 0x10 | (uint)(*input)[1] << 8 | (uint)(*input)[0] |
             (uint)(*input)[3] << 0x18;
  local_24 = (uint)(*input)[6] << 0x10 | (uint)(*input)[5] << 8 | (uint)(*input)[4] |
             (uint)(*input)[7] << 0x18;
  DES_encrypt1(&local_28,ks,enc);
  (*output)[0] = (uchar)local_28;
  (*output)[1] = (uchar)(local_28 >> 8);
  (*output)[2] = (uchar)(local_28 >> 0x10);
  (*output)[3] = (uchar)(local_28 >> 0x18);
  (*output)[4] = (uchar)local_24;
  (*output)[5] = (uchar)(local_24 >> 8);
  (*output)[6] = (uchar)(local_24 >> 0x10);
  (*output)[7] = (uchar)(local_24 >> 0x18);
  return;
}

