
uchar * SHA384(uchar *d,size_t n,uchar *md)

{
  uchar *md_00;
  SHA512_CTX local_f8;
  
  local_f8.h[0]._0_4_ = 0xc1059ed8;
  local_f8.h[0]._4_4_ = 0xcbbb9d5d;
  md_00 = &m_7551;
  if (md != (uchar *)0x0) {
    md_00 = md;
  }
  local_f8.h[1]._0_4_ = 0x367cd507;
  local_f8.h[1]._4_4_ = 0x629a292a;
  local_f8.h[3]._0_4_ = 0xf70e5939;
  local_f8.h[3]._4_4_ = 0x152fecd8;
  local_f8.h[2]._0_4_ = 0x3070dd17;
  local_f8.h[2]._4_4_ = 0x9159015a;
  local_f8.h[4]._0_4_ = 0xffc00b31;
  local_f8.h[4]._4_4_ = 0x67332667;
  local_f8.num = 0;
  local_f8.md_len = 0x30;
  local_f8.h[5]._0_4_ = 0x68581511;
  local_f8.h[5]._4_4_ = 0x8eb44a87;
  local_f8.h[7]._0_4_ = 0xbefa4fa4;
  local_f8.h[7]._4_4_ = 0x47b5481d;
  local_f8.Nl._0_4_ = 0;
  local_f8.Nl._4_4_ = 0;
  local_f8.h[6]._0_4_ = 0x64f98fa7;
  local_f8.h[6]._4_4_ = 0xdb0c2e0d;
  local_f8.Nh._0_4_ = 0;
  local_f8.Nh._4_4_ = 0;
  SHA512_Update(&local_f8,d,n);
  SHA512_Final(md_00,&local_f8);
  OPENSSL_cleanse(&local_f8,0xd8);
  return md_00;
}

