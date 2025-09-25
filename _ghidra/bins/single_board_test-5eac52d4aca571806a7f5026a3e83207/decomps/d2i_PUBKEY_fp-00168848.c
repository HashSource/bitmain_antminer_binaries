
EVP_PKEY * d2i_PUBKEY_fp(FILE *fp,EVP_PKEY **a)

{
  EVP_PKEY *pEVar1;
  
  pEVar1 = (EVP_PKEY *)ASN1_d2i_fp((xnew *)0x12d771,(undefined1 *)0x169df1,fp,a);
  return pEVar1;
}

