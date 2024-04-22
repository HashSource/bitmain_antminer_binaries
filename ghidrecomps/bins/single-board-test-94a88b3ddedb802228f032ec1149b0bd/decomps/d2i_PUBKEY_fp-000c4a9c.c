
EVP_PKEY * d2i_PUBKEY_fp(FILE *fp,EVP_PKEY **a)

{
  EVP_PKEY *pEVar1;
  
  pEVar1 = (EVP_PKEY *)ASN1_d2i_fp(EVP_PKEY_new + 1,d2i_PUBKEY + 1,fp,a);
  return pEVar1;
}

