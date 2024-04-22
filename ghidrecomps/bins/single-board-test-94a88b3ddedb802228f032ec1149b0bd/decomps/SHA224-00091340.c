
uchar * SHA224(uchar *d,size_t n,uchar *md)

{
  uchar *md_00;
  SHA256_CTX local_90;
  
  md_00 = DAT_000913dc;
  if (md != (uchar *)0x0) {
    md_00 = md;
  }
  memset(&local_90,0,0x70);
  local_90.h[0] = 0xc1059ed8;
  local_90.h[1] = 0x367cd507;
  local_90.h[2] = 0x3070dd17;
  local_90.h[3] = 0xf70e5939;
  local_90.h[4] = 0xffc00b31;
  local_90.h[5] = 0x68581511;
  local_90.h[6] = 0x64f98fa7;
  local_90.h[7] = 0xbefa4fa4;
  local_90.md_len = 0x1c;
  if (n != 0) {
    SHA256_Update_part_0(&local_90,d,n);
  }
  SHA256_Final(md_00,&local_90);
  OPENSSL_cleanse(&local_90,0x70);
  return md_00;
}

