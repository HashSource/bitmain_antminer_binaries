
uchar * SHA384(uchar *d,size_t n,uchar *md)

{
  SHA512_CTX SStack_f0;
  
  if (md == (uchar *)0x0) {
    md = &m_8561;
  }
  SHA384_Init(&SStack_f0);
  SHA512_Update(&SStack_f0,d,n);
  SHA512_Final(md,&SStack_f0);
  OPENSSL_cleanse(&SStack_f0,0xd8);
  return md;
}

