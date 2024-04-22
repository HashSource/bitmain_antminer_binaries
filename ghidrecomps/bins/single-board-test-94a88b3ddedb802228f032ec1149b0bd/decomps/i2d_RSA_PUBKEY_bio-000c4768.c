
int i2d_RSA_PUBKEY_bio(BIO *bp,RSA *rsa)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_bio(i2d_RSA_PUBKEY + 1,bp,(uchar *)rsa);
  return iVar1;
}

