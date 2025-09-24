
uchar * WHIRLPOOL(void *inp,size_t bytes,uchar *md)

{
  WHIRLPOOL_CTX WStack_c0;
  
  if (md == (uchar *)0x0) {
    md = &m_7227;
  }
  WHIRLPOOL_Init(&WStack_c0);
  WHIRLPOOL_Update(&WStack_c0,inp,bytes);
  WHIRLPOOL_Final(md,&WStack_c0);
  return md;
}

