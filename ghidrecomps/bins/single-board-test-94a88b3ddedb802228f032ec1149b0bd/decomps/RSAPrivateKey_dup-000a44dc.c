
RSA * RSAPrivateKey_dup(RSA *rsa)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_item_dup((ASN1_ITEM *)RSAPrivateKey_it,rsa);
  return pRVar1;
}

