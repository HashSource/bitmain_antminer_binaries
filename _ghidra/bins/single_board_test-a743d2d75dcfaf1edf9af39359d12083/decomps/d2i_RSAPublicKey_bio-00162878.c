
RSA * d2i_RSAPublicKey_bio(BIO *bp,RSA **rsa)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_item_d2i_bio((ASN1_ITEM *)RSAPublicKey_it,bp,rsa);
  return pRVar1;
}

