
int i2d_ECPrivateKey_bio(BIO *bp,EC_KEY *eckey)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_bio((undefined1 *)0x125f5d,bp,(uchar *)eckey);
  return iVar1;
}

