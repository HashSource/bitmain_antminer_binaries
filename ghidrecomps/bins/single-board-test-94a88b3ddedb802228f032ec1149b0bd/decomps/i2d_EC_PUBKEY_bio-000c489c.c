
int i2d_EC_PUBKEY_bio(BIO *bp,EC_KEY *eckey)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_bio(i2d_EC_PUBKEY + 1,bp,(uchar *)eckey);
  return iVar1;
}

