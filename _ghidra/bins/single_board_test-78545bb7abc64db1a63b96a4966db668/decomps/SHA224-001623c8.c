
uchar * SHA224(uchar *d,size_t n,uchar *md)

{
  SHA256_CTX SStack_88;
  
  if (md == (uchar *)0x0) {
    md = &m_7256;
  }
  SHA224_Init(&SStack_88);
  SHA256_Update(&SStack_88,d,n);
  SHA256_Final(md,&SStack_88);
  OPENSSL_cleanse(&SStack_88,0x70);
  return md;
}

