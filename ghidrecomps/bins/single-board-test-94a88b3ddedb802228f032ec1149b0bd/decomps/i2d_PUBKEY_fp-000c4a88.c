
int i2d_PUBKEY_fp(FILE *fp,EVP_PKEY *pkey)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_fp(i2d_PUBKEY + 1,fp,pkey);
  return iVar1;
}

