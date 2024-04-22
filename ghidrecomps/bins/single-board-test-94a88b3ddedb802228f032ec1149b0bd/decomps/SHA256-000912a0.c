
uchar * SHA256(uchar *d,size_t n,uchar *md)

{
  uchar *md_00;
  SHA256_CTX local_90;
  
  md_00 = DAT_0009133c;
  if (md != (uchar *)0x0) {
    md_00 = md;
  }
  memset(&local_90,0,0x70);
  local_90.h[0] = 0x6a09e667;
  local_90.h[1] = 0xbb67ae85;
  local_90.h[2] = 0x3c6ef372;
  local_90.h[3] = 0xa54ff53a;
  local_90.h[4] = 0x510e527f;
  local_90.h[5] = 0x9b05688c;
  local_90.h[6] = 0x1f83d9ab;
  local_90.h[7] = 0x5be0cd19;
  local_90.md_len = 0x20;
  if (n != 0) {
    SHA256_Update_part_0(&local_90,d,n);
  }
  SHA256_Final(md_00,&local_90);
  OPENSSL_cleanse(&local_90,0x70);
  return md_00;
}

