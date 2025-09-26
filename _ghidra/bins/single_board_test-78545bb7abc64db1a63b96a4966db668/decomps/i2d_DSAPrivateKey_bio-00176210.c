
int i2d_DSAPrivateKey_bio(BIO *bp,DSA *dsa)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_bio((undefined1 *)0x122275,bp,(uchar *)dsa);
  return iVar1;
}

