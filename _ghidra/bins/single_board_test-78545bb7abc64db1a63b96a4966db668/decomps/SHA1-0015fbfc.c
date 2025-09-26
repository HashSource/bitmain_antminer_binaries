
uchar * SHA1(uchar *d,size_t n,uchar *md)

{
  uchar *puVar1;
  SHA_CTX SStack_78;
  
  if (md == (uchar *)0x0) {
    md = &m_7250;
  }
  puVar1 = (uchar *)SHA1_Init(&SStack_78);
  if (puVar1 != (uchar *)0x0) {
    SHA1_Update(&SStack_78,d,n);
    SHA1_Final(md,&SStack_78);
    OPENSSL_cleanse(&SStack_78,0x60);
    puVar1 = md;
  }
  return puVar1;
}

