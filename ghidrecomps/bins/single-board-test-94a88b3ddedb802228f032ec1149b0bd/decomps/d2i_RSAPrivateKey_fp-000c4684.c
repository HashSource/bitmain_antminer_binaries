
RSA * d2i_RSAPrivateKey_fp(FILE *fp,RSA **rsa)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_item_d2i_fp((ASN1_ITEM *)RSAPrivateKey_it,fp,rsa);
  return pRVar1;
}

