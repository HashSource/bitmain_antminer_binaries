
void idea_ecb_encrypt(uchar *in,uchar *out,IDEA_KEY_SCHEDULE *ks)

{
  uint local_20;
  uint local_1c;
  
  local_20 = (uint)in[1] << 0x10 | (uint)*in << 0x18 | (uint)in[3] | (uint)in[2] << 8;
  local_1c = (uint)in[5] << 0x10 | (uint)in[4] << 0x18 | (uint)in[7] | (uint)in[6] << 8;
  idea_encrypt(&local_20,ks);
  out[3] = (uchar)local_20;
  *out = (uchar)(local_20 >> 0x18);
  out[1] = (uchar)(local_20 >> 0x10);
  out[2] = (uchar)(local_20 >> 8);
  out[7] = (uchar)local_1c;
  out[4] = (uchar)(local_1c >> 0x18);
  out[5] = (uchar)(local_1c >> 0x10);
  out[6] = (uchar)(local_1c >> 8);
  return;
}

