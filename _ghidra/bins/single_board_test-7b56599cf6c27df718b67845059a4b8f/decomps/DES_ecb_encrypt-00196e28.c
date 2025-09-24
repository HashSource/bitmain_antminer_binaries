
void DES_ecb_encrypt(const_DES_cblock *input,DES_cblock *output,DES_key_schedule *ks,int enc)

{
  uint local_20;
  undefined4 local_1c;
  
  local_20 = *(uint *)*input;
  local_1c = *(undefined4 *)(*input + 4);
  DES_encrypt1(&local_20,ks,enc);
  (*output)[0] = (uchar)local_20;
  (*output)[1] = (uchar)(local_20 >> 8);
  (*output)[2] = (uchar)(local_20 >> 0x10);
  (*output)[3] = (uchar)(local_20 >> 0x18);
  (*output)[4] = (uchar)local_1c;
  (*output)[5] = (uchar)((uint)local_1c >> 8);
  (*output)[6] = (uchar)((uint)local_1c >> 0x10);
  (*output)[7] = (uchar)((uint)local_1c >> 0x18);
  return;
}

