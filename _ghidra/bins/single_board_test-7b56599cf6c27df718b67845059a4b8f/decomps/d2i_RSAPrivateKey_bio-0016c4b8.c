
RSA * d2i_RSAPrivateKey_bio(BIO *bp,RSA **rsa)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_item_d2i_bio((ASN1_ITEM *)RSAPrivateKey_it,bp,rsa);
  return pRVar1;
}

