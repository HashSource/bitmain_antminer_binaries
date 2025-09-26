
EVP_PKEY * d2i_PUBKEY_fp(FILE *fp,EVP_PKEY **a)

{
  EVP_PKEY *pEVar1;
  
  pEVar1 = (EVP_PKEY *)ASN1_d2i_fp((xnew *)0x152c61,(undefined1 *)0x156b81,fp,a);
  return pEVar1;
}

