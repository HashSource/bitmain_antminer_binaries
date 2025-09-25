
int i2d_RSAPrivateKey_bio(BIO *bp,RSA *rsa)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_bio((ASN1_ITEM *)RSAPrivateKey_it,bp,rsa);
  return iVar1;
}

