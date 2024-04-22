
uchar * SHA1(uchar *d,size_t n,uchar *md)

{
  int iVar1;
  uchar *md_00;
  SHA_CTX SStack_70;
  
  md_00 = DAT_000e07c0;
  if (md != (uchar *)0x0) {
    md_00 = md;
  }
  iVar1 = SHA1_Init(&SStack_70);
  if (iVar1 == 0) {
    md_00 = (uchar *)0x0;
  }
  else {
    SHA1_Update(&SStack_70,d,n);
    SHA1_Final(md_00,&SStack_70);
    OPENSSL_cleanse(&SStack_70,0x60);
  }
  return md_00;
}

