
int i2d_ECPrivateKey_bio(BIO *bp,EC_KEY *eckey)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_bio((undefined1 *)0x18e4e9,bp,(uchar *)eckey);
  return iVar1;
}

