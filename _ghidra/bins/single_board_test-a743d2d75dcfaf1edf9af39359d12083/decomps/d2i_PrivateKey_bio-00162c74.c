
EVP_PKEY * d2i_PrivateKey_bio(BIO *bp,EVP_PKEY **a)

{
  EVP_PKEY *pEVar1;
  
  pEVar1 = (EVP_PKEY *)ASN1_d2i_bio((xnew *)0x152c61,(undefined1 *)0x157dd5,bp,a);
  return pEVar1;
}

