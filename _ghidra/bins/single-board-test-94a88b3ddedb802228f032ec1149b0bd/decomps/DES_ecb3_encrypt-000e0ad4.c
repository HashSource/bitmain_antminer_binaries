
void DES_ecb3_encrypt(const_DES_cblock *input,DES_cblock *output,DES_key_schedule *ks1,
                     DES_key_schedule *ks2,DES_key_schedule *ks3,int enc)

{
  uint local_28;
  uint uStack_24;
  
  local_28 = (uint)(*input)[2] << 0x10 | (uint)(*input)[1] << 8 | (uint)(*input)[0] |
             (uint)(*input)[3] << 0x18;
  uStack_24 = (uint)(*input)[6] << 0x10 | (uint)(*input)[5] << 8 | (uint)(*input)[4] |
              (uint)(*input)[7] << 0x18;
  if (enc == 0) {
    DES_decrypt3(&local_28,ks1,ks2,ks3);
  }
  else {
    DES_encrypt3(&local_28,ks1,ks2,ks3);
  }
  (*output)[0] = (uchar)local_28;
  (*output)[1] = (uchar)(local_28 >> 8);
  (*output)[2] = (uchar)(local_28 >> 0x10);
  (*output)[3] = (uchar)(local_28 >> 0x18);
  (*output)[4] = (uchar)uStack_24;
  (*output)[5] = (uchar)(uStack_24 >> 8);
  (*output)[6] = (uchar)(uStack_24 >> 0x10);
  (*output)[7] = (uchar)(uStack_24 >> 0x18);
  return;
}

