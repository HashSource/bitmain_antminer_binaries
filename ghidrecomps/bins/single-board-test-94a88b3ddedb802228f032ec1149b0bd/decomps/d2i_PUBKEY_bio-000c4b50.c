
EVP_PKEY * d2i_PUBKEY_bio(BIO *bp,EVP_PKEY **a)

{
  EVP_PKEY *pEVar1;
  
  pEVar1 = (EVP_PKEY *)ASN1_d2i_bio((xnew *)0xb2005,(undefined1 *)0xb6dc5,bp,a);
  return pEVar1;
}

