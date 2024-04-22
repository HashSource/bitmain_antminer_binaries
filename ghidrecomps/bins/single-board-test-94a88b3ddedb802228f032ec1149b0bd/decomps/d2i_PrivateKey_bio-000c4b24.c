
EVP_PKEY * d2i_PrivateKey_bio(BIO *bp,EVP_PKEY **a)

{
  EVP_PKEY *pEVar1;
  
  pEVar1 = (EVP_PKEY *)ASN1_d2i_bio(EVP_PKEY_new + 1,d2i_AutoPrivateKey + 1,bp,a);
  return pEVar1;
}

