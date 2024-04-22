
EVP_PKEY * PEM_read_PUBKEY(FILE *fp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  EVP_PKEY *pEVar1;
  
  pEVar1 = (EVP_PKEY *)PEM_ASN1_read(d2i_PUBKEY + 1,"PUBLIC KEY",fp,x,cb,u);
  return pEVar1;
}

