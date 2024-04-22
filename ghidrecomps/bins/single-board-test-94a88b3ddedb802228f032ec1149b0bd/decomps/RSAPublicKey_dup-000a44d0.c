
RSA * RSAPublicKey_dup(RSA *rsa)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_item_dup(DAT_000a44d8,rsa);
  return pRVar1;
}

