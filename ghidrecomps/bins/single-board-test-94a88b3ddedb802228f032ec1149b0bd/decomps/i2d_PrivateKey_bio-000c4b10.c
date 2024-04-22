
int i2d_PrivateKey_bio(BIO *bp,EVP_PKEY *pkey)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_bio(i2d_PrivateKey + 1,bp,(uchar *)pkey);
  return iVar1;
}

