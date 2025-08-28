
uchar * SHA512(uchar *d,size_t n,uchar *md)

{
  undefined1 *md_00;
  SHA512_CTX local_f8;
  
  local_f8.h[2]._0_4_ = 0xfe94f82b;
  local_f8.h[2]._4_4_ = 0x3c6ef372;
  md_00 = m_7558;
  local_f8.h[3]._0_4_ = 0x5f1d36f1;
  local_f8.h[3]._4_4_ = 0xa54ff53a;
  local_f8.h[0]._0_4_ = 0xf3bcc908;
  local_f8.h[0]._4_4_ = 0x6a09e667;
  if (md != (uchar *)0x0) {
    md_00 = md;
  }
  local_f8.h[4]._0_4_ = 0xade682d1;
  local_f8.h[4]._4_4_ = 0x510e527f;
  local_f8.h[1]._0_4_ = 0x84caa73b;
  local_f8.h[1]._4_4_ = 0xbb67ae85;
  local_f8.num = 0;
  local_f8.h[6]._0_4_ = 0xfb41bd6b;
  local_f8.h[6]._4_4_ = 0x1f83d9ab;
  local_f8.md_len = 0x40;
  local_f8.h[5]._0_4_ = 0x2b3e6c1f;
  local_f8.h[5]._4_4_ = 0x9b05688c;
  local_f8.h[7]._0_4_ = 0x137e2179;
  local_f8.h[7]._4_4_ = 0x5be0cd19;
  local_f8.Nl._0_4_ = 0;
  local_f8.Nl._4_4_ = 0;
  local_f8.Nh._0_4_ = 0;
  local_f8.Nh._4_4_ = 0;
  SHA512_Update(&local_f8,d,n);
  SHA512_Final(md_00,&local_f8);
  OPENSSL_cleanse(&local_f8,0xd8);
  return md_00;
}

