
EVP_PKEY * d2i_PrivateKey_bio(BIO *bp,EVP_PKEY **a)

{
  EVP_PKEY *pEVar1;
  
  pEVar1 = (EVP_PKEY *)ASN1_d2i_bio((xnew *)0x1557a1,(undefined1 *)0x15a915,bp,a);
  return pEVar1;
}

