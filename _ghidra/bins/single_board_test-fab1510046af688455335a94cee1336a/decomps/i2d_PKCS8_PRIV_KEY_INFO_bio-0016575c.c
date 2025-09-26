
int i2d_PKCS8_PRIV_KEY_INFO_bio(BIO *bp,PKCS8_PRIV_KEY_INFO *p8inf)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_bio((undefined1 *)0x15eb8d,bp,(uchar *)p8inf);
  return iVar1;
}

