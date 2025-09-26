
int i2d_RSAPublicKey_bio(BIO *bp,RSA *rsa)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_bio((ASN1_ITEM *)RSAPublicKey_it,bp,rsa);
  return iVar1;
}

