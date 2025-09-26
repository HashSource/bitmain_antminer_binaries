
RSA * RSAPublicKey_dup(RSA *rsa)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_item_dup((ASN1_ITEM *)RSAPublicKey_it,rsa);
  return pRVar1;
}

