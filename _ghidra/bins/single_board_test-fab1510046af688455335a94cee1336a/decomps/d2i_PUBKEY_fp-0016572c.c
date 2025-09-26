
EVP_PKEY * d2i_PUBKEY_fp(FILE *fp,EVP_PKEY **a)

{
  EVP_PKEY *pEVar1;
  
  pEVar1 = (EVP_PKEY *)ASN1_d2i_fp((xnew *)0x1557a1,(undefined1 *)0x1596c1,fp,a);
  return pEVar1;
}

