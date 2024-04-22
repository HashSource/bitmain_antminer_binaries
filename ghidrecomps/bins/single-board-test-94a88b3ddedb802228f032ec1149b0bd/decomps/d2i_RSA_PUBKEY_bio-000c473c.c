
RSA * d2i_RSA_PUBKEY_bio(BIO *bp,RSA **rsa)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)ASN1_d2i_bio(RSA_new + 1,d2i_RSA_PUBKEY + 1,bp,rsa);
  return pRVar1;
}

