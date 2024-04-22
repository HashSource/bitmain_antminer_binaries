
void RC2_ecb_encrypt(uchar *in,uchar *out,RC2_KEY *key,int enc)

{
  uint local_20;
  uint local_1c;
  
  local_20 = (uint)in[2] << 0x10 | (uint)in[1] << 8 | (uint)*in | (uint)in[3] << 0x18;
  local_1c = (uint)in[6] << 0x10 | (uint)in[5] << 8 | (uint)in[4] | (uint)in[7] << 0x18;
  if (enc == 0) {
    RC2_decrypt(&local_20,key);
  }
  else {
    RC2_encrypt(&local_20,key);
  }
  *out = (uchar)local_20;
  out[1] = (uchar)(local_20 >> 8);
  out[2] = (uchar)(local_20 >> 0x10);
  out[3] = (uchar)(local_20 >> 0x18);
  out[4] = (uchar)local_1c;
  out[5] = (uchar)(local_1c >> 8);
  out[6] = (uchar)(local_1c >> 0x10);
  out[7] = (uchar)(local_1c >> 0x18);
  return;
}

